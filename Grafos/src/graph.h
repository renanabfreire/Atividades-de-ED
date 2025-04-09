#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> // For exit()

class Graph{
    private:
        size_t num_vertices;
        std::vector<std::vector<int>> matrix;
        std::vector<std::vector<int>> list;

    public:
        Graph();
        ~Graph();

        void read(char*);
        int getDimension();
        void print();
        void dfs_recursive(int,std::vector<bool>&, std::vector<int>&);
        std::vector<int> dfs(int);
        std::pair<std::vector<int>, std::vector<int>> dfs_pilha(int);
        std::pair<std::vector<int>, std::vector<int>> dfs_busca(int, int);
        int num_comp(int);
        std::pair<std::vector<int>, std::vector<int>> bfs(int);
        std::pair<std::vector<int>, std::vector<int>> bfs_busca(int,int);
};

#endif // GRAPH_H