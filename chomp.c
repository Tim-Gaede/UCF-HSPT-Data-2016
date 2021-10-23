#include <stdio.h>

int main(){

	int testCases, caseOn;
	
	//Read in the number of cases
	scanf("%d", &testCases);
	
	for(caseOn = 1;caseOn<=testCases;caseOn++){
		
		int n, k, i, j;
		
		
		scanf("%d", &n);
		scanf("%d", &k);
		
		//Read in the food values
		int food[n];
		for(i = 0;i<n;i++){
			scanf("%d", &food[i]);
		}
		
		
		//This array stores the sum of the food values from 0 to i in position i
		//This allows us to quickly get the sum of any range of the food array
		//The sum from position i to position j in the food array is equal to
		//prefixSums[j]-prefixSums[i-1] which is the sum from 0 to j minus the 
		//sum from 0 to i-1
		long long prefixSums[n];
		for(i = 0;i<n;i++){
			prefixSums[i] = food[i];
			if(i > 0){
				prefixSums[i]+=prefixSums[i-1];
			}
		}
		
		long long answer = 0;
		
		//This array keeps track of the frequency of the sums of all possible
		//first chomps that end at least two positions before th
		long long counts[k];
		
		for(i = 0;i<k;i++){
			counts[i] = 0;
		}
		
		
		//We are looping over the start position of the second chomp and using
		//counts array to keep track of possibilites for the first chomp
		for(i = 2; i<n;i++){
		
			//We need to add in all the first chomps that end at position i-2
			//as this is now a valid position for them to end. To do this we loop
			//over all possible start positions of the first chomp and add the
			//sum from j to i-2 mod k to the counts array
			for(j = 0;j<=i-2;j++){
				long long sum = prefixSums[i-2]-(j == 0 ? 0 : prefixSums[j-1]);
				sum%=k;
				counts[sum]++;
			}
			
			//This loops over all possible end positions of the second chomp
			for(j = i;j<n;j++){
			
				long long sum = prefixSums[j]-(i == 0 ? 0 : prefixSums[i-1]);
				sum%=k;
				
				//We need the sum of the two chomps to be equal to 0 when moded
				//by k in order for the sum of the remaining food to be the same
				//mod k as the original plate
				int need = (k-sum)%k;
				
				//Add the number of first chomps that have the right sum to our
				//answer
				answer+=counts[need];
			}
			
		}
		
		
		
		printf("Plate #%d: %lld\n", caseOn, answer);
	}

	return 0;
}
