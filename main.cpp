#include <iostream>
#include <cstring>

using namespace std;

template<typename dataType>
class Vector {
private:
    dataType *mass;
    int index;
    int size;
public:
    Vector() {
        index = 0;
        size = 0;
        mass = new dataType[size];
    }

    Vector(int s) {
        index = 0;
        size = s;
        mass = new dataType[size];
    }

    ~Vector() {
        delete[] mass;
    }

    bool insert(dataType arg) {
        if (index < size) {
            mass[index] = arg;
            index++;
            return true;
        } else {
            size = size + 1;
            dataType *ptr = new dataType[size];
            memcpy(ptr, mass, size * sizeof(dataType));
            delete[] mass;
            mass = ptr;
            mass[index] = arg;
            index++;
            return false;
        }
    }

    dataType out(int ind) {
        if (ind > size) return -1;
        else return mass[ind];
    }

    string isEmpty() {
        if (size <= 0) {
            return "Yes! It's empty!";
        } else {
            return "It's not empty";
        }
    }

    int sizeOf() {
        return size;
    }

    void pushBack(dataType arg) {
        size = size + 1;
        dataType *ptr = new dataType[size];
        memcpy(ptr, mass, size * sizeof(dataType));
        delete[] mass;
        mass = ptr;
        mass[size - 1] = arg;
    }


    void operator=(const Vector &obj) {
        this->size = obj.size;
        this->mass = new dataType[obj.size];
        for (int i = 0; i < obj.size; i++){
            this->mass[i] = obj.mass[i];
        }
    }

    void operator[](const Vector &obj) {
        cout << "this" << this << endl;

    }


};

int main() {
    Vector<int> gg(5);

    for (int i = 0; i < 7; i++) {
        gg.insert(i);
        cout << gg.out(i) << endl;
    }
    Vector<int> wp(2);

    wp = gg;

    gg.pushBack(228);
    cout << endl << "gg after pushback";
    for (int i = 0; i < 8; i++) {
        cout << gg.out(i) << endl;
    }
    cout<<endl;
    for (int i = 0; i < 10; i++) {
        cout << wp.out(i) << endl;
    }
    cout << "Is it empty ? - " << gg.isEmpty() << endl << "that's the size - " << gg.sizeOf() << endl;

    return 0;
}