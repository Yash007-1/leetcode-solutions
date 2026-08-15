class Solution {
public:
    int f(vector<int>&nums,int i,int x,int len){
        if(i==0){
            if((nums[0]^x))return len+1;
            else return 0;
        }
       
        int ntake=f(nums,i-1,x,len);
        int take=0;
      take=f(nums,i-1,x^nums[i],len+1);
       
       return max(take,ntake);
        

    }
    int longestSubsequence(vector<int>& nums) {
        
        int n=nums.size();
       int mx=nums[0];
       int x=0;
     for(int i=0;i<n;i++){
            x=x^nums[i];
            mx=max(mx,nums[i]);

     }
     if(x!=0)return n;
     if(x==0&&mx==0)return 0;
     else return n-1;
    }
};