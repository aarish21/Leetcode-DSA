class Solution {
public:
   
    int countVowelStrings(int n) {
//         if(n==1)    return 5;
//         if(n==2)    return (n*(n+1))/2;
        n = n+1;
     return n * (n + 1) * (n + 2) * (n + 3) / 24;
    }
};