# Definition for singly-linked list.
class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

  def print(self):
    curr = self
    while curr:
      print(curr.val, end='')
      if curr.next:
        print("->", end='')
      curr = curr.next
    print()

def buildLinkedList(elements: dict):
  if len(elements) == 0: return None
  head = ListNode(elements[0])
  curr = head
  for i in range(1, len(elements)):
    curr.next = ListNode(elements[i])
    curr = curr.next
  return head


# solution
def removeElements(head: ListNode, val: int) -> ListNode:
  return head


# head = buildLinkedList([1,2,6,3,4,5,6]); val = 6; # 1->2->3->4->5
# head = buildLinkedList([1,1,2,6,3,1,4,5,6]); val = 1; # 2,6,3,4,5,6
head = buildLinkedList([1,2]); val = 2; # 1

res = removeElements(head, val)

if res: res.print()
