#include <stdlib.h>
#include <stdio.h>

/**
 * PROJECT EULER #19
 * Counting Sundays
 *
 * You are given the following information, but you may prefer to do some
 * research for yourself.
 *
 * - 1 Jan 1900 was a Monday.
 * - Thirty days has September,
 *   April, June and November.
 *   All the rest have thirty-one,
 *   Saving February alone,
 *   Which has twenty-eight, rain or shine.
 *   And on leap years, twenty-nine.
 * - A leap year occurs on any year evenly divisible by 4, but not on a
 *   century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth
 * century (1 Jan 1901 to 31 Dec 2000)?
 */

int main(int argc, char *argv[]) {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sunCount = 0;
    int month;
    int year;
    int dayOfWeek = 1; // January 1, 1900 was a Monday (1)

    // First, advance through 1900 to get to January 1, 1901
    // 1900 is not a leap year (divisible by 100, not by 400)
    monthDays[1] = 28; // February 1900 has 28 days
    
    for(month = 1; month <= 12; month++)
    {
        dayOfWeek = (dayOfWeek + monthDays[month - 1]) % 7;
        if(dayOfWeek == 0) dayOfWeek = 7; // Keep Sunday as 7 for this representation
    }

    // Now we're at January 1, 1901
    // Loop through each year from 1901 to 2000
    for (year = 1901; year <= 2000; year++)
    {
        // Set February days based on leap year
        if (((year % 100 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0)))
        {
            monthDays[1] = 29;
        }
        else
        {
            monthDays[1] = 28;
        }

        // Check each month in this year
        for (month = 1; month <= 12; month++)
        {
            // Check if the first day of this month is a Sunday
            if (dayOfWeek == 7) // Sunday
            {
                sunCount++;
                printf("Sunday found: %d/1/%d\n", month, year);
            }
            
            // Advance to the first day of next month
            dayOfWeek = (dayOfWeek + monthDays[month - 1]) % 7;
            if(dayOfWeek == 0) dayOfWeek = 7; // Keep Sunday as 7
        }
    }
    
    printf("Total Sundays on the first of the month (1901-2000): %d\n", sunCount);
    return EXIT_SUCCESS;
}