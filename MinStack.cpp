class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        m_stack.push(x);
        if (m_min_stack.empty()) m_min_stack.push(x);
        else m_min_stack.push(min(m_min_stack.top(), x));
    }
    
    void pop() {
        m_stack.pop();
        m_min_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_min_stack.top();
    }
private:
    stack<int> m_stack;
    stack<int> m_min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */