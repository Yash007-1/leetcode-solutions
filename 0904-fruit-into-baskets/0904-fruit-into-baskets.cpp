class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int lastf=-1,f2=-1;
        int n=nums.size();
        int r=0;
        int currcount=1,streak=0;
        int ans=0;
        while(r<n){
           if(nums[r]==lastf||nums[r]==f2)currcount++;
           else currcount=streak+1;
           if(nums[r]==lastf)streak++;
           else {
            streak=1;
            f2=lastf;
            lastf=nums[r];
           }
            ans=max(ans,currcount);
           
           r++;}
        
        return ans;
    }
};