//	Hash functions which need to use hash table
//	CLRS 11.3 Hash functions, 11.4 Open addressing
//	Written by Jeong Jae Hoon 2017-10-17

#ifndef __HASH_FUNCTION_H__
#define __HASH_FUNCTION_H__

#include <cstdlib>
#include <ctime>

//	Hash function using division method ( modulus operation )
//	Input:	key , size of hash table
//	Output:	slot number which key go to
//	Time:	O(1)
int division_hash(int key, int m);

//	Hash function using multiplication method
//	Input:	key , size of hash table
//	Output:	slot number which key go to
//	Time:	O(1)
int multiplication_hash(int key, int p);

//	Universal hash function (random select hash function in hash class H )
//	Input:	key , size of hash table
//	Output:	slot number which key go to
//	Time:	O(1)
int universal_hash(int key, int m);

//	hash function using linear probe
//	Input:	key , i th , size of hash table
//	Output:	slot number which key go to
//	Time:	O(1)
int linear_hash(int key, int i, int m);

//	hash function using quadratic probe
//	Input:	key , i th , size of hash table
//	Output:	slot number which key go to
//	Time:	O(1)
int quadratic_hash(int key, int i, int m);

//	hash function using double hash function
//	Input:	key , i th , size of hash table
//	Output:	slot number which key go to
//	Time:	O(1)
int double_hash(int key, int i, int m);

int gcd(int a, int b);

#endif