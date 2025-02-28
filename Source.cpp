#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string name;
    int weight;

protected:
    string species; 

public:

    Animal(string name, int weight, string species) : name(name), weight(weight), species(species) {}


    void print() const {
        cout << "���: " << name << ", ���: " << weight << ", ���: " << species << endl;
    }

    string getName() const { return name; }
    int getWeight() const { return weight; }
};

class Cat : public Animal {
public:
    Cat(string name, int weight) : Animal(name, weight, "�����") {}

};

class Dog : public Animal {
public:
    Dog(string name, int weight) : Animal(name, weight, "������") {}
};

int main() {
    Cat cat1("������", 4);
    Cat cat2("������", 5);
    Dog dog1("�����", 15);
    Dog dog2("����", 20);

    cout << "���������� � ������:" << endl;
    cat1.print();
    cat2.print();

    cout << "\n���������� � �������:" << endl;
    dog1.print();
    dog2.print();
}