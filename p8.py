import heapq

graph = {
    'S': [('a', 3), ('b', 2)],
    'a': [('c', 4), ('d', 5)],
    'b': [('c', 2), ('d', 3)],
    'c': [('G', 1)],  
    'd': [('G', 2)],  
    'G': []
}

heuristics = {
    'S': 5,
    'a': 4,
    'b': 3,
    'c': 1,
    'd': 2,
    'G': 0
}

def A (graph,heuristics,start,goal):
    open_list = []
    heapq.heappush(open_list,(heuristics[start],0,start,[start]))

    while open_list:
        f , g , current , path = heapq.heappop(open_list)

        if current == goal :
            return path, g 
        
        for neb , cost in graph[current]:
            new_g = g+cost
            new_f = g + heuristics[neb]

            heapq.heappush(open_list,(new_f, new_g , neb , path + [neb]))
        
    return None 

path , cost = A(graph,heuristics,'S','G')
print("Optimal Path:", path)
print("Total Cost:", cost)