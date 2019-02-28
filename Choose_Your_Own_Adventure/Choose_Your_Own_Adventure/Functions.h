#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <time.h>
#include "Player.h"
#include "Art.h"

using namespace std;

void begin_Game();

string input_Name() {
	string name1;
	cout << endl;
	cout << "Please enter a name for your character :";
	getline(cin, name1);

	return name1;
}

int input_Age() {
	int age1;
	cout << "Please enter the age of your character :";
	cin >> age1;
	while (std::cin.fail()) {
		std::cout << "You didn't enter an integar, please try again..." << std::endl;
		cout << endl;
		cout << "Please enter the age of your character :";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> age1;
	}
	cin.ignore();
	return age1;
}

string input_Race() {
	string Srace;
	char Crace;
	int counter = 0;

	while (counter == 0) {
		cout << endl;

		cout << "Please choose a race:" << endl;
		cout << "Dwarf (a)" << endl;
		cout << "Elf (b)" << endl;
		cout << "Human (c)" << endl;

		getline(cin, Srace);

		Crace = Srace[0];

		if (Crace == 'a') {
			Srace = "Dwarf";
			counter++;
		}
		else if (Crace == 'b') {
			Srace = "Elf";
			counter++;
		}
		else if (Crace == 'c') {
			Srace = "Human";
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
	return Srace;
}

bool lose() {
	system("cls");
	int counter = 0;
	string Sanswer;
	char Canswer;

	while (counter == 0) {

		system("cls");

		cout << "Sorry... You died!" << endl;
		print_Skull();

		cout << endl;

		cout << "Would you like to try again?" << endl;

		cout << "Yes (y)" << endl;
		cout << "No (n)" << endl;

		getline(cin, Sanswer);

		Canswer = Sanswer[0];

		if (Canswer == 'y') {
			system("cls");
			cout << "Alrighty, lets do it again!" << endl;
			system("Pause");
			begin_Game();
			return true;
		}
		else if (Canswer == 'n') {
			system("cls");
			cout << "Okay, see you next time!" << endl;
			system("Pause");
			exit(0);
			return false;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

bool win(string name) {
	system("cls");
	int counter = 0;
	string Sanswer;
	char Canswer;

	while (counter == 0) {

		system("cls");

		cout << "Congratulations " << name << "! You went on the most epic adventure and won!" << endl;
		print_Mountains();
		cout << "I would like to give a special thanks to Joan G. Stark (aka Spunk) for providing almost all of the art for this project!" << endl;
		
		cout << endl;

		cout << "Would you like to try again?" << endl;

		cout << "Yes (y)" << endl;
		cout << "No (n)" << endl;

		getline(cin, Sanswer);

		Canswer = Sanswer[0];

		if (Canswer == 'y') {
			system("cls");
			cout << "Alrighty, lets do it again!" << endl;
			system("Pause");
			return true;
		}
		else if (Canswer == 'n') {
			system("cls");
			cout << "Okay, see you next time!" << endl;
			system("Pause");
			system("exit");
			return false;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room1(int age, string race) {
	int counter = 0;
	string Sanswer;
	char Canswer;

	while (counter == 0) {

		system("cls");

		cout << "Would you like to go on an adventure?" << endl;

		cout << "Yes (y)" << endl;
		cout << "No (n)" << endl;

		print_Question();

		getline(cin, Sanswer);

		Canswer = Sanswer[0];
	
		if ((Canswer == 'y') && (age < 18)) {
			system("cls");
			cout << "Sorry, you're not old enough to go on an adventure." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Canswer == 'y') && (age >= 60) && (race != "Elf")) {
			system("cls");
			cout << "Sorry, you're too old to go on an adventure." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Canswer == 'y') && (age >= 18) && (race == "Elf") && (age <= 1000)) {
			system("cls");
			cout << "Alrighty! Lets go on this adventure!" << endl;
			counter++;
		}
		else if ((Canswer == 'y') && (age >= 18) && (race == "Elf") && (age >= 1000)) {
			system("cls");
			cout << "Sorry, you're too old to go on an adventure." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Canswer == 'y') && (age >= 18)) {
			system("cls");
			cout << "Alrighty! Lets go on this adventure!" << endl;
			counter++;
		}
		else if (Canswer == 'n') {
			system("cls");
			cout << "Oh... well then you lose." << endl;
			system("Pause");
			lose();
			counter++;
		}
		
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room2(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "What path would you like to take?" << endl;

		cout << "The Fields (a)" << endl;
		cout << "The Mountain (b)" << endl;
		cout << "The Forest (c)" << endl;

		print_Mountains();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if ((Cchoice == 'a') && (race != "Dwarf") && (((age <= 50)) || (race == "Elf"))) {
			system("cls");
			cout << "Alrighty! You go through the fields!" << endl;
			counter++;
		}
		else if ((Cchoice == 'a') && (race != "Dwarf") && (age >= 50)) {
			system("cls");
				cout << "Sorry, you got stuck in a pothole and were too old to climb out." << endl;
				cout << "You starved to death..." << endl;
				system("Pause");
				lose();
				counter++;
		}
		else if ((Cchoice == 'a') && (race == "Dwarf")) {
			system("cls");
			cout << "Sorry, you got stuck in a pothole and weren't tall enough to climb out." << endl;
			cout << "You starved to death..." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Cchoice == 'b') && (race == "Dwarf")) {
			system("cls");
			cout << "You traverse the caves of the mountains without harm." << endl;
			counter++;
		}
		else if ((Cchoice == 'b') && (race != "Dwarf")) {
			system("cls");
			cout << "You got crushed by the cave collapsing because you had no idea what you were doing." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Cchoice == 'c') && (race == "Human")) {
			system("cls");
			cout << "You got lost in the forest." << endl;
			cout << "You end up being eaten by Direwolves..." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Cchoice == 'c') && (race != "Human")) {
			system("cls");
			cout << "You traverse the forest, enjoying all of nature's beauty." << endl;
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room3(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "You come up to an ocean, what do you do?" << endl;

		cout << "Swim (a)" << endl;
		cout << "Build A Raft (b)" << endl;
		cout << "Dig A Tunnel Under It (c)" << endl;

		print_Ocean();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "Um... you drowned." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b') {
			system("cls");
			cout << "You built a raft and began going across the ocean!" << endl;
			counter++;
		}
		else if ((Cchoice == 'c') && (race == "Dwarf")) {
			system("cls");
			cout << "You dug a tunnel under the ocean, but it took you 40 years." << endl;
			if (age + 40 <= 70) {
				counter++;
				Player::age = age + 40;
			}
			else if (age + 40 >= 71){
				cout << "You died of old age and being overworked." << endl;
				system("Pause");
				lose();
			}
		}
		else if ((Cchoice == 'c') && (race != "Dwarf")) {
			system("cls");
			cout << "You dig yourself into quicksand and die." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room4(int age, string race) {
	int counter = 0;
	string Sanswer;
	char Canswer;

	while (counter == 0) {

		system("cls");

		cout << "You get to the other side of the ocean, but you get attacked by a giant pelican! What do you do?" << endl;

		cout << "Fight (f)" << endl;
		cout << "Run (r)" << endl;

		print_Pelican();

		getline(cin, Sanswer);

		Canswer = Sanswer[0];

		if ((Canswer == 'f') && (race == "Elf")) {
			system("cls");
			cout << "You shoot it with 50 arrows before it even gets close." << endl;
			counter++;
		}
		else if ((Canswer == 'f') && (race == "Dwarf")) {
			system("cls");
			cout << "You chop it's head off and cook it over a fire." << endl;
			counter++;
		}
		else if ((Canswer == 'f') && (race == "Human")) {
			system("cls");
			cout << "You get eaten alive by the pelican's massive mouth." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Canswer == 'r') && (race == "Elf")) {
			system("cls");
			cout << "You ran away and got to safety." << endl;
			counter++;
		}
		else if ((Canswer == 'r') && (race == "Dwarf")) {
			system("cls");
			cout << "You're too slow, and it catches up to you and eats you." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Canswer == 'r') && (race == "Human")) {
			system("cls");
				cout << "You narrowly escape with your life." << endl;
				counter++;
		}


		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room5(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "You come across a raging river down a cliff. But, there's a wooden bridge, a log, and a swing rope." << endl;
		cout << "How do you try to get across?" << endl;


		cout << "Wooden Bridge (a)" << endl;
		cout << "Log (b)" << endl;
		cout << "Swing Rope (c)" << endl;

		print_Bridge();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a' && (race == "Human") && (age <= 40)) {
			system("cls");
			cout << "You walk across the bridge without any fear of danger." << endl;
			counter++;
		}

		else if (Cchoice == 'a' && (race == "Human") && (age >= 40)) {
			system("cls");
			cout << "You walk across the bridge, but halfway through you look down and have a heart attack." << endl;
			cout << "You fall down into your riverly grave." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'a' && (race == "Elf")) {
			system("cls");
			cout << "You walk across the bridge, but halfway through you get blown away by a gust of wind." << endl;
			cout << "You fall down into your riverly grave." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'a' && (race == "Dwarf")) {
			system("cls");
			cout << "You walk across the bridge, but halfway through you fall through a plank." << endl;
			cout << "You fall down into your riverly grave." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b' && (race == "Human")) {
			system("cls");
			cout << "You begin walking across the log, but then there was this spider on the log right?" << endl;
			cout << "So you start freaking out and worrying because there's this spider." << endl;
			cout << "In the end, you fall down to your riverly grave trying to avoid it." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b' && (race == "Dwarf")) {
			system("cls");
			cout << "You start walking across the bride, but you end up losing your balance." << endl;
			cout << "You fall down into your riverly grave." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b' && (race == "Elf")) {
			system("cls");
			cout << "Instead of walking on the log, you crawl through the log to the other side." << endl;
			counter++;
		}
		else if (Cchoice == 'c' && (race == "Human")) {
			system("cls");
			cout << "You mistimed this jump by a lot." << endl;
			cout << "You fall down into your riverly grave." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'c' && (race == "Dwarf")) {
			system("cls");
			cout << "You get up on that rope and you yeet yourself to the other side!" << endl;
			counter++;
		}
		else if (Cchoice == 'c' && (race == "Elf")) {
			system("cls");
			cout << "You are so light that when you let go you go flying into a tree." << endl;
			cout << "Unfortunately, both you and the tree end up falling into your riverly grave." << endl;
			cout << "Be nicer to trees bro." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room6(int age, string race) {
	int counter = 0;
	int t;
	string Schoice;
	while (counter == 0) {
	t = clock() + 10000;
	system("cls");

	cout << "\"This statement is false\"" << endl;
	cout << "Is this a true or false statement?" << endl;
	cout << endl;
	cout << "Press enter when you are ready to answer the question." << endl;
	system("Pause");

	system("cls");

	if (clock() >= t) {
		cout << "You thought about this question long enough..." << endl;
		counter++;
	}
	else if (clock() <= t) {
	cout << "True (a)" << endl;
	cout << "False (b)" << endl;

	getline(cin, Schoice);

	cout << "No, think about it harder." << endl;
	system("Pause");
	lose();
		}
	}
}

void room7(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "Ahead of you, you see three cave trolls blocking the path." << endl;
		cout << "How do you try to get across?" << endl;


		cout << "Ask Politely (a)" << endl;
		cout << "Charge Through (b)" << endl;
		cout << "Sneak Around (c)" << endl;

		print_Trolls();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a' && (race == "Human")) {
			system("cls");
			cout << "You ask them politely to let you pass, and they think your face is too darn cute to say no to." << endl;
			counter++;
		}

		else if (Cchoice == 'a' && (race != "Human")) {
			system("cls");
			cout << "You go up to ask politely, but they just pick you up and throw you in a stew." << endl;
			cout << "You get boiled to death." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b' && (race != "Dwarf")) {
			system("cls");
			cout << "You charge in to attack, but one of them accidentaly trips." << endl;
			cout << "You get squashed under troll butt." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b' && (race == "Dwarf")) {
			system("cls");
			cout << "You charge in to attack, and you hack and slash your way through them." << endl;
			counter++;
		}
		else if (Cchoice == 'c' && (race != "Elf")) {
			system("cls");
			cout << "You try sneaking around, but you step on a stick." << endl;
			cout << "In a panic, the trolls throw boulders at your general area and crush you." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'c' && (race == "Elf")) {
			system("cls");
			cout << "You quietly sneak through the trees to get around the trolls." << endl;
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room8(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "You come to a gray barren wasteland that is has bones everywhere." << endl;
		cout << "Out of the silence, you hear a voice." << endl;
		cout << endl;
		cout << "\"You have come far traveler, but do you dare challenge me?\"" << endl;
		cout << "\"If you come any closer, you will be coming to your doom!\"" << endl;
		cout << "\"LEAVE NOW WHILE YOU CAN!\"" << endl;
		cout << endl;
		cout << "What do you do?" << endl;

		cout << "Continue Forward (a)" << endl;
		cout << "Go Back (b)" << endl;

		print_Wasteland();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "You bravely move forward." << endl;
			cout << "But the voice comes again." << endl;
			cout << endl;
			cout << "\"Wait... that usually works. U'm okay, then... \"" << endl;
			cout << "\"PREPARE TO FACE YOUR DOOM!\"" << endl;
			cout << "\"...\"" << endl;
			cout << "\"...\"" << endl;
			cout << "\"...\"" << endl;
			cout << "\"Later.\"" << endl;
			cout << endl;

			counter++;
		}

		else if (Cchoice == 'b') {
			system("cls");
			cout << "You pack up your things, and you turn around and walk away." << endl;
			cout << "You live the rest of your miserable life full of regret because of this moment." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room9(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "You come up to a castle that seems to be the source of all the barreness of this wasteland." << endl;
		cout << "The castle has a mote surrounding it." << endl;
		cout << "How do you try to get across?" << endl;


		cout << "Swim Across (a)" << endl;
		cout << "Yell To Drop The Drawbridge Down (b)" << endl;
		cout << "Attempt To Jump Across (c)" << endl;

		print_Castle();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "You get swallowed by an orca whale." << endl;
			system("Pause");
			lose();
			counter++;
		}

		else if (Cchoice == 'b') {
			system("cls");
			cout << "You yell for the drawbridge to get dropped, and you hear the voice once again." << endl;
			cout << "\"What? I mean, if you say so.\"" << endl;
			cout << "The drawbridge is longer than it looked, so when it drops down, it just crushes you." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'c') {
			system("cls");
			cout << "You jump as long and hard as you can, but you still come up short." << endl;
			system("Pause");
			system("cls");
			cout << "Buuuuuuut." << endl;
			cout << "You land on an invisible platform that goes across." << endl;
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

int room10(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "You get to the other side of the moat, but the door won't open." << endl;
		cout << "Above the door, there is a riddle." << endl;
		cout << "\"In order to enter, you must 'enter' the phrase that asks you to 'continue'.\"" << endl;
		cout << "You also see a couple of windows that are high up." << endl;
		cout << "You once again hear the voice." << endl;
		cout << endl;
		cout << "\"HA! You may have gotten across the moat, but you will never be able to enter my castle!\"" << endl;
		cout << endl;
		cout << "How do you proceed?" << endl;

		cout << "Attempt to answer the riddle (a)" << endl;
		cout << "Climb to the window on the left (b)" << endl;
		cout << "Climb to the window on the right (c)" << endl;
		cout << "Attempt to kick down the door (d)" << endl;

		print_Door();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "'Enter' the answer to the riddle." << endl;
			getline(cin, Schoice);
			if (Schoice == "Press any key to continue...") {
				cout << "Correct!" << endl;
				counter++;
				return 1;
			}
			else {
				cout << "Incorrect!" << endl;
				cout << "The door shoots out a lighning bolt that vaporizes you!" << endl;
				cout << endl;
				cout << "Here's comes a hint to the answer." << endl;
				system("Pause");
				lose();
			}
		}

		else if ((Cchoice == 'b') && (race == "Human")) {
			system("cls");
			cout << "You successfully climb up into the window." << endl;
			counter++;
			return 2;
		}
		else if ((Cchoice == 'b') && (race == "Dwarf")) {
			system("cls");
			cout << "You try to climb up the window, but your big feet slip and you fall into the moat." << endl;
			cout << "You get eaten by an orca whale." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Cchoice == 'b') && (race == "Elf")) {
			system("cls");
			cout << "You try to climb up the window, but you're too used to climbing trees and you fall into the moat." << endl;
			cout << "You get eaten by an orca whale." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Cchoice == 'c') && (race == "Human")) {
			system("cls");
			cout << "You try to climb up to the window, but your small feet slip and you fall into the moat." << endl;
			cout << "You get eaten by an orca whale." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Cchoice == 'c') && (race == "Dwarf")) {
			system("cls");
			cout << "You successfully climb up into the window." << endl;
			counter++;
			return 3;
		}
		else if ((Cchoice == 'c') && (race == "Elf")) {
			system("cls");
			cout << "You try to climb up the window, but you're too used to climbing trees and you fall into the moat." << endl;
			cout << "You get eaten by an orca whale." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'd') {
			system("cls");
			cout << "You kick the door with all your might, and break your leg." << endl;
			cout << "You stumble backwards, forget where the invisible platform is and fall into the moat." << endl;
			cout << "You get eaten by an orca whale." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room10h(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "You come to a window that has two slides going left and right." << endl;
		cout << "Which one do you choose?" << endl;

		cout << "Left (l)" << endl;
		cout << "Right (r)" << endl;

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'r') {
			system("cls");
			cout << "You slide down to the main floor right behind the entrance door." << endl;
			counter++;
		}

		else if (Cchoice == 'l') {
			system("cls");
			cout << "You slide back out to the moat." << endl;
			cout << "You get eaten by an orca whale." << endl;
			print_Whale();
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room10d(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "You come to a window that has two slides going left and right." << endl;
		cout << "Which one do you choose?" << endl;

		cout << "Left (l)" << endl;
		cout << "Right (r)" << endl;

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'l') {
			system("cls");
			cout << "You slide down to the main floor right behind the entrance door." << endl;
			counter++;
		}

		else if (Cchoice == 'r') {
			system("cls");
			cout << "You slide back out to the moat." << endl;
			cout << "You get eaten by an orca whale." << endl;
			print_Whale();
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room11(int age, string race) {
	int counter = 0;
	string Schoice;
	string insult;
	char Cchoice;

	if (race == "Dwarf")
		insult = "a dawdling dwarf";
	else if (race == "Elf")
		insult = "an envious elf";
	else if (race == "Human")
		insult = "a horrible human";

	while (counter == 0) {

		system("cls");

		cout << "In the castle, there are three doors." << endl;
		cout << "Door 1 is labled \"Imminent Doom\"" << endl;
		cout << "Door 2 is labled \"Dungeon Of Death\"" << endl;
		cout << "Door 3 is labled \"Rainbows n' Sunshine\"" << endl;
		cout << endl;
		cout << "Once again, the voice pierces the silence." << endl;
		cout << "\"I can't believe " << insult << " was able to enter my castle!\"" << endl;
		cout << "\"No matter, for you will now be entering your IMMINENT DOOM!\"" << endl;
		cout << endl;
		cout << "Which door do you enter?" << endl;

		cout << "Imminent Doom (a)" << endl;
		cout << "Dungeon Of Death (b)" << endl;
		cout << "Rainbows n' Sunshine (c)" << endl;

		print_Doors();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "You go through the door and enter the other side completely safe." << endl;
			cout << endl;
			cout << "\"What? How? Not even reverse pshychology works on you?\"" << endl;
			cout << "\"You may be proving yourself to be a worthy advisary after all " << race << ".\"" << endl;
			cout << endl;
			counter++;
		}

		else if (Cchoice == 'b') {
			system("cls");
			cout << "You enter the Dungeon of Death and get bludgened to death." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'c') {
			system("cls");
			cout << "You enter Rainbows n' Sunshine room and literally get killed with kindness." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

bool room12(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "Once through the door, you find yourself if a room." << endl;
		cout << "There is a tunnel you may be able to crouch through," << endl;
		cout << "or an entrance to a bar." << endl;
		cout << "Where do you go?" << endl;
		cout << endl;
		cout << "Tunnel (a)" << endl;
		cout << "Bar (b)" << endl;

		print_Tunnel();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if ((Cchoice == 'a') && (race == "Dwarf")) {
			system("cls");
			cout << "You go through the tight fit and crawl to the other side." << endl;
			cout << "The room you come into happens to be a room with a giant cobra." << endl;
			cout << endl;
			counter++;
			return true;
		}
		else if ((Cchoice == 'a') && (race != "Dwarf")) {
			system("cls");
			cout << "You attempt to crawl through, but you get stuck and suffocate." << endl;
			system("pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b') {
			system("cls");
			cout << "You enter the bar and see a bartender." << endl;
			counter++;
			return false;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room12a(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "\"Hey there\" says the bartender." << endl;
		cout << "\"Would you like to try my special new beer?\"" << endl;

		cout << "Yes (y)" << endl;
		cout << "No (n)" << endl;

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if ((Cchoice == 'y') && (age >= 21)) {
			system("cls");
			cout << "The bartender checks your I.D. and gives you some of his beer." << endl;
			cout << endl;
			cout << "\"Thanks for trying it out, just for that I won't kill ya in the Dungeon of Doom.\"" << endl;
			cout << "The bartender pulls a trap door and lands you safely into a room with a giant cobra." << endl;
			cout << endl;
			counter++;
		}
		else if ((Cchoice == 'y') && (age < 21)) {
			system("cls");
			cout << "The bartender checks your I.D. and frowns." << endl;
			cout << "\"It says here that your not old enough to drink, the penalty for this is death.\"" << endl;
			cout << "The bartender pulls a trap door and You enter the Dungeon of Death and get bludgened to death." << endl;
			system("Pause");
			lose();
			cout << endl;
			counter++;
		}
		else if (Cchoice == 'n') {
			system("cls");
			cout << "The bartender frowns." << endl;
			cout << "\"Well then there's no use keeping you around then is there?\"" << endl;
			cout << "The bartender pulls a trap door and You enter the Dungeon of Death and get bludgened to death." << endl;
			system("Pause");
			lose();
			cout << endl;
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room13(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "\"HA!\" says the Voice." << endl;
		cout << "\"I see you've found my pet Scuddles, there will be no escape now!\"" << endl;
		
		cout << endl;

		cout << "What the next move?" << endl;
		cout << "Pet it (a)" << endl;
		cout << "Attack it (b)" << endl;
		cout << "Boomshakalak it (c)" << endl;

		print_Snake();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "You go up to pet it and it eats you." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b') {
			system("cls");
			cout << "You attack it, but it wraps itself around you and crushes you before eating you." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if ((Cchoice == 'c') && (age <= 25)) {
			system("cls");
			cout << "You attempt to boomshakalak it, however you are too young to even know what that means." << endl;
			cout << "You look like a fool while getting eaten." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'c') {
			system("cls");
			cout << "You boomshakalak it, and the snake joins in." << endl;
			cout << "You boomshakalak it all the way to the exit and leave the room." << endl;
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room14(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");
		cout << "You come to a room with five buttons." << endl;
		cout << endl;

		cout << "\"This is impossible! But alas, you will never pick the right button to push!\" exclaims the Voice." << endl;

		cout << endl;

		cout << "What button do you press?" << endl;
		cout << "Red (a)" << endl;
		cout << "Blue (b)" << endl;
		cout << "Green (c)" << endl;
		cout << "White (d)" << endl;
		cout << "Black (e)" << endl;

		print_Button();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "A lava trap door opens up underneath you." << endl;
			cout << "You melt to death..." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b') {
			system("cls");
			cout << "A water hole opens up above you and fills the room with water." << endl;
			cout << "You drown..." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'c') {
			system("cls");
			cout << "Grass grows everywhere and you end up spending your life savings trying to keep it alive." << endl;
			cout << "You go broke and die..." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'e') {
			system("cls");
			cout << "Nothing happens, and non of the other buttons work." << endl;
			cout << "You sit in this room and you starve to death." << endl;
			system("Pause");
			counter++;
		}
		else if (Cchoice == 'd') {
			system("cls");
			cout << "All the buttons get pushed at once, and you hear a loud cranking noise as a door opens up for your escape." << endl;
			cout << "You hear the voice yell exasparated." << endl;
			cout << endl;

			cout << "\"Gosh digity darn it! You broke it! Now I gotta call the death button guy on the weekend.\"" << endl;
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room15(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");
		cout << "You come to a room that is similar to the first entrance of the castle." << endl;
		cout << "In the room, there are three doors." << endl;
		cout << endl;

		cout << "Which door do you enter?" << endl;
		cout << "Imminent Doom (a)" << endl;
		cout << "Dungeon Of Death (b)" << endl;
		cout << "Rainbows n' Sunshine (c)" << endl;

		print_Doors();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "You go through the door and enter the other side completely safe." << endl;
			cout << endl;
			cout << "\"WHAAAT!?! NOT EVEN REVERSE REVERSE PSYCHOLOGY WORKS ON YOU!\"" << endl;
			cout << "\"You are starting to get close to my chamber, perphaps it's time to ramp things up!\"" << endl;
			cout << endl;
			counter++;
		}

		else if (Cchoice == 'b') {
			system("cls");
			cout << "You enter the Dungeon of Death and get bludgened to death." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'c') {
			system("cls");
			cout << "You enter Rainbows n' Sunshine room and literally get killed with kindness." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room16(int age, string race, string name) {
	int counter = 0;
	string Schoice;
	char Cchoice;
	string Sname;
	string Sanswer;

	while (counter == 0) {

		system("cls");
		cout << "You come to a room with mirror with a face on it, the face talks slowly and methodically to you." << endl;
		cout << endl;
	
		cout << "\"In order to pass me, you must answer three questions.\"" << endl;
		cout << "\"WHAT, is your name?\"" << endl;
		
		print_Mirror();

		getline(cin, Sname);
		if (Sname == name) {
			counter++;
		}
		else {
			system("cls");
			cout << "\"Wow, you forgot your own name...\"" << endl;
			cout << "You die of embarassment." << endl;
			system("Pause");
			lose();
			counter++;
		}
	}
	while (counter == 1) {
		cout << endl;
		cout << "\"Very good. Now, WHAT, is your quest?\"" << endl;
		cout << "To find gold (a)" << endl;
		cout << "To go on an adventure (b)" << endl;
		cout << "To seek the holy grail (c)" << endl;

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a') {
			system("cls");
			cout << "\"If your quest is for gold, then you shall have gold!\"" << endl;
			cout << "You turn into a gold statue..." << endl;
			system("Pause");
			lose();
		}

		else if (Cchoice == 'b') {
			counter++;
		}
		else if (Cchoice == 'c') {
			system("cls");
			cout << "\"Oh? Well actually we lost it... a while ago... in the ocean...... of lava.\"" << endl;
			system("Pause");
			lose();
		}
		else {
			cout << "You made a mistake, please try again." << endl;
			system("Pause");
			system("cls");
		}
	}
	while (counter == 2) {
		cout << endl;
		cout << "\"Excellent. Now WHAT, is the average velocity of European laden swallow?\"" << endl;
		cout << "(Answer should be in Miles Per Hour)" << endl;

		getline(cin, Sanswer);

		if (Sanswer == "24") {
			cout << endl;
			cout << "\"Congratulations, you are allowed to pass.\"" << endl;
			counter++;
		}
		else {
			system("cls");
			cout << "INCORRECT!" << endl;
			cout << "You are sent of a bridge that wasn't there before." << endl;
			system("Pause");
			lose();
			counter++;
		}
	}
}

void room17(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");
		cout << "You come to a room that has one door and a staircase going down." << endl;
		cout << endl;
		cout << "\"You may have come this far, however, this is where you will meet your end!\" the Voice says confidently." << endl;
		cout << "\"Either you must have magic in your blood so you can go through the door, or you must enter the Depths of Despair!\"" << endl;
		cout << endl;
		cout << "How do you choose to proceed?" << endl;

		cout << "The Door (a)" << endl;
		cout << "The Depths of Despair (b)" << endl;

		print_Tower();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if ((Cchoice == 'b') && (race == "Human")) {
			system("cls");
			cout << "You enter the Depths of Despair, but life as a human has always been in despair, so you are unaffected." << endl;
			cout << "You take the elavator up." << endl;
			counter++;
		}
		else if ((Cchoice == 'a') && (race == "Human")) {
			system("cls");
			cout << "You enter the door, but because you don't have magic in your blood, you die from the curse." << endl;
			system("Pause");
			lose();
		}
		else if ((Cchoice == 'a') && (race != "Human")) {
			system("cls");
			cout << "You enter the door and continue on the path forward." << endl;
			counter++;
		}
		else if ((Cchoice == 'b') && (race != "Human")) {
			system("cls");
			cout << "You enter the Depths of Despair, and live the rest of your life there." << endl;
			system("Pause");
			lose();
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room18(int age, string race) {
	int counter = 0;
	string Schoice;
	char Cchoice;

	while (counter == 0) {

		system("cls");

		cout << "You come to a long hallway. You hear the familiar Voice once more, but this time it sounds louder." << endl;
		cout << "\"You will never be able to get across this hallway to the door of my room!\"" << endl;
		cout << "How do you try to get across?" << endl;

		cout << "Run (a)" << endl;
		cout << "Walk (b)" << endl;
		cout << "Crawl (c)" << endl;

		print_Hallway();

		getline(cin, Schoice);

		Cchoice = Schoice[0];

		if (Cchoice == 'a' && (race == "Elf")) {
			system("cls");
			cout << "You run all the way to the door without looking back, and you make it." << endl;
			counter++;
		}

		else if (Cchoice == 'a' && (race != "Elf")) {
			system("cls");
			cout << "You begin to run, but a boulder from starts rolling from behind you and you get crushed." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'b' && (race == "Human")) {
			system("cls");
			cout << "You begin walking across when a boulder starts rolling from behind you." << endl;
			cout << "But without panicking, you realize you could just step to the side and let it pass." << endl;
			counter++;
		}
		else if (Cchoice == 'b' && (race != "Human")) {
			system("cls");
			cout << "You begin walking across when a boulder falls from the ceiling and crushes you." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else if (Cchoice == 'c' && (race == "Dwarf")) {
			system("cls");
			cout << "You begin crawling across, when this boulder starts rolling from behind you." << endl;
			cout << "But because of your strong posture and back, the boulder rolls right over you, leaving you unharmed." << endl;
			counter++;
		}
		else if (Cchoice == 'c' && (race != "Dwarf")) {
			system("cls");
			cout << "You begin crawling across, when this boulder starts rolling from behind you." << endl;
			cout << "You get crushed from the rolling boulder." << endl;
			system("Pause");
			lose();
			counter++;
		}
		else {
			cout << "You made a mistake, please try again." << endl;
		}
	}
}

void room19(int age, string race) {
	int counter = 0;
	string Schoice;
	string insult;
	string a = "a";

	if (race == "Dwarf") {
		insult = "dawdling";
	}
	else if (race == "Elf") {
		insult = "envious";
		a = "an";
	}
	else if (race == "Human") {
		insult = "horrible";
	}

	while (counter == 0) {

		system("cls");

		cout << "You make it to the door, and hear the Voice right behind it." << endl;
		cout << "\"You finally made it to my door, but I will only let you in if you prove that you were paying attention!\"" << endl;
		cout << "\"If you recall, when you first entered my castle, I insulted you. If you remember what my insult was, I will let you in.\"" << endl;
		cout << "\"My exact words were...\"" << endl;
		cout << "\"I can't believe " << a << " (blank) " << race << " was able to enter my castle!\"" << endl;
		cout << "\"If you can fill in the blank, I'll unlock my door and let you in.\"" << endl;
		cout << endl;

		print_Question();

		getline(cin, Schoice);

		if (Schoice == insult) {
			system("cls");
			cout << "\"Wow, I'm actually kind've touched that you remembered that. We have grown so much closer because of this experience.\"" << endl;
			cout << "\"I'll unlock my door now.\"" << endl;
			counter++;
		}
		else {
			cout << "Wrong! Now I will never open this door for you!" << endl;
			system("Pause");
			lose();
		}
	}
}

void bossa(int age, string race) {

		system("cls");

		cout << "As you begin to open the door, you hear the Voice speak." << endl;
		cout << "\"I should warn you though, I'm immortal, so you'll never beat me.\"" << endl;
		cout << "\"Well... technically I have three weaknessess that could defeat me.\"" << endl;
		cout << "\"My first weakness is a 100 year old Elf.\"" << endl;
		cout << "\"My second weakness is a 70 year old Dwarf named Bob.\"" << endl;
		cout << "\"My third weakness is any human.\"" << endl;
		cout << "\"So if you aren't any one of my weaknesses, then you will lose.\"" << endl;
		cout << endl;

}

void bossb(int age, string race, string name) {

	system("cls");

	print_Dragon();

	if ((race == "Elf") && (age == 100)) {
		cout << "\"Wow, what are the odds of you being a 100 year old Elf? Ok then, I guess I admit defeat.\"" << endl;
		system("Pause");
	}
	else if((race == "Dwarf") && (age == 70) && (name == "Bob")){
		cout << "\"Oh my gosh Bob is that you?!? Holy crap dude I haven't seen you in forever! Congrats on getting to me!\"" << endl;
		cout << "\"We've got so much to catch up on.\"" << endl;
	}
	else if (race == "Human") {
		cout << "\"Wow, I can't believe a human was actually able to make it to me. Ok then, I guess I admit defeat.\"" << endl;
	}
	else {
		cout << "You fight your heart out, but the Voice was true to his word. His imortality made him undefeatable. You end up being slain." << endl;
		system("Pause");
		lose();
	}
}

void begin_Game(){
	system("cls");
	print_Mountains();
	cout << "Welcome to choose your own adventure! To begin, let's start with some of the basic information." << endl;
	cout << "Don't worry, I'm sure none of this will be important in the future." << endl;
	string name = input_Name();
	int age = input_Age();
	string race = input_Race();

	Player Protagonist(name, age, race);
	cout << endl;
	Protagonist.introduce();

	system("Pause");

	room1(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room2(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room3(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room4(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room5(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room6(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room7(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room8(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room9(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	int window = (room10(Protagonist.get_Age(), Protagonist.get_Race()));

	if (window == 2) {
		room10h(Protagonist.get_Age(), Protagonist.get_Race());
	}
	else if (window == 3) {
		room10d(Protagonist.get_Age(), Protagonist.get_Race());
	}
	system("Pause");

	room11(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	if (room12(Protagonist.get_Age(), Protagonist.get_Race()) == false) {
		system("Pause");
		room12a(Protagonist.get_Age(), Protagonist.get_Race());
	}
	system("Pause");

	room13(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room14(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room15(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room16(Protagonist.get_Age(), Protagonist.get_Race(), Protagonist.get_Name());
	system("Pause");

	room17(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room18(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	room19(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	bossa(Protagonist.get_Age(), Protagonist.get_Race());
	system("Pause");

	Protagonist.introduce();
	system("Pause");

	bossb(Protagonist.get_Age(), Protagonist.get_Race(), Protagonist.get_Name());
	system("Pause");

	if (win(Protagonist.get_Name()) == true) {
		begin_Game();
	}
}
