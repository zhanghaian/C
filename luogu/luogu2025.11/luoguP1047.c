#include <stdio.h>

int main() {
    long l, m;
    scanf("%ld %ld", &l, &m);

    int removed[100001] = {0};
    
    while ( m-- ) {
        int u, v;
        scanf("%d %d", &u, &v);
        for ( int i = u; i <= v; i++ ) {
            removed[i] = 1;
        }
    }

    int cnt = 0;
    for ( int i = 0; i <= l; i++ ) {
        if ( !removed[i] ) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}