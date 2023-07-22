/*
    Problem Statement:

    This is a follow-up question to “Frog Jump”.
    In the previous question, the frog was allowed to jump either one or two steps at a time.
    In this question, the frog is allowed to jump up to ‘K’ steps at a time. 
    If K=4, the frog can jump 1,2,3, or 4 steps at every index.

    Tabulation approach:

    1. Declare a dp[] array of size n.
    2. First initialize the base condition values, i.e dp[0] as 0.
    3. Set an iterative loop which traverses the array( from index 1 to n-1)
       then again run nested for loop to calculate min from k distances.

    T.C = O(N*K)
          We are running two nested loops, where outer loops run from 1 to N-1 and the inner loop runs from 1 to K.
          where,
               N=height
               K=No. of Jumps
    S.C = O(N)
*/

#include <bits/stdc++.h>

using namespace std;

int solveDP(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;// Base condition value
    for(int i=1;i<n;i++){
        int minSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0)// Steps must be greater than 1
            {
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                minSteps= min(jump, minSteps);//  store min value
            }
        }
        dp[i]= minSteps;
    }
    return dp[n-1];
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);//Create a dp[n] array initialized to -1.
    return solveDP(n, height, dp, k);// call solveDP()
}

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n,height,k);
}
