class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int maxs=0;
        int best=nums[0];
        ;
        for(int j=k;j<nums.size();j++){
            best=max(best,nums[j-k]);
            maxs=max(maxs,best+nums[j]);
        }
    return maxs;}
};