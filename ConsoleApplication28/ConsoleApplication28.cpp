#include <iostream>
#include <cstdlib>  
#include <ctime>  
#include <limits>

int main()
{
    setlocale(LC_ALL, "ru");
    const int SIZE = 10;
    int arr[SIZE];
    std::srand(std::time(0));

    std::cout << "\nМассив случайных чисел: ";
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = std::rand() % 100;
        std::cout << arr[i] << " ";
    }

    int min = arr[0];
    int max = arr[0];


    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }


    std::cout << "\nМинимальный элемент: " << min << std::endl;
    std::cout << "Максимальный элемент: " << max << std::endl;

    return 0;
}

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    int lowerBound, upperBound, comparisonValue;


    std::cout << "Введите размер массива: ";
    std::cin >> size;


    std::cout << "Введите нижнюю границу диапазона: ";
    std::cin >> lowerBound;
    std::cout << "Введите верхнюю границу диапазона: ";
    std::cin >> upperBound;


    if (upperBound <= lowerBound) {
        std::cout << "Ошибка: верхняя граница должна быть больше нижней." << std::endl;
        return 1;
    }


    std::cout << "Введите значение для сравнения: ";
    std::cin >> comparisonValue;


    int* arr = new int[size];


    std::srand(std::time(0));


    std::cout << "Массив случайных чисел: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + std::rand() % (upperBound - lowerBound + 1);
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < comparisonValue) {
            sum += arr[i];
        }
    }


    std::cout << "Сумма элементов, меньших " << comparisonValue << ": " << sum << std::endl;


    delete[] arr;

    return 0;
}

int main() {
    setlocale(LC_ALL, "ru");
    const int months = 12;
    double profits[months];

    std::cout << "Введите прибыль фирмы за 12 месяцев:\n";
    for (int i = 0; i < months; ++i) {
        std::cout << "Месяц " << (i + 1) << ": ";
        std::cin >> profits[i];
    }


    int start, end;
    std::cout << "Введите диапазон месяцев :\n";
    std::cout << "Начальный месяц: ";
    std::cin >> start;
    std::cout << "Конечный месяц: ";
    std::cin >> end;


    if (start < 1 || end > months || start > end) {
        std::cout << "Ошибка: диапазон введен некорректно." << std::endl;
        return 1;
    }


    double maxProfit = std::numeric_limits<double>::lowest();
    double minProfit = std::numeric_limits<double>::max();
    int monthOfMaxProfit = start - 1;
    int monthOfMinProfit = start - 1;


    for (int i = start - 1; i < end; ++i) {
        if (profits[i] > maxProfit) {
            maxProfit = profits[i];
            monthOfMaxProfit = i + 1;
        }
        if (profits[i] < minProfit) {
            minProfit = profits[i];
            monthOfMinProfit = i + 1;
        }
    }


    std::cout << "Максимальная прибыль в месяце " << monthOfMaxProfit << ": " << maxProfit << std::endl;
    std::cout << "Минимальная прибыль в месяце " << monthOfMinProfit << ": " << minProfit << std::endl;

    return 0;
}