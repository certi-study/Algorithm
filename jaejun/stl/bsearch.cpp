//#pragma GCC optimize ("O3")
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N (1 << 22)
#define M 1 << 20

/* STL에 있는 것 */
int compare(void const *first, void const *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

/* 일반 (삼성 채점 서버에서돌려본 결과 STL보다 느림) */
int bst(int *arr, int key, int size) {
	register int * p = arr;
	register int *m;
	register int l = 0;
	register int r = size - 1;
	while (l <= r) {
		m = p + (l + r) / 2;
		if (*m == key)
			return m - p;
		else if (*m > key)
			r = m - p - 1;
		else
			l = m - p + 1;
	}
	return -1;
}

/* 최적화 1 - "여기서는" m을 포인터로 사용하지 않는게 연산 수 줄일 수 있음 */
int bst_op1(int *arr, int key, int size) {
	register int *p = arr;
	register int m;
	register int l = 0;
	register int r = size - 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (p[m] == key)
			return m;
		else if (p[m] > key)
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

/* 최적화 2 - "=="의 경우는 극히 드문 케이스라 가장 아래 배치 */
int bst_op2(int *arr, int key, int size) {
	register int *p = arr;
	register int m;
	register int l = 0;
	register int r = size - 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (p[m] > key)
			r = m - 1;
		else if (p[m] < key)
			l = m + 1;
		else
			return m;
	}
	return -1;
}

/* 최적화 3 - 나누기 대신 "비트 연산자" 사용 */
int bst_op3(int *arr, int key, int size) {
	register int *p = arr;
	register int m;
	register int l = 0;
	register int r = size - 1;
	while (l <= r) {
		m = (l + r) >> 1;
		if (p[m] > key)
			r = m - 1;
		else if (p[m] < key)
			l = m + 1;
		else
			return m;
	}
	return -1;
}

/* 최적화 4 - 비교 줄이기 */
/* reference: http://www.cplusplus.com/forum/general/170539/ */
int bst_op4(int *arr, int key, int size) {
	register int *p = arr;
	register int m;
	register int l = 0;
	register int r = size - 1;
	while (r - l > 1) {
		m = (l + r) >> 1;
		if (p[m] <= key)
			l = m;
		else
			r = m;
	}

	if (p[l] == key)
		return l;
	else
		return -1;
}


/* 최적화 5 - 반복문 제거 */
/* reference: https://stackoverflow.com/questions/20024634/how-can-i-optimize-binary-search */
int bst_op5(int *arr, int key, int size) {
	register int *p = arr;
	register int m = N >> 1;
	register int l = -1;

	if (p[m] < key) // 21
		l = N - m;
	m = m >> 1;
	if (p[l + m] < key) //20
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key) //15
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key) // 10
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key) // 5
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;
	m = m >> 1;
	if (p[l + m] < key)
		l += m;


	if (l > N or p[l] != key)
		return -1;
}

int main() {
//	srand((unsigned)time(NULL));
	int *p = (int*)malloc(sizeof(int)*N);
	int *q = (int*)malloc(sizeof(int)*M);
	for (register int i = 0; i < N; i++)
		*p++ = i;
	for (register int i = 0; i < M; i++)
		*q++ = rand() % N;

	p -= N;
	q -= M;

	int start;
	int *find;

	cout << endl;

	start = clock();
	for (register int i = 0; i < M; i++)
		find = (int*)bsearch(q + i, p, N, sizeof(int), compare);
	cout << "STL: " << clock() - start << endl;

	start = clock();
	for (register int i = 0; i < M; i++)
		*find = bst(p, *(q + i), N);
	
	cout << "No op: " << clock() - start << endl;

	start = clock();
	for (register int i = 0; i < M; i++)
		*find = bst_op1(p, *(q + i), N);
	cout << "Op1: " << clock() - start << endl;

	start = clock();
	for (register int i = 0; i < M; i++)
		*find = bst_op2(p, *(q + i), N);
	cout << "Op2: " << clock() - start << endl;

	start = clock();
	for (register int i = 0; i < M; i++)
		*find = bst_op3(p, *(q + i), N);
	cout << "Op3: " << clock() - start << endl;

	start = clock();
	for (register int i = 0; i < M; i++)
		*find = bst_op4(p, *(q + i), N);
	cout << "Op4: " << clock() - start << endl;

	start = clock();
	for (register int i = 0; i < M; i++)
		*find = bst_op5(p, *(q + i), N);
	cout << "Op5: " << clock() - start << endl;

	return 0;
}
