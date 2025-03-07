## Permutation of a String  

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
