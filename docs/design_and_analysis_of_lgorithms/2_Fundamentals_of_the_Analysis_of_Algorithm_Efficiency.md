<!-- TOC -->

- [_2.1 The Analysis Framework](#_21-the-analysis-framework)
  - [Measuring an Input's Size](#measuring-an-inputs-size)
  - [Units for Measuring Running Time](#units-for-measuring-running-time)
  - [Orders of Growth](#orders-of-growth)
  - [Worst-Case, Best-Case, and Average-Case Efficiency](#worst-case-best-case-and-average-case-efficiency)
  - [Recapitulation of the Analysis Framework](#recapitulation-of-the-analysis-framework)
  - [Excercises](#excercises)
- [_2.2 Asymptopic Notations and Basic Efficiency Classes渐进标记和基本效率类型](#_22-asymptopic-notations-and-basic-efficiency-classes渐进标记和基本效率类型)
  - [Informal Introduction概念介绍](#informal-introduction概念介绍)
  - [Useful Property Involving the Asymptotic Notations一些有用的特性](#useful-property-involving-the-asymptotic-notations一些有用的特性)
- [_2.3 Mathematical Analysis of Nonrecursive Algorithms](#_23-mathematical-analysis-of-nonrecursive-algorithms)
- [_2.4 Mathematical Analysis of Recursive Algorithms](#_24-mathematical-analysis-of-recursive-algorithms)
- [_2.5 Example: Computing the nth Fibonacci Number](#_25-example-computing-the-nth-fibonacci-number)
- [_2.6 Empirical Analysis of Algorithms](#_26-empirical-analysis-of-algorithms)
- [_2.7 Algorithm Visualization](#_27-algorithm-visualization)

<!-- /TOC -->

如何分析算法的效率: 时间和空间  
2.1章节介绍了分析框架, 这一章节的内容可以说构成了整本书的最重要的内容  
2.2章节介绍了算法效率的表示方法和符号, 比如$\Omicron$, $\Omega$, $\Theta$
2.3章节介绍了非递归算法的分析  
2.4章节介绍了递归算法的分析  
2.5章节以Fibonacci算法为例说明了算法分析的方法  
2.3和2.4章节介绍的分析方法非常有用, 但是不够简单明了, 2.6和2.7章节通过实证分析和可视化作为算法分析的重要补充

<a id="markdown-_21-the-analysis-framework" name="_21-the-analysis-framework"></a>
## _2.1 The Analysis Framework

对算法分析有两个重要指标: time efficiency, 也称为time complexity, 另外一个是space efficiency, 也称为space complexity  
随着计算机的发展, 内存空间在很多情况下已足够使用, 所以我们一般把time efficiency作为算法的重要分析指标  

### Measuring an Input's Size

算法的时间效率通常和输入Input的大小size相关

### Units for Measuring Running Time

我们通过Input Size能够计算出算法的基本操作数(basic operation), 以basic operation的数量来衡量算法的time efficiency

$$T(n)\approx c_opC(n)$$

$T(n)$表示这个算法的总计算时间, $c_op$表示在某台计算机里一个basic operation的执行时间, $C(n)$表示在input size是n的情况下basic operation的数量  
为什么是约等于呢? 因为算法的执行时间除了基本操作, 还会有其他开销. 但是basic operation是主要的耗时.  
另外, 不用的硬件里$c_op$是不一样的, 所以我们用basic operation的数量$C(n)$来衡量time efficiency

举一个例子:

$$C(n) = \frac{1}{2}n(n-1) = frac{1}{2}n^2 - frac{1}{2}n \ approx frac{1}{2}n^2$$

我们看上面这个等式, 我们发现我们分析一个算法的time efficiency, 一步一步省略, 省略单个脚本操作的时间, 省略多项式的低阶部分, 等等, 最后我们把焦点放在多项式的最高阶的部分, 我们称之为order of growth, 因为input size足够大的情况下, 最高阶指数和低阶指数、对数相比, 要大得多得多.

### Orders of Growth

书中有一个图表, 拿$log_2 n$, $n$, $nlog_2 n$, $n^2$, $n^3$, $2^n$, $n!$  
随着n不断增长, 差别越来越大, 但是$2^n$, $n!$的增长速度简直疯狂, 疯狂到算法不可用  
所以我们要用算法解决某个问题的时候, 需要让算法的基本操作数控制在input size的指数级, 才是可用的

### Worst-Case, Best-Case, and Average-Case Efficiency

对于顺序查找法sequential search, 假设input size是n  
那么best-case情况下, 查找第一个元素是就匹配上了, 基本操作数是1  
在worst-case情况下, 我们要查找的元素不在input里面, 或者是在最后, 那么基本操作数是n  
average-case是怎样的呢? best0-case和worst-case两者相加除以2吗? 并没有那么简单:

假设搜索的成功率是$p$, 也就是能匹配到的成功率.  
在第i个元素匹配到的几率就是$\frac{p}{n}$, 因为对于input中的每个元素, 匹配的几率都是一样的, 都是$\frac{1}{n}$, 所以, 我们可以得到:
$$C_{avg} (n) = \left[1\cdot\frac{p}{n} + 2\cdot \frac{p}{n} + ... + i\cdot\frac{p}{n} + ... + n\cdot\frac{p}{n}\right] + n\cdot (1-p)$$
最后需要加上$n\cdot (1-p)$, 匹配不到的情况下, 基本操作数是n. 这个等式参照这个定理: [expected vaslue](./docs/discrete_mathmatics/chapter9_counting_and_probability?id=expected-value)  
假设$p = 1$, 也就是一定能够找到, 那么上面的式子等于$(n+1)/2$, 刚好等于best case和worst case相加除以2, 但是我们不能这么算.

从上面的例子我们可以看出, best case不足以表现这个算法的time efficiency, average case计算又太复杂, worst case可以作为衡量算法time efficiency的指标  
但是best case和average case也是有作用的  
比如一个算法在best case的情况下都效率不高, 这个算法就可以舍弃了, 不用再去考虑best case的情况.  
average case也是有用的, 有些算法在worst case情况下过去悲观, 但是这个算法在average case情况下效率还不错. 所以如果我们舍弃average case, 可能会错失很多重要的算法.

番外: amortized efficiency(平摊算法), section9.2有讲解

### Recapitulation of the Analysis Framework

- 算法分析需要衡量time和space
- time efficiency通过basic operation的数量来衡量, space efficiency通过内存单元数量来衡量
- 一个算法在某个input size情况下, 在best case, worst case, average case下效率不一样
- 算法效率主要关注的是在input size n情况下, 关于n的order of growth

### Excercises

1. excercise 1  
  a. computing the sum if n numbers  
    input size n  
    basic operation count n - 1  
    三种case的basic operation count都是一样的  
  b. computing n!  
    input size n  
    basic operation count n - 1  
    三种case的basic operation count都是一样的  
  c. Euclid's algorithm # TODO  
  d. sieve of Eratosthenes # TODO   
  e. pen-and-pencil algorithms for multiplying two n-digit decimal integers # TODO  
2. excercise 2

先刷完课文, 习题之后做

<a id="markdown-_22-asymptopic-notations-and-basic-efficiency-classes" name="_22-asymptopic-notations-and-basic-efficiency-classes"></a>
## _2.2 Asymptopic Notations and Basic Efficiency Classes渐进标记和基本效率类型

### Informal Introduction概念介绍

$g(n)$是一个关于input size的表达式
$t(n)$代表算法的效率, 一般是指basic operation的数量

$O$表示lower of order, 也就是说算法的效率曲线(basic operation)是低于g(n)曲线的
$$t(n) \le cg(n)\ for\ all\ n \ge n_0$$
例如: $100n + 5 \in O(n^2)$

$\Omega$则是高于$g(n)$曲线的  
$$t(n) \ge cg(n)\ for\ all\ n \ge n_0$$
例如: $n^3 \in \Omega(n^2)$

$\Theta$则表示在某个参数$c_1$情况下, 效率曲线低于$c_1g(n)$, 在某个参数$c_2$下, 效率曲线高于$c_2g(n)$:
$$c_2g(n) \le t(n) \le c_1g(n)\ for\ all\ n \ge n+0$$
例如: $\frac{1}{2}n(n-1) \in \Theta(n^2)$  
因为$\frac{1}{2}n(n-1) \le \frac{1}{2}n^2$, $\frac{1}{2}n(n-1) \ge \frac{1}{4}n^2$  

### Useful Property Involving the Asymptotic Notations一些有用的特性


<a id="markdown-_23-mathematical-analysis-of-nonrecursive-algorithms" name="_23-mathematical-analysis-of-nonrecursive-algorithms"></a>
## _2.3 Mathematical Analysis of Nonrecursive Algorithms

<a id="markdown-_24-mathematical-analysis-of-recursive-algorithms" name="_24-mathematical-analysis-of-recursive-algorithms"></a>
## _2.4 Mathematical Analysis of Recursive Algorithms

<a id="markdown-_25-example-computing-the-nth-fibonacci-number" name="_25-example-computing-the-nth-fibonacci-number"></a>
## _2.5 Example: Computing the nth Fibonacci Number

<a id="markdown-_26-empirical-analysis-of-algorithms" name="_26-empirical-analysis-of-algorithms"></a>
## _2.6 Empirical Analysis of Algorithms

<a id="markdown-_27-algorithm-visualization" name="_27-algorithm-visualization"></a>
## _2.7 Algorithm Visualization