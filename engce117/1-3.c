#include <stdio.h>
#include <stdlib.h>

// Prototype ฟังก์ชัน
int *GetSet(int *memberCount);

// --- ส่วน Main (สำหรับรันเทสในเครื่อง) ---
int main() {
    // แก้ CLO3: ประกาศตัวแปรแยกบรรทัด
    int *resultSet; 
    int count = 0;

    // เรียกใช้ฟังก์ชัน
    resultSet = GetSet(&count);

    printf("Output: ");
    for(int i = 0; i < count; i++) {
        printf("%d ", resultSet[i]);
    }
    printf("\n");

    // คืนค่าหน่วยความจำ
    if (resultSet != NULL) {
        free(resultSet);
    }

    return 0;
}
// ----------------------------------------

// --- ส่วนคำตอบที่ต้องเอาไปส่ง (Copy เฉพาะส่วนนี้ไปส่งได้) ---
int *GetSet(int *memberCount) {
    int *setArray; // เปลี่ยนชื่อตัวแปรให้สื่อความหมาย

    // 1. รับจำนวนสมาชิก
    printf("Number of members: ");
    scanf("%d", memberCount);

    // 2. จองพื้นที่หน่วยความจำ
    // แก้ CLO4: ตรวจสอบความปลอดภัยหลังจอง
    setArray = (int*) malloc(*memberCount * sizeof(int));

    // เช็คว่าเมมโมรี่เต็มไหม (Safety check)
    if (setArray == NULL) {
        printf("Memory allocation error\n");
        exit(1); 
    }

    // 3. รับค่าสมาชิกทีละตัว
    printf("Input values:\n");
    // แก้ CLO2: ใช้ Loop ถูกต้องแล้ว
    for (int k = 0; k < *memberCount; k++) {
        printf("Member %d: ", k + 1);
        scanf("%d", &setArray[k]);
    }

    // ส่ง Pointer กลับไปที่ main
    return setArray;
}