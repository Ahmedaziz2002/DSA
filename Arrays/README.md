# ARRAYS
An array is a contiguous block of memory that can store elements of one type.
An array is a linear data structure.
#Characteristics of arrays
1.Homogeneous elements
2.Fixed size
3.Zero base indexing

# Advantages
1.Random access
2.Efficient memoy usage

# Disadvantage
1.Fixed size

# Searching algorithms in arrays
1.Linear search-a simple algorithm used to find a specific value in an array
It begins at the first element in the array and checks if it matches the target value.If not it then checks all the other elements one by one sequentially
2.Binary search-used to find a specific value in a sorted array.
Define the range which is low and high
Define the Mid point use the function mid=low+(high-low)/2
We check the value at the middle index if it matches the target we return mid if not check the left side whereby high=mid-1 or check the right side whereby low=mid+1
Repeat this process either Iteratively or recursively


# Sorting algorithms in Arrays
Arrays have various sorting algorithms which are used depending on the data size.
1.Bubble sort
Difficulty-Easy
Frequency of use-Rarely used in practice due to inefficiency.
Operation-Imagine comparing each pair of adjacement elements in an array.If the first element is greater than the second,swap them.Repeat this process for all pairs until you pass through the entire array without swapping.

2.Selection sort
Difficulty-Easy
Frequency of use-Rarely used for large data sets but easy to understand.
Operation-Think of it as finding the smalllest element in an array and swapping it with the first element.Then you repeat this process for the remaining unsorted portion of the array gradually buildng a sorted section at the beginning.

3.Insertion sort
Difficulty-Easy
Frequency of use-Commmonly used for small datasets or partially sorted array.
Operation-Visualize sorting a hand of playing cards.You take one card at a time and insert it into its correct position among the already sorted cards,shifying the others as necessary.

4.Merge Sort
Difficulty-Moderate
Frequency of use-Frequentlu used especially for large datasets due to its efficiency and stability.
Operation-Picture dividing the array into two halves,sorting each half recursively, and then merging the sorted halves together.This process continues until the entire array is sorted.

5.Quick sort
Difficulty-Moderate
Frequency of use-Very commonly used due to its efficiency and in place sorting capacity.
Operation-Imagine selecting a pivot elemet form the array,then rearranging the other elements into two groups,all elements less then the pivot to one side and those greater than the pivot to one side.You then recursively sort the two gropus.


6.Heap sort
Difficulty-Moderate
Frequency of use-Used in various applications especially where memory usage is a concern.
Operation-Think of building a binary heap structure from the array elements.Once the heap is built you repeatedly remove the largest element(for a max heap) and place it at the end of the array,adjusting the heap each time.

7.Counting sort
Difficulty-Moderate
Frequency of use-Used when range of input values is known and small,very efficient for specific cases.
Operation-Visualize counting occurences of each distinct element in the array.You then use this count to determine position of each elemenmt in the array.

8.Radix Sort
Difficulty-Moderate
Frequency of use-Used for sorting integers or strings,especially when the nu,ber of digits is limited.
Operation-Imagine sorting numbers based on each digit,starting from the lsd to the msd.You use a stable sorting algorithm like counting sort at each digit level.


9.Bucket sort
Difficulty-Moderate
Frequency of implementation-Effective for uniformly distributed data but less common due to specific requirements.
Operation-Think of dividing the array into several buckets based on range of values.You then sort each bucket individually using another sorting algorithm and finally concatenate the sorted buckets.


