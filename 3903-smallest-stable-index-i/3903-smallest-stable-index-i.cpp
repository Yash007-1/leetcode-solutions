class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n);
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            prefix[i]=maxi;
        } 
        int mini=nums[n-1];
        int ans=-1;
        for(int j=n-1;j>=0;j--){
            mini=min(mini,nums[j]);
            int score=prefix[j]-mini;
            if(score<=k)
            ans=j;
        }
  return ans; }
};