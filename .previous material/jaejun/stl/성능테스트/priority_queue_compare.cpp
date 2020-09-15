#include <iostream>
#include <ctime>
#include <queue>
using namespace std;

#define N 1234567
#define MAX_SIZE 128

int heap[MAX_SIZE];
int heapSize = 0;
priority_queue< int, vector<int>, less<int> > pq;

void heapInit(void) {
	heapSize = 0;
}

/* reference: https://www.swexpertacademy.com */
int heapPush(register int value) {
	if (heapSize + 1 > MAX_SIZE) {
		printf("queue is full!");
		return 0;
	}

	heap[heapSize] = value;

	register int current = heapSize;
	register int temp, idx = (current - 1) >> 1;
	while (current > 0 && heap[current] < heap[idx]) {
		temp = heap[idx];
		heap[idx] = heap[current];
		heap[current] = temp;

		current = idx;
		idx = (idx - 1) >> 1;
	}

	heapSize = heapSize + 1;

	return 1;
}

/* reference: https://www.swexpertacademy.com */
int heapPop(register int *value) {
	if (heapSize <= 0) {
		return -1;
	}

	*value = heap[0];
	heapSize = heapSize - 1;

	heap[0] = heap[heapSize];

	register int current = 0;
	register int temp, child, idx = current << 1;
	while (idx + 1 < heapSize) {
		child = (idx + 2 == heapSize) ? idx + 1 : (heap[idx + 1] < heap[idx + 2] ? idx + 1 : idx + 2);

		if (heap[current] < heap[child]) {
			break;
		}

		temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		current = child;
		idx = current << 1;
	}
	return 1;
}
int main(int argc, char* argv[])
{
	int start, value;

	cout << endl;

	start = clock();
	heapInit();
	for (int i = N; i; --i) {
		pq.push(5);
        pq.push(1);
        pq.push(10);
        pq.push(2);
        pq.push(4);
        pq.pop();
        pq.pop();
        pq.pop();
        pq.pop();
        pq.pop();
	}
	cout << clock() - start << endl;

	start = clock();
	heapInit();
	for (int i = N; i; --i) {
		heapInit();
		heapPush(5);
		heapPush(1);
		heapPush(10);
		heapPush(2);
		heapPush(4);
		heapPop(&value);
		heapPop(&value);
		heapPop(&value);
		heapPop(&value);
		heapPop(&value);
	}
	cout << clock() - start << endl;

	return 0;
}