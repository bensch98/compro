#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int num_rows) {
    vector<vector<int>> p(num_rows);
    for (int i = 0; i < num_rows; i++) {
      p[i].resize(i + 1);
      p[i][0] = p[i][i] = 1;
      for (int j = 1; j < i; j++)
        p[i][j] = p[i-1][j-1] + p[i-1][j];
    }
    return p;
  }

  vector<vector<int>> generate_1(int num_rows) {
    vector<vector<int>> p(num_rows);
    for (int i = 0; i < num_rows; i++) {
      if (i == 0) p[i].push_back(1);
      else {
        p[i].push_back(1);
        for (int j = 0; j < p[i-1].size() - 1; j++)
          p[i].push_back(p[i-1][j] + p[i-1][j+1]);
        p[i].push_back(1);
      }
    }
    return p;
  }
};

void print_vec(vector<int> &v, int w) {
  cout << setw(w) << "[ ";
  for (const auto &i : v)
    cout <<  i << " ";
  cout << "]" << endl;
}

void print_vecs(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); i++) print_vec(v[i], v.size()-i+1);
}

int main() {
  Solution sol;
  vector<vector<int>> pascals = sol.generate(10);
  print_vecs(pascals);
  return 0;
}


