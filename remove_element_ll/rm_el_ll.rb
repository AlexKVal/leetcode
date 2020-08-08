# Definition for singly-linked list.
class ListNode
  attr_accessor :val, :next
  def initialize(val = 0, _next = nil)
    @val = val
    @next = _next
  end

  def to_s
    cur = self
    res = []
    while cur
      res << cur.val
      res << '->' if cur.next
      cur = cur.next
    end
    res.join
  end
end

def build_linked_list(arr)
  return nil if arr.size.zero?
  cur = head = ListNode.new(arr[0])
  for i in 1...arr.size
    cur.next = ListNode.new(arr[i])
    cur = cur.next
  end
  head
end

# @param {ListNode} head
# @param {Integer} val
# @return {ListNode}
def remove_elements(head, val)
  return head unless head
  #
  return head
end


# head = build_linked_list([1,2,6,3,4,5,6]); val = 6; # 1->2->3->4->5
head = build_linked_list([1,1,2,6,3,1,4,5,6]); val = 1; # 2,6,3,4,5,6
# head = build_linked_list([1,2]); val = 2; # 1
# head = build_linked_list([]); val = 0

res = remove_elements(head, val)

puts res.to_s
