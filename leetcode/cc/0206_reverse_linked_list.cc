#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverse_list(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (head) {
      curr = curr->next;
      head->next = prev;
      prev = head;
      head = curr;
    }
    return prev;
  }
};

int main() {
  vector<int> v = { 1, 2, 3, 4, 5 };
  ListNode *ln = new ListNode();
  ListNode *head = ln;
  for (const auto &i : v) {
    ln->val = i;
    ln->next = new ListNode();
    ln = ln->next;
  }
  ln = head;
  while (ln) {
    cout << " -> " << ln->val;
    ln = ln->next;
  }
  cout << endl;

  Solution sol;
  head = sol.reverse_list(head);

  while (head) {
    cout << " -> " << head->val;
    head = head->next;
  }
  cout << endl;
  return 0;
}
