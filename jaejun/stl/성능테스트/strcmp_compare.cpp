#include <iostream>
#include <cstring>
#include <ctime>
#define N 12345678
using namespace std;

/* 단순한 구현 */
inline int equal1(register const char *a, register const char *b) {
	register int len_a = sizeof(a) / sizeof(char);
	register int len_b = sizeof(b) / sizeof(char);
	if (len_a != len_b)
		return 0;
	for (register int i = 0; i < len_a; i++) {
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

/* const 빼고 포인터 접근 */
inline int equal2(register char *a, register char *b) {
	register int len_a = sizeof(a) / sizeof(char);
	register int len_b = sizeof(b) / sizeof(char);
	if (len_a != len_b)
		return 0;
	register char *p = a;
	register char *q = b;
	for (register int i = 0; i < len_a; i++) {
		if (*p++ != *q++)
			return 0;
	}
	return 1;
}

/* return 순서 최적화 */
inline int equal3(register const char *a, register const char *b) {
	if (sizeof(a) != sizeof(b))
		return 0;
	register int len = sizeof(a) / sizeof(char);

	for (register int i = 0; i < len; i++) {
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

/* reference from: https://code.woboq.org/userspace/glibc/string/strcmp.c.html */
inline int equal4(register const char *a, register const char *b) {

	register const unsigned char *s1 = (const unsigned char *)a;
	register const unsigned char *s2 = (const unsigned char *)b;
	register unsigned char c1, c2;
	do
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0')
			return c1 - c2;
	} while (c1 == c2);
	return c1 - c2;
}

/* reference from: https://muyu.tistory.com/entry/strcmp-문자열-비교-함수-구현-코드-문자열-포인터 */
inline int equal5(register const char *a, register const char *b) {
	for (; *a == *b; a++, b++)
		if (*a == '\0')
			return 0;

	return *a - *b;
}

/* 5 최적화 */
inline int equal6(register const char *a, register const char *b) {
	while (1) {
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
		if (!*a)
			return 0;
		a++;
		b++;
	}
	return *a - *b;
}

int main() {
	char a[] = "abcdef";
	char b[] = "abcdef";

	int start;

	cout << endl;

	start = clock();
	for (int i = 0; i < N; i++)
		strcmp(a, b);
	cout << clock() - start << endl;

	start = clock();
	for (int j = 0; j < N; j++)
		equal1(a, b);
	cout << clock() - start << endl;

	start = clock();
	for (int j = 0; j < N; j++)
		equal2(a, b);
	cout << clock() - start << endl;

	start = clock();
	for (int j = 0; j < N; j++)
		equal3(a, b);
	cout << clock() - start << endl;

	start = clock();
	for (int j = 0; j < N; j++)
		equal4(a, b);
	cout << clock() - start << endl;

	start = clock();
	for (int j = 0; j < N; j++)
		equal5(a, b);
	cout << clock() - start << endl;

	start = clock();
	for (int j = 0; j < N; j++)
		equal6(a, b);
	cout << clock() - start << endl;

	return 0;
}