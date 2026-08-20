class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        if(nums.size()<=2)return nums;
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i=0,j=0;
        for(int k=2;k<nums.size();k++){
            if(arr1[i]>arr2[j]){arr1.push_back(nums[k]);i++;}
            else {arr2.push_back(nums[k]);j++;}
        }
        vector<int>result;
        for(auto x:arr1)result.push_back(x);
        for(auto y:arr2)result.push_back(y);
        return result;

    }
};