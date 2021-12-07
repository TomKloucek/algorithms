#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[] ) {
    // argument from terminal means maximum number
    int max = atoi(argv[1]);
    int cisla[max];
    max = max-2;
    // fill the array with numbers from 2 to max
    for (int i = 0; i <= max; i++) {
        cisla[i] = i+2;
    }
    // the sieve, for number in array, go through all his multiples and change their values to zero
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

    // then all numbers which are not zeroes are the prime numbers

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

    printf("%d",count);

    // ### Results
    // Prime numbers under 25 - time: 0,002s
    // Prime numbers under 100,000 - time: 0,002s
    // Prime numbers under 250,000 - time: 0,003s
    // Prime numbers under 1,000,000 - time: 0,058s

    return 0;
}
