#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// reverse string and return new string
char* reverse(char str[]) {
    int len = strlen(str);
    char *out = malloc(len + 1);   
    // allocate output
    for (int i = 0; i < len; i++)
        out[i] = str[len - 1 - i]; 
        // copy reversed
    out[len] = '\0';               
    // end string
    return out;
}

int main() {
    char text[50] = "I Love You";
    char *out = reverse(text);
    printf("%s\n", out);
    free(out);                     
    // free memory
    return 0;
}
