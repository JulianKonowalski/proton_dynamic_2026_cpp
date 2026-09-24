# Zadanie rekrutacyjne Proton Dynamic 2026

Jeden z głównych układów sterujących bolidu wścigowego zbiera dane na temat
wychylenia pedału przyspieszenia i przekazuje je dalej, w celu wysłania żądania
mocy do silników elektrycznych. Regulamin wymaga, aby rejestrowany sygnał został
odszumiony prostym filtrem, poprzez uśrednienie ostatnich 10 pomiarów. Na
podstawie tych informacji oraz przygotowanego publicznego interfejsu,
zaimplementuj logikę działania klasy `ThrottleFilter` umieszczonej w pliku
`include/pd/ThrottleFilter.hpp`. Klasę możesz dowolnie rozwijać, pod warunkiem,
że istniejący interfejs publiczny nie ulegnie zmianie. Do rozwiązania zadania
możesz posłużyć się biblioteką standardową C++. Wyznacznikiem poprawnej logiki
działania będzie przejście wszystkich testów zawartych w
`tests/pd/ThrottleFilter.cpp`.

## Klonowanie

Aby sklonować projekt do folderu, w którym został otwarty wiersz poleceń, posłuż
się komendą:
```
git clone --recurse-submodules https://github.com/JulianKonowalski/proton_dynamic_2026_cpp.git
```

## Budowanie

Projekt używa CMake, zatem do zbudowania go będzie potrzebny:
- CMake
- Generator
- Kompilator C++

W Protonie używamy CMake wraz z Ninja oraz GCC. Po pobraniu wszystkich
zależności, projekt można zbudować wywołując kolejno:
```
cmake -G Ninja -B ./build -S .
cmake --build build
```

Projekt na początku się nie zbuduje, ponieważ kod nie przejdzie testów. To jest
oczekiwane zachowanie.

## Przesyłanie

Ukończone zadanie należy przesłać na adres `juliankon.protondynamic@gmail.com`.

_Powodzenia!_