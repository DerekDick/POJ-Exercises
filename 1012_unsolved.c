#include <stdio.h>

int isGoodAlive(int k, int m);

int main(int argc, char* argv[]) {
	int k = 0, m = 0;

	//Input and output in loops
	while (scanf("%d", &k)) {
		//Check the end
		if (!k) {
			break;
		}

		m = k + 1;
		while (!isGoodAlive(k, m)) {
			m++;
		}
		printf("%d\n", m);
	}

	return 0;
}

int isGoodAlive(int k, int m) {
	int size = 2 * k;
	int current = -1;
	//Kill k people
	int i = 0;
	for (; i < k; i++) {
		//Kill the mth person
		current = (current + m) % size;
		if (current < k) {
			return 0;
		}
		size--;
		current--;
	}

	return 1;
}
