class Solution {
public:
  //Algorithm
  /*
    fn(12)=1+min(fn(11),fn(8),fn(3))
    G.F=>fn(n)=1+min(n-j*j);wher j:1 to n
    Base Condition:fn(0)=0
    T.C:O(N)
    S.C:O(N)
  */
              
        
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX); //vector to store result
        dp[0]=0; //Base Condition
        for(int i=1;i<=n;i++) //iterating from 1
        {
            //Applying the recurrence relation
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        //return the answer for nth index
        return dp[n];
          
    }
};