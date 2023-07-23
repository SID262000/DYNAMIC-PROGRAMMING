/* 
Modification of House Robber question.

https://leetcode.com/problems/house-robber-ii/description/

Space optimization
Algorithm:
1. Declare two temp vector and push elements of nums in temp1(except first element) and temp2(except last element).
2. Find the maximum of non-adjacent elements as mentioned in House Robber code on temp1 and temp2 separately. 
3. Return max as our final answer.
//T.C = O(n)
//S.C = O(1)
*/

class Solution {
public:

int maxSum(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0; i<n; i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(maxSum(temp1), maxSum(temp2));
    }
};