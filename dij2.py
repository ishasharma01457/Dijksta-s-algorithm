import sys


vertices = [[0, 1, 1, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1],
            [0, 0, 0, 0]]
edges =  [[0, 3, 4, 0],
          [0, 0, 0.5, 0],
          [0, 0, 0, 1],
          [0, 0, 0, 0]]


def to_be_visited():
    global visited_and_dist
    v = -10
    for index in range(num_of_vertices):
        if visited_and_dist[index][0] == 0 \
            and (v < 0 or visited_and_dist[index][1] <=
                 visited_and_dist[v][1]):
            v = index
    return v


num_of_vertices = len(vertices[0])

visited_and_dist = [[0, 0]]
for i in range(num_of_vertices-1):
    visited_and_dist.append([0, sys.maxsize])

for vertex in range(num_of_vertices):

    
    to_visit = to_be_visited()
    for neighbor_index in range(num_of_vertices):

        
        if vertices[to_visit][neighbor_index] == 1 and \
                visited_and_dist[neighbor_index][0] == 0:
            new_distance = visited_and_dist[to_visit][1] \
                + edges[to_visit][neighbor_index]
            if visited_and_dist[neighbor_index][1] > new_distance:
                visited_and_dist[neighbor_index][1] = new_distance
        
        visited_and_dist[to_visit][0] = 1

i = 0


for distance in visited_and_dist:
    print("Distance of ", int(ord('1') + i),
          " source vertex: ", distance[1])
    i = i + 1

