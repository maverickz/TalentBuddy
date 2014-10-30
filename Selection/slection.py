def select_kth_number(v,k):
    pivot = v[len(v)-1]
    left = []
    right = []
    for i in range(len(v)):
        if v[i] < pivot:
            left.append(v[i])
        elif v[i] > pivot:
            right.append(v[i])
    # the element is in the left subarray
    if k<= len(left):
        return select_kth_number(left, k)
    # the element is in the right subarray
    elif k > len(v) - len(right):
        return select_kth_number(right, k - (len(v) - len(right)))
    # the element is the pivot
    else:
        return pivot
        
def select_numbers(v, k):
    # Write your code here
    # To print results to the standard output you can use print
    # Example: print "Hello world!"
    # Find the kth largest number in the array
    kth_elem = select_kth_number(v,k)
    output = []
    # Find all numbers smaller than the kth largest element
    for elem in v:
        if elem <= kth_elem:
            output.append(elem)
    # Return the sorted output
    for sorted_elem in sorted(output):
        print sorted_elem