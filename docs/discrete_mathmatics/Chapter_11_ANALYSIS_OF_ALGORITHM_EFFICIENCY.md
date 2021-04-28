<!-- TOC -->

- [_11.1 Real-Valued Functions of a Real Variable and Their Graphs](#_111-real-valued-functions-of-a-real-variable-and-their-graphs)
- [_11.2 Omicron Omega Theta Notations](#_112-omicron-omega-theta-notations)
  - [Definition](#definition)
  - [Orders of Power Functions](#orders-of-power-functions)
  - [Orders of Polynomial Functions多项式](#orders-of-polynomial-functions多项式)
  - [Orders for Functions of Integer Variables](#orders-for-functions-of-integer-variables)
  - [Extension to Functions Composed of Rational Power Functions](#extension-to-functions-composed-of-rational-power-functions)
- [_11.3 Application: Analysis of Algorithm Efficiency](#_113-application-analysis-of-algorithm-efficiency)
- [_11.5 Application: Alalysis of Algorithm Efficiency 2](#_115-application-alalysis-of-algorithm-efficiency-2)

<!-- /TOC -->

Chapter 11 ANALYSIS OF ALGORITHM EFFICIENCY

Rene Descartes笛卡尔的analytic geometry(解析几何)为本章内容: $\Omicron$, $\Omega$, $\Theta$以及它们在算法分析中的应用, 提供了基石  

<a id="markdown-_111-real-valued-functions-of-a-real-variable-and-their-graphs" name="_111-real-valued-functions-of-a-real-variable-and-their-graphs"></a>
### _11.1 Real-Valued Functions of a Real Variable and Their Graphs

**real-valued function of a real variable**是指一个function, 这个function表示一个实数set和另外一个实数set的关联关系.  
如果f代表这个function, f中的每个实数x, 都有唯一一个对应的实数f(x).  
这个对应关系在笛卡尔坐标系里可以构成一个graph, 定义如下:  
Let $f$ be a real-valued function of a real variable. The graph of $f$ is the set of all points (x, y) in the Cartesian coordinate plane with the property that $x$ is in the domain of $f$ and $y= f(x)$.

下面是几种函数类型, 除了常见的power function, 值得注意的是还有一些描述性的函数表达, 不只是通过数学表达式

- Power Functions

  常见的一种函数, 书中的表示是: $p_a(x) = x^a$  
  这样, $p_{1/2}(x) = x^{1/2} = \sqrt{x}$, $p_2(x) = x^2$  
  在笛卡尔坐标系里分别可以画出不同的曲线, 这里不再赘述

- The Floor Function

  For each real number x
  $$
  \begin{aligned}
  f(x) &= \lfloor x \rfloor \\
  &= the\ greatest\ integer\ that\ is\ less\ than\ or\ equal\ to\ x \\
  &= the\ unique\ integer\ n\ such\ that\ n \le x \lt n+1
  \end{aligned}
  $$
  画出来的图形是这样的:  
<img src="./_images/floor_function.png" width=50%>

- Graphing Functions Defined on Sets of Integers

  在上面的Power Functions里面x指的是所有实数, 如果我们指定x是所有正整数呢, 那么图形就会变成下面这样:  
  <img src="./_images/graphing_functions_defined_on_sets_of_integers.png" width=50%>

- Graph of a Multiple of a Function

  这个对理解$\Omicron$有帮助  

  定义是这样的:  
  f是一个实数函数, M也是一个实数, 我们定义Mf, 是multiple of f by M或者M times f(即f乘以M), Mf的domain(参数范围)和f一样:
  $$(Mf)(x) = M\cdot(f(x))\ for\ all\ x \in domain\ of\ f$$

  简单的说: 就是对函数的值乘以一个固定的数, 参数域不变

- Increasing and Decreasing Functions

  举个简单的例子便于理解, 对于绝对值函数, 它的graph是这样的:  
  <img src="./_images/absolute_value_function.png" width=50%>  

  纵坐标左边的线是递减的(decrease), 纵坐标右边的线是递增的(increase)  

  精确的定义是:
  f是一个实数函数, domain of f包括一个字集S  
  我们说f在S里是increasing, 那么: 对于S里的$x_1$, $x_2$, 如果$x_1 \lt x_2$, 那么$f(x_1) \lt f(x_2)$  
  我们说f在S里是decreasing, 那么: 对于S里的$x_1$, $x_2$, 如果$x_1 \lt x_2$, 那么$f(x_1) \gt f(x_2)$  
  我们说f是一个increasing(decreading)函数, 那么f在整个domain里都是increasing(decreasing)

  另外, 很显然, 一个M是正数的Mf, 如果f是increasing function, Mf也是increasing function

<a id="markdown-_112-omicron-omega-theta-notations" name="_112-omicron-omega-theta-notations"></a>
### _11.2 Omicron Omega Theta Notations

#### Definition

同一项工作用不同的算法需要的时间和空间是不一样的, 这三个符号就可以来表示这种差别

这三个符号的发明, 有必要做一下了解:  
The oldest of the notations,O-notation (read “big-Onotation”), was introduced bythe German mathematician Paul Bachmann in 1894 in a book on analytic number the-ory. Both the- (read “big-Omega”) and- (read “big-Theta”) notations were developedby Donald Knuth, one of the pioneers of the science of computer programming.

这三种符号是什么意思呢:  
对于一个函数f, 以及另外一个函数g  
- positive real number M, nonnegative real number k, 使得$|f(x)| \le M|g(x)|$ for all real number $x \gt k$, 那么我们说f is of order at most g, 记作$f(x)$ is $\Omicron (g(x))$, 在笛卡尔坐标系里f(x)的曲线在绝大多数范围内都是在Mg(x)的曲线下面
- positive real number M, nonnegative real number k, 使得$|f(x)| \ge M|g(x)|$ for all real number $x \gt k$, 那么我们说f is of order at least g, 记作$f(x)$ is $\Omega (g(x))$, 在笛卡尔坐标系里f(x)的曲线在绝大多数范围内都是在Mg(x)的曲线上面
- positive real number A B, nonnegative real number k, 使得$A|g(x) \le |f(x)| \le B|g(x)|$ for all real number $x \gt k$, 那么我们说f is of order g, 记作$f(x)$ is $\Theta (g(x))$, 在笛卡尔坐标系里f(x)的曲线在绝大多数范围内都是在Ag(x)和Bg(x)的曲线之间  

下面举几个例子说明:  
$$10|x^6| \le |17x^6-45x^3+2x+8| \le 30|x^6|\ for\ all\ real\ number\ x \gt 2$$
套用上面的定义, 我们说$17x^6-45x^3+2x+8$ is $\Theta(x^6)$

看到这里, 会觉得有点可疑. 我们看上面的等式的前半部分和后半部分, 我们根据定义又可以得出,$17x^6-45x^3+2x+8$ is $\Omega (x^6)$, $17x^6-45x^3+2x+8$ is $\Omicron (x^6)$, 这是这三个notation的特征:  
1. 如果$f(x)\ is\ \Omicron (g(x))$ and $f(x)\ is\ \Omega (g(x))$, 那么必须$f(x)\ is\ \Theta (g(x))$ and  
2. 如果$f(x)\ is\ \Omega (g(x))$, 那么必须$f(x)\ is\ \Omicron (g(x))$
3. 如果$f(x)\ is\ \Omicron (g(x))$, $g(x)\ is\ \Omicron (h(x))$, 那么$f(x)\ is\ \Omicron (h(x))$

下面举例子来说明
####  Orders of Power Functions  
$$
\begin{aligned}
1 &< x \\
x &< x^2 \\
x^2 &< x^3
\end{aligned}
$$
$$1 < x < x^2 < x^3$$
对于$x>1$, $r < s$, 有$x^r < x^s$, 所以$x^r\ is\ \Omicron(r^s)$  
所以$x^2\ is\ \Omicron(x^3)$, $x^2\ is\ \Omicron(x^4)$...  
我们在笛卡尔坐标里面画出这些graph, 也会发现, $x^s$在$x^r$的上面

#### Orders of Polynomial Functions多项式

- Example 1  
对于这样的一个函数$3x^3 + 2x + 7$  
for real number x > 1, $3x^3 + 2x + 7 \le 12x^3$  
为什么? 因为$2x < 2x^3$, $7 < 7x^3$  
所以我们说$3x^3 + 2x + 7$ is $\Omicron(x^3)$  
我们还可以得出$3x^3 + 2x + 7 > 3x^3$  
所以我们说$3x^3 + 2x + 7$ is $\Omega(x^3)$  
从而$3x^3 + 2x + 7$ is $\Theta(x^3)$  
- Example 2  
假如把上面的函数的加号换成减号呢: $3x^3 - 2x - 7$  
根据triangle inequality(三角不等式):  
$$|a+b| \le |a| + |b|$$
所以:
$$|a-b| = |a+(-b)| \le |a| + |-b| = |a| + |b|$$
从而:  
$$3x^3 - 2x - 7 \le 3x^3 + 2x + 7$$
$3x^3 + 2x + 7$ is $\Omicron(x^3)$, 那么$3x^3 - 2x - 7$ is $\Omicron(x^3)$
- Example 3  
$x^2$不是$\Omicron(x)$, 证明如下:  
假设$x^2$是$\Omicron(x)$, 那么存在:  
$|x^2| \le Mx$ for x > m  
假定x大于M也大于m, 它满足:  
$xx > Mx$  
和上面相悖, 所以$x^2$不是$\Omicron(x)$, 进而$x^2$不是$\Theta(x)$

存在下面的定理:  
$$a_nx^n + a_{n-1}x^{n-1 + ... + a_1x + a_0}\ is\ not\ \Omicron(x^m)\ if\ m < n$$
$$a_nx^n + a_{n-1}x^{n-1 + ... + a_1x + a_0}\ is\ not\ \Theta(x^m)\ if\ m < n$$
  
#### Orders for Functions of Integer Variables

还是举例子说明
- Example 1
$$1 + 2 + 3 + ... + n\ is\ \Theta(n^2)$$
很好证明: 
$$1 + 2 + 3 + ... + n = \frac{n(n+1)}{2} = \frac{1}{2}n^2 + \frac{1}{2}n$$
$$\frac{1}{2}n^2 + \frac{1}{2}n\ is\ \Theta(n^2)$$
$$1 + 2 + 3 + ... + n\ is\ \Theta(n^2)$$

####  Extension to Functions Composed of Rational Power Functions

对于两个指数函数相除的情况, 例如:
$$\frac{(x^{3/2}+3)(x-2)^2}{x^{1/2}(2x^{1/2}+1)} = \frac{x^{7/2} - 4x^{5/2} + 4x^{3/2} + 3x^2 - 12x + 12}{2x + x^{1/2}}$$
$$\frac{x^{7/2} - 4x^{5/2} + 4x^{3/2} + 3x^2 - 12x + 12}{2x + x^{1/2}}\ is\ \Omicron(x^c)\ for\ c > 7/2 - 1 = 5/2$$
$$\frac{x^{7/2} - 4x^{5/2} + 4x^{3/2} + 3x^2 - 12x + 12}{2x + x^{1/2}}\ is\ not\ \Omicron(x^c)\ for\ c < 7/2 - 1 = 5/2$$
有下面的定理:  
Let m and n be positive integers, and let $r_0, r_1, r_2, ..., r_n$ and $s_0, s_1, s_2, ..., s_m$ be nonnegative rational numbers with $r_0 < r_1 < r_2 < ··· < r_n$ and $s_0 < s_1 < s_2 < ··· < s_m$. Let $a_0, a_1, a_2, ..., a_n$ and $b_0, b_1, b2, ..., b_m$ be real numbers with $a_n \neq 0$ and $b_m \neq 0$, then:
$$\frac{a_nx^{r_n} + a_{n-1}x^{r_{n-1}} + ... + a_1x^{r_1} + a_0x^{r_0}}{b_mx^{s_m} + b_{m-1}x^{s_{m-1}} + ... + b_1x^{s_1} + b_0x{s_0}}\ is\ \Theta(x^{r_n - s_m})$$
$$\frac{a_nx^{r_n} + a_{n-1}x^{r_{n-1}} + ... + a_1x^{r_1} + a_0x^{r_0}}{b_mx^{s_m} + b_{m-1}x^{s_{m-1}} + ... + b_1x^{s_1} + b_0x{s_0}}\ is\ \Omicron(x^c)\ for\ any\ real\ number\ c > r_n - s_m$$
$$\frac{a_nx^{r_n} + a_{n-1}x^{r_{n-1}} + ... + a_1x^{r_1} + a_0x^{r_0}}{b_mx^{s_m} + b_{m-1}x^{s_{m-1}} + ... + b_1x^{s_1} + b_0x{s_0}}\ is\ not\ \Omicron(x^{r_n - s_m})\ for\ any\ real\ number\ c < r_n = s_m$$

<a id="markdown-_113-application-analysis-of-algorithm-efficiency" name="_113-application-analysis-of-algorithm-efficiency"></a>
### _11.3 Application: Analysis of Algorithm Efficiency 

- The Sequential Search Algorithm 顺序查找算法

  很简单, 从第一个元素开始一次查找

- The Insertion Sort Algorithm 插入排序算法

  将一组数字按升序排列, 最开始, 用第2个元素和第1个元素比较, 如果小于第1个元素, 则交换.

  基本的思想, 是依次将元素放到左边序列里的正确的位置.

- Time Efficiency of an Algorithm 算法的时间效率

  Roughly speaking, the analysis of an algorithm for time efficiency begins by try- ing to count the number of elementary operations that must be performed when the algorithm is executed with an input of size *n* (in the best case, worst case, or average case).

  粗略的说, 分析一个算法的时间效率, 我们可以对大小为n的输入的情况下, 必须执行的操作数来作为开始.

  我们以一个简单的例子来做说明:
  $$
  \begin{aligned}
  &p:=0, x:=2 \\
  &for\ i:=2\ to\ n \\
  &\ \ \ \ p := (p+i).x \\
  &next\ i
  \end{aligned}
  $$
  这里是一个循环, 每一个循环里面会做一次加法和一次乘法, 循环的次数是n-2+1, 所以执行的操作数是:
  
  $$2*(n-2+1)=2n-2$$
  
  $2n-2$可能大于n, 也可能小于n, 所以这个算法的效率可以表示为$\Theta(n)$
  
- **The Insertion Sort Algorithm插入算法详解**

  强烈建议看看此算法, 算法的原理是**挪动位置**

- 插入算法的最差效率

  那就是a[k]前面的数字都小于a[k], 那么

<a id="markdown-_115-application-alalysis-of-algorithm-efficiency-2" name="_115-application-alalysis-of-algorithm-efficiency-2"></a>
### _11.5 Application: Alalysis of Algorithm Efficiency 2

divide and conquer分而治之

采用此策略, 我们可以得出binary search算法, 来和11.3的sequential search算法做比较

已经merge sort算法和11.3的insert sort算法做比较

看效率是否提高

- Binary Search

  看书中的定义, 很清晰, 注意算法定义了3个变量: index = 0, bot = 1, top = n

- Merge Sort

  不太直观, 有点烧脑. 看Python的写法吧.