#include <iostream>
#include <memory>

using namespace std;

struct MemoryBlock {
    int size;
    MemoryBlock(int s) : size(s) {
        cout << "Bloc de mémoire alloué de " << size << " unités." << endl;
    }
};

unique_ptr<MemoryBlock> fusionner(unique_ptr<MemoryBlock> b1, unique_ptr<MemoryBlock> b2) {
    int new_size = b1->size + b2->size;
    cout << "Fusion des deux blocs : " << new_size << " unités." << endl;
    unique_ptr<MemoryBlock> new_block = make_unique<MemoryBlock>(new_size);
    return new_block;
}

int main() {
    unique_ptr<MemoryBlock> block1 = make_unique<MemoryBlock>(100);
    unique_ptr<MemoryBlock> block2 = make_unique<MemoryBlock>(200);
    
    unique_ptr<MemoryBlock> block3 = fusionner(move(block1), move(block2));
    cout <<"Liberation de la mémoire." << endl;
    return 0; // Les destructeurs des unique_ptr libèrent la mémoire automatiquement
}
