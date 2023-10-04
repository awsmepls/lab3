#include <iostream>
#include <cmath>

using namespace std;

// Применяем грубую силу, рассматривая все возможные варианты распределения чашек
int main() {
    int n;
    std::cin >> n;

    // Максимальное значение n равно 32 согласно условиям задачи
    int m[32];
    // Читаем количество чашек n и их веса. Вес каждой чашки сохраняется в массиве m.
    for (int i = 0; i < n; i++)
    {
        std::cin >> m[i];
    }

    // Начало с максимально возможного значения
    int min_difference = INT_MAX;

    // Перебор всех 2^n комбинаций. Mask - это бинарное представление этих комбинаций
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int masha_sum = 0;
        int petya_sum = 0;

        // Перебор всех чашек и проверка, кому принадлежит текущая чашка
        for (int j = 0; j < n; j++)
        {
            // Если j-й бит установлен, чашка принадлежит Маше
            if (mask & (1 << j))
                masha_sum += m[j];
            else // Иначе чашка принадлежит Пете
                petya_sum += m[j];
        }

        // Мы вычисляем разницу в весе между порциями Маши и Пети и смотрим, является ли она минимальной
        int current_difference = std::abs(masha_sum - petya_sum);
        if (current_difference < min_difference)
        {
            min_difference = current_difference;
        }
    }

    // После перебора всех комбинаций выводим минимальную найденную разницу
    std::cout << min_difference << std::endl;
    return 0;
}