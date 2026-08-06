class Solution {
public:
//     int helper(vector<int>&nums,int idx,vector<vector<int>>&dp,
//     bool t){
//         if(idx==0){
//         if(t)return 0;
//         return nums[0];}
//        if(idx<0)return 0;
//        if(dp[idx][t]!=-1)return dp[idx][t];
//       int take=0,n_take=0;
//       if(t&&idx==nums.size()-1){
//          take=nums[idx]+helper(nums,idx-2,dp,true);
        
//          n_take=helper(nums,idx-1,dp,false);}
//         else if(t){
//             take=nums[idx]+helper(nums,idx-2,dp,true);
//   n_take=helper(nums,idx-1,dp,true);
//         }
//         else {
//             take=nums[idx]+helper(nums,idx-2,dp,false);
        
//          n_take=helper(nums,idx-1,dp,false);
//         }
//         return dp[idx][t]=max(take,n_take);
      
//     }
//     int rob(vector<int>& nums) {
//         vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
//         if(nums.size()==1)return nums[0];
       
//         return helper(nums,nums.size()-1,dp,true);
//     }
   int helper(vector<int>&nums,int idx,vector<int>&dp){
        if(idx==0)return nums[0];
       if(idx<0)return 0;
       if(dp[idx]!=-1)return dp[idx];
        int  take=nums[idx]+helper(nums,idx-2,dp);
        int n_take=helper(nums,idx-1,dp);
        return dp[idx]=max(take,n_take);
      }
    int rob(vector<int>& nums) {
        int prev_with_0=nums[0];
        int prev_without_0=0;
        int prev2=0;
       
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i==nums.size()-1)take=0;
             else if(i>1)take=nums[i]+prev2;;
            int n_take=prev_with_0;
            int curr=max(take,n_take);
            prev2=prev_with_0;
            prev_with_0=curr;
        }
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            
            if(i>1)take=nums[i]+prev2;;
            int n_take=prev_without_0;
            int curr=max(take,n_take);
            prev2=prev_without_0;
            prev_without_0=curr;
        }
        
      return max(prev_without_0,prev_with_0);
    }
};