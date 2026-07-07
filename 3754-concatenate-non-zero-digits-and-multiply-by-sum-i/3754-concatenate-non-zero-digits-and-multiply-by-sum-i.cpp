class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        int sum=0;
        int i=1;
        while(n!=0){
            int dig=n%10;
            if(dig==0){
                n/=10;
                continue;
            }
            x=x+i*dig;
            sum+=dig;
            n/=10;
            i*=10;
        }
    return x*sum;}
};