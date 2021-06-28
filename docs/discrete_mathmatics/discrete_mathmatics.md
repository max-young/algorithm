<!-- TOC -->

- [Chapter2 The logic of compound statements](#chapter2-the-logic-of-compound-statements)
  - [2.1 Logical Form and Logical Equivalence](#21-logical-form-and-logical-equivalence)
  - [2.2 Conditional Statements](#22-conditional-statements)
  - [2.3 Valid and Invalid Arguments](#23-valid-and-invalid-arguments)
  - [2.4 Application: Digital Logic Circuits](#24-application-digital-logic-circuits)
  - [2.5 Application: Number Systems and Circuits for Addition](#25-application-number-systems-and-circuits-for-addition)
- [Chapter3 The Logic of Quantified Statements](#chapter3-the-logic-of-quantified-statements)
  - [3.1 Predicates and Quantified Statements I](#31-predicates-and-quantified-statements-i)
  - [3.2 Predicates and Quantified Statements II](#32-predicates-and-quantified-statements-ii)
  - [3.3 Statements with Multiple Quantifiers](#33-statements-with-multiple-quantifiers)
- [Chapter4 Elementary Number Theory and Methods of Proof](#chapter4-elementary-number-theory-and-methods-of-proof)
  - [_4.1 Direct Proof and Counterexample I: Introduction](#_41-direct-proof-and-counterexample-i-introduction)
  - [_4.8 Applications: Algorithms](#_48-applications-algorithms)
- [Chapter 6 SET THEORY](#chapter-6-set-theory)
  - [6.1 Set Theory: Definition and the Element Method of Proof](#61-set-theory-definition-and-the-element-method-of-proof)
  - [6.4 Boolean Algebras, Russell's Paradox, and the Halting Problem](#64-boolean-algebras-russells-paradox-and-the-halting-problem)
- [Chapter 8 RELATIONS](#chapter-8-relations)
  - [8.1 Relation on Sets](#81-relation-on-sets)
  - [8.2 Reflexivity, Symmetry, and Transitivity自反性, 对称性, 传递性](#82-reflexivity-symmetry-and-transitivity自反性-对称性-传递性)
  - [8.3 Equivalence Relations](#83-equivalence-relations)
  - [8.4 Modular Arithmetic with Applications to Cryptopraphy模块化算法在密码学中的应用](#84-modular-arithmetic-with-applications-to-cryptopraphy模块化算法在密码学中的应用)
  - [8.5 Partial Order Relations偏序关系](#85-partial-order-relations偏序关系)
- [Chapter 12: Regular Expressions and Finite-State Automata](#chapter-12-regular-expressions-and-finite-state-automata)

<!-- /TOC -->

<a id="markdown-chapter2-the-logic-of-compound-statements" name="chapter2-the-logic-of-compound-statements"></a>
### Chapter2 The logic of compound statements

<a id="markdown-21-logical-form-and-logical-equivalence" name="21-logical-form-and-logical-equivalence"></a>
#### 2.1 Logical Form and Logical Equivalence

在此书中用~代表not, $\lor$代表or, $\land$代表and

- De Morgan's Laws

  The negation if an and statement is logically equicalent to the or statement in which each component is negated.

  The negation of an or statement is logically equivalent to the and statement in which each component is negated.

  也就是说:

  $$\lnot (p\land q) \equiv \lnot p \lor \lnot q$$

  $$\lnot (p\lor q) \equiv \lnot p \land \lnot q$$

- Tautologies and Contradictions

  A tautology is a statement form that is always true regardless of the truth values of the individual statement substituted for its statement variables. A statement whose form is a tautology is a taotulogical statement.

  A contradiction is a statement form that is always false regardless of the truth values of the individual statement substituted for its statment variables. A statement whose form is a contradictions is a contradictory statement.

  例如: $p \lor \lnot p$ 就是一个tautology, $p \land \lnot p$就是一个contradiction

  if t is a tautology and c is a contradiction, show that $p \wedge t \equiv p$ and $p \wedge c \equiv c$.

<a id="markdown-22-conditional-statements" name="22-conditional-statements"></a>
#### 2.2 Conditional Statements

- Conditional

  if *p* and *q* are statement variables, the conditional of *q* by *p* is **"If *p* then *q* "** or "*p* implies *q*" and is denoted $p\to q$ . It is false when *p* is true and *q* is false; otherwise it is true. We call *p* the hypothesis(or antecedent) of the conditional and *q* the conclusion(or consequent).

  True Table for $p\to q$

  | *p*  | *q*  | $p\to q$   |
  | :--: | :--: | :--------: |
  |  T   |  T   |     T      |
  |  T   |  F   |     F      |
  |  F   |  T   |     T      |
  |  F   |  F   |     T      |

​		这样我们能得出: $p \to q \equiv \neg p \lor q$

​		通俗的翻译是:

​		有这样一句话: 假如你做了某事A, 会得到某样东西B.

​		这句话的含义是, 你做了A, 肯定得到B, 如果你不做, 可能得到B也可能得不到B, 所以上面表格的意思就清楚了

- biconditional

  Given statement variable *p* and *q*, the biconditional of *p* and *q* is **"*p* if, and only if, *q*"** and is denoted $p\iff q$. It is true if both *p* and *q* have the same truth values and is false if *p* and *q* have opposite truth values. The words if and only if are sometimes abbreviated iff.

  True Table for $p\iff q$

  | *p*  | *q*  | $p\iff q$ |
  | :--: | :--: | :---------: |
  |  T   |  T   |      T      |
  |  T   |  F   |      F      |
  |  F   |  T   |      F      |
  |  F   |  F   |      T      |

​		通俗的翻译是:

​		有这样一句话: 假如你做了某事A, 会得到某样东西B.如果你不做A, 就得不到B. 所以上面表格的意思就清楚了

- Necessary and SufficientCOnditions

  If *r* and *s* are statements:

  ​	*r* is a sufficient condition for *s* means "if *r* then *s*."

  ​	*r* is a necessary condition for *s* means "if not *r* then not *s*."

  ​    *r* is a necessary condition for *s* also means "if *s* then *r*."

  ​	r is a necessary and sufficient condition for s means "r if, and only if, s."

<a id="markdown-23-valid-and-invalid-arguments" name="23-valid-and-invalid-arguments"></a>
#### 2.3 Valid and Invalid Arguments

An augument is a sequence of statements, nad an argument form is a sequence of statement forms. All statements in an argument and all statement forms in an argument form, except for the final one , are called **premise**(or assumptions or hypotheses). The final statement or statement form is called the **conclusion**. The symbol$\therefore$ , which is read "therefore", is normally placed just before the conclusion.

To say the argument form is **valid** means that no matter what particular statements are substituted for the statement variables in it's premises, if the resulting premises are all true, then the conclusion is also true. To say that argument is valid means that it's form is valid.
$$
p\to q \lor \neg r\\
q\to p \lor r\\
\therefore p \to r
$$

- Modus Ponens and Modus Tollens

  An argument form consisting of two premises and a conclusion is called a **syllogism**. The first and second premises are called the major premise and minor premise, respectively.

  The most famous form of syllogism in logic is called modus ponies. It has following form:
  $$
  If\ p\ then\ q. \\
  p \\
  \therefore q
  $$
  the term modus ponens is Ladin meaning "method of affirming"(the conclusion is an affirmation)

  modus tollens has the following form:
  $$
  If\ p \ then \ q. \\
  \neg q \\
  \therefore \neg p
  $$
  Modus tollens is Latin meaning "method of denying"

- Fallacies

  For an argument to be valid, every argument of the same form whose premises are all true must have a true conclusion. It follows that for an argument to be invalid means that there is an argument of that form whosr premises are all true and whose conclusion is false.

- Contradictions and Valid Arguments

  Contradiction Rule:

  If you can show that supposition that statement *p* is false leads logically to a contradiction, then you can conclude that *p* is true.
  $$
  \neg p \to c \\
  \therefore p
  $$
  

<a id="markdown-24-application-digital-logic-circuits" name="24-application-digital-logic-circuits"></a>
#### 2.4 Application: Digital Logic Circuits

 这一章的内容主要讲与非门, 在《[编码](https://book.douban.com/subject/4822685/)》这本书里有度过, 就不详细去读啦, 

<a id="markdown-25-application-number-systems-and-circuits-for-addition" name="25-application-number-systems-and-circuits-for-addition"></a>
#### 2.5 Application: Number Systems and Circuits for Addition

这一章也在《[编码](https://book.douban.com/subject/4822685/)》里看过, 主要讲二进制

<a id="markdown-chapter3-the-logic-of-quantified-statements" name="chapter3-the-logic-of-quantified-statements"></a>
### Chapter3 The Logic of Quantified Statements

<a id="markdown-31-predicates-and-quantified-statements-i" name="31-predicates-and-quantified-statements-i"></a>
#### 3.1 Predicates and Quantified Statements I

In grammar, the word *predicate* refers to the part of a sentence that gives information about the subject. In the sentence “James is a student at Bedford College,” the word *James* is the subject and the phrase *is a student at Bedford College* is the predicate. The predicate is the part of the sentence from which the subject has been removed.

- The Universal Quantifier: $\forall$

  One sure way to change predicates into statements is to assign specific values to all their variables. For example, if *x* represents the number 35, the sentence “*x* is (evenly) divis- ible by 5” is a true statement since 35 = 5·7. Another way to obtain statements from predicates is to add **quantifiers.** Quantifiers are words that refer to quantities such as “some” or “all” and tell for how many elements a given predicate is true

  The symbol ∀ denotes “for all” and is called the **universal quantifier.** For example, another way to express the sentence “All human beings are mortal” is to write

  ∀ human beings *x* , *x* is mortal.

- **The Existential Quantifier:** $\exists$

  The symbol ∃ denotes “there exists” and is called the **existential quantifier.** For example,

  the sentence “There is a student in Math 140” can be written as
   ∃ a person *p* such that *p* is a student in Math 140,

  or, more formally,

  ∃*p* ∈ *P* such that *p* is a student in Math 140,

  where *P* is the set of all people.

<a id="markdown-32-predicates-and-quantified-statements-ii" name="32-predicates-and-quantified-statements-ii"></a>
#### 3.2 Predicates and Quantified Statements II

- Negations of Quantified Statements

  Consider the statement “All mathematicians wear glasses.” Many people would say that its negation is “No mathematicians wear glasses,” but if even one mathematician does not wear glasses, then the sweeping statement that *all* mathematicians wear glasses is false. So a correct negation is “There is at least one mathematician who does not wear glasses.”

  **The negation of a universal statement (“all are”) is logically equivalent to an existential statement (“some are not” or “there is at least one that is not”).**

  **The negation of an existential statement (“some are”) is logically equivalent to a universal statement (“none are” or “all are not”).**

- Negations of Universal Conditional Statements

  ∼(∀*x*, *P*(*x*) → *Q*(*x*)) ≡ ∃*x* such that ∼(*P*(*x*) → *Q*(*x*))

  ∼(*P*(*x*) → *Q*(*x*)) ≡ *P*(*x*) ∧ ∼*Q*(*x*)

  ∼(∀*x*, *P*(*x*) → *Q*(*x*)) ≡ ∃*x* such that (*P*(*x*)∧ ∼*Q*(*x*))

<a id="markdown-33-statements-with-multiple-quantifiers" name="33-statements-with-multiple-quantifiers"></a>
#### 3.3 Statements with Multiple Quantifiers

many important technical statements contain both ∃ and ∀, a convention has developed for interpreting them uniformly. When a statement contains more than one quantifier, we imagine the actions suggested by the quantifiers as being performed in the order in which the quantifiers occur. For instance, consider a statement of the form

∀*x* in set *D*, ∃*y* in set *E* such that *x* and *y* satisfy property *P*(*x*, *y*)

- Negations of Multiply-Quantified Statements

  You can use the same rules to negate multiply-quantified statements that you used to negate simpler quantified statements. Recall that

  ∼(∀*x* in *D*, *P*(*x*)) ≡ ∃*x* in *D* such that ∼*P*(*x*).

  and

  ∼(∃*x* in *D* such that *P*(*x*)) ≡ ∀*x* in *D*,∼*P*(*x*).

   We apply these laws to find

  ∼(∀*x* in *D*,∃*y* in *E* such that *P*(*x*, *y*))

   by moving in stages from left to right along the sentence.

  First version of negation:* ∃*x* in *D* such that ∼(∃*y* in *E* such that *P*(*x*, *y*)).

   *Final version of negation:* ∃*x* in *D* such that ∀*y* in *E*, ∼*P*(*x*, *y*).

  Similarly, to find

  ∼(∃*x* in *D* such that ∀*y* in *E*, *P*(*x*, *y*)),

  we have

  ∼(∃*x* in *D* such that ∀*y* in *E*, *P*(*x*, *y*)),

  *First version of negation:* ∀*x* in *D*, ∼(∀*y* in *E*, *P*(*x*, *y*)).

  *Final version of negation:* ∀*x* in *D*, ∃*y* in *E* such that ∼*P*(*x*, *y*).

<a id="markdown-chapter4-elementary-number-theory-and-methods-of-proof" name="chapter4-elementary-number-theory-and-methods-of-proof"></a>
### Chapter4 Elementary Number Theory and Methods of Proof

基础数学理论和证明方法, 序言相当棒, 数学和逻辑的魅力展露无遗

<a id="markdown-_41-direct-proof-and-counterexample-i-introduction" name="_41-direct-proof-and-counterexample-i-introduction"></a>
#### _4.1 Direct Proof and Counterexample I: Introduction

- **Definitions**

  我们知道偶数是能被2整除, 奇数不能被2整除. 这是我们被“教育”的概念, 我们再来看看能够展现数学和逻辑的魅力的定义:

  An integer *n* is **even** if, and only if, *n* equals twice some integer. An integer *n* is **odd**

  if, and only if, *n* equals twice some integer plus 1.

  Symbolically, if *n* is an integer, then
  $$
  n\ is\ even \iff \exists\ an\ integer\ k\ such\ that\ n=2k\\
  n\ is\ odd \iff\ an\ integer\ k\ such\ that\ n=2k+1
  $$
  
- Proving Existential Statements

  ∃*x* ∈ *D* such that *Q*(*x*)

  我们要证明上面的statement, 我们可以在D集合里面找到一个元素, 来满足合格条件, 这种证明方法叫**constructive proofs of existence**

  或者我们通过理论证明D集合里面没有元素满足要求, 这种证明方法叫 **nonconstructive proof of existence**

- **Disproving Universal Statements by Counterexample**

  To disprove a statement of the form “∀*x* ∈ *D*, if *P*(*x*) then *Q*(*x*),” find a value of *x* in *D* for which the hypothesis *P*(*x*) is true and the conclusion *Q*(*x*) is false. Such an *x* is called a **counterexample.**

<a id="markdown-_48-applications-algorithms" name="_48-applications-algorithms"></a>
#### _4.8 Applications: Algorithms

- Division Algorithm

  如果我们不用计算机内置的除法, 怎么实现除法的算法呢?

  $$a=d \times q + r$$

  这里q是商数quotient, r是余数remainder, 我们要实现求得q和r的算法.

  余数r应该满足$0\leq r < d$ , 我们可以用a减去d, 一直减, 一直到剩下的值小于d, 最后, 减的次数就是q, 剩余的值就是r

  ```
  伪代码:
  Input: a[a nonnegative number], d[a positive number]
  Algorithm Body:
  q = 0, r = a
  a一只减b, 一直到r<d
  while (r>=d)
      r = r - d 
      q = q + 1
  end while
  while运行结束之后, a = b*q + r
  Output: q, r
  ```

- The Euclidean Algorithm

  求两个证书的最大公约数greatest common divisor, 最大公约数的定义是

  Let *a* and *b* be integers that are not both zero. The **greatest common divisor** of *a*

  and *b*, denoted **gcd**(**a**, **b**), is that integer *d* with the following properties: 

  1. *d* is a common divisor of both *a* and *b*. In other words,

  *d*|*a* and *d*|*b*.

  2. For all integers *c*, if *c* is a common divisor of both *a* and *b*, then *c* is less than or

  equal to *d*. In other words,

  for all integers*c*,if *c*|*a* and *c*|*b*,then*c* ≤ *d*.

  有两个推论:

  1. If *r* is a positive integer, then gcd(*r*, 0) = *r* .

  2. If *a* and *b* are any integers not both zero, and if *q* and *r* are any integers such that *a* = *bq* + *r*, then

     $gcd(a, b) = gcd(b, r)$  
     $a = b\times q + r$  
     假设c是a和b的最大公约数, 那么$a=c\times m, b=c\times n$  
     $c\times m = c\times n \times q + r$  
     $r = c\times m - c\times n \times q$  
     $r = (m - n\times q)\times c$  
     这样c也是r的约数, c是a和b的最大公约数, c又是b和r的约数, 那么c小于等于b和r的最大公约数.也就是:  
     $gcd(a, b) <= gcd(b, r)$  
     下面我们再来证明b和r的最大公约数小于等于a和b的最大公约数  
     假设c是b和r的最大公约数, 那么$b=c\times m, c=c\times n$  
     $a = c\times m \times q + c\times n$  
     $a = (m\times q + n)\times c$  
     这样c也是a的余数, c是b和r的最大公约数, c又是a和b的约数, 那么c小于等于a和b的最大公约数.也就是:  
     $gcd(b, r) <= gcd(a, b)$  
     从而得到$gcb(a, b)=gcb(b, r)$

  上面的证明对求两个正整数的最大公约数有什么关系呢? 

  如果没有上面的证明, 我们大概想到的方法就是穷举Exhaustion, 从2一直循环到最小的那个数, 对于数量较小的两个数还可行, 如果数字足够大, 那将相当耗费资源.

  如果我们利用上面的证明, 就能大幅提高计算速度.

  伪代码:  
  ```
  Input: A, B[integers with A > B >= 0]  
  Output: gcd  
  Algorithm Body:  
    a = A, b = B  
    如果b != 0, 计算a mod b, 得到余数r, 替换a=b, b=r. 重复这个过程  
    while(b != 0):  
      r = a mod b  
      a = b  
      b = r  
    end while  
    gcd = a  
  ``````

<a id="markdown-chapter-6-set-theory" name="chapter-6-set-theory"></a>
### Chapter 6 SET THEORY

<a id="markdown-61-set-theory-definition-and-the-element-method-of-proof" name="61-set-theory-definition-and-the-element-method-of-proof"></a>
#### 6.1 Set Theory: Definition and the Element Method of Proof

If S is a set and P(x) is a property that element of S may or may not satisfy, then a set A may be defined by writing:

$$A = \{ x \in S | P(x) \}$$

which is read "The set of all x in S such that P of x"

- Subsets

  $$A \subseteq B \iff \forall x,\ if\ x \in A\ then\ x \in B$$

  $$A \not\subseteq B \iff \exists x,\ x \in A\ and\ x \notin B $$

  $$
  \begin{align*}
  &A\ is\  proper\ subset\ of\ B \iff \\
  &(1) A \subseteq B, and\\
  &(2) there\ is\ at\ least\ one\ element\ in\ B\ that\ is\ not\ in\ A.
  \end{align*}
  $$
  
- Set Equality

  $$A = B \iff A \subseteq B\ and\ B \subseteq A$$

- Operations on Sets

  the set of real numbers would be called a **universal set** or a **universe of discourse**

  Let A and B be sbubsets of a universal set U.

  1. The **uninon** of A and B, denoted $A \cup B $, is the set of all elements that are in at least one of A or B.
  2. The **intersection** of A and B, denoted $A \cap B$, is the set of all elements that are common to both A and B.
  3. The **difference** of B minus A (or **relative complement** of A in B), denoted $B - A$, is the set of all elements that are in B and not A.
  4. The **complement** of A, denoted $ A^{c}$ , is the set of all elements in U that are not in A.

  Symbolically:
  $$
  \begin{align*}
  A \cup B &= \{x \in U | x \in A \ or\ x \in B\} \\
  A \cap B &= \{x \in U | x \in A \ and\ x \in B\} \\
  B - A &= \{x \in U | x \in B \ and\ x \notin A \} \\
  A^{c} &= \{x \in U | x \notin A \}
  \end{align*}
  $$
  
- The empty Set

  We call it the **empty set** (or **null set**) and denote it by the symbol $\emptyset$ . Thus $\{1, 3\} \cap \{2, 4\} = \emptyset$ and $\{x \in R | x^2 = -1\} = \emptyset$

- Partition of Sets

  Two sets are called **disjoint** if, and only if, they have no elements in common. Symbolically: 
  $$
  A\ and\ B\ are\ disjoint \iff A \cap B = \emptyset
  $$
  
- Power Set

  Given a set A, the **power set** of A, denoted $\mathcal{P}(A)$, is the set of all sub sets of A
  $$
  \mathcal{P}(\{x, y\}) = \{\emptyset, \{x\}, \{y\}, \{x, y\}\}
  $$
  
- Cartesian Products

  笛卡尔积

  Given sets $A_1, A_2, ..., A_n$, the **Cartesian product** of $A_1, A_2, ..., A_n$ denoted $A_1 \times A_2 \times ... \times A_n$, is the set of all ordered n-tuples $(a_1, a_2, ..., a_n)$ where $a_1 \in A_1, a_2 \in A_2, ..., a_n \in A_n$. 

  Symbolically: 
  $$
  A_1 \times A_2 \times ... \times A_n = \{(a_1, a_2, ..., a_n | a_1 \in A_1, a_2 \in A_2, ..., a_n \in A_n \}
  $$
  
  
  In particular,
  $$
  A_1 \times A_2 = \{(a_1, a_2) | a_1 \in A_1\ and\ a_2 \in A_2\}
  $$
  is the Cartesian product if $A_1$ and $A_2$.

<a id="markdown-64-boolean-algebras-russells-paradox-and-the-halting-problem" name="64-boolean-algebras-russells-paradox-and-the-halting-problem"></a>
#### 6.4 Boolean Algebras, Russell's Paradox, and the Halting Problem

- Boolean Algebras

  不太能理解

- Russell's Paradox

  很有趣的一个Paradox:

  In a certain town there is a male barber who shaves all those men, and only those men, who do not shave themselves. *Question:* Does the barber shave himself?

- The Halting problem

  太抽象, 看不懂. 大概是说计算机算法不会得出halting或者永远循环的输出. 和上面的悖论相关.

<a id="markdown-chapter-8-relations" name="chapter-8-relations"></a>
### Chapter 8 RELATIONS

<a id="markdown-81-relation-on-sets" name="81-relation-on-sets"></a>
#### 8.1 Relation on Sets

最后讲数据库很形象

<a id="markdown-82-reflexivity-symmetry-and-transitivity自反性-对称性-传递性" name="82-reflexivity-symmetry-and-transitivity自反性-对称性-传递性"></a>
#### 8.2 Reflexivity, Symmetry, and Transitivity自反性, 对称性, 传递性

书中用了这样的一个Relation做例子:

$A=\{2, 3, 4, 6, 7, 9\}$, for all $x, y \in A$,

$x\ R\ y \iff 3|(x-y)$

备注: $3|(x-y)$表示$x-y$能被3整除

这里能根据Relation画出图来, 看书吧

我们定义出Relation的3种特性::

1. Reflexive: $R$ is reflexive if, and only if, for all $x \in A, x\ R\ x$
2. symmetric: $R$ is symmetric if, and only if, for all $x, y \in A, if\ x\ R\ y\ then\ y\ R\ x$
3. Transitive: $R$ is transitive if, and only if, for all $x, y, z \in A, if\ x\ R\ y\ and\ y\ R\ z\ then\ x\ R\ z$

<a id="markdown-83-equivalence-relations" name="83-equivalence-relations"></a>
#### 8.3 Equivalence Relations

Let *A* be a set and *R* a relation on *A*. *R* is an **equivalence relation** if, and only if, *R*

is reflexive, symmetric, and transitive.

<a id="markdown-84-modular-arithmetic-with-applications-to-cryptopraphy模块化算法在密码学中的应用" name="84-modular-arithmetic-with-applications-to-cryptopraphy模块化算法在密码学中的应用"></a>
#### 8.4 Modular Arithmetic with Applications to Cryptopraphy模块化算法在密码学中的应用

<a id="markdown-85-partial-order-relations偏序关系" name="85-partial-order-relations偏序关系"></a>
#### 8.5 Partial Order Relations偏序关系

<a id="markdown-chapter-12-regular-expressions-and-finite-state-automata" name="chapter-12-regular-expressions-and-finite-state-automata"></a>
### Chapter 12: Regular Expressions and Finite-State Automata

正则表达式、有限状态机......应用到的时候再看吧