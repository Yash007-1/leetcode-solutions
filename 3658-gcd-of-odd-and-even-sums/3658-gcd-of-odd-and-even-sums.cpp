class Solution {
public:
    int gcd(int a,int b){
        if(a==0&&b!=0)return b;
        if(a!=0&&b==0)return a;
        if(a>b)return gcd(a%b,b);
        else return gcd(a,b%a);

    }
    int gcdOfOddEvenSums(int n) {
        int oddsum=0;
        int evensum=0;
        for(int i=1;i<=n;i++){
            oddsum+=2*i-1;
            evensum+=2*i;
        }
        return gcd(evensum,oddsum);
    }
};