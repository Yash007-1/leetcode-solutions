class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        int Gmax = INT_MIN;
        int ans = 0;
        int Cmax = INT_MIN;
                
        
        for (int i = 0; i < n; i++) {
            Gmax = max(nums[i], Gmax);
            if (i == ans) {
                Cmax = max(Cmax, nums[i]);
            }
            if (Cmax-nums[i]>k){
                Cmax=Gmax;
                ans=i+1;
            }
      
        }
        return ans<n?ans:-1;
    }
};