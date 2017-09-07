#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int values[] = {3, 6, 1, 1, 3};
    int n = 5;
    int max = values[0];
    for (int i = 0; i < n; i++) //found the largest number of array
    {
        if (values[i] > max)
        {
            max = values[i];
        }
    }
    
    printf("the max number of {3, 6, 1, 1, 3} is %i\n", max);
    
    int counting_array[max + 1]; //creat a counting array which include "max" boxes
    for (int i = 0; i <= max; i++) //filled all boxes of counting array with 0
    {
        counting_array[i] = 0;
    }
    
    for (int i = 0; i <= max; i++)
    {
        printf("%i, ", counting_array[i]);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        int idx = values[i];
        counting_array[idx]++;
    }
    
    for (int i = 0; i <= max; i++)
    {
        printf("%i, ", counting_array[i]);
    }
    printf("\n");
}