class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suffix(n);
        int maxi=nums[0];
         
        int mini=nums[n-1];
        int ans=-1;
        for(int j=n-1;j>=0;j--){
            mini=min(mini,nums[j]);
            suffix[j]=mini;
            
        }
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            int score=maxi-suffix[i];
            if(score<=k)return i;
        }
  return -1; }
};