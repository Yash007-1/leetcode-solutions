class Solution {
public:
    int gcd(int a,int b){
        if(a==0&&b!=0)return b;
        if(a!=0&&b==0)return a;
        if(a>b)return gcd(a%b,b);
        else return gcd(a,b%a);

    }
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};