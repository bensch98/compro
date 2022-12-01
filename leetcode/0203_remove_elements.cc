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
  ListNode *remove_elements(ListNode *head, int val) {
    if (head == nullptr) return nullptr;
    while (head != nullptr && head->val == val)
      head = head->next;
    ListNode *ln = head;

    while (ln != nullptr && ln->next != nullptr) {
      if (ln->next->val == val)
        ln->next = ln->next->next;
      else
        ln = ln->next;
    }

    return head;
  }
};

int main() {
  vector<int> v = { 1, 2, 2, 1 };
  ListNode *ln = new ListNode();
  ListNode *head = ln;
  for (const auto &i : v) {
    ln->val = i;  
    ln->next = new ListNode();
    ln = ln->next;
  }

  Solution sol;
  head = sol.remove_elements(head, 2);

  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << endl;

  return 0;
}
