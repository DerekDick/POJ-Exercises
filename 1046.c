#include <stdio.h>

int main(int argc, char* argv[]) {
	//Input the target set of colors
	int target[16][3] = { { 0, 0, 0 } };
	int i = 0;
	for (i = 0; i < 16; i++) {
		scanf("%d", &target[i][0]);
		scanf("%d", &target[i][1]);
		scanf("%d", &target[i][2]);
	}
	
	//Input and output in loops
	int current[3] = { 0, 0, 0 };
	while (1) {
		scanf("%d", &current[0]);
		scanf("%d", &current[1]);
		scanf("%d", &current[2]);
		//Check the end of input
		if (current[0] == -1 && current[1] == -1 && current[2] == -1) {
			break;
		}
		//If not the end, find the nearest and output it
		printf("(%d,%d,%d) maps to ", current[0], current[1], current[2]);
		//Bubble sort
		int nearest[3] = { target[0][0], target[0][1], target[0][2] };
		int distanceSquare = (current[0] - target[0][0]) * (current[0] - target[0][0]) + (current[1] - target[0][1]) * (current[1] - target[0][1]) + (current[2] - target[0][2]) * (current[2] - target[0][2]);
		for (i = 1; i < 16; i++) {
			int temp = (current[0] - target[i][0]) * (current[0] - target[i][0]) + (current[1] - target[i][1]) * (current[1] - target[i][1]) + (current[2] - target[i][2]) * (current[2] - target[i][2]);
			if (temp < distanceSquare) {
				distanceSquare = temp;
				nearest[0] = target[i][0];
				nearest[1] = target[i][1];
				nearest[2] = target[i][2];
			}
		}
		printf("(%d,%d,%d)\n", nearest[0], nearest[1], nearest[2]);
	}
	
	return 0;
}
