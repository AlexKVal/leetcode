#include <iostream>
#include <vector>
#include <string>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  std::string toString() const {
    auto res = std::to_string(val);
    if (next != nullptr) res += "->";
    return res;
  }

  void print() const {
    auto curr = this;
    while (curr->next != nullptr){
      std::cout << curr->toString();
      curr = curr->next;
    }
    std::cout << curr->toString() << std::endl;
  }
};

ListNode* buildLinkedList(std::vector<int> &nums){
  ListNode *curr = new ListNode();
  auto head = curr;

  if (nums.size() > 0)
    curr->val = nums[0];

  for (int i = 1; i < nums.size(); i++){
    curr->next = new ListNode(nums[i]);
    curr = curr->next;
  }

  return head;
}

ListNode* removeElements(ListNode* head, int val) {
  return head;
}

// c++ -std=c++11 rm_el_ll.cpp && ./a.out
int main(int argc, char const *argv[]){
  std::vector<int> nums = {1,2,6,3,4,5,6}; int val = 6; // 1->2->3->4->5
  auto head = buildLinkedList(nums);

  auto result = removeElements(head, 6);

  result->print();

  return 0;
}