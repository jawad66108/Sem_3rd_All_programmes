import heapq

heuristics = {
    'A': 6,  # Receiving Dock
    'B': 5,  # Sorting Area
    'C': 4,  # Cold Storage
    'D': 3,  # Dry Goods
    'E': 2,  # Produce Prep
    'F': 1,  # Packing Station
    'G': 0   # Dispatch (GOAL)
}

graph = {
    'A': [('B', 5)],                    # A -> B: 5 min
    'B': [('C', 3), ('D', 4)],          # B -> C: 3 min, B -> D: 4 min
    'C': [('E', 2)],                    # C -> E: 2 min
    'D': [('F', 3)],                    # D -> F: 3 min
    'E': [('F', 2), ('G', 1)],          # E -> F: 2 min, E -> G: 1 min
    'F': [('G', 1)],                    # F -> G: 1 min
    'G': []                             # Goal node
}

def a_star_algorithm(graph, heuristics, start, goal):
    open_list = []
    heapq.heappush(open_list, (heuristics[start], 0, start, [start]))
    
    while open_list:
        f, g, current, path = heapq.heappop(open_list)
        
        if current == goal:
            return path, g
            
        for neighbor, cost in graph[current]:
            new_g = g + cost
            new_f = new_g + heuristics[neighbor]
            heapq.heappush(open_list, (new_f, new_g, neighbor, path + [neighbor]))
    
    return None, float('inf')

path, cost = a_star_algorithm(graph, heuristics, 'A', 'E')

print("Optimal Path:", path)
print("Total Cost:", cost)
