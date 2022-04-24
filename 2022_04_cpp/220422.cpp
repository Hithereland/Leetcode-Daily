//
// Created by z on 4/24/2022.
// # 706

class MyHashMap {
public:
    vector<int> x;
    MyHashMap() {
        x.resize(1000001, -1);
    }

    void put(int key, int value) {
        x[key] = value;
    }

    int get(int key) {
        return x[key];
    }

    void remove(int key) {
        x[key] = -1;
    }
};

