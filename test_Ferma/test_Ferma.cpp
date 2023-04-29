#include <iostream>
#include <random>

using namespace std;

// функция возведения в степень по модулю
long long powerMod(long long a, long long b, long long m)
{
    long long res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// функция теста Ферма на простоту числа n
bool fermatTest(long long n, int k)
{
    // основной цикл выполнения теста k раз
    for (int i = 0; i < k; i++)
    {
        // выбор случайного числа a из диапазона [2, n-2]
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<long long> dis(2, n - 2);
        long long a = dis(gen);

        // вычисление a^(n-1) mod n
        long long res = powerMod(a, n - 1, n);
       
        // проверка на простоту
        if (res != 1)
            return false;
    }

    // если после k итераций все тесты прошли успешно, то число n считаем простым
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    long long n = 22032003LL;
    int k = 20;

    if (fermatTest(n, k))
        cout << n << " является простым числом" << endl;
    else
        cout << n << " не являтся простым числом" << endl;
    cout << endl;

    long long n_min = n;
    while (fermatTest(n_min, k) == false) {
        n_min++;
    }
    cout << "Ближайше простое число: " << n_min << "\n" << endl;

    long long n_max = n;
    while (fermatTest(n_max, k) == false) {
        n_max--;
    }
    cout << "Меньшее ближайшее простое число: " << n_max << endl;

    return 0;
}