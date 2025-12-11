#include <stdio.h>

// split string by splitter
void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0, j = 0, k = 0;
    *count = 0;

    while (str1[i] != '\0') {
        if (str1[i] == splitter) {      
            // found separator
            str2[j][k] = '\0';          
            // end word
            j++;                        
            // next word
            k = 0;                      
            // reset index
        } else {
            str2[j][k++] = str1[i];     
            // append char
        }
        i++;
    }

    str2[j][k] = '\0';                   
    // last word
    *count = j + 1;                      
    // total words
}

int main() {
    char out[20][10];
    int num;

    explode("I/Love/You", '/', out, &num);

    for (int i = 0; i < num; i++)
        printf("%s\n", out[i]);

    printf("count = %d\n", num);
    return 0;
}
