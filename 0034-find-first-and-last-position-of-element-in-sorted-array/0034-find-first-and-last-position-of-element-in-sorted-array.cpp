class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (target == nums[mid]) {
                ans[0] = mid;
                j = mid - 1;
            } else if (target > nums[mid]) {
                i = mid + 1;
            } else
                j = mid - 1;
        }
        i = 0, j = n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (target == nums[mid]) {
                ans[1] = mid;
                i = mid + 1;
            } else if (target > nums[mid])
                i = mid + 1;
            else
                j = mid - 1;
        }

        return ans;
    }
};