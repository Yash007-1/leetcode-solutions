class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(k>=nums.size())return nums.size();
      
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
        mxlength=max(mxlength,j-i+1);
        
            j++;
            if(j<nums.size())m[nums[j]]++;
      }

       return mxlength;}
};