#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// 1.	Написать программу, которая удаляет из двухмерного массива, заполненного случайными числами, строки, содержащие нулевые элементы.
void delete_str(int**&a, int &n, int m) {
	for (int pass = 0; pass < n - 1; pass++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 0)
				{
					swap(a[i], a[i + 1]);
					break;
				}
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
			{
				k++;
				break;
			}
		}
	}
	n = n - k;
	for (int i = n + 1; i < n + k; i++)
		delete[] a[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// 2 case 2

// 3.	Создайте динамический массив, хранящий в первой строке идетификационный номер, а во второй - телефон.
//Организуйте поиск по ID и по номеру телефона и возможность ввода и изменения данных.

void input(int **&a, int &n) {
	int id, nomer;
	cin >> id >> nomer;

	int **tmp;
	tmp = new int*[2];
	tmp[0] = new int[n + 1];
	tmp[1] = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		tmp[0][i] = a[0][i];
		tmp[1][i] = a[1][i];
	}
	tmp[0][n] = id;
	tmp[1][n] = nomer;

	if (n != 0)
	{
		delete[] a[0], delete[] a[1];
		delete[] a;
	}
	a = tmp;
	n++;
}
void change(int **&a, int n) {
	cout << "введите индекс номера, который хотите изменить (или сначала воспользуйтесь функцией поиска):" << endl;
	int k;
	cin >> k;

	cout << "введите новый ID и номер:" << endl;
	int id, nomer;
	cin >> id >> nomer;

	int **tmp;
	tmp = new int*[2];
	tmp[0] = new int[n];
	tmp[1] = new int[n];

	for (int i = 0; i < n; i++)
	{
		tmp[0][i] = a[0][i];
		tmp[1][i] = a[1][i];
		if (i == k)
		{
			tmp[0][k] = id;
			tmp[1][k] = nomer;
		}
	}
	
	if (n != 0)
	{
		delete[] a[0], delete[] a[1];
		delete[] a;
	}
	a = tmp;
}
bool searchID(int **a, int n) {
	int id;
	cin >> id;

	int k = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[0][i] == id) k = i;
	}
	if (k < 0)
	{
		cout << "number (" << id << ") is not found" << endl;
		return false;
	}
	else
	{
		cout << "id: "<< id <<" is under the index: " << k << ", tel number is: " << a[1][k] << endl;
		return true;
	}
}
bool searchNum(int **a, int n) {
	int nomer;
	cin >> nomer;

	int k = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[1][i] == nomer) k = i;
	}
	if (k < 0)
	{
		cout << "number (" << nomer << ") is not found" << endl;
		return false;
	}
	else
	{
		cout << "telephone number ( " << nomer << ") is under the index: " << k << ", id: " << a[0][k] << endl;
		return true;
	}
}
void print(int **a, int n) {
	cout << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
}




int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

switch (tn)
		{
		case 1:
		{
			int**a;
			int n, m;
			cin >> n >> m;
			a = new int*[n];

			for (int i = 0; i < n; i++)
				a[i] = new int[m];

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					a[i][j] = rand() % 10;
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
				
			delete_str(a, n, m);

			for (int i = 0; i < n; i++)
				delete[] a[i];

			delete[] a;
		}
		break;
		case 2:
		{
		// 2.	Написать программу, которая поэлементно суммирует два динамических двумерных массива,
		// заполненных случайными числами и сохраняет результат в третьем массиве.
		// Размеры исходных массивов задаются пользователем.
			int **a, **b;
			int na, ma, nb, mb;
			cin >> na >> ma >> nb >> mb;
			a = new int*[na];
			b = new int*[nb];

			for (int i = 0; i < na; i++)
				a[i] = new int[ma];

			for (int i = 0; i < nb; i++)
				b[i] = new int[mb];

			for (int i = 0; i < na; i++)
			{
				for (int j = 0; j < ma; j++)
				{
					a[i][j] = rand() % 10;
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < nb; i++)
			{
				for (int j = 0; j < mb; j++)
				{
					b[i][j] = rand() % 10;
					cout << b[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;

			int cs, ck;
			if (na < nb) cs = na;
			else cs = nb;
			if (ma < mb) ck = ma;
			else cs = mb;

			int **c;
			c = new int*[cs];
			for (int i = 0; i < cs; i++)
				c[i] = new int[ck];

			for (int i = 0; i < cs; i++)
			{
				for (int j = 0; j < ck; j++)
				{
					c[i][j] = a[i][j] + b[i][j];
					cout << c[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;

			for (int i = 0; i < na; i++)
				delete[] a[i];
			delete[] a;

			for (int i = 0; i < nb; i++)
				delete[] b[i];
			delete[] b;

			for (int i = 0; i < cs; i++)
				delete[] c[i];
			delete[] c;
		}
		break;
		case 3:
		{
			int n;
			cin >> n;
			int **a;
			a = new int*[2];

			for (int i = 0; i < 2; i++)
				a[i] = new int[n];

			for (int i = 0; i < 2; i++)
			{
				if (i == 0) cout << "ID:   ";
				else cout << "tel number: ";
				for (int j = 0; j < n; j++)
				{
					a[0][j] = rand() % + 100;
					a[1][j] = rand() % 1000;
					cout << a[i][j] << "   ";
				}
				cout << endl;
			}
			cout << endl;

			int choice;
			bool f = true;
			while (f)
			{
				cout << "Выберите действие:" << endl;
				cout << "1 - добавление номера" << endl;
				cout << "2 - поиск телефона по ID" << endl;
				cout << "3 - поиск телефона по номеру" << endl;
				cout << "4 - изменение данных" << endl;
				cout << "0 - выход" << endl << endl;

				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					input(a, n);
					print(a, n);
				}
				break;
				case 2:
				{
					searchID(a, n);
					print(a, n);
				}
				break;
				case 3:
				{
					searchNum(a, n);
					print(a, n);
				}
				break;
				case 4:
				{
					change(a, n);
					print(a, n);
				}
				break;
				case 0:
				{
					f = false;
				}
				break;
				}
			}

			for (int i = 0; i < 2; i++)
				delete[] a[i];
			delete[] a;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}