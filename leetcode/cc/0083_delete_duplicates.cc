#include <iostream>

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
  ListNode *delete_duplicates(ListNode *head) {
    ListNode *cur = head;

    while (cur && cur->next) {
      if (cur->val == cur->next->val)
        cur->next = cur->next->next;
      else
        cur = cur->next;
    }

    return head;
  }
};

void print_ll(ListNode *ll) {
  cout << "List:" << endl;
  while (ll) {
    cout << ll->val;
    ll = ll->next;
    if (ll != nullptr)
      cout << ", ";
  }
  cout << endl << endl;
}

int get_rand(int beg, int end) {
  return rand() % ((end - beg) + 1) + beg;
}

void create_ll(ListNode *ll) {
  ListNode *cur = ll;
  int tmp;
  int j = 0;
  for (int i = 0; i < 10; i++) {
    tmp = get_rand(0, 100);
    if (tmp < 50)
      j++;
    cur->next = new ListNode(j);
    cur = cur->next;
  }
}

int main() {
  // init rand generator
  srand(static_cast<int>(time(0)));

  // testcase
  ListNode ll;
  create_ll(&ll);
  print_ll(&ll);

  // solution
  Solution sol;
  sol.delete_duplicates(&ll);

  cout << "Result linked list: " << endl;
  print_ll(&ll);

  return 0;
}
