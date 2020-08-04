#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
  int val;
  struct ListNode* next;
} ListNode_t;

ListNode_t* newNode(int val){
  ListNode_t* node = malloc(sizeof(ListNode_t));
  node->val = val;
  node->next = NULL;
  return node;
}

ListNode_t* buildLinkedList(int nums[], int numsSize){
  // puts("buildLinkedList");
  ListNode_t* head = NULL;
  if (numsSize == 0) return head;

  head = newNode(nums[0]);

  ListNode_t* curr = head;
  for (int i = 1; i < numsSize; i++){
    curr->next = newNode(nums[i]);
    curr = curr->next;
  }

  return head;
}

void printLinkedList(ListNode_t* head){
  // puts("printLinkedList");
  while (head){
    printf("%d", head->val);
    if (head->next) printf("->");
    head = head->next;
  }
  putchar('\n');
}

ListNode_t* removeElements(ListNode_t* head, int val){
  if (!head) return head;

  ListNode_t* curr = head;
  while (curr->next){
    if (curr->next->val == val)
      curr->next = curr->next->next;
    else
      curr = curr->next;
  }
  if (head->val == val) head = head->next;

  return head;
}

// clang rm_el_ll.c && ./a.out
int main(int argc, char const *argv[]){
  // int nums[] = {1,2,6,3,4,5,6}; int val = 6; // 1->2->3->4->5
  int nums[] = {1,1,2,6,3,1,4,5,6}; int val = 1; // 2,6,3,4,5,6
  // int nums[] = {1,2}; int val = 2; // 1

  int numsSize = sizeof(nums)/sizeof(int);
  ListNode_t* head = buildLinkedList(nums, numsSize);

  // printLinkedList(head);
  // ListNode_t* result = removeElements(NULL, 0); // check for null

  ListNode_t* result = removeElements(head, val);

  printLinkedList(result);

  return 0;
}