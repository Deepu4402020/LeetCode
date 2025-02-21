class MinStack {
public:
    int top_=-1;vector<int> v;int mini=INT_MAX;

    MinStack() {
        
        
    }
    
    void push(int val) {
        
        top_++;
        v.push_back(val);
        if(val<mini){mini=val;}
    }
    
    void pop() {
        
        v.erase(v.begin()+top_);top_--;
    }
    
    int top() {
        return v.at(top_);
    }
    
    int getMin() {
       
        int minim=*min_element(v.begin(),v.end());
        return minim;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */