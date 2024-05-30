class UnionFind { 
    vector<int> root;
public:
    UnionFind(int n):root(n) {
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        if (x == root[x]){
            return x;
        }else{
            root[x] = Find(root[x]);
            return root[x];
        }
    }

    void Union(int x, int y){ 
        x= Find(x);
        y= Find(y);
        if (x == y)
            return;
        else
            root[y]=x;    
    }

    bool connected(int x, int y){ 
        return Find(x) == Find(y); 
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind G(n);// graph G with n vertices
        for (auto& e: edges){
            G.Union(e[0], e[1]);// edge between
        }
        return G.connected(source, destination);
    }
};






////////////////////////////////////////
// TLE, slow
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination) 
            return true;

        int m = edges.size();
        if(m == 0)
            return false;

        unordered_set<int> visited;
        bool pathFounded = false;

        for(int i = 0; i < m; i++){
            if(edges[i][0] == source){
                pathFounded = visitNext(edges, visited, edges[i][1], destination);
            }else if(edges[i][1] == source){
                pathFounded = visitNext(edges, visited, edges[i][0], destination);
            }

            //visited.clear();
            if(pathFounded)
                return true;
        }

        return false;
    }

    bool visitNext(vector<vector<int>>& edges, unordered_set<int> visited, int source, int destination){
        visited.insert(source);
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == source){

                if(edges[i][1] == destination)
                    return true;

                if(visited.count(edges[i][1]))
                    continue;

                if(visitNext(edges, visited, edges[i][1], destination))
                    return true;

            }else if(edges[i][1] == source){

                if(edges[i][0] == destination)
                    return true;

                if(visited.count(edges[i][0]))
                    continue;

                if(visitNext(edges, visited, edges[i][0], destination))
                    return true;
            }
        }

        return false;
    }
};