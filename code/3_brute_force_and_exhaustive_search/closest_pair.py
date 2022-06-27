import math

def closest_pair(P):
    min_distance = float('inf')
    n = len(P)
    for i in range(n-1):
        for j in range(i + 1, n):
            distance = math.dist(P[i], P[j])
            if distance < min_distance:
                min_distance = distance
    return min_distance

P = [[0, 0], [1, 0]]
assert closest_pair(P) == 1
P = [[0, 0], [1, 0], [1, 0.5]]
assert closest_pair(P) == 0.5