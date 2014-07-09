#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void sort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = A[i];

		for (j = i - 1; j >= 0 && A[j] > key; j--)
			A[j + 1] = A[j];
		
		A[j + 1] = key;
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
	{
		cout << A[i] << ' ';
		}
	cout << '\n';

	sort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << ' ';
		}
	cout << '\n';
	}