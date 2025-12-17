#include <stdio.h>

int main() {
    int N, i;

    // 1. รับค่า N
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    // 2. ประกาศ Array ขนาด N
    int scores[N];

    // 3. รับค่าตัวเลข N ตัว เก็บลง Array
    for (i = 0; i < N; i++) {
        if (scanf("%d", &scores[i]) != 1) {
            return 1;
        }
    }

    // 4. แสดงผลจากท้ายไปหน้า
    for (i = N - 1; i >= 0; i--) {
        printf("%d\n", scores[i]);
    }

    return 0;
}
