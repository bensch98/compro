#include <iostream>
#include <set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool has_cycle(ListNode *head) {
    if (head == nullptr)
      return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow)
        return true;
    }
    return false;
  }

  bool has_cycle_1(ListNode *head) {
    set<ListNode*> ptrs;
    while (head) {
      if (ptrs.find(head) == ptrs.end())
        ptrs.insert(head);
      else
        return true;
      head = head->next;
    }
    return false;
  }
};

int main() {
  ListNode *head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;

  for (int i = 0; i < 10; i++) {
    if (head) {
      cout << head->val << " -> ";
      head = head->next;
    }
  }
  cout << endl;
  for (int i = 0; i < 10; i++) {
    if (head) {
      cout << head->next << endl;
      head = head->next;
    }
  }

  Solution sol;
  cout << "Has cycle: " << sol.has_cycle(head) << endl;;
  return 0;
}
