#include <stdio.h>
#define MAX 15

void StringCount( char s[] );
void ReadString( char s[] );

int main() {

    char s[MAX];

    ReadString(s);
    StringCount(s);

    return 0;
}

void StringCount( char s[] ) {
    int letter = 0, blank = 0, digit = 0, other = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
            letter++;
        else if (c == ' ' || c == '\n')
            blank++;
        else if (c >= '0' && c <= '9')
            digit++;
        else
            other++;
    }

    printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
}

void ReadString(char s[] ) {

}