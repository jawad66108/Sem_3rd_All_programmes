# import heapq

# graph = {
#     'Islamabad': [('Peshawar', 174), ('Faisalabad', 260), ('Quetta', 714)],
    
#     'Peshawar': [('Sialkot', 260), ('Lahore', 385)],
    
#     'Sialkot': [('Lahore', 238)],
    
#     'Faisalabad': [('Lahore', 338), ('Islamabad', 388), ('Quetta', 161)],
    
#     'Lahore': [('Sukkur', 437)],
    
#     'Quetta': [('Multan', 388), ('Islamabad', 714), ('Faisalabad', 161)],
    
#     'Multan': [('Sukkur', 313)],
    
#     'Sukkur': [('Karachi', 150)],
    
#     'Karachi': []
# }

# heuristics = {
#     'Islamabad': 125,
#     'Peshawar': 695,
#     'Sialkot': 273,
#     'Faisalabad': 218,
#     'Lahore': 241,
#     'Quetta': 714,
#     'Multan': 357,
#     'Sukkur': 386,
#     'Karachi': 0
# }

# def a_star(graph, heuristics, start, goal):
    
#     open_list = []
#     visited = set()
    
#     # f(n) = g(n) + h(n)
#     heapq.heappush(open_list, (heuristics[start], 0, start, [start]))
    
#     while open_list:
#         f, g, current, path = heapq.heappop(open_list)
        
#         if current == goal:
#             return path, g
        
#         if current in visited:
#             continue
        
#         visited.add(current)
        
#         for neighbor, cost in graph[current]:
#             new_g = g + cost
#             new_f = new_g + heuristics[neighbor]
            
#             heapq.heappush(
#                 open_list,
#                 (new_f, new_g, neighbor, path + [neighbor])
#             )

# path, cost = a_star(graph, heuristics, 'Islamabad', 'Karachi')

# print("Optimal Path:", path)
# print("Total Cost:", cost)



print("Name: Bob")
print("Father's Name: Alice ")
print("Date of Birth: 24-09-1999")
# part b

text = input("Enter a string: ")

rev = ""
for ch in text:
    rev =ch+rev  
print(rev)

# part c

text = input("Enter a string: ")
print(len(text))

# part d

print("University Name: University of Wah")
print("Campus/Location: WAH CANTT")
print("Class/Semester: BSCS Semester 3")
print("Registration Number: UW-24-CS-BS-066")
# part e

a = 5
b = 10

a, b = b, a

print("a =", a)
print("b =", b)

# graph = {
#     'A': ['B', 'C', 'D'],
#     'B': ['A', 'E'],
#     'C': ['A', 'D', 'F'],
#     'D': ['A', 'C', 'E', 'G'],
#     'E': ['B', 'D', 'G'],
#     'F': ['C', 'G'],
#     'G': ['D', 'E', 'F']
# }

# from collections import deque

# def bfs(graph, start):
#     visited = []          
#     queue = deque([start])  

#     while queue:
#         node = queue.popleft()   

#         if node not in visited:  
#             print(node, end=" ") 
#             visited.append(node)

#             for neighbor in sorted(graph[node]):  
#                 if neighbor not in visited:
#                     queue.append(neighbor)

# print("BFS Traversal starting from A:")
# bfs(graph, 'A')

