#include <iostream>
#include <math.h>
using namespace std;

// Перегрузка функции заполнения случайными числами
void fillrand(int* array, int array_size)	//заполнение массива int
{
	cout << "\nМассив элементов типа [INT]"<<endl;
	for (int i = 0; i < array_size; i++)
	{
		array[i] = rand() % 100 * pow(-1, rand() % 2);
	}
}
void fillrand(float* array, int array_size)	//заполнение массива float
{
	cout << "\nМассив элементов типа [FLOAT]" << endl;
	for (int i = 0; i < array_size; i++)
	{
		array[i] = pow(-1, rand() % 2) / rand() * 10000;
	}
}
void fillrand(double* array, int array_size)	//заполнение массива double
{
	cout << "\nМассив элементов типа [DOUBLE]" << endl;
	for (int i = 0; i < array_size; i++)
	{
		array[i] = rand() * pow(-1, rand() % 2);
	}
}
void fillrand(char* array, int array_size)	//заполнение массива char
{
	cout << "\nМассив элементов типа [CHAR]" << endl;
	for (int i = 0; i < array_size; i++)
	{
		array[i] = rand()%26+65;
	}
}

// Вывод массива на экран в прямом и обратном порядке (шаблонная функция)
template <typename T>
void print(T* array, int array_size, bool print_all)	
{
	(print_all) ? cout <<  "Элементы массива в прямом порядке: " : cout << "";
	for (int i = 0; i < array_size; i++)
	{
		cout << array[i] << " ";
	}
	if (print_all)
	{
		cout << "\n" <<  "Элементы массива в обратном порядке: ";
		for (int i = array_size - 1; i >= 0; i--)
		{
			cout << array[i] << " ";
		}
	}
}

// Сумма элементов массива (шаблонная функция) (без char)
template <typename T>
T sum(T* array, int array_size)	// сумма элементов массива
{
	T sum = 0;
	for (int i = 0; i < array_size; i++)
	{
		sum += array[i];
	}
	return sum;
}

// Средне арифметическое элементов массива (шаблонная функция) (без char)
template <typename T>
double avg(T* array, int array_size)
{
	return sum(array, array_size) / array_size;
}

// Минимальный элемент в массиве (шаблонная функция)
template <typename T>
T minValueIn(T* array, int array_size, int i)	
{
	T min = array[i];
	for (i = 0; i < array_size; i++)
	{
		if (min > array[i]) min = array[i];
	}
	return min;
}

// Максимальный элемент в массиве (шаблонная функция)
template <typename T>
T maxValueIn(T* array, int array_size)
{
	T max = array[0];
	for (int i = 0; i < array_size; i++)
	{
		if (max < array[i]) max = array[i];
	}
	return max;
}

// Сдвиг влево на n-элементов
template <typename T>
void shiftLeft(T* array, int array_size, int shift)
{
	T temp;
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

// Сдвиг вправо на n-элементов
template <typename T>
void shiftRight(T* array, int array_size, int shift)
{
	T temp;
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

// Сортировка по возрастанию алгоритмом выбора
template <typename T>
void Sort(T* array, int array_size)
{
	T min;
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

// Вызов всех функций
template <typename T>
void do_all(T* array, int array_size, int shift, bool isChar)
{
	fillrand(array, array_size);
	print(array, array_size, true);
	if (!isChar)
	{
		cout << "\n" << "Сумма элементов массива равна " << sum(array, array_size);
		cout << "\n" << "Среднеарифметическое элементов массива равно " << avg(array, array_size);
	}
	cout << "\n" << "Наибольшее значение среди элементов: " << maxValueIn(array, array_size);
	cout << "\n" << "Наименьшее значение среди элементов: " << minValueIn(array, array_size, 0);
	cout << "\n" << "Сдвиг вправо на " << shift << " элементов ";
	shiftLeft(array, array_size, shift);
	print(array, array_size, false);
	cout << "\n" << "Сдвиг влево на " << shift << " элементов ";
	shiftRight(array, array_size, shift);
	print(array, array_size, false);
	cout << "\n" << "Произведём сортировку массива в порядке возрастания: ";
	Sort(array, array_size);
	print(array, array_size, false);
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	int array_size, shift;
	cout << "Введите размер массива: "; cin >> array_size;
	shift = rand() % array_size;
	
	int* array_int = new int[array_size];
	do_all(array_int, array_size, shift, false);
	
	float* array_float = new float[array_size];
	do_all(array_float, array_size, shift, false);
	
	double* array_double = new double[array_size];
	do_all(array_double, array_size, shift, false);

	char* array_char = new char[array_size];
	do_all(array_char, array_size, shift, true);

	delete[] array_int;
	delete[] array_float;
	delete[] array_double;
	delete[] array_char;
}