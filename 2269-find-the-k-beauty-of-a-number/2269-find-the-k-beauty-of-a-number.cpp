class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count=0;
        for(int i = 0; i <= s.length() - k; i++) {
             string temp = s.substr(i, k) ;
           
            int x = stoi(temp);
            // string y = to_string(x);
            if(x==0 ){
                continue;
            }
            if(num%x==0){
                count++;
            }
        }
        return count;
    }
};