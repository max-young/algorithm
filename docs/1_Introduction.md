<!-- TOC -->

- [1.1 What Is an Algorithm](#11-what-is-an-algorithm)
  - [greatest common divisor最大公约数](#greatest-common-divisor最大公约数)
    - [Euclid欧几里得的算法](#euclid欧几里得的算法)
    - [Consecutive integer checking algorithm连续整数检查算法](#consecutive-integer-checking-algorithm连续整数检查算法)
    - [Middle-school procedure中学算法](#middle-school-procedure中学算法)
  - [Excercises](#excercises)
- [1.2 Fundamentals of Algorithmic Problem Solving](#12-fundamentals-of-algorithmic-problem-solving)
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

<!-- /TOC -->

学习算法的重要性: 不只是计算机科学的核心, 并且是一种思想, 和其他学科共同的思想, 解决问题的思想

1.1 讲最大公约数的三种算法  
1.2 设计和分析算法的若干要点  
1.3 算法问题类型  
1.4 数据结构的介绍  

<a id="markdown-11-what-is-an-algorithm" name="11-what-is-an-algorithm"></a>
## 1.1 What Is an Algorithm

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
                如果m[m_index] < n[n_index], 则m_index自增1;  
                执行Step3  
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
    对于m、n, 存在m = x*n + y  
    y是m mod n  
    假设m、n的最大公约是是r,将上面的等式两边除以r  
    m/r = x*n/r + y/r  
    因为r是m、n的最大公约数, 所以m/r和x*n/r都是自然数  
    那么y/r = m/r - x*n/r, y/r也是自然数, 所以y也能被r整除  
    所以r是n和y的公约数, 我们假设n和y的最大公约数是r1, 那么r <= r1  
    我们对m = x*n + y两边除以r1, 得到:  
    m/r1 = x*n/r1 + y/r1  
    因为r1是n和y的最大公约数, 所以x*n/r1和y/r1都是自然数, 那么m/r1也是自然数  
    所以r1是m和n的公约数, 所以r1 <= r  
    r <= r1 and r1 <= r, 那么m、n的最大公约数r就等于n、y(m mode n)的最大公约数r1  
    即gcd(m, n) = gcd(n, m mod n)

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

<a id="markdown-12-fundamentals-of-algorithmic-problem-solving" name="12-fundamentals-of-algorithmic-problem-solving"></a>
## 1.2 Fundamentals of Algorithmic Problem Solving

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
代码见: [decimal to binary](https://github.com/max-young/algorithm/blob/master/code/1_Introduction/1.2_Fundamental_of_Algorithmic_Problem_Solving/e5_decimal_to_binary.cpp)

6. ATM algorithm  
    我没搞明白这个问题, 姑且认为是取钱的步骤吧  
    natural language  
    Step1: 查询余额为m, m >= 0  
    Step2: 输入取现金额n, n > 0; 或者退卡  
    Step3: 如果n > m, raise exception, 执行Step2; 如果n < m, 则执行下一步  
    Step4: 余额m -= n  
    Step5: 吐出钞票, 执行Step2

7. $\pi$ is irrational
$\pi$1776年, Johann Heinrich Lambert证明了$\pi$是无理数