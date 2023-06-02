class Solution
{
    public:
        int compress(vector<char> &chars) {
            if(chars.size()<=1) return chars.size();
            int count=1,i=0,j=1,left=0;
            string s;
            while(j<chars.size()){
                if(chars[i]==chars[j]){
                    j++;
                } else{
                    chars[left]=chars[i];
                    left++;
                    if(j-i>1){
                        string x = to_string(j-i);
                        for(char c: x){
                            chars[left++]=c;
                        }
                       
                    }
                    i=j;
                }
                
            }
            chars[left++]=chars[i];
            if(j-i>1){
                string x = to_string(j-i);
                for(char c: x){
                    chars[left++]=c;
                }
            }
            // chars.clear();
            // for(char x:s){
            //     chars.push_back(x);
            // }
            return left;
        }
};