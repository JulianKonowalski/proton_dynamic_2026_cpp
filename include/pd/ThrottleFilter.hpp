#pragma once

#include <type_traits>

namespace pd {

/*----------------------------------------------------------------------------*/

template <typename DataType, size_t WindowSize>
class ThrottleFilter final {
    static_assert(std::is_arithmetic_v<DataType>,
                  "DataType must be an arithmetic type");

    using ThisType = ThrottleFilter<DataType, WindowSize>;

  public:
    ThrottleFilter();
    ~ThrottleFilter();

    ThrottleFilter(ThisType&& other)                 = delete;
    ThrottleFilter(const ThisType& other)            = delete;
    ThrottleFilter& operator=(ThisType&& other)      = delete;
    ThrottleFilter& operator=(const ThisType& other) = delete;

    inline constexpr size_t get_window_size() const;

    void reset();
    void push_measurement(DataType data);
    double get_output() const;
};

/*----------------------------------------------------------------------------*/

template <typename DataType, size_t WindowSize>
ThrottleFilter<DataType, WindowSize>::ThrottleFilter() {}

template <typename DataType, size_t WindowSize>
ThrottleFilter<DataType, WindowSize>::~ThrottleFilter() {}

template <typename DataType, size_t WindowSize>
inline constexpr size_t
ThrottleFilter<DataType, WindowSize>::get_window_size() const {
    return 0;
}

template <typename DataType, size_t WindowSize>
void ThrottleFilter<DataType, WindowSize>::reset() {}

template <typename DataType, size_t WindowSize>
void ThrottleFilter<DataType, WindowSize>::push_measurement(DataType data) {}

template <typename DataType, size_t WindowSize>
double ThrottleFilter<DataType, WindowSize>::get_output() const {
    return .0;
}

/*----------------------------------------------------------------------------*/

} // namespace pd
