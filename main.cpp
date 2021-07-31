#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

using namespace std;

//string signs are used to identify which which
string operators[4] = {" + ", " - ", " * ", " / "};
//Counts How many answers were either correct/wrong in the for loop in main function
int wrong_answer_count = 0;
int right_answer_count = 0;


struct variables {
	//it asks the for loop of main function to print out number of iterations to be executed
	int number_Of_Questions;

	//these two data types were changed in order to be able
	double correct_answer;
	double your_attempt;

	//these two stores the random numbers generated and perform the operations in different functions
	double random_number1;
	double random_number2;

	//this is an initial operator
	int choose_option[1];

	/*If a different option matches the correct answer or two options are equal,
	  it will generate a new number which is unique and
	  impossible for random generator to generate the same previous number.
	  let's be real, The chances of this occurring is pretty low, but it should do the trick :) */
	int new_random_number;
	bool option_order;

} var ;

class option {
	/*
	the print operation commented in // are debug texts to check
	whether the conditions are working.
	you can uncomment them to see which option gets executed
	*/
private:

	/*
	  just a regular format, it is like this, since I wanted to randomize the options
	  so the options wouldn't be in one format, correct answers in one position
	  to give you a feeling that you're really taking an MCQ test
	*/
	void choose_option() {
		//here true = 1, false = 0
		if (var.option_order == true) {
			//cout << "if conditon located at choose_option() is executed" << endl;
			cout << "Options: " << var.choose_option[0] << " or " << var.correct_answer << "\nYour Answer: ";
		} else {
			//cout << "else conditon located at choose_option() is executed" << endl;
			cout << "Options: " << var.correct_answer << " or " << var.choose_option[1] << "\nYour Answer: ";
		}
	}

	//it chooses the new option if the show_options are uhh
	void choose_new_option() {
		//here same case
		if (var.option_order == true) {
			//cout << "if conditon located at choose_new_option() is executed" << endl;
			cout << "Options: " << var.new_random_number << " or " << var.correct_answer << "\nYour Answer: ";
		} else {
			//cout << "else conditon located at choose_new_option() is executed" << endl;
			cout << "Options: " << var.correct_answer << " or " << var.new_random_number << "\nYour Answer: ";
		}
	}

public:
	/*
	  shows the options on screen,
	  but before showing it checks whether these the other option matches the correct answer
	*/
	void show_options() {
		if (var.choose_option[0] == var.choose_option[1]) {
			//cout << "if conditon located at show_options() is executed" << endl;
			choose_new_option();
		} else if (var.choose_option[0] == var.correct_answer && var.choose_option[1] == var.correct_answer) {
			//cout << "else if or second conditon located at show_options() is executed" << endl;
			choose_new_option();
		} else {
			//cout << "else conditon located at show_options() is executed" << endl;
			choose_option();
		}
	}

};


class Solve {

private:
	//this is the function to stop the overflow and go on, uses <limits> here
	void stop_buffer_overflow() {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

public:
	//to solve the given question
	void check_answer() {
		if (var.your_attempt == var.correct_answer) {
			right_answer_count++; //counts the right answer to 1
			cout << "Congratulations, that is correct";
		} else {
			//when the user types a string instead of expected float or integer, it overflows
			//thus, why it exists
			stop_buffer_overflow();
			wrong_answer_count++; //counts the wrong answer as 1
			cout << "Wrong, The answer was " << var.correct_answer;
		}
	}
};

//this class is meant to display the question
class Generate_Question {

private:

	option option;
	Solve solve;

	/*
	common format for four different types of questions
	op means operator but I can't fully write 'operator' since it is a C++ keyword
	*/

	void question_format(string op) {
		cout << var.random_number1 << op << var.random_number2 << " = " << " ?\n";
		option.show_options(); //display the options for user to choose
		cin >> var.your_attempt;
		solve.check_answer(); //shows the answer
	}

public:

	//types of questions which utilizeS the format_question()
	int Addition(int random_number1, int random_number2) {
		var.correct_answer = random_number1 + random_number2;
		question_format(" + ");
		return var.correct_answer;
	}

	int Subtraction(int random_number1, int random_number2) {
		var.correct_answer = random_number1 - random_number2;
		question_format(" - ");
		return var.correct_answer;
	}

	int Multiplication(int random_number1, int random_number2) {
		var.correct_answer = random_number1 * random_number2;
		question_format(" X ");
		return var.correct_answer;
	}

	void Division(int random_number1, int random_number2) {
		var.correct_answer = random_number1 / random_number2;
		question_format(" / ");
	}

	//chooses the question randomly with random_numbers parameters
	void choose_question() {
		if (operators[rand() % 4] == operators[0]) {
			Addition(var.random_number1, var.random_number2);
        } else if (operators[rand() % 4] == operators[1]) {
			Subtraction(var.random_number1, var.random_number2);
		} else if (operators[rand() % 4] == operators[2]) {
			Multiplication(var.random_number1, var.random_number2);
		} else {
			Division(var.random_number1, var.random_number2);
		}
	}
};

class Display {
private:

	//these all are used inside the function in obtain new numbers everytime this loop iterates
	void random_numbers() {
		var.random_number1 = 2 + rand() % 10;
		var.random_number2 = 2 + rand() % 10;
		var.new_random_number = -69 + rand() % 1; //noice
		var.choose_option[0] = 2.0 + fmod(rand(), 10.0);
		var.choose_option[1] = 2.0 + fmod(rand(), 10.0);
		var.option_order = rand() % 2;
	}

public:

	Display(int number_Of_Questions) {
		//this is outside the loop to avoid creating objects continously
		Generate_Question generat;
		for (int a = 1; a <= number_Of_Questions; a++) {

			random_numbers();

			//here's the question displayed
			cout << "Question: " << a << endl;
			generat.choose_question();
			cout << endl << endl;
		}
	}

};

int main() {
	srand(time(0)); //increments the seed with time after 31 Dec/1 Jan, 1969/1970

	//asks the user to input how many times question needs to be displayed
	cout << "How many questions? ";
	cin >> var.number_Of_Questions;
	cout << endl;

	Display(var.number_Of_Questions);

	//after the main loop is executed these results are shown here
	cout << "\nNumber of Correct answers: " << right_answer_count << endl;
	cout << "Number of InCorrect answers: " << wrong_answer_count << endl;

	getchar(); //exits the program
	return 0;
}
