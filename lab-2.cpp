#include <iostream>

double v_stepenb(double osnovanie_stepeni, int stepenb) {
    double result = 1;
    int k = 0;
    while (k < stepenb) {
        result *= osnovanie_stepeni;
        k++;
    }
    return result;
}

double dvoinoi_factorial(int argument) {
    double result = 1;
    for (int k = argument; k > 0; k -= 2) {
        result *= k;
    }
    return result;
}

double T(double argument) {
    double sum1 = 0;
    double sum2 = 0;
    for (int k = 0; k <= 10; k++) {
        sum1 += v_stepenb(argument, 2 * k + 1) / dvoinoi_factorial(2 * k + 1);
    }
    for (int k = 0; k <= 10; k++) {
        sum2 += v_stepenb(argument, 2 * k) / dvoinoi_factorial(2 * k);
    }
    return sum1 / sum2;
}

int main() {
    double y, chislitelb, znamenatelb, res;

    std::cout << "Enter your y:\n";
    std::cin >> y;

    chislitelb = 7 * T(0.25) + 2 * T(1 + y);
    znamenatelb = 6 - T(v_stepenb(y, 2) - 1);
    res = chislitelb / znamenatelb;

    std::cout.precision(10);
    std::cout << "Ответ: " << res << std::endl;

    return 0;
}