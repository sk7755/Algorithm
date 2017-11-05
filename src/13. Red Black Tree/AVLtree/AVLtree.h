#ifndef __AVLTREE_H__
#define __AVLTREE_H__

namespace AVLTREE
{
	template <class T>
	struct NODE
	{
		T key;
		NODE *left, *right, *parent;
		int height;
	};

	template <class T>
	class AVLtree
	{
	public:
		using nptr = NODE<T>*;
	private:
		nptr root;
		nptr sentinel;
		int n;

		void balance(nptr x);
		inline int max(int a, int b)
		{
			return a > b ? a : b;
		}
		nptr min_subtree(nptr x);
		nptr max_subtree(nptr x);
		void transparent(nptr u, nptr v);
		void left_rotation(nptr x);
		void right_rotation(nptr x);
		void destruct_subtree(nptr x);
	public:
		AVLtree();
		void insertion(T key);
		nptr search(T key);
		void deletion(nptr x);
		int isempty();
		int size();
		T max();
		T min();
		int height();
		nptr successor(nptr x);
		nptr predecessor(nptr x);
		void print();
		~AVLtree();
	};
}
#include "AVLtree.cpp"
#endif