public:
    long long numberOfWays(long long N) {
        //code here
        //Algorithm
        /*
        1.Recuurence Relation: F(n)=F(n-1)+F(n-2)
        T.C:O(N)
        S.C:O(N)
        */
        long long dp[N+1];
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=N;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
        
        return dp[N];
        
    }