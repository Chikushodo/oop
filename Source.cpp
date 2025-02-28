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
        cout << "Имя: " << name << ", Вес: " << weight << ", Вид: " << species << endl;
    }

    string getName() const { return name; }
    int getWeight() const { return weight; }
};

class Cat : public Animal {
public:
    Cat(string name, int weight) : Animal(name, weight, "Кошка") {}

};

class Dog : public Animal {
public:
    Dog(string name, int weight) : Animal(name, weight, "Собака") {}
};

int main() {
    Cat cat1("Муська", 4);
    Cat cat2("Барсик", 5);
    Dog dog1("Бобик", 15);
    Dog dog2("Рекс", 20);

    cout << "Информация о кошках:" << endl;
    cat1.print();
    cat2.print();

    cout << "\nИнформация о собаках:" << endl;
    dog1.print();
    dog2.print();
}