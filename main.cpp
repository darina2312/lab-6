#include "solid.hpp"
#include <iostream>

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {6, 3, 8, 1, 9, 4};

    Sorter sorter;
    std::cout << "Original: ";
    printVector(data);

    sorter.setStrategy(std::make_unique<BubbleSortStrategy>());
    sorter.sortData(data);
    std::cout << "BubbleSort: ";
    printVector(data);

    data = {6, 3, 8, 1, 9, 4};
    sorter.setStrategy(std::make_unique<QuickSortStrategy>());
    sorter.sortData(data);
    std::cout << "QuickSort: ";
    printVector(data);

    data = {6, 3, 8, 1, 9, 4};
    sorter.setStrategy(std::make_unique<StdSortStrategy>());
    sorter.sortData(data);
    std::cout << "StdSort: ";
    printVector(data);

    data = {6, 3, 8, 1, 9, 4};
    sorter.setStrategy(std::make_unique<InsertionSortStrategy>());
    sorter.sortData(data);
    std::cout << "InsertionSort: ";
    printVector(data);

    return 0;
}