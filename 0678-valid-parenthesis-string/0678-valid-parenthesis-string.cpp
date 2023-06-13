class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0,leftMax = 0;
        for(int a:s){
            if(a=='('){
                leftMin+=1;
                leftMax+=1;
            }else if(a==')'){
                leftMin-=1;
                leftMax-=1;
            }else {
                leftMin-=1;
                leftMax+=1;
            }
            
            if(leftMin<0) leftMin=0;
            if(leftMax<0) return false;
        }
        return leftMin==0;
    }
};