# def dls(graph, current, goal, depth, path, visited):
#     # Agar depth 0 ho jaye to matlab hum max limit tak aa chukay hain
#     if depth == 0:
#         # Check karo agar current node hi goal hai
#         if current == goal:
#             # Agar haan, to path ke sath current node return karo
#             return path + [current]
#         # Agar goal nahi mila to None return karo
#         return None

#     # Current node ko visited set me add kar do taake dobara visit na ho
#     visited.add(current)

#     # Agar current node hi goal hai
#     if current == goal:
#         # To path ke sath current node return kar do
#         return path + [current]


#     # Current node ke sab neighbors ko explore karo
#     for neighbor in graph.get(current, []):
#         # Agar neighbor pehle visit nahi hua
#         if neighbor not in visited:
#             # Recursive call lagao, depth ko 1 kam kar do
#             result = dls(
#                 graph,                 # pura graph pass karo
#                 neighbor,              # next node jahan jana hai
#                 goal,                  # goal node
#                 depth - 1,             # depth kam kar di
#                 path + [current],      # path me current node add karo
#                 visited.copy()         # visited ka copy bhejo
#             )
#             # Agar result mila (path mil gaya)
#             if result:
#                 # To wahi result return kar do
#                 return result

#     # Agar is depth par koi path nahi mila
#     return None


# # Iterative Deepening Depth-First Search (IDDFS) function
# def iddfs(graph, start, goal, max_depth=10):
#     # Depth ko 0 se le kar max_depth tak increase karte jao
#     for depth in range(max_depth):
#         # Har depth ke liye naya visited set banao
#         visited = set()
#         # DLS call karo current depth ke sath
#         path = dls(graph, start, goal, depth, [], visited)
#         # Agar path mil jaye
#         if path:
#             # To wahi path return kar do
#             return path
#     # Agar max_depth tak bhi path na mile
#     return None


# # Example graph define kiya ja raha hai
# graph = {
#     'A': ['B', 'C'],   # A se B aur C ja sakte hain
#     'B': ['D', 'E'],   # B se D aur E
#     'C': ['F'],        # C se F
#     'D': [],           # D ka koi child nahi
#     'E': ['F'],        # E se F
#     'F': []            # F goal node hai, koi child nahi
# }

# # Start node define ki
# start = 'A'
# # Goal node define ki
# goal = 'F'

# # IDDFS function call ki
# result = iddfs(graph, start, goal)

# # Result ko proper indexing ke sath print karwa diya
# if result:
#     print("Path found:")
#     for idx, node in enumerate(result, start=1):
#         print(f"{idx}. {node}")
# else:
#     print("No path found")

# def dls_path(graph, current, goal, limit, path):
#     if current == goal:
#         return path
#     if limit == 0:
#         return None
#     for neighbor in graph.get(current, []):
#         if neighbor not in path: 
#             result = dls_path(graph, neighbor, goal, limit - 1, path + [neighbor])
#             if result is not None:
#                 return result
#     return None

# def iddfs(graph, start, goal, max_depth=10):
#     for depth in range(max_depth + 1):
#         result = dls_path(graph, start, goal, depth, [start])
#         if result is not None:
#             return result
#     return None

# graph = {
#     'A': ['B', 'C'],
#     'B': ['D', 'E'],
#     'C': ['F'],
#     'D': [],
#     'E': ['F'],
#     'F': []
# }

# start = 'A'
# goal = 'F'
# print(iddfs(graph, start, goal))

# def one_letter_diff(a, b):
#     if len(a) != len(b):
#         return False
#     diff = 0
#     for x, y in zip(a, b):
#         if x != y:
#             diff += 1
#             if diff > 1:
#                 return False
#     return diff == 1

# def build_word_graph(word_list):
#     graph = {}
#     for word in word_list:
#         graph[word] = []
#     for i in range(len(word_list)):
#         for j in range(i + 1, len(word_list)):
#             w1 = word_list[i]
#             w2 = word_list[j]
#             if one_letter_diff(w1, w2):
#                 graph[w1].append(w2)
#                 graph[w2].append(w1)
#     return graph

# def dls_word(current, goal, depth, path, visited, graph):
#     if depth < 0:
#         return None
#     path.append(current)
#     if current == goal:
#         return path
#     visited.add(current)
#     for neighbor in graph.get(current, []):
#         if neighbor not in visited:
#             result = dls_word(neighbor, goal, depth - 1, path, visited, graph)
#             if result is not None:
#                 return result
#     path.pop()
#     return None

# def iddfs_word_ladder(start, goal, word_list, max_depth=10):
#     if start not in word_list:
#         word_list = word_list + [start]
#     graph = build_word_graph(word_list)
#     for depth in range(max_depth + 1):
#         path = []
#         visited = set()
#         result = dls_word(start, goal, depth, path, visited, graph)
#         if result is not None:
#             return result
#     return None

# word_list = ['hit', 'hot', 'dot', 'dog', 'cog', 'log', 'lot']
# start = 'hit'
# goal = 'cog'

# result = iddfs_word_ladder(start, goal, word_list)
# print(result)


# def puzzle_to_tuple(state):
#     return tuple(tuple(row) for row in state)

# def find_zero(state):
#     for i in range(3):
#         for j in range(3):
#             if state[i][j] == 0:
#                 return i, j

# def get_neighbors_puzzle(state):
#     neighbors = []
#     x, y = find_zero(state)
#     moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
#     for dx, dy in moves:
#         nx = x + dx
#         ny = y + dy
#         if 0 <= nx < 3 and 0 <= ny < 3:
#             new_state = [row[:] for row in state]
#             new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
#             neighbors.append(new_state)
#     return neighbors

# def dls_puzzle(current, goal, depth, path, visited):
#     if depth < 0:
#         return None
#     tcur = puzzle_to_tuple(current)
#     path.append(current)
#     if current == goal:
#         return path
#     visited.add(tcur)
#     for neighbor in get_neighbors_puzzle(current):
#         tnb = puzzle_to_tuple(neighbor)
#         if tnb not in visited:
#             result = dls_puzzle(neighbor, goal, depth - 1, path, visited)
#             if result is not None:
#                 return result
#     path.pop()
#     return None

# def iddfs_puzzle(start_state, goal_state, max_depth=20):
#     for depth in range(max_depth + 1):
#         path = []
#         visited = set()
#         result = dls_puzzle(start_state, goal_state, depth, path, visited)
#         if result is not None:
#             return result
#     return None

# start_state = [[1, 2, 3],
#                [4, 0, 6],
#                [7, 5, 8]]

# goal_state = [[1, 2, 3],
#               [4, 5, 6],
#               [7, 8, 0]]

# solution = iddfs_puzzle(start_state, goal_state)
# if solution is None:
#     print("No solution within depth limit")
# else:
#     for s in solution:
#         print(s)
#         print("-----")

def get_neighbors_maze(maze, pos):
    rows = len(maze)
    cols = len(maze[0])
    x, y = pos
    neighbors = []
    moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for dx, dy in moves:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < rows and 0 <= ny < cols:
            if maze[nx][ny] == 1:
                neighbors.append((nx, ny))
    return neighbors

def dls_maze(current, goal, depth, path, visited, maze):
    if depth < 0:
        return None
    path.append(current)
    if current == goal:
        return path
    visited.add(current)
    for neighbor in get_neighbors_maze(maze, current):
        if neighbor not in visited:
            result = dls_maze(neighbor, goal, depth - 1, path, visited, maze)
            if result is not None:
                return result
    path.pop()
    return None

def iddfs_maze(maze, start, goal, max_depth=20):
    for depth in range(max_depth + 1):
        path = []
        visited = set()
        result = dls_maze(start, goal, depth, path, visited, maze)
        if result is not None:
            return result
    return None

maze = [
    [1, 0, 1, 1],
    [1, 1, 0, 1],
    [0, 1, 1, 0],
    [1, 0, 1, 1]
]

start = (0, 0)
goal = (3, 3)

path = iddfs_maze(maze, start, goal)
print(path)
