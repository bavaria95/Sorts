#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
	}

int partition(int A[], int p, int q)
{
	int x = A[q - 1];
	int i = p - 1;
	for (int j = p; j < q - 1; j++)
	{
		if (A[j] <= x)
			swap(A[j], A[++i]);
		}
	swap(A[++i], A[q - 1]);
	return i;
	}

void quick_sort(int A[], int p, int q)
{
	if (p < q)
	{
		int r = partition(A, p, q);
		quick_sort(A, p, r);
		quick_sort(A, r + 1, q);
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

	quick_sort(A, 0, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << '\n';
	}