# # -----------BFS--------------
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
#             print(node , end= " " )
#             visited.add(node)
#             # queue.extend(graph[node])
#             for i in graph[node]:
#                 if i not in visited:
#                     queue.append(i)

# bfs(0)
# print()

# def dfs(node , visited = None):
#     if visited is None:
#         visited = set()
#     if node not in visited:
#         print(node , end=" ")
#         visited.add(node)
#         for child in graph[node]:
#             dfs(child,visited)
# dfs(0)


# customers = {
#     501: {"purchases": 72000, "loyalty_score": 88},
#     502: {"purchases": 45000, "loyalty_score": 92},
#     503: {"purchases": 38000, "loyalty_score": 92},
#     504: {"purchases": 56000, "loyalty_score": 75},
#     505: {"purchases": 90000, "loyalty_score": 81},
#     506: {"purchases": 22000, "loyalty_score": 64},
#     507: {"purchases": 48000, "loyalty_score": 85}
# }

# max_score = 0

# for i in customers:
#     if customers[i]["loyalty_score"] > max_score:
#         max_score = customers[i]["loyalty_score"]

# for i in customers:
#     if customers[i]["loyalty_score"] == max_score:
#         print("Customer ID:", i, "Score:", max_score)

# for j in customers:
#     if customers[j]["purchases"] < 50000:
#         print("Low purchase customer ID:", j)
    
# temps = [18.5, 20.1, 19.8, 22.4, 23.9, 21.7, 25.3]
# min_temp = temps[0]
# max_rise = 0

# for t in temps:
#     if t < min_temp:
#         min_temp = t

# for t in temps:
#     rise = t - min_temp
#     if rise > max_rise:
#         max_rise = rise

# print("Max Temperature Rise:", max_rise)

# players = {
#     "Babar": 90,
#     "Rizwan": 35,
#     "Shaheen": 60,
#     "Shadab": 25
# }

# for name,i in players.items():
#     if i==60:
#         print("Runs 50 is scored by: ",name)

# for j in players.items():
#     print(j)
