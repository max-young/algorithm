def sequential_search(A, k):
    n = len(A)
    A.append(k)
    i = 0
    while A[i] != k:
        i += 1
    if i < n:
        return i
    return -1

A = [1, 9]
k = 5
print(sequential_search(A, k))