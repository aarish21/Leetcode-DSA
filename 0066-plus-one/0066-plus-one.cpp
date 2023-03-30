class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> output;
        int carry = 0;
        int dig = (digits[digits.size()-1]+1);
        output.push_back(dig%10);
        
        for(int i=digits.size()-2;i>=0;i--){
            carry = dig/10;
            dig = (digits[i]+ carry);
            
            
            output.push_back(dig%10);
        }
        if(output[output.size()-1]==0) output.push_back(1);
        reverse(output.begin(),output.end());
        return output;
    }
};