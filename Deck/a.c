#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.c"
// #include "deck.h"
#define MAX 30

int main(void)
{
    srand(time(0));
    cria_db_carta();
    printf("%i\n", rand());
    libera_db_carta();
    return 0;
}