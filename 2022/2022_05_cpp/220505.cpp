//
// Created by z on 5/8/2022.
// # 225

class MyStack {
public:

    std::queue<int> q;
    int stk_top = -1;

    MyStack() {

    }

    void push(int x) {
        q.push(x);
        stk_top = x;
    }

    int pop() {

        std::queue<int> tmp;
        int ret = stk_top, n = q.size();
        for (int i = 0; i < n-1; i++) {

            int x = q.front();
            q.pop();
            tmp.push(x);
            stk_top = x;
        }
        q = tmp;
        return ret;
    }

    int top() {
        return stk_top;
    }

    bool empty() {
        return q.size() == 0;
    }
};


