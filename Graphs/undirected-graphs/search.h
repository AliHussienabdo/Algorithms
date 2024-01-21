#include "graph.h"
#include <vector>
using namespace std;

class Search{
    public:
        Search(Graph G, int V){
            Adj = G.getAdj(V);
        }
        bool isConnected(int s){
            for(int i = 0; i < Adj.size(); i++){
                if(Adj[i] == s) return true;
            }
            return false;
        }
        int count(){
            return Adj.size();
        }
    private:
        vector<int> Adj;
};