/*
Solution to Disc using a non-deterministic (randomized) algorithm.  It generates 100,000 random permutations of the waves, and takes the best score that any of those permutations achieve.

There is also a solution involving brute force (see the Java solution for more details).

Analysis:
First, note that the total number of possible arrangements of n waves is n!
For n = 10, the maximum allowed value, this is equal to 3,628,800.
Now, we will find some properties of an optimal solution:
First, an optimal solution wants to alternate increasing/decreasing pairs.
In other words, if a[i] >= a[i-1], then a[i+1] <= a[i].
Here's a proof of why this is the case (this type of proof is called an exchange argument):
Suppose that a[i], ..., a[j] are in increasing order, with j > i + 1.
Case 1 : a[j] is the last element.  Then, by swapping a[j] and a[j-1], all differences of consecutive
elements will be unchanged except for |a[j-1] - a[j-2]| and |a[j] - a[j-1]|.  Suppose the original values were
a[j-2] = x, a[j-1] = y, and a[j] = z, with x <= y <= z.  
Then, the sum of the two differences listed above is (z - y) + (y - x) = z - x.
After swapping the last two elements, the order of these three elements is x, z, y, so the sum of these differences is z-x + z-y.
Since z - y >= 0, z-x + z-y >= z-x, so swapping the last two elements does not change the answer.

Case 2: a[j] is not the last element.
Let a[j-2], a[j-1], a[j], and a[j-1] = p, q, r, and s, respectively, with p <= q, q <= r, and r >= s.
The value added to the score for the three differences of consecutive elements is this range is q-p + r-q + r-s = 2r - p - s.
If a[j] and a[j-1] are swapped, the new total score is r-p + r-q + |q-s| = 2r - p - q + |q-s|.
If q >= s, this is equal to 2r - p - q + (q - s) = 2r - p - s.
If q < s, this is equal to 2r - p - q - (q - s) = 2r - p - 2q + s.  Since q < s, -2q > -2s, so this sum is greater than 2r - p -s.
Either way, swapping a[j] and a[j-1] does not decrease the total score.

Therefore, if there is any sequence of three or more consecutive elements that are increasing, the last two elements in the sequence can be swapped without making
the total score worse, and this decreases the length of that sequence by at least two.  Such operations can be repeated until there are no more increasing sequences
of length three or more.  A similar proof shows that the same process can be done with decreasing sequences, and combining these two processes will result in an array
that alternates between increasing and decreasing elements.

Now, suppose we have an alternating sequence.  Either all elements in odd indices will be greater than or equal to their neighbors,
or all elements in even indices will be greater than or equal to their neighbors.  Let S be one of those two groups
(whichever has only elements that are greater than or equal to their neighbors).
Now, suppose a[i] is in S, and call the other group T.  Then, a[i] will be added twice to the sum if it is not the first or last element - 
once in the difference a[i] - a[i-1], and again in the difference a[i] - a[i+1].
It will be added to the sum once if it is the first or last element since it will only have one neighbor.
Similarly, the elements in T will be subtracted from the sum twice, or once if they are the first or last element.  Suppose n is even.
Then, there are (n-2)/2 positions that will be added twice, 1 element that will be added once, 1 element that will be subtracted once,
and (n-2)/2 positions that will be subtracted twice.  Therefore, in the optimal solution,
the (n-2)/2 largest elements should be placed in the positions that are added twice, the next largest element should be placed in the position that is added once,
the next largest element should be placed in the position that is subtracted once,
and the smallest (n-2)/2 elements should be placed in the positions that are subtracted twice.
This leads to an algorithm to produce an optimal solution in linear time after sorting the array.

Now, let us look at the case when n = 10, and suppose an optimal solution is generated using the approach above.
Then, the 4 largest elements can be placed in any order without affecting the score of the solution, 
and the 4 smallest elements can be placed in any order as well without affecting the score.
Also, the solution can be reversed without affecting the score (so now the even indices will be added instead of the odd indices or vice versa).
Therefore, there are 4!*4!*2 = 1152 different arrangements that all produce the maximum possible score.
So, the probability that a randomly chosen arrangement is optimal is at least 1152/3628800 = .00031746, 
and the probability that it is suboptimal is at most 1 - 1152/3628800 = .99968254.
Therefore, the probability that k solutions are produced and they are all sub-optimal is at most .99968254^k.
For k = 100,000, this probability is less than 10^-12 = .000000000001.
While there is still a chance of this algorithm failing, this chance is extremely small, so a solution using this algorithm will pass almost all of the time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int score(int n, int waves[])
{
  int res = 0;
  int i;
  for(i = 0; i<n-1; i++)
  {
    res += abs(waves[i] - waves[i+1]);
  }
  return res;
}

int main()
{
  int T;
  scanf("%d", &T);
  int t, i, j, n;
  for(t = 0; t<T; t++)
  {
    scanf("%d", &n);
    int waves[n];
    for(i = 0; i<n; i++) scanf("%d", &waves[i]);
    int max = 0;
    for(i = 0; i<100000; i++)
    {
      // Fill cur with a random permutation of the elements in waves.
      int cur[n];
      int used[n];
      for(j = 0; j<n; j++) used[j] = 0;
      for(j = 0; j<n; j++)
      {
        // Generate numbers in the range [0, n) until one that hasn't been used yet is found.
        // Then, add the element of waves at that index to cur, and mark the index as used.
        int idx = rand()%n;
        while(used[idx]) idx = rand()%n;
        cur[j] = waves[idx];
        used[idx] = 1;
      }
      // Calculate the score 
      int curAns = score(n, cur);
      if(curAns > max) max = curAns;
    }
    printf("Wave #%d: %d\n", t+1, max);
  }
  return 0;
}
