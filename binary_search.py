#binary_search.py
def binary_search(array, target):
    low, high = 0, len(array) - 1
    
    while low <= high:
        mid = low + (high - low) // 2
        
        if array[mid] == target:
            return mid
        elif array[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1  # Target not found