#include "Linear_Sort.h"

/*

Bucket sort (int array)

<Input>
1.	array adress
2.	array size
3.	lower bound of source array
4.	upper bound of source array

<output>
1.	sorted int array

<specific>
1.	Actually this code is not stable, But It can be stable
2.	not in place
3.	O(n) Expected Time Complexity
4.	O(n) Space Complexity

*/

typedef struct node* nptr;

struct node
{
	int key;
	nptr link;
};

void Bucket_Sort(int a[], int n, int left, int right)
{
	nptr* head = (nptr*)malloc(sizeof(nptr)* n);

	for (int i = 0; i < n; i++)
		head[i] = NULL;

	for (int i = 0; i < n; i++)
	{
		nptr pnew = (nptr)malloc(sizeof(node));
		int bucket = (long long)(a[i] - left) * (long long)n / (long long)(right - left + 1);
		pnew->key = a[i];
		pnew->link = head[bucket];
		head[bucket] = pnew;
	}

	int k = 0;
	for (int i = 0; i < n; i++)
	{
		nptr del = NULL;
		for (nptr p = head[i]; p; p = p->link)
		{
			if (del)
				free(del);
			a[k++] = p->key;
			del = p;
		}
		if (del)
			free(del);
	}

	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i;
		while (j>0 && a[j - 1] > key)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = key;
	}

	free(head);
}