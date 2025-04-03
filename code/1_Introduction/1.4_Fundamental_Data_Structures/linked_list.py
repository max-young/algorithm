"""Implementation of a singly linked list data structure."""


class Node:
    """A node in a singly linked list containing data and a reference to the next node."""

    def __init__(self, data):
        """Initialize a Node with data and no next reference."""
        self.value = data
        self.next = None


class LinkedList:
    """Linked List class that manages a collection of nodes.
    """

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
        """
        Insert a new node with the given data at the beginning of the linked list.
        
        Args:
            data: The data to be stored in the new node.
            
        Time Complexity:
            O(1) - Constant time operation as it only updates pointers.
            
        Example:
            linked_list = LinkedList()
            linked_list.insert_begin(10)
        """
        node = Node(data)
        node.next = self.head
        self.head = node

    def insert_end(self, data):
        '''
        Inserts a new node with the given data at the end of the linked list.

        This method creates a new node with the provided data and adds it to the end of the
        linked list. If the list is empty, the new node becomes the head of the list.
        Otherwise, it traverses the list to find the last node and appends the new node.

        Args:
            data: The data to be stored in the new node.

        Time Complexity: O(n) where n is the number of nodes in the list,
        as it needs to traverse the entire list to find the last node.

        Space Complexity: O(1) as it only creates one new node regardless of list size.
        '''
        node = Node(data)
        if not self.head:
            self.head = node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = node
        return

    def insert_between(self, middle, data):
        """
        Inserts a new node with the given data after the first node containing the middle value.
        
        If a node with the middle value is found, the new node is inserted after it.
        If no node with the middle value is found, the new node is appended to the end of the list.
        If the list is empty, the new node becomes the head of the list.
        
        Args:
            middle: The value to search for in the list
            data: The data to be stored in the new node
            
        Returns:
            None
        """
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
        """
        Delete the first occurrence of a node with the given data value from the linked list.

        Args:
            data: The value to be deleted from the linked list.

        Returns:
            None. The method modifies the linked list in-place.

        Note:
            - If the list is empty, the method returns without any action.
            - If the head node contains the data to be deleted, the head is updated to the next node.
            - If the data is not found in the list, the list remains unchanged.
        """
        if not self.head:
            return
        if self.head.value == data:
            self.head = self.head.next
            return
        current = self.head
        next_node = current.next
        while next_node:
            if next_node.value == data:
                current.next = next_node.next
            current = next_node
            next_node = next_node.next

    def search(self, data):
        """
        Search for a node with the specified data in the linked list.
        
        Args:
            data: The value to search for in the linked list.
            
        Returns:
            bool: True if a node with the specified data is found, False otherwise.
            
        Time Complexity:
            O(n) where n is the number of nodes in the linked list.
        
        Space Complexity:
            O(1) as only a constant amount of extra space is used.
        """
        if not self.head:
            return False
        current = self.head
        while current:
            if current.value == data:
                return True
            current = current.next

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
        