/** 
 * Subor:  matematika.c 
 * Autor:  Tomas Lukac (lukac@fajnorka.sk) 
 * 
 * Datum:   19. jula 2020 
 * 
 * Predmet: PRJ 2020
 * Trieda:  Učiteľ
 * 
 * Opis suboru: 
 * 
 *  Program na spocitanie zakladnych mat. operacii
 *  ako priemer, minimum, maximum
 * 
 *  
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER_SIZE 10

/*
*   FUNKCIA Priemer
*   Funkcia priemer spočíta priemer kladných hodnôt z poľa arr
*   Vstupné parametre:
*       -   const unsigned int *arr         = pole premenných // napr. arr[0] = 1 arr[1] = 5
*       -   const unsigned int arr_length   = veľkosť pola, počet hodnôt v poli
*
*   Výstupné parametre:
*       - float **priemer** - priemer hodnôt z pola
*   Príklad
*   Ak arr = {1,2,3,4}, tak arr_length = 4
*   priemer sa spočíta ako (1+2+3+4)/4 = 2,5
*/
float priemer(const unsigned int arr[], const unsigned int arr_length)
{
    // TODO - napíšte funkciu podľa požiadaviek vyššie
    float priemer = 0;

    return priemer;
}

/*
*   FUNKCIA Maximum
*   Funkcia maximum nájde maximum kladných hodnôt z poľa arr
*   Vstupné parametre:
*       -   const unsigned int *arr         = pole premenných // napr. arr[0] = 1 arr[1] = 5
*       -   const unsigned int arr_length   = veľkosť pola, počet hodnôt v poli
*
*   Výstupné parametre:
*       - unsigned int **maximum** - index kde sa nachádza maximum
*   Príklad
*   Ak arr = {1,8,3,5}, tak arr_length = 4
*   tak maximum je cislo 8 v indexi 1 a funkcia vrati cislo 1
*
*   Ak arr = {9,8,14,1}, tak arr_length = 4
*   tak maximum je cislo 14 v indexi 2 a funkcia vrati cislo 2
*   
*/
unsigned int maximum(const unsigned int arr[], const unsigned int arr_length)
{
    // TODO - napíšte funkciu podľa požiadaviek vyššie
    unsigned int index = 0;

    return index;
}

/*
*   FUNKCIA Minumum
*   Funkcia Minimum nájde minimum kladných hodnôt z poľa arr
*   Vstupné parametre:
*       -   const unsigned int *arr         = pole premenných // napr. arr[0] = 1 arr[1] = 5
*       -   const unsigned int arr_length   = veľkosť pola, počet hodnôt v poli
*
*   Výstupné parametre:
*       - unsigned int **minumu** - index kde sa nachádza minimum
*   Príklad
*   Ak arr = {1,8,3,5}, tak arr_length = 4
*   tak minimum je cislo 1 v indexi 0 a funkcia vrati cislo 0
*
*   Ak arr = {9,8,14,1}, tak arr_length = 4
*   tak minimum je cislo 1 v indexi 3 a funkcia vrati cislo 3
*   
*/
unsigned int minimum(const unsigned int arr[], const unsigned int arr_length)
{
    // TODO - napíšte funkciu podľa požiadaviek vyššie

    unsigned int index = 0;

    return index;
}

int main(int argc, char *argv[])
{

    // Ak nezadal vstupný argumnet skonči
    if (argc != 2)
    {
        printf("Musíš zadať jeden názov súboru\n");
        printf("Použitie: ./priemer numbers_small.txt\n");
        return 0;
    }

    // Názov súboru na otvorenie
    char *filename = argv[1];

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
    // Spočítaj priemer
    float p = priemer(arr, arr_length);

    // Nájdi index kde je maximum
    unsigned int indexMaxima = maximum(arr, arr_length);

    // Nájdi index kde je minimum
    unsigned int indexMinima = minimum(arr, arr_length);

    printf("Priemer z hodnôt je %.2f\n", p);
    printf("Maximum sa nachádza na pozici %d a je to cislo %d\n", indexMaxima, arr[indexMaxima]);
    printf("Minimum sa nachádza na pozici %d a je to cislo %d\n", indexMinima, arr[indexMinima]);

    // Uvoľni miesto v pamäti
    free(arr);
    printf("\n\n...\nPri práci sme v pamäti zabrali %.2f kB\n", (float)sizeof(temp) * (float)arr_length / 1024.0);
}