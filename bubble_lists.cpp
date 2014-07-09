#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

struct node
{
	int w;
	node *next;
	};

void sort(node *first)
{
	node *prev;
	node *curr;
	node *following;
	node *iter = first;

	while (iter != NULL)
	{
		prev = first;
		curr = prev->next;
		following = curr->next;

		while (following->next != NULL)
		{
			if (curr->w > following->w)
			{
				prev->next = following;
				curr->next = following->next;
				following->next = curr;
				}
			prev = curr;
			curr = following;
			following = following->next;
			}
		iter = iter->next;
		}
	}

int main()
{
	srand(time(NULL));
	int n, w;
	cin >> n;

	node *first;
	node *begin;
	node *current;

	first = new node;
	first->w = INT_MIN;
	begin = first;

	current = new node;
	first->next = current;
	first = current;

	for (int i = 0; i < n; i++)
	{
		// cin >> w;
		w = rand() % 100;
		cout << w << " ";
		first->w = w;
		current = new node;

		first->next = current;
		first = current;
		}
	cout << "\n";

	node *tmp = begin;
	sort(begin);
	tmp = tmp -> next;
	while (tmp->next != NULL)
	{
		cout << tmp->w << " ";
		tmp = tmp->next;
		}

	cout << "\n";
	}