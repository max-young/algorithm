- [Example 12: Permutation of a String](#example-12-permutation-of-a-string)
  - [Thinking Process](#thinking-process)
  - [Python Code](#python-code)
  - [Time Complexity](#time-complexity)
- [Example 13: Fibonacci Sequence](#example-13-fibonacci-sequence)
- [Example 14: print fibonacci sequence](#example-14-print-fibonacci-sequence)
- [example 15: print fibonacci sequence with memoization](#example-15-print-fibonacci-sequence-with-memoization)
- [example 16: prints the power of 2 from 1 to n](#example-16-prints-the-power-of-2-from-1-to-n)


## Example 12: Permutation of a String  

### Thinking Process

Let's consider the permutations of a string from the shortest:

If the string is "", then return []  

If the string is "a", then return ["a"]  

If the string is "ab", then return ["ab", "ba"]  

If the string is "abc", it becomes a bit more complex, but we can think of it as:  
Fix the first character and permute the rest of the string.  
Set the first character one by one:  
```
abc, acb  
bac, bca  
cab, cba
```
The process is:  
Fix the first character, calculate the permutations of the rest of the string, and prepend the fixed character to each permutation of the rest of the string.

Let's calculate the permutations of "abcd":  
```
abcd, abdc, acbd, acdb, adbc, adcb
bacd, badc, bcad, bcda, bdac, bdca
cabd, cadb, cbad, cbda, cdab, cdba
dabc, dacb, dbac, dbca, dcab, dcba
```

### Python Code

The Python code is:
```python
def permutation(my_str):
  if len(my_str) == 0:
    return []
  if len(my_str) == 1:
    return [my_str]
  result = []
  index = 0
  for i in my_str:
    rest = my_str[:index] + my_str[index+1:]
    for j in permutation(rest):
      result.append(i + j)
    index += 1
  return result
```

### Time Complexity

The slicing operation `rest = my_str[:index] + my_str[index+1:]` takes O(n) time, and appending to the result list also takes O(n) time.

The number of recursive calls is as follows:
The function calls itself n times, each call creates n-1 recursive calls, then n-2, and so on.
This creates a tree-like structure of recursive calls with a total of n! calls.

Therefore, the total time complexity is O(n * n!).

## Example 13: Fibonacci Sequence

The fibonacci sequence is a sequence in which each element is the sum of the two elements that precede it.

the c++ code is:
```c++
int fib(int n)
{
  if (n <= 0)
    return 0;
  else if (n == 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
}
```

The time complexity pattern for recursive calls is: $O(branches^{depth})$(page 44). So the time complexity of the above code is $O(2^n)$.

## Example 14: print fibonacci sequence

```c++
void printFab(int n)
{
  for (int i = 0; i <= n; i++)
  {
    std::cout << fib(i) << std::endl;
  }
}
```

we know that the time complecity of fibonacci is $2^n$, so the total time complecity of printFab is:
$$
2^0 + 2^1 + 2^2 + ... + 2^n = 2^{n+1} - 1
$$
so the time complecity of printFab is still $O(2^n)$

> the sum of $2^0 + 2^1 + 2^2 + ... + 2^n$ be deducted by binary.

## example 15: print fibonacci sequence with memoization

```python
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
    
all_fib(10)
```
let's walk through what the code does:
fib(0)
    return 0
fib(1)
    return 1
fib(2)
    fib(0) -> return 0
    fib(1) -> return 1
    store 1 in fib_list
    return 1
fib(3)
    fib(1) -> return 1
    fib(2) -> lookup fib_list[2] -> return 1
    store 2 in fib_list
    return 2
fib(4)
    fib(2) -> lookup fib_list[2] -> return 1
    fib(3) -> lookup fib_list[3] -> return 2
    store 3 in fib_list
    return 3
fib(5)
    fib(3) -> lookup fib_list[3] -> return 2
    fib(4) -> lookup fib_list[4] -> return 3
    store 5 in fib_list
    return 5
...
the count of calls is constant.  
so if we call fib(n), the depth of the recursive call is n, but the number of calls in each level is constant, so the time complexity is O(n).

## example 16: prints the power of 2 from 1 to n

for example, the output of 4 is: $2^0 = 1, 2^1 = 2, 2^2 = 4$, the output of 5 is also: $2^0 = 1, 2^1 = 2, 2^2 = 4$
```python
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
```
The time complexity of this function is $O(\log n)$  
we can think in this way, each time n doubles, the number of calls increases by 1, so the number of calls n is in the equation $2^x = n$, so the time complexity is $O(\log n)$
