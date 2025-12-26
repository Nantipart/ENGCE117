#include <stdio.h>
#include <string.h>

/* function prototype */
void vowelCounter(const char *text, int *total);

int main(void) {
    char sentence[100];
    int vowelTotal = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    /* remove newline */
    sentence[strcspn(sentence, "\n")] = '\0';

    vowelCounter(sentence, &vowelTotal);

    printf("\n--- VOWEL COUNT REPORT ---\n");
    printf("Sentence : \"%s\"\n", sentence);
    printf("Vowels   : %d\n", vowelTotal);

    return 0;
}

/* count vowels using pointer traversal */
void vowelCounter(const char *text, int *total) {
    while (*text != '\0') {
        char ch = *text;

        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
            ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') {
            (*total)++;
        }
        text++;   // move pointer
    }
}
