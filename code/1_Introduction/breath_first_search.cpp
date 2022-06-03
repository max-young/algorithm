#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node(int value): value(value), left(nullptr), right(nullptr) {};
};

vector<vector<int>> outputTree(Node *root)
{
  vector<vector<int>> result;
  vector<Node*> firstLevel{root};
  queue<vector<Node*>> nodeQueue;
  nodeQueue.push(firstLevel);
  while (!nodeQueue.empty())
  {
    vector<Node*> preLevelNodes = nodeQueue.front();
    nodeQueue.pop();
    vector<int> preLevelValues;
    vector<Node*> nextLevelNodes;
    for (auto node: preLevelNodes)
    {
      if (node != nullptr)
      {
        preLevelValues.push_back(node->value);
        nextLevelNodes.push_back(node->left);
        nextLevelNodes.push_back(node->right);
      }
    }
    if (nextLevelNodes.size() > 0)
      nodeQueue.push(nextLevelNodes);
    if (preLevelValues.size() >0)
      result.push_back(preLevelValues);
  }
  return result;
}

int main()
{
  Node root = {1};
  Node n1 = {1};
  Node n2 = {2};
  Node n3 = {3};
  Node n4 = {4};
  Node n5 = {5};
  root.left = &n1;
  root.right = &n2;
  n1.left = &n3;
  n2.left = &n4;
  n2.right = &n5;
  auto output = outputTree(&root);

  return 0;
}