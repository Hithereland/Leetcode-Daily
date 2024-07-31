//
//
//

#include <climits>
#include <vector>

class Solution
{
    const int THICKNESS = 0;
    const int HEIGHT    = 1;

  public:
    int minHeightShelves(std::vector<std::vector<int>> &books, int shelfWidth)
    {
        int n = books.size();

        // dp[i] = min height, exclude books with index >= i
        std::vector<int> dp(n + 1);

        dp[1] = books[0][HEIGHT];

        for (int i = 0; i < books.size(); i++) {
            int tmp_ans = INT_MAX, tmp_max_height = 0, tmp_width = 0;

            for (int j = i; j >= 0; j--) {
                tmp_max_height = std::max(books[j][HEIGHT], tmp_max_height);
                tmp_width += books[j][THICKNESS];
                if (tmp_width > shelfWidth) {
                    break;
                }
                // valid
                tmp_ans = std::min(dp[j] + tmp_max_height, tmp_ans);
            }

            dp[i + 1] = tmp_ans;
        }

        return dp[n];
    }
};