# TimeZoneFinder

C++17-программа для определения временной зоны по координатам (WGS-84).

## Возможности

- Вывод идентификатора зоны (`Europe/London`) и смещения (`UTC+0`)
- Использует GeoJSON и RapidJSON

## Сборка

```bash
git clone --recurse-submodules https://github.com/Dimly82/TZFinder
cd TZFinder
git submodule update --init -- recursive # если зависимости не установлены

./scripts/download.sh

mkdir build && cd build
cmake ..
make
```

## Использование

``./TZFinder <latitude> <longitude>``

### Пример

``./TZFinder 55.7558 37.6176
→ Europe/Moscow, UTC+3
``

## Тестирование (после сборки в папке build)

``ctest`` или ``./tests``
