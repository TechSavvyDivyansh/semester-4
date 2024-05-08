// gpt code 

#include <stdio.h>

#define N 2 // Define the size of the matrices

void strassen(int A[][N], int B[][N], int C[][N], int n);
void add(int A[][N], int B[][N], int C[][N], int n);
void subtract(int A[][N], int B[][N], int C[][N], int n);

void strassen(int A[][N], int B[][N], int C[][N], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize], M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Divide matrices A and B into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate seven products recursively
    strassen(A11, B11, temp1, newSize); // M1 = (A11 + A22) * (B11 + B22)
    strassen(A12, B21, temp2, newSize); // M2 = (A21 + A22) * (B11)
    add(A11, A22, temp1, newSize);      // A11 + A22
    add(B11, B22, temp2, newSize);      // B11 + B22
    strassen(temp1, temp2, M1, newSize); // M1 = (A11 + A22) * (B11 + B22)

    add(A21, A22, temp1, newSize); // A21 + A22
    strassen(temp1, B11, M2, newSize); // M2 = (A21 + A22) * (B11)

    subtract(B12, B22, temp1, newSize); // B12 - B22
    strassen(A11, temp1, M3, newSize);   // M3 = (A11) * (B12 - B22)

    subtract(B21, B11, temp1, newSize); // B21 - B11
    strassen(A22, temp1, M4, newSize);   // M4 = (A22) * (B21 - B11)

    add(A11, A12, temp1, newSize); // A11 + A12
    strassen(temp1, B22, M5, newSize); // M5 = (A11 + A12) * (B22)

    subtract(A21, A11, temp1, newSize); // A21 - A11
    add(B11, B12, temp2, newSize);      // B11 + B12
    strassen(temp1, temp2, M6, newSize); // M6 = (A21 - A11) * (B11 + B12)

    subtract(A12, A22, temp1, newSize); // A12 - A22
    add(B21, B22, temp2, newSize);      // B21 + B22
    strassen(temp1, temp2, M7, newSize); // M7 = (A12 - A22) * (B21 + B22)

    // Calculate C matrices
    add(M1, M4, temp1, newSize); // M1 + M4
    subtract(M7, M5, temp2, newSize); // M7 - M5
    add(temp1, temp2, C11, newSize); // C11 = M1 + M4 - M5 + M7

    add(M3, M5, C12, newSize); // C12 = M3 + M5

    add(M2, M4, C21, newSize); // C21 = M2 + M4

    add(M1, M3, temp1, newSize); // M1 + M3
    subtract(M6, M2, temp2, newSize); // M6 - M2
    add(temp1, temp2, C22, newSize); // C22 = M1 + M3 - M2 + M6

    // Combine submatrices into C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

void add(int A[][N], int B[][N], int C[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int A[][N], int B[][N], int C[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void printMatrix(int A[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{1,2} ,  {3,4}};
    int C[N][N] = {0};

    strassen(A, B, C, N);

    printf("Matrix A:\n");
    printMatrix(A, N);
    printf("\nMatrix B:\n");
    printMatrix(B, N);
    printf("\nMatrix C (Result of A * B):\n");
    printMatrix(C, N);

    return 0;
}
