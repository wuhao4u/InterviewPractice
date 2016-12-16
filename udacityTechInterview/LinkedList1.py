"""The LinkedList code from before is provided below.
Add three functions to the LinkedList.
"get_position" returns the element at a certain position.
The "insert" function will add an element to a particular
spot in the list.
"delete" will delete the first element with that
particular value.
Then, use "Test Run" and "Submit" to run the test cases
at the bottom."""

class Element(object):
    def __init__(self, value):
        self.value = value
        self.next = None
        
class LinkedList(object):
    def __init__(self, head=None):
        self.head = head
        
    def append(self, new_element):
        curPtr = self.head
        if self.head:
            while curPtr.next:
                curPtr = curPtr.next
            curPtr.next = new_element
        else:
            self.head = new_element
            
    def get_position(self, position):
        """Get an element from a particular position.
        Assume the first position is "1".
        Return "None" if position is not in the list."""
        if position < 1:
            return None

        counter = 1
        current = self.head
        while current and counter != position:
            if current.next:
                current = current.next
                counter += 1
            else:
                return None

        return current
    
    def insert(self, new_element, position):
        """Insert a new node at the given position.
        Assume the first position is "1".
        Inserting at position 3 means between
        the 2nd and 3rd elements."""
        prev = self.get_position(position-1)
        tempPtr = prev.next
        prev.next = new_element
        prev.next.next = tempPtr

    
    def delete(self, value):
        """Delete the first node with a given value."""
        if self.head.value == value:
            self.head = self.head.next
        else:
            curPtr = self.head
            while curPtr.next:
                if curPtr.next.value == value:
                    curPtr.next = curPtr.next.next
                else:
                    curPtr = curPtr.next

# Test cases
# Set up some Elements
e1 = Element(1)
e2 = Element(2)
e3 = Element(3)
e4 = Element(4)

# Start setting up a LinkedList
ll = LinkedList(e1)
ll.append(e2)
ll.append(e3)

# Test get_position
# Should print 3
print ll.head.next.next.value
# Should also print 3
print ll.get_position(3).value

# Test insert
ll.insert(e4,3)
# Should print 4 now
print ll.get_position(3).value

# Test delete
ll.delete(1)
# Should print 2 now
print ll.get_position(1).value
# Should print 4 now
print ll.get_position(2).value
# Should print 3 now
print ll.get_position(3).value

print ll.get_position(10)