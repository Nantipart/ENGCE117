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

int *GetMatrix(int *ptrRow, int *ptrCol) {
    int *myMatrix; // เปลี่ยนชื่อจาก matrix_ptr เป็น myMatrix

    // 1. รับขนาดมิติของเมทริกซ์
    // ใช้คำสั่ง printf นำทางเพื่อให้รู้ว่าต้องกรอกอะไร
    printf("Enter dimensions (Rows Cols): ");
    scanf("%d %d", ptrRow, ptrCol);

    // 2. จองพื้นที่หน่วยความจำ (Allocation)
    // สูตร: แถว * คอลัมน์ * ขนาดของ int
    int totalSize = (*ptrRow) * (*ptrCol);
    myMatrix = (int *)malloc(totalSize * sizeof(int));

    // ตรวจสอบว่าจองได้จริงไหม (แก้เรื่อง Stability CLO4)
    if (myMatrix == NULL) {
        return NULL; // ถ้าจองไม่ได้ให้ส่งค่าว่างกลับไป
    }

    // 3. รับค่าสมาชิกแต่ละตัว
    printf("Input data elements:\n");
    for (int k = 0; k < totalSize; k++) {
        // ใช้ scanf รับค่าใส่ใน pointer array โดยตรง
        scanf("%d", &myMatrix[k]);
    }

    // 4. ส่ง address ของ array กลับไป
    return myMatrix;
}