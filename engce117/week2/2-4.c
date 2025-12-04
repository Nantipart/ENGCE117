#include <stdio.h>
#include <stdlib.h>

// Function Prototype
int *GetMatrix(int *row, int *col);

int main() {
    // [Fix CLO3]: ประกาศตัวแปรแยกบรรทัด เพื่อให้อ่านง่ายและไม่โดนแจ้งเตือน Multiple statements
    int *data;
    int m;
    int n;

    // เรียกใช้ฟังก์ชันตามเดิม
    data = GetMatrix(&m, &n);

    // [Fix CLO4]: เพิ่มความเสถียร (Stability) เช็คว่าได้ข้อมูลกลับมาจริงไหม กันโปรแกรมเด้ง
    if (data == NULL) {
        printf("Error: Allocation failed or invalid dimensions.\n");
        return 1; // จบโปรแกรมแบบแจ้ง error
    }

    printf("\n--- Result ---\n");
    printf("Matrix Size: %d x %d", m, n);
    printf("\nData: ");
    
    // ส่วนแสดงผล
    for (int i = 0; i < m * n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // [Fix CLO4]: คืนหน่วยความจำเสมอ (ป้องกัน Memory Leak)
    free(data);

    return 0;
}

// ----------------------------------------------------

int *GetMatrix(int *ptrRow, int *ptrCol) {
    int *myMatrix;

    // 1. รับขนาด Matrix
    printf("Enter dimensions (Rows): ");
    scanf("%d", ptrRow); // [Fix Logic]: เอา ptrCol ออก รับทีละค่าให้ถูกต้อง

    printf("Enter dimensions (Cols): ");
    scanf("%d", ptrCol);

    // [Fix CLO4]: ตรวจสอบค่าก่อนจอง (กัน User ใส่ 0 หรือ ติดลบ)
    if (*ptrRow <= 0 || *ptrCol <= 0) {
        return NULL;
    }

    // 2. จองหน่วยความจำ
    int totalSize = (*ptrRow) * (*ptrCol);
    myMatrix = (int *)malloc(totalSize * sizeof(int));

    // ตรวจสอบว่าจองสำเร็จไหม
    if (myMatrix == NULL) {
        return NULL;
    }

    // 3. รับข้อมูล
    printf("Input data elements:\n");
    for (int k = 0; k < totalSize; k++) {
        scanf("%d", &myMatrix[k]);
    }

    // 4. ส่งค่ากลับ
    return myMatrix;
}