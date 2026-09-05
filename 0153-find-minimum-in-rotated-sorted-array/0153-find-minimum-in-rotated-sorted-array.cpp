class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int st=0,end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            ans=min(ans,nums[mid]);
            if(nums[st]>nums[end]){
                if(nums[end]<nums[mid])st=mid+1;
                 else end=mid-1;
            }

            else{ if(nums[st]<nums[mid])end=mid-1;
            else st=mid+1;}
        }
    return ans;}
};