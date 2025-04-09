#include "graph.h"

int main(int argc, char** argv){
    Graph g;
    g.read(argv[1]);

    g.print();

//    g.bfs_busca(144, 0);
    for(int i=0; i<g.getDimension(); i++){
        for(int j=0; j<g.getDimension(); j++){
            if(i != j){
                std::cout << "========== CAMINHO ENTRE " << i << " E " << j << " ==========\n\n\t+ BFS:\n";
                g.bfs_busca(i, j);
                std::cout << "\n\t+ DFS:\n";
                g.dfs_busca(i, j);
                std::cout << std::endl;
            }
        }
    }

    return 0;
}