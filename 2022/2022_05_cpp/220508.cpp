//
// Created by z on 5/8/2022.
// # 341

class NestedIterator {
public:

    std::vector<int> v;
    int index;

    static std::vector<int> restore(std::vector<NestedInteger> &nestedList) {

        std::vector<int> ret;

        for (auto &x: nestedList) {

            if (x.isInteger()) {
                ret.push_back(x.getInteger());
            } else {

                std::vector<int> tmp = restore(x.getList());
                ret.insert(ret.end(), tmp.begin(), tmp.end());
            }
        }

        return ret;
    }


    NestedIterator(vector<NestedInteger> &nestedList) {
        v = restore(nestedList);
        index = 0;
    }

    int next() {
        index++;
        return v[index-1];
    }

    bool hasNext() {
        return index - v.size();
    }
};
