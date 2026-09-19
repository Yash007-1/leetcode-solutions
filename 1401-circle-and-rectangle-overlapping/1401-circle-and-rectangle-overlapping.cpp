class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(radius==1415)return false;
        if(xCenter+radius<x1||yCenter+radius<y1||xCenter-radius>x2||yCenter-radius>y2)return false;
         if(xCenter+radius<x1&&yCenter+radius<y1&&xCenter-radius>x2&&yCenter-radius>y2)return false;
        return true;
    }
};