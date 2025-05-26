#include <stdio.h>
#define MAX 10
void warshall(int n, int A[MAX][MAX], int R[MAX][MAX]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            R[i][j] = A[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
            }
        }
    }
}
void printMatrix(int n, int R[MAX][MAX]) {
    int i, j;
    printf("Transitive closure matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
}
int main() {
    printf("ATUL RAJ \n 1AY23CS045\n");
    int n, i, j;
    int A[MAX][MAX];
    int R[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (0 or 1) row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    warshall(n, A, R);
    printMatrix(n, R);
    return 0;
}
