//
// Created by z on 3/19/2022.
// # 895
// In fact, this is not the version I code initially. I made it cleaner. I was so happy that I wrote such neat code until I saw someone else's code...

class FreqStack {
public:
    vector<stack<int>> v;
    unordered_map<int, int> m;

    FreqStack() {
        v = {{},{}};
    }

    void push(int val) {
        if (m.find(val) == m.end())
            m[val] = 0;

        m[val]++;
        if (v.size() < m[val]+1)
            v.push_back({});
        v[m[val]].push(val);
    }

    int pop() {
        int ret = v[v.size()-1].top(), index = v.size()-1;
        m[ret]--;
        v[index].pop();
        if (v[index].empty())
            v.pop_back();
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */