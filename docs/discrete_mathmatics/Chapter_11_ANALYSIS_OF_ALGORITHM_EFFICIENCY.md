<!-- TOC -->

- [_11.1 Real-Valued Functions of a Real Variable and Their Graphs](#_111-real-valued-functions-of-a-real-variable-and-their-graphs)
- [_11.2 Omicron Omega Theta Notations](#_112-omicron-omega-theta-notations)
  - [Definition](#definition)
  - [Orders of Power Functions](#orders-of-power-functions)
  - [Orders of Polynomial Functions多项式](#orders-of-polynomial-functions多项式)
  - [Orders for Functions of Integer Variables](#orders-for-functions-of-integer-variables)
  - [Extension to Functions Composed of Rational Power Functions](#extension-to-functions-composed-of-rational-power-functions)
- [_11.3 Application: Analysis of Algorithm Efficiency](#_113-application-analysis-of-algorithm-efficiency)
  - [The Sequential Search Algorithm 顺序查找算法](#the-sequential-search-algorithm-顺序查找算法)
  - [The Insertion Sort Algorithm 插入排序算法](#the-insertion-sort-algorithm-插入排序算法)
  - [Time Efficiency of an Algorithm 算法的时间效率](#time-efficiency-of-an-algorithm-算法的时间效率)
- [_11.4 Exponential and Logarithmic Functions: Graphs and Orders](#_114-exponential-and-logarithmic-functions-graphs-and-orders)
  - [Graphs of Exponential Functions](#graphs-of-exponential-functions)
  - [Graphs of Logarithmic Functions](#graphs-of-logarithmic-functions)
- [_11.5 Application: Alalysis of Algorithm Efficiency 2](#_115-application-alalysis-of-algorithm-efficiency-2)
  - [Binary Search](#binary-search)
  - [The Efficiency of the Binary Search Algorithm](#the-efficiency-of-the-binary-search-algorithm)
  - [Merge Sort](#merge-sort)

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

<a id="markdown-definition" name="definition"></a>
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
<a id="markdown-orders-of-power-functions" name="orders-of-power-functions"></a>
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

<a id="markdown-orders-of-polynomial-functions多项式" name="orders-of-polynomial-functions多项式"></a>
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
  $$a_nx^n + a_{n-1}x^{n-1} + ... + a_1x + a_0\ is\ not\ \Omicron(x^m)\ if\ m < n$$
  $$a_nx^n + a_{n-1}x^{n-1} + ... + a_1x + a_0\ is\ not\ \Theta(x^m)\ if\ m < n$$
  

<a id="markdown-orders-for-functions-of-integer-variables" name="orders-for-functions-of-integer-variables"></a>
#### Orders for Functions of Integer Variables

还是举例子说明

- Example 1

$$1 + 2 + 3 + ... + n\ is\ \Theta(n^2)$$
很好证明: 
$$1 + 2 + 3 + ... + n = \frac{n(n+1)}{2} = \frac{1}{2}n^2 + \frac{1}{2}n$$
$$\frac{1}{2}n^2 + \frac{1}{2}n\ is\ \Theta(n^2)$$
$$1 + 2 + 3 + ... + n\ is\ \Theta(n^2)$$

<a id="extension-to-functions-composed-of-rational-power-functions" name="extension-to-functions-composed-of-rational-power-functions"></a>
<a id="markdown-extension-to-functions-composed-of-rational-power-functions" name="extension-to-functions-composed-of-rational-power-functions"></a>
#### Extension to Functions Composed of Rational Power Functions

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

<a id="markdown-the-sequential-search-algorithm-顺序查找算法" name="the-sequential-search-algorithm-顺序查找算法"></a>
#### The Sequential Search Algorithm 顺序查找算法

一个array a, $[a_1, a_2, ..., a_n]$从中找到一个指定的数据x, sequential search就是从第一个元素开始依次和x进行比较, 知道匹配为止  
最好的情况best case, 第一个元素就是x, 只需比较一次就可以了, 那么sequential search algorithm是$\Theta(1)$, 也是$\Theta(n^0)$  
最坏的情况worst case, a里面没有x, 那么我们要把a中的所有元素都要比较一遍, 也就是比较n次, 那么sequential search algorithm是$\Theta(n)$

PS: 我想, 为什么是$\Theta$呢? 我觉得, 因为上面说的都是某些特定情况, 特定情况的前后分别是小于和大于的情况, 假如是第5个元素匹配, 那么就是$\Theta(5)$, 没有问题. 虽然对于最好和最坏的情况而言, 没有order of most和order of least, 但是对于特定情况, 我们都记为$\Theta$

<a id="markdown-the-insertion-sort-algorithm-插入排序算法" name="the-insertion-sort-algorithm-插入排序算法"></a>
#### The Insertion Sort Algorithm 插入排序算法

将一组元素按升序排列  
最开始, 用第2个元素和第1个元素比较, 如果小于第1个元素, 则交换, 否则执行下一步  
然后用第3个元素和第2个元素比较, 如果小于, 则交换, 然后再和第1个比较, 否则, 执行下一步  
...  
基本的思想, 是依次将元素放到左边序列里的正确的位置.

算法效率的两个重要维度: 时间和空间. 在不同的情况下侧重点不一样.

<a id="markdown-time-efficiency-of-an-algorithm-算法的时间效率" name="time-efficiency-of-an-algorithm-算法的时间效率"></a>
#### Time Efficiency of an Algorithm 算法的时间效率

如何计算一个算法的效率呢?  
算法的执行时间取决于很多因素, 其中一个因素是输入数据的大小, 另外一个因素是输入数据的特性, 什么意思呢? 第一个好理解, 我们从100个元素里查找, 和从100万个元素里查找, 时间通常是不一样的. 第二点, 如同上面的sequential search algorithm里说到的, 同样的100个元素的输入数据, 有的可能匹配一次就找到了, 有的可能匹配100次都找不到.  

那么我们有没有精确衡量的办法呢?  
粗略的说, 分析一个算法的时间效率, 我们可以在对大小为n的输入的情况下, 计算在最好的情况, 最坏的情况, 平均状态的情况, 执行的基本操作数.
什么是基本操作呢? 不同的算法里不一样, 比如多想是算法里基本操作是加减乘除, 搜索算法里基本操作是比较. 我们把这些操作都称之为基本操作.  
**最好的情况best case, 最坏的情况worst case**这两个次也很关键, 我们来看标准定义:
1. 假如一个算法A的基本操作数只取决于输入数据的大小n, 和输入数据的性质无关, 那么操作数可以表示为$f(n)$, 如果$f(n)$是$\Theta(g(n))$, 那么我们说这个算法A is of order $\Theta(g(n))$
2. 假如A的基本操作数还取决于输入数据的性质, 那么这样就存在best case 和 worst case  
    - 在best case下, 如果操作数$b(n)$ is $\Theta(g(n))$, 那么我们说A is best case order of $\Theta(g(n))$
    - 在worst case下, 如果操作数$w(n)$ is $\Theta(g(n))$, 那么我们说A is worst case order of $\Theta(g(n))$

定义不太好理解? 还是看例子吧.

- **Computing an Order of an Algorithm Segment**  
  计算一个代码片段的order  
  ```
  p := 0, x := 2
  for i := 2 to n
    p := (p + i).x
  next i
  ```
  这里是一个循环, 每一次循环里面会做一次加法和一次乘法, 基本操作数是2, 循环的次数取决与n, 此书是$n-2+1 = n - 1$, 所以执行的操作数是:
  $$2*(n-1)=2n-2$$
  所以我们说这个算法片段是$\Theta(n)$

- **An Order for an Algorithm with Nested Loop**  
  再看复杂一点的情况: nested loop
  ```
  s := 0
  for i := 1 to n
    for j := 1 to i
      s := s + j.(i - j + 1)
    next j
  next i
  ```
  每次循环里面会做2次加法, 1次减法, 1次乘法, 总共4个基本操作  
  我们再计算循环次数, 无法一眼看出来, 我们可以可以从n = 1开始计算, 最后我们发现循环次数等于$1 + 2 + ... + n = \frac{n(n+1)}{2}$  
  循环次数在这里是用compete enumeration穷举法的方法算出来的, 如果再加一层循环, 穷举法就很麻烦了, 甚至无法算出来了, nested loop的循环次数的计算方法参照: [counting-iteration-of-a-loop](./docs/discrete_mathmatics/Chaper_9_COUNTING_AND_PROBABILITY?id=counting-iteration-of-a-loop):   
  循环次数是: $\binom{2 + n - 1}{2} = \binom{n+1}{2} = \frac{(n+1)!}{2!\cdot (n+1-2)!} = \frac{(n+1)!}{2!\cdot (n-1)!} = \frac{(n+1)n}{2}$  
  所以基本操作数是$4\cdot \frac{n(n+1)}{2} = 2n(n+1)$  
  所以我们说这个算法片段是$\Theta(n^2)$

- **When the Number of Iterations Depends on the Floor Function**  
  n是positive integer, 算法片段如下:  

  for i := $\lfloor n/2 \rfloor $to n  
    a := n - i  
  next i

  loop的次数是$n - \lfloor \frac{n}{2} \rfloor + 1$  
  如果n是even偶数, loop的次数就是$n - \frac{n}{2} + 1 = \frac{n + 2}{2}$  
  如果n是odd奇数, loop的次数就是$n - \frac{n-1}{2} + 1 = \frac{n + 3}{2}$  
  不管n是even还是odd, 都是$\Theta(n)$
  
- **The Insertion Sort Algorithm**  
  Insertion Sort算法的伪代码如下:
  ```
  ALGORITHM insertion sort  
  // Input: a array A with n items that can compare
  // Output: a acsent sorted array A
  从第2个元素current_item开始, 往左边依次比较, 如果左边的元素compare_item大于此元素, 则把左边的元素往右挪一位  
  current_item应该在的位置减去1
  for i = 2 to n:
    current_item = A[i]
    move_index = i
    for j = i-1 to 1:
      compare_item = A[j]
      if compare_item > current_item:
        A[j+1] = A[j]
        move_index -= 1
      else:
        break
    A[move_index] = current_item
  ```
  - Worst-Case Order  
  最差的情况就是从第2个元素开始, 左边的元素都比他大, 这样左边的元素都需要比较一遍, 当i = 2时, 比较1次, 当i = 3时, 比较2次...., 所以总的比较次数是:  
  $$1 + 2 + 3 + ... + (n-1) = \frac{n(n+1)}{2} - n = \frac{1}{2}n^2 - \frac{1}{2}n$$
  这个多项式是$\Theta{n^2}$, 所以The insertion sort algorithm是worst case order $\Theta(n^2)$
  - Average-Case Order  
  长度为k的array的比较次数, 应该是前面长度为k-1的子array的比较次数, 加上最后一个元素和前面k-1个元素的比较次数, 可以表示为:  
  $CS_k = CS_{k-1} + C_k$ for all integers $k \ge 2$
  当array的长度是1时, 即$k = 1$时, 比较次数是0, $CS_1 = 0$  
  这个其实就是一个sequence的recursively定义, 回忆一下[第五章](/./docs/discrete_mathmatics/Chapter_5_Sequences_Mathematical_Induction_and_Recursion?id=_56-defining-sequence-recursively)  
  但是$C_k$是不确定的, 我们来看看怎么计算:  
  最后一个元素$i_k$要比较几次呢? 取决于最以后一个元素的大小, 可以排在前面k-1个元素的哪个位置, 排在某个位置的概率是相等的, 都是$\frac{1}{k}$(可能比前面的元素都大)  
  我们把$i_k$最终排在的位置定义为j, 那么比较次数是$k - j$(注:这里定义第一个元素的索引是1)  
  那么根据[expected value](./docs/discrete_mathmatics/Chapter_9_Counting_and_Probability?id=_98-probability-axioms-and-expected-value)的定义, 最后一个元素$i_k$的比较次数等于其最终在前面k-1个的可能位置的概率乘以比较次数之和:
  $$
  \begin{aligned}
  C_k &= \sum_{j = 1}^{k}\frac{1}{k}(k-j) \\
  &=\frac{1}{k}((k - 1) + (k - 2) + ... + 1 + 0) \\
  &=\frac{1}{k}\frac{k(k-1)}{2} \\
  &= \frac{k-1}{2}
  \end{aligned}
  $$
  所以上面的sequence的recursively define就是:  
  $CS_k = CS_{k-1} + \frac{k-1}{2}$ for all integers $k \ge 2$
  当array的长度是1时, 即$k = 1$时, 比较次数是0, $CS_1 = 0$  
  我们用[iteration](./docs/discrete_mathmatics/Chapter_5_Sequences_Mathematical_Induction_and_Recursion?id=_57-solving-recurrence-relations-by-iteration)来求解这个问题:
  $$
  \begin{aligned}
  CS_1 &= 0 \\
  CS_2 &= 0 + \frac{1}{2} \\
  CS_3 &= 0 + \frac{1}{2} + \frac{2}{2} \\
  CS_4 &= 0 + \frac{1}{2} + \frac{2}{2} + \frac{3}{2} \\
  CS_5 &= 0 + \frac{1}{2} + \frac{2}{2} + \frac{3}{2} + \frac{4}{2} \\
  ... \\
  CS_k &= \frac{1}{2}(1 + 2 + 3 + ... (k - 1)) \\
  &= \frac{1}{2} \cdot \frac{k(k-1)}{2} \\
  &= \frac{k^2 - k}{4} \\
  \end{aligned}
  $$
  这个多项式是$\Theta{n^2}$, 所以The insertion sort algorithm是average case order $\Theta(n^2)$

<a id="markdown-_114-exponential-and-logarithmic-functions-graphs-and-orders" name="_114-exponential-and-logarithmic-functions-graphs-and-orders"></a>
### _11.4 Exponential and Logarithmic Functions: Graphs and Orders

Exponential and Logarithmic Functions在数学和计算机科学中扮演很重要的角色  
比如在计算算法里表示执行次数, 有的算法的执行次数是输入数据大小的Exponential指数函数, 表示这个算法的效率很低  
有的算法的执行次数是输入数据大小的Logarithmic对数函数, 表示这个算法的效率相对不错

#### Graphs of Exponential Functions

在7.2章节里有[Exponential Function](./docs/discrete_mathmatics/Chapter_7_Functions?id=relations-between-exponential-and-logarithmic-functions)的定义  
我们在笛卡尔坐标系下画出指数函数的曲线, 在b>1的情况下, 曲线的增长是非常惊人的  

#### Graphs of Logarithmic Functions

在7.1章节里有[Logarithm Function](./docs/discrete_mathmatics/Chapter_7_Functions?id=examples-of-functions)的定义

如果logarithm function的base b > 1, 在笛卡尔坐标系下函数的曲线是递增的, 那么对于两个正数$x_1$和$x_2$:
$$if x_1 \lt x_2,\ then\ log_b (x_1) \lt log_b (x_2)$$

Logarithm的特性:  
- 如果$2^k \le x \lt 2^{k+1}$, 那么$\lfloor log_2 x \rfloor = k$  

  证明一下:
  $2^k \le x \lt 2^{k+1}$  
  因为上面的特性, 对数的曲线是递增的, 所以:  
  $log_2 (2^k) \le log_2 x \lt log_2 (2^{k+1})$  
  $k \le log_2 x \lt k+1$  
  所以: $\lfloor log_2 x \rfloor = k$  

- 对于大于1的奇数n, $\lfloor log_2 (n-1) \rfloor = \lfloor log_2 n \rfloor$

  假设$\lfloor log_2 n \rfloor = k$, 那么:  
  $2^k \le n \lt 2^{k+1}$, 因为$n$是奇数, $2^k$是偶数, 那么:  
  $2^k \lt n \lt 2^{k+1}$  
  $2^k \le n-1 \lt 2^{k+1}$  
  所以$\lfloor log_2 (n-1) \rfloor = k$  
  所以$\lfloor log_2 (n-1) \rfloor = \lfloor log_2 n \rfloor$


<a id="markdown-_115-application-alalysis-of-algorithm-efficiency-2" name="_115-application-alalysis-of-algorithm-efficiency-2"></a>
### _11.5 Application: Alalysis of Algorithm Efficiency 2

**divide and conquer分而治之**  

采用此策略, 我们可以得出binary search算法, 来和11.3的sequential search算法做比较  
以及merge sort算法和11.3的insert sort算法做比较  
看效率是否提高

#### Binary Search

假设一个array a是有序的, 从小到大排列, 我们要确定一个数字x在a中的位置index  
我们定义bot_index是1, top_index是len(a) = n, 我们找到中间的元素mid_index来和x做比较  
mid_index应该是(bot_index + top_index) / 2, 如果bot_index + top_index是奇数, 我们取floor值  
如果mid_index的值等于x, 那么就结束了, 找到了位置  
如果x小于中间的元素, 那么x就在左半区, 我们把top_index变成mid_index - 1  
如果x大于中间的元素, 那么x就在右半区, 我们把bot_index变成mid_index + 1  
这样一直执行下去, 直到找到为止...  
等等, 如果x不在a里面, 我们一直这样切分下去, 最后会得到bot_index > top_index, 当达到这种情况时, 说明我们已经找遍了所有元素, 应该中止执行  

写一下伪代码Proseudo
```
ALGORITHM binary search
// Input: an array a that ascending order, a item x
// Output: the index that x in a, if x not in a, return 0
// 备注: 在本书的算法里, array的index都是从1开始
int bot_index = 1
int top_index = len(a)
while bot_index <= top_index
  mid_index = (bot_index + top_index) / 2
  if x == a[mid_index]:
    return mid_index
  if x <  a[mid_index]:
    top_index = mid_index - 1
  else:
    bot_index = mid_index + 1
return 0
```

#### The Efficiency of the Binary Search Algorithm

best case的情况, 就是while执行一次就查到了  
worst case的情况下, 就是x不在a里面, while一直执行下去, 直到bot_index > top_index.  
while执行一次, 就是把a去掉一半, 这样cut掉的次数应该是$log_2 n$, while执行的次数应该近似于$log_2 n$  
那么执行的次数应该是多少呢?  
假设n是1, bot_index = mid_index = top_index = 1, 只执行1次  
假设n是2, cut一次, bot_index = mix_index = 1, top_index = 2, worst case下, 下一次执行应该是bot_index += 1, 这样bot_index = top_index = 2, 再执行一次, 等于2  
假设n是3, cut一次之后, 左边和右边两段都是1, 所以的次数是n=1的情况+1, 执行次数是2  
假设n是4, cut一次之后, 左边长度是1, 右边长度是2, worst
case下, 应在选右边继续执行, 所以次数是n=2的情况+1, 执行次数是3  
假设n是5, cut一次之后, 左边长度是2, 右边长度也是2, 所以次数是n=2的情况+1, 执行次数是3  
假设n是6, cut一次之后, 左边长度是2, 右边长度是3, 所以此时是n=3的情况+1, 执行此时是3  
假设n是7, cut一次之后, 左边长度是3, 右边长度是3, 所以此时是n=3的情况+1, 执行此时是3  
假设n是8, cut一次之后, 左边长度是3, 右边长度是4, 所以此时是n=4的情况+1, 执行此时是4  
假设n是9, cut一次之后, 左边长度是4, 右边长度是4, 所以此时是n=4的情况+1, 执行此时是4  
...  
在上面的推导里, 需要注意到, 如果长度是偶数, 做切分时, 两边长度是不等的, 在worst case下, 要取长的那一段, 下面做详细表述  

我们把对一个长度为n的array做binary search, while执行的此时记为$w_n$  
如果我们对array a切分一次, 分成两半  
假如长度是偶数, 那么左边的长度是n/2 - 1, 右边的长度是n/2  
我们取worst case的情况, 取右边, 这样:  
$$w_n = w_{n/2} + 1$$
如果长度是奇数, 那么左边和右边的长度都是$(n+1)/2 - 1 = (n-1)/2 = \lfloor n/2 \rfloor $, 从而:
$$w_n = w_{(n-1)/2} + 1 = w_{\lfloor n/2 \rfloor} + 1$$
实际上, 偶数的情况下:
$$w_n = w_{n/2} + 1 = w_{\lfloor n/2 \rfloor} + 1$$

我们根据上面的推导, 好像能发现一个规律, while执行的次数好像满足这样的规律:  
$$if\ 2^i \le n \lt 2^{i+1}\ then\ w_n = i + 1$$
也就是说:
$$w_n = \lfloor log_2 n \rfloor + 1$$
我们试着证明一下, 采用数学归纳法:  
当n = 1时, i = 0, $w_2 = 0 + 1 = 1$
下面我们来证明:  
当k>=1时, 如果$w_i = \lfloor log_2 i \rfloor + 1$, for 1 <= i <= k, 那么$w_{k+1} = \lfloor log_s (k+1) \rfloor + 1$  
当k为奇数时:  
$$
\begin{aligned}
w_{k+1} &= w_{\lfloor (k + 1)/2 \rfloor} + 1 \\
&= \lfloor log_2 (k+1)/2 \rfloor + 1 + 1\ 因为(k+1)/2<=k\\
&= \lfloor log_2 (k+1) - log_2 2 \rfloor + 2 \\
&= \lfloor log_2 (k+1) \rfloor + 1
\end{aligned}
$$
当k为偶数时:  
$$
\begin{aligned}
w_{k+1} &= w_{\lfloor (k + 1)/2 \rfloor} + 1 \\
&= w_{\lfloor k/2 \rfloor} + 1 因为k是偶数\\
&= \lfloor log_2 k/2 \rfloor + 1 + 1\ 因为k/2<k\\
&= \lfloor log_2 k - log_2 2 \rfloor + 2 \\
&= \lfloor log_2 k - 1 \rfloor + 2 \\
&= \lfloor log_2 k \rfloor + 1 \\
&= \lfloor log_2 (k + 1) \rfloor + 1\ 看11.4章节对数的特性\\
\end{aligned}
$$

所以Binary Search Algorithm是worst case order $\Omega(log_2n)$  

#### Merge Sort
