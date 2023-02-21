#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // O(n*log(n))
  vector<int> get_row(int row_index) {
    vector<int> p(row_index+1, 1);
    for (int row = 1; row < row_index; row++)
      for (int i = row; i > 0; i--)
        p[i] += p[i-1];
    return p;
  }

  // recursive
  vector<int> get_row_1(int row_index) {
    vector<int> currow;
    currow.push_back(1);
    if (row_index == 0) return currow;
    vector<int> prev = get_row(--row_index);
    for (int i = 1; i < prev.size(); i++)
      currow.push_back(prev[i-1] + prev[i]);
    currow.push_back(1);
    return currow;
  }

  // too slow
  vector<int> get_row_2(int row_index) {
    vector<int> p(row_index);
    for (int i = 0; i < row_index; i++) {
      p.resize(i + 1);
      p[0] = p[i] = 1;
      int bef;
      int cur = 1;
      for (int j = 1; j < i; j++) {
        bef = p[j];
        p[j] += cur;
        cur = bef;
      }
    }
    return p;
  }
};

void print_vec(const vector<int> &v) {
  cout << "[ ";
  for (const auto &i : v)
    cout <<  i << " ";
  cout << "]" << endl;
}

int main() {
  Solution sol;
  for (int i = 0; i < 5; i++) print_vec(sol.get_row(i));
  return 0;
}
