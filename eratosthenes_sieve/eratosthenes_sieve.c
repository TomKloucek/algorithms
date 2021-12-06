#include<stdio.h>
#include <stdlib.h>

int main(char *argv[] ) {
    int max = atoi(argv[1]);
    int cisla[max];
    max = max-2;
    for (int i = 0; i <= max; i++) {
        cisla[i] = i+2;
    }
    for(int i = 2; i <= max; i++) {
        for(int j = 2; j <= (max/i)+1;j++) {
            if (i*j <= max+2) {
                cisla[(i*j)-2] = 0;
            }
            else {
                break;
            }
        }
    }
    int pocet = 0;
    for (int i = 0; i <= max; i++) {
        if (cisla[i] != 0) {
            pocet++;
        }
    }
    int vysledek[pocet];
    int count = 0;
    for (int i = 0; i <= max; i++) {
        if (cisla[i] != 0) {
            vysledek[count] = cisla[i];
            count++;
        }
    }
/*
    for (int i = 0; i < pocet; i++) {
       printf("%d,",vysledek[i]);
    }
*/
    return 0;
}
