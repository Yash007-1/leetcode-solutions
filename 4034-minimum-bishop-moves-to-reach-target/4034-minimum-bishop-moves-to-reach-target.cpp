class Solution {
public:
    
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int st=source[0],end=source[1];
        
        int t1=target[0],t2=target[1];
        if((st%2==end%2&&t1%2==t2%2)||(st%2!=end%2&&t2%2!=t1%2)){
            if((st+end)==(t1+t2)||(st-end)==(t1-t2))return 1;
            else return 2;
        }
        else return -1;
       
        
    }
};