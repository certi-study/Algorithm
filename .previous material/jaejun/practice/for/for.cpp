#include <stdio.h>
#include <algorithm>
#include <time.h>
using namespace std;

#define N 100005

int main() {
	int int_n = N;
    int start;
    int s = 0;
    /* 일반 for문 */
    start = clock();
	for (int i = 0; i < int_n; i++){
	    s++;
	}
	printf("%d\n", clock() - start);

	register int t = 0;
	/* 최적화 for문 */
    start = clock();
    register int iter = int_n / 10;
	int loc = int_n % 10;
	
	switch (loc) {
		case 9:
            t++;
		case 8:
            t++;
		case 7:
            t++;
		case 6:
            t++;
		case 5:
            t++;
		case 4:
            t++;
		case 3:
            t++;
		case 2:
            t++;
		case 1:
            t++;
	}
	
	for(register int i = 0; i < iter; i++){
        t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;
    }
	printf("%d\n", clock() - start);
	
	t = 0;
	/* 축약 최적화 for문 */
    start = clock();
    iter = int_n / 10;
	loc = int_n % 10;
	
	switch (loc) {
		case 9:
            t++;
		case 8:
            t++;
		case 7:
            t++;
		case 6:
            t++;
		case 5:
            t++;
		case 4:
            t++;
		case 3:
            t++;
		case 2:
            t++;
		case 1:
            t++;
	}
	
	for(register int i = iter - 1; i--;){
        t++;t++;t++;t++;t++;t++;t++;t++;t++;t++;
    }
	printf("%d\n", clock() - start);
    
	return 0;
}