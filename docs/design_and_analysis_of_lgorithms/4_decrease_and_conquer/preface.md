decrease-and-conquer技术是建立给定实例的解决方案与较小实例的解决方案之间的关系. 这样就可以top-down自上而下或bottom-up自下而上地加以利用.  
前者可以用递归实现，后者通常以迭代方式实现，从解决问题的最小实例开始.  
这个方法有时被称为incremental approach.

decrease and conquer有三种形式:
- decrease by constant
- decrease by constant factor
- variable size decrease

我们分别来说明:  

**decrease by constant**是指按一个固定的数量减小问题的规模. 这个数量通常是1.  
例如计算$a^n$, 我们发现$a^n = a^{n-1} \cdot a$.   
所以我们如果用top down的方式, 就可以用recursive来解决:  
$$
f(n) = \left\{
  \begin{aligned}
  &f(n-1) \cdot a\ &if\ n \gt 0 \\
  &1\ &if\ n = 0
  \end{aligned}
\right.
$$ 
也可以用bottom up的方式, 用iterative来解决, 用1乘以$n$次$a$.  
这两个算法的效率是$\Theta(n)$  
注: 这个方法好像也brute force一样? 是的, 但是思维方式不一样.

**decrease by a constant factor**是按一个固定的常数因子来减小问题的规模. 如何理解? 还是上面的例子.  
$a^n = (a^{n/2})^2$. top down的方式, 每次减少一半, 这就叫decrease by a constant factor. 这里要注意一下n是奇数的情况. 用recursive的方式表达:
$$
a^n = \left\{
  \begin{array}{ll}
  (a^{n/2})^2 &if\ n\ is\ even\\
  (a^{(n-1)/2})^2 \cdot a &if\ n\ is\ odd \\
  1 &if\ n = 0
  \end{array}
\right.
$$ 
这个算法的效率是$\Theta(\log n)$

**variable size decrease**是指decrease的大小和上一个循环相关, 比如:
$$gcd(m, n) = gcd(n, m\ mod\ n)$$