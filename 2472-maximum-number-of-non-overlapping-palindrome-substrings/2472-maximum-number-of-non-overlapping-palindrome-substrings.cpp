class Solution {
public:
 bool ispal(string s,int i,int j){
   
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
 }
    int maxPalindromes(string s, int k) {
        int count=0;
        int n=s.size();
       
        if(k==1)return n;
        for(int i=0;i<=n-k;i++){
            for(int j=k;j<k+2;j++){
                if(ispal(s,i,i+j-1)){
                   count++;
                   i+=j-1;
                  break;
                }
            }
        }
   return count; }
};