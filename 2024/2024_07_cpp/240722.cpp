// 2418. Sort the People
// Easy
// https://leetcode.com/problems/sort-the-people/

#include <vector>
#include <string>
#include <algorithm>

class Solution
{
  public:
    std::vector<std::string> sortPeople(std::vector<std::string> &names,
                                        std::vector<int> &heights)
    {
        typedef struct person
        {
            std::string _name;
            int _height;
            person(std::string &name, int height) : _name(name), _height(height)
            {}
        } person;

        std::vector<person> people;
        for (int i = 0; i < names.size(); i++) {
            people.push_back(person(names[i], heights[i]));
        }

        sort(people.begin(), people.end(),
             [](person a, person b) -> bool { return a._height > b._height; });

        std::vector<std::string> ret;
        for (auto &p : people) {
            ret.push_back(p._name);
        }

        return ret;
    }
};