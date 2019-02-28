#pragma once
#include <string>
#include <iostream>
using namespace std;
class Player
{
private:
	string name;
	string race;

public:
	static int age;
	Player(string na, int ag, string ra);
	string get_Name();
	int get_Age();
	string get_Race();

public:
	void introduce();

};