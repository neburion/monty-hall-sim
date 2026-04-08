#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUMBER_OF_ITERATIONS 100000
#define NUMBER_OF_DOORS 3
#define SUCCESS true
#define FAILURE false

bool gameIteration(){
    int correctDoor = (rand() % NUMBER_OF_DOORS) +1;
    int chosenDoor  = (rand() % NUMBER_OF_DOORS) +1;

    int removedDoor;
    removedDoor = (rand() % NUMBER_OF_DOORS) +1;
    while(removedDoor == chosenDoor || removedDoor == correctDoor)
        removedDoor = (rand() % NUMBER_OF_DOORS) +1;

    int switchedDoor;
    switchedDoor = (rand() % NUMBER_OF_DOORS) +1;
    while(switchedDoor == chosenDoor || switchedDoor == removedDoor)
        switchedDoor = (rand() % NUMBER_OF_DOORS) +1;

    if(switchedDoor == correctDoor)
        return SUCCESS;
    else
        return FAILURE;
}

int main(){
    srand(time(NULL));
    int successCount = 0;

    for (int i = 0; i < NUMBER_OF_ITERATIONS; i++){
        if(gameIteration() == SUCCESS)
            successCount++;
    }

    // print the success rate
    double successRate = ((double) successCount/(double) NUMBER_OF_ITERATIONS) * 100;
    printf("The success rate of switching was %.2f%% over %d attempts.\n",
                successRate, NUMBER_OF_ITERATIONS);
    printf("The success rate of not switching was %.2f%% over %d attempts.\n",
                100 - successRate, NUMBER_OF_ITERATIONS);

    return 0;
}
