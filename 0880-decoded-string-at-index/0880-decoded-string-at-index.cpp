class Solution {
public:
    string decodeAtIndex(string s, int k) {
//         long long int count = 0, n = 0;
//         for(int i=0;i<s.size();i++){
            
//             if(isdigit(s[i])){
//                 count = count + i - n;
//                 count = count*(s[i]-'0');
//                 n = i + 1;
//             }
            
//         }
        long long int count=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int d = (s[i]-'0');
                count *= d;
            }else {
                count++;
            }
        }
        cout<<count;
        
        for(int i=s.size()-1;i >= 0; i--){
            if(isdigit(s[i])){
                count /= (s[i]-'0');
                k %= count; 
            }
            else{
                if(k==0 || k == count)
                    return string(1,s[i]);
                
                count--;
            }
        }
        
        return "";
    }
};