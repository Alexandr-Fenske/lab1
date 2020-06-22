#include <iostream>
#include <vector>

using namespace std;

size_t digits(size_t max_count);

int main()
{
    // ���� ������
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<double> numbers(number_count);

    for (size_t i = 0; i < number_count; i++)
    {
        cin >> numbers[i]; // ������������� ������� (������������� �������)
    }

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // ��������� ������
    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
    }

    vector<size_t> bins(bin_count); // ����������� ������� bins
    for (double number : numbers)
    { // numbers ��� ����� �� �����
        size_t bin = (size_t)((number - min) / (max - min) * bin_count); // ����� ������ ������� ��� ���������� �����
        if (bin == bin_count)
        { // ���� ����� ������� ��������� � ����� ����������� ���������, ��������� �� 1 ����� �������� ����� ��������� �������
            bin--;
        }
        bins[bin]++; // ��������� ��������� � ������ �������
    }

    // ����� ������


    // ���� ������������ ���������� ��������� �� �������
    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }

    // ���������������
    size_t digits_count = digits(max_count);
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - (digits_count + 2) - 1;
    const bool scaling_needed = max_count > MAX_ASTERISK;
    cerr << endl;
    for (size_t bin : bins)
    {
        size_t spaces_count = digits_count - digits(bin);
        for(size_t i = 0; i < spaces_count; i++){
            cout << " ";
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}

 size_t digits(size_t max_count)
{
    size_t count = 1;
    double cnt = max_count;
    while(cnt >= 10)
    {
        cnt /= 10.0;
        count++;
    }
    return count;
}
