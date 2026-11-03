class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size();
        int unlock =0;
       int swaps=0;
        int flag=0;
      for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(nums[j]<nums[j-1]){
                if(j==1)flag=1;
                unlock+=locked[j]+locked[j-1];
                locked[j]=locked[j-1]=0;
                swap(nums[j],nums[j-1]);
                swaps++;
            }
        }
      }
      if(flag)unlock+=locked[0];
      if(unlock>k)return -1;
      return unlock+swaps;
    }
};