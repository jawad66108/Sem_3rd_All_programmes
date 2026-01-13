import heapq

graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

huristic = {
    'A': 1,
    'B': 2,
    'C': 3,
    'D': 4
}

def A(graph ,huristic ,start ,goal):
    queue = []
    heapq.heappush(queue,(huristic[start] ,0 ,start , [start]))
    while  queue:
        f ,g , current,path = heapq.heappop(queue)

        if current == goal:
            return path ,g
    
        for neb, cost in graph[current]:
                    new_g = g + cost
                    new_f = new_g + huristic[neb]

                    heapq.heappush(queue,(new_f,new_g,neb,path+[neb]))

path ,cost = A(graph,huristic,'A','D')
print("PATH: ",path + "COST: ",cost)
