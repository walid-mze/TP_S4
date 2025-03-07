#include <iostream>
#include <vector>
using namespace std;


class Shared_ptr{
private:
    int* ptr;
    int* count;
public: 
    Shared_ptr(int* ptr){
        this->ptr = ptr;
        count = new int(1);
        cout << "Création d'un SharedPtr vers " << (*ptr) <<endl;
        cout << "Nombre de références : " << *count << endl;
    }
    ~Shared_ptr(){
        (*count)--;
        if (*count == 0){
            delete ptr;
            delete count;
            cout << "Destruction d'un SharedPtr"<<endl;
            cout << "Objet supprimé"<<endl;
        }
        else{
            cout << "Destruction d'un SharedPtr"<<endl;
            cout << "Nombre de références : " << *count << endl;
        }

    }
    Shared_ptr(const Shared_ptr& other){
        ptr = other.ptr;
        count = other.count;
        (*count)++;
        cout << "Création d'une copie"<<endl;
        cout << "Nombre de références : " << *count << endl;
    }
    int use_count(){
        return *count;
    }
    int* get(){
        return ptr;
    }

};

int main(){
    Shared_ptr p1(new int(10));
    Shared_ptr p2 = p1;
    return 0;
}