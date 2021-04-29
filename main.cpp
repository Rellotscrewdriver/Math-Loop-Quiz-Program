#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	srand(time(0));
	int number_Of_Questions;
	int your_attempt;
	int wrong_answer_count = 0;
	int right_answer_count = 0;

	cout << "How many questions?" << "\nAnswer: ";
	cin >> number_Of_Questions;
	cout << endl;

	/* You can probably see where I'm going, currently it can only do addition.*/
	for(int a = 1; a <= number_Of_Questions; a++){

    int random_number1 = rand() % 10;
    int random_number2 = rand() % 10;
    int correct_answer = random_number1 + random_number2;
    //char rand_operators[] = {'-', '/', '*', '+'};

	cout << "Question: " << a << endl;
	cout << random_number1 << " + " << random_number2 << " = " << " ?\n";
	cout << "Options: " << rand() % 10 << " or " << correct_answer << "\nYour Answer: " << endl;
	cin >> your_attempt;

	if(your_attempt == (correct_answer)){
		cout << "Congradulations, that is correct" << endl;
		right_answer_count += 1;
	} else {
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	}
        cout << endl;
	}

	cout << "\n\nNumber of Correct answers: " << right_answer_count << endl;
	cout << "Number of Wrong answers: " << wrong_answer_count << endl;

    return 0;
}
