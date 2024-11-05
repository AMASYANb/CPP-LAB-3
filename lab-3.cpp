#include <iostream>
#include <cmath>
#include <chrono>

int min_diff(int* array, int n) {
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += array[i];
    }
    
    int target_sum = total_sum / 2;
    bool* dp = new bool [target_sum + 1]();
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = target_sum; j >= array[i]; j--) {
            dp[j] = dp[j] || dp[j - array [i]];
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
    int second_sum = total_sum - first_sum;
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