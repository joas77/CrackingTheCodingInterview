from list import SingleLinkedList

if __name__ == "__main__":
    slist = SingleLinkedList()
    assert len(slist) == 0
    
    n = 10 
    for i in range(n):
        slist.append(i)
    assert len(slist) == n

    slist.print()