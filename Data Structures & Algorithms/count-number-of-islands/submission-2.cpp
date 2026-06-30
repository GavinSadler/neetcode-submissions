
class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        // Initially, all nodes are size 1, they contain themselves
        size = vector(n + 1, 1);

        parent.resize(n + 1);

        // All nodes are their own parent initially
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Grab the parent of a given node
    int find(int node) {
        // Iterate through the vector until we find the node which is its own parent
        if (node != parent[node]) {
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;
        
        if (size[pu] >= size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }

        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        DSU dsu(cols * rows);

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ni = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                
                if (grid[i][j] == '1') {
                    ni++;

                    for(auto& d : directions) {
                        int r = i + d[0];
                        int c = j + d[1];

                        // Disqualify if oob or not an island
                        if (r < 0 ||
                            c < 0 ||
                            r >= rows ||
                            c >= cols ||
                            grid[r][c] != '1')
                            continue;
                        
                        if (dsu.unionBySize(r * cols + c, i * cols + j))
                            ni--;
                    }
                }
            }
        }

        return ni;
    }
};
