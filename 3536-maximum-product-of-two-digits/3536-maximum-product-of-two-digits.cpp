class Solution {
public:
    int maxProduct(int n) {
        int maxdigit=0;
        int x=n;
     while(x!=0){
           maxdigit=max(maxdigit,x%10);
           x=x/10;

     }
     int count=1;
     int secmax=0;
     while(n!=0){
        if(n%10==maxdigit&&count!=0){
            n=n/10;
            count --;continue;}
        secmax=max(secmax,n%10);
        n=n/10;
     }
     return maxdigit*secmax;
    }
};