#include <iostream>
#include <math.h>
using namespace std;
#define offset "\t"

template <typename T1, typename T2>

void fillrand(T1* array, T2 array_size)	//заполнение массива
{
	for (int i = 0; i < array_size; i++)
	{
		array[i] = rand() % 100*pow(-1,rand()%2);
	}
}

void print(T *array, int array_size, bool print_all)	// вывод массива на экран в прямом и обратном порядке
{
	(print_all) ? cout << offset << "Элементы массива в прямом порядке: " : cout<<"";
	for (int i = 0; i < array_size; i++)
	{
		cout << array[i] << " ";
	}
	if (print_all)
	{
		cout << "\n" << offset << "Элементы массива в обратном порядке: ";
		for (int i = array_size - 1; i >= 0; i--)
		{
			cout << array[i] << " ";
		}
	}
}

int sum(int* array, int array_size)	// сумма элементов массива
{
	int sum = 0;
	for (int i = 0; i < array_size; i++)
	{
		sum += array[i];
	}
	return sum;
}

int minValueIn(int* array, int array_size, int i)	// минимальный элемент в массиве
{
	int min = array[i];
	for (i = 0; i < array_size; i++)
	{
		if (min > array[i]) min = array[i];
	}
	return min;
}

int maxValueIn(int* array, int array_size)	// максимальный элемент в массиве
{
	int max = array[0];
	for (int i = 0; i < array_size; i++)
	{
		if (max < array[i]) max = array[i];
	}
	return max;
}

void shiftLeft(int* array, int array_size, int shift) // сдвиг влево
{
	int temp;
	for (int j = 0; j < shift; j++)
	{
		temp = array[array_size - 1];
		for (int i = array_size - 1; i > 0; i--)
		{
			array[i] = array[i - 1];
		}
		array[0] = temp;
	}
}

void shiftRight(int* array, int array_size, int shift)	// сдвиг вправо
{
	int temp;
	for (int j = 0; j < shift; j++)
	{
		temp = array[0];
		for (int i = 0; i < array_size-1 ; i++)
		{
			array[i] = array[i + 1];
		}
		array[array_size-1] = temp;
	}
}

void Sort(int* array, int array_size)
{
	int min;
	for (int i = 0; i < array_size; i++)
	{
		min = array[i];
		for (int j = i + 1; j < array_size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				array[j] = array[i];
				array[i] = min;
			}
		}
	}
}

void main()
{
	setlocale(LC_ALL, "");
	int array_size, shift;
	cout << offset << "Введите размер массива: "; cin >> array_size;
	int* array = new int[array_size];
	fillrand<int>(array, array_size);
	print<int>(array, array_size, true);
	//cout << "\n" << offset << "Сумма элементов массива равна " << sum(array, array_size);
	//cout << "\n" << offset << "Среднеарифметическое элементов массива равно " << (float)(sum(array, array_size)) / (array_size);
	//cout << "\n" << offset << "Наибольшее значение среди элементов: " << maxValueIn(array, array_size);
	//cout << "\n" << offset << "Наименьшее значение среди элементов: " << minValueIn(array, array_size, 0);
	//shift = rand() % array_size;
	//cout << "\n" << offset << "Сдвиг вправо на "<<shift<<" элементов ";
	//shiftLeft(array, array_size, shift);
	//print(array, array_size, false);
	//cout << "\n" << offset << "Сдвиг влево на " << shift << " элементов ";
	//shiftRight(array, array_size, shift);
	//print(array, array_size, false);
	//cout << "\n" << offset << "Произведём сортировку массива в порядке возрастания: ";
	//Sort(array, array_size);
	//print(array, array_size, false);
	//cout << endl;
}