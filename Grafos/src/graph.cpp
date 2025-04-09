#include "graph.h"

Graph::Graph(){}

Graph::~Graph(){}

void Graph::read(char* fileName){
    std::ifstream f(fileName);
    
    if (!f.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }
    
    int n;
    f >> n;
    f.ignore();
    
    this->num_vertices = n;
    
    std::string line;
    getline(f, line);
    for(int i=0; i<n; i++) {
        getline(f, line);
        size_t start = 0;

        std::vector<int> temp_line;
        std::vector<int> temp_matrix;

        for(int j=0; j<n; j++){
            size_t pos = line.find('\t', start);
            std::string token;
            if (pos == std::string::npos) {
                token = line.substr(start);
                start = line.length(); // End the loop after this token.
            } else {
                token = line.substr(start, pos - start);
                start = pos + 1;
            }

            token.erase(0, token.find_first_not_of(" \n\r\t"));
            token.erase(token.find_last_not_of(" \n\r\t") + 1);
            int value = stoi(token);

            temp_matrix.push_back(value);
            if(value != 0) temp_line.push_back(j);
        }
        this->matrix.push_back(temp_matrix);
        if(!temp_line.empty())
            this->list.push_back(temp_line);
        else
            this->list.push_back({-1});
    }
}

void Graph::print(){
    std::cout << "Número de Vértices: " << this->num_vertices << std::endl;
    std::cout << "Matriz de adjacência:" << std::endl;

    for(int i=0; i<this->matrix.size(); i++){
        for(int j=0; j<this->matrix[i].size()-1; j++){
            std::cout << this->matrix[i][j] << " - ";
        }

        std::cout << this->matrix[i].back() << std::endl;
    }

    std::cout << "\nLista de Adjacência:" << std::endl;

    for(int i=0; i<this->list.size(); i++){
        for(int j=0; j<this->list[i].size()-1; j++){
            if(!list[i].empty())
                std::cout << this->list[i][j] << " - ";
        }
        std::cout << this->list[i].back() << std::endl;
    }
    std::cout << "\n";
}

int Graph::getDimension(){return this->num_vertices;}

void Graph::dfs_recursive(int v, std::vector<bool>& visitados, std::vector<int>& pred){
    std::cout << "Vetice: " << v << std::endl;
    visitados[v] = true;
    for(auto &u: this->list[v]){
        if(visitados[u] == false){
            pred[u] = v;
            this->dfs_recursive(u, visitados, pred);
        }
    }
}

std::vector<int> Graph::dfs(int source){
    std::vector<int> pred(this->num_vertices, -1);
    std::vector<bool> visitados(this->num_vertices, false);

    dfs_recursive(source, visitados, pred);

    return pred;
}

std::pair<std::vector<int>, std::vector<int>> Graph::dfs_pilha(int source){
    std::vector<bool> visitados(this->num_vertices, false);
    std::vector<int> pred(this->num_vertices, -1);
    std::vector<int> distance(this->num_vertices, -1);
    
    std::list<int> queue; // funcionará tal qual uma pilha

    queue.push_back(source);
    visitados[source] = true;
    distance[source] = 0;

    while(!queue.empty()){
        int v = queue.back();
        queue.pop_back();
        std::cout << "Vertice: " << v << std::endl;

        for(auto& u : this->list[v]){
            if(visitados[u] == false){
                queue.push_back(u);
                visitados[u] = true;
                distance[u] = distance[v] + 1;
                pred[u] = v;
            }
        }
    }

    return {distance, pred};
}

std::pair<std::vector<int>, std::vector<int>> Graph::bfs(int source){
    std::vector<bool> visitados(this->num_vertices, false);
    std::vector<int> pred(this->num_vertices, -1);
    std::vector<int> distance(this->num_vertices, -1);
    
    std::list<int> queue; // funcionará tal qual uma fila

    queue.push_back(source);
    visitados[source] = true;
    distance[source] = 0;

    while(!queue.empty()){
        int v = queue.front();
        queue.pop_front();
        std::cout << "Vertice: " << v << std::endl;

        for(auto& u : this->list[v]){
            if(visitados[u] == false){
                queue.push_back(u);
                visitados[u] = true;
                distance[u] = distance[v] + 1;
                pred[u] = v;
            }
        }
    }

    return {distance, pred};
}

std::pair<std::vector<int>, std::vector<int>> Graph::dfs_busca(int source, int val){
    std::vector<bool> visitados(this->num_vertices, false);
    std::vector<int> pred(this->num_vertices, -1);
    std::vector<int> distance(this->num_vertices, -1);
    bool achado = false;
    
    std::list<int> queue; // funcionará tal qual uma pilha

    queue.push_back(source);
    visitados[source] = true;
    distance[source] = 0;

    while(!queue.empty()){
        int v = queue.back();
        queue.pop_back();
        std::cout << "Vertice: " << v << std::endl;
        if(v == val){
            achado = true;
            break;
        }

        for(auto& u : this->list[v]){
            if(u != -1 && visitados[u] == false){
                queue.push_back(u);
                visitados[u] = true;
                distance[u] = distance[v] + 1;
                pred[u] = v;
            }
        }
    }

    if(!achado) std::cout << "Não há caminho entre os vértices" << std::endl;
    return {distance, pred};
}

std::pair<std::vector<int>, std::vector<int>> Graph::bfs_busca(int source, int val){
    std::vector<bool> visitados(this->num_vertices, false);
    std::vector<int> pred(this->num_vertices, -1);
    std::vector<int> distance(this->num_vertices, -1);
    bool achado = false;
    
    std::list<int> queue; // funcionará tal qual uma fila

    queue.push_back(source);
    visitados[source] = true;
    distance[source] = 0;

    while(!queue.empty()){
        int v = queue.front();
        queue.pop_front();
        std::cout << "Vertice: " << v << std::endl;
        if(v == val){
            achado = true;
            break;
        }

        for(auto& u : this->list[v]){
            if(u != -1 && visitados[u] == false){
                queue.push_back(u);
                visitados[u] = true;
                distance[u] = distance[v] + 1;
                pred[u] = v;
            }
        }
    }

    if(!achado) std::cout << "Não há caminho entre os vértices" << std::endl;
    return {distance, pred};
}

int Graph::num_comp(int source){
    std::vector<int> pred = this->dfs(source);
    int num = 0;
    for (int i = 0; i< this->num_vertices; i++){
        if (pred[i] == -1) num += 1;
    }
    return num;
}