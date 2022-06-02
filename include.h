#ifndef INCLUDE_H
#define INCLUDE_H

//this file contains all the preprocessors and classes for the whole project
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

using namespace std;

class Display {
private:
    void horizontal_rule(char symbol);
public:
    int number_Of_Questions;
    //greets the user :)
    void Welcome_Text();
};

class Option {
	/*
	the print operation commented in // are debug texts to check
	whether the conditions are working.
	you can uncomment them to see which option gets executed
	*/
private:
    int new_random_number;
	bool option_order;
	int option_choose[2];
	/*
	  just a regular format, it is like this, since I wanted to randomize the options
	  so the options wouldn't be in one format, correct answers in one position
	  to give you a feeling that you're really taking an MCQ test
	*/
	void choose_option(double answer);
	void generate_unique_number(double option1, double option2, double answer);
	//it chooses the new option if the answer is same as the other option
	void choose_new_option(double answer);

public:
	/*
	  shows the options on screen,
	  but before showing it checks whether the other option matches the correct answer or not
	*/
	void show_options(double right_answer);

};


class Solve {
private:
	//this is the function to stop the overflow and go on, uses <limits> here
	void stop_buffer_overflow();

public:
	//to check whether the answer was correct or not
	void check_answer(float your_attempt, float correct_answer);
	void final_score();
};

class Generate_Question {
private:
    Option choice;
	Solve solve;
	Display screen;
	/*
	common format for four different types of questions
	op means operator but I can't fully write 'operator' since it is a C++ keyword
	*/
	void question_format(string op);

public:
    int random_number;
    int random_number2;
    string operators[4] = {" + ", " - ", " * ", " / "};
    float correct_answer;
    float your_attempt;

	//types of questions which utilizeS the question_format()
	float Addition(float random_number1, float random_number2);
	float Subtraction(float random_number1, float random_number2);
	float Multiplication(float random_number1, float random_number2);
	float Division(float random_number1, float random_number2);

	//chooses the question randomly with random_numbers parameters
	void choose_question();
};

class Display_2 : public Display {
public:
    //I removed that 'e' letter since generate is a C++ keyword
    Generate_Question genrat;
    Solve solve;

    Display_2();
};

#endif
