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
        if node is None:
            return Node(new_val)
        else:
            if new_val <= node.value:
                node.left = self.insert_node(node.left, new_val)
            else:
                node.right = self.insert_node(node.right, new_val)
            return node

    def search(self, find_val):
        return self.search_node(self.root, find_val)

    def search_node(self, node, find_val):
        if node:
            if node.value == find_val:
                return True
            else:
                return (self.search_node(node.left, find_val)) or (self.search_node(node.right, find_val))
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
        if start:
            traversal.append(str(start.value))

            self.preorder_print(start.left, traversal)

            self.preorder_print(start.right, traversal)

        return traversal

    def inorder_print(self, start, traversal):
        if start:
            self.inorder_print(start.left, traversal)

            traversal.append(str(start.value))

            self.inorder_print(start.right, traversal)

        return traversal


# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# print(tree.print_tree())

# Check search
# Should be True
print(tree.search(4))
print(tree.search(1))
print(tree.search(5))

# Should be False
print(tree.search(6))
print(tree.search(0))
print(tree.search(100))