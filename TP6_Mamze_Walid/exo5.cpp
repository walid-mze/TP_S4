#include <iostream>
#include <list>
#include <unordered_map>
#include <memory>

class LRUCache {
private:
    struct Node {
        int key;
        std::shared_ptr<int> value;
        Node(int k, int v) : key(k), value(std::make_shared<int>(v)) {}
    };

    int capacity;
    std::list<std::shared_ptr<Node>> cache;
    std::unordered_map<int, std::weak_ptr<Node>> map;

    void moveToFront(std::shared_ptr<Node> node) {
        cache.remove(node);
        cache.push_front(node);
    }

public:
    LRUCache(int cap) : capacity(cap) {}

    void access(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            if (auto node = it->second.lock()) {
                moveToFront(node);
                return;
            }
        }

        if (cache.size() >= capacity) {
            auto last = cache.back();
            map.erase(last->key);
            cache.pop_back();
        }

        auto newNode = std::make_shared<Node>(key, value);
        cache.push_front(newNode);
        map[key] = newNode;
    }

    void printCache() {
        for (const auto& node : cache) {
            std::cout << *(node->value) << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LRUCache cache(4);
    cache.access(1, 1);
    cache.access(2, 2);
    cache.access(3, 3);
    cache.access(1, 1);
    cache.access(4, 4);
    std::cout << "Cache actuel : ";
    cache.printCache();
    
    cache.access(5, 5);
    std::cout << "Accès à la clé 5 -> Eviction de la clé 2\n";
    std::cout << "Cache actuel : ";
    cache.printCache();
    
    return 0;
}
