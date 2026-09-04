class Solution {
public:
    bool checkValidString(string s) {
        int maxo=0,mino=0;
        for(auto c:s){
            if(c=='('){
                mino++;maxo++;
            }
            if(c==')'){
                mino--;maxo--;
            }
            if(c=='*'){
                mino--;maxo++;
            }
            if(maxo<0)return false;
            mino=max(0,mino);
        }
    return mino==0;}
};