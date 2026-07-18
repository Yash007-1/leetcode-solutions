class Solution {
public:
int gcd(int a,int b){
    if(a==0&&b)return b;
    if(b==0&&a)return a;
    if(a>b)return gcd(a%b,b);
    else return gcd(a, b%a);
}
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return gcd(nums[0],nums[nums.size()-1]);
    }
};