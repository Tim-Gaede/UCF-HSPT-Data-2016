#include <math.h>
#include <stdio.h>

int main() {
    
    // Read in the number of days to process.
    int numCases;
    scanf("%d", &numCases);
    
    // Loop through each day.
    for(int curCase = 1; curCase <= numCases; ++curCase) {
        // Read the number of fish.
        int numFish;
        scanf("%d", &numFish);
        
        // Get the first power of two greater than or equal to the number.
        int fishTree = 1;
        while(fishTree < numFish)
            fishTree *= 2;
        
        // Find the number of fish remaining on the tree.
        int remaining = fishTree - numFish;
        
        // Print the answer.
        printf("Day #%d: %d extra fish\n", curCase, remaining);
    }
}
