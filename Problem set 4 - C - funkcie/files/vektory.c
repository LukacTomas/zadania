/** 
 * Subor:    vektory.c 
 * Autor:  Tomas Lukac (lukac@fajnorka.sk) 
 * 
 * Datum:   19. jula 2020 
 * 
 * Predmet: PRJ 2020
 * Trieda:  Učiteľ
 * 
 * Opis suboru: 
 * 
 *  Program na spocitanie zakladnych operacii s vektormi
 *  ako velkost a uhol(cos)[t.j. odchylka]
 * 
 *  TODO 
 *  porozmyslat nad lepsou definiciou vstupnych suborov
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/**
*   Funkcia velkost
*   vrati velkost vektora pocitanu od pociatku suradnic    
*   
*                   (x,y)             (x,y)
*   Ak je vektor od (0,0) smerujuci k (1,0) jeho velkost je 1
*
*                   (x,y)             (x,y)
*   Ak je vektor od (0,0) smerujuci k (0,1) jeho velkost je 1
*
*                   (x,y)             (x,y)
*   Ak je vektor od (0,0) smerujuci k (3,4) jeho velkost je 5
*
*   Ak je vektor od (0,0,0) smerujuci k (3,4,0) jeho velkost je 5
*
*
*   Ak je vetktor od (0,0,0) smerujuci k (3,4,5) jeho velkost je 7.07
*
*   Odporucam pozriet https://onlinemschool.com/math/assistance/vector/length/
*
*
*  Vo vseobecnost vsak vektor nemusi mat dlzku 2 alebo 3, ale vektorLength
*/

double velkost(const int vektor[], int vektorLength)
{
    double velkost = 0.0;

    for (unsigned int i = 0; i < vektorLength; ++i)
    {
        velkost += pow(vektor[i], 2);
    }
    return sqrt(velkost);
}

/*
*   Funkcia odchylka
*   vrati odchylku alebo uhol medzi dvoma vektormi
*
*   
*   Nech je vektor1[3] = {5,6,7} a vektor2[3] = {-5,6,6},
*   tak ochylka je 0.513090
*
*   a ochylku spocitame ako
*   
*   odchylka = produkt(vektor1, vektor2) / (velkost(vektor1) * velkost(vektor2))
*   
*   t.j. produkt vektorov podeleni sucinom velkosti jednotlivych vektorov
*
*   Ako ale spocitame produkt?
*   produkt(vektor1, vektor2) = vektor1[0]*vektor2[0] + vektor1[1]*vektor2[1] + at+d
*
*
*   Odporucam pozriet https://onlinemschool.com/math/assistance/vector/angl/
*
*   Vo vseobecnost vsak vektor nemusi mat dlzku 2 alebo 3, ale vektorLength
*   Predpokladajme, pre jednoduchost ze vektory maju rovnaku dlzku
*/
double odchylka(const int vektor1[], int vektor1Length, const int vektor2[], int vektor2Length)
{
    // TODO Dopis podla poziadaviek vyssie

    return 0;
}

int main(void)
{
    int size = 3;
    int vektor1[3] = {5, 6, 7};
    int vektor2[3] = {-5, 6, 6};
    printf("Velkost vektora1 je %.2f\n", velkost(vektor1, size));
    printf("Velkost vektora2 je %.2f\n", velkost(vektor2, size));
    printf("Odchylka (uhol) je %f\n", odchylka(vektor1, size, vektor2, size));
}