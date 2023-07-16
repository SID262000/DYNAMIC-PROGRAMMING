class Solution {
public:


    //https://leetcode.com/problems/maximum-product-subarray/description/
    /* Intuition :
       For solving this problem  kadane's algorithm will be the best approach to
       solve the problem in O(N).

       Algorithm :
        1.Initially store 0th index value in maxp, minp and r.
        2.Traverse the array from 1st index. 
        3.For each element, update maxp and minp.
        4.maxp is maximum of current element, product of current element and maxp,
          product of current element and minp.  
        5.minp is minimum of current element, product of current element and maxp,
          product of current element and minp.  
        6.Return maximum of result(r) and maxp

        T.C= O(N)
        S.C= O(1)
    */
    int maxProduct(vector<int>& nums) {
        int r = nums[0];
        int n=nums.size();
    
    for (int i = 1, maxp = r, minp = r; i < n; i++) {
      //update maxp and minp.
        int temp = max({nums[i],maxp*nums[i],minp*nums[i]});
        minp = min({nums[i],maxp*nums[i],minp*nums[i]});
        maxp = temp;

        
        r = max(r, maxp); // store max product result in r
    }
    return r; 
    }
};