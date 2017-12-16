#ifndef __OS_RBTREE_H__
#define __OS_RBTREE_H__

namespace OS_RBTREE
{
	enum COLOR { RED, BLACK };

	template <class T>
	struct NODE
	{
		T key;
		NODE *left, *right, *parent;
		int size;
		COLOR color;
	};

	template <class T>
	class OS_RBtree
	{
	public:
		using nptr = NODE<T>*;
	private:
		nptr root;
		int n;
		nptr sentinel;

		void insert_fixup(nptr x);
		void delete_fixup(nptr x);
		void transparent(nptr u, nptr v);
		void left_rotation(nptr x);
		void right_rotation(nptr x);
		nptr min_subtree(nptr x);
		nptr max_subtree(nptr x);
		void print_tree(nptr x);
		void cleaner(nptr x);
	
	public:
		OS_RBtree();
		void insertion(T key);
		nptr search(T key);
		void deletion(nptr x);
		int black_height(nptr x);
		int isempty();
		int size();
		T max();
		T min();
		T select(int i);
		int rank(nptr x);
		nptr successor(nptr x);
		nptr predecessor(nptr x);
		void print();
		void nonrecursive_print();
		~OS_RBtree();
	};
}

#include "OS_RBtree.cpp"
#endif