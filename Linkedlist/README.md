# Linked List
A linked list is a linear data structure where elements called nodes are stored in separate memory locations.Each node contains two parts,data and a reference to the next node.
1.Single linked list-Each node points to the next node and the last node points to NULL.
2.Double linked list-Each node has two pointers,one points to the next and the other points to the previous node.This allow traversal in both directions.
3.Circular linked list-The last node points back to the first node forming a circle.

# Linked list algorithms
1Insertion.Adding a newnode to the list can be done at the beginning,end or a specific position.To insert a the beginning create a newnode,set its next pointer to the head and then update the head to this newnode.
2.Deletion-Removing a node in  a list involves updating the pointer of the previous node to skip the node being deleted.If you are deleting the head,you simply update the head to the next node.
3.Traversal-To access elements you start from the head and follow the next pointers until you reach the NULL.
4.Searching-You can search for a value by traversing the list from the head and checking each node's data until you find the target or reach the end.
5.Reversing-To reverse a linked list you can iterate through the list,changing the next pointers of each node to point to the previous node instead of the next one.
6.Sorting-A bit complex but you can use merge sort or insertion sort.