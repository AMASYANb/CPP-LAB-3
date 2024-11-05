#include <iostream>
#include <cmath>
#include <chrono>

// функция, которая считает сумму всех элементов в массиве, а точнее, в нашей задаче это общий вес граммовок всех чашек
// создаем функцию фукнцию, называем её, на вход она принимает указатель на массив array и целочисленное количество чашек 
// array содержит в себе все граммовки чашек 

int min_diff(int* array, int n) { 
    int total_sum = 0;                                  // задаем начальное значение = 0 
    for (int i = 0; i < n; i++) {                       //создаем цикл, который сложит все числа, начинаем от нуля, а значит надо i < n, то есть не включительно
        total_sum += array[i];                          // с каждой итерацией прибавляем к total_sum новое значение граммовки новой чашки
    }

    int target_sum = total_sum / 2;                     // будем использовать метод поиска максимально приближенного подмножества к половине от общей сумммы
    bool* dp = new bool[target_sum + 1]();              // устанавливаем значение false для массива динамически, для экономии памяти и чтоб значения большие считались
    dp[0] = true;                                       // устанавливаем начальное значение dp = true при сумме подмножества = 0, потому что пустое подмножество всегда достижимо

    for (int i = 0; i < n; i++) {                       //запускаем цикл внутри цикла, после каждой итерации, цикл внутри будет заводиться заново с новым значением array[i]
        for (int j = target_sum; j >= array[i]; j--) {  // начинаем цикл от target_sum и идем с шагом 1 вниз по значениям до тех пор, пока j не достигнет [i], потому что ниже нет смысла искать
            dp[j] = dp[j] || dp[j - array[i]];          // тут проверяем, если некоторая сумма уже была достигнута ранее, то мы просто пропускаем 
        }
    }

    int closest_sum = 0;
    for (int i = target_sum; i >= 0; i--) {
        if (dp[i] == true) {
            closest_sum = i;
            break;
        }
    }

    int first_sum = closest_sum; 
    int second_sum = total_sum - closest_sum;
    int result = std::abs(first_sum - second_sum);
    
    delete[] dp;
    return result;
}

int main() {
    int n;
    std::cout << "Введите количество чашек: ";
    std::cin >> n;

    int array[32];
    std::cout << "Введите граммовку чашек: ";
    for (int i = 0; i < n; i++)
    std::cin >> array[i];

    auto start = std::chrono::high_resolution_clock::now();
    int difference = min_diff(array, n);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Минимальная разница: " << difference << std::endl;
    std::cout << "Время выполнения: " << elapsed.count() << " миллисекунд" << std::endl;

    return 0;
} 