#define SIZE 65536

int arr_sorted[SIZE];

void sort(int *arr, int len) {
	if (len < 2)
		return;
    
	register int mid = len / 2, i = 0, j = mid, k = 0;

	sort(arr, mid);
	sort(arr + mid, len - mid);
 
	while ((i < mid) && (j < len)) {
		if (arr[i] < arr[j])
			arr_sorted[k++] = arr[i++];
		else
			arr_sorted[k++] = arr[j++];
	}

	while (i < mid) 
		arr_sorted[k++] = arr[i++];
 
	while (j < len)
		arr_sorted[k++] = arr[j++];
 
    for (register int i = 0; i < len; ++i) {
		arr[i] = arr_sorted[i];
	}
}
