// Eric Ly
// HSPT 2016
// Baby Names

#include <iostream>
#include <string>
#include <stdio.h>
#include <set>

using namespace std;

// List of vowels
char vowel[] = {'A', 'E', 'I', 'O', 'U'};

// set will store our answer in sorted order
set<string> s;

// Check is a character is a vowel
bool isVowel(char a)
{
   for(int i = 0; i < 5; i++) if(a == vowel[i]) return true;
   return false;
}

// Simulate naming process
// We assume a is the first string
// b is the second string
void solve(string a, string b)
{
   // we start at 1 to guarantee a non-empty string
   for(int i = 1; i < a.length(); i++)
   {
      // Determine is the last character is a vowel or not
      bool flag = isVowel(a[i-1]);
      string an = a.substr(0, i);
      
      // we start at 1 to guarantee a non-empty string
      for(int j = 1; j < b.length(); j++)
      {

         // If the last char in A is the same type as the first char in B
         // Skip this iteration
         if(isVowel(b[j]) == flag) continue;
         string bn = b.substr(j);
         
         // They are not the same so concatenate our 2 substring and add it to our set
         s.insert(an+bn);
      }
   }
}

int main()
{
   int n; cin >> n;
   for(int nn = 1; nn <= n; nn++)
   {
      // Clear our set because we are doing a new case
      s.clear();
      string a, b; cin >> a >> b;
      
      // We solve both ways
      solve(a, b);
      solve(b, a);
      
      // Print the output
      // Set is ordered so it will already be alphabetized
      printf("Couple #%d: %d possible names\n", nn, s.size());
      for(set<string>::iterator it = s.begin(); it != s.end(); it++) cout << *it << endl;

      // Don't forget the newline
      printf("\n");
   }
   return 0;
}
