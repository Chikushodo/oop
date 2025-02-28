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
        cout << "Создана боевая единица типа: " << unitType << endl;
        cout << "Общее здоровье армии: " << totalHealth << endl;
        cout << "Общая боевая мощь армии: " << totalDamage << endl;
    }

    ~CombatUnit() {
        totalHealth -= health;
        totalDamage -= damage;
        cout << "Уничтожена боевая единица типа: " << unitType << endl;
        cout << "Общее здоровье армии: " << totalHealth << endl;
        cout << "Общая боевая мощь армии: " << totalDamage << endl;
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
        cout << "Здоровье " << unitType << " изменено.  Новое значение: " << health << endl;
        cout << "Общее здоровье армии: " << totalHealth << endl;
    }

    void setDamage(int newDamage) {
        totalDamage -= damage; 
        damage = newDamage;
        totalDamage += damage; 
        cout << "Урон " << unitType << " изменен. Новое значение: " << damage << endl;
        cout << "Общая боевая мощь армии: " << totalDamage << endl;
    }

    void takeDamage(int damageTaken) {
        int prevHealth = health;
        health -= damageTaken;
        if (health < 0) {
            health = 0;
        }
        totalHealth -= (prevHealth - health); 
        cout << unitType << " получил " << damageTaken << " урона.  Осталось здоровья: " << health << endl;
        cout << "Общее здоровье армии: " << totalHealth << endl;

        if (health == 0) {
            cout << unitType << " уничтожен!" << endl;
        }
    }

    void dealDamage(CombatUnit& target) {
        cout << unitType << " наносит " << damage << " урона " << target.unitType << endl;
        target.takeDamage(damage);
    }
};
int CombatUnit::totalHealth = 0;
int CombatUnit::totalDamage = 0;

int main() {
    CombatUnit unit1(100, 20, "Warrior");
    CombatUnit unit2(80, 15, "Archer");

    cout << "Общее здоровье армии: " << CombatUnit::getTotalHealth() << endl;
    cout << "Общая боевая мощь армии: " << CombatUnit::getTotalDamage() << endl;

    unit1.setDamage(25);
    unit2.setHealth(90);

    unit1.dealDamage(unit2);

    unit2.takeDamage(50);
    unit2.dealDamage(unit1);

    CombatUnit* unit3 = new CombatUnit(120, 30, "Tank");
    delete unit3; 
}