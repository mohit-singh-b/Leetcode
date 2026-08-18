class dsu {
    vector <int> parent , size;

    public : 
        dsu(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for ( int i = 0 ; i < n+1 ; i++)
                parent[i] = i;
        }

        int boss(int n){
            if ( n == parent[n])
                return n;
            return parent[n] = boss(parent[n]);
        }

        bool unions(int a, int b){
            int ba = boss(a);
            int bb = boss(b);
            if ( ba == bb)return false;
            if ( size[ba] > size[bb]){
                parent[bb] = ba;
                size[ba]+=size[bb];
            }
            else {
                parent[ba] = bb;
                size[bb]+=size[ba];
            }
            return true;
        }
        int countboss(){
            int count = 0;
            for ( int i = 0 ; i < parent.size() ; i++){
                if ( parent[i] == i)
                    count++;
            }
            return count;
        }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        dsu ds(n-1);
        int wires = 0;
        int heads = 0;

        for ( auto& edge : connections){
            int a = edge[0];
            int b = edge[1];
            if ( !ds.unions(a,b))wires++;
        }
        heads = ds.countboss();

        if ( heads == 1)
            return 0;
        if ( heads-1 >wires)
            return -1;
        return heads-1;
    }
};