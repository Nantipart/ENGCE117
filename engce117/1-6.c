#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *row, int *col);

int main() {
    int *data, m, n;

    data = GetMatrix(&m, &n);

    printf("\n--- Result ---\n");
    printf("Matrix Size: %d x %d", m, n);
    printf("Data: ");
    for(int i = 0; i < m * n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
// ----------------------------------------------------

int *GetMatrix(int *row, int *col) {
    int *matrix_ptr;

    // 1. รับจำนวนแถวและคอลัมน์
    printf("Enter number of rows and columns: ");
    scanf("%d %d", row, col);

    // 2. จองพื้นที่หน่วยความจำ
    // ขนาด = แถว x คอลัมน์ x ขนาดของ int
    matrix_ptr = (int *)malloc((*row) * (*col) * sizeof(int));

    // เช็คว่าจองสำเร็จไหม
    if (matrix_ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // 3. รับค่าสมาชิก
    printf("Enter matrix elements:\n");
    for (int i = 0; i < (*row) * (*col); i++) {
        scanf("%d", &matrix_ptr[i]);
    }

    // 4. ส่ง Pointer กลับ
    return matrix_ptr;
}