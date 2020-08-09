# Definition for singly-linked list.
class ListNode
  attr_accessor :val, :next
  def initialize(val = 0)
    @val = val
    @next = nil
  end
end

# [1, 2, 3, 3, 4, 4, 5] => 1->2->3->3->4->4->5
def buildLL(arr)
  return nil if arr.size.zero?

  head = ListNode.new(arr[0])
  curr = head
  for i in (1...arr.size)
    curr.next = ListNode.new(arr[i])
    curr = curr.next
  end

  head
end

# 1->2->3->3->4->4->5
def printLL(head)
  curr = head
  while (curr)
    print curr.val
    print('->') if curr.next
    curr = curr.next
  end
  puts
end

# @param {ListNode} head
# @return {ListNode}
def delete_duplicates(head)
  return unless head
  curr = head
  prev = nil
  dval = nil
  while (curr.next)
    if (!dval)
      if (curr.val == curr.next.val)
        dval = curr.val
      else # curr.val != curr.next.val
        prev = curr
        curr = curr.next
      end
    else # dval is present
      if (curr.val == dval)
        if (prev)
          prev.next = curr.next
        else
          head = curr.next
        end
        curr = curr.next
      else
        dval = nil
      end
    end
  end
  if (curr.val == dval)
    if (prev)
      prev.next = curr.next
    else
      head = curr.next
    end
  end
  head
end

nums = [1, 2, 3, 3, 4, 4, 5] # 1->2->5
# nums = [1, 1, 1, 2, 3] # 2->3
# nums = [1, 1] # nil

head = buildLL(nums)
result = delete_duplicates(head)

printLL(result)
