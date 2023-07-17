class Solution {
public:
    int climbStairs(int n) {
        /* Intuition:
            To identify a DP solution,
            Count the total number of ways
            Given multiple ways of doing a task, which way 
            will give the minimum or the maximum output.
            We can try to apply recursion. Once we get the recursive solution,
            we can go ahead to convert it to a dynamic programming one.

            Algo:
           1. Declare a dp[] array of size n+1.
           2. First initialize the base condition values, i.e i=0, i=1 and i=2 of
              the dp array as 0,1,2 respectively.  
           3. Set an iterative loop that traverses the array( from index 3 to n) and
              for every index set its value as dp[i-1] + dp[i-2].  

              T.C= O(N)
              S.C= O(N)
        */

        if(n<=2)
         return n;
        vector<int> dp(n+1);// Declare a dp[] array of size n+1.
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2]; // to count the no. of ways to climb at top 
        
        return dp[n];
    }
};