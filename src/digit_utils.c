/* Author: Neyfeld */

/* Implementation of digit maipulation functions */

#include "digit_utils.h"
#include <stdio.h>

#define MAX_DIGITS 10

static void count_digits(unsigned int n, int digits[])
{
    int i;
    for (i = 0; i < MAX_DIGITS; i++)
        digits[i] = 0;

    if(n == 0)
        digits[0] = 1;
    else
    {
        while(n > 0){
            digits[n % 10]++;
            n /= 10;
        }
    }
}

static unsigned int build_max_number(int digits[])
{
    unsigned int result = 0;
    int digit, count, i;

    for(digit = 9; digit >= 0; digit--){
        for(count = 0; count < digits[digit]; count++)
          {
              result = result * 10 + digit;
          }
    }

    return result;
}

unsigned int max_from_digits(unsigned int n)
{
    int digits[MAX_DIGITS];

    count_digits(n, digits);
    return build_max_number(digits);
}