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
  ListNode *merge_two_lists(ListNode *l1, ListNode *l2) {
    ListNode ll;
    ListNode *cur = &ll;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        cur->next = new ListNode(l2->val);
        l2 = l2->next;
      }
      cur = cur->next;
    }

    if (l1)
      cur->next = l1;
    else
      cur->next= l2;
    return ll.next;
  }
};

void print_ll(ListNode *ll) {
  // iterate over merged linked list
  cout << "List:" << endl;
  while (ll) {
    cout << ll->val;
    ll = ll->next;
    if (ll != nullptr)
      cout << ", ";
  }
  cout << endl << endl;;
}

int get_rand(int beg, int end) {
  return rand() % ((end - beg) + 1) + beg;
}

void create_ll(ListNode *ll) {
  ListNode *cur = ll;
  int min = 0;
  int max = 10;
  int tmp = 0;
  int r = get_rand(0, 100);
  for (int i = 0; i < r; i++) {
    tmp = get_rand(tmp, max);
    cur->next = new ListNode(tmp);
    cur = cur->next;
    max += 10;
  }
}

int main() {
  // init rand generator
  srand(static_cast<int>(time(0)));

  // testcase
  ListNode l1;
  ListNode l2;

  // create linked lists
  create_ll(&l1);
  print_ll(&l1);
  create_ll(&l2);
  print_ll(&l2);

  // run solution
  Solution sol;
  ListNode *lmerged = sol.merge_two_lists(&l1, &l2);

  cout << "Merged Linked List:" << endl;
  print_ll(lmerged);

  return 0;
}
