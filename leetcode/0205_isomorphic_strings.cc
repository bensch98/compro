#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool is_isomorphic(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, char> umap;
    unordered_set<char> uset;
    int i = 0;
    while (i < s.length()) {
      if (umap.find(s[i]) == umap.end() && uset.find(t[i]) != uset.end()) return false;
      if (umap.find(s[i]) == umap.end()) {
        umap[s[i]] = t[i];
        uset.insert(t[i]);
        s[i] = t[i];
      } else s[i] = umap.at(s[i]);
      i++;
    }
    return s == t;
  }
};

int main() {
  string s = "title";
  string t = "paper";
  Solution sol;

  bool isomorphic = sol.is_isomorphic(s, t);
  cout << "Isomorphic: " << isomorphic << endl;
  return 0;
}

