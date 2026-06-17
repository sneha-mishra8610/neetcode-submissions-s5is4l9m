class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        pq.push(stones[i]);
        while(!pq.empty()){
            if(pq.size()==1)
            return pq.top();
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a==b)
            continue;
            pq.push(abs(a-b));
        }
        return 0;
    }
};