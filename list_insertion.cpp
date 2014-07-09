#include <iostream>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int val;
	node *next;
};

void sort(node *first)
{
	node *iter_prev = first;
	node *iter_curr = first -> next;

	while (iter_curr -> next -> next!= NULL)
	{
		int key = iter_curr -> val;
		node *front_prev = first;
		node *front_curr = first -> next;

		if (iter_curr -> val < iter_prev -> val)
		{
			while ((front_curr != iter_curr) && (front_curr -> val < key))
			{
				front_prev = front_curr;
				front_curr = front_curr -> next;
				}

			node *tmp1 = iter_prev;
			node *tmp2 = iter_curr -> next;

			front_prev -> next = iter_curr;
			iter_prev -> next = iter_curr -> next;

			iter_curr -> next = front_curr;

			iter_prev = tmp1;
			iter_curr = tmp2;
			}
		else
		{
			iter_prev = iter_curr;
			iter_curr = iter_curr -> next;
			}

		}
	}

int main()
{
	srand(time(NULL));
	node *first;
	node *curr;
	node *begin;
	node *tmp;

	first = new node;
	begin = first;
	first -> val = INT_MIN;

	curr = new node;
	first -> next = curr;

	int n, w;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		w = rand() % 100;
		cout << w << " ";
		curr -> val = w;
		tmp = new node;
		curr -> next = tmp;
		curr = tmp;
		}
	cout << '\n';

	tmp = new node;
	tmp -> val = INT_MAX;
	curr -> next = tmp;

	node *backup = begin;
	sort(backup);

	begin = begin -> next;
	while (begin -> next -> next != NULL)
	{
		cout << begin -> val << ' ';
		begin = begin -> next;
		}

	cout << '\n';

	}