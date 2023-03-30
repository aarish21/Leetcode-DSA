class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0,i = a.length()-1,j = b.length()-1;
        string ans;

        while(i>=0 && j>=0) {
            if(a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1' ){
                if(carry==0) ans.push_back('1');
                else {ans.push_back('0'); carry = 1;}
                
            }
            else if(a[i] == '0' && b[j] == '0' ){
                if(carry==0) ans.push_back('0');
                else {ans.push_back('1'); carry = 0;}
               
            }
            else{
                if(carry==0){ans.push_back('0'); carry =1;} 
                else {ans.push_back('1'); carry = 1;}
               
            }
             i--;j--;
            
        }
        cout<<i<<" "<<j;
        // cout<<i;
        while(i>=0) {
            if(a[i] == '1' && carry == 1){
                ans.push_back('0'); carry =1;
            }
            else if (a[i]=='1' && carry == 0){
                ans.push_back('1'); carry = 0;
            }else if (a[i]=='0' && carry == 1){
                ans.push_back('1'); carry = 0;
            }else {
                ans.push_back('0'); carry = 0;
            }
            i--;
        }
         while(j>=0) {
            if(b[j] == '1' && carry == 1){
                ans.push_back('0'); carry =1;
            }
            else if (b[j]=='1' && carry == 0){
                ans.push_back('1'); carry = 0;
            }else if (b[j]=='0' && carry == 1){
                ans.push_back('1'); carry = 0;
            }else {
                ans.push_back('0'); carry = 0;
            }
            j--;
        }
       
        if(carry == 1) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};