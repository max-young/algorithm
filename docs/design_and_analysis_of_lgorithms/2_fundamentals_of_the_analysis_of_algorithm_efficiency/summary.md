- 算法效率有两种: 时间效率和空间效率
- 算法的时间效率主要通过一个输入大小作为参数, 计算basic operation的执行次数的函数来表示. basic operation是指算法里对运行时间贡献最大的操作, 通常是在loop循环里.
- 一些算法的运行时间在不同的输入大小的情况下可能差别很大, 所以我们可能需要分析best-case效率, worst-case效率, average-case效率
- 算法效率分析的框架是随着输入大小的增大, 运行时间增长的order阶
- 符号$O$, $\Omega$, $\Theta$可以用来表示增长的order阶
- 算法的效率可以归类为: constant常量(1), logarithmic对数($\log n$), linear线性(n), linearithmic($n\log n$), quadratic二次方($n^2$), cubic三次方($n^3$), exponential指数($2^n$), factorial($n!$)
- nonrecursive algorithm的分析主要是计算basic operation的sum, 然后得到其order
- recursive algorithm的分析是确定basic operation执行次数的递归表示, 然后计算其order
- recursive algorithm的间接性可能会掩盖其低效率
- 有多种fibonacci算法, 其效率也大相径庭
- 对算法的经验分析是通过输入样本运行算法并分析观察到的数据(基本操作的计数或物理运行时间). 这通常涉及生成伪随机数. 对任何算法的适用性是这种方法的主要优势, 但结果对特定设备和样本的依赖性是其主要弱点。不同的设备和不同的样本可能结果会差很多.
- 算法可视化是使用图像来传达关于算法的有用信息。算法可视化的两个主要形式是静态算法的可视化和动态算法的可视化(也称为算法动画).