#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

using namespace std;

char operators[4] = {'+', '-', '*', '/'};
//Counts How many answers were either correct/wrong in the for loop in main function
int wrong_answer_count = 0;
int right_answer_count = 0;


struct variables {
	//asks the for loop of main function to print out number of questions to be attempted
	int number_Of_Questions;
	//these two data types were changed in order to be able
	float correct_answer;
	float your_attempt;

	//these two stores the random numbers generated and perform the operations in different functions
	float random_number1;
	float random_number2;
	int option[1]; //it can only choose between two
	/*If the option variable matches the correct answer, it will generate a new variable.
	  The chances of this occurring is pretty low, but still it should do the trick. */
	int new_random_number;
	int option_order;
} var ;

class option {
private:
	void choose_new_option() {
		if (var.option_order == 1)
			cout << "Options: " << var.new_random_number << " or " << var.correct_answer << "\nYour Answer: ";
		else
			cout << "Options: " << var.correct_answer << " or " << var.new_random_number << "\nYour Answer: ";
	}

    void choose_option() {
		if (var.option_order == 1)
			cout << "Options: " << var.option[0] << " or " << var.correct_answer << "\nYour Answer: ";
		else
			cout << "Options: " << var.correct_answer << " or " << var.option[1] << "\nYour Answer: ";
	}

public:
	void show_options() {
		if (var.option[0] == var.option[1]){
			choose_new_option();
		} else if (var.option[0] == var.correct_answer && var.option[1] == var.correct_answer){
			choose_new_option();
        } else {
            choose_option();
		}
	}

};


class Solve {
public:
	void check_answer() {
		if (var.your_attempt == var.correct_answer) {
			cout << "Congradulations, that is correct" << endl;
			right_answer_count++;
		} else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You are wrong, the answer was " << var.correct_answer << endl;
			wrong_answer_count++;
		}
	}
};


class Generate {

private:

	void question_format(string op) { //op means operator
		option o;
		Solve s;
		cout << var.random_number1 << op << var.random_number2 << " = " << " ?\n";
		o.show_options();
		cin >> var.your_attempt;
		s.check_answer();
	}

public:

	float generate_addition_question(int random_number1, int random_number2) {
		var.correct_answer = random_number1 + random_number2;
		question_format(" + ");
		return var.correct_answer;
	}

	float generate_subtract_question(int random_number1, int random_number2) {
		var.correct_answer = random_number1 - random_number2;
		question_format(" - ");
		return var.correct_answer;
	}

	float generate_multiply_question(int random_number1, int random_number2) {
		var.correct_answer = random_number1 * random_number2;
		question_format(" * ");
		return var.correct_answer;
	}

	float generate_division_question(int random_number1, int random_number2) {
		var.correct_answer = random_number1 / random_number2;
		question_format(" / ");
        return var.correct_answer;
	}

};

class Display {

public:
	void numberOfTimes(int number_Of_Questions) {
		Generate gen;

		for (int a = 1; a <= number_Of_Questions; a++) {
			var.random_number1 = 2.0 + fmod(rand(), 10.0);
			var.random_number2 = 2.0 + fmod(rand(), 10.0);
			var.new_random_number = -69.0 + fmod(rand(), 1.0);
			var.option[0] = 2 + fmod(rand(), 10.0);
			var.option[1] = 2 + fmod(rand(), 10.0);
			var.option_order = rand() % 2;

			cout << "Question: " << a << endl;
			if (operators[rand() % 4] == operators[0])
				gen.generate_addition_question(var.random_number1, var.random_number2);
			else if (operators[rand() % 4] == operators[1])
				gen.generate_subtract_question(var.random_number1, var.random_number2);
			else if (operators[rand() % 4] == operators[2])
				gen.generate_multiply_question(var.random_number1, var.random_number2);
			else
				gen.generate_division_question(var.random_number1, var.random_number2);
			cout << endl;
		}
	}

	//display random question
	//show option
};

/*
    Class Generate{
        question format
        generate questions
    }

    Class Solve {
        check answer
    }

    Class Options {
        choose option
    }
    Class Display{
        show number of times
        display random question
    }
*/
int main() {
	srand(time(0));
	cout << "How many questions?" << "\nAnswer: ";
	cin >> var.number_Of_Questions;
	Display show;
	show.numberOfTimes(var.number_Of_Questions);

	cout << "\n\nNumber of Correct answers: " << right_answer_count << endl;
	cout << "Number of InCorrect answers: " << wrong_answer_count << endl;
	system("pause");
	return 0;
}

/*
#include <iostream>
#include<cstdlib>
using namespace std;

class Question {
    public:
        int correctAnswerCount = 0;
        int wrongAnswerCount = 0;
        Question(){
            srand(time(0));
        }

        string signCalc[4] = {"-" , "+" , "/", "*"};
        int generateRandNumber () {
            return (rand() % 50) +10;
        }

        int generateQuestions () {

            string sign = signCalc[rand() % 4];

            int secondNumber = generateRandNumber();
            int firstNumber = generateRandNumber();

            cout << to_string(firstNumber) + " " + sign + " " + to_string(secondNumber) + " ?"<< endl;

            int correctAnswer = (sign == "+") ? firstNumber + secondNumber:
                                (sign == "/") ? firstNumber / secondNumber:
                                (sign == "-") ? firstNumber - secondNumber:
                                firstNumber * secondNumber;

            return correctAnswer;
        }

        int noOfTimes(int y){
            for(int i = 0; i < y; i++){
                cout << "question" + to_string(i) << endl;
                int corretAnswer = generateQuestions();
                cout << "ans ? " << endl;
                int userChoice;
                cin >> userChoice;

                if(userChoice == corretAnswer){
                    correctAnswerCount++;
                }else{
                    wrongAnswerCount++;
                }
            }
            cout << "Ans correct " << correctAnswerCount << endl;
            cout << "Ans wrong " << wrongAnswerCount << endl;
            return 0;
        }

};

int main(){
    Question firstq;
    //take user input and pass it to noOfTimes
    firstq.noOfTimes(2);
}
*/
