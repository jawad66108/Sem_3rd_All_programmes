# from collections import deque

# graph = {
#     0: [1, 3, 4],
#     1: [2],
#     3: [5],
#     4: [],
#     2: [],
#     5: []
# }

# def bfs(start):
#     visited = set()
#     queue = deque([start])
    
#     while queue:
#         node = queue.popleft()
#         if node not in visited:
#             print(node, end=" ")
#             visited.add(node)
#             queue.extend(graph[node])

# print("BFS Traversal:")
# bfs(0)

# DFS Graph (tree) from second image
# tree = {
#     1: [2, 7, 8],
#     2: [3, 6],
#     7: [],
#     8: [9, 12],
#     3: [4, 5],
#     6: [],
#     9: [10, 11],
#     12: [],
#     4: [],
#     5: [],
#     10: [],
#     11: []
# }

# def dfs(node, visited=set()):
#     if node not in visited:
#         print(node, end=" ")
#         visited.add(node)
#         for child in tree[node]:
#             dfs(child, visited)

# print("DFS Traversal:")
# dfs(1)

# from collections import deque
# graph = {
#     0: [1, 3, 4],
#     1: [2],
#     3: [5],
#     4: [],
#     2: [],
#     5: []
# }
# def bfs(start):
#     visited=set()
#     queue= deque(start)

#     while queue:
#         node =queue.popleft()
#         if node not in visited:
#             visited.add(node)
#             queue.extend(graph[node])


# from collections import deque
# graph = {
#     0: [1, 3, 4],
#     1: [2],
#     3: [5],
#     4: [],
#     2: [],
#     5: []
# }

# def bfs(start):
#     visited =set()
#     queue = deque([start])
#     while queue:
#         node = queue.popleft()
#         if node not in visited:
#             print(node)
#             visited.add(node)
#             # queue.extend(graph[node])
#             for j in graph[node]:
#                 if j not in visited:
#                     queue.append(j)

# bfs(0)

# from collections import deque
# graph = {
#     0: [1, 3, 4],
#     1: [2],
#     3: [5],
#     4: [],
#     2: [],
#     5: []
# }

# def dfs(node , visited=set()):
#     if node not in visited:
#         print(node)
#         visited.add(node)
#         for child in graph[node]:
#             dfs(child,visited)

# dfs(0)
