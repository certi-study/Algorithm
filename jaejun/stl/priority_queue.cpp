#include <iostream>
using namespace std;

#define MAX_SIZE 128

int heap[MAX_SIZE];
int heapSize = 0;
/* 이유는 모르겠지만 이 상황에서는 함수로 변수 넘기는 것 보다 전역 변수가 빠르다 */
/* 아마 함수 인자가 많아져서인듯? */

/* reference: https://www.swexpertacademy.com */
inline void heapInit(void) {
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
		/* swap 함수 안쓰니 시간이 반 덜걸림... */
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
	register int temp, child, left = (current << 1) + 1, right = 0;
	while (left < heapSize) {
		right = left + 1;
		child = (right == heapSize) ? left : (heap[left] < heap[right] ? left : right);

		if (heap[current] < heap[child])
			break;

		temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		current = child;
		left = (current << 1) + 1;
	}
	return 1;
}
