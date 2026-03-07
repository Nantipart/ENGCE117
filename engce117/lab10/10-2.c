#include <stdio.h>

void moveTower(int disks, int start, int end);

int main()
{
    int total = 3;

    moveTower(total, 1, 3);

    return 0;
}

void moveTower(int disks, int start, int end)
{
    if(disks <= 0)
        return;

    int middle = 6 - start - end;

    if(disks > 1)
    {
        moveTower(disks - 1, start, middle);
    }

    printf("Move disk %d from rod %d to rod %d\n", disks, start, end);

    if(disks > 1)
    {
        moveTower(disks - 1, middle, end);
    }
}