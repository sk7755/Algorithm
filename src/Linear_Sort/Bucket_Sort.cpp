#include "Linear_Sort.h"

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