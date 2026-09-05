class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        int mid = 0;
        if (mid == 0) {
            if (nums[mid] != nums[mid + 1])
                return nums[mid];
        }
        mid = n - 1;
        if (mid == n - 1) {
            if (nums[mid] != nums[mid - 1])
                return nums[mid];
        }
        int st = 1, end = n - 2;
        while (st <end) {
            mid = (st + end) / 2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
                              return nums[mid];
                          else if (mid % 2 == 0 && nums[mid] == nums[mid - 1] ||
                                   mid % 2 == 1 && nums[mid] == nums[mid + 1]) {
                              end = mid - 1;
                          } else {
                              st = mid + 1;
                          }
        }
    return nums[st];}
};