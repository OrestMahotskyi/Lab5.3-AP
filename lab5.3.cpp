#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int fac(int n);

double f(double x) {
    if (abs(x) >= 1) {
        return (sin(x * x) + sin(x * x * x)) / (1 + cos(x * x));
    } else {
        double sum = 0;
        for (int n = 0; n <= 6; ++n) {
            sum += 1.0 / (pow(1 + x * x, 4 * n + 1) * fac(4 * n + 1));
        }
        return sum;
    }
}

int fac(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fac(n - 1);
    }
}

int main() {
    double a, b, h;

    // Запит початкових значень
    cout << "початок: "; cin >> a;
    cout << "кінець: "; cin >> b;
    cout << "к-сть поділок: "; cin >> h;

    // Виведення заголовка таблиці
    cout << "---------------------------" << endl;
    cout << "| " << setw(10) << "x" << " | " << setw(10) << "f(x)" << " |" << endl;
    cout << "---------------------------" << endl;

    // Основний цикл для виведення таблиці значень
    for (double x = a; x <= b; x += h) {
        cout << "| " << setw(10) << fixed << setprecision(4) << x
             << " | " << setw(10) << fixed << setprecision(4) << f(x)
             << " |" << endl;
    }

    // Виведення нижньої межі таблиці
    cout << "---------------------------" << endl;

    return 0;
}
