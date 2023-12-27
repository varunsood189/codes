# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
#         dummy = ListNode()
#         temp = dummy

#         for list_ in lists:
#             prev = dummy   
#             dummy =dummy.next
#             while dummy and list_:
#                 if dummy.val<=list_.val:
#                     prev = dummy
#                     dummy = dummy.next                    
#                 else:
#                     prev.next=list_
#                     temp_value = dummy
#                     dummy= list_
#                     list_=temp_value
#             if list_:
#                 prev.next= list_
                            
#             dummy = temp        
#         return temp.next
import heapq
class comparenode():
    def __init__(self,node:ListNode):
        self.node = node
    def __lt__(self,other):
        return self.node.val<other.node.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        list_ = []
        for node in lists:
            if node :
                list_ +=[comparenode(node)]
        heapq.heapify(list_)
        temp = temp2 =ListNode()
        while list_:
            curr_node = heapq.heappop(list_)
            node = curr_node.node
            temp.next = node
            temp= node
            if(node.next):
                heapq.heappush(list_, comparenode(node.next))
        return temp2.next 





