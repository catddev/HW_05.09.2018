#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// 1.	�������� ���������, ������� ������� �� ����������� �������, ������������ ���������� �������, ������, ���������� ������� ��������.
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







// 3.	�������� ������������ ������, �������� � ������ ������ ���������������� �����, � �� ������ - �������.
//����������� ����� �� ID � �� ������ �������� � ����������� ����� � ��������� ������.






int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "������ � ";
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

			delete[] a;
		}
		break;
		case 2:
		{
		// 2.	�������� ���������, ������� ����������� ��������� ��� ������������ ��������� �������,
		// ����������� ���������� ������� � ��������� ��������� � ������� �������.
		// ������� �������� �������� �������� �������������.
			int **a, **b;
			int na, ma, nb, mb;
			cin >> na >> ma >> nb >> mb;
			a = new int*[na];
			b = new int*[nb];

			for (int i = 0; i < na; i++)
				a[i] = new int[ma];

			for (int i = 0; i < nb; i++)
				b[i] = new int[mb];

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
					cout<<
			}

		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "��� ����� ������" << endl << endl;
		}
	}
	system("pause");
	return 0;
}