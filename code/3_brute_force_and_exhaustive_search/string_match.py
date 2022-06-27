def string_match(t, p):
    n = len(t)
    m = len(p)
    if n == 0 or m == 0:
        return -1
    for i in range(n - m + 1):
        j = 0
        while j < m and t[i + j] == p[j]:
            j += 1
        if j == m:
            return i
    return -1

t = "hello world"
p = "he"
assert string_match(t, p) == 0
p = ""
assert string_match(t, p) == -1, "{}".format(string_match(t, p))
p = "llo"
assert string_match(t, p) == 2
