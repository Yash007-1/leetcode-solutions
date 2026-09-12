class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int f1=-1,f2=-1;
        int n=nums.size();
        int i=0,r=0;
        int ans=0;
        while(r<n&&i<n){
           if(f1==-1)f1=nums[r];
           
           else if(nums[r]!=f1&&f2==-1)f2=nums[r];
           else if(nums[r]!=f1&&nums[r]!=f2){
           
                i=r-1;
                while(i>=0&&nums[i]==nums[r-1])i--;
                i++;
                 f1=nums[i];
                f2=nums[r];
                

            }
            ans=max(ans,r-i+1);
           
           r++;}
        
        return ans;
    }
};