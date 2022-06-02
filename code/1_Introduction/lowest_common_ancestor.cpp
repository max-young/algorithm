// 1. 定义数据结构, 节点的member data, 有自身的值, 以及左右节点的指针, 以及构建函数
// 2. 定义函数, 参数是root node, 和要求的两个节点a,b
// 3. 如果root和a,b其中一个是null, 返回null
// 4. 如果其中一个节点是root, 那么返回root
// 5. 以root的左节点和a,b递归计算得到节点lr
// 6. 以root的右节点和a,b递归计算得到节点rl
// 7. 如果lr是null, 返回rl
// 8. 如果rl是null, 返回lr
// 9. 如果lr和rl都不是null, 返回root
// 10. return null

#include <iostream>

using std::cout;
using std::endl;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

Node *lowestCommonAncestor(Node *root, Node *a, Node *b)
{
  if (root == nullptr || a == nullptr || b == nullptr)
    return nullptr;
  if (root == a || root == b)
    return root;
  Node *lr = lowestCommonAncestor(root->left, a, b);
  Node *rl = lowestCommonAncestor(root->right, a, b);
  if (lr == nullptr)
    return rl;
  if (rl == nullptr)
    return lr;
  if (rl != nullptr && lr != nullptr)
    return root;
  return nullptr;
}

int main()
{
  Node root = Node(1);
  Node a = Node(2);
  Node b = Node(3);
  root.left = &a;
  root.right = &b;
  Node *lca = lowestCommonAncestor(&root, &a, &b);
  cout << lca->value << endl;
}