// problems: // https://www.geeksforgeeks.org/disjoint-set-data-structures/
// https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/

#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int V;
    public:
        DSU(int V){
            this->V = V;
            rank.resize(V, 0);
            size.resize(V, 1);
            for(int i = 0; i < V; parent.push_back(i++));
        }
        int Find(int node){
            return parent[node] == node ? node : parent[node] = Find(parent[node]);
        }
        void Union(int a, int b){
            // not considerinf rank
            parent[Find(b)] = Find(a);
        }
        void UnionByRank(int a, int b){
            int p1 = Find(a), p2 = Find(b);
            if(p1 == p2) return ;
            int r1 = rank[p1], r2 = rank[p2];
            if(r1 > r2) parent[p2] = p1;
            else if(r1 < r2) parent[p1] = p2;
            else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
        void UnionBySize(int a, int b){
            int p1 = Find(a), p2 = Find(b);
            if(p1 == p2) return ;
            int s1 = size[p1], s2 = size[p2];
            if(s1 < s2){
                parent[p1] = p2;
                size[p2] += size[p1];
            }else{
                parent[p2] = p1;
                size[p1] += size[p2];
            }
        }
        void display(){
            for(auto x: size) cout << x << " ";
            cout << "\n";
        }
};

int main(int argc, char const *argv[])
{
    DSU dsu(5);
    dsu.UnionByRank(0, 1);
    cout << "Parent of 1 is " << dsu.Find(1) << endl;
    dsu.Union(0, 2);
    cout << "Parent of 2 is " << dsu.Find(2) << endl;
    cout << "Parent of 0 is " << dsu.Find(0) << endl;

    DSU dsu2(5);
    dsu2.UnionBySize(1, 2);
    dsu2.UnionBySize(3, 4);
    dsu2.UnionBySize(1, 3);
    dsu2.UnionBySize(2, 4);
    dsu2.display();
    return 0;
}
