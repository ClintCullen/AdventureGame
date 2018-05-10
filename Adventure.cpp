#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<windows.h>

using namespace std;

enum class MenuOption {
	Play = 1,
	Instructions,
	EndGameResult,
	Quit
};

enum FirstChoice {
	MakeCamp = 1,
	Explore
};

enum class SecondChoice {
	FindFood = 1,
	StartFire,
	CollectFuel
};

int Firewood = 0;
std::string YourFate;

int main()
{
	int live = 1;
	//int firewood = 0
	const int LEAVE = 5;
	int stranger = 1;
	std::string ridOne;
	std::string ridTwo;
	std::string ridThree;
	int startup;
	int decOne;
	int decTwo;

	MenuOption menuOption;
	FirstChoice firstChoice;
	SecondChoice secondChoice;

	int num;
	int rid;

	void lightFire(int fuel);
	void StartGame();
	int ReturnToCamp();


begin:
	StartGame();

	std::cin >> startup;
	std::cout << "you chose " << startup << std::endl;

	menuOption = static_cast<MenuOption>(startup);

	switch (menuOption) {

	case MenuOption::Play:
		system("cls");
		std::cout << "You...are...alone..." << std::endl;
		std::cout << "Fatigued and weak, you wake up in the middle of a forest." << std::endl;
		std::cout << "You must make a choice: 1 - [Make a camp]  2 - [Explore the area]	";
		std::cin >> decOne;

		firstChoice = static_cast<FirstChoice>(decOne);

		switch (firstChoice) {
		case MakeCamp:
		Fireline:
			system("cls");

			ridOne = "";
			ridTwo = "";
			ridThree = "";

			std::cout << "You make a small camp, with a one-person shelter, and a crude firepit." << std::endl;
			std::cout << std::endl;
			std::cout << "You have " << Firewood << " firewood" << std::endl;
			std::cout << std::endl;
			std::cout << "Now what? 1 - [Look for Food] 2 - [Light a Fire] 3 - [Collect Firewood] ";
			std::cin >> decTwo;

			secondChoice = static_cast<SecondChoice>(decTwo);

			switch (secondChoice) {
			case SecondChoice::FindFood:
				std::cout << "You look for food...after a few hours, your efforts prove fruitless." << std::endl;
				std::cout << "You look around, suddenly with no sense of direction. You. Are. Lost." << std::endl;
				std::cout << "You havent eaten in days, your body gives out on you, it's the end for you this time..." << std::endl;
				break;

			case SecondChoice::StartFire:
				lightFire(Firewood);
				Sleep(5000);
				decTwo = ReturnToCamp();
				goto Fireline;
				break;

			case SecondChoice::CollectFuel:

				time_t t = time(0);

				//srand(t);

				num = rand() % 8;

				if (num >= 2) {
					std::cout << "You found some firewood!" << std::endl;
					Firewood++;
					std::cout << "You head back to camp..." << std::endl;
					Sleep(2000);
					//int choice = ReturnToCamp();
					goto Fireline;

				}
				else {
					std::cout << "You come across a strange woman... she will let you pass if you answer a riddle correctly" << std::endl;
					srand(time(0));
					rid = rand() % 2;
					switch (rid) {
					case 1:
						std::cout << "What gets sharper the more you use it?" << std::endl;
						std::cin >> ridOne;
						if (ridOne == "brain" || ridOne == "Brain") {
							std::cout << "You answered correctly. You may leave, and you get some firewood." << std::endl;
							Firewood++;
						}
						else {
							system("CLS");
							std::cout << "That answer wasn't right... The strange woman casts a spell, and suddenly you cease to exist" << std::endl;
							std::cout << "Better luck next time!" << std::endl;
							exit(0);
						}
						break;
					case 2:
						std::cout << "What gets wetter the more it dries?" << std::endl;
						std::cin >> ridTwo;
						if (ridTwo == "towel" || ridTwo == "Towel") {
							std::cout << "You answered correctly. You may leave, and you get some firewood." << std::endl;
							Firewood++;
						}
						else {
							system("CLS");
							std::cout << "That answer wasn't right... The strange woman casts a spell, and suddenly you cease to exist" << std::endl;
							std::cout << "Better luck next time!" << std::endl;
							exit(0);
						}
						break;
					default:
						std::cout << "What gets bigger the more you take away?" << std::endl;
						std::cin >> ridThree;
						if (ridThree == "hole" || ridThree == "Hole") {
							std::cout << "You answered correctly. You may leave, and you get some firewood." << std::endl;
							Firewood++;
						}
						else {
							system("CLS");
							std::cout << "That answer wasn't right... The strange woman casts a spell, and suddenly you cease to exist" << std::endl;
							std::cout << "Better luck next time!" << std::endl;
							exit(0);
						}
						break;
					}
					Sleep(2000);
					goto Fireline;
				}
				break;
			}
			break;
		case Explore:
			std::cout << "Explore" << std::endl;
			break;
		}
		break;
	case MenuOption::Instructions:
		std::cout << "Instructions" << std::endl;
		Sleep(3000);
		goto begin;
	case MenuOption::EndGameResult:
		std::cout << "Outcome" << std::endl;
		std::cout << decOne << std::endl;
		break;
	case MenuOption::Quit:
		std::cout << "Good-bye!" << std::endl;
		Sleep(3000);
		break;
	default:
		system("cls");
		std::cout << "You seem to have chosen poorly. Please try again..." << std::endl;
		goto begin;
	}
	std::cout << "Thanks for playing!!" << std::endl;

	return 0;
}

void StartGame() {
	std::cout << "                 SURVIVE                 " << std::endl;
	std::cout << "_________________________________________" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "         1       [PLAY]                  " << std::endl;
	std::cout << "         2   [INSTRUCTIONS]              " << std::endl;
	std::cout << "         3 [SEE YOUR OUTCOME]	          " << std::endl;
	std::cout << "         4       [QUIT]                  " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Enter an Option Number: ";
}

int ReturnToCamp() {
	int choice;
	system("cls");
	std::cout << "You return to your one person shelter at camp. You have " << Firewood << " pieces of firewood." << std::endl;
	std::cout << "What next? 1 - [Look for Food] 2 - [Light a Fire] 3 - [Collect Firewood] ";
	std::cin >> choice;
	return choice;
}

void lightFire(int fuel) {
	if (fuel >= 5) {
		// decrement amount of firewood remaining by cost of fire (5)
		Firewood -= 5;
		std::cout << "You have started a nice, warm fire." << std::endl;
		std::cout << "You bask in the warm glow..." << std::endl;
	}
	else {
		if (fuel > 0) {
			Firewood--;
			std::cout << "you tried to start a fire, but not enough wood. " << std::endl;
			std::cout << "you lost one piece of firewood!";
		}
		else {
			std::cout << "you don't have any firewood to burn!";
		}
	}
}



