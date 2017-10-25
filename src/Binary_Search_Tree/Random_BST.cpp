#include "Random_BST.h"
#include "../Random_Permute/Random_Permute.h"

Random_BST::Random_BST(int a[], int n) : BST()
{
	knuth_shuffle(a, n);
	for (int i = 0; i < n; i++)
		insertion(a[i]);
}