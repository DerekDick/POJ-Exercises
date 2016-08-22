#include <stdio.h>

int triangle[5050] = { 0 };

int max(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, char* argv[]) {
    int N = 0;
    scanf("%d", &N);
    
    //Input the triangle
    int num = N * (N + 1) / 2;
    int i = 0;
    for (i = 0; i < num; i++) {
        scanf("%d", &triangle[i]);
    }
    
    //Calculate the maximum of the sum
    for (i = N - 1; i > 0; i--) {
        int begin = i * (i - 1) / 2;
        int j = 0;
        for (j = 0; j < i; j++) {
            triangle[begin + j] += max(triangle[begin + j + i], triangle[begin + j + i + 1]);
        }
    }
    
    //Output
    printf("%d\n", triangle[0]);
    
    return 0;
}
