#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *get_intersection_node(ListNode *head_a, ListNode *head_b) {
    ListNode *a = head_a;
    ListNode *b = head_b;
    while (a != b) {
      if (a) a = a->next;
      else a = head_b;
      if (b) b = b->next;
      else b = head_a;
    }
    return a;
  }
};

int main() {
  ListNode *x = new ListNode(1);
  ListNode *y = new ListNode(2);
  y->next = x;
  Solution sol;
  ListNode *intersection = sol.get_intersection_node(x, y);
  if (intersection)
    cout << "Intersection at: " << intersection << ", val = " << intersection->val << endl;
  else
    cout << "No intersection" << endl;
  return 0;
}
