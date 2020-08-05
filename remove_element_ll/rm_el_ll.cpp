#include <iostream>
#include <vector>
#include <string>

// Definition for singly-linked list.
struct ListNode : public std::enable_shared_from_this<ListNode>{
  int val;
  std::shared_ptr<ListNode> next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}

  bool has_next() const {
    return next != nullptr;
  }

  std::string toString() const {
    auto res = std::to_string(val);
    if (has_next()) res += "->";
    return res;
  }

  void print() const {
    auto curr = shared_from_this();
    while (curr != nullptr){
      std::cout << curr->toString();
      curr = curr->next;
    }
    std::cout << std::endl;
  }
};

std::shared_ptr<ListNode> buildLinkedList(std::vector<int> &nums){
  std::shared_ptr<ListNode> curr = std::make_shared<ListNode>(); // ListNode *curr = new ListNode();

  auto head = curr;

  if (nums.size() > 0)
    curr->val = nums[0];

  for (int i = 1; i < nums.size(); i++){
    curr->next = std::make_shared<ListNode>(nums[i]); // new ListNode(nums[i]);
    curr = curr->next;
  }

  return head;
}

std::shared_ptr<ListNode> removeElements(std::shared_ptr<ListNode> head, int val) {
  // my 3
  if (!head) return head;
  auto curr = head;
  while (curr->next){
    if (curr->next->val == val)
      curr->next = curr->next->next;
    else
      curr = curr->next;
  }
  if (head->val == val)
    head = head->next;
  return head;

  // // my 2
  // if (!head) return head;
  // for (auto curr = head, prev = curr; curr; curr = curr->next){
  //   if (curr->val == val){
  //     prev->next = curr->next;
  //   } else {
  //     prev = curr;
  //   }
  // }
  // if (head->val == val)
  //   head = head->next;
  // return head;

  // my 1
  // for (auto curr = head, prev = curr; curr != nullptr; curr = curr->next){
  //   if (curr->val == val){
  //     if (curr == head){
  //       prev = head = curr->next;
  //     } else {
  //       prev->next = curr->next;
  //     }
  //   } else {
  //     prev = curr;
  //   }
  // }
  // return head;

  // // double pointer
  // ListNode **cur = &head;
  // while (*cur) {
  //   if ((*cur)->val == val) {
  //     *cur = (*cur)->next;
  //   } else {
  //     cur = &(*cur)->next;
  //   }
  // }
  // return head;
}

// c++ -std=c++11 rm_el_ll.cpp && ./a.out
int main(int argc, char const *argv[]){
  // std::vector<int> nums = {1,2,6,3,4,5,6}; int val = 6; // 1->2->3->4->5
  std::vector<int> nums = {1,1,2,6,3,1,4,5,6}; int val = 1; // 2,6,3,4,5,6
  // std::vector<int> nums = {1,2}; int val = 2; // 1
  auto head = buildLinkedList(nums);

  // auto head = nullptr; int val = 1; // check for null
  auto result = removeElements(head, val);

  result->print();

  return 0;
}