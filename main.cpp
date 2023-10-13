#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class ArrayProcessor {
private:
    std::vector<std::vector<T>> matrix;
    int rows;
    int cols;

public:
    ArrayProcessor(int rows, int cols) : rows(rows), cols(cols) {
        matrix.resize(rows, std::vector<T>(cols));
    }

    // Заповнення матриці
    void fillMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Введіть елемент [" << i << "][" << j << "]: ";
                std::cin >> matrix[i][j];
            }
        }
    }

    // Вивід матриці
    void printMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Кількість рядків, у яких елементи упорядковані за зростанням
    int countRowsOrderedAscending() {
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            bool ordered = std::is_sorted(matrix[i].begin(), matrix[i].end());
            if (ordered) {
                count++;
            }
        }
        return count;
    }

    // Знайти перший рядок, який містить хоча б один додатний елемент
    int findFirstRowWithPositiveElement() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] > 0) {
                    return i;
                }
            }
        }
        return -1;
    }

    // Розміщення елементів непарних стовпців у порядку спадання
    void sortOddColumnsDescending() {
        for (int j = 1; j < cols; j += 2) {
            std::vector<T> column;
            for (int i = 0; i < rows; ++i) {
                column.push_back(matrix[i][j]);
            }
            std::sort(column.rbegin(), column.rend());
            for (int i = 0; i < rows; ++i) {
                matrix[i][j] = column[i];
            }
        }
    }
};

int main() {
    int rows, cols;
    std::cout << "Введіть кількість рядків та стовпців: ";
    std::cin >> rows >> cols;

    ArrayProcessor<int> processor(rows, cols);

    std::cout << "Введення матриці:\n";
    processor.fillMatrix();

    std::cout << "Вивід матриці:\n";
    processor.printMatrix();

    int orderedRows = processor.countRowsOrderedAscending();
    std::cout << "Кількість рядків, у яких елементи упорядковані за зростанням: " << orderedRows << std::endl;

    int firstRowWithPositiveElement = processor.findFirstRowWithPositiveElement();
    if (firstRowWithPositiveElement >= 0) {
        std::cout << "Перший рядок, який містить хоча б один додатний елемент: " << firstRowWithPositiveElement << std::endl;
    } else {
        std::cout << "Додатній елемент не знайдено в матриці." << std::endl;
    }

    processor.sortOddColumnsDescending();
    std::cout << "Матриця після сортування непарних стовпців у порядку спадання:\n";
    processor.printMatrix();

    return 0;
}
