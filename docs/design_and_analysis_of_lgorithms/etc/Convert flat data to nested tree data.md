### Convert flat data to nested tree data

list:

```python
[
  {"id": 1, "parent_id": None},
  {"id": 2, "parent_id": 1},
  {"id": 3, "parent_id": None},
  {"id": 4, "parent_id": 3},
  {"id": 5, "parent_id": 4}
]
```

将其转换为:

```python
[
  {
    "id": 1,
    "children": [
      {
        "id": 2
      }
    ]
  },
  {
    "id": 3,
    "children": [
      {
        "id": 4,
        "children": [
          {
            "id": 5
          }
        ]
      }
    ]
  }
]
```

answer:

```python
def create_nested_structure(lst):
    # 创建一个字典，用于存储每个节点的ID和对应的字典表示
    nodes = {
        item['id']: {
            'id': item['id'],
            'parent_id': item["parent_id"]
        }
        for item in lst
    }

    # 遍历列表，将每个节点添加到其父节点的子节点列表中
    for item in lst:
        parent_id = item['parent_id']
        if parent_id is None:
            # 如果没有父节点，则跳过
            continue
        parent_node = nodes[parent_id]
        children = parent_node.setdefault('children', [])
        children.append(nodes[item['id']])

    print(nodes)
    # 返回根节点列表，即没有父节点的节点
    return [node for node in nodes.values() if node['parent_id'] is None]


# 测试示例数据
data = [{
    "id": 1,
    "parent_id": None
}, {
    "id": 2,
    "parent_id": 1
}, {
    "id": 3,
    "parent_id": None
}, {
    "id": 4,
    "parent_id": 3
}, {
    "id": 5,
    "parent_id": 4
}]

result = create_nested_structure(data)
print(result)
```
