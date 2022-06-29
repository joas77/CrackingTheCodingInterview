
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

    def sum_reverse(self, linked_list):
        result = SingleLinkedList()
        n1, n2 = self.head, linked_list.head

        carry, digit = 0, 0
        while n1 and n2:
            s = n1.data + n2.data + carry
            if s > 9:
                digit = s - 10
                carry = s // 10
            else:
                digit = s

            result.append(digit)
            n1 = n1.next
            n2 = n2.next

        return result