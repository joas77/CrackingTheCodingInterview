from ast import If
from ctypes import sizeof


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def append(self, data):
        end = Node(data)
        n = self
        while n.next:
            n = n.next

        n.next = end


class SingleLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def append(self, data):
        if self.size == 0:
            self.head = Node(data)
        else:
            self.head.append(data)

        self.size += 1

    def __len__(self):
        return self.size

    def print(self):
        n = self.head
        while n is not None:
            print(n.data, end=" -> ")
            n = n.next

        print("None")

if __name__ == "__main__":
    slist = SingleLinkedList()
    assert len(slist) == 0
    
    n = 10 
    for i in range(n):
        slist.append(i)
    assert len(slist) == n

    slist.print()