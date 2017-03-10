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
 
bool recursion(int value, int values[], int begin, int end)
{
    // If array of one element
    if (end - begin == 0)
    {
        return (value == values[end]);
    }
    
    int middle = (begin + end )/ 2;

    if (values[middle] == value)
    {
        return true;
    }
    
    if (value < values[middle])
    {
        return recursion(value, values, begin, middle);
    }
    
    else if (value > values[middle])
    {
        return recursion(value, values, middle+1, end);
    }

    return false;
} 
 
 
bool search(int value, int values[], int n)
{   
    return recursion(value, values, 0, n-1);   
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
