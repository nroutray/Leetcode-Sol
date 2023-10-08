class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        int n =row.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i+=2){
            ds.unionBySize(row[i],row[i+1]);
        }
        int res=0;
        for(int i=0;i<n;i+=2){
            if(ds.findUPar(i)!=ds.findUPar(i+1)){
                res++;
                ds.unionBySize(ds.findUPar(i),ds.findUPar(i+1));
            }
        }
        return res;
    }
};