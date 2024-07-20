/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the result matrix
    int** matrix = (int**)malloc(rowSumSize * sizeof(int*));
    for (int i = 0; i < rowSumSize; i++) {
        matrix[i] = (int*)malloc(colSumSize * sizeof(int));
    }

    // Initialize the matrix with zeros
    for (int i = 0; i < rowSumSize; i++) {
        for (int j = 0; j < colSumSize; j++) {
            matrix[i][j] = 0;
        }
    }

    // Fill the matrix according to rowSum and colSum
    for (int i = 0; i < rowSumSize; i++) {
        for (int j = 0; j < colSumSize; j++) {
            // Find the value to put in the matrix
            int value = rowSum[i] < colSum[j] ? rowSum[i] : colSum[j];
            matrix[i][j] = value;
            rowSum[i] -= value;
            colSum[j] -= value;
        }
    }

    // Set return values
    *returnSize = rowSumSize;
    *returnColumnSizes = (int*)malloc(rowSumSize * sizeof(int));
    for (int i = 0; i < rowSumSize; i++) {
        (*returnColumnSizes)[i] = colSumSize;
    }

    return matrix;
}

// Helper function to print the matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

