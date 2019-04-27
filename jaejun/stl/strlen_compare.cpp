#include <iostream>
#include <ctime>
#include <cstring>

//#pragma warning(disable:4996)
using namespace std;

#define N 1234567

inline int len(register const char *a) {
	register const char *b = a;
	while (*a++);
	return a - b - 1;
}

inline int len2(register const char *a) {
	register const char *b = a;
	for (; *b; b++);
	return b - a;
}

inline int len3(register const char *a) {
	register const char *b = a;
	for (; *b++;);
	return b - a;
}

inline int len4(register const char *a) {
	register const char *b = a;
	for (b = a; *b; b++);
	return b - a;
}

inline int len5(register const char *a) {
	register const char *b = a;
	while (1) {
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
		if (!*b)
			break;
		b++;
	}
	return b - a;
}
int main() {
	char a[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	int start;

	cout << endl;

	start = clock();
	for (int i = 0; i < N; i++) {
		strlen(a);
	}
	cout << clock() - start << endl;

	start = clock();
	for (int i = 0; i < N; i++) {
		len(a);
	}
	cout << clock() - start << endl;

	start = clock();
	for (int i = 0; i < N; i++) {
		len2(a);
	}
	cout << clock() - start << endl;

	start = clock();
	for (int i = 0; i < N; i++) {
		len3(a);
	}
	cout << clock() - start << endl;

	start = clock();
	for (int i = 0; i < N; i++) {
		len4(a);
	}
	cout << clock() - start << endl;

	start = clock();
	for (int i = 0; i < N; i++) {
		len5(a);
	}
	cout << clock() - start << endl;

	return 0;
}