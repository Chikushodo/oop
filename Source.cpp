#include <iostream>
#include <string>

using namespace std;

class BaseEnemy {
public:
    BaseEnemy() {
        cout << "Вызван конструктор BaseEnemy" << endl;
    }
    virtual void DoDamage() = 0; 

    virtual void Die() = 0; 

    virtual void ChasePlayer() = 0; 

    virtual ~BaseEnemy() {
        cout << "Вызван деструктор BaseEnemy" << endl;
    }
};

class Goblin : public BaseEnemy {
public:
    Goblin() {
        cout << "Вызван конструктор Goblin" << endl;
    }

    void DoDamage() override { 
        cout << "Гоблин наносит 5 единиц урона!" << endl;
    }

    void Die() override {
        cout << "Гоблин умирает с противным хрипом!" << endl;
    }

    void ChasePlayer() override {
        cout << "Гоблин бежит за игроком, размахивая дубиной!" << endl;
    }

    ~Goblin() override {
        cout << "Вызван деструктор Goblin" << endl;
    }
};

class Orc : public BaseEnemy {
public:
    Orc() {
        cout << "Вызван конструктор Orc" << endl;
    }

    void DoDamage() override {
        cout << "Орк бьет топором, нанося 10 единиц урона!" << endl;
    }

    void Die() override {
        cout << "Орк падает, издав боевой клич!" << endl;
    }

    void ChasePlayer() override {
        cout << "Орк несется к игроку с яростным ревом!" << endl;
    }

    ~Orc() override {
        cout << "Вызван деструктор Orc" << endl;
    }
};

int main() {

    BaseEnemy* goblin = new Goblin();
    BaseEnemy* orc = new Orc();

    goblin->DoDamage();   
    goblin->ChasePlayer();
    goblin->Die();

    orc->DoDamage();     
    orc->ChasePlayer();
    orc->Die();

    delete goblin; 
    delete orc;    
}