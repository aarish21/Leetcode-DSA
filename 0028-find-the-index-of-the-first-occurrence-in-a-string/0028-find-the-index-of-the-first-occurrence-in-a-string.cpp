class Solution
{
    public:
        int strStr(string s1, string s2)
        {
            int i = 0;
            int j = 0;
            int pos=0;
           
            while (i < s1.size())
            {

                if (s1[i] == s2[j])
                {
                    if (j == s2.size()-1)
                    {
                        return pos;
                    }
                    i++;
                    j++;
                }
                else
                {
                   
                    pos++;
                    i = pos;
                    j = 0;
                }
            }
            // if(ans == INT_MAX) return -1;
            return -1;
        }
};