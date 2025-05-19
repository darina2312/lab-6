#ifndef SOLID_HPP
#define SOLID_HPP

#include <vector>
#include <memory>
#include <algorithm>

class SortingStrategy {
public:
    virtual ~SortingStrategy() = default;
    virtual void sort(std::vector<int>& data) = 0;
};

class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

class QuickSortStrategy : public SortingStrategy {
    void quickSort(std::vector<int>& data, int left, int right) {
        if (left >= right) return;

        int pivot = data[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            while (data[i] < pivot) i++;
            while (data[j] > pivot) j--;

            if (i <= j) {
                std::swap(data[i], data[j]);
                i++;
                j--;
            }
        }

        quickSort(data, left, j);
        quickSort(data, i, right);
    }
public:
    void sort(std::vector<int>& data) override {
        if (!data.empty()) {
            quickSort(data, 0, data.size() - 1);
        }
    }
};

class StdSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::sort(data.begin(), data.end());
    }
};

class InsertionSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        for (size_t i = 1; i < data.size(); ++i) {
            int key = data[i];
            int j = i - 1;

            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }
};

class Sorter {
    std::unique_ptr<SortingStrategy> strategy;
public:
    explicit Sorter(std::unique_ptr<SortingStrategy> strategy = nullptr)
        : strategy(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<SortingStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void sortData(std::vector<int>& data) {
        if (strategy) {
            strategy->sort(data);
        }
    }
};

#endif // SOLID_HPP