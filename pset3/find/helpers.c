/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include<stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int centro;
    int ini = 0;
    int fin = n-1;
    // TODO: implement a searching algorithm
    
    sort(values,n);
    
        while(ini<=fin){
            centro= (((fin-ini)/2)+ini);
            if(values[centro]==value)
            return true;
            else
                if(value< values[centro])
                    fin = centro-1;
                    else
                    ini=centro+1;
             
        }return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    int size = n-1;
    int minPos;
        for(int j = 0; j <= size; j++){
            minPos = j;
                for(int i = j+1; i <= size; i++){
                     if(values[i] < values[minPos]){
                         minPos = i;
                     }   
                }
                if(minPos!=j){
                    int tmp = values[j];
                    values[j]=values[minPos];
                    values[minPos]= tmp;
                }
        }
    return;
}