//compguess.cc
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <ctime>

using namespace std;

int main () {

	//////////// Declare some variables //////////////

	char a;
	char b;
	int guess;
	int count = 0;
	int max = 100;
	int min = 1;
	int loop = 1;
	bool playagain = true;

	//////////// Intro to the game ///////////////////

	cout<<"Welcome to the guessing game!"<<endl;
	while(playagain == true) {
		cout<<"\nThink of a positive integer between 1 and 100."<<endl;
		sleep(1);
		cout<<".";
		sleep(1);      //// Give the player some time to think
		cout<<".";
		sleep(1);
		cout<<"."<<endl;
		cout<<"Got it? Let's begin!"<<endl;
	

	///////////// Begin the game loop /////////////////

		srand((unsigned)time(NULL));
		guess = (rand()%100+1);
		while (loop==1) {
			cout<<"Is it: "<<guess<<"?\n"<<"Enter 'h' if the guess is too high, 'l' if the guess is too low, or 'y' if the guess is correct: ";
			cin >> a;
			switch (a) {
				case 'h':
					++count;
					if (max>guess) {
						max=guess;
					}
					guess = ((max+min)/2);
					break;
				case 'l':
					++count;
					if (min<guess) {
						min=guess;
					}
					guess = ((max+min)/2);
					break;
				case 'y':
					loop = 0;
					break;
				default:
					cout<<"I'm sorry, I didn't understand you, try again.\n";
			}
		}
		cout<<"Yay, I got it!"<<endl;
		cout<<"It only took me "<<count<<" tries!"<<endl;
		sleep(1);
		cout<<"\nPlay again? (y/n): ";
		cin >> b;
		switch (b) {
			case 'y':
				loop = 1;
				count = 0;
				max = 100;
	       			min = 1;
				continue;
			case 'n':
				cout<<"Goodbye!"<<endl;
				playagain = false;
			default:
				playagain = false;
		}
	}

	return 0;
}
