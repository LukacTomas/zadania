/* 
* C program na generovanie náhodných čísiel
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(void)
{

    // Použijeme funckciu time(0) z kniznice time.h
    // na naplnenie počiatku pseudonáhodnej funkcie
    srand(time(0));
    printf("RAND_MAX: %d\n", RAND_MAX);
    for (int i = 0; i < SIZE; i++)
    {
        // rand vygeneruje nahodne cislo medzi 0 - RAND_MAX
        printf(" %d ", rand());
    }

    // Ak chcem zmenit max pocet t.j. generovanie od 0 - MAX
    int max = 10;
    printf("\nMAX: %d\n", max);
    for (int i = 0; i < SIZE; i++)
    {
        // rand vygeneruje nahodne cislo medzi 0 - RAND_MAX
        printf(" %d ", rand() % (max + 1));
    }
    printf("\n");

    return 0;
}
