/** 
 * Subor:    cezar.c 
 * 
 * Autor1:  Tomas Lukac (lukac@fajnorka.sk) 
 * 
 * Datum:   18. jula 2020 
 * Partner: Farjnorka 
 * Predmet: PRJ 2020
 * 
 * 
 * Opis suboru: 
 * 
 *  Program zasifruje cezarovou sifrou spravu
 *  Nacita kluc
 *  Nacita text na sifrovanie
 *  Vypise sifru
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Velkost buffera pri nacitavani znakov
// Pri mensej hodnote sa castejsie vola realloc
// Zrejme ale nebudeme siforvat dlhe texty
// A nejde nam o rychlost programu
#define BUFFER_SIZE 100

// Maximalny pocet stringov co moze zadat
// nemal by byt vacsi ako 2
// nechajme 10
#define SIZE 10

// Contajner s ukazovatelmi na pole znakov
// aby valgrind nespiskoval
// a pekne sme odstranovali pamat
char *strings[SIZE];
int number_of_strings = 0;

// Funkciu zavolame pri ukonceni main
void cleanUp(void) __attribute__((destructor));

// Uvolni vsetku pamat pri vypnuti programu
void cleanUp(void)
{
    for (unsigned int i = 0; i < number_of_strings; ++i)
    {
        free(strings[i]);
    }
}

// Jednoducha funkcia na ziskanie textu
char *get_string()
{
    // Veľkost buffera je allocation
    int allocation = BUFFER_SIZE;
    char *buffer = calloc(allocation, sizeof(char *));

    unsigned int counter = 0;
    // c musi byt int lebo getchar vracia -1 pri EOF
    int c;
    while ((c = getchar()) != '\r' && c != '\n' && c != EOF)
    {
        *(buffer + counter++) = c;
        if (counter == allocation)
        {
            allocation = 2 * allocation;
            buffer = realloc(buffer, allocation);
        }
    }
    // aj posledny char - '\0'
    buffer[counter] = '\0';

    // sprav miesto v pamati pre presnu velkost textu
    char *text = calloc(counter, sizeof(char *));

    // skopiruj buffer do text
    strcpy(text, buffer);

    // uvolni buffer
    free(buffer);

    // ulož ukazovatel na text do pola char *strings[]
    // aby som mohol potom text uvolnit pri ukonceni progrmu
    strings[number_of_strings++] = text;
    return text;
}

int main(void)
{
    /*************** NACITAJ KLUC *****************/
    printf("Kluc: ");
    unsigned int kluc = atoi(get_string());
    /**********************************************/

    /************** NACITAJ TEXT ******************/
    printf("Nesifrovany text: ");
    char *text = get_string();
    /**********************************************/

    printf("Sifrovany text: ");
    /**
     *  TODO 
     *  Vypíš na obrazovku šifrovaný text zo znakov v poli znakov "text"
     *  Zašifruj len písmená bez diakritiky
     *  Nešifruj písmená z diakritikou, čísla a iné znaky
     *  Program musí rozlišovať malé a veľké písmená t.j. 
     *  vstup „ahoj“ nie je ten istý ako „Ahoj“ alebo „aHoJ“
     *  Šifru nemusíš ukladať do novej premennej, stačí vypísať znaky na obrazovku
     *  
     *  ci= (pi  + k) % 26 ak index je 0
     *  index A je ale 65
     *  index a je ale 97
     * 
     *  pomocka vyuzite funkcie isupper() a islower() definovane v kniznici ctype.h
     * */
    /* ZACIATOK TVOJHO PROGRAMU PRE Cezara */

    // TODO

    /* KONIEC TVOJHO PROGRAMU PRE Bargraph */

    return EXIT_SUCCESS;
}