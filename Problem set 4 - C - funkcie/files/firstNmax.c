/** 
 * Subor:  firstNmax.c 
 * Autor:  Tomas Lukac (lukac@fajnorka.sk) 
 * 
 * Datum:   19. jula 2020 
 * 
 * Predmet: PRJ 2020
 * Trieda:  Učiteľ
 * 
 * Opis suboru: 
 * 
 *  Program na vypisanie prvych N maxim z pola
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#define N_MAX 100
#define BUFFER_SIZE 10

/*  FUNKCIA inArray
*   Funkcia inArray skontroluje, či sa zadaný key nachádza v poli
*   Vstupné parametre:
*       -   const unsigned int *arr         = pole premenných // napr. arr[0] = 1 arr[1] = 5
*       -   const unsigned int arr_length   = veľkosť pola, počet hodnôt v poli
*       -   const int key                   = hľadaná hodnota v poli
*   Výstupné parametre:
*       -   integer     -    i - index v ktorom je key
*       -   integer     -   -1 - ak sa key v poli nenachádza
*/

int inArray(const unsigned int *arr, int arr_length, const int key)
{

    for (unsigned int i = 0; i < arr_length; ++i)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

/*
*   FUNKCIA firstNMax
*   Funkcia firstNMax vypíše prvých N maxim kladných hodnôt z poľa, bez opakovania
*   Vstupné parametre:
*       -   const unsigned int *arr         = pole premenných // napr. arr[0] = 1 arr[1] = 5
*       -   const unsigned int arr_length   = veľkosť pola, počet hodnôt v poli
*       -   const unsigned numOfMax         = počet maxim, ktoré má vypísať
*   Výstupné parametre:
*       -
*   Príklad
*   Ak arr = {1,2,3,3,4,4}, tak arr_length = 6 a ak numOfMax = 2
*   vypíše 4, 3,
*/
void firstNMax(const unsigned int arr[], const unsigned int arr_length, const unsigned numOfMax)
{
}

int main(int argc, char *argv[])
{

    // ak nezadal vstupný argumnet skonči
    if (argc != 3)
    {
        printf("Zadal si málo vstupných parametrov\n");
        printf("Musíš zadať počet maxím do %d a jeden názov súboru\n", N_MAX);
        printf("Použitie napr.: pre 5 maxím: ./firstNMax 5 numbers_small.txt\n");
        return 0;
    }

    char *filename = argv[2]; // názov súboru na otvorenie

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Nemôžem otvoriť súbor: %s\n", filename);
        return 0;
    }

    int numOfMax = atoi(argv[1]);
    if (numOfMax < 1 || numOfMax > N_MAX)
    {
        printf("Zrejme si zadal zlý počet maxím, skús nabudúce číslo od 1 - %d\n", N_MAX);
        printf("Nateraz budem uvažovať, že chceš nájsť 5 maxím\n...\n\n");
        numOfMax = 5;
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

    // spočítaj čo potrebuješ s hodnotami
    firstNMax(arr, arr_length, numOfMax);

    // uvoľni miesto v pamäti
    free(arr);
    printf("\n\n...\nPri práci sme v pamäti zabrali %.2f kB\n", (float)sizeof(temp) * (float)arr_length / 1024.0);
}
