#include <stdio.h>
#include <stdlib.h>
/*
2
hi my name is eric
afghiwghwg wfgwg
*/
int main()
{
    int N;
    scanf("%d ", &N);

    int n;
    for(n = 1; n <= N; n++)
    {
        char s[100];

        scanf("%[^\n] ", s);
        printf("%s Just do it!\n", s);
    }
}
