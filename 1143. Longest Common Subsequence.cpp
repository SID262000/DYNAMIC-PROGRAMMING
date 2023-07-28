/*
    Brute force:
    we can take 2 strings s1 and s2, the simplest approach we can generate all the subsequences
    and store them, then manually find out the longest common subsequence among them.
    This naive approach will give the correct answer but to generate all the subsequences,
    we will require exponential(2^n)times. 

    Using Dynamic Programming:
    We would want to try something that can give us the longest common subsequence on the way
    of generating all subsequences. To generate all subsequences we will use recursion and in 
    the recursive logic we will figure out a way to solve this problem.

    As we find that some of the steps are overlapping in recursive approach so, we can memorize the
    recursive code to reduce the time complexity.
    T.C: O(N*M)
    Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.
    S.C: O(N*M) + O(N+M)

    Again convert memorization to tabulation to reduce space complexity.
    To convert the memoization approach to a tabulation one, create a dp array with the same size as done in memoization.

    Best Approach.
    Space optimization:
    Intuition:
      we can use two rows: dp[ind1-1][ ], dp[ind][ ],
      So we are not required to contain an entire array, we can simply have two rows prev and cur where prev corresponds
      to dp[ind-1] and cur to dp[ind]. After declaring prev and cur, replace dp[ind-1] to prev and dp[ind] with cur and
      after the inner loop executes, we will set prev = cur, so that the cur row can serve as prev for the next index.

      T.C: O(N*M)
      S.C: O(M)
*/

// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
// space Optimization
//T.C= O(N*M)
//S.C= O(M)

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        vector<int> prev(m+1, 0), cur(m+1,0);

        for(int idx1=1; idx1<=n; idx1++)
        {
            for(int idx2=1; idx2<=m; idx2++)
            {
                if(text1[idx1-1] == text2[idx2-1])
                    cur[idx2]  = 1+ prev[idx2-1];

                else
                    cur[idx2] = max(prev[idx2], cur[idx2-1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};