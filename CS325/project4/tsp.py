import math
import sys

def main(argv):
    """
    Reads the input file and writes an approximate TSP solution to a file.
    Note that the city IDs are only used for output. Internally, each city is
    indexed by order.
    """
    if len(argv) <= 1:
        sys.exit('No input file given')
    file = argv[1]
    ids, coords = read_cities(file)
    dist_matrix = get_dist_matrix(coords)
    path = christofides(coords, dist_matrix)
    length = tour_length(path, dist_matrix)
    with open(file + '.tour', 'w') as fp:
        print(length, file=fp)
        for i in path:
            print(ids[i], file=fp)


def read_cities(file):
    """Reads a file and returns a mapping from city IDs to coordinates."""
    ids = []
    coords = []
    with open(file) as fp:
        for line in fp:
            tokens = line.split()
            if len(tokens) == 3:
                id = int(tokens[0])
                xc = int(tokens[1])
                yc = int(tokens[2])
                ids.append(id)
                coords.append((xc, yc))
    return ids, coords


def get_dist_matrix(coords):
    """Generates a distance matrix for the given coordinates."""
    m = [[0 for x in coords] for x in coords]
    for i in range(len(coords)):
        for j in range(i + 1, len(coords)):
            dx = coords[j][0] - coords[i][0]
            dy = coords[j][1] - coords[i][1]
            dist = int(round(math.sqrt(dx * dx + dy * dy)))
            m[i][j] = dist
            m[j][i] = dist
    return m


def mst(coords, dist_matrix):
    """Returns an MST in adjacency list format."""
    adj_list = [[] for x in dist_matrix]
    delaunay(coord_sort(coords), coords, adj_list)
    edges = []
    for i in range(len(adj_list)):
        for j in adj_list[i]:
            if j > i:
                edges.append((i, j))
    edges = sorted(edges, key=lambda x: dist_matrix[x[0]][x[1]])
    return kruskal(coords, edges)


def kruskal(coords, edges):
    """Returns an MST spanning the given edges in adjacency list format."""
    mst = [[] for x in coords]
    # Disjoint-set forest
    parents = {i : i for i in range(len(coords))}
    ranks = {i : 0 for i in range(len(coords))}
    for edge in edges:
        if get_root(parents, edge[0]) != get_root(parents, edge[1]):
            r1 = get_root(parents, edge[0])
            r2 = get_root(parents, edge[1])
            if r1 != r2:
                if ranks[r1] > ranks[r2]:
                    parents[r2] = r1
                else:
                    parents[r1] = r2
                    if ranks[r1] == ranks[r2]:
                        ranks[r2] += 1
            mst[edge[0]].append(edge[1])
            mst[edge[1]].append(edge[0])
    return mst


def get_root(parents, v):
    """
    Finds the root of v in the disjoint-set forest represented by parents.
    """
    if parents[v] != v:
        parents[v] = get_root(parents, parents[v])
    return parents[v]


def add_approx_perfect_matching(o, dist_matrix, adj_list):
    """
    Finds an approximate minimum perfect matching for the vertices in 0 and
    appends it to the adjacency list. All items in o will be removed.
    """
    while o:
        v = o.pop(0)
        d = float("inf")
        for u in o:
            if dist_matrix[u][v] < d:
                d = dist_matrix[u][v]
                closest = u
        o.remove(closest)
        adj_list[v].append(closest)
        adj_list[closest].append(v)


def eulerian_tour(adj_list):
    """
    Finds an Eulerian tour for the adjacency list, assuming that one exists.
    """
    circuit = []
    stack = []
    v = 0
    while stack or adj_list[v]:
        if not adj_list[v]:
            circuit.append(v)
            v = stack.pop()
        else:
            stack.append(v)
            w = adj_list[v][0]
            adj_list[v].remove(w)
            adj_list[w].remove(v)
            v = w
    return circuit


def shortcut(circuit):
    """Removes duplicate vertices from a circuit."""
    path = []
    visited = set()
    for x in circuit:
        if x not in visited:
            visited.add(x)
            path.append(x)
    return path


def christofides(coords, dist_matrix):
    """Performs the Christofides algorithm."""
    adj_list = mst(coords, dist_matrix)
    o = [x for x in range(len(adj_list)) if len(adj_list[x]) % 2 == 1]
    add_approx_perfect_matching(o, dist_matrix, adj_list)
    circuit = eulerian_tour(adj_list)
    path = shortcut(circuit)
    return path


def tour_length(path, dist_matrix):
    """
    Calculates the length of the given path according to the distance matrix.
    """
    length = 0
    for i in range(len(path)):
        length += dist_matrix[path[i]][path[i - 1]]
    return length


def coord_sort(coords):
    """
    Sorts the indices of the coordinates in x-coordinate order, breaking ties
    by y-coordinate.
    """
    return [x[0] for x in sorted([(i, coords[i]) for i in range(len(coords))], key=lambda x: x[1])]


class QuadEdge:
    def __init__(self):
        self.edges = [Edge(i, self) for i in range(4)]
        self.edges[0].next = self.edges[0]
        self.edges[1].next = self.edges[3]
        self.edges[2].next = self.edges[2]
        self.edges[3].next = self.edges[1]


class Edge:
    def __init__(self, num, qe):
        self.num = num
        self.qe = qe
        self.next = None
        self.p = None
    def rot(self):
        return self.qe.edges[(self.num + 1) % 4]
    def invrot(self):
        return self.qe.edges[(self.num + 3) % 4]
    def sym(self):
        return self.qe.edges[(self.num + 2) % 4]
    def onext(self):
        return self.next
    def oprev(self):
        return self.rot().onext().rot()
    def lnext(self):
        return self.invrot().onext().rot()
    def lprev(self):
        return self.onext().sym()
    def rnext(self):
        return self.rot().onext().invrot()
    def rprev(self):
        return self.sym().onext()
    def org(self):
        return self.p
    def dest(self):
        return self.sym().p
    def set(self, o, d):
        self.p = o
        self.sym().p = d


def splice(a, b):
    """Performs the splice operation on two edges."""
    alpha = a.onext().rot()
    beta = b.onext().rot()
    t1 = b.onext()
    t2 = a.onext()
    t3 = beta.onext()
    t4 = alpha.onext()
    a.next = t1
    b.next = t2
    alpha.next = t3
    beta.next = t4


def make_edge():
    """Initializes an edge."""
    qe = QuadEdge()
    return qe.edges[0]


def delete_edge(e):
    """Removes an edge."""
    splice(e, e.oprev())
    splice(e.sym(), e.sym().oprev())


def connect(a, b):
    """Connects the destination of a to the origin of b."""
    e = make_edge()
    splice(e, a.lnext())
    splice(e.sym(), b)
    e.set(a.dest(), b.org())
    return e


def triarea(coords, a, b, c):
    """Returns the signed area of the triangle formed by a, b, and c."""
    return (coords[b][0] - coords[a][0]) * (coords[c][1] - coords[a][1]) - (coords[b][1] - coords[a][1]) * (coords[c][0] - coords[a][0])


def in_circle(coords, a, b, c, d):
    """Returns whether d is in the circle circumscribed by a, b, and c."""
    return ((coords[a][0] * coords[a][0] + coords[a][1] * coords[a][1]) * triarea(coords, b, c, d) -
            (coords[b][0] * coords[b][0] + coords[b][1] * coords[b][1]) * triarea(coords, a, c, d) +
            (coords[c][0] * coords[c][0] + coords[c][1] * coords[c][1]) * triarea(coords, a, b, d) - 
            (coords[d][0] * coords[d][0] + coords[d][1] * coords[d][1]) * triarea(coords, a, b, c)) > 0


def ccw(coords, a, b, c):
    """Returns whether a, b, and c are in counter-clockwise order."""
    return triarea(coords, a, b, c) > 0


def right_of(coords, x, e):
    """Returns whether x is to the right of e."""
    return ccw(coords, x, e.dest(), e.org())


def left_of(coords, x, e):
    """Returns whether x is to the left of e."""
    return ccw(coords, x, e.org(), e.dest())


def delaunay(s, coords, adj_list):
    """
    Adds the edges of a Delaunay triagulation of the given points to the adjacency list.
    """
    if len(s) == 2:
        adj_list[s[0]].append(s[1])
        adj_list[s[1]].append(s[0])
        a = make_edge()
        a.set(s[0], s[1])
        return a, a.sym()
    elif len(s) == 3:
        adj_list[s[0]].append(s[1])
        adj_list[s[1]].append(s[0])
        adj_list[s[1]].append(s[2])
        adj_list[s[2]].append(s[1])
        a = make_edge()
        b = make_edge()
        splice(a.sym(), b)
        a.set(s[0], s[1])
        b.set(s[1], s[2])
        turn = triarea(coords, s[0], s[1], s[2])
        if turn == 0:
            return a, b.sym()
        else:
            c = connect(b, a)
            adj_list[c.org()].append(c.dest())
            adj_list[c.dest()].append(c.org())
            if turn > 0:
                return a, b.sym()
            else:
                return c.sym(), c
    else:
        l = s[:len(s)//2]
        r = s[len(s)//2:]
        ldo, ldi = delaunay(l, coords, adj_list)
        rdi, rdo = delaunay(r, coords, adj_list)
        while True:
            if left_of(coords, rdi.org(), ldi):
                ldi = ldi.lnext()
            elif right_of(coords, ldi.org(), rdi):
                rdi = rdi.rprev()
            else:
                break
        basel = connect(rdi.sym(), ldi)
        adj_list[basel.org()].append(basel.dest())
        adj_list[basel.dest()].append(basel.org())
        if ldi.org() == ldo.org():
            ldo = basel.sym()
        if rdi.org() == rdo.org():
            rdo = basel
        while True:
            lcand = basel.sym().onext()
            if right_of(coords, lcand.dest(), basel):
                while in_circle(coords, basel.dest(), basel.org(), lcand.dest(), lcand.onext().dest()):
                    t = lcand.onext()
                    adj_list[lcand.org()].remove(lcand.dest())
                    adj_list[lcand.dest()].remove(lcand.org())
                    delete_edge(lcand)
                    lcand = t
            rcand = basel.oprev()
            if right_of(coords, rcand.dest(), basel):
                while in_circle(coords, basel.dest(), basel.org(), rcand.dest(), rcand.oprev().dest()):
                    t = rcand.oprev()
                    adj_list[rcand.org()].remove(rcand.dest())
                    adj_list[rcand.dest()].remove(rcand.org())
                    delete_edge(rcand)
                    rcand = t
            if not right_of(coords, lcand.dest(), basel) and not right_of(coords, rcand.dest(), basel):
                break
            if not right_of(coords, lcand.dest(), basel) or (right_of(coords, rcand.dest(), basel) and
                    in_circle(coords, lcand.dest(), lcand.org(), rcand.org(), rcand.dest())):
                basel = connect(rcand, basel.sym())
                adj_list[basel.org()].append(basel.dest())
                adj_list[basel.dest()].append(basel.org())
            else:
                basel = connect(basel.sym(), lcand.sym())
                adj_list[basel.org()].append(basel.dest())
                adj_list[basel.dest()].append(basel.org())
        return ldo, rdo


if __name__ == "__main__":
    main(sys.argv)
