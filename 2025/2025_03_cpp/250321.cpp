// 2115. Find All Possible Recipes from Given Supplies
// Medium
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
#include <string>
#include <unordered_set>
#include <vector>

#include <unordered_map>

class Solution
{
public:
    bool is_possible(std::string &recipe, std::unordered_map<std::string, std::vector<std::string>> &ingredients_map, std::unordered_set<std::string> &supplies_set, std::unordered_set<std::string> &banned) {

        if (supplies_set.find(recipe) != supplies_set.end()) {
            return true;
        }

        auto &ingredients = ingredients_map[recipe];
        auto ret = true;

        for (auto &ingredient : ingredients) {
            // check banned
            if (banned.find(ingredient) != banned.end()) {
                return false;
            }
            // check already set
            if (supplies_set.find(ingredient) != supplies_set.end()) {
                continue;
            }
            // check recipe
            if (ingredients_map.find(ingredient) != ingredients_map.end()) {
                banned.insert(ingredient);
                if (is_possible(ingredient, ingredients_map, supplies_set, banned)) {
                    banned.erase(ingredient);
                    continue;
                }
                banned.erase(ingredient);
            }
            ret = false;
            break;
        }

        return ret;
    }

    std::vector<std::string> findAllRecipes(std::vector<std::string> &recipes, std::vector<std::vector<std::string>> &ingredients, std::vector<std::string> &supplies) {

        std::unordered_map<std::string, std::vector<std::string>> ingredients_map;
        std::unordered_set<std::string> supplies_set, banned;

        // init ingredients_map
        for (int i = 0; i < recipes.size(); i++) {
            auto &recipe = recipes[i];
            auto &target_ingredients = ingredients[i];
            ingredients_map[recipe] = target_ingredients;
        }

        // init supplies_set
        for (auto &already : supplies) {
            supplies_set.insert(already);
        }

        std::vector<std::string> ret;
        for (auto &recipe : recipes) {
            banned.insert(recipe);
            if (is_possible(recipe, ingredients_map, supplies_set, banned)) {
                ret.push_back(recipe);
            }
            banned.clear();
        }

        return ret;
    }
};