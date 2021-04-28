#include <iostream>
//include <cstdlib>
using namespace std;

int main(){
	//srand(time_t(3));
	int number_Of_Questions = 3;
	int your_attempt;
	int correct_answer;
	int wrong_answer_count = NULL;
	int right_answer_count = NULL;

	cout << "How many questions?" << "\nAnswer: ";
	//this input is useless for now
	cin >> number_Of_Questions;
	cout << endl;


 /* even though this project is supposed to be done in loop
	but for now I just copycat it for now. later it will be
	dynamic, you can call it some sort of a prototype */

	//case 1
	cout << 2 << " X " << 1 << " = ";
	cin >> your_attempt;
	cout << "Options 2 or 1" << endl;
	if(your_attempt == (correct_answer = 2*1)){
		cout << "Congradulations, that is correct" << endl;
		right_answer_count += 1;
	} else {
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	}

	//for some reason the if and else statement aren't returning the newline
	cout << endl;

	//case 2
	cout << 5 << " X " << 2 << " = ";
	cin >> your_attempt;
	cout << "Options 10 or 7" << endl;
	if(your_attempt == (correct_answer = 5*2)){
		cout << "Congradulations, that is correct" << endl;
		right_answer_count += 1;
	} else {
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	}

	//for some reason the if and else statement aren't returning the newline
	cout << endl;

	//case 3
	cout << 5 << " + " << 2 << " = ";
	cin >> your_attempt;
	cout << "Options 3 or 7" << endl;
	if(your_attempt == (correct_answer = 5+2)){
		cout << "Congradulations, that is correct" << endl;
		right_answer_count += 1;
	} else {
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	}

	cout << "\n\nNumber of Correct answers: " << right_answer_count << endl;
	cout << "Number of Wrong answers: " << wrong_answer_count << endl;

	system("pause");
}
