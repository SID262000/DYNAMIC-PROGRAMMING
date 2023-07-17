class Solution {
public:

    /* Brute Force 
        1. Run a loop to find the start of the subarrays.
        2. Run another nested loop
        3. Multiply each element and store the maximum value of all the subarray.

        T.C =O(N*N)
        S.C =O(1)
    */


    //https://leetcode.com/problems/maximum-product-subarray/description/
    /* Optimized Solution
        Intuition :
        The intuition of the algorithm is not to consider the subarray as a part of the answer
        if its sum is less than 0. A subarray with a sum less than 0 will always reduce our
        answer and so this type of subarray cannot be a part of the subarray with maximum sum.
        For solving this problem  kadane's algorithm will be the best approach.

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
