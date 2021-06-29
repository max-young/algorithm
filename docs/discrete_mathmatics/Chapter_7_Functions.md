<!-- TOC -->

- [7.1 Function Defined on General Sets](#71-function-defined-on-general-sets)
  - [定义](#定义)
  - [Examples of Functions](#examples-of-functions)
  - [函数相等](#函数相等)
  - [布尔函数Boolean Function](#布尔函数boolean-function)
- [7.2 Ont-to-One and Onto, Inverse Functions](#72-ont-to-one-and-onto-inverse-functions)
  - [One-to-One Functions一对一函数](#one-to-one-functions一对一函数)
  - [Application: Hash Functions](#application-hash-functions)
  - [Onto Functions](#onto-functions)
  - [Inverse Functions](#inverse-functions)
  - [Relations between Exponential and Logarithmic Functions](#relations-between-exponential-and-logarithmic-functions)
- [7.4 Cardinality with Applications to Computability](#74-cardinality-with-applications-to-computability)

<!-- /TOC -->

Functions函数

<a id="markdown-71-function-defined-on-general-sets" name="71-function-defined-on-general-sets"></a>
### 7.1 Function Defined on General Sets

#### 定义

   一个函数$f$表示一个集合$X$到集合$Y$的关系, 表示为: $f:X \to Y$ , 必须满足$X$中的每一个元素都与$Y$中的某一个元素有关系. 

#### Examples of Functions

- Definition Logarithms and Logarithmic Function
  
  b是一个不等于1的正实数, 对于一个正实数x, the **logarithm with base b of x**, 写作$log_b x$, 它表示b能够得到x的指数(exponent):
  $$log_b x = y \Leftrightarrow b^y = x$$
  the **logarithmic function with base b** 是$R^+$到$R$的函数, 具体是指实数$x$到$log_b x$ 

#### 函数相等

  如果两个函数$F:X \to Y$和$G: X \to Y$, 如果$F = G$, 则所有$x \in X$都满足$F(x) = G(x)$

#### 布尔函数Boolean Function

  有意思, 但是不清楚可以用在什么地方

<a id="markdown-72-ont-to-one-and-onto-inverse-functions" name="72-ont-to-one-and-onto-inverse-functions"></a>
### 7.2 Ont-to-One and Onto, Inverse Functions

#### One-to-One Functions一对一函数

  $F$是一个表示集合$X$到集合$Y$的函数, 如果说$F$是一个Ont-to-One函数, 那么它必须满足条件:

  如果$F(x_{1}) = F(x_{2})$, 那么$x_{1} = x_{2}$

  或者说如果$x_{1} \neq x_{2}$, 那么$F(x_{1}) \neq F(x_{2})$

  用符号可以表示为:

  $$F: X \to Y\ is\ one-to-one\ \iff \forall x_{1}, x_{2} \in X, if\ F(x_{1}) = F(x_{2})\ then\ x_{1} = x_{2}$$

#### Application: Hash Functions

#### Onto Functions

  $F$是一个表示集合$X$到集合$Y$的函数, 如果说$F$是一个onto函数, 那么集合$Y$中的所有元素, 都能在$X$中找到一个元素$x$满足$F(x) = y$

  用符号可以表示为:

  $$F: X \to Y\ is\ onto \iff \forall y \in\ Y, \exists x\ in\ X\ such\ that\ F(x) = y$$ 

#### Inverse Functions

  $F(x) = y$反过来怎么表示呢? $F^{-1}(y) = x$

#### Relations between Exponential and Logarithmic Functions

对于一个不等于1的正数b, the **exponential function with base b**, 表示为$exp_b$  
它是一个$R$到$R^+$的函数: 对于所有real number实数x:
$$exp_b(x) = b^x$$
$b^0 = 1$, $b^{-x} = 1/b^x$  
注: $R$代表实数, $R^+$代表正实数

<a id="markdown-74-cardinality-with-applications-to-computability" name="74-cardinality-with-applications-to-computability"></a>
### 7.4 Cardinality with Applications to Computability

*cardinal number* 表示一个集合set的大小("This set has *eight* elements"), *ordinal number*表示集合的元素顺序("This is the *right* element in the row")

Let *A* and *B* be any sets. **A** **has the same cardinality as** **B** if, and only if, there is a one-to-one correspondence from *A* to *B*. In other words, *A* has the same cardinality as *B* if, and only if, there is a function *f* from *A* to *B* that is one-to-one and onto.

后面的内容很理论, 看不懂, 略过