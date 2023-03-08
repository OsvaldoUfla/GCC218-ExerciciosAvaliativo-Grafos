import heapq

INF = float('inf')

def dijkstra(graph, c, s):
    n = len(graph)
    dist = [INF] * n
    parent = [-1] * n
    dist[s] = 0
    q = [(0, s)] # fila de prioridade
    while q:
        d, u = heapq.heappop(q)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            if w > c[u]:
                continue # não é possível chegar a v com o combustível atual
            fuel = c[u] - w
            alt = dist[u] + w * (c[u] - fuel) # custo total até v
            if alt < dist[v]:
                dist[v] = alt
                parent[v] = u
                heapq.heappush(q, (alt, v))
    return dist, parent

# leitura do grafo
n, m = map(int, input().split())
c = list(map(int, input().split()))
graph = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

# processamento dos testes
x = int(input())
for _ in range(x):
    Q, s, t = map(int, input().split())
    dist, parent = dijkstra(graph, c, s)
    if dist[t] == INF or Q < graph[s][0][1]:
        print("sem solucao")
    else:
        path = [t]
        while parent[path[-1]] != -1:
            path.append(parent[path[-1]])
        path.reverse()
        cost = 0
        fuel = 0
        for i in range(len(path) - 1):
            u, v = path[i], path[i+1]
            d = graph[u][v == parent[u]][1] # distância entre u e v
            cost += d * (c[u] - fuel)
            fuel = c[u] - d / Q
        print(cost)