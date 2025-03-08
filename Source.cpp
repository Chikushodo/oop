#include <iostream>
#include <string>

using namespace std;

class BaseEnemy {
public:
    BaseEnemy() {
        cout << "������ ����������� BaseEnemy" << endl;
    }
    virtual void DoDamage() = 0; 

    virtual void Die() = 0; 

    virtual void ChasePlayer() = 0; 

    virtual ~BaseEnemy() {
        cout << "������ ���������� BaseEnemy" << endl;
    }
};

class Goblin : public BaseEnemy {
public:
    Goblin() {
        cout << "������ ����������� Goblin" << endl;
    }

    void DoDamage() override { 
        cout << "������ ������� 5 ������ �����!" << endl;
    }

    void Die() override {
        cout << "������ ������� � ��������� ������!" << endl;
    }

    void ChasePlayer() override {
        cout << "������ ����� �� �������, ���������� �������!" << endl;
    }

    ~Goblin() override {
        cout << "������ ���������� Goblin" << endl;
    }
};

class Orc : public BaseEnemy {
public:
    Orc() {
        cout << "������ ����������� Orc" << endl;
    }

    void DoDamage() override {
        cout << "��� ���� �������, ������ 10 ������ �����!" << endl;
    }

    void Die() override {
        cout << "��� ������, ����� ������ ����!" << endl;
    }

    void ChasePlayer() override {
        cout << "��� ������� � ������ � �������� �����!" << endl;
    }

    ~Orc() override {
        cout << "������ ���������� Orc" << endl;
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