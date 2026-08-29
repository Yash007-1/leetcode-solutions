class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int c_ones=0;
        for(auto i:nums){
            if(i==1)c_ones++;
            else {
                ans=max(ans,c_ones);
                c_ones=0;
            }
        }
        ans=max(ans,c_ones);
    return ans;}
};