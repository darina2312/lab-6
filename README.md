# Лабораторная работа №6: Паттерн "Стратегия"

## Цель работы
- Реализация паттерна "Стратегия" для алгоритмов сортировки
- Изучение принципов SOLID (SRP, OCP)
- Разработка гибкой системы, расширяемой новыми алгоритмами без модификации существующего кода

- 
## Реализованные стратегии
1. `BubbleSortStrategy` - сортировка пузырьком
2. `QuickSortStrategy` - быстрая сортировка
3. `StdSortStrategy` - стандартная сортировка (std::sort)
4. `InsertionSortStrategy` - сортировка вставками (добавленная стратегия)

## Принципы SOLID
1. **Single Responsibility Principle**:
   - Каждый класс стратегии отвечает только за свою реализацию сортировки
   - Класс `Sorter` отвечает только за применение стратегии

2. **Open/Closed Principle**:
   - Система открыта для расширения (можно добавлять новые стратегии)
   - Закрыта для модификации (не требует изменений существующего кода)

## Сборка и запуск
```bash
# Создание папки сборки
mkdir build && cd build

# Генерация Makefile
cmake ..

# Компиляция проекта
make

