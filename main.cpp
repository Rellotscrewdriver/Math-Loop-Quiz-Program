#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//asks the for loop of main function to print out number of questions to be attempted
int number_Of_Questions;
float correct_answer;
int your_attempt;
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
int operators[] = {1, 2, 3, 4};
//these two stores the random numbers generated and perform the operations in different functions
int random_number1;
int random_number2;
int option[1]; //it can only choose between two, but in the future, I will add it upto 4
/*If the option variable matches the correct answer, it will generate a new variable.
  The chances of this occuring is pretty low, but still it should do the trick. */
int new_random;
//this
int place_option;


/*
    Generate Random Questions And Handle Their Answers For Addition, Subtraction, Multiplication
    and Division
*/
void GRQATAFA();
void GRQATAFS();
void GRQATAFM();
void GRQATAFD();

int main(){

	srand(time(0));

	cout << "How many questions?" << "\nAnswer: ";
	cin >> number_Of_Questions;
	cout << endl;

	/* the correct answers are now dynamic. but the options are only 2.
       In the future, I will add upto 4 and probably work on input function
       not to excute when a string is entered
	*/
	for(int a = 1; a <= number_Of_Questions; a++){

    random_number1 = rand() % 10;
    random_number2 = rand() % 10;
    new_random = rand() % 20;
    option[0] = rand() % 20;
    option[1] = rand() % 20;
    place_option = rand() % 2;

    cout << "Question: " << a << endl;
    if(operators[rand() % 4] == operators[0])
       GRQATAFA();
    else if(operators[rand() % 4] == operators[1])
       GRQATAFS();
    else if(operators[rand() % 4] == operators[2])
       GRQATAFM();
    else
       GRQATAFD();

        cout << endl;
    }

	cout << "\n\nNumber of Correct answers: " << right_answer_count << endl;
	cout << "Number of Wrong answers: " << wrong_answer_count << endl;

    return 0;
}


void option_choose(){
    if(place_option == 1)
    cout << "Options: " << new_random << " or " << correct_answer << "\nYour Answer: ";
    else
    cout << "Options: " << correct_answer << " or " << new_random << "\nYour Answer: ";

}

void options(){
	if(option[0] == option[1])
        option_choose();
	else if(option[0] == correct_answer || option[1] == correct_answer)
        option_choose();
    else
        option_choose();
}

//these functions generate random question and handle the answers
//I had to create four fricking functions for the program to ask four different questions!

void GRQATAFA(){
    correct_answer = random_number1 + random_number2;
	cout << random_number1 << " + " << random_number2 << " = " << " ?\n";
    options();
	cin >> your_attempt;

	if(your_attempt == (correct_answer)){
		cout << "Congradulations, that is correct" << endl;
		right_answer_count += 1;
	} else {
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	}
}

void GRQATAFS(){
    correct_answer = random_number1 - random_number2;
	cout << random_number1 << " - " << random_number2 << " = " << " ?\n";
    options();
	cin >> your_attempt;

	if(your_attempt == (correct_answer)){
		cout << "Congratulations, that is correct" << endl;
		right_answer_count += 1;
	} else {
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	}
}

void GRQATAFM(){
    correct_answer = random_number1 * random_number2;
	cout << random_number1 << " X " << random_number2 << " = " << " ?\n";
    options();
	cin >> your_attempt;

	if(your_attempt == (correct_answer)){
		cout << "Congratulations, that is correct" << endl;
		right_answer_count += 1;
	} else {
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	}
}

void GRQATAFD(){
    correct_answer = random_number1 / random_number2;
	cout << random_number1 << " / " << random_number2 << " = " << " ?\n";
    options();
	cin >> your_attempt;

	if(your_attempt == (correct_answer)){
		cout << "Congratulations, that is correct" << endl;
		right_answer_count += 1;
	} else {
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
    }
}
