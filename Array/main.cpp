#include <iostream>
using namespace std;
#define offset "\t\t\t\t"

void main()
{
	setlocale(LC_ALL, "");
	int array_size;
	cout << offset << "Введите размер массива: "; cin >> array_size;
	int* array = new int[array_size];
	int sum = 0, max, min;
	for (int i = 0; i < array_size; i++)
	{
		cout << offset << "Элемент #" << i + 1 << " -> ";
		cin >> array[i];
	}
	cout << endl;
	max = array[0];
	min = array[0];
	cout << offset << "Элементы массива в прямом порядке: ";
	for (int i = 0; i < array_size; i++)
	{
		sum += array[i];
		if (max < array[i]) max = array[i];
		if (min > array[i]) min = array[i];
		cout << array[i] << " ";
	}
	cout << "\n" << offset << "Элементы массива в обратном порядке: ";
	for (int i = array_size - 1; i >= 0; i--)
	{
		cout << array[i] << " ";
	}
	cout << "\n" << offset << "Сумма элементов массива равна " << sum;
	cout << "\n" << offset << "Среднеарифметическое элементов массива равно " << (float)(sum) / (float)(array_size);
	cout << "\n" << offset << "Наибольшее значение среди элементов: " << max;
	cout << "\n" << offset << "Наименьшее значение среди элементов: " << min;
}