class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int i=0;
        for( i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)sum+=nums[i];
            else break;
        }
        sort(nums.begin(),nums.end());
        for(int j=i-1;j<nums.size();j++){
            if(nums[j]>sum)break;
            if(nums[j]==sum)sum++;
        }
    return sum;}
};