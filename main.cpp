#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

//asks the for loop of main function to print out number of questions to be attempted
int number_Of_Questions;
float correct_answer;
float your_attempt;

//Counts How many answers were either correct/wrong in the for loop in main function
int wrong_answer_count = 0;
int right_answer_count = 0;
/*
The array numbers mean
   * 1 = Addition
   * 2 = Subtraction
   * 3 = Multiplication
   * 4 = Division
*/
char operators[4] = {'+', '-', '*', '/'};
//these two stores the random numbers generated and perform the operations in different functions
float random_number1;
float random_number2;
int option[1]; //it can only choose between two
/*If the option variable matches the correct answer, it will generate a new variable.
  The chances of this occuring is pretty low, but still it should do the trick. */
int new_random_number;
int option_order;



void generate_addtion_question();
void generate_subtract_question();
void generate_multiply_question();
void generate_division_question();

int main(){
	srand(time(0));

	cout << "How many questions?" << "\nAnswer: ";
	cin >> number_Of_Questions;
	cout << endl;

	/* edit: I rather scrap that last idea and call it done. I would focus more on
        refactoring, cleaning and tiding code and probably fix some bugs
	*/
	for(int a = 1; a <= number_Of_Questions; a++){

    random_number1 = 2 + (rand() % 10);
    random_number2 = 2 + (rand() % 10);
    new_random_number = -69.0 + (rand() % 2);
    option[0] = 2 + (rand() % 20);
    option[1] = 2 + (rand() % 20);
    option_order = rand() % 2;


    cout << "Question: " << a << endl;
    if(operators[rand() % 4] == operators[0])
       generate_division_question();
    else if(operators[rand() % 4] == operators[1])
       generate_division_question();
    else if(operators[rand() % 4] == operators[2])
       generate_division_question();
    else
       generate_division_question();

        cout << endl;
    }

	cout << "\n\nNumber of Correct answers: " << right_answer_count << endl;
	cout << "Number of Wrong answers: " << wrong_answer_count << endl;

	system("pause");
    return 0;
}

void choose_option(){
    if(option_order == 1)
    cout << "Options: " << new_random_number << " or " << correct_answer << "\nYour Answer: ";
    else
    cout << "Options: " << correct_answer << " or " << new_random_number << "\nYour Answer: ";

}

void show_options(){
	if(option[0] == option[1])
        choose_option();
	else if(option[0] == correct_answer && option[1] == correct_answer)
        choose_option();
    else
        choose_option();
}

void check_answer(){

	if(your_attempt == correct_answer){
		cout << "Congradulations, that is correct" << endl;
		right_answer_count += 1;
	} else if(your_attempt == new_random_number || your_attempt != your_attempt){
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	} else {
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	}

}
//these functions generate random question and handle the answers
//I had to create four fricking functions for the program to ask four different questions!

void generate_addtion_question(){
    correct_answer = random_number1 + random_number2;
	cout << random_number1 << " + " << random_number2 << " = " << " ?\n";
    show_options();
	cin >> your_attempt;
    check_answer();
}

void generate_subtract_question(){
    correct_answer = random_number1 - random_number2;
	cout << random_number1 << " - " << random_number2 << " = " << " ?\n";
    show_options();
	cin >> your_attempt;
    check_answer();
}

void generate_multiply_question(){
    correct_answer = random_number1 * random_number2;
	cout << random_number1 << " X " << random_number2 << " = " << " ?\n";
    show_options();
	cin >> your_attempt;
    check_answer();
}

void generate_division_question(){
    correct_answer = random_number1 / random_number2;
	cout << random_number1 << " / " << random_number2 << " = " << " ?\n";
    show_options();
	cin >> your_attempt;
    check_answer();
}
