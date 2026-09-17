class Solution {
public:
    int minSumOfLengths(vector<int>&nums, int target) {
       
        int l=0,n=nums.size();
        long long sum=0;
        int ans=1e9;
        vector<int>best(n,1e9);
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(l<r&&sum>target){
                sum-=nums[l];
                l++;
            }
            if(r>0)best[r]=best[r-1];
            if(sum==target){
                int len=r-l+1;
                if(l>0&&best[l-1]!=1e9)
               ans=min(ans,len+best[l-1]);
              
              best[r]=min(best[r],len);
                
                
               
            }
        }
    return ans==1e9?-1:ans;;}
};