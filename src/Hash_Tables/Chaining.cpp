#include "Chaining.h"

Chaining::Chaining(int n, int(*hash)(int, int)) :n(n), hash(hash)
{
	data = new nptr[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = new NODE;
		data[i]->next = data[i]->pre = data[i];
		data[i]->key = sentinel;
	}
}
void Chaining::insertion(int key)
{
	int x = hash(key, n);
	printf("%d insert\n", x);
	nptr pnew = new NODE;
	pnew->key = key;
	pnew->next = data[x];
	pnew->pre = data[x]->pre;
	pnew->pre->next = pnew;
	pnew->next->pre = pnew;
	data[x] = pnew;
}
nptr Chaining::search(int key)
{
	int x = hash(key, n);
	for (nptr p = data[x]; p->key != sentinel; p = p->next)
	{
		if (p->key == key)
			return p;
	}

	return nullptr;
}
void Chaining::deletion(nptr p)
{
	if (!p)
		return;

	int x = hash(p->key, n);

	p->next->pre = p->pre;
	p->pre->next = p->next;

	if (data[x] == p)
		data[x] = p->next;
	delete p;
}

void Chaining::print()
{
	for (int i = 0; i < n; i++)
	{
		for (nptr p = data[i]; p->key != sentinel; p = p->next)
		{
			printf("%d ", p->key);
		}
		if(data[i]->key != sentinel)
			printf("\n");
	}
}

Chaining::~Chaining()
{
	for (int i = 0; i < n; i++)
	{
		nptr del = nullptr;
		for (nptr p = data[i]; p->key != sentinel; p = p->next)
		{
			if (del)
				delete del;
			del = p;
		}
		delete del;
	}
	delete[]data;
}