def selection_sort(array):
    n = len(array)
    for i in range(n-1):
        min_index = i
        for j in range(i + 1, n):
            if array[j] < array[min_index]:
                min = j
        min_value = array[min_index]
        array[min_index] = array[i]
        array[i] = min_value

array = [1, 0, 1, 4, 2, 7, 9]
selection_sort(array)
print(array)