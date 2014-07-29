# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def quicksort(unsortedList):
	headNode = unsortedList
	return headNode

def createLinkList(mList):
	headNode = ListNode(mList[0])
	temp = headNode
	for i in range(1, len(mList)):
		temp.next = ListNode(mList[i])
		temp = temp.next
	return headNode
		
def traverse(linkedList):
	tempLL = linkedList
	while tempLL.next != None:
		print tempLL.val
		tempLL = tempLL.next
		

l1 = [6,5,1,3,8,4,7,9,2]
ll1 = createLinkList(l1)
traverse(quicksort(ll1))