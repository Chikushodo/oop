#include <iostream>
#include <string>
using namespace std;
class CombatUnit {
private:
    int health;
    int damage;
    string unitType;

    static int totalHealth;
    static int totalDamage;

public:
    CombatUnit(int health, int damage, std::string unitType) : health(health), damage(damage), unitType(unitType) {
        totalHealth += health;
        totalDamage += damage;
        cout << "������� ������ ������� ����: " << unitType << endl;
        cout << "����� �������� �����: " << totalHealth << endl;
        cout << "����� ������ ���� �����: " << totalDamage << endl;
    }

    ~CombatUnit() {
        totalHealth -= health;
        totalDamage -= damage;
        cout << "���������� ������ ������� ����: " << unitType << endl;
        cout << "����� �������� �����: " << totalHealth << endl;
        cout << "����� ������ ���� �����: " << totalDamage << endl;
    }

    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    string getUnitType() const { return unitType; }
    static int getTotalHealth() { return totalHealth; }
    static int getTotalDamage() { return totalDamage; }

    void setHealth(int newHealth) {
        totalHealth -= health; 
        health = newHealth;
        totalHealth += health; 
        cout << "�������� " << unitType << " ��������.  ����� ��������: " << health << endl;
        cout << "����� �������� �����: " << totalHealth << endl;
    }

    void setDamage(int newDamage) {
        totalDamage -= damage; 
        damage = newDamage;
        totalDamage += damage; 
        cout << "���� " << unitType << " �������. ����� ��������: " << damage << endl;
        cout << "����� ������ ���� �����: " << totalDamage << endl;
    }

    void takeDamage(int damageTaken) {
        int prevHealth = health;
        health -= damageTaken;
        if (health < 0) {
            health = 0;
        }
        totalHealth -= (prevHealth - health); 
        cout << unitType << " ������� " << damageTaken << " �����.  �������� ��������: " << health << endl;
        cout << "����� �������� �����: " << totalHealth << endl;

        if (health == 0) {
            cout << unitType << " ���������!" << endl;
        }
    }

    void dealDamage(CombatUnit& target) {
        cout << unitType << " ������� " << damage << " ����� " << target.unitType << endl;
        target.takeDamage(damage);
    }
};
int CombatUnit::totalHealth = 0;
int CombatUnit::totalDamage = 0;

int main() {
    CombatUnit unit1(100, 20, "Warrior");
    CombatUnit unit2(80, 15, "Archer");

    cout << "����� �������� �����: " << CombatUnit::getTotalHealth() << endl;
    cout << "����� ������ ���� �����: " << CombatUnit::getTotalDamage() << endl;

    unit1.setDamage(25);
    unit2.setHealth(90);

    unit1.dealDamage(unit2);

    unit2.takeDamage(50);
    unit2.dealDamage(unit1);

    CombatUnit* unit3 = new CombatUnit(120, 30, "Tank");
    delete unit3; 
}