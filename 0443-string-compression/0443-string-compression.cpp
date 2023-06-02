class Solution
{
    public:
        int compress(vector<char> &chars) {
            if(chars.size()<=1) return chars.size();
            int count=1,i=0,j=1;
            string s;
            while(j<chars.size()){
                if(chars[i]==chars[j]){
                    j++;
                } else{
                    s+=chars[i];
                    if(j-i>1){
                        string x = to_string(j-i);
                        s+=x;
                    }
                    i=j;
                }
                
            }
            s+=chars[i];
            if(j-i>1){
                
                string x = to_string(j-i);
                s+=x;
            }
            chars.clear();
            for(char x:s){
                chars.push_back(x);
            }
            return chars.size();
        }
};