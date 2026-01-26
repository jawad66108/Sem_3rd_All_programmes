graph = {
    0: [1, 2, 3],
    1: [4, 5],
    2: [6],
    3: [7],
    4: [],
    5: [8],
    6: [],
    7: [9],
    8: [],
    9: []
}

visited = []
queue = []

def bfs(graph , node):
    visited.append(node)
    queue.append(node)
    
    while queue:
        
        m = queue.pop(0)
        
        print(m,end=" ")
        for neb in graph[m]:
            if m not in visited:
                visited.append(neb)
                queue.append(neb)
                bfs(neb,graph)
            
bfs(0,graph)

