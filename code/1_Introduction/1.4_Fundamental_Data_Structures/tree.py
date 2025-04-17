class TreeNode:

    def __init__(self, value):
        self.value = value
        self.children = set()

    def add_children(self, node):
        self.children.add(node)

class Tree:
    def __init__(self, head):
        self.head = head

    def __repr__(self):
        current_level = [self.head]
        result = ""
        while True:
            temp_level = []
            for i in current_level:
                result = result + " " + str(i.value)
                for c in i.children:
                    temp_level.append(c)
            if not temp_level:
                break
            result += "\n"
            current_level = temp_level
        return result

if __name__ == "__main__":
    node1 = TreeNode(1)
    tree = Tree(node1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node4 = TreeNode(4)
    node1.add_children(node2)
    node1.add_children(node4)
    node4.add_children(node3)
    print(tree)
        