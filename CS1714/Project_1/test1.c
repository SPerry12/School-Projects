#include <stdio.h>
#include <stdlib.h>
int randomInt;
int main()
{
    int i;
    srand(time(0));
    for (i = 0; i < 4; ++i) {
        randomInt = rand() % 4;
        printf("%d\n", randomInt);
    }
    return 0;
}
