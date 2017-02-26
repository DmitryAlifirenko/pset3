/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include "helpers.h"

const int MAX1 = 65536;

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int begin = 0;
    int end = n - 1;
    int middle = (begin + end) / 2;

    while (begin <= end)
    {
    if (values[middle] == value)
        return true;
    else if (value < values[middle])
    {
        end = middle - 1;
        middle = (begin + end) / 2;
    }
    else if (value > values[middle])
    {
        begin = middle + 1;
        middle = (begin + end) / 2;
    }
    else 
        break;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int arr[MAX1];
    for (int i=0; i<MAX1; i++)
    {
        arr[i]=0;
    }
    for (int i = 0; i < n; i++) 
    {
 		++arr[values[i]]; 	
    }
    for(int i = 0; i < MAX1; i++)
    {
        for(int j = arr[i]; j--;)
            *values++ = i;
    }        
}
