class Solution {
public:
    bool f(vector<int>& nums, int idx, int tgt, vector<vector<int>>& dp) {
        if (tgt == 0)
            return true;
        if (idx == 0)
            return nums[0] == tgt;
        if (dp[idx][tgt] != -1)
            return dp[idx][tgt];
        bool notake = f(nums, idx - 1, tgt, dp);
        bool take = false;
        if (nums[idx] <= tgt)
            take = f(nums, idx - 1, tgt - nums[idx], dp);
        return dp[idx][tgt] = take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (auto i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        int tgt = sum / 2;
       
        vector<bool>prev(tgt+1,false);
        vector<bool>curr(tgt+1,false);
        prev[0]=true;
        curr[0]=true;
        
        if (nums[0] <= tgt)
            prev[nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= tgt; j++) {
                bool ntake =prev[j];
                bool take = false;
                if (nums[i] <= j)
                    take = prev[j-nums[i]];
                      curr[j]=take||ntake;
            }
            prev=curr;
          
        }
        return prev[tgt];
    }
};