#include <iostream>
#include <cmath>

using namespace std;

// ��������� ������ ����, ������������ ��� ��������� �������� ������������� �����
int main() {
    int n;
    std::cin >> n;

    // ������������ �������� n ����� 32 �������� �������� ������
    int m[32];
    // ������ ���������� ����� n � �� ����. ��� ������ ����� ����������� � ������� m.
    for (int i = 0; i < n; i++)
    {
        std::cin >> m[i];
    }

    // ������ � ����������� ���������� ��������
    int min_difference = INT_MAX;

    // ������� ���� 2^n ����������. Mask - ��� �������� ������������� ���� ����������
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int masha_sum = 0;
        int petya_sum = 0;

        // ������� ���� ����� � ��������, ���� ����������� ������� �����
        for (int j = 0; j < n; j++)
        {
            // ���� j-� ��� ����������, ����� ����������� ����
            if (mask & (1 << j))
                masha_sum += m[j];
            else // ����� ����� ����������� ����
                petya_sum += m[j];
        }

        // �� ��������� ������� � ���� ����� �������� ���� � ���� � �������, �������� �� ��� �����������
        int current_difference = std::abs(masha_sum - petya_sum);
        if (current_difference < min_difference)
        {
            min_difference = current_difference;
        }
    }

    // ����� �������� ���� ���������� ������� ����������� ��������� �������
    std::cout << min_difference << std::endl;
    return 0;
}