//
// Created by z on 4/24/2022.
// # 705

class MyHashSet {
public:

    std::vector<bool> x;

    MyHashSet() {
        x.resize(1000001, 0);
    }

    void add(int key) {
        x[key] = 1;
    }

    void remove(int key) {
        x[key] = 0;
    }

    bool contains(int key) {
        return x[key];
    }
};

