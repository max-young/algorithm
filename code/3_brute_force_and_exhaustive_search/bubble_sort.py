def bubble_sort(A):
    n = len(A)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if A[j] > A[j+1]:
                temp = A[j]
                A[j] = A[j+1]
                A[j+1] = temp


A = [1, 2, 3, 6, 2, 8, 3, 9, 1, 0]
bubble_sort(A)
print(A)