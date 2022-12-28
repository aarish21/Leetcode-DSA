class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       priority_queue<int> pq;
        for(auto x: piles){
            pq.push(x);
        }
        while(k!=0){
            double x = pq.top();
            pq.pop();
            x = ceil(x/2);
            k--;
            pq.push(x);
        }
        int sum =0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};