class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),st=0,end=n-1,mid;
        while(st<=end){
            mid=st + (end-st)/2;
            if(nums[mid]==target){
               return mid;
            }
            else if(nums[st]<=nums[mid]){
                if(nums[st]<=target&&nums[mid]>target)
                end=mid-1;
                else st=mid+1;
            }
            
            else {
                if(nums[mid]<target&&nums[end]>=target)
                st=mid+1;
                else end=mid-1;

            }
        }
        
     return -1;}
};