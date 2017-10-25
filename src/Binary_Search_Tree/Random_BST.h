#ifndef __RANDOM_BST_H__
#define __RANDOM_BST_H__

#include "BST.h"

template <class T>
class Random_BST : public BST<T>
{
public:
	Random_BST(T a[], int n);
};

#endif