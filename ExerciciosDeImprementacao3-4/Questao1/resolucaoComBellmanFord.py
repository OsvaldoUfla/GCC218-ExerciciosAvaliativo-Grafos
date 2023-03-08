from collections import defaultdict

def bellman_ford(graph, source, c, Q):
    dist = defaultdict(lambda: float('inf'))
    dist[source] = 0
    fuel = defaultdict(lambda: 0)
    fuel[source] = Q
    
    for i in range(len(graph)-1):
        for u in graph:
            for v, w in graph[u]:
                if dist[u] != float('inf') and fuel[u] >= w:
                    new_fuel = fuel[u] - w
                    new_cost = dist[u] + w*c[v]
                    if new_fuel > fuel[v] or (new_fuel == fuel[v] and new_cost < dist[v]):
                        fuel[v] = new_fuel
                        dist[v] = new_cost
    
    for u in graph:
        for v, w in graph[u]:
            if dist[u] != float('inf') and fuel[u] >= w:
                new_fuel = fuel[u] - w
                new_cost = dist[u] + w*c[v]
                if new_fuel > fuel[v] or (new_fuel == fuel[v] and new_cost < dist[v]):
                    return "sem solucao"
    
    return dist[t]

# Leitura da entrada
n, m = map(int, input().split())
c = list(map(int, input().split()))

graph = defaultdict(list)
for i in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

# Realização dos testes
t = int(input())
for _ in range(t):
    Q, s, t = map(int, input().split())
    cost = bellman_ford(graph, s, c, Q)
    if cost == "sem solucao":
        print("sem solucao")
    else:
        print(cost)
