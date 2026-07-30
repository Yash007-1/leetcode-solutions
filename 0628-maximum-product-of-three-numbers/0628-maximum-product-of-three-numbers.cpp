class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max1,max2,max3,min1,min2;
        max1=nums[nums.size()-1];
        max2=nums[nums.size()-2];
        max3=nums[nums.size()-3];
        min1=nums[0];
        min2=nums[1];
        return max(max1*max2*max3,min1*min2*max1);
    }
};