def merge_sort(array):
    if len(array) <= 1:
        return array
    middle_index = len(array) // 2
    left_array = array[:middle_index]
    right_array = array[middle_index:]
    left_result = merge_sort(left_array)
    right_result = merge_sort(right_array)
    return merge_two_array(left_result, right_result)


def merge_two_array(array_a, array_b):
    len_a = len(array_a)
    len_b = len(array_b)
    result = []
    index_a = 0
    index_b = 0
    while index_a < len_a and index_b < len_b:
        if array_a[index_a] <= array_b[index_b]:
            result.append(array_a[index_a])
            index_a += 1
        else:
            result.append(array_b[index_b])
            index_b += 1
    if index_a < len_a:
        result += array_a[index_a:]
    if index_b < len_b:
        result += array_b[index_b:]
    return result

my_array = [9, 1, 2, 5, 3, 4, 7, 8, 6]
print(merge_sort(my_array))
