#include <stdio.h>

long intervals[50000][2] = { { 0 } };
int max(int int1, int int2, int int3);
void quicksort(long arr[][2], int begin, int end);

int main(int argc, char* argv[]) {
	int n = 0;
	scanf("%d", &n);

	//Input all the initial intervals
	int i = 0;
	for (i = 0; i < n; i++) {
		scanf("%ld %ld", &intervals[i][0], &intervals[i][1]);
	}

	//Sort
	quicksort(intervals, 0, n - 1);

	//Merge and output
	int current[2] = { 0 };
	for (i = 0; i < n; i++) {
		if (!i) {
			current[0] = intervals[0][0];
			current[1] = intervals[0][1];
			continue;
		}
		else if (current[1] < intervals[i][0]) {
			printf("%ld %ld\n", current[0], current[1]);
			current[0] = intervals[i][0];
			current[1] = intervals[i][1];
		}
		else {
			current[1] = max(current[1], intervals[i][0], intervals[i][1]);
		}
	}
	printf("%ld %ld\n", current[0], current[1]);

	return 0;
}

int max(int int1, int int2, int int3) {
	int temp1 = (int1 > int2) ? int1 : int2;
	return (temp1 > int3) ? temp1 : int3;
}

void quicksort(long arr[][2], int begin, int end) {
	//Set the pivot
	int pivot = arr[end][0];

	//Partition
	int i = begin, j = end;
	while (i < j) {
		while (arr[i][0] < pivot) {
			i++;
		}
		while (pivot < arr[j][0]) {
			j--;
		}
		if (i < j) {
			int temp1 = arr[i][0];
			int temp2 = arr[i][1];
			arr[i][0] = arr[j][0];
			arr[i][1] = arr[j][1];
			arr[j][0] = temp1;
			arr[j][1] = temp2;
			i++;
			j--;
		}
		else if (i == j) {
			i++;
			j--;
		}
	}

	//Recursion
	if (begin < j) {
		quicksort(arr, begin, j);
	}
	if (i < end) {
		quicksort(arr, i, end);
	}

	return;
}
