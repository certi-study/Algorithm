#pragma GCC optimize ("O3")

#include <stdio.h>
#include <algorithm>
#include <time.h>
using namespace std;

#define N 100

int array_sort[N];

int main() {
	int int_n = N;
    int start;
    
    /* 일반 for문 */
    start = clock();
	for (int i = N; i-- >= 0; array_sort[i] = N - i);
	for (int i = 0; i < int_n; printf("%d\n", array_sort[i]), i++);
	printf("%d\n", clock() - start);
	
	
	/* 최적화 for문 */
    start = clock();
	for (int i = N; i-- >= 0; array_sort[i] = N - i);
    int i = 0;
    int iter = int_n / 10 - 1;
	int loc = int_n % 10;
	if (loc) iter++;
	do {
		switch (loc) {
		case 0:
            printf("%d\n", array_sort[i++]);
		case 9:
            printf("%d\n", array_sort[i++]);
		case 8:
            printf("%d\n", array_sort[i++]);
		case 7:
            printf("%d\n", array_sort[i++]);
		case 6:
            printf("%d\n", array_sort[i++]);
		case 5:
            printf("%d\n", array_sort[i++]);
		case 4:
            printf("%d\n", array_sort[i++]);
		case 3:
            printf("%d\n", array_sort[i++]);
		case 2:
            printf("%d\n", array_sort[i++]);
		case 1:
            printf("%d\n", array_sort[i++]);
		}
		loc = 0;
	} while (iter--);
	printf("%d\n", clock() - start);
    
	return 0;
}