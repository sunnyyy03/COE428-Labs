#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])
{
    srand(time(NULL)); //seeding the rng
    int array[100000];
    int arrayElements = 5;
    if(argc > 1){
        arrayElements = argc;
        for(int i = 0; i < arrayElements; i++) //populating the array with random elements
            array[i] = atoi(argv[i]);
    }
    else{
        for(int i = 0;i < arrayElements; i++)
	array[0] = 10;
 	array[1] = 20;
 	array[2] = 30;
 	array[3] = 40;

    }
    mySort(array, arrayElements);
        
    for(int i = 0; i < arrayElements-1; i++){ //checking if there is a sorting error
        if(array[i]>array[i+1]) //if there is an error, this print statement will executre and the pogram will exit
        {
            printf("Sorting error at index %d \n",arrayElements);
            exit(1);
        }
    }
    
    for(int i = 1; i<arrayElements;i++)//print out sorted array
        printf("%d \n",array[i]);

    return 0;        
}
