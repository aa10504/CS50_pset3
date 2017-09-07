/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

bool linear_search(int value, int values[], int n);
bool binary_search(int value, int values[], int n);
void selection_sort(int values[], int n);
void bubble_sort(int values[], int n);
void bubble_sort2(int values[], int n);
void counting_sort(int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    return binary_search(value, values, n); //applyed binary reaserch directly
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) //applyed counting sort directly
{
    bubble_sort(values, n);
}

bool linear_search(int value, int values[], int n) //linear search
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }
    return false;
}

bool binary_search(int value, int values[], int n) //binary search
{
    int end = n - 1; //define the initial end point of array
    int start = 0; //define the initial start point of array

    while(end >= start) //while the array exist, do following things.
    {
        int mid = (start + end) / 2;
        if (values[mid] == value)
        {
            return true;
        }
        else if (values[mid] > value) //search the left half of array
        {
            end = mid - 1;
        }
        else //search the right half of array
        {
            start = mid + 1;
        }
    }
    return false;
}

void selection_sort(int values[], int n) //selection sort
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = values[i];
        int index = i; //an integer which marks the min number of array

        for (int j = i + 1; j <= n - 1; j++)
        {
            if (values[j] < min)
            {
                min = values[j];
                index = j;
            }
        }

        int tmp = values[i];
        values[i] = min;
        values[index] = tmp;
    }
}

void bubble_sort(int values[], int n) //bubble sort
{
    int tmp;
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i <= n - (2 + j); i++)
        {
            if (values[i] > values[i + 1])
            {
                tmp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = tmp;
            }
        }
    }
}

void bubble_sort2(int values[], int n) //bubble sort ver.2
{
    int tmp;
    bool iter;

    do
    {
        iter = false;
        for(int i = 0; i <= n - 2; i++)
        {
            if (values[i] > values[i + 1])
            {
                tmp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = tmp;
                iter = true;
            }
        }
    } while(iter);
}

void counting_sort(int values[], int n)
{
    int max = values[0];
    for (int i = 0; i < n; i++) //found the largest number of array
    {
        if (values[i] > max)
        {
            max = values[i];
        }
    }

    int counting_array[max + 1]; //creat a counting array which include "max + 1" boxes
    for (int i = 0; i <= max; i++) //filled all boxes of counting array with 0
    {
        counting_array[i] = 0;
    }

    for (int i = 0; i < n; i++) //add numbers in counting array, i.g. when there are two '3' in values[], the value of counting_array[3] must be 2.
    {
        int idx = values[i];
        counting_array[idx]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= max; j++)
        {
            if (counting_array[j] != 0)
            {
                values[i] = j;
                counting_array[j]--;
                break;
            }
        }
    }
}