class Solution {
public:
int gcd(int a,int b){
    if(a==0&&b)return b;
    if(b==0&&a)return a;
    if(a>b)return gcd(a%b,b);
    else return gcd(a, b%a);
}
    int findGCD(vector<int>& nums) {
       int mx=nums[0],mn=nums[0];
       for(int i=1;i<nums.size();i++){
        mx=max(mx,nums[i]);
        mn=min(mn,nums[i]);
       }
        return gcd(mn,mx);
    }
};