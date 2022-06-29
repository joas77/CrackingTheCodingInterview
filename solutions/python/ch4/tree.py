from re import X


class BinSearchTree:
    def __init__(self) -> None:
        self.root = None

    def insert(self, key, data):
        y = None
        x = self.root
        new_node = Tnode(key, data)

        while x:
            y = x
            if new_node.key < x.key:
                x = x.left
            else:
                x = x.right
        
        new_node.parent = y

        if y is None:
            self.root = new_node # tree was empty
        elif new_node.key < y.key:
            y.left = new_node
        else:
            y.right = new_node

    def inorder_traversal(self, node):
        
        if node:
            
            self.inorder_traversal(node.left)
            print(f"({node.key}, {node.data})", end=", ")
            self.inorder_traversal(node.right)

        

    def print(self):
        print("[", end= " ")
        self.inorder_traversal(self.root)
        print("]")

class Tnode:
    def __init__(self, key, data, left=None, right=None) -> None:
        self.key = key
        self.data = data
        self.left = left
        self.right = right
        self.parent = None


if __name__ == "__main__":
    tree = BinSearchTree()
    for i in range (1, 10):
        tree.insert(i, 2*i)

    tree.print() # should print [(1,2), (2,4), ..., (9,18)]