class Solution {
public:
int gcd(int a,int b){
    while(a!=0&&b!=0){
        if(a>b)a=a%b;
        else b=b%a;
    }
    if(a)return a;
    else return b;
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