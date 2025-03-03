#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructeur pour initialiser un noeud
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // Fonction récursive pour insérer un élément
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    // Fonction récursive pour rechercher un élément
    Node* search(Node* node, int data) {
        if (node == nullptr || node->data == data) {
            return node;
        }
        if (data < node->data) {
            return search(node->left, data);
        }
        return search(node->right, data);
    }

    // Fonction récursive pour supprimer un élément
    Node* remove(Node* node, int data) {
        if (node == nullptr) {
            return node;
        }

        if (data < node->data) {
            node->left = remove(node->left, data);
        } else if (data > node->data) {
            node->right = remove(node->right, data);
        } else {
            // Nœud avec un ou aucun enfant
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Nœud avec deux enfants : 
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Trouver le nœud avec la valeur minimale (utilisé pour la suppression)
    Node* minValueNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Parcours infixe (Gauche, Racine, Droite)
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    // Fonction publique pour insérer un élément
    void insert(int data) {
        root = insert(root, data);
    }

    // Fonction publique pour rechercher un élément
    bool search(int data) {
        return search(root, data) != nullptr;
    }

    // Fonction publique pour supprimer un élément
    void remove(int data) {
        root = remove(root, data);
    }

    // Fonction publique pour le parcours infixe
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST arbre;

    cout << "insertion des elements : 5 3 7 2 4 6 8" << endl;
    arbre.insert(5);
    arbre.insert(3);
    arbre.insert(7);
    arbre.insert(2);
    arbre.insert(4);
    arbre.insert(6);
    arbre.insert(8);

    cout << "Parcours infixe : ";
    arbre.inorder();

    cout << "recherche de 4 : ";
    if (arbre.search(4)) {
        cout << "trouvé" << endl;
    } else {
        cout << "non trouvé" << endl;
    }

    cout << "Suppression de 4" << endl;
    arbre.remove(4);

    cout << "Parcours infixe apres suppression : ";
    arbre.inorder();

    return 0;
}