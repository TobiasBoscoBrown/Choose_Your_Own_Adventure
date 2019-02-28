#include "Player.h"

Player::Player(string na, int ag, string ra) {
age = ag;
name = na;
race = ra;
}

int Player::get_Age() {
	return age;
}

string Player::get_Name() {
	return name;
}

string Player::get_Race() {
	return race;
}

void Player::introduce() {
	cout << "My name is " << name << " and I am a " << age << " year(s) old " << race << "!" << endl;
}
int Player::age;