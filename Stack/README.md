# STACK
A stack is a linear data structure that follows the Last In First Out(LIFO) principle.
This means that the last element to be added to the stack is the first one to be removed.
It can be visualized as a stack of plates where you pick and add plates from the top.

# Key characterristics of stacks
1.LIFO-Last In First Out
2.Sequential Operations- Stack operations are performed at only one end,known as the top of the stack.

# Basic operations of the stack
1.Push-Inserting elements at the stack-added at the top.
2.Pop-Remove an element from the top of the stack.
3.Peek-Select the top most element from the stack.
4.IsFull-Check if the stack is Full.For array based stacks.
5.IsEmpty-Check if the stack is Empty.

# Real life examples of stack
1.Stack of plates
2.Pile of cards
3.Undo/Redo operations.
4.Browser history

# Applications of Stack
1.Expression evaluation
2.Fuction calls(Recursion)
3.Backtracking-Algorithms such as Depth First Search and pathfinding use stacks.
4.Undo/Redo in text editors
5.Browser history

# Types of stack implementation
1.Linked list based stacks
A stack can be implemented using a linked list which allows for dynamic memory allocation.
->Create a Node struct which holds the stack data and a pointer to the next node.
->Create a function to check whether the stack is empty.Return top==NULL if empty.
->Create a function to create a stack
->create a function to push elements to the stack.
->Create a function to pop elements to the stack
->Create a function to peek elemets from the stack
->Create a function to print elements
-Main function.

2.Arrays based stack
You can also implement a stack using arrays by maintaining a variable to track the index of the top element.
Define a MAX to hold array elements(a preprocessor)

# Algorithms in stack

1.DFS-Depth First Search
An algorithm used to traverse a tree of graph structure.
The algorithm explores as far as possible before backtracking.

# How it works
1.Starting point-DFS begins at a selected node often the root and explores as far down a branch as possible before moving to next branch.
2.Data structure-DFS is implemented using a stack data structure.This can either be a system stack(through recursion) or an explicit stack that you manage yourself.
3.Steps of the algorithm
->Push the starting node into the stack
->While stack is not empty
->Pop a node from the stack
->If the node has not been visited
->Mark it as visited
->Push all of its adjacent nodes into the stack
4.Recursion-An alternative way of implementing DFS is through recursion where a function calls itself for each unvisited node.
5.Applications of DFS
->Pathfinding in mazes of puzzles
->Finding connected components in a graph.

6.Complexity-The time complexity of DFS is O(v+e)
where v-vertices and e=edges of the graph.
Space complexity is O(v).