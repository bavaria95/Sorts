#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	}

void selection_sort(int a[], int n)
{
	int k;
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[k])
				k = j;
		if (k != i)
			swap(a[k], a[i]);
		}
	}


int main()
{
	srand(time(NULL));
	int n;
	cin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100;
		}

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << '\n';

	selection_sort(A, n);
	
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << '\n';
	}