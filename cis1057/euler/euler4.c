#include <stdlib.h>
#include <stdio.h>

/**
 * PROJECT EULER #4
 * Largest Palindrome Product
 *
 * A palindromic number reads the same both ways. The largest palindrome
 * made from the product of two 2-digit numbers is 9009 = 91 x 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

int main(int argc, char *argv[]) {
    //palindrome (reads same both ways) = threedigitnum_1 + threedigitnum_2
	//test for numbers between 100-999

    //incrementing each number?: takes too long
    //one

    //int x;
    //int y;
    //int product = x * y;

    int largest = 0;

    for (int x = 999; x >= 100; x--) {
        for (int y = 999; y >= 100; y--) { 
            int product = x * y;
            if (product < largest) { //allows to stop at the largest palindrome; started with largest numbers
                break;
            }
            int num = product;
            int pal = 0;
            while (num > 0) { //breaks for num <= 0
                pal = pal * 10 + num % 10; //(1) pal = palindrome
                                           //(2) "%" is a form of division: by order of operations, it is done first
                num /= 10; //reduce number 
                           //while{} process moves the last number to the front
            }
            if (pal == product) {
                largest = pal; //or product, as they should be the same number (aka palindrome)
            }
        }
    }

    printf("Largest palindrome from product of two 3-digit numbers is: %d", largest);

    return EXIT_SUCCESS;
}