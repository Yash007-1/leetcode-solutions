class Solution {
public:
 int  f(vector<int>&nums,int idx,int prev,vector<int>&res){
      if(idx==nums.size())return 0;
      int ntake=f(nums,idx+1,prev,res);
      int take=0;
      if(prev==-1||nums[prev]%nums[idx]==0){
        take=1+f(nums,idx+1,idx,res); 
      }
      if(ntake>take)return ntake;
      else{
        res.push_back(nums[idx]);
        return take;
      }
 }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>arr=nums;
        vector<int>res;
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++)hash[i]=i;
        sort(arr.begin(),arr.end());
        int maxi=0;
        int last=0;
        for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[i]%arr[prev]==0){
                if(dp[i]<1+dp[prev]){
                    hash[i]=prev;
                    dp[i]=1+dp[prev];
                }
            }

        }
        if(dp[i]>maxi){
            maxi=dp[i];
            last=i;
        }
        }
       
        while (hash[last]!=last){
            res.push_back(arr[last]);
            last=hash[last];
        }
         res.push_back(arr[last]);
        reverse(res.begin(),res.end());
            
            return res;
    }
};