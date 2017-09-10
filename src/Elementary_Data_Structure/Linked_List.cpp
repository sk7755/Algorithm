#include "Linked_List.h"

Linked_List::Linked_List()
{
	sentinel = new NODE;
	sentinel->next = sentinel->pre = sentinel;
}
void Linked_List::push(int key)
{
	nptr pnew = new NODE;
	pnew->key = key;
	pnew->pre = sentinel;
	pnew->next = sentinel->next;
	sentinel->next->pre = pnew;
	sentinel->next = pnew;
}
void Linked_List::pop(nptr x)
{
	if (x == nullptr)
		return;
	x->pre->next = x->next;
	x->next->pre = x->pre;

	delete x;
}
nptr Linked_List::search(int key)
{
	for (nptr p = sentinel->next; p != sentinel; p = p->next)
	{
		if (p->key == key)
			return p;
	}

	return nullptr;
}

void Linked_List::print()
{
	for (nptr p = sentinel->next; p != sentinel; p = p->next)
	{
		printf("%d ", p->key);
	}
	printf("\n");
}

Linked_List::~Linked_List()
{
	for (nptr p = sentinel->next; p != sentinel;)
	{
		nptr del = p;
		p = p->next;
		delete del;
	}
	delete sentinel;
}