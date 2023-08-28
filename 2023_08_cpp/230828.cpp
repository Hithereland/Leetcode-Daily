// No. 225
// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
private:
    list<int> l;
public:
    MyStack() {

    }

    void push(int x) {
        l.push_front(x);
    }

    int pop() {
        int ret = l.front();
        l.pop_front();
        return ret;
    }

    int top() {
        return l.front();
    }

    bool empty() {
        return l.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */