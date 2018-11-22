//  Alvin Teng
//  Assignment7.cpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Tower {
private:
    vector<string> disks;
public:
    Tower (string name, int size, bool isInitialTower) {
        this->name = name;
        if(isInitialTower){
            for (int i = size; i > 0 ; i--) {
                this->pushDisk(to_string(i));
            }
        }

    }
    string name;
    
    void pushDisk(string i) {
        this->disks.push_back(i);
    }
    char popDisk() {
        this->disks.pop_back();
        return 0;
    }
    string Print() {
        string output = "Tower: " + this->name + ": ";
        for (auto disk: disks) {
            output = output + disk + ", ";
        }
        return output;
    }
};
void hanoi(int, Tower*, Tower*, Tower*);

int main() {
    auto A = new Tower("A", 3, true);
    auto B = new Tower("B", 3, false);
    auto C = new Tower("C", 3, false);

    cout << A->Print() << endl;
    cout << B->Print() << endl;
    cout << C->Print() << endl;
    hanoi(3, A, B, C);
    return 0;
}

void hanoi (int disks, Tower* source, Tower* target, Tower* aux) {
    if (disks > 0) {
        hanoi(disks - 1, source, aux, target);
        cout << "Move disk " << disks << " from " << source->name << " to " << target->name << endl;
        source->popDisk();
        target->pushDisk(to_string(disks));
        cout << source->Print() << endl;
        cout << target->Print() << endl;
        cout << aux->Print() << endl;
        hanoi (disks - 1, aux, target, source);
    }
}
