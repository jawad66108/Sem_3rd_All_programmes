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


def dfs(node,graph):
    visited = []
    if node not in visited:
        print (node)
        visited.append(node)
        
        for depth in graph[node]:
            dfs(depth,graph)
    
dfs (10,graph)
