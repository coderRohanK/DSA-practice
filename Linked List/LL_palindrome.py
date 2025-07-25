class Solution(object):
    def isPalindrome(self, head):
        fast=head
        slow=head
        while(fast and fast.next):
            fast=fast.next.next
            slow=slow.next
        cur=slow
        prev=None
        while(cur):
            temp=cur.next
            cur.next=prev
            prev=cur
            cur=temp
        first=head
        second=prev
        while(second):
            if(first.val!=second.val):
                return False
            first=first.next
            second=second.next
        return True
        