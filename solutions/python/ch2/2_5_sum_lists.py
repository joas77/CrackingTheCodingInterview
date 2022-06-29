from list import SingleLinkedList

if __name__ == "__main__":
    sl_num1 = SingleLinkedList()
    sl_num2 = SingleLinkedList()

    # sl_num1 represents 617 in reversed order i.e 7->1->6
    sl_num1.append(7)
    sl_num1.append(1)
    sl_num1.append(6)

    # sl_num2 represents 295 in reversed order i.e 5->9->2
    sl_num2.append(5)
    sl_num2.append(9)
    sl_num2.append(2)

    # 617 + 295 = 912

    sl_result = sl_num1.sum_reverse(sl_num2)
    sl_result.print() # it shall print 2->1->9->None

    
