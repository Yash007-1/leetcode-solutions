class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int mini=INT_MAX,maxi=INT_MIN;
       for(auto i:nums){
        mini=min(mini,i);
        maxi=max(maxi,i);
       }
       int n=nums.size();
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