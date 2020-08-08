#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    std::string toString() {
        auto res = std::to_string(val);
        if (next) res += "->";
        return res;
    }
};

void printLL(ListNode* head) {
    auto cur = head;
    while (cur) {
        std::cout << cur->toString();
        cur = cur->next;
    }
    std::cout << std::endl;
}

ListNode* buildLL(int elements[], int size) {
    if (size == 0) return NULL;
    auto head = new ListNode(elements[0]);
    auto cur = head;
    for (int i = 1; i < size; i++) {
        cur->next = new ListNode(elements[i]);
        cur = cur->next;
    }
    return head;
}
// 4->5->1->9->3
// 5->1->9->3
// 1->9->3
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

// c++ -std=c++11 del_node.cpp && ./a.out
int main(int argc, char const *argv[]) {
    int nums[]{4,5,1,9};// int node = 5;

    int size = sizeof(nums)/sizeof(int);
    auto head = buildLL(nums, size);
    deleteNode(head);
    printLL(head);

    return 0;
}
