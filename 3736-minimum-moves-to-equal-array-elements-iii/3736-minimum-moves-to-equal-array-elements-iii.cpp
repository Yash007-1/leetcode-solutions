class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxe=nums[0];
        int sum=0;
        for(auto i:nums){
            maxe=max(maxe,i);
            sum+=i;
        }
    return (nums.size())*maxe-sum;}
};