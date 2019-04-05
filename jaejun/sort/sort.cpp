#include <stdio.h>
#include <algorithm>
#include <time.h>
using namespace std;

#define N 100005

int array_sort[N];

/* �Ϲ����� Quick Sort */
void quick(int *arr, int l, int r) {
	int i = l;
	int j = r;
	int pivot = arr[(l + r) / 2];

	do {
		while (arr[i]<pivot)
			i++;
		while (arr[j]>pivot)
			j--;
		if (i <= j)
			swap(arr[i++], arr[j--]);
	} while (i <= j);

	if (l<j)
		quick(arr, l, j);
	if (i<r)
		quick(arr, i, r);
}

/* �Ű������� �ѱ�� ���ٴ� ���� ���� ����ؼ� �ѱ�°� ������ �� �� �ִ�. */
int x, y;
void fast_quick() {
	int i = x;
	int j = y;
	int pivot = array_sort[(x + y) / 2];

	do {
		while (array_sort[i]<pivot)
			i++;
		while (array_sort[j]>pivot)
			j--;
		if (i <= j)
			swap(array_sort[i++], array_sort[j--]);
	} while (i <= j);

    int o_y = y, o_x = x;
	if (x<j){
	    y = j;
		fast_quick();
		y = o_y;
	}
	if (i<y){
	    x = i;
		fast_quick();
		x = o_x;
	}
}

/* register ���� ���� �������� Ȯ�� �� �� �ִ�. */
void register_fast_quick() {
	register int i = x;
	register int j = y;
	register int pivot = array_sort[(x + y) / 2];

	do {
		while (array_sort[i]<pivot)
			i++;
		while (array_sort[j]>pivot)
			j--;
		if (i <= j)
			swap(array_sort[i++], array_sort[j--]);
	} while (i <= j);

    register int o_y = y, o_x = x;
	if (x<j){
	    y = j;
		register_fast_quick();
		y = o_y;
	}
	if (i<y){
	    x = i;
		register_fast_quick();
		x = o_x;
	}
}

/* ���� ���� ���� ���� ���� ���� ������ ������ �� �� �ִ�. */
int p;
void slow_quick(int *arr, int l, int r) {
	x = l;
	y = r;
	p = arr[(l + r) / 2];

	do {
		while (arr[x]<p)
			x++;
		while (arr[y]>p)
			y--;
		if (x <= y)
			swap(arr[x++], arr[y--]);
	} while (x <= y);

	if (l<y)
		slow_quick(arr, l, y);
	if (x<r)
		slow_quick(arr, x, r);
}

int main() {
	int int_n = N;
    int start;
    
    /* STL */
    start = clock();
	for (int i = N; i-- >= 0; array_sort[i] = N - i);
	sort(array_sort, array_sort + int_n);
	printf("%d\n", clock() - start);
    
    /* �Ϲ����� QSort */
    start = clock();
	for (int i = N; i-- >= 0; array_sort[i] = N - i);
	quick(array_sort, 0, int_n - 1);
	printf("%d\n", clock() - start);
	
	/* �Ű����� ���� QSort */
    start = clock();
	for (int i = N; i-- >= 0; array_sort[i] = N - i);
    x = 0, y = int_n - 1;
    fast_quick();
	printf("%d\n", clock() - start);
	
	/* �Ű����� ���� + register ���� QSort */
    start = clock();
	for (int i = N; i-- >= 0; array_sort[i] = N - i);
    x = 0, y = int_n - 1;
    register_fast_quick();
	printf("%d\n", clock() - start);
	
	/* �������� ���� ���� QSort */
    start = clock();
	for (int i = N; i-- >= 0; array_sort[i] = N - i);
	slow_quick(array_sort, 0, int_n - 1);
	printf("%d\n", clock() - start);
	
	return 0;
}