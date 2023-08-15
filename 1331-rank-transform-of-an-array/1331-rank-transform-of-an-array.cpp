class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a(arr.begin(),arr.end());
        map<int,int> m;
        sort(a.begin(),a.end());
        int temp=1;
        for(int i=0;i<arr.size();i++){
            if(m.count(a[i])<1)
                m[a[i]] = temp++;
                
        }
        for(int i=0;i<arr.size();i++){
             arr[i]=m[arr[i]];
        }
        return arr;
    }
};