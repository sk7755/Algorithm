#ifndef __LINEAR_SORT_H__
#define __LINEAR_SORT_H__

#include <cstdlib>

void Counting_Sort(int a[], int n, int left, int right);
/*
counting sort (int array)

<Input>
1.	array adress
2.	array size
3.	lower bound of source array
4.	upper bound of source array

<output>
1.	sorted int array

<specific>
1.	stable
2.	not in place
3.	O(k+n) Time Complexity	(k = right - left + 1)
4.	O(k) Space Complexity
*/

void Radix_Sort(int a[], int n);
/*
Radix sort (int array)

<Input>
1.	array adress
2.	array size

<output>
1. sorted int array

<specific>
1.	stable
2.	not in place
3.	O( (b/r)(n + 2^r) ) Time Complexity (b = size of bit, r = radix )
In this code, b = 32, I select 2^r = 10
So O(n) Time Complexity
4.	O(n) Space Complexity
*/

void Bucket_Sort(int a[], int n, int left, int right);
/*
Bucket sort (int array)

<Input>
1.	array adress
2.	array size
3.	lower bound of source array
4.	upper bound of source array

<output>
1.	sorted int array

<specific>
1.	Actually this code is not stable, But It can be stable
2.	not in place
3.	O(n) Expected Time Complexity
4.	O(n) Space Complexity
*/

#endif