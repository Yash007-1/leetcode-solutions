class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=n-1;
        while(st<end){
             int mid=(st+end)/2;
             if(mid>0&&mid<n-1){
                if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return mid;
                else if(nums[mid]<nums[mid+1])st=mid+1;
                else if(nums[mid]<nums[mid-1])end=mid-1;
                
             }
             else{
                if(mid==0){if(nums[mid]>nums[mid+1])return mid;
                else st=mid+1;}
                if(mid==n-1){if(nums[mid]>nums[mid-1])return mid;
                else end=mid-1;}
             }}
        return st;}
};