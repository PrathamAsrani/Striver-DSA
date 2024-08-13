
'''
from collections import deque

def fire_spread(n, h, conn):
    q = deque([])
    vis = set([0])
    q.append((0, 0))
    reached = []
    
    while q:
        node, node_time = q.popleft()
        reached.append(node)
        
        for edge in conn:
            x, y, time = edge
            if x == node and node_time <= time and y not in vis:
                q.append((y, time))
                vis.add(y)
                
            elif y == node and node_time <= time and x not in vis:
                q.append((x, time))
                vis.add(x)
                
    reached.sort()
    return reached

n = 6
h = 1
connections = [
    [0, 1, 0],
    [1, 2, 5],
    [2, 3, 8],
    [1, 5, 10]
]
print(fire_spread(n, h, connections))
'''

import heapq as pq

def splitArray(arr, n, k):
    a = [0]*k
    pq.heapify(a)
    arr.sort(reverse = True)
    
    for i in range(n):
        val = pq.heappop(a)
        val += arr[i]
        pq.heappush(a, val)
    
    return max(a)

n = 5
k = 2
arr = [1, 2, 4, 7, 8]
print(splitArray(arr, n, k))