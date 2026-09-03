class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int o_min=INT_MAX,e_min=INT_MAX;
       int even=0,odd=0;
       for(auto i:nums1){

        if(i%2==0){even++;e_min=min(e_min,i);}
        else {odd++;o_min=min(o_min,i);}
       }
       if(odd==0||even==0)return true;
       if(o_min<e_min)return true;
       return false;
    }
};