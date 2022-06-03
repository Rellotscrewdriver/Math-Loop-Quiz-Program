#include "include.h"

void Option::show_options(double right_answer) {
	option_choose[0] = 2.0 + fmod(rand(), 10.0);
	option_choose[1] = 2.0 + fmod(rand(), 10.0);
	option_order = rand() % 2;

	if (option_choose[0] == option_choose[1]) {
		//cout << "first condition at show_options() is executed" << endl;
		generate_unique_number(option_choose[0], option_choose[1], right_answer);
		//cout << "final random number: " << new_random_number << "\n";
		//cout << "comparing numbers to: Option1: " << option_choose[0] << " : Option2: " << option_choose[1] << "\n Answer: " << right_answer << endl;
		choose_new_option(right_answer);
	} else if (option_choose[0] == right_answer || option_choose[1] == right_answer) {
		//cout << "second condition at show_options() is executed" << endl;
		generate_unique_number(option_choose[0], option_choose[1], right_answer);
		//cout << "final random number: " << new_random_number << "\n";
		//cout << "comparing numbers to: Option1: " << option_choose[0] << " : Option2: " << option_choose[1] << "\n Answer: " << right_answer << endl;
		choose_new_option(right_answer);
	} else {
		//cout << "third condition at show_options() is executed" << endl;
		choose_option(right_answer);
	}
}

void Option::generate_unique_number(double option1, double option2, double answer) {
	while(true) {
		new_random_number = 2.0 + fmod(rand(), 10.0);
		/*cout << "intial random number: " << new_random_number << "\n";
		  cout << "comparing inital numbers to: Option1: " << option1
		  << " : Option2: " << option2
		  << "\n Answer: " << answer << endl;*/

		if(option1 == new_random_number || option2 == new_random_number) {
			new_random_number = 2.0 + fmod(rand(), 10.0);
		} else if(answer == new_random_number) {
			new_random_number = 2.0 + fmod(rand(), 10.0);
		} else {
			break;
		}
	}
}

void Option::choose_option(double answer) {
	//here true = 1, false = 0
	if (option_order == true) {
		//cout << "first condition located at choose_option() is executed" << endl;
		cout << "Options: " << option_choose[0] << " or " << answer << "\nYour Answer: ";
	} else {
		//cout << "second conditon located at choose_option() is executed" << endl;
		cout << "Options: " << answer << " or " << option_choose[1] << "\nYour Answer: ";
	}
}

//it chooses the new option if the show_options are uhh
void Option::choose_new_option(double answer) {
	//here same case
	if (option_order == true) {
		//cout << "first condition located at choose_new_option() is executed" << endl;
		cout << "Options: " << new_random_number << " or " << answer << "\nYour Answer: ";
	} else {
		//cout << "second conditon located at choose_new_option() is executed" << endl;
		cout << "Options: " << answer << " or " << new_random_number << "\nYour Answer: ";
	}
}
