#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool is_palindrome(string s) {
    int start = 0;
    int end = s.length() - 1;
    while (start < end) {
      char cs = tolower(s[start]);
      char ce = tolower(s[end]);
      if (!isalnum(cs)) {
        start++;
        continue;
      }
      if (!isalnum(ce)) {
        end--;
        continue;
      }
      if (cs != ce) return false;
      start++;
      end--;
    }
    return true;
  }

  bool is_palindrome_1(string s) {
    // convert to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    // filter by ASCII code
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
      if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
        tmp += s[i];
    // check for palindrome
    for (int i = 0; i < tmp.length(); i++)
      if (tmp[i] != tmp[tmp.length()-i-1])
        return false;
    return true;
  }
};

int main() {
  string s = "A man, a plan, a canal: Panama";
  Solution sol;
  bool pal = sol.is_palindrome(s);
  cout << "Is palindrome: " << pal << endl;
  return 0;
}
