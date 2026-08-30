class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int mini=0,maxi=0; int n=nums.size();
       for(int i=0;i<n;i++){
        if(nums[mini]>=nums[i]){
            mini=i;
        }
        if(nums[maxi]<=nums[i])maxi=i;
       }
      int f_del=0,b_del=0,fb_del=0;
      f_del=max(mini+1,maxi+1);
      b_del=max(n-mini,n-maxi);
      fb_del=min(mini+1+n-maxi,n-mini+1+maxi);
      return min(f_del,min(b_del,fb_del));
    }
};