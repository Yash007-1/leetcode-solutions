class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candy(n,1);
        int candies=0;
        for(int i=0;i<n;i++){
            if(i&&ratings[i]>ratings[i-1]){
                candy[i]=max(candy[i],candy[i-1]+1);
                
            }
            if(i<n-1&&ratings[i]>ratings[i+1]){
                candy[i]=max(candy[i],candy[i+1]+1);
            }
            
        }
         for(int i=n-1;i>=0;i--){
            if(i&&ratings[i]>ratings[i-1]){
                candy[i]=max(candy[i],candy[i-1]+1);
                
            }
            if(i<n-1&&ratings[i]>ratings[i+1]){
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }
        for(auto i:candy)candies+=i;
    return candies;}
};