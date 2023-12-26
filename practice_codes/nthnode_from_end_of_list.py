# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head==None or head.next==None:
            return  
        temp=head
        c=0
        while temp:
            c+=1
            temp=temp.next
        pos=c-n
        if pos==0:
            head=head.next
            return head
        tmp=head
        r=0
        while tmp:
            r+=1
            if r==pos:
                tmp.next=tmp.next.next
            tmp=tmp.next
        return head
            
