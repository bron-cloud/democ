#include <iostream>
using namespace std;
#include<ctime>
#include<cstdlib>
class character {
public:
	character(int HP, int speed, int damage, int defenseValue, string name) :
		m_speed(speed), m_HP(HP), m_damage(damage), m_defenseValue(defenseValue), m_name(name) {};
	virtual void attack(character& character) = 0;
	virtual void specialAttack(character& character) = 0;
	int  getHP() {
		return m_HP;
	};
	void takedamage(int damageDone) {
		m_HP -= damageDone;
		if (m_HP < 0) { m_HP = 0; }
	}
	int getdenfenseValue() {
		return m_defenseValue;
	};
	string getname() {
		return m_name;
	}
	int getspeed() {
		return m_speed;
	}
	bool ignore = false;
	bool confused = false;
	int roundcount = 1;
protected:
	int m_HP;
	int m_damage;
	string m_name;
	int m_speed;
	int m_defenseValue;
};
class bronya :public character {
private:
	
	void attack(character& character) override {
		if (ignore || rand() % 100 < 15) {
			ignore = false;
			int damageDone = m_damage;
			cout << "bronya本次攻击无视防御" << endl;
			cout << m_name << "造成了" << damageDone << "点伤害" << endl;
			character.takedamage(damageDone);
			cout << character.getname() << "的剩余血量为" << character.getHP()<<endl;
		}
		else {
			int damageDone = m_damage - character.getdenfenseValue();
			cout << m_name << "造成了" << damageDone << "点伤害" << endl;
			character.takedamage(damageDone);
			cout << character.getname() << "的剩余血量为" << character.getHP()<<endl;
		}

	}
	void specialAttack(character& character)override {
		if (roundcount % 3 ==0) //三回合发动一次主动技能
		{
			int damageDone = 5 * (16 - character.getdenfenseValue());
			if (rand() % 100 < 20) {
				character.confused = true;
				cout << "bronya的本次攻击造成了对手混乱" << endl;
				cout << m_name << "造成了" << damageDone << "点伤害" << endl;
				character.takedamage(damageDone);
				cout << character.getname() << "的剩余血量为" << character.getHP()<<endl;
			}
			else {
				cout << "bronya的本次攻击没有造成了对手混乱" << endl;
				cout << m_name << "造成了" << damageDone << "点伤害" << endl;
				character.takedamage(damageDone);
				cout << character.getname() << "的剩余血量为" << character.getHP()<<endl;
			}
		}
	}
public:
	bronya(int HP, int speed, int damage, int defenseValue, string name) :
		character(HP, speed, damage, defenseValue, name) {}

};
class dreamseeker :public character {
public:dreamseeker(int HP, int speed, int damage, int defenseValue, string name) :
	character(HP, speed, damage, defenseValue, name) {}

private:
	bool boostdamage = false;
	void attack(character& character)override {
		
			if (m_HP < 50) {
				cout << getname() << "触发了被动技能,攻击力提高到30" << endl;
				m_damage = 30;
				boostdamage = true;
			}
			if (!boostdamage && rand() % 100 < 70) {
				cout << getname() << "博弈成功了，攻击力提高到24" << endl;
				m_damage = 24;
				boostdamage = false;
			}

			int damageDone = m_damage - character.getdenfenseValue();
			cout << m_name << "造成了" << damageDone << "点伤害" << endl;
			character.takedamage(damageDone);
			cout << character.getname() << "的剩余血量为" << character.getHP()<<endl;
		
	};
	void specialAttack(character& character)override {
		if (roundcount % 3 == 0) {
			if (m_HP < 50) {
				cout << getname() << "触发了被动技能,攻击力提高到30" << endl;
				m_damage = 30;
				boostdamage = true;
			}
			if (!boostdamage && rand() % 100 < 70) {
				cout << getname() << "博弈成功了，攻击力提高到24" << endl;
				m_damage = 24;
				boostdamage = false;
			}
			int damageDone = m_damage * 1.3;
			cout << m_name << "造成了" << damageDone << "点伤害" << endl;
			character.takedamage(damageDone);
			cout << character.getname() << "的剩余血量为" << character.getHP() << endl;
		}
		};
};

int roundcount = 1;
void fight(character& player1, character& player2) {
	while (player1.getHP() > 0 && player2.getHP() > 0) {
		cout << "-----------round" << roundcount <<"----------"<< endl;
		if (player1.getspeed ()> player2.getspeed())
		{
			player1.attack(player2);
			player1.specialAttack(player2);
			if (player1.getHP() == 0) {
				cout << player2.getname() << " 取得胜利" << endl;
				break;
			}
			if (player2.getHP() == 0) {
				cout << player1.getname() << " 取得胜利" << endl;
				break;
			}

			player2.attack(player1);
			player2.specialAttack(player1);
		}
		else {
			player2.attack(player1);
			player2.specialAttack(player1);
			if (player1.getHP() == 0) {
				cout << player2.getname() << " 取得胜利" << endl;
				break;
			}
			if (player2.getHP() == 0) {
				cout << player1.getname() << " 取得胜利" <<endl;
				break;
			}
			player1.attack(player2);
			player1.specialAttack(player2);
		}
		roundcount++;
		
	}
}
	void test01() {
		srand(time(0));
		bronya b1(100, 20, 18, 6, "bronya");
		dreamseeker d1(100, 21, 16, 8, "dreamseeker");
		fight(b1, d1);
	}
	int main() {
		test01();
		return 0;
	}