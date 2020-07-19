/** 
 * Subor:   statistika.c 
 * 
 * Autor1:  Tomas Lukac (lukac@fajnorka.sk) 
 * 
 * Datum:   18. juna 2020 
 * Partner: Farjnorka 
 * Predmet: PRJ 2020
 * 
 * 
 * Opis suboru: 
 * 
 * Program spocita a vypise kumulatívna suma a priemer
 *  
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER_SIZE 10

int main(int argc, char *argv[])
{

    // Ak nezadal vstupný argumnet skonči
    if (argc != 2)
    {
        printf("Musis zadat jeden nazov suboru\n");
        printf("Pouzitie: ./statistika numbers_small.txt\n");
        return 0;
    }
    // Názov súboru na otvorenie
    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Nemozem otvorit subor: %s\n", filename);
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

    /*
    *   TODO
    *   Dopíš program kumulatívna suma, 
    *   ktorý spočíta do nového pola cumSum komulatívnu sumu z pola arr
    *   tútú sumu následne vypíše do jednotlivých riadkov
    * 
    *   pole sa nazýva  - arr - a je to pole kladných integerov
    *   t.j. unsigned int arr;
    * 
    *   pole má dĺžku arr_length
    * 
    *   nech v poli arr je
    *   arr[0] = 5; arr[1] = 10; arr[2] = 15; arr[3] = 7;
    * 
    *   potom pole komulativnej sumy cumSum je
    *   cumSum[0] = 5; cumSum[1] = 15; cumSum[2] = 30; cumSum[3] = 37;
    * 
    */
    /* ZACIATOK TVOJHO PROGRAMU PRE KUMULATIVNU SUMU */

    // TODO

    /* KONIEC TVOJHO PROGRAMU PRE KUMULATIVNU SUMU */

    /*  
    *   TODO
    *   Dopíš program, ktorý nájde priemer v poli      
    * 
    *   pole sa nazýva  - arr - a je to pole kladných integerov
    *   t.j. unsigned int arr;
    * 
    *   pole má dĺžku arr_length
    * 
    */
    /* ZACIATOK TVOJHO PROGRAMU PRE PRIEMER */

    // TODO

    /* KONIEC TVOJHO PROGRAMU PRE PRIEMER */

    // Uvoľni miesto v pamäti
    free(arr);
    printf("\n\n...\nPri praci sme v pamati zabrali %.4f kB\n", (float)sizeof(temp) * (float)arr_length / 1024.0);
}