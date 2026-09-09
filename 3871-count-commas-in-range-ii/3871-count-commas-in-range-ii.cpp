class Solution {
public:
    long long countCommas(long long n) {
        int long long ans=0;
        int it=1;
        long long sb=1000;
        long long x=n;
        while(sb<=n){
              ans+=(n-sb+1);
              
              sb*=1000;
              
        }
        return n>999?ans:0;
    }
};