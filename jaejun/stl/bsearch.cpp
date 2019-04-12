//#pragma GCC optimize ("O3")
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N (1 << 22)
#define M 1 << 20

/* STL�� �ִ� �� */
int compare(void const *first, void const *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

/* �Ϲ� (�Ｚ ä�� �������������� ��� STL���� ����) */
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

/* ����ȭ 1 - "���⼭��" m�� �����ͷ� ������� �ʴ°� ���� �� ���� �� ���� */
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

/* ����ȭ 2 - "=="�� ���� ���� �幮 ���̽��� ���� �Ʒ� ��ġ */
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

/* ����ȭ 3 - ������ ��� "��Ʈ ������" ��� */
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

/* ����ȭ 4 - �� ���̱� */
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


/* ����ȭ 5 - �ݺ��� ���� */
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
