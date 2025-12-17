#include <stdio.h>

int main() {

int score;
int ok;

ok = scanf("%d",&score);

if(ok!=1){
    printf("Error");
    return 0;
}
////////////////////////////
if(score<0 || score>100){
    printf("Error");
    return 0;
}
if(score>=80 || score<=100){
    printf("grade - A");
}
else if(score>=70 || score<80){
    printf("grade - B");
}
else if(score>=60 || score<70){
    printf("grade - C");
}
else if(score>=50 || score<60){
    printf("grade - D");
}
else{
    printf("grade - F");
}
///////////////////////////
return 0;
}