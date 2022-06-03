#include "include.h"

//chooses the question randomly with random_numbers parameters
void Generate_Question::choose_question() {
	random_number = 2 + rand() % 10;
	random_number2 = 2 + rand() % 10;

	//cout << "at choose_question(): " << random_number << " : " << random_number2 << endl;

	if (operators[rand() % 4] == operators[0]) {
		Addition(random_number, random_number2);
	} else if (operators[rand() % 4] == operators[1]) {
		Subtraction(random_number, random_number2);
	} else if (operators[rand() % 4] == operators[2]) {
		Multiplication(random_number, random_number2);
	} else {
		Division(random_number, random_number2);
	}
}

void Generate_Question::question_format(string op) {
	cout << random_number << op << random_number2 << " = ?\n";
	choice.show_options(correct_answer); //display the options for user to choose
	cin >> your_attempt;
	solve.check_answer(your_attempt, correct_answer); //checks and shows the answer
}

float Generate_Question::Addition(float random_number1, float random_number2) {
	correct_answer = random_number1 + random_number2;
	question_format(" + ");
	return correct_answer;
}

float Generate_Question::Subtraction(float random_number1, float random_number2) {
	correct_answer = random_number1 - random_number2;
	question_format(" - ");
	return correct_answer;
}

float Generate_Question::Multiplication(float random_number1, float random_number2) {
	correct_answer = random_number1 * random_number2;
	question_format(" x ");
	return correct_answer;
}

float Generate_Question::Division(float random_number1, float random_number2) {
	correct_answer = random_number1 / random_number2;
	question_format(" / ");
	return correct_answer;
}
