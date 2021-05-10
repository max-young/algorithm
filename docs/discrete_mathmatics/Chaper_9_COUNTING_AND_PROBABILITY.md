<!-- TOC -->

- [_9.1 Introduction 介绍](#_91-introduction-介绍)
- [_9.2 Possibility Trees and the Multiplication Rule](#_92-possibility-trees-and-the-multiplication-rule)
  - [Permutations](#permutations)
  - [Permutations of Selected Elements](#permutations-of-selected-elements)
- [_9.3 Counting Elements of Disjoint Sets: The Addition Rule加法法则](#_93-counting-elements-of-disjoint-sets-the-addition-rule加法法则)
- [_9.4 The Pigeonhole Principle鸽洞原理](#_94-the-pigeonhole-principle鸽洞原理)
- [_9.5 Counting subsets of a Set: Combinations](#_95-counting-subsets-of-a-set-combinations)
- [_9.6 r-combinations with Repetition Allowed](#_96-r-combinations-with-repetition-allowed)
  - [Definition](#definition)
  - [从5种饮料中选出15瓶饮料](#从5种饮料中选出15瓶饮料)

<!-- /TOC -->

Chapter 9 COUNTING AND PROBABILITY 计数和概率

<a id="markdown-_91-introduction-介绍" name="_91-introduction-介绍"></a>
### _9.1 Introduction 介绍

sanple space: 样本空间

A sample space is the set of all possible outcomes of a random process or experiment.
An event is a subset of a sample space.

Equally Likely Probability Formula: 均等概率公式

<a id="markdown-_92-possibility-trees-and-the-multiplication-rule" name="_92-possibility-trees-and-the-multiplication-rule"></a>
### _9.2 Possibility Trees and the Multiplication Rule

#### Permutations

一个set的permutation是指其元素的ordering. 比如一个set的元素是a, b, c, 它有6个permutations:  
abc acb cba bac bca cab  
那么n个yuansu的set, 有多少个permutations呢? 很好算, 我们挨个排, 第一个元素有n个选择, 第二个元素有n-1个选择, 第n个元素只有1个选择, 所以我们有这样的定理:  
对于$n \ge 1$的整数n, 一个有n个元素的set, 有$n(n-1)(n-2)...1 = n!$个permutations

#### Permutations of Selected Elements

上面说的permutation是指给定set里的所有元素的排序, 假如我们从中选取一部分元素做排序, 会有多少种排序呢?  
这就是Permutations of Selected Elements的定义:

一个含有n个元素的set, 它的**r-permutations**是指从这n个元素中挑选出r个元素, 并且是有序的, 这些挑选组合的集合.  
用$P(n, r)$来表示这个几何的长度, 也就是共有多少种挑选

$P(n, r)$怎么计算呢? 跟Permutations的计算很像:  
还是挨个排, 第一个元素有n种选择, 第二个元素有n-1种选择, 第r个元素有i$n-(r-1)=n-r+1$种选择, 所以:
$$P(n, r) = n(n-1)(n-2)...(n-r+1)$$
将这个等式做一下转换:
$$\frac{n!}{(n-r)!} = \frac{n(n-1)(n-2)...(n-r+1)(n-r)(n-r-1)...1}{(n-r)(n-r-1)...1} = n(n-1)(n-2)...(n-r+1)$$
所以:
$$P(n, r) = \frac{n!}{(n-r)!}$$

<a id="markdown-_93-counting-elements-of-disjoint-sets-the-addition-rule加法法则" name="_93-counting-elements-of-disjoint-sets-the-addition-rule加法法则"></a>
### _9.3 Counting Elements of Disjoint Sets: The Addition Rule加法法则

例如, 密码是26个字母的组合, 长度是1位到3位, 那么密码的可能是1位、2位、3位三种可能性之和

<a id="markdown-_94-the-pigeonhole-principle鸽洞原理" name="_94-the-pigeonhole-principle鸽洞原理"></a>
### _9.4 The Pigeonhole Principle鸽洞原理

5只鸽子飞往4个洞, 那么至少有一个洞有2个或2个以上鸽子, 好像是显而易见的哈. 用术语表达就是:

Pigeonhole Principle:  A function from one finite set to a smaller finite set cannot be one-to-one: There must be a least two elements in the domain that have the same image in the co-domain.

<a id="markdown-_95-counting-subsets-of-a-set-combinations" name="_95-counting-subsets-of-a-set-combinations"></a>
### _9.5 Counting subsets of a Set: Combinations

一个实际的问题: 从12个人中挑出5个人组成一个team去工作, 有多少种不一样的5个人的挑法?   
这就涉及到这一章节要讲的定义: r-combination  
两个正整数r and n, $r \le n$, 有n个元素的set的**r-combination**, 是指一个subset, 它有r个元素, 这r个元素属于这n个元素, 表示为:
$$\binom{n}{r}$$
读作"n choose r", 表示从n个元素的set里挑出r个元素的subset(r-combination)的长度

举一个例子, 一个set{0, 1, 2, 3}, 从中挑出两个数字, 元素比较少, 我们手动就能算出来: $\binom{4}{2} = 6$, 手动全部列出来的方法叫**complete enumeration**穷举法  

有没有公式来计算呢? 我们回顾一下9.2章节的[Permutations of Selected Elements](#permutations-of-selected-elements), $P(n, r) = \frac{n!}{(n-r)!}$
我们可以把r-permutations的计算拆分成两步, 还是以set{0, 1, 2, 3}为例:
1. 找出{0, 1, 2, 4}的两个元素的子集
2. 对这些子集进行排序
第一步的子集的数量就是$\binom{4}{2}$, 第二步, 对于每一个子集的排序的数量, 其实就是permutations的计算方法: $2!$, 因为是每个子集都是2个元素, 所以:
$$P(4, 2) = \binom{4}{2}\cdot2!$$
所以:
$$\binom{4}{2} = \frac{P(4, 2)}{2!} = \frac{\frac{4!}{(4-2)!}}{2!} = \frac{4!}{(4-2)!2!} = 6$$

这个例子具有普遍性, 从而我们得到这样的一个定理:  
一个含有n个元素的set, 从中能挑出具有r个元素的subset(r-combinations)的数量, 记为$\binom{n}{r}$, 它具有这样的性质:
$$\binom{n}{r} = \frac{P(n, r)}{r!} = \frac{\frac{n!}{(n-r)!}}{r!} = \frac{n!}{r!(n-r)!}$$
n和r都是正整数, 且$r \le n$

### _9.6 r-combinations with Repetition Allowed

#### Definition

在上一章节介绍了r-combinations的概念, r-combinations里的元素是不重复的, 如果可以重复呢? 这就是r-combinations with repetition allowed的概念. 

还是举例子说明:  
一个set{1, 2, 3, 4}, 从中取3个元素, 它的r-combinations with repetition allowed有:  
[1,1,1];[1,1,2];[1,1,3];[1,1,4] all combinations with 1, 1  
[1,2,2];[1,2,3];[1,2,4];all additional combinations with 1, 2  
[1,3,3];[1,3,4];[1,4,4];all additional combinations with 1, 3 or 1, 4  
[2,2,2];[2,2,3];[2,2,4];all additional combinations with 2, 2  
[2,3,3];[2,3,4];[2,4,4];all additional combinations with 2, 3 or 2, 4  
[3,3,3];[3,3,4];[3,4,4];all additional combinations with 3, 3 or 3, 4  
[4,4,4]the only additional combination with 4, 4

如何计算呢? 下面的idea非常之精妙:  
我们把1,2,3,4之间加上分割符号, 1,2,3,4可以代表值为1,2,3,4的分类, 这样依次排开, 上面的穷举法里的例子就可以这样表示:  
| 1category | \|  | 2category | \|  | 3category | \|  | 4category | complete enumeration |
| ---       | --- | ---       | --- | ---       | --- | ---       | ---                  |
| ***       | *   |           | *   |           | *   |           | 111                  |
| *         | *   | **        | *   |           | *   |           | 122                  |
| *         | *   | *         | *   | *         | *   |           | 123                  |
我们可以理解为, 有123456个位置, 我们要从这6个位置中挑出3个位置, 来放置3个数字  
假如我们挑123位置, 那么相当于complete enumeration里的{1, 1, 1}  
假如我们挑134位置, 那么相当于complete enumeration里的{1, 2, 2}  
假如我们挑135位置, 那么相当于complete enumeration里的{1, 2, 3}  
...  
所以上面的例子里, 从4个数字里挑出3个数字, 数字允许重复, 那么有多少种选法呢?  
$$\binom{6}{3} = \frac{6!}{3!(6-3)!} = \frac{6\cdot5\cdot4\cdot3\cdot2\cdot1}{3\cdot2\cdot1\cdot3\cdot2\cdot1} = 20$$

我们可以归纳出, 一个含有n个元素的set, 从中能挑出r个元素的subset(r-combinations with repition allowed)的数量是:
$$\binom{r + n - 1}{r}$$

#### 从5种饮料中选出15瓶饮料

场景描述: 家里举行宴会, 计划买15瓶饮料, 楼下商店只有5种饮料, 请问:
1. 商店供应充足, 请问有多少种买法?  
  这个问题套用上面的公式就可以了:
  $$\binom{15 + 5 -1}{15} = \frac{19!}{15!(19-15)!} = 3876$$
2. 客人里有人要喝酒, 至少要买6瓶啤酒, 那么有几种买法呢?  
  我们可以理解为: 有15 + 5 -1 = 19个位置, 但是有6个位置已经被占用了, 所以计算方法是:
  $$\binom{(15 - 6) + (5 - 1)}{15-6} = \binom{13}{9} = 715$$
3. 商店里只有5瓶啤酒, 其他饮料货源充足, 请问有几种买法?  
  那么买6瓶啤酒以上的买法要被排除掉, 所以是上面两个问题的答案相减:
  $$N(R\le5) = N(T) - N(r\ge6) = 3876 - 715 = 3161$$
4. 如果必须买5瓶啤酒, 那么有几种买法?  
   其实就是从4种饮料中买10瓶饮料
   $$\binom{10 + 4 - 1}{10} = \binom{13}{10}$$