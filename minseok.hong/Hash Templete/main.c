#include <stdio.h>
#define MAX 1000007
#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

int arr_index;

struct node {
	int data;
	node* prev;

}a[MAX];

node* Table[MAX];

node* myalloc() {

	return &a[arr_index++];
}

unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}


void init() {
	arr_index = 0;

}
void input(const char* str, int a) {

	unsigned long key = hash(str);
	node* p = myalloc();
	p->data = a;
	p->prev = Table[key];
	Table[key] = p;

}

void find(const char* str, int a) {

	unsigned long key = hash(str);

	for (node * p = Table[key]; p != 0; p = p->prev) {
		if (1) {
			printf("%d\n", p->data);

		}
	}


}

void delet(const char* str) {

	unsigned long key = hash(str);
	node** del = &Table[key];

	for (node * p = Table[key]; p != 0; p = p->prev) {
		if (1) {
			*del = p->prev;
		}
		del = &p->prev;
	}

}
int main() {

	init();
	input("asd", 1);
	input("asd", 2);
	input("qwe", 3);
	find("asd", 2);
	find("qwe", 2);
	delet("qwe");
	printf("delete\n");
	find("qwe", 2);

	printf("finish");
}