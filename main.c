#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main()
{
    printf("Projet Euler probleme 4 : \n\n");

    int i, j, resultat, palindrome;
    NombrePalindrome nombre;

    for(i=999; i>99; i--)
    {
        for(j=i; j>99; j--)
        {
            resultat = i*j;

            palindrome = verifPalindrome(resultat);

            if(palindrome == 1 && nombre.resultat < resultat)
            {
                nombre.x = i;
                nombre.y = j;
                nombre.resultat = resultat;
            }
        }
    }
    printf("Le plus grand nombre palindrome est : %d x %d = %d\n", nombre.x, nombre.y, nombre.resultat);
    return 0;
}

int remplirTableau(int nombre, char tableau[])
{
    int i, longueurTableau = 0;

    for(i=0; i<6; i++)
    {
        tableau[i] = nombre%10;
        nombre = nombre/10;
        longueurTableau++;

        if(nombre<=0)
        {
            break;
        }
    }

    return longueurTableau;
}

int verifPalindrome(int nombre)
{
    int i, j, longueurNombre, palindrome;
    char tableau[6];

    longueurNombre = remplirTableau(nombre, tableau);

    palindrome = 1;
    for(i=0, j=longueurNombre-1; i<j; i++, j--)
    {
        if(tableau[i] != tableau[j])
        {
            palindrome = 0;
            break;
        }
    }

    return palindrome;
}

