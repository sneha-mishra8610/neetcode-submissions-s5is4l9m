class MedianFinder {
public:
priority_queue<double> m1;
priority_queue<double> m2;
int mid;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        double d=1.0*num,a=-1e6,b=-1e6;
        if(m1.size()>0)
        a=m1.top();
        if(m2.size()>0)
        b=-m2.top();
        if(a==-1e6){
        m1.push(d);
        return;
        }
        if(d<=a)
        m1.push(d);
        else
        m2.push(-d);
        int l1=m1.size(),l2=m2.size();
        if(l1>0)
        a=m1.top();
        if(l2>0)
        b=-m2.top();
        if(l2>l1){
            m2.pop();
            m1.push(b);
        }else if(l2+1<l1){
            m1.pop();
            m2.push(-a);
        }
    }
    
    double findMedian() {
        double a=-1e6,b=-1e6;
        int l1=m1.size(),l2=m2.size();
        if(l1>0)
        a=m1.top();
        if(l2>0)
        b=-m2.top();
        if(l1>l2)
        return a;
        else{
            double ans=(a+b)/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */