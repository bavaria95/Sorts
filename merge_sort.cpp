#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

void merge(int A[], int p, int q, int r)		//merging two sorted arrays in one
{
	int n1 = q - p + 1;		//size of first array
	int n2 = r - q;		   //size of second array

	int L[n1 + 1];		//sorted left part of array
	int R[n2 + 1];	   //sorted rigth part of array
	int i, j;

	for (i = 0; i < n1; i++)	
		L[i] = A[p + i];			//copy left sorted part of array to accessory array

	for (j = 0; j < n2; j++)
		R[j] = A[q + j + 1];		//the same with rigth part

	L[n1] = INT_MAX;				//trick that makes possible not to check 
	R[n2] = INT_MAX;			   //emptiness in both accessory arrays		

	i = 0;
	j = 0;
	for (int k = p; k <= r; k++)
		if (L[i] <= R[j])			//properly merging
		{						   //as two decks of cards
			A[k] = L[i];
			i++;
			}
		else
		{
			A[k] = R[j];
			j++;
			}
	}

void mergeSort(int A[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = ((p + r) / 2);		//middle of array

		mergeSort(A, p, q);			//recursively sort left half
		mergeSort(A, q + 1, r);	   //recursively sort rigth half
		merge(A, p, q, r);			 //merge that two halfs
		}
	}

int main()
{
	srand(time(NULL));
	int n;

	cin >> n;
	int *A = new int[n];
	for (int i = 0; i <= n; i++)
	{
		A[i] = rand() % 20;
		}
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << ' ';
		}
	cout << "\n\n";

	mergeSort(A, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << ' ';
		}
	cout << '\n';
	}