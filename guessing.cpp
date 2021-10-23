#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {

	int n;
	cin >> n;

	//loop for each input case
	for(int game = 1; game <= n; game++){
		//input variables
		int a,b,x;
		cin >> a >> b >> x;

		int numberOfGuesses = 0;

		int min = a;
		int max = b;

		//simulating the guessing game
		while(true){
			numberOfGuesses++;
			//the plus one here ensures that the guess rounds up if min+max is odd
			int toguess = (min+max+1)/2;
			if(toguess == x){
				break;
			}
			else if(toguess > x){//the guess was too high so Jimmy knows the maximum number x could be is less than toguess
				max = toguess-1;
			}
			else if(toguess < x){//the guess was too low so Jimmy knows the minimum number x could be is more than toguess
				min = toguess+1;
			}


		}


		 //writing the output
		 cout << "Game #" << game << ": ";

		//printing differently if the number of guesses was one
		if(numberOfGuesses == 1) cout << numberOfGuesses << " guess" << endl;
		else cout << numberOfGuesses << " guesses" << endl;


	}
	
	return 0;
}
