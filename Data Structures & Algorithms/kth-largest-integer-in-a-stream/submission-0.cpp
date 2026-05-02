class KthLargest {
public:
priority_queue<int> pq;
int kk;
int n;
    KthLargest(int k, vector<int>& nums) {
        n=nums.size();
        priority_queue<int> p;
        for(int i=0;i<n;i++){
            p.push(nums[i]);
        }
        for(int i=0;i<min(n,k);i++){
            pq.push(-p.top());
            p.pop();
        }
        kk=k;
    }
    int add(int val) {
        if(n<kk){
        pq.push(-1*val);
        n++;
        return -1*pq.top();
        }
        else{
        if(val<(-1*pq.top()))
        return -1*pq.top();
        else{
            pq.pop();
            pq.push(-1*val);
            return -1*pq.top();
        }
        }
    }
};