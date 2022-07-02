def insertion_sort(array):
  n = len(array)
  for i in range(1, n):
    v = array[i]
    j = i - 1
    while j >= 0 and array[j] > v:
      array[j+1] = array[j]
      j -= 1
    array[j+1] = v

array = [1, 2, 1, 5, 7, 4, 3]
insertion_sort(array)
print(array)