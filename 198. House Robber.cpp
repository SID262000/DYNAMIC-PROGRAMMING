/* Space Optimization
// T.C = O(n)
// S.C = O(1)

Intuition :
    First we can apply recursion as we need to count the total number of ways then 
    convert it into DP solution but due to recursion there we will be overlapping subproblems and 
    will increase the S.C so,for space optimization we can convert tabulation approach to 
    space optimization approach.

Algorithm:
1. Each iteration’s cur_i and prev become the next iteration’s prev and prev2 respectively.
2. Therefore after calculating cur_i, if we update prev and prev2 according to the next step, we will always get the answer. 
3. After the iterative loop has ended we can simply return prev as our answer.*/
class Solution {
public:
int rob(vector<int>& nums){
    int prev = nums[0];
    int prev2 =0;
    int n=nums.size();

    for(int i=1; i<n; i++){
        int pick = nums[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

};