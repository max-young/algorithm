# Introduction to the Design and Analysis of Algorithms算法的设计和分析

![](https://img1.doubanio.com/view/subject/l/public/s6944177.jpg)

<!-- TOC -->

- [Introduction to the Design and Analysis of Algorithms算法的设计和分析](#introduction-to-the-design-and-analysis-of-algorithms%E7%AE%97%E6%B3%95%E7%9A%84%E8%AE%BE%E8%AE%A1%E5%92%8C%E5%88%86%E6%9E%90)
  - [Preface前言](#preface%E5%89%8D%E8%A8%80)
  - [Introduction介绍](#introduction%E4%BB%8B%E7%BB%8D)
    - [What Is an Algorithm什么是算法](#what-is-an-algorithm%E4%BB%80%E4%B9%88%E6%98%AF%E7%AE%97%E6%B3%95)
    - [greatest common divisor最大公约数](#greatest-common-divisor%E6%9C%80%E5%A4%A7%E5%85%AC%E7%BA%A6%E6%95%B0)

<!-- /TOC -->

## Preface前言

我们提出算法时遵循两种选择, 一是面对具体问题的解决办法, 二是算法设计思想.  
第二点显得尤其重要  
第二点是讲实际的解决方案里共性的方法和思想归类, 有感于现在分类的弊端, 作者提出了新的分类方法(目录则是笔者的分类)

- 先决条件

  读者需要经过介绍性的编程课程和标准的离散结构的课程.   
  关于介绍性的编程课程, 我学习了C++  
  关于离散数学, 我读了[《Discrete Mathematics with Applications》](https://book.douban.com/subject/5495234/)

学习顺序可参考前言里的计划, 大体和顺序学习差不多

## Introduction介绍

学习算法的重要性: 不只是计算机科学的核心, 并且是一种思想, 和其他学科共同的思想, 解决问题的思想

1.1 讲最大公约数的三种算法  
1.2 设计和分析算法的若干要点  
1.3 算法问题类型  
1.4 数据结构的介绍  

### What Is an Algorithm什么是算法

*An algorithm is a sequence of unambiguous instructions for solving a problem, i.e., for obtaining a required output for any legitimate input in a finite amount of time.*

算法是为了解决问题的明确指令的序列. 在有限的时间内, 根据合法的输入, 得到所需的输出.

这里以最大公约数的三种算法来诠释关于算法的以下要点:

1. 算法的每一步必须明确无误
2. 算法的输入范围必须指定
3. 同样的算法可以用多种方法表示
4. 同一个问题可以存在多种算法
5. 同一个问题的多种算法可以基于不同的思想、而且可能速度差别很大

### greatest common divisor最大公约数

两个不都为0的正整数m, n, 他们的最大公约数表示为$gcd(m, n)$

- Euclid欧几里得的算法  

  欧几里得的算法基于:  
  $gcd(m, n) = gcd(n, m\ mod\ n)$  
  循环执行, 直到m mod n = 0, 然后gcd(m, 0) = m, 例如:  
  $gcd(60, 24) = gcd(24, 12) = gcd(12, 0) = 12$  
  结构化的描述是:  
  第一步: 如果n = 0, 返回m; 如果不为0, 那么执行下一步  
  第二步:  m除以n, 余数赋值给r  
  第三步: 将n赋值给m, r赋值给n, 执行第一步  
  
  算法 Euclid(m, n)  
  // Computers gcd(m, n) by Euclid's algorithm  
​	 // Input: Two nonnegative, not-both-zero integers m and n  
​	 // Output: Greatest common divisor of m and n  
  ```math
​	 while $n \neq 0$ do  
​	 　r $\gets$ m mod n  
​	 　m $\gets$ n  
​	 　n $\gets$ r  
  return m  
  ```

- Consecutive integer checking algorithm连续整数检查算法  

  这个算法基于最大公约数的定义: 能被两个数整除的最大数  
  这个数最大值肯定是这两个数其中的较小的数, 那么我们从较小的数开始检查, 看是否能被两个数整除, 如果不是, 那么数字减1, 继续检查  
​  结构化的描述是:
  第一步: 将min{m, n}赋值给t  
  第二步: m除以t, 如果余数是0, 执行第三步; 如果不是0, 执行第四步  
  第三步: n除以t, 如果余数是0, 返回t; 如果不是0, 执行第四步  
  第四步: t自减1, 执行第二步  

- Middle-school procedure中学算法

  这个算法的命名是因为我们通常在中学里是这么学的  
  第一步: 找出m的素因子  
  第二步: 找出m的素因子  
  第三步: 找到第一步和第二步的公共因子  
  第四步: 第三步的因子相乘, 得到最大公约数  

  举例如下:  
  $60 = 2.2.3.5$  
  $24=2.2.2.3$  
  $gcd(m, n) = 2.2.3 = 12$  

  这个算法不是合法的, 因为我们在上面解释算法的要点时, 需要满足算法的每一步都必须明确无误, 我们看到这个算法的1-3步, 都不是明确的. 我们如何执行这三步呢? 恐怕是要打问号的.

  要明确上面的步骤, 需要用到小于某个数的所有素数的算法: [sieve of Eratosthenes埃拉托斯特尼筛法](https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95)

  ALGORITHM Sieve(n)
  // Implements the sieve of Erathosthenes  
  // Input: A positive integer n > 1  
  // Output: Array L of  all prime numbers less than or equal to n  
  for p $\gets$ 2 to n do A[p] $\gets$ p  
  　for p $\gets$ 2 to $\lfloor \sqrt{n} \rfloor$ do  
  　　if A[p] $\neq$ 0  
　　　　j $\gets$ p*p  
  ​		　while j $\le$ n do  
  ​			A[j] $\gets$ 0  
  ​			j $\gets$ j + p  
  i $\gets$ 0  
  for p $\gets$ 2 to n do  
  ​	if A[p] $\neq$ 0  
  ​		L[i] $\gets$ A[p]  
  ​		i $\gets$ i + 1    
  return L