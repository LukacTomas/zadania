/** 
 * Subor:   bargraph.c 
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
 * Vypise vertikalny graf z hodnot co nacita z pola
 *    ###
 *    ###
 *    ###
 *    --- 
 *     3
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER_SIZE 10

int main(int argc, char *argv[])
{
   // ak nezadal vstupný argumnet skonči
   if (argc != 2)
   {
      printf("Musis zadat jeden nazov suboru\n");
      printf("Pouzitie: ./bargraph numbers_small.txt\n");
      return 0;
   }

   char *filename = argv[1]; // názov súboru na otvorenie

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

   /* ZACIATOK TVOJHO PROGRAMU PRE Bargraph */

   // TODO

   /* KONIEC TVOJHO PROGRAMU PRE Bargraph */

   // Uvoľni miesto v pamäti
   free(arr);
   printf("\n\n...\nPri praci sme v pamati zabrali %.4f kB\n", (float)sizeof(temp) * (float)arr_length / 1024.0);
   return EXIT_SUCCESS;
}