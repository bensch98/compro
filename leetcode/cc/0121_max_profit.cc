#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int max_profit(vector<int> &prices) {
    int profit = 0;
    int tmp = INT_MAX;
    for (int i = 0; i < prices.size(); i++) {
      tmp = min(prices[i], tmp);
      profit = max(prices[i] - tmp, profit);
    }
    return profit;
  }
};

int main() {
  vector<int> prices = { 7, 1, 5, 3, 6, 4 };
  Solution sol;
  int res = sol.max_profit(prices);
  cout << "Max profit: " << res << endl;
  return 0;
}
