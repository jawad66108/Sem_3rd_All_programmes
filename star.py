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

def a(graph,heuristics, start ,goal):
    listl= []
    heapq.heappush(listl,(heuristics[start], 0 ,start,[start]))
    
    while listl:
        f,g,current,path = heapq.heappop(listl)
        if current == goal:
            return path,g
    
        for neb,cost in graph[current]:
            new_g = g + cost
            new_f = new_g + heuristics[neb]
        
            heapq.heappush(listl,(new_f,new_g,neb,path + [neb]))
        
        
path , cost = a(graph,heuristics,'S','G')
print("PATH:",path," Cost: ",cost)

    