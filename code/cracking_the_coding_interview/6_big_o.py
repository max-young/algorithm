def all_fib(n):
    my_list = [0 for i in range(n)]
    for i in range(n):
        print(f"{i} fibnacci is: {fib(i, my_list)}")

        
def fib(n, fib_list):
    assert isinstance(n, int), "n must be integer"
    if n <= 0:
        return 0
    if n == 1:
        return 1
    if fib_list[n] > 0:
        return fib_list[n]
    fib_list[n] = fib(n-2, fib_list) + fib(n-1, fib_list)
    return fib_list[n]

def powersof2(n):
    assert isinstance(n, int), "n nust be integer"
    if n < 1:
        return 0
    elif n == 1:
        print(1)
        return 1
    else:
        prev = powersof2(n // 2)
        curr = prev * 2
        print(curr)
        return curr

powersof2(16)
