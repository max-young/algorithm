<!-- TOC -->

- [_1.1 Variables](#_11-variables)
- [_1.2 The Language of Sets](#_12-the-language-of-sets)
- [_1.3 The language of Relations and Functions](#_13-the-language-of-relations-and-functions)
  - [Relations](#relations)
  - [Functions](#functions)

<!-- /TOC -->

Chapter 1 Speaking Mathematically

<a id="markdown-11-variables" name="11-variables"></a>
<a id="markdown-_11-variables" name="_11-variables"></a>
### _1.1 Variables

**Variable变量**可以作为一个占位符, 在下面两种情况下用到:

1. 有想象有一个或多个值, 但是是未知的
2. 又一个集合里面的值满足某个特性, 但是你不想用集合里的某一个特定的值来表达

**Statement声明**

A **universal statement** asserts that a certain property is true for all elements in a set.

A **conditional statement** asserts that if one thing is true then some other thing alse has to be true.

Given a property that may or may not be true, an **existential statement** assert that there is at least one thing for which the property is true.

<a id="markdown-12-the-language-of-sets" name="12-the-language-of-sets"></a>
<a id="markdown-_12-the-language-of-sets" name="_12-the-language-of-sets"></a>
### _1.2 The Language of Sets

The **axiom of extension** says that a set is completely determined by what its elements are—not the order in which they might be listed or the fact that some elements might be listed more than once.

集合set又里面的元素来定义, 与元素的顺序和元素出现的顺序无关.

set刻意由大括号$\{...\}$来表示. 有一些约定俗成的符号来表示特定的集合, 比如R表示所有real number, Z表示所有整数, Q表示所有有理数rational numbers.

如果我们用直线来表示R的话, 中间是0, 两边是正负real number, 这条直线是连续的continuous.

Z不是连续的, 因为各个整数之间是有距离的, 我们称之为discrete. Discrete Mathematics就是来源于continuous和discrete的数学对象的区别.

另外一种set的表示方法是**Set-Builder Notation**, ${x\in S|P(x)}$, We may define a new set to be **the set of all elements** **x** **in** **S** **such that** **P(x)** **is true**. 

- Subsets

  $A\subseteq B$ Means that For all elements x, if $x\in A$ then $x\in B$

  $A\nsubseteq B$ means that there is at least one element x such that $x\in A$ and  $x\notin B$

- ordered pair

  $(a, b)$是ordered pair, 元素是有序的

  $(a, b)=(c, d)$ means that $a = c$ and $b = d$

- Cartesian product笛卡尔积

  set of all ordered pairs $(a, b)$, where a is in A and b is in B.

  $A\times B = {(a, b)|a\in A\ and\ b\in B}$

  有趣的一点是: $R\times R$表示笛卡尔平面(Cartesian plane)

<a id="markdown-13-the-language-of-relations-and-functions" name="13-the-language-of-relations-and-functions"></a>
<a id="markdown-_13-the-language-of-relations-and-functions" name="_13-the-language-of-relations-and-functions"></a>
### _1.3 The language of Relations and Functions

#### Relations

  Let *A* and *B* be sets. A **relation** **R** **from** **A** **to** **B** is a subset of *A* × *B*. Given an ordered pair (*x*, *y*) in *A*×*B*, **x** **is related to** **y** **by** **R**, written *x R y*, if, and only if, (*x*, *y*) is in *R*. The set *A* is called the domain of *R* and the set *B* is called its co-domain.

  $(x, y)$是A和B两个集合的笛卡尔积的元素, 且$(x, y)$满足定义的关系, 那么我们说$x\ R\ \ y$

​		举两个例子:

​		Let$ A = \{1,2\}$ and $B = \{1,2,3\}$ and define a relation *R* from *A* to *B* as follows: Given any $(x,  y) \in A \times  B$

​						$$(x, y) \in R\ means\ that\ \frac{x - y}{2}\ is\ an\ integer$$.

​   再举一个Circle Relation的例子, 我们可以用Relation表示一个圆, 很神奇

​		Define a relation C from R to R as follows: For any$(x, y)\in R\times R$,

​						$$(x, y)\in C\ means\ that\ x^2 + y^2 = 1$$

#### Functions

  a **function** **F** **from a set** **A** **to a set** **B** is a relation with domain $A$ and co-domain $B$  
  that satisfies the following two properties:
  1. For every element x in $A$, there is an element y in $B$ such that$(x, y)\in F$.
  2. For all elements x in $A$ and y and z in $B$, if $(x, y)\in  F$ and $(x, z)\in F$, then  y = z.

  两个set $A$ and $B$, $F$是一个function from $A$ to $B$, 那么对于任何一个$A$中的元素x, 都有一个B中的元素通过$F(x)$和x关联, 读作"F of x"