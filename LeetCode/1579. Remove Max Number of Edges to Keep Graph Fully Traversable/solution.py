from typing import List

# Runtime 1551ms Beats 99.09%
# Memory 56.26MB Beats 85.07%
class DisjointSet:
    def __init__(self, n: int) -> None:
        self.parent = [i for i in range(n)]
        self.rank = [1] * n


    def find(self, x: int) -> int:
        while x != self.parent[x]:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x
        

    def union(self, x: int, y: int) -> bool:
        root_y = self.find(y)
        root_x = self.find(x)
        
        if root_y == root_x:
            return False
        
        if self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
            self.rank[root_x] += self.rank[root_y]
        else:
            self.parent[root_x] = root_y
            self.rank[root_y] += self.rank[root_x]

        return True



class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        connections = 0
        alice_connections = 0
        bob_connections = 0

        dset_alica = DisjointSet(n)
        dset_bob = DisjointSet(n)

        for typeOfEdge, node1, node2 in edges:
            if typeOfEdge == 3:
                u1 = dset_alica.union(node1-1, node2-1)
                u2 = dset_bob.union(node1-1, node2-1)
                if u1 or u2:
                    connections += 1

        for typeOfEdge, node1, node2 in edges:
            if typeOfEdge == 1 and dset_alica.union(node1-1, node2-1):
                alice_connections += 1
            elif typeOfEdge == 2 and dset_bob.union(node1-1, node2-1):
                bob_connections += 1

        if connections + alice_connections < n-1:
            return -1
        if connections + bob_connections < n-1:
            return -1
            
        return len(edges) - (connections + alice_connections + bob_connections)




if __name__ == '__main__':
    n = 4
    edges = [[3,1,2], [3,3,4], [1,1,3],[2,2,4]]
    sol = Solution()
    ans = sol.maxNumEdgesToRemove(n, edges)
    print(ans)
