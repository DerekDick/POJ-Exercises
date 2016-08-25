#include <stdio.h>
#include <string.h> //For strlen() and memset()

char n[10] = "";

void printTop(char c, int width);
void printUpper(char c, int width);
void printMiddle(char c, int width);
void printLower(char c, int width);
void printBottom(char c, int width);

int main(int argc, char* argv[]) {
	int s = 0;
	
	//Input and output in loops
	while (scanf("%d %s", &s, &n) != EOF) {
		//Check for the end of input
		if (!s) {
			break;
		}
		
		int i, j, length = strlen(n);
		//Top layer
		for (i = 0; i < length; i++) {
			printTop(n[i], s);
			printf(" ");
		}
		printf("\n");
		
		//Upper layer
		for (j = 0; j < s; j++) {
			for (i = 0; i < length; i++) {
				printUpper(n[i], s);
				printf(" ");
			}
			printf("\n");
		}
		
		//Middle layer
		for (i = 0; i < length; i++) {
			printMiddle(n[i], s);
			printf(" ");
		}
		printf("\n");
		
		//Lower layer
		for (j = 0; j < s; j++) {
			for (i = 0; i < length; i++) {
				printLower(n[i], s);
				printf(" ");
			}
			printf("\n");
		}
		
		//Bottom layer
		for (i = 0; i < length; i++) {
			printBottom(n[i], s);
			printf(" ");
		}
		printf("\n");
		
		//A new line
		printf("\n");
		
		//Reset
		memset(n, 0, 10);
	}
	
	return 0;
}

void printTop(char c, int width) {
	printf(" ");
	int i;
	if (c == '1' || c == '4') {
		for (i = 0; i < width; i++) {
			printf(" ");
		}
	}
	else {
		for (i = 0; i < width; i++) {
			printf("-");
		}
	}
	printf(" ");
	
	return;
}

void printUpper(char c, int width) {
	if (c == '1' || c == '2' || c == '3' || c == '7') {
		printf(" ");
		int i;
		for (i = 0; i < width; i++) {
			printf(" ");
		}
		printf("|");
	}
	else if (c == '5' || c == '6') {
		printf("|");
		int i;
		for (i = 0; i < width; i++) {
			printf(" ");
		}
		printf(" ");
	}
	else {
		printf("|");
		int i;
		for (i = 0; i < width; i++) {
			printf(" ");
		}
		printf("|");
	}
	
	return;
}

void printMiddle(char c, int width) {
	printf(" ");
	int i;
	if (c == '0' || c == '1' || c == '7') {
		for (i = 0; i < width; i++) {
			printf(" ");
		}
	}
	else {
		for (i = 0; i < width; i++) {
			printf("-");
		}
	}
	printf(" ");
	
	return;
}

void printLower(char c, int width) {
	if (c == '2') {
		printf("|");
		int i;
		for (i = 0; i < width; i++) {
			printf(" ");
		}
		printf(" ");
	}
	else if (c == '0' || c == '6' || c == '8') {
		printf("|");
		int i;
		for (i = 0; i < width; i++) {
			printf(" ");
		}
		printf("|");
	}
	else {
		printf(" ");
		int i;
		for (i = 0; i < width; i++) {
			printf(" ");
		}
		printf("|");
	}
	
	return;
}

void printBottom(char c, int width) {
	printf(" ");
	int i;
	if (c == '1' || c == '4' || c == '7') {
		for (i = 0; i < width; i++) {
			printf(" ");
		}
	}
	else {
		for (i = 0; i < width; i++) {
			printf("-");
		}
	}
	printf(" ");
	
	return;
}
