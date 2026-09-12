class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0,ans=0;
        int i=0,r=0,n=nums.size();
        while(r<n&&i<n){
            if(nums[r]==0)zeros++;
            if(zeros>k){
                while(i<r&&nums[i]!=0){
                    i++;
                }
                zeros--;
                i++;
              
            }
            ans=max(ans,r-i+1);
            r++;

        }
    return ans;}
};