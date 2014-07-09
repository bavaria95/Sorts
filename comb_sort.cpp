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

void comb_sort(int a[], int n)
{
	int top, gap, x, i, j;
	bool swapped = true;

	gap = n;
	while (gap > 1 || swapped)
	{
		gap = max(int(gap/1.3), 1);
		top = n - gap;
		swapped = false;
		for (i = 0; i < top; i++)
		{
			j = i + gap;
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
				swapped = true;
				}
			}
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

	comb_sort(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << '\n';
	}