#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Nombre de sommets
    std::vector<int>* adj; // Pointeur vers un tableau contenant les listes d'adjacence

    void dfs(int v, bool visited[]) {
        // Marquer le sommet actuel comme visité et l'afficher
        visited[v] = true;
        std::cout << v << " ";

        // Répéter pour tous les sommets adjacents à ce sommet
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                dfs(*i, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        vector<int>* tmp = new vector<int>[V];
        adj = tmp;
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Ajouter w à la liste d'adjacence de v
    }

    void main_dfs(int v) {
        // Marquer tous les sommets comme non visités
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        // Appeler la fonction utilitaire DFS pour le sommet donné
        dfs(v, visited);

        delete[] visited;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 2);

    std::cout << "Parcours en profondeur à partir du sommet 0 : ";
    g.main_dfs(0);
    cout << endl;
    return 0;
}