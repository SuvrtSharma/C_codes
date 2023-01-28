#include <stdio.h>
#include <string.h>

const char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

const char morse_alpha[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z'
};

void convert_to_morse(char *text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A';
            for (j = 0; j < strlen(morse_code[c]); j++) {
                printf("%c", morse_code[c][j]);
            }
            printf(" ");
        } else if (c >= 'a' && c <= 'z') {
            c = c - 'a';
            for (j = 0; j < strlen(morse_code[c]); j++) {
                printf("%c", morse_code[c][j]);
            }
            printf(" ");
        } else if (c == ' ') {
            printf(" ");
        }
    }
}

void convert_to_alpha(char *text) {
    int i, j;
    char morse[10000];
    int k = 0;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            morse[k] = '\0';
            for (j = 0; j < 26; j++) {
                if (strcmp(morse, morse_code[j]) == 0) {
                    printf("%c", morse_alpha[j]);
                    break;
                }
            }
            k = 0;
        } else {
            morse[k] = text[i];
            k++;
        }
    }
    morse[k] = '\0';
    for (j = 0; j < 26; j++) {
        if (strcmp(morse, morse_code[j]) == 0) {
            printf("%c", morse_alpha[j]);
            break;
        }
    }
    printf("\n");
}

int main() {
    char text[10000];
    int a;
    printf("select\n1>english to morse\n2>morse to english\n");
    scanf("%d",&a);
    if(a==1){
    printf("Enter text to convert to morse code: ");
    scanf("%s", text);
    printf("Morse code: ");
    convert_to_morse(text);
    }
    else if(a==2){
    printf("Enter text to convert to english: ");
    scanf("%s", text);
    printf("english: ");
    convert_to_alpha(text);
        
    }
   
    return 0;
}

