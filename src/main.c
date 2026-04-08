#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int testNum = INT_MAX;
    bool switching = true;

    srand(time(NULL));

    int successCount = 0;

    for (int i = 0; i < testNum; i++) {
        // select correct door
        int correctDoor = (rand() % 3) + 1;

        // chose door
        int chosenDoor = (rand() % 3) + 1;

        // removing one door
        int removedDoor;
        if(chosenDoor == correctDoor) {
            int doors[2];
            int off = 0;
            for(int j = 0; j < 2; j++) {
                if(j == chosenDoor) {
                    off++;
                }
                doors[j] = i+off;
            }
            removedDoor = doors[(rand() % 2)];
        } else {
            removedDoor = 6 - (chosenDoor + correctDoor);
        }

        // chose if switching
        if(switching) {
            chosenDoor = 6 - (chosenDoor + removedDoor);
            if(chosenDoor == correctDoor) {
                successCount++;
            }

        } else {
            if(chosenDoor == correctDoor) {
                successCount++;
            }
        }
    }

    // print the success rate
    double successRate = ((double) successCount/(double) testNum) * 100;
    if(switching) {
        printf("The success rate of switching was %.2f%% over %d attempts.\n", successRate, testNum);
    } else {
        printf("The success rate of not switching was %.2f%% over %d attempts.\n", successRate, testNum);
    }

    return 0;
}
