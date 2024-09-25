#include <iostream> 
using namespace std;

void sueta(int n, char lenin, char navalnui, char konec) {
    if (n == 1) {
        cout << "Переместить диск 1 с " << lenin << " на " << konec << endl;
        return;
    }
    sueta(n - 1, lenin, konec, navalnui); 
    cout << "Переместить диск " << n << " с " << lenin << " на " << konec << endl;
    sueta(n - 1, navalnui, lenin, konec); 
}

int main() {
    int n;
    cout << "Количество дисков: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество дисков должно быть положительным." << endl; 
        return 1;
    }

    sueta(n, 'A', 'B', 'C'); 
    return 0;
}