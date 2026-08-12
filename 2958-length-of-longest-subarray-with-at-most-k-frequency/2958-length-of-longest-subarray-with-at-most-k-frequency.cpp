class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(k>=nums.size())return nums.size();
       int mxele=nums[0];
       for(auto it:nums){
        mxele=max(mxele,it);
       }
       unordered_map<int,int>m;
       int mxlength=0;
       
       int i=0,j=0;
       m[nums[j]]++;
      while(i<=j&&j<nums.size()){
        while(m[nums[j]]>k){
            m[nums[i]]--;
            i++;
            continue;
        }
        mxlength=max(mxlength,j-i);
        
            j++;
            if(j<nums.size())m[nums[j]]++;
      }

       return mxlength+1;}
};