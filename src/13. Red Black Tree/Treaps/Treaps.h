#ifndef __Treaps_H__
#define __Treaps_H__

namespace TREAPS
{
	enum{MAX_PRIORITY = 1000000000};

	template <class T>
	struct NODE
	{
		T key;
		NODE *left, *right, *parent;
		int priority;
	};

	template <class T>
	class Treaps
	{
	public:
		using nptr = NODE<T>*;
	private:
		nptr root;
		int n;
		nptr sentinel;

		void insert_fixup(nptr x);
		void left_rotation(nptr x);
		void right_rotation(nptr x);
		nptr min_subtree(nptr x);
		nptr max_subtree(nptr x);
		void print_tree(nptr x);
		void cleaner(nptr x);

	public:
		Treaps();
		void insertion(T key);
		nptr search(T key);
		void deletion(nptr x);
		int isempty();
		int size();
		T max();
		T min();
		nptr successor(nptr x);
		nptr predecessor(nptr x);
		void print();
		void nonrecursive_print();
		~Treaps();
	};
}
#include "Treaps.cpp"
#endif