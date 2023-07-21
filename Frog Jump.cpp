// https://www.codingninjas.com/studio/problems/frog-jump_3621012

/*
Intuition :
    First we can apply recursion as we need to count the total number of ways then 
    apply convert it into DP solution but due to recursion there we will be overlapping subproblems and 
    will increase the S.C so,for space optimization we can convert tabulation approach to 
    space optimization approach.

Algorithm:
    1. Each iteration’s cur and prev becomes the next iteration’s prev and prev2 respectively.
    2. Therefore after calculating cur, if we update prev and prev2 according to the next step, we will always get the answer. 
    3. After the iterative loop has ended we can simply return prev as our answer.

    T.C = O(N)
    S.C = O(1)
*/

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev =0; // dp[i-1]
    int prev2 =0; // dp[i-2]
    for(int i=1; i<n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i-1]);//for 1st step
        int ss = INT_MAX;
        if(i > 1)
        ss = prev2 + abs(heights[i] - heights[i-2]);//for 2nd step

        int cur = min(fs, ss);
        prev2 = prev;
        prev =cur;
    }
    return prev;
}