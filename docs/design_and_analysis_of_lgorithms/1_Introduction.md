<!-- TOC -->

- [_1.1 What Is an Algorithm](#_11-what-is-an-algorithm)
  - [greatest common divisor最大公约数](#greatest-common-divisor最大公约数)
    - [Euclid欧几里得的算法](#euclid欧几里得的算法)
    - [Consecutive integer checking algorithm连续整数检查算法](#consecutive-integer-checking-algorithm连续整数检查算法)
    - [Middle-school procedure中学算法](#middle-school-procedure中学算法)
  - [Excercises](#excercises)
- [_1.2 Fundamentals of Algorithmic Problem Solving](#_12-fundamentals-of-algorithmic-problem-solving)
  - [Understanding the Problem](#understanding-the-problem)
  - [Ascertaining the Capabilities of the Computational Device确定计算设备](#ascertaining-the-capabilities-of-the-computational-device确定计算设备)
  - [Choosing between Exact and Approximate Problem Solving在精确还是近似解决问题之间做选择](#choosing-between-exact-and-approximate-problem-solving在精确还是近似解决问题之间做选择)
  - [Algorithm Design Techniques](#algorithm-design-techniques)
  - [Design an Algorithm and Data Structure](#design-an-algorithm-and-data-structure)
  - [Methods of Specifying an Algorithm详细说明算法的方法](#methods-of-specifying-an-algorithm详细说明算法的方法)
  - [Proving an Algorithm's Correctness](#proving-an-algorithms-correctness)
  - [Analyzing an Algorithm](#analyzing-an-algorithm)
  - [Coding an Algorithm](#coding-an-algorithm)
  - [Excecises](#excecises)
- [_1.3 Important Problem Types](#_13-important-problem-types)
  - [Sorting排序](#sorting排序)
  - [Searching查找](#searching查找)
  - [String processing字符串处理](#string-processing字符串处理)
  - [Graph problems图形问题](#graph-problems图形问题)
  - [Combinatorial problems组合问题](#combinatorial-problems组合问题)
  - [Geometric problems几何问题](#geometric-problems几何问题)
  - [Numerical problems数值问题](#numerical-problems数值问题)
  - [Exercises](#exercises)
- [_1.4 Fundamental Data Structures](#_14-fundamental-data-structures)
  - [Linear Data Structures线性数据结构](#linear-data-structures线性数据结构)
  - [Graphs](#graphs)
  - [Trees](#trees)
  - [Sets and Dictionaries](#sets-and-dictionaries)
  - [Excercises](#excercises-1)
  - [Summary](#summary)

<!-- /TOC -->

学习算法的重要性: 不只是计算机科学的核心, 并且是一种思想, 和其他学科共同的思想, 解决问题的思想

1.1 讲最大公约数的三种算法  
1.2 设计和分析算法的若干要点  
1.3 算法问题类型  
1.4 数据结构的介绍  

<a id="markdown-_11-what-is-an-algorithm" name="_11-what-is-an-algorithm"></a>
## _1.1 What Is an Algorithm

*An algorithm is a sequence of unambiguous instructions for solving a problem, i.e., for obtaining a required output for any legitimate input in a finite amount of time.*

算法是为了解决问题的明确指令的序列. 在有限的时间内, 根据合法的输入, 得到所需的输出.

这里以最大公约数的三种算法来诠释关于算法的以下要点:

1. 算法的每一步必须明确无误
2. 算法的输入范围必须指定
3. 同样的算法可以用多种方法表示
4. 同一个问题可以存在多种算法
5. 同一个问题的多种算法可以基于不同的思想、而且可能速度差别很大

<a id="markdown-greatest-common-divisor最大公约数" name="greatest-common-divisor最大公约数"></a>
### greatest common divisor最大公约数

两个不都为0的正整数m, n, 他们的最大公约数表示为gcd(m, n)

<a id="markdown-euclid欧几里得的算法" name="euclid欧几里得的算法"></a>
#### Euclid欧几里得的算法

  欧几里得的算法基于:  
  gcd(m, n) = gcd(n, m mod n)  
  循环执行, 直到m mod n = 0, 然后gcd(m, 0) = m, 例如:  
  gcd(60, 24) = gcd(24, 12) = gcd(12, 0) = 12  

  对算法结构化的描述是:  
  第一步: 如果n = 0, 返回m; 如果不为0, 那么执行下一步  
  第二步: m除以n, 余数赋值给r  
  第三步: 将n赋值给m, r赋值给n, 执行第一步  

  伪代码:
  算法 Euclid(m, n)  
  // Computers gcd(m, n) by Euclid's algorithm  
  // Input: Two nonnegative, not-both-zero integers m and n  
  // Output: Greatest common divisor of m and n  
  while n != 0 do  
      r = m mod n  
      m = n  
      n = r  
  return m

<a id="markdown-consecutive-integer-checking-algorithm连续整数检查算法" name="consecutive-integer-checking-algorithm连续整数检查算法"></a>
#### Consecutive integer checking algorithm连续整数检查算法

  这个算法基于最大公约数的定义: 能被两个数整除的最大数  
  这个数最大值肯定是这两个数其中的较小的数, 那么我们从较小的数开始检查, 看是否能被两个数整除, 如果不是, 那么数字减1, 继续检查

  结构化的描述是:  
  第一步: 将min{m, n}赋值给t  
  第二步: m除以t, 如果余数是0, 执行第三步; 如果不是0, 执行第四步  
  第三步: n除以t, 如果余数是0, 返回t; 如果不是0, 执行第四步  
  第四步: t自减1, 执行第二步  

  算法 cic(m, n)
  // 用consecutive integer check连续整数检察法来计算gcd(m, n)  
  // Input: Two nonnegtive, not noth zero integers m, n  
  // Output: Greatest common divisor of m and n  
  $t \gets min(m, n)$  
  while true  
      if m mod t == 0  
          if n mod t == 0  
              return t  
    t -= 1  

<a id="markdown-middle-school-procedure中学算法" name="middle-school-procedure中学算法"></a>
#### Middle-school procedure中学算法

  这个算法的命名是因为我们通常在中学里是这么学的
  第一步: 找出m的素因子
  第二步: 找出m的素因子
  第三步: 找到第一步和第二步的公共因子
  第四步: 第三步的因子相乘, 得到最大公约数

  举例如下:
  60 = 2.2.3.5
  24=2.2.2.3
  gcd(m, n) = 2.2.3 = 12

  这个算法不是合法的, 因为我们在上面解释算法的要点时, 需要满足算法的每一步都必须明确无误, 我们看到这个算法的1-3步, 都不是明确的. 我们如何执行这三步呢? 恐怕是要打问号的.

  要明确上面的步骤, 需要用到小于某个数的所有素数的算法: [sieve of Eratosthenes埃拉托斯特尼筛法](https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95)

  结构化的描述是:  
  给定一个大于等于2的整数n, 求小于等于n的所有素数  
  第一步: 定义一个列表array, 元素是2到m  
  第二步: 将p赋值2, 如果p\*p > m, 则返回array  
  第三步: 从p\*p开始, 将p的倍数从array里删除(为什么从p\*p开始, 因为在之前的循环里, 2,...(p-1)p都已经执行过了, 仔细想想. 这里也能解释第二步的限制条件p\*p > m则返回)  
  第四步: p自增1, 执行第二步

  ALGORITHM Sieve(n)  
  // Implements the sieve of Erathosthenes  
  // Input: A positive integer n > 1  
  // Output: Array L of  all prime numbers less than or equal to n
  for p = 2 to n do A[p] = p  
  for p = 2 to $\lfloor \sqrt{n} \rfloor$ do  
      if A[p] != 0  
          j = p*p  
          while j <= n do  
              A[j] = 0  
              j = j + p  
  i = 0  
  for p = 2 to n do  
      if A[p] != 0  
          L[i] = A[p]  
          i = i + 1  
  return L

> 个人感悟:
> 通过对greatest common divisor的三种算法的学习, 我们可以把算法的设计归结为3个步骤:
> 
> 1. 算法的结构化描述(这一步很关键, 借助纸笔+大脑, 纸笔很重要)
> 2. 伪代码
> 3. 代码实现
> 具体的设计方法下一章节有介绍

<a id="markdown-excercises" name="excercises"></a>
### Excercises

1. al-Khorezmi  
    中译花拉子米, 波斯数学家, 活跃在大约公元前800年. 代数algebra一次来源于他的著作《代数学》, 而算法algorithm一词是花拉米子的拉丁译名.

2. 算法可以申请专利吗?  
    根据我国的情况, 算法属于治理活动, 不能申请专利, 但是有其他办法, 比如与硬件结合, 或者申请著作权

3. 算法要求每一步都是明确无误的, 那么尝试按照此要求描述从家到学校(公司)的路线, 以及做一道菜 
    - 从家到公司的路线
      1. 沿SYB路往东走500m
      2. 左转
      3. 沿DWD路往北走4km
    - 西红柿炒茄蛋的做法
      1. 加生粉水、打散鸡蛋 
      2. 炒鸡蛋30s
      3. 盛出装盘
      4. 炒西红柿1min
      5. 将炒好的鸡蛋倒入锅中
      6. 加盐, 炒30s
      7. 加蒜末, 拌匀
      8. 盛出装盘

4. 设计一个算法, 求出一个正整数n的floor square root, 即$\lfloor \sqrt{n} \rfloor$, 只能用基本的四种运算  
    floor square root算法:  
    第一步: 将1赋值给i  
    第二步: 将i的平方大于n, 则返回i-1  
    第二步: i自增1, 执行第二步  

    伪代码是:  
    ALGORITHM floor_square_root(n)  
    // Input: a positive integer n  
    // Output: a positive integer  
    i = 1  
    while i * i <= n  
      i += 1  
    return i - 1

5. Design an algorithm to find all the common elements in two sorted lists of numbers. For example, for the lists 2, 5, 5, 5 and 2, 2, 3, 5, 5, 7, the output should be 2, 5, 5. What is the maximum number of comparisons your algorithm makes if the lengths of the two given lists are m and n, respectively?  
    common_item算法:  
    Step1: 定义一个空的list r  
    Step2: 定义初始化index, m_index = 0, n_index = 0  
    Step3: 如果m_index = len(m) - 1或者n_index = len(n) - 1, 则返回r  
    Step4: 如果m[m_index] > n[n_index], 则n_index自增1;  
      如果m[m_index] = n[n_index], 则将m[m_index]加入到list r, m_index和n_index都自增1;  
      如果m[m_index] < n[n_index], 则m_index自增1;执行Step3  
    Step5: 返回list r

    Preseudocode  
    ALgorithm common_item_of_two_list(m, n)  
    // Input: two integer list m, n  
    // Output: list r of common elements in m, n  
    r = []  
    m_index = n_index = 0  
    while m_index < len(m) || n_index < len(n)  
      if m[m_index] < n[n_index]:  
        m_index ++  
      elif m[m_index] == n[n_index]:  
        r.append(m[m_index])  
        m_index ++  
        n_index ++  
      elif m[m_index] > n[n_index]:  
        n_index ++  
    return r

6. Find gcd(31415, 14142) by applying Euclid’s algorithm. 执行代码可知答案是1; 用Euclid的方法运行2次即可, 用sonsecutive integer check的方法要运行14142次, 差距悬殊

7. 证明gcd(m, n) = gcd(n, m mod n)  
    对于m、n, 存在$m = x \times n + y$  
    y是m mod n  
    假设m、n的最大公约是是r,将上面的等式两边除以r  
    $m/r = x \times n/r + y/r$  
    因为r是m、n的最大公约数, 所以m/r和x*n/r都是自然数  
    那么$y/r = m/r - x \times n/r$, y/r也是自然数, 所以y也能被r整除  
    所以r是n和y的公约数, 我们假设n和y的最大公约数是r1, 那么r <= r1  
    我们对$m = x \times n + y$两边除以r1, 得到:  
    $m/r1 = x \times n/r1 + y/r1$  
    因为r1是n和y的最大公约数, 所以$x \times n/r1$和y/r1都是自然数, 那么m/r1也是自然数  
    所以r1是m和n的公约数, 所以r1 <= r  
    r <= r1 and r1 <= r, 那么m、n的最大公约数r就等于n、y(m mode n)的最大公约数r1  
    即gcd(m, n) = gcd(n, m mod n)

    这里也可见[Discrete Mathmatics: Elementary Number Theory and Methods of Proof](./docs/discrete_mathmatics/discrete_mathmatics?id=_48-applications-algorithms)


8. 当m < n时, 我们在做第一次运算的时候实际上就是把m、n交换了, 比m > n的情况多计算了一次

9. a可以马上得出答案是1, b的话, 用穷举法吧

10. a Euclid的变种: gcd(m, n) = gcd(m - n, n) for m >= n >= 0
    Algorithm euclid(m, n)  
    // Input: grater than zero integer m, n  
    // Out: greatest common divisor of m, n  
    while true:  
      if m == 0:  
        return n  
      if n == 0:  
        return m  
      if m > n:  
        m = m - n  
      elif m == n:  
        return m  
      else:  
        n = n - m  
    实际代码请看代码仓库  
    b. 看两个数是的倍数是多大, 偶数倍, 则第二个选择. 方法是从最小的数字开始计算, 从1、2开始, 来做总结

11. extended euclid's algorithm  
    定理解释看维基百科: <https://zh.wikipedia.org/wiki/%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95>  
    这里做算法实现, 证明可参加百科, 这里不做重点  
    
    extended euclid's algorithm  
    Step 1: 给定大于等于0的整数m、n, 定义ro = m, r1 = n, s0 = 1, s1 = 0, t0 = 0, t2 = 1  
    Step 2: 如果r1等于0, 则返回最大公约数r0, 以及s0和t0, 满足s0 * m + t0 * n = r0, 执行Step3  
    Step 3: x是r0除以r1的quotient, y是remainder, ro赋值r1, r1赋值y, s2赋值s0 - x * s1, so赋值s1, s1赋值s2, t2赋值t0 - x * t1, t0赋值t1, t1赋值t2, 执行Step 2

    PreseudoCode  
    extended euclid's algorithm  
    // Input: two greater than zero m, n  
    // Output: three integer r, s, t that r is the greatest common divisor of m, n and r = m * s + n *t  
    ro = m, r1 = n, s0 = 1, s1 = 0, t0 = 0, t1 = 1  
    while true  
      if r1 == 0  
        assert r0 = s0 * m + t0 * n  
        return r0, s0, t0  
      y = r0 mod r1  
      x = r0 - x * r1  
      r0 = r1  
      r1 = y  
      s2 = s0 - x * s1  
      s0 = s1  
      s1 = s2  
      t2 = t0 - x * t1  
      t0 = t1  
      t1 = t2

12. locker doors  
    locker doors algorithm  
    Step1: 定义一个array, 元素数量为n, 元素全部为0, 代表n个锁着的柜子  
    Step2: i赋值0
    Step3: 如果i等于n, 返回array; 如果小于n, 执行下一步
    Step4: j赋值0
    Step5: 如果j大于i, i自增1, 执行Step3; 如果j小于等于i, 执行下一步  
    Step5: array[j]如果是1则赋值0, 如果0则赋值1, j自增1, 执行Step5

    locker door algorithm  
    // Input: positive integer n
    // Output: a array that item is 0 or 1  
    array = [0, ..., 0]  
    i = 0  
    while i < n  
      j = 0  
      while j <= i  
        array[j] = array[j] == 0?: 1, 0  
        j ++  
        i ++  
    return array

<a id="markdown-_12-fundamentals-of-algorithmic-problem-solving" name="_12-fundamentals-of-algorithmic-problem-solving"></a>
## _1.2 Fundamentals of Algorithmic Problem Solving

*"We can consider algorithms to be procedural solutions to problems"*  
精确定义每一步步骤, 至关重要

<a id="markdown-understanding-the-problem" name="understanding-the-problem"></a>
### Understanding the Problem

如何理解要解决的问题?  

仔细阅读问题, 如有疑问则提问并解答, 手写一些简单的例子, 想想一些特殊的情况, 再想想有没有什么疑问  

Input一个输入实际上指的是算法要解决的一个instance实例, 如果没有搞清楚input, 你设计的算法可能能解决大多数情况, 但是在一些边界情况可能会失败. 一个算法应该在所有合法输入的情况下都能正确运行.

搞清楚Input, 不然你会做重复工作

<a id="markdown-ascertaining-the-capabilities-of-the-computational-device确定计算设备" name="ascertaining-the-capabilities-of-the-computational-device确定计算设备"></a>
### Ascertaining the Capabilities of the Computational Device确定计算设备

在理解了一个问题之后, 我们要确定算法在什么养的设备运行, 绝大多数算法会在冯诺伊曼机器上运行, 这类机器会顺序执行程序, 一个时间单位只能执行一个程序, 依赖于这类机器上运行的算法我们称之为sequential algorithms(顺序算法)

与之对应的, 如果机器可以并行parallel, 也就是一个时间单位可以同时执行多个程序(请注意与并发concurrent的区别, concurrent是指交替执行), 那么基于此, 可以设计parallel algorithms(并行算法).

但是在可见的未来, 设计sequential algorithms还是算法的基石

好, 上面说了一些概念和现状. 基于此, 我们设计算法的时候需要注意速度和内存空间, 因为我们需要在计算机上运行, 而不只是科学练习, 尽管现在计算机的性能已经很好, 但是我们在实际工作中, 会经常遇到复杂的问题, 大量的数据, 已经时间限制, 所以速度和内存空间, 需要被关注

<a id="markdown-choosing-between-exact-and-approximate-problem-solving在精确还是近似解决问题之间做选择" name="choosing-between-exact-and-approximate-problem-solving在精确还是近似解决问题之间做选择"></a>
### Choosing between Exact and Approximate Problem Solving在精确还是近似解决问题之间做选择

什么意思? 为什么还有近似解决? 算法为什么分exact algorithm和approximation algorithm?

1. 很多问题无法精确解决, 比如平方根, 非线性方程式赛车等等, 我们无法得到一个精确的答案.
2. 由于问题的复杂性, 精确解决方案的速度可能慢到无法接受
3. 一个近似的算法可是是一个精确的复杂算法的一部分

<a id="markdown-algorithm-design-techniques" name="algorithm-design-techniques"></a>
### Algorithm Design Techniques

算法设计技术、策略、范式, 是用算法解决问题的通用方法.

看这本书的目录, 很多讲的都是算法设计技术, 这些设计技术至关重要, 因为:
1. 它们为解决新问题系统了指导, 我们通过设计技术能学会自己捕鱼, 而不是别人给我们鱼, 它们是我们的工具箱
2. 算法是计算机科学的基石. 通过算法设计技术可以对算法进行分类和研究.

<a id="markdown-design-an-algorithm-and-data-structure" name="design-an-algorithm-and-data-structure"></a>
### Design an Algorithm and Data Structure

虽然有很多算法设计技术, 但是设计算法来解决问题还是很有挑战的事情, 因为有的算法可以应用一种设计技术就能解决, 但是有的算法可能需要通过组合多种设计技术才能解决, 甚至有的算法用已知的设计技术根本无法解决.就算通过设计技术能够得到算法, 这中间也依赖设计者聪明的才智. 通过练习、应用, 能让算法设计变得容易一些, 但算法设计还是意见不容易的事儿.

我们还应关注数据结构的选择, 比如在1.1里介绍的筛法, 如果数据结构用linked list链表, 相比于用array数组, 运行时间更厂(因为inked list读取其中的元素效率更低). 第6、7章的算法设计技术里, 密切依赖于数据重组、数据结构的选择. 以前有一本很有名的书叫: Algorithm + Data Structure = Program, 表明了数据结构的重要性. 1.4节我们会回顾基本的数据结构.

<a id="markdown-methods-of-specifying-an-algorithm详细说明算法的方法" name="methods-of-specifying-an-algorithm详细说明算法的方法"></a>
### Methods of Specifying an Algorithm详细说明算法的方法

在上一章节的欧几里得算法里, 我们可以看到, 我们有两种方法来说明算法:
1. 自然语言, 这种方法很直接明了, 但是自然语言总是不够精确, 但是这种方法依然是一项很重要的技能
2. Pseudocode伪代码, 伪代码是自然语言与编程语言的结合体. 比自然语言更加精确更简洁. 伪代码没有统一的格式, 但是神奇的是, 尽管每个人写的伪代码格式会有差别, 但是, 大家都能明白.

以前的主要手段是流程图flowchart, 但是这个被证实不太方便, 在早期的算法书里能见到.  
目前还没有达到将自然语言或者伪代码输入到计算机能运行的程度, 但是这是算法实现的一个重要过程

<a id="markdown-proving-an-algorithms-correctness" name="proving-an-algorithms-correctness"></a>
### Proving an Algorithm's Correctness

算法被具体描述之后(不管是自然语言还是伪代码), 可以写代码取实现了吗? 不, 我们还需要证明Specify的正确性, 不然代码实现时会做重复工作.

要证明算法的正确性, 意味着你要根据所有合法的输入都能得到正确的结果, 且在一个有限的时间内.

证明的常用方法是采用数据归纳法(什么是数学归纳法? 去翻书吧《how to solve it如何解题》)

<a id="markdown-analyzing-an-algorithm" name="analyzing-an-algorithm"></a>
### Analyzing an Algorithm

证明了算法的正确性, 我们接下来要关注算法的效率, 效率氛围时间效率time efficiency和空间效率space efficency, 这部分会在第二章讲解.

我们还关注算法是否简单simplicity, simplicity不能像efficiency一样被精确量化, 只能靠眼睛直观感受. 比如最大公约数的算法, 欧几里得算法肯定比中学算法要简单明了, 但是比连续整数监察法要简单明了吗? 我们可能要打个问号, 简单的算法更容易被实现, bug也会更少. 通常效率也会更高, 但是不绝对. 这就需要做一些权衡.

我们还要考虑算法的通用性generality, 指的是, 在问题和输入两方面具有更好的通用性, 比如我们要确认两个整数是否互为prime number, 我们实际上可以设计一个求两个数的最大公约数的算法, 如果最大公约数是1, 那么两个数互为prime number. 对于输入也是类似, 我们不应特定限制输入的范围.

如果对于efficiency, simplicity, generaality这三方面不满意, 那么拿起你的白板, 重新设计吧!

实际上就算你觉得满意了, 还会有更好的算法设计. 

> A designer knows he has arrived at perfection not when there is no longer anything to add, but when there is no longer anything to take away.

<a id="markdown-coding-an-algorithm" name="coding-an-algorithm"></a>
### Coding an Algorithm

> As a rule, a good algorithm is a result of repeated effort and rework.

好像和很多事情一样, repeated effort and rework is important, not genious

代码实现之外, 测试程序必不可少

最后, 算法设计不是一项枯燥的活动, 事实上, 算法设计是一项非常体现创造力和成就感的事情. 

<a id="markdown-excecises" name="excecises"></a>
### Excecises

1. wolves, goat, cabbage puzzle  
    Step1: move goat to the other side  
    Step2: boat back to the origin  
    Step3: move wolve to the other side  
    Step4: move goat back to the origin  
    Step5: move cabbage to the other side  
    Step6: boat back to the origin  
    Step7: move goat to the other side  

2. modernn puzzle  
    // Input: {A: 1, B: 2, C: 5, D: 10}  
    // Outpuy: total time t  
    Step1: A and B move to the other side, t = 2  
    Step2: A move back, t += 1, t = 3  
    Step3: C and D move to the other side , t += 10, t = 13  
    Step4: B move back, t += 2, t = 15  
    Step5: A and B move to the other side , t += 2, t = 17  
    // 这个问题想的时间比较长, 尝试了好多种移动的方法, 最后解出来的关键是时间长的两个人, 最好一起走, 会节省时间

 做到这里, 虽然上面两个问题都解决了, 但是都是通过自然语言描述, 无法做到伪代码描述, 为什么做不到? 我觉得很大原因是没有合适的数据结构, 我看看之后怎么解决这个问题

 3. abc都是正确的公式, 但是我们的已知元素是三边边长, 所以a是正确答案, 这是heron's formula(海伦公式)

 4. 二次方程  
x的解是: $\frac{-b\pm\sqrt{b^2-4ac}}{2a}$  
这个很容易就能推导出来, 下面我们用伪代码来计算这个结果:  
Pseudocode  
// Input: 实数a, b, c, 满足$ax^2 + bx + c = 0$  
// Output: 两个实数  
　$s = b^2 - 4ac$  
　if s1 < 0  
　　raise exception  
　else  
　　return $\frac{-b+\sqrt{s}}{2a},\frac{-b+\sqrt{s}}{2a}$

5. decimal integer to binary representation  
natural language  
Step1: s赋值空字符串  
Step2: 如果n等于0, 则返回s, 负责执行下一步  
Step3: n除以2, 得到整数商x, 和余数y  
Step4: 将x赋值给n, s前面加上字符串y, 执行Step2  
Pseudocode  
s = ""  
while n != 0  
    x = floor(n / 2)  
    y = mod(n, 2)  
    n = x  
    s = str(y) + s  
return s
代码见: <a href="../../code/1_Introduction/1.2_Fundamental_of_Algorithmic_Problem_Solving/e5_decimal_to_binary.cpp">decimal to binary</a>

6. ATM algorithm  
    我没搞明白这个问题, 姑且认为是取钱的步骤吧  
    natural language  
    Step1: 查询余额为m, m >= 0  
    Step2: 输入取现金额n, n > 0; 或者退卡  
    Step3: 如果n > m, raise exception, 执行Step2; 如果n < m, 则执行下一步  
    Step4: 余额m -= n  
    Step5: 吐出钞票, 执行Step2

7. $\pi$ is irrational
$\pi$1776年, Johann Heinrich Lambert证明了$\pi$是无理数, 对于这道题我就了解到这儿吧...

8. sort algorithm
  
9. finding the distance between the two closest elements in an array of numbers
　- j可以从i+1开始循环  
　- 重新设计算法, 暂时想不出来, 待以后再想

10. how to solve it. 回头再看看这本书
  

<a id="markdown-_13-important-problem-types" name="_13-important-problem-types"></a>
## _1.3 Important Problem Types

问题多种多样, 浩如烟海, 但是有些类型的问题熠熠生辉:
- Sorting排序
- Searching查找
- String processing字符串处理
- Graph problems图形问题
- Combinatorial problems组合问题
- Geometric problems几何问题
- Numerical problems数值问题

<a id="markdown-sorting排序" name="sorting排序"></a>
### Sorting排序

为什么要排序?  
- 现实的需要, 比如排名
- 利于查找
- 其他算法的辅助手段

排序算法的两个特征需要特别提及:
- stable  
  如果一个排序算法, 在排序之后仍然保持了原来list里两个相等元素的相对位置, 那么我们称这个算法stable  
  换句话说, 在原来list里两个想等元素的位置是i, j, i < j, 经过排序之后, 它们的位置是i1, j1, 仍然满足i1 < j1
- in-place  
  这个特征表示一个排序算法是否需要额外内存, 如果不需要额外内存, 那么称这个算法in-place

<a id="markdown-searching查找" name="searching查找"></a>
### Searching查找

查找算法, 包括顺序查找, 效率更高但是有限制性的二分查找, 已经基于不同组织形式的基础数据的查找. 后一种算法对于现实世界尤其重要.

<a id="markdown-string-processing字符串处理" name="string-processing字符串处理"></a>
### String processing字符串处理

字符串处理算法长期以来对于计算机科学领域的计算机语言和编译问题都很重要.

很典型的一个问题: 如何在文本中搜索一个特定的单词? 我们称之为string matching字符串匹配. 在第3章和第7章有介绍.

<a id="markdown-graph-problems图形问题" name="graph-problems图形问题"></a>
### Graph problems图形问题

Graph图形是vertices(顶点)的集合, 它们用edges边连接.

图形应用广泛, 感兴趣的可以参照[Fundamentals of Computer Graphics](https://max-young.github.io/computer_graphics/)

基本的图形算法包括:
- graph-traversal algorithms图形遍历算法  
  如何到达所有点
- shortest-path algorithm最短路径算法
- topological sorting for graph with directed edges有向图形的拓扑排序  

一些图形算法非常困难, 著名的两个问题:
- travelling salesman problem(TSP)  
  这个问题需要解决在只能停留一次的情况下到达所有城市的最短路径.  
  这个算法还能应用在芯片制造、晶体学、基因工程等领域, awesome!!
- graph-coloring problem  
  这个算法要解决用最小数量的颜色分配给图的顶点, 相邻顶点的颜色不能相同

<a id="markdown-combinatorial-problems组合问题" name="combinatorial-problems组合问题"></a>
### Combinatorial problems组合问题

上面提到的travelling salesman problem和graph-coloring problem就是组合问题

组合问题非常难以解决. 一些组合问题能够被高效的算法解决, 比如最短路径问题, 但这只是幸运的例外

<a id="markdown-geometric-problems几何问题" name="geometric-problems几何问题"></a>
### Geometric problems几何问题

这一段描述很有意思:  
集合算法处理几何对象, 例如点、线、面、多边形  
古希腊人热衷于解决几何问题, 用没有刻度的尺子和指南针来构建图形.  
但是之后的两千年, 人类对这类问题的热情消失了...  
直到近世进入计算机时代, 我们重燃热情, 我们不再使用尺子和指南针了, 而是字节和大脑

我们将讨论两个经典问题:
- the closest-pair problem  
  平面上有n个点, 找到相隔距离最近的两个点
- convex-hull problem  
  再给点的点的集合里, 找到最小的凸多边形

<a id="markdown-numerical-problems数值问题" name="numerical-problems数值问题"></a>
### Numerical problems数值问题

很重要的领域, 不再详述

<a id="markdown-exercises" name="exercises"></a>
### Exercises

1. comparison counting sort  
  ALGORITHM ComparisonCountingSort(A[0...n-1])  
  //Sorts an array by comparison counting  
  //Input: Array A[0...n-1] of orderable values  
  //Output: Array S[0...n-1] of A's element sorted in nondecreasing order  
  for i = 0 to n-1 do  
      Count[i] = 0  
  for i = 0 to n-2 do  
      for j = i+1 to n-1 do  
          if A[i] < A[j]  
              Count[j] = Count[j] + 1  
          else  
              Count[i] = Count[i] + 1  
  for i = 0 to n-1 do  
      C[Count[i]] = A[i]  
  return s  
  代码见[comparisonCountingSort](../../code/1_Introduction/1.3_Important_Problem_Types/e1_comparison_counting_sort.cpp)  
  is this algorithm stable?  
      no. 如A[i] < A[j]改成A[i] <= A[j], 则是stable  
  is it in-place?  
      no. 因为额外用到了Count这个数组

2. sequential search algorithm and binary search algorithm

3. string-matching problem  
  ALGORITHM stringMatchingAlgorithm  
  //string matching algorithm  
  //Input: a string s, a alpha a 
  //Output: a integer what the alpha's index in string  
  index = -1  
  for i in s:  
    if i == a:  
      return s.index(i)  
  return index  

4. Königsberg bridge  
  参照[discrete mathmatics:graphics-Königsberg bridge](./docs/discrete_mathmatics/Chapter_10_GRAPHS_AND_TREES?id=königsberg-bridge)

5. Hamiltonian Circuits  
  参照[discrete mathmatics:Hamiltonian Circuits](./docs/discrete_mathmatics/Chapter_10_GRAPHS_AND_TREES?id=hamiltonian-circuits)

6. find a least edge trail and a least verticles path, then compare?

7. tavelling-salesman problem参照[discrete mathmatics:Hamiltonian Circuits](./docs/discrete_mathmatics/Chapter_10_GRAPHS_AND_TREES?id=hamiltonian-circuits)  
  graph-coloring problem好像是一个很复杂的问题
  // TODO 日后再看

8. 同上graph-coloring problem

9. 给定一组点, 判断这组点是否在一个圆周上. 设计一个算法.
  ALGORITHM check_circle  
  //Input: a list A of (x, y) points  
  //Output: Boolean that whether points in A are in a circle line  
  if len(A) <= 3:  
    return true  
  $x_0, y_0$ = A[0]  
  $x_1, y_1$ = A[1]  
  $x_2, y_2$ = A[2]  
  // 求得三个点的圆心  
  c = (a, b)  
  $(x_0 - a)^2 + (y_0 - b)^2 = (x_1 - a)^2 + (y_1 - b)^2$  
  $(x_1 - a)^2 + (y_1 - b)^2 = (x_2 - a)^2 + (y_2 - b)^2$  
  // 求得a, b并计算得到半径  
  $bj = \sqrt{(x_0 - a)^2 + (y_0 - b)^2}$  
  for i in A[3:]:  
    if $(i.x - a)^2 + (i.y - b)^2 \neq bj$:  
      return false  
  return true
  // TODO 日后再看

10. 两条线段是否相交, 两条线的端点x, y已知  
  // TODO 日后再看

<a id="markdown-_14-fundamental-data-structures" name="_14-fundamental-data-structures"></a>
## _1.4 Fundamental Data Structures

很多算法都是在操作数据, 数据的组织形式在设计和分析算法的工程中扮演重要的角色.

A **data structure** can be defined as a particular schema of organizing related data items.

<a id="markdown-linear-data-structures线性数据结构" name="linear-data-structures线性数据结构"></a>
### Linear Data Structures线性数据结构

最重要的两种基本数据类型是array和linked list.

**array**是一系列同一种类型的数据集合, 在内存里连续存储, 能够通过index获取其中的数据, 且时间一样.  
index一般是数字0至n-1, 也有其他形式的index  
array可以用来实现其他数据结构, 比如string字符串, string是一系列字母, 然后以一个特殊字符结尾.

**linked list**链表是一系列nodes, node包括数据, 和1个或者多个pointer, 指向其他node  
在单链表singly linked list里, 除了最后一个node, 其他node都含有一个pointer指向下一个node  
要获取node, 需要从第一个node依次往下找, 效率不高. 但是插入和删除效率高, 因为linked list不像array需要顺序存储.
linked list可以从一个特殊的node开始, 这个node称为header, 可以包含一些特殊信息, 比如linked list的长度, 指向最后一个node的pointer等信息
另外一个扩展的数据结构是doubly linked list, 除了首尾两个node, 其他node都包含指向其前后两个node的pointer  

array和linked list用来表示list, list的基本操作是search查找、insert插入、delete删除
另外两种list的特殊数据结构是stack和queue:

**stack**是只能在end末端插入和删除元素的list, 这个末端称之为top, 因为我们图像化stack的时候习惯从垂直来看, 而不是水平方向.  
stack有last in first out(LIFO)的风格, 就像堆盘子一样  
stack可以应用在recursive algorithms上

**queue**是一个在一端删除, 另外一端增加的list, 删除的那一端叫做front, 删除的操作叫dequeue, 增加的那一端叫rear, 增加的操作叫enqueue  
queue有first in first out(FIFO)的风格, 如果银行了单个服务台服务一列客户  
queue可以应用在graph problems上

很多重要的应用里需要从一系列动态变化的数据中选出优先级高的数据, 满足这种需求的数据结构叫priority queue.  
一个priority queue是一个有序的数据集合. 其主要的操作是查找最大的元素, 删除最大的元素, 添加一个新元素. 后两个操作都可能会得出新的priority queue.  
要实现这样的数据类型, 可以用array或者sorted array, 但是效率都不高. 在6.4章节会介绍heap这个数据类型, 这是更好的解决方案.

### Graphs

**Definition**

graph相关知识可以参照discrete mathmatics的内容, 参照[discrete mathmatics:Hamiltonian Circuits](./docs/discrete_mathmatics/Chapter_10_GRAPHS_AND_TREES)
这里记录一下discrete mathmatics没有的信息

一个graph的edge相对缺失比较少, 我们称这个graph dense(稠).  
(为什么是“缺失比较少”这样的表达, 因为是相对于complete而言的, 一个graph的所有vertices都有edge相连, 我们称其complete)  
一个graph的edge相对于vertices比较少, 我们称这个graph sparse(疏).  

**Representation**

在discrete mathmatics里说到, graph可以用adjacency matrix表示, 这里不再赘述, 本书还提到另外一种表示方式:  
adjacency list: a collection of linked lists  
例如这样的一个graph:  
<img src="./_images/graph1.png" width=30%>  
用adjacency matrix和adjacency list分别表示如下:  
<img src="./_images/graph_representation.png" width=50%>  

如果graph sparse, 那么用adjacency list表示, 更节省空间. 反之, adjacency matrix更好.  
另外两种方式的选择, 也需要据问题和算法的类型而定

**Weighted Graphs**

Weighted Graph是指给edge赋给数值的graph. 这个数值称为weights或者costs.  
这个类型的graph是来源于现实世界的问题: 比如最短路径等等.

weighted graph也可以用上面的两种方法表示, 如下图:  
<img src="./_images/weighted_graph.png" width=50%>  
$\infty$表示两个vertices没有edge相连

**Paths and Cycles**

这里的path指的是discrete mathmatics里的walk  
simple path指的是discrete mathmatics里的path

cycle指的是discrete mathmatics里的circuit  
如果一个graph没有cycle, 那么我们说这个graph acyclic

### Trees

tree相关知识可以参照discrete mathmatics的内容, 参照[discrete mathmatics: tree](./docs/discrete_mathmatics/Chapter_10_GRAPHS_AND_TREES?id=_105-trees-树)

tree是一个没有cycle(circuit), 且是connected的graph, 如果不connected, 那么就是forest

tree的edge的数量是vertices的数量减1

**Rooted Trees**

我们可以从一个tree里选取一个点, 称之为**root**, 其他点都有唯一一条simple path到达root(这是由tree的特性决定的, 如果存在多条, 则会构成cycle)  
显示的时候可以把root放在最上面, 我们称这样的tree为**rooted tree**

对于一个tree T上的一个vertex v, 从root到v的simple path上的vertices成为v的**ancestors**(包括v), 如果排除v, 则是**proper ancestors**  
如果edge {u, v}是这条simple path上的最后一条edge, 那么u是v的parent, v是u的child.  
如果vertices的parent相同, 则它们是**siblings**  
没有child的vertex称为**leaf**  
一个vertex至少有一个child, 称之为**parental**
vertices的ancestor是v, 那么这些vertices称之为v的**descendants**, 排除v则称之为**proper descendants**  
一个vertex v和它的所有descendants以及相连的edges称之为T的**subtree**, 其为root为v的rooted tree  
v的**depth**是从root到v的simple path的长度  
tree的**height**是指所有顶点里最长的simple path的长度

**Ordered Trees**  

ordered tree是指一个tree, 它的所有vertices的children都是有序的

**binary tree**是指所有vertices最多只有2个children的tree.  
两个children可以称为**left child, right child**  
以这两个children作为root的tree称为**left subtree, right subtree**  
如果所有vertices都大于left subtree上的vertices, 小于right subtree上的vertices, 那么这个tree称为**binary search tree**  
binary tree满足:  
$$log_2n \le h \le n-1$$
n是vertices数量, h是高度  

binary tree在计算机里可以用linked list来表示, 每个node包含自身的值, 以及left child和right child的pointer  

ordered tree可以用first child-next sibling representation方法表示, 同样是用linked list, 每个node包含自身的值, 以及第一个child的pointer, 和下一个sibling的pointer 

### Sets and Dictionaries

**set**是一组无序的但是unique的元素elements.  
我们可以详细指定其中的元素, 也可以用满足公共的属性来表示.  
set的基本操作有: 检查某元素是否属于这个set, 计算两个set的union, 以及intersection

set的表示方法:  
书中提到了一种很有意思的表示方法: 一个set s是一个large set的subset, 这个large set我们称为universal set.  
我们可以用bit string来表示这个set s, 例如universal set是{1, 2, 3, 4, 5, 6, 7, 8, 9}, s是{2, 3, 5, 7}  
那么我们可以用011010100来表示s, 值得注意的是: 我们假定universal是有序的.  
这样表示的好处是执行set操作非常快, 不好的地方是占用内存比较大.

如果我们在上面提到的set的操作的基础上, 还要进行搜索, 添加, 删除. 我们就需要用到这种数据结构了: **Dictionary**  


我们在说上面这些数据结构的时候, 都会特别提到这些这些数据结构需要支持什么操作.  
这些操作实际上构成了这些抽象数据的重要决定特征. 从queue、stack就能看出来.  
在计算机科学里有个术语叫ADT(abstract data type).  
在面向对象的语言里, 如C++, 可以自定义数据类型, 我们称之为class 

### Excercises

1. array在内存里是顺序存储的

2. 对于sorted array, 可以用binary search. 对于linked list, 没有办法, 从第一个开始查

3. (a, c), (c, d)

4. 除了对角线, matrix其他元素都是1; 对角线又一个元素是1; 其中一行和对应的列是0, 自身连自身可以是1.

5. 没有idea. 之后的章节有讲解.

6. discrete mathmatics里有证明  

7. 实现查找、增加、删除的操作; 铜钱一个一样, 但是需要做这些操作之后还要保持sorted; 用linked list表示, 操作时还要保持binary search tree的属性, 操作包括增加节点, 搜索节点, 删除节点.

8. no idea

9. sorted array; dictionary; 涉及postfix notation, 以后看吧.

10. anagram algorithm  
ALGORITHM check_anagram  
// Input: string a, string b  
// Output: boolean whether a and b is anagram  
init a array count with 256 zero  
int i = 0  
while a[i] and b[i]:  
  count[a[i]] ++  
  count[b[i]] --  
  i++  
if a[i] or b[i]:  
  return false  
for i in count:  
  if i != 0:  
    return false  
return true
代码见<a href="../../code/1_Introduction/1.4_Fundamental_Data_Structures/e10_anagram.cpp">anagram algorithm</a>

### Summary

- 一个算法是由一系列清晰无误的步骤组成, 在有限的时间内解决特定问题. 算法的输入即是问题的一个实例.
- 算法可以由自然语言或者伪代码来表示. 也可以用计算机语言来实现.
- 算法有多种分类, 主要的两种分类是:
  - 根据问题类型分类.
  - 根据设计方法分类.
- 主要的问题类型包括: 查找、排序、字符串处理、图形问题、组合问题、几何问题、数值问题.
- 算法设计技术(策略或者范式)是用算法解决问题的通用方法, 应用在各个领域.
- 算法设计虽然是一项创造性的工作, 但是依然可以从中找到一些关联动作和方法.
- 一个好的算法是不断努力和契而不舍的结果.
- 一个问题通常可以用多种算法来解决, 比如计算最大公约数.
- 算法以数据作为操作对象, 所以数据结构在算法设计中非常重要, 比较重要的数据结构有:linear data structure: array, linked list, stack, queue; graph; tree; set and dictionary.
- 一系列支持特定操作的数据构成了某种数据类型, 我们称之为ADT(abstract data type), 在面向对象的计算机语言里通过class的方式来实现ADT.