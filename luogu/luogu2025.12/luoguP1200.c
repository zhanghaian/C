#include <stdio.h>
#include <string.h>


int main () {

    char comet[10], group[10];
    scanf("%9s %9s", &comet, &group);

    long long a = 1, b = 1;

    for ( int i = 0; i < strlen(comet); i++ ) {
        a *= ( comet[i] - 'A' + 1 );
    }

    for ( int i = 0; i < strlen(group); i++ ) {
        b *= ( group[i] - 'A' + 1 );
    }

    if ( a % 47 == b % 47 ) {
        printf("GO\n");
    } else {
        printf("STAY\n");
    }



    return 0;
}