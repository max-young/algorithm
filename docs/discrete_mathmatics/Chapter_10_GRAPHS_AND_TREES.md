<!-- TOC -->

- [Chapter 10 GRAPHS AND TREES 图和树](#chapter-10-graphs-and-trees-图和树)
  - [_10.1 Graphs: Definitions and Basic Properties](#_101-graphs-definitions-and-basic-properties)
    - [definition](#definition)
    - [一些特殊的Graph:](#一些特殊的graph)
    - [Degree](#degree)
  - [_10.2 Trails, Paths, and Circuits](#_102-trails-paths-and-circuits)
    - [Königsberg bridge](#königsberg-bridge)
    - [definition](#definition-1)
    - [Connectedness](#connectedness)
    - [Euler Circuits](#euler-circuits)
    - [Hamiltonian Circuits](#hamiltonian-circuits)
  - [_10.5 Trees 树](#_105-trees-树)
    - [Tree的定义](#tree的定义)
    - [Characterizing Trees树的特点](#characterizing-trees树的特点)
  - [_10.6 Rooted Trees](#_106-rooted-trees)
    - [定义](#定义)
    - [Binary Trees](#binary-trees)
  - [_10.7 Spanning Trees and Shortest Paths](#_107-spanning-trees-and-shortest-paths)
    - [Spanning Trees](#spanning-trees)
    - [Minimum Spanning Trees](#minimum-spanning-trees)
      - [weighted graph](#weighted-graph)
      - [Kruskal Algorithm](#kruskal-algorithm)
      - [Prim Algorithm](#prim-algorithm)
      - [Dijkstra Shortest Path Algorithm](#dijkstra-shortest-path-algorithm)

<!-- /TOC -->

<a id="markdown-chapter-10-graphs-and-trees-图和树" name="chapter-10-graphs-and-trees-图和树"></a>
## Chapter 10 GRAPHS AND TREES 图和树

<a id="markdown-_101-graphs-definitions-and-basic-properties" name="_101-graphs-definitions-and-basic-properties"></a>
### _10.1 Graphs: Definitions and Basic Properties


<a id="markdown-definition" name="definition"></a>
#### definition

A **graph** G consists of two finite sets: a nonempty set V(G) of **vertices**(顶点) and a set E(G) of **edges**(边), where each edge is associated with a set consisting of either one or two vertices called it‘s **endpoints**. The correspondence from edges to endpoints is called the **edge-endpoint function**.  
An edge with just one endpoint is called a **loop**, and two or more distinct edges with the same set of endpoints are said to be **parallel**. An edge is said to connect it‘s endpoints; two vertices that are connected by an edge are called **adjacent**; and a vertex that is an endpoint of a loop is said to be adjacent to itself.  
An edge is said to be **incident** on each of it's endpoints, and two edges incident on the same endpoint are called adjacent. A vertex on which no edges are incident is called **isolated**.

举例说明:  
<img src="./_images/graph_definition.png" width=50%>  
- $e_1, e_2, e_3$ are incident on $v_1$
- $v_2$ and $v_3$ are adjacent to $v_1$
- $e_2, e_3, e_4$ are adjacent to $e_1$
- $e_6$ and $e_7$ are loops
- $e_2$ and $e_3$ are parallel
- $v_5$ and $v_6$ are adjacent to themselves
- $v_4$ is an isolated vertex

Graph可以用可视化的图片(pictorial representation)表示, 也可以用vertex set、edge set和edge-endpoint function表示, 比如这个图可以这么表示:  
vertex set = {$v_1, v_2, v_3, v_4, v_5, v_6$}  
edge set = {$e_1, $e_2, $e_3, e_4, e_5, e_6, e_7$}  
edge-endpoint function:

| Edge | Endpoints |
| --- | --- |
| $e_1$ | {$v_1, v_2$} |
| $e_2$ | {$v_1, v_3$} |
| $e_3$ | {$v_1, v_3$} |
| $e_4$ | {$v_2, v_3$} |
| $e_5$ | {$v_5, v_6$} |
| $e_6$ | {$v_5$} |
| $e_7$ | {$v_6$} |

edge-endpoint function里不包含$v_4$, 因为它是isolated vertex, 在vertex set里表示就可以了  
同时, 我们也可以了解到, 一个可视化的图片表示可以决定一个图形, 但是一个vertex set、edge set和edge-endpoint function的表示, 可以画出多种可视化图片, 因为edge的弧度, vextex的相对位置都是可以变化的.  

这里说的graph是普通graph(ordinnary graph), 还有有向graph(directed graph), 指的是edge-endpoint function里的endpoint是有序的.

图可以解决很多问题, 数中列举了网络、知识图谱、还有一个很有意思的问题: 素食者和食人族

#### 一些特殊的Graph:

- simple graph  
  simple graph是指没有loop和parallel的graph.  
  因为这个特性, 用两个endpoint就能就能表示一条edge. 例如一条edge的endpont是v和w, 那么这条edge可以表示为{v, w}
- complete graph
  一个包含n个vertices的complete graph可以表示为$K_n$, 它是一个simple graph, 并且每一对vertices都有且只有一条edge相连.  
  例如$K_1, K_2, K_3, K_4, K_5$可以这么表示:  
  <img src="./_images/complete_graph.png" width=50%>
- complete bipartite graph  
  我把定义抄下来, 英文表达更准确:  
  Let m and n be positive integers.A complete bipartite graph on (m,n) vertices, denoted $K_{m,n}$, is a simple graph with distinct  vertices $v_1, v_2, ..., v_m$ and $w_1, w_2, ..., w_n$ that satisfies the following properties: For all i, k = 1, 2, ..., m and for all j, l = 1, 2, ..., n,  
  1. There is an edge from each vertex $v_i$ to each vertex $w_j$.
  2. There is no edge from any vertex $v_i$ to any other vertex $v_k$.
  3. There is no edge from any vertex $w_j$ to any other vertex $w_l$.  
  
  通俗的说: 一个grah的vertices分成两部分, 这两部分里的点各自都不相连, 但是这两部分的点互相相连, 举例说明$K_{3, 2}$和$K_{3, 3}$:  
  <img src="./_images/complete_bipartite_graph.png" width=50%>  
- subgraph
  一个graph H是另一个graph G的subgraph, 那么H的所有vertex也都是G的vertex, H的所有edge也是G的edge, 并且endpoints都是一样的

<a id="markdown-degree" name="degree"></a>
#### Degree

**定义**  
G是一个图, v是其中一个顶点, v的degree表示为deg(v), 指以v为起点的边的数量, 如果边是一个环loop, 那么计数2, G的degree是所有顶点的degree之和  

举例说明:  
<img src="./_images/graph_degree.png" width=50%>  
v1的dgree是0, v2的degree是2, v3的degree是4, 这个图的degree是6

The handshake Theorem:  
一个graph G, G的所有vertices的degree之和(也就是G的degree)是G的edge数量的两倍.  
为什么叫handshake theorem呢, 因为可以把graph想像成一个舞会, 相互握手, 一次握手, 握手的两个人都会增加一个degree, 所以成为handshake theorem  

根据这个定理我们得到推论: graph的total degree是偶数(even)  
我们还能得到推论: 如果一个graph里有n的vertices是奇数(odd)degree, 那么n是偶数(even)



<a id="markdown-_102-trails-paths-and-circuits" name="_102-trails-paths-and-circuits"></a>
### _10.2 Trails, Paths, and Circuits

<a id="markdown-königsberg-bridge" name="königsberg-bridge"></a>
#### Königsberg bridge  
这里举了一个经典的例子: Königsberg bridge, 如图所示:  
<img src="./_images/konigsberg_bridges.png" width=800px>  
这个城镇有一条河, 七座桥, 如果从ABCD中的其中一个区域出发, 回到这个区域, 但是要经过所有的七座桥且不能重复  

我们可以把问题简化成一个graphic:  
<img src="./_images/konigsberg_bridges_graphic.png" width=40%>  
答案: 无解  
证明:   
假设我们从A出发, 那么我们通过BCD的时候都需要到达并且离开, 不管多少次, 到达和离开的总次数都是偶数(也就是BCD顶点的边都应该是偶数), 但是B的edge是5, C和D的edge是3  
从其他的点出发, 也是同样的, 所以这题无解

<a id="markdown-definition-1" name="definition-1"></a>
#### definition

G是一个Graph, v、w是两个顶点, 从v走到w:  
如果没有重复走一条边, 则叫**trail**  
没有走重复的顶点, 则叫**path**  
如果v和w是同一个点, 则叫**closed walk**  
一个closed walk, 如果至少包括一条边, 且不重复, 则是**circuit**  
一个circuit, 除了起点和终点重复, 没有其他的重复的顶点, 则称为**simple curcuit**  

这里举一个例子来说明上面的定义:  
<img src="./_images/graph_walk_definition.png" width=50%>  
有这样几条线路:  
a. v1e1v2e3v3e4v3e5v4: 这是trail, 因为没有重复的边  
b. e1e3e5e5e6: 这是普通的walk, 既有重复边又有重复顶点  
c. v2v3v4v5v3v6v2: 这是circuit, 首尾是同一个点, 因为有重复顶点, 所以不是simple circuit  
d. v2v3v4v5v6v2: 这是simple circuit, 首尾是同一个点, 没有重复边和顶点  
e. v1e1v2e1v1: 这是closed walk, 因为有重复边  
f. v1: 这是closed walk, 也是trail

<a id="markdown-connectedness" name="connectedness"></a>
#### Connectedness

定义:  
G是一个graph, 两个顶点v和w存在walk, 那么它们connected. 如果G的任意两个顶点都存在walk, 那么G是connected:  
$$G\ is\ connected \iff \forall\ verticles\ v,w \in V(G), \exists\ a\ walk\ from\ v\ to\ w $$

**connected component**  
图H如果是图G的connected component, 那么必须满足:  
1. H是G的子图subgraph  
2. H是connected  
3. G不存在另外一个子图, 包括H, 且还有H没有的顶点和边  

举例说明:  
<img src="./_images/connected_component.png" width=50%>  
这个图包含3个connected component: v1v2v3, v4, v5v6v7v8  

<a id="markdown-euler-circuits" name="euler-circuits"></a>
#### Euler Circuits

定义:  
G是一个图, G的Euler Circuits是一个包含G的所有顶点和边的circuit. Euler Circuit至少包含一条边, 首尾是同一个点, 每个顶点至少通过一次, 每条边只能通过一次

我们可以回想到Königsberg bridge的问题, 有这样一个定理:  
如果一个图有Euler circuit, 那么这个图的所有顶点的degree是偶数even  
我们可以朴素的想见这个定理是正确的, 因为进入一个顶点和离开一个顶点是成对的.  
我们也可能得到:  
如果一个图有顶点的degree是奇数odd, 那么这个图没有Euler Circuit 

那么如果一个图的所有顶点的degree都是even, 那么就存在于euler circuit吗? 答案是不能, 比如下图:  
<img src="./_images/even_degree_graph_not_have_euler_circuit.png" width=50%>  
我们很容易看出, 因为这个图不是connected, 所以不存在euler circuit, 存在这样的定理:  
如果一个图G是connected, 并且每个顶点的degree都是positive even integer, 那么这个图存在euler circuit. 证明详见教材. 这个证明方法也可以用来寻找一个图的Euler Circuit.  
引申的定理: 如果一个图有euler circuit, 那么这个图必须是connected, 并且顶点都是positive even integer

有euler circuit, 也有euler trail, 和euler circuit的定义一样, 必须通过所有顶点至少一次, 通过所有的边仅一次, 只是起始点不同.  
推论: 如果一个图G的两个不同的顶点v和w存在euler trail, 这个这两个顶点的degree是positive odd integer, 其他顶点的degree是positive even integer. 证明和上面类似.  

<a id="markdown-hamiltonian-circuits" name="hamiltonian-circuits"></a>
#### Hamiltonian Circuits

上一节的定理解决了如何找到一个通过所有边一次的circuit, 我们能不能找到只通过所有顶点一次的circuit呢?

定义:  
一个图G, Hamiltniann circuit是指一个simple circuit(还记得定义吗, 只有起始点重复, 其他点不能重复), 通过G的所有顶点一次, 除了起始点, 还有, 边不重复(但不要求通过所有边).  

如果一个至少有两个顶点的图G存在Hamiltonian circuit, 这个circuit这么表示:
$$C: v_0e_1v_1e_2...v_{n-1}e_nv_n$$
$e_i$是distinct, $v_j$除了$v_0=v_n$其他都是distinct, 这条circuit组成了G的一个subbgraph H, 不难看出, H的顶点数和边数是相同的, H的顶点数和G的顶点数一样, 顶点的degree必须大于2. 总结如下:  
如果一个graph G有Hamiltonian circuit, 那么G必须存在一个subgraph H满足下面的条件:  
1. H包含G的所有顶点
2. H是connected
3. H的顶点数和边数相等
4. H的所有顶点的degree是2
如果不满足这个条件, 那么这个图也不存在hamiltonian circuit

举例说明:  
<img src="./_images/hamiltonian_circuit.png" width=50%>  
这个图是否存在hamiltonian circuit呢? 我们按照上面的定理来推导:  
我们找到一个subgraph, 包含abcde这5个顶点, 且是connected, 满足了上面的1、2两个条件, 我们尝试满足第3、4个条件, acde的edge都是2, b现在有4个edge, 我们去掉一个试试, 会发现无论去掉b的哪一条edge, 都会让另一个端点的degree变成1, 所以这个graph不存在hamiltonnian circuit  

另外一个有意思的问题: A travelling salesman problem  
<img src="./_images/a_travelling_salesman_problem.png" width=50%>  

ABCD4座城市和距离, 从A出发, 经过所有城市1次, 回到A, 这是一个hamiltonian circuit的问题, 对于顶点较少的情况, 我们可以一一列举:  

| route | distance                |
| ---   | ---                     |
| ABCDA | 30 + 30 + 25 + 40 = 125 |
| ABDCA | 30 + 35 + 25 + 50 = 140 |
| ACBDA | 50 + 30 + 35 + 40 = 155 |
| ACDBA | ABDCA相反           140 |
| ADBCA | ACBDA相反           155 |
| ADCBA | ABCDA相反           125 |

最佳方案是ABCDA或者ADCBA  
对于顶点数多的情况, 一一列举就非常耗时了. 很遗憾, 现在还没有很有效率的算法来解决这个问题.  
只有有效率的算法能求得相对更好的路径. 

<a id="markdown-_105-trees-树" name="_105-trees-树"></a>
### _10.5 Trees 树

#### Tree的定义

树其实是一种特殊的图
> A graph is said to be circuit-free if, and only if, it has no circuits. A graph is called a tree if, and only if, it is circuit-free and connected. A trivial tree is a graph that consists of a single vertex. A graph is called a forest if, and only if, it is circuit-free and not connected.

tree是没有circuit的graph, 并且是connected, 如果不是connected, 那么就是forest

一些tree的例子, 很有意思:
- A Decision Tree
- A Parse Tree: 比如语意语法分析

#### Characterizing Trees树的特点

下面的定理的证明都很有意思, 可参照课本

- tree至少有一个vertex的degree是1  
  如果一个tree只有一个或两个vertrx, 那么这两个vertex成为terminal vertex.  
  如果这个tree有两个以上vertex, degree等于1的vertex成为terminal vertex(或者称为leaf), 大于的vertex称为internal vertex(或者叫branch vertex)  
- 一个有n个vertices的tree有n-1个edge  
- 如果一个graph G是connected, C是G的一个circuit, 如果移除C里的一个edge, 那么G依然是connected
- 如果一个Graph G是cinnected, 有n个vertices, n-1个edge, 那么G是一个tree

<a id="markdown-_106-rooted-trees" name="_106-rooted-trees"></a>
### _10.6 Rooted Trees

#### 定义

rooted tree是有一个特殊的vertex, 称之为root. 其他vertex都存在一条唯一的以root为起点的path.  
vertex的level是从root到此vertex的edge的数量.  
rooted tree的height是指最长的一条path的数量.  
一个vertex v的children是指远离root、和v相邻的vertex. 如果w是v的children, 那么v称之为w的parent.  
如果两个vertex有同一个parent, 那么称两者为siblings.  
如果v处在root和w的path的线路上, 那么v是w的ancestor, w是v的descendant.  

#### Binary Trees

如果一个rooted tree的每一个vertex最多只有两个children, 这两个children我们称为left child和right child, 那么这个rooted tree是binary tree.  
一个full binary tree是指每个parent都有两个children.  
一个binary tree是的left child, 以之为root、和它的所有descendants组成left subtree. right child则组成right subtree. 

如果一个full binary tree T有k个internal vertices, 那么T共有2k + 1个vertices, 以及k + 1个terminal vertices.  
证明: T的vertices可以分为有parent的vertex和没有parent的vertex, 没有parent的vertex只有一个, 那就是root, 每个internal vertex都有2个children, 且不会和其他vertex共有, 所以有parent的vertex共有2k个, 总的vertex就有2k + 1个  
同时, T的vertices可以分为internal和terminal, internal有k个, 那么terminal vertices就有2k + 1 - k = k + 1个

full binary tree的height是h, 有t个terminal vertices, 那么: $t \le 2^k$, $log_2t\le h$

<a id="markdown-_107-spanning-trees-and-shortest-paths" name="_107-spanning-trees-and-shortest-paths"></a>
### _10.7 Spanning Trees and Shortest Paths

#### Spanning Trees

定义: Spanning tree是一个graph G的subgraph, 包含G的所有vertices, 并且是tree  

书中举了一个生动的例子, 航空公司在能开通的航线范围内, 要用最少的航线连通所有的城市.  
要满足这个条件, 必须是一个tree, 因为如果航线有circuit, 那么我们总是可以去掉一条航线, 而不影响城市的连通.

#### Minimum Spanning Trees

在上面航线的例子里, 航线是有长度的, 我们为了经济性, 如何选择最短路径的spanning tree呢?

##### weighted graph  
**weighted graph**是指一个graph, 他的每一条edge都有正实数的属性, 我们称之为**weight**.  
所有edges的weight的和, 称为这个graph的**total weight**.  
**minimum spanning tree**是指一个graph的所有spanning tree**中total weight最小的那个spanning tree.  
G是一个weighted graph, e是G的一条edge, 那么w(e)是指e的weight, w(G)指G的total weight

##### Kruskal Algorithm  

ALGORITHM kruskal
// 找到一个graph的minumum spanning tree  
// Input: graph G, connected, n vertices  
// Output: tree  
初始化T为minimum spanning tree, 还没有vertex  
E是G的所有edge的set  
while (i < n-1) do(为什么是n-1呢? 因为tree的edge的数量是vertex的数量减去1)  
　　选择E中最下weight的edge e  
　　从E中删除e  
　　如果把e加上T上之后, 没有构成circuit, 则把e加上T上  
　　i += 1  
end while

书中有例子, 参照例子更好理解

##### Prim Algorithm

另外一种求得minimum spanning tree的算法  

ALGORITHM prim  
// 找到一个graph的minumum spanning tree  
// Input: graph G, connected, n vertices  
// Output: tree  
init spanning tree T with 1 random select vertex v
V is set of n vertices without v  
while i < n - 1 do  
  　从与T相邻的所有edge中选取一条edge e, 这条edge满足:  
　　1. T加上e还是tree, 即没有circuit  
　　2. 与其他edge相比, T加上e之后的total weight最小  
　　T加上e和e的另一端vertex w, V去掉w  
next i

书中有例子, 参照例子更好理解

##### Dijkstra Shortest Path Algorithm

如何求得weighted graph中两个vertex的最短路径呢? 上面两个算法提供了灵感  
Dijkstra's Shortest Path Algorithm是Prim's Algorithm的变体

Algorithm Dijkastra  
// Input: graph G, starting vertex a, ending vertex z  
    L(u)代表起点a到vertex u的最短路径(integer)  
    $\infty$表示大于w(G)的一个数  
    w(u, v)代表u,v两个vertex组成的edge的weight    
// Output: L(z), z到a的最短路径  
1. init a graph T with a vertex a, V(T)是T的vertex的集合, E(T)是T的vertex的集合  
2. L(a) = 0, G的其他顶点u的L(u) = $\infty$
3. v = a, F = {a}, v表示最近添加到T的vertex
4. while $z \notin V(T)$  
    4a. $F := (F - {v}) \cup {vertices that adjacent v and not in V(T)}$  
        这里不太好理解, F称之为fringe  
    4b. 对于所有和v相邻的vertex并不属于V(T)的vertex u  
        if L(v) + w(v, u) < L(u) then:  
            L(u) := L(v) + w(v, u)  
            D(u) := v (D(u)标记了edge的起点)  
  4c. 在上一步中找到最小的L(x), 将x加到V(T), {D(x), x}加到E(T). v := x.  
end while

书中有例子, 参照例子更好理解. 这个算法实际上求得了G中所有vertices到a的最短距离