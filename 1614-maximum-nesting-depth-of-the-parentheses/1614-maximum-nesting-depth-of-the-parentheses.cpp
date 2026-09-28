class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int ans=0;
        for(auto i:s){
            if(i=='(')depth++;
            else if(i==')'){
                depth--;
            }
            ans=max(ans,depth);
        }
    return ans;}
};