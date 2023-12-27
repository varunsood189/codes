# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dummy = ListNode()
        temp = dummy

        for list_ in lists:
            prev = dummy   
            dummy =dummy.next
            while dummy and list_:
                if dummy.val<=list_.val:
                    prev = dummy
                    dummy = dummy.next                    
                else:
                    prev.next=list_
                    temp_value = dummy
                    dummy= list_
                    list_=temp_value
            if list_:
                prev.next= list_
                            
            dummy = temp        
        return temp.next
