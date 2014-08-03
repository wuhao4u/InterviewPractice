# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def quicksort(unsortedList):
	headNode = unsortedList
	rightList = unsortedList
	leftList = None
	
	# pick the pivot from first of the list for now
	pivot = rightList.val
	while not rightList is None:
		if rightList.next.val < pivot:
			# for the first ele in the left list
			if leftList is None:
				leftList = rightList.next
				leftList.next = None
			else:
				leftList.next = rightList.next
				
				
			rightList.next = rightList.next.next
				
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