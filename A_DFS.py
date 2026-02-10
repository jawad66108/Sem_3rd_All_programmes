graph = {
    10: [20, 30, 40],
    20: [50, 60],
    30: [70],
    40: [80],
    50: [],
    60: [90],
    70: [],
    80: [],
    90: [],
    100: []  # isolated node
}

visited = []

def DFS(start):
    if start not in visited:
        print(start)
        visited.append(start)
    
        for depth in graph[start]:

                DFS(depth)
        
DFS(10)

