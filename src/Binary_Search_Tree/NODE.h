#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class NODE
{
public:
	T key;
	NODE<T> *left, *right, *parent;

	NODE(T key, NODE<T> *left = nullptr, NODE<T> *right = nullptr, NODE<T> *parent= nullptr) : key(key), left(left),right(right),parent(parent) {}
};

#endif