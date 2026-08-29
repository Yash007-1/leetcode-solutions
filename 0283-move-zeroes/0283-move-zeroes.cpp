class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int j=0,n=nums.size();
        for(int i=0;i<n&&j<n;i++){
            j=i;
            if(nums[i]==0){
                while(j<n&&nums[j]==0){
                    j++;
                }
                if(j<n)
                swap(nums[i],nums[j]);
            }
        }
    }
};