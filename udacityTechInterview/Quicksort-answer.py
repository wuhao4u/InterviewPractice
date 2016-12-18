"""Implement quick sort in Python.
Input a list.
Output a sorted list."""


def quicksort(array):
    return sort(array, 0, len(array)-1)

def sort(array, start, end):
    if start < end:
        # partition the list
        pivot = partition(array, start, end)

        # sort both halves
        sort(array, start, pivot-1)
        sort(array, pivot+1, end)
    return array 

def partition(array, start, end):
    pivotValue = array[start]

    # tracks element larger than pivotValue value
    left = start+1
    right = end
    done = False
    while not done:
        # find an element that is larger than pivotValue
        while left <= right and array[left] <= pivotValue:
            left = left + 1

        # find an element that is smaller or equal to pivotValue
        while array[right] > pivotValue and right >=left:
            right = right -1

        if right < left:
            done= True
        else:
            # swap places
            swap(array, left, right)

    # swap start with array[right]
    swap(array, start, right)
    return right

def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
print(quicksort(test))
