#include <iostream>
using namespace std;
#define offset "\t\t\t\t"

void main()
{
	setlocale(LC_ALL, "");
	int array_size;
	cout << offset << "������� ������ �������: "; cin >> array_size;
	int* array = new int[array_size];
	int sum = 0, max, min;
	for (int i = 0; i < array_size; i++)
	{
		cout << offset << "������� #" << i + 1 << " -> ";
		cin >> array[i];
	}
	cout << endl;
	max = array[0];
	min = array[0];
	cout << offset << "�������� ������� � ������ �������: ";
	for (int i = 0; i < array_size; i++)
	{
		sum += array[i];
		if (max < array[i]) max = array[i];
		if (min > array[i]) min = array[i];
		cout << array[i] << " ";
	}
	cout << "\n" << offset << "�������� ������� � �������� �������: ";
	for (int i = array_size - 1; i >= 0; i--)
	{
		cout << array[i] << " ";
	}
	cout << "\n" << offset << "����� ��������� ������� ����� " << sum;
	cout << "\n" << offset << "�������������������� ��������� ������� ����� " << (float)(sum) / (float)(array_size);
	cout << "\n" << offset << "���������� �������� ����� ���������: " << max;
	cout << "\n" << offset << "���������� �������� ����� ���������: " << min;
}