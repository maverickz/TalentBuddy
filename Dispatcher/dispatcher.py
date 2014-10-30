import sys
import re
import heapq
class Vertex:
    def __init__(self,key):
        self.id = key
        self.connectedTo = {}

    def addNeighbor(self,nbr,weight=0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id) + ' connectedTo: ' + str([x.id for x in self.connectedTo])

    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id

    def getWeight(self,nbr):
        return self.connectedTo[nbr]

class Graph:
    def __init__(self):
        self.vertList = {}
        self.numVertices = 0

    def addVertex(self,key):
        self.numVertices = self.numVertices + 1
        newVertex = Vertex(key)
        self.vertList[key] = newVertex
        return newVertex

    def getVertex(self,n):
        if n in self.vertList:
            return self.vertList[n]
        else:
            return None

    def __contains__(self,n):
        return n in self.vertList

    def addEdge(self,f,t,cost=0):
        if f not in self.vertList:
            nv = self.addVertex(f)
        if t not in self.vertList:
            nv = self.addVertex(t)
        self.vertList[f].addNeighbor(self.vertList[t], cost)

    def getVertices(self):
        return self.vertList.keys()

    def __iter__(self):
        return iter(self.vertList.values())

def get_vertex_with_smallest_dist(Q, dist):
    smallest = sys.maxint
    vertex = None
    for idx,elem in enumerate(Q):
        if idx == 0:
            vertex = elem
            continue
        key = elem.getId()
        if dist[key] < smallest:
            smallest = dist[key]
            vertex = elem
    return vertex


def ShortestPath(G,dist,Q,s,d):
    while len(Q):
        tup = heapq.heappop(Q)
        u = G.getVertex(tup[1])
        if u.getId() == d:
            break
        key = u.getId()
        if dist[key] == sys.maxint:
            break
        min_dist = sys.maxint
        for v in u.connectedTo:
            alt = dist[u.getId()] + u.getWeight(v)
            if alt < dist[v.getId()]:
                dist[v.getId()]  = alt
                heapq.heappush(Q, (dist[v.getId()], v.getId()))
    return dist, Q
                       
def find_closest_car(city_map, cars, customer):
    # Write your code here
    # To print results to the standard output you can use print
    # Example: print "Hello world!"
    car_dict = {}
    for idx, intersection in enumerate(cars):
        car_dict[intersection] = idx
    G = Graph()
    for intersection in city_map:
        l = re.split(",", intersection)
        G.addEdge(int(l[0]),int(l[1]),int(l[2]))
        G.addEdge(int(l[1]),int(l[0]),int(l[2]))
    
    dist = {}
    Q = []
    for v in G.getVertices():
        if v == customer:
            dist[v] = 0
        else:
            dist[v] = sys.maxint
        heapq.heappush(Q, (dist[v], G.getVertex(v).getId()))
    
    min_car_id = -1
    min_dist = sys.maxint
    for idx, car in enumerate(cars):
        dist, Q = ShortestPath(G, dist, Q, customer, car)
        if dist[car] < min_dist:
            min_dist = dist[car]
            min_car_id = idx
    print min_car_id+1