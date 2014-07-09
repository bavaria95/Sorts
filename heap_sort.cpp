#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int parent(int i)
{
	return (i - 1)/2;
	}

int left(int i)
{
	return 2 * i + 1;
	}

int right(int i)
{
	return 2 * i + 2;
	}

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
	}

void Heapify(int A[], int i, int n)
{
	int largest = i;
	int l = left(i);
	int r = right(i);

	if ((l < n) && (A[l] > A[largest]))
		largest = l;

	if ((r < n) && (A[r] > A[largest]))
		largest = r;

	if (i != largest)
	{
		swap(A[i], A[largest]);
		Heapify(A, largest, n);
		}
	}

void Build_Heap(int A[], int n)
{
	for (int i = parent(n - 1); i >= 0; i--)
	{
		Heapify(A, i, n);
		}
	}

void Heap_Sort(int A[], int n)
{
	Build_Heap(A, n);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(A[0], A[i]);
		Heapify(A, 0, i);
		}
	}


int main()
{
	int n = 20000000;
	int *A = new int[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = rand();
		}

	Heap_Sort(A, n);

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\n";
	}