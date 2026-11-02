class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
      
        auto arr=nums;
        sort(arr.begin(),arr.end());
        int target=arr[n/2];
       
        
        long long  ans=0;
        for(int i:nums){
            ans+=abs(i-target);
        }
return ans;
    }
};