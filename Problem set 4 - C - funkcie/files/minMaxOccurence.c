#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER_SIZE 10

/*
*   FUNKCIA minMaxOccurence
*   Funkcia minMaxOccurence spočíta maximum a minimum a ich početnosť kladných hodnôt z poľa
*   Vstupné parametre:
*       -   const unsigned int *arr         = pole premenných // napr. arr[0] = 1 arr[1] = 5
*       -   const unsigned int arr_length   = veľkosť pola, počet hodnôt v poli
*
*   Výstupné parametre:
*       -
*   Príklad
*   Ak arr = {1,1,3,4}, tak arr_length = 4
*   minimum je 1 a jeho početnosť je 2
*   maximum je 4 a jeho početnosť je 1
*/
void minMax(const unsigned int arr[], const unsigned int arr_length)
{
    unsigned int maximum = arr[0];
    unsigned int maxOccurence = 1;
    unsigned int minimum = arr[0];
    unsigned int minOccurence = 1;

    // TODO - napíšte funkciu podľa požiadaviek vyššie

    printf("Maximum z poľa čísiel je: %d a jeho početnosť je %d\n", maximum, maxOccurence);
    printf("Minimum z poľa čísiel je: %d a jeho početnosť je %d\n", minimum, minOccurence);
}

int main(int argc, char *argv[])
{

    // ak nezadal vstupný argumnet skonči
    if (argc != 2)
    {
        printf("Musíš zadať jeden názov súboru\n");
        printf("Použitie: ./minMaxOccurence numbers_small.txt\n");
        return 0;
    }

    char *filename = argv[1]; // názov súboru na otvorenie

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Nemôžem otvoriť súbor: %s\n", filename);
        return 0;
    }

    // Na priebežnú zmenu dĺžky pola
    unsigned int allocation = BUFFER_SIZE;

    // Na ukladanie hodnôť - Pole arr
    unsigned int *arr = malloc(allocation * sizeof(unsigned int));

    // počítadlo dĺžky pola a kde sa má hodnota temp uložiť
    unsigned int counter = 0;

    // Na ukladanie priebežne načítaných hodnôt
    unsigned int temp;

    // Scanuj až do konca súboru
    while (fscanf(file, "%d", &temp) != EOF)
    {
        // Dymicky si realocuj miesto v pamäti
        // Skontroluj ci sme vytvorili pamat
        if (counter == allocation)
        {
            allocation *= 2;
            arr = realloc(arr, allocation * sizeof(unsigned int));
            assert(arr != NULL);
        }

        // Zapíš do arr na správne miesto v pamäti
        *(arr + counter++) = temp;
    }
    fclose(file);

    // Dĺžka poľa;
    const unsigned int arr_length = counter;

    // zavolaj funkciu
    minMax(arr, arr_length);
    // uvoľni miesto v pamäti
    free(arr);
    printf("\n\n...\nPri práci sme v pamäti zabrali %.2f kB\n", (float)sizeof(temp) * (float)arr_length / 1024.0);
}
