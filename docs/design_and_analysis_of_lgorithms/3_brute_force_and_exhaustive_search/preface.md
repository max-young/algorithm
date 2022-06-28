上一章节讲到了算法效率分析的框架和方法. 这里讲算法的设计策略.  
本章讲brute force蛮力以及其中的一个重要特例: exhausitive search穷举查找.  

brute force是一种很直接的解决问题的方法, 通常直接基于问题陈述或者其涉及的定义.
brute force通常是最容易应用的策略.

brute force可能不是聪明和高效的解策略, 但是它也有其优点:
1. 其应用非常广泛, 很难找出其不能解决的问题.
2. 对于一些重要的问题, 例如，排序、搜索、矩阵乘法、字符串匹配, brute force至少是一种有实用价值的方法。
3. 如果问题的数量很少，并且brute force的效率可接受，那么设计更有效的算法可能是不合理的。
4. brute force可以服务于理论或教育目的，作为衡量解决问题的更有效替代方案的标准