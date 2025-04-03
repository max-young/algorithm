"""Implementation of a singly linked list data structure."""


class Node:
    """A node in a singly linked list containing data and a reference to the next node."""

    def __init__(self, data):
        """Initialize a Node with data and no next reference."""
        self.value = data
        self.next = None


class LinkedList:

    def __init__(self, data=None):
        if data:
            self.head = Node(data)
        else:
            self.head = None

    def __repr__(self):
        if not self.head:
            return ""
        repr_str = str(self.head.value)
        current = self.head
        while current:
            if current.next:
                repr_str += f" -> {current.next.value}"
            else:
                repr_str += " -> None"
            current = current.next
        return repr_str

    def insert_begin(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node

    def insert_end(self, data):
        node = Node(data)
        if not self.head:
            self.head = node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = node
    
    def insert_between(self, middle, data):
        node = Node(data)
        if not self.head:
            self.head = node
            return
        current = self.head
        while True:
            if current.value == middle:
                node.next = current.next
                current.next = node
                return
            if current.next:
                current = current.next
            else:
                break
        current.next = node
        return

    def delete(self, data):
        if not self.head:
            return
        if self.head.value == data:
            self.head = self.head.next
            return
        current = self.head
        next = current.next
        while next:
            if next.value == data:
                current.next = next.next
            current = next
            next = next.next

    def search(self, data):
        if not self.head:
            return False
        current = self.head
        while current:
            if current.value == data:
                return True
            current = current.next
        return False

if __name__ == "__main__":
    my_list = LinkedList()
    my_list.insert_begin(3)
    my_list.insert_begin(2)
    my_list.insert_begin(1)
    my_list.insert_end(4)
    my_list.insert_end(5)
    print(my_list)
    print(my_list.search(3))
    my_list.delete(3)
    print(my_list)
    print(my_list.search(3))
        