#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//asks the for loop of main function to print out number of questions to be attempted
int number_Of_Questions;
int correct_answer;
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

	/* edit: I rather scrap that last idea and call it done. I would focus more on
        refactoring, cleaning and tiding code and probably fix some bugs
	*/
	for(int a = 1; a <= number_Of_Questions; a++){

    random_number1 = 2 + (rand() % 10);
    random_number2 = 2 + (rand() % 10);
    new_random = 2.0 + (rand() % 20);
    option[0] = 2 + (rand() % 20);
    option[1] = 2 + (rand() % 20);
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

	system("pause");
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
	else if(option[0] == correct_answer && option[1] == correct_answer)
        option_choose();
    else
        option_choose();
}

void fdgd(){
//try{
	if(your_attempt == (correct_answer)){
		cout << "Congradulations, that is correct" << endl;
		right_answer_count += 1;
	} else if(your_attempt == new_random || your_attempt != your_attempt){
		cout << "You are wrong, the answer was " << correct_answer << endl;
		wrong_answer_count += 1;
	} else {
       // throw "Invaild Number: ";
	}
//}
	//catch(const char* l){
     //   cout << "you attempted to write a text or a letter instead of integer" << endl;
    //    std::terminate();
	//}
}
//these functions generate random question and handle the answers
//I had to create four fricking functions for the program to ask four different questions!

void GRQATAFA(){
    correct_answer = random_number1 + random_number2;
	cout << random_number1 << " + " << random_number2 << " = " << " ?\n";
    options();
	cin >> your_attempt;

    fdgd();
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
