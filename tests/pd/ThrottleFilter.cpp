#include "pd/ThrottleFilter.hpp"

#include <algorithm>
#include <gtest/gtest.h>
#include <random>
#include <type_traits>
#include <vector>

namespace pd::tests::throttle_filter {

/*----------------------------------------------------------------------------*/

static constexpr double k_tolerance   = .000001;
static constexpr size_t k_window_size = 10;

template <typename DataType, size_t Size>
const std::vector<DataType>& get_random_vector() {
    static_assert(std::is_arithmetic_v<DataType>,
                  "DataType must be an arithmetic type");
    static const auto random_vector = []() {
        std::random_device random_device;
        std::mt19937 mersenne_twister(random_device());
        std::vector<DataType> vector(Size);
        if constexpr (std::is_integral_v<DataType>) {
            std::uniform_int_distribution<DataType> distribution(0, 100);
            std::generate(vector.begin(), vector.end(),
                          [&]() { return distribution(mersenne_twister); });
        } else {
            std::uniform_real_distribution<DataType> distribution(.0, 100.0);
            std::generate(vector.begin(), vector.end(),
                          [&]() { return distribution(mersenne_twister); });
        }
        return vector;
    }();
    return random_vector;
}

/*----------------------------------------------------------------------------*/

TEST(ThrottleFilter, initializes_to_zero) {
    pd::ThrottleFilter<float, k_window_size> filter;
    ASSERT_TRUE(std::fabs(filter.get_output() - .0) < k_tolerance);
}

/*----------------------------------------------------------------------------*/

TEST(ThrottleFilter, gets_window_size) {
    pd::ThrottleFilter<float, k_window_size> filter;
    ASSERT_EQ(filter.get_window_size(), k_window_size);
}

/*----------------------------------------------------------------------------*/

TEST(ThrottleFilter, resets_to_zero) {
    pd::ThrottleFilter<float, k_window_size> filter;
    filter.push_measurement(.1f);
    filter.push_measurement(.2f);
    filter.push_measurement(.3f);
    ASSERT_FALSE(std::fabs(filter.get_output() - .0) < k_tolerance);
    filter.reset();
    ASSERT_TRUE(std::fabs(filter.get_output() - .0) < k_tolerance);
}

/*----------------------------------------------------------------------------*/

TEST(ThrottleFilter, filters_throttle_signal_floating_point_type) {
    constexpr size_t k_num_windows = 10;
    const auto& signal =
        get_random_vector<float, k_window_size * k_num_windows>();
    pd::ThrottleFilter<float, k_window_size> filter;
    for (int i = 0; i < (k_window_size * k_num_windows) - k_window_size; ++i) {
        double average = .0;
        std::for_each(signal.begin() + i, signal.begin() + i + k_window_size,
                      [&](auto v) {
                          filter.push_measurement(v);
                          average += v / static_cast<double>(k_window_size);
                      });
        ASSERT_TRUE(std::fabs(filter.get_output() - average) < k_tolerance);
    }
}

/*----------------------------------------------------------------------------*/

TEST(ThrottleFilter, filters_throttle_signal_integer_type) {
    constexpr size_t k_num_windows = 10;
    const auto& signal =
        get_random_vector<int, k_window_size * k_num_windows>();
    pd::ThrottleFilter<int, k_window_size> filter;
    for (int i = 0; i < (k_window_size * k_num_windows) - k_window_size; ++i) {
        double average = .0;
        std::for_each(signal.begin() + i, signal.begin() + i + k_window_size,
                      [&](auto v) {
                          filter.push_measurement(v);
                          average += v / static_cast<double>(k_window_size);
                      });
        ASSERT_TRUE(std::fabs(filter.get_output() - average) < k_tolerance);
    }
}

/*----------------------------------------------------------------------------*/

} // namespace pd::tests::throttle_filter
