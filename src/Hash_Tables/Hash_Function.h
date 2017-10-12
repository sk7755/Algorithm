#ifndef __HASH_FUNCTION_H__
#define __HASH_FUNCTION_H__

#include <cstdlib>
#include <ctime>

int division_hash(int key, int m);
int multiplication_hash(int key, int p);
int universal_hash(int key, int m);
int linear_hash(int key, int i, int m);
int quadratic_hash(int key, int i, int m);
int double_hash(int key, int i, int m);
int gcd(int a, int b);

#endif