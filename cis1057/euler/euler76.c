#include <stdlib.h>
#include <stdio.h>

/**
 * PROJECT EULER #76
 * Counting Summations
 *
 * It is possible to write five as a sum in exactly six different ways:
 *
 *                      4 + 1
 *                      3 + 2
 *                      3 + 1 + 1
 *                      2 + 2 + 1
 *                      2 + 1 + 1 + 1
 *                      1 + 1 + 1 + 1 + 1
 *
 * How many different ways can one hundred be written as a sum of at least
 * two positive integers?
 */

int main(int argc, char *argv[]) 
{
    // Check if user provided exactly one argument
    if (argc != 2) {
        printf("Usage: %s <positive integer>\n", argv[0]);
        return 1;
    }

    // Convert the input argument to an integer
    int target = atoi(argv[1]);

    if (target < 2) {
        printf("Please enter a number greater than or equal to 2.\n");
        return 1;
    }

    int ways[target + 1];
    for (int i = 0; i <= target; i++) {
        ways[i] = 0;
    }
    ways[0] = 1;

    for (int part = 1; part < target; part++) {
        for (int sum = part; sum <= target; sum++) {
            ways[sum] += ways[sum - part];
        }
    }

    printf("Number of ways to write %d as a sum of at least two positive integers: %d\n", target, ways[target]);
    
    return EXIT_SUCCESS;
}