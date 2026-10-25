class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int candy=0;
        int total=0;
        for(int i=n-1;i>=0;i--){
            if(candy==2){
                candy=0;
                continue;
            }
            total+=cost[i];
            candy++;
        }
    return total;}
};