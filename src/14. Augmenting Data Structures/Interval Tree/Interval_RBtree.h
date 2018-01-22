#ifndef __INTERVAL_RBTREE_H__
#define __INTERVAL_RBTREE_H__

#include <iostream>
using namespace std;

namespace INTERVAL_RBTREE
{
	enum COLOR { RED, BLACK };

	class interval
	{
	public:
		int s, f;
		friend ostream& operator<<(ostream& os, const interval i);
		friend istream& operator>>(istream& is, interval& i);
	};

	struct NODE
	{
		interval i;
		NODE *left, *right, *parent;
		int max;
		COLOR color;
	};

	class Interval_RBtree
	{
	public:
		using nptr = NODE*;
	private:
		nptr root;
		int n;
		nptr sentinel;

		void insert_fixup(nptr x);
		void delete_fixup(nptr x);
		void transparent(nptr u, nptr v);
		void left_rotation(nptr x);
		void right_rotation(nptr x);
		void print_tree(nptr x);
		void cleaner(nptr x);
		int isOverlap(interval a, interval b);
		inline nptr MAX(nptr x, nptr y)
		{
			if (x == sentinel)
				return y;
			else if (y == sentinel)
				return x;
			else
				return x->max > y->max ? x : y;
		}

	public:
		Interval_RBtree();
		void insertion(interval i);
		nptr search(interval i);
		void deletion(nptr x);
		int isempty();
		int size();
		void print();
		void nonrecursive_print();
		~Interval_RBtree();
	};
}

#endif