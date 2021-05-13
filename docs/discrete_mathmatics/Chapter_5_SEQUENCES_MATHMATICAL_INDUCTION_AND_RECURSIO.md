<!-- TOC -->

- [5.1 Sequences](#51-sequences)
- [5.5 Application: Correctness of Algorithms](#55-application-correctness-of-algorithms)
- [5.9 General Recursive Definitions and Structural Induction](#59-general-recursive-definitions-and-structural-induction)

<!-- /TOC -->

Chapter5 SEQUENCES, MATHMATICAL INDUCTION, AND RECURSION

<a id="markdown-51-sequences" name="51-sequences"></a>
#### 5.1 Sequences

- sequence

  sequence的定义有一些奇怪: A **sequence** is a function whose domain is either all the integers between two given integers or all the integers greater than or equal to a given integer.

- Summation Notation

  有这样的一个sequence, $A_k = 2^k$, 我们要求前六个term的求和:

  $$A_1 + A_2 + A_3 + A_4 + A_5 + A_6 = 2^1 + 2^2 + 2^3 + 2^4 + 2^5 + 2^6 = 126$$

  有没有更简单的表示呢?

  if m and n are integers and $m\leq n$, the symbol $\sum\limits_{k=m}^{n} a_k$, read the summation from k equals m to n of a-sub-k, is the sum of all the terms $a_m, a_{m+1}, a_{m+2}, ..., a_n$. we say that $a_m + a_{m+1} + a_{m+2} + ... + a_n$ is the expand form of the sum, and we write:

  $$\sum\limits_{k=m}^na_k = a_m + a_{m+1} + a+{m+2} + ... + a_n$$

  we call k the index of the summation, m the lower limit of the summation, and n the upper limit of the summation.

- Product Notaion

  if m and n are integers and $m\leq n$, the symbol $\prod\limits_{k=m}^n a_k$(注释: 此处latex limits不起作用), read the product from k equals m to n of a-sub-k, is the product if all terms $a_m, a_{m+1, a_{m+2}, ... , a_n}$, we write:

  $$\prod\limits_{k=m}^n a_k = a_m.a_{m+1}.a_{m+2}...a_n $$

- Properties of Summations and Products

  if $a_m, a_{m+1}, a_{m+2}, ...$ and $b_m, b_{m+1}, b_{m+2}, ...$ are sequemces of real numbers and c is any real number, then the following equations hold for any integer $n\geq m$:

  1. $\sum\limits_{k=m}^n a_k + \sum\limits_{k=m}^n b^k = \sum\limits_{k=m}^n (a_k+b_k)$
  2. $c.\sum\limits_{k=m}^n a_k = \sum\limits_{k=m}^n c.a_k$
  3. $\left( \prod\limits_{k=m}^n a_k \right) .\left(\prod\limits_{k=m}^n b_k\right) = \prod\limits_{k=m}^n (a_k.b_k)$

- Factorial and "n choose r" Notation

  for each positive integer n , the quantity a factorial denoted $n!$, is defined to be the product of all the integers fro 1 to n:

  $$n! = a.(n-1)...3.2.1$$

  Zero factorial, denoted 0!, is defined to be 1:

  $$0! = 1$$

  Let n and r be integers with $0\leq r \leq n$. the symbol

  $${n \choose r}$$

  is read "n choose r" and represents the number of subsets of size r that can be chosen from a set with n elements.

  fro all integers n and r with $0\leq r \leq n$

  $${n \choose r} = \frac{n!}{r!(n-r)!} $$

- Sequence in computer programming

  计算机里用到的最多的是一位数组one-dimensional array

- Application: Algorithm to Convert from Base 10 to Base 2 Using Repeated Division by 2
  $$
  38 = 19.2 + 0 \\
  19 = 9.2 + 1 \\
  9 = 4.2 + 1 \\
  4 = 2.2 + 0 \\
  2 = 1.2 + 0 \\
  1 = 0.2 + 1
  $$
  
  $$
  38 = 19·2+0 \\
  = (9·2+1)·2+0 \\
  = 9·2^2 +1·2+0 \\
  = (4·2+1)·2^2 +1·2+0 \\
  = 4·2^3 +1·2^2 +1·2+0 \\
  = (2·2+0)·2^3 +1·2^2 +1·2+0 \\
  = 2·2^4 +0·2^3 +1·2^2 +1·2+0 \\
  = (1·2+0)·2^4 +0·2^3 +1·2^2 +1·2+0 \\
  = 1·2^5 +0·2^4 +0·2^3 +1·2^2 +1·2+0.
  $$

​	$$a_{10} = (r[k]r[k-1]...r[2]r[1])_2$$

```
Algorithm Decimal to Binary Conversion Using Repeated Division by 2
Input: n[a nonnegtive integer]
Algorithm Body:
	q = n, i = 0
  q一直除以2知道q变成0, 存储remainder余数到一个一维数组
  while(i = 0 or q != 0)
  	r[i] = q mod 2
  	q = q div 2
  	i = i + 1
  end while 
Ouptput: r[0], r[1], ..., r[i-1]
```

<a id="markdown-55-application-correctness-of-algorithms" name="55-application-correctness-of-algorithms"></a>
#### 5.5 Application: Correctness of Algorithms

In this section we given an overview of the general format of correctness proofs and the details of one crucial technique, the *loop invariant procedure*

- Assertions

  Often the predicate describing the initial state is called **pre-condition for the algorithm**, and the predicate describing the final state is called the **post-condition for the algorithm**

  Example:

  Algorithm to compute a product if nonnegtive integers

  *Pre-condition*: The input variables *m* and *n* are nonnegative integers

  *Post-condition*: The output variable *p* equals m.n

- Loop invariants

  非常严谨的证明loop的方法, 无法描述, 看书吧

<a id="markdown-59-general-recursive-definitions-and-structural-induction" name="59-general-recursive-definitions-and-structural-induction"></a>
#### 5.9 General Recursive Definitions and Structural Induction

- Recursively Defined Sets

  定义方法是:

  1. BASE: A statement that certain objects belong to the set
  2. RECURSION: A collection of rules indicating how to form new set objects from those already known to be the set
  3. RESTRICTION: A statement that no objects belong to the set other than those coming from 1 and 2

-  Proving Properties about Recursively Defined Sets

  structural induction可证明

- Recursive Functions