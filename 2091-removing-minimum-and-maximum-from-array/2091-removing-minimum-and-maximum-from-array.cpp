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
       int last=0;
       int i=0,j=n-1;
       int del=0;
       while(i<=j){
        if(nums[i]==mini||nums[i]==maxi){
            if(i-last<j-i){
                 del+=i-last+1;
                 last=i+1;
                
            }
            else{
                 del+=j-i+1;
                j=j-i-1;
               
            }
        }
        i++;
       }
       i=n-1,j=0;
       last=n-1;
       int del2=0;
       while(i>=j){
        if(nums[i]==mini||nums[i]==maxi){
            if(last-i<i-j){
                 del2+=last-i+1;
                 last=i-1;
                
            }
            else{
                 del2+=i-j+1;
                j=i-j+1;
               
            }
        }
        i--;
       }
    return min(del,del2);}

};