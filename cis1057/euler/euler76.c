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
        printf("Usage: %s positive integer\n", argv[0]); //Prints error statement
                                                        //If user does not input more than 2 values
        return 1;
    }

    int target = atoi(argv[1]); //Using atoi() convert string argv[1] into integer
                                //target: number of sums that add up to 100 we want to find

    if (target < 2) {
        printf("Please enter a number greater than or equal to 2.\n");  // If number is not at least 2, prints statement
                                                                        //needs to sum at least 2 posititve integers
        return 1;
    }

    int ways[target + 1];   //array index starts at 0, so target + 1
                            //trying to find how many ways 100 can be calculated
    for (int i = 0; i <= target; i++) { 
        ways[i] = 0; //avoiding garbage values present
    }
    ways[0] = 1; //represents 1 way to write number "0" as sum

    for (int numberToUse = 1; numberToUse < target; numberToUse++) { //numberToUse: Numbers allowed to use (between 1-99)
                                                        //initialized ways[0] to 1
                                                        //Numbers that we are allowed to use to add up to sum
                                                        //Loops as long as numberToUse is less than number needed to find
        for (int sum = numberToUse; sum <= target; sum++) { //sum = target
                                                            //target: number of ways to add up to a certain number (100 in here)
            ways[sum] += ways[sum - numberToUse]; //finds the number of "ways" to add up to int sum
                                                //since sum <= target, numberToUse is number being tested
                                                //right side finds the 
                                                //thought process: If I aleready know how many ways I can make "sum - numberToUse", 
                                                //    then I can make "sum" by adding "numberToUse" to each of those combinations
        }
    }

    printf("Number of ways to write %d as a sum of at least two positive integers: %d\n", target, ways[target]);
    
    return EXIT_SUCCESS;
}