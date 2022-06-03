#include "include.h"

extern int right_answer_count = 0;
extern int wrong_answer_count = 0;

//this is the function to stop the overflow and go on, uses <limits> here
void Solve::stop_buffer_overflow() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Solve::check_answer(float your_attempt, float correct_answer) {
	if (round(your_attempt) == round(correct_answer)) {
		cout << "Congratulations, that is correct";
		right_answer_count++; //counts the right answer to 1
	} else {
		//when the user types a string instead of expected float or integer, it overflows
		//thus, why it exists
		stop_buffer_overflow();
		wrong_answer_count++;
		cout << "Wrong, The answer was " << correct_answer;
	}

	cout << "\nyour score now: " << right_answer_count << " Right, " << wrong_answer_count << " Wrong\n";
}

void Solve::final_score() {
	//after the main loop is executed these results are shown here
	cout << "Number of Correct Answers: " << right_answer_count << endl;
	cout << "Number of InCorrect Answers: " << wrong_answer_count << endl;
}
