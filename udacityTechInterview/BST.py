class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST(object):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        self.insert_node(self.root, new_val)

    # insert_node : Node int -> Node
    def insert_node(self, node, new_val):
        if node == None:
            print(new_val)
            return Node(new_val)
        else:
            if new_val <= node.value:
                node.left = self.insert_node(node.left, new_val)
            else:
                node.right = self.insert_node(node.right, new_val)
            return node

    def search(self, find_val):
        if self.root.value == find_val:
            return True
            # elif find_val < self.
        return False

    def print_tree(self):
        """Print out all tree nodes
        as they are visited in
        a pre-order traversal."""
        res = []
        # self.preorder_print(self.root, res)
        self.inorder_print(self.root, res)
        return '-'.join(res)

    def preorder_print(self, start, traversal):
        """Helper method - use this to create a 
        recursive print solution."""
        traversal.append(str(start.value))

        if start.left:
            self.preorder_print(start.left, traversal)

        if start.right:
            self.preorder_print(start.right, traversal)

        return traversal

    # something's wrong here
    def inorder_print(self, start, traversal):
        if start.left:
            self.preorder_print(start.left, traversal)

        traversal.append(str(start.value))

        if start.right:
            self.preorder_print(start.right, traversal)

        return traversal


# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)
y = 0
# print(tree.print_tree())

# Check search
# Should be True
# print tree.search(4)
# Should be False
# print tree.search(6)