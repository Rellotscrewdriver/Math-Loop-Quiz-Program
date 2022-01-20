#include "include.h"

void Option::show_options(double right_answer) {
    new_random_number = -69 + rand() % (-69 - 1 + 1); //noice
    option_choose[0] = 2.0 + fmod(rand(), 10.0);
    option_choose[1] = 2.0 + fmod(rand(), 10.0);
    option_order = rand() % 2;

    if (option_choose[0] == option_choose[1]) {
        //cout << "first condition at show_options() is executed" << endl;
        choose_new_option(right_answer);
    } else if (option_choose[0] == right_answer || option_choose[1] == right_answer) {
        //cout << "second condition at show_options() is executed" << endl;
        choose_new_option(right_answer);
    } else {
       //cout << "third condition at show_options() is executed" << endl;
        choose_option(right_answer);
    }
}

void Option::choose_option(double answer) {
    //here true = 1, false = 0
    if (option_order == true) {
        //cout << "first condition located at choose_option() is executed" << endl;
        cout << "Options: " << option_choose[0] << " or " << answer << "\nYour Answer: ";
    } else {
        //cout << "second conditon located at choose_option() is executed" << endl;
        cout << "Options: " << answer << " or " << option_choose[1] << "\nYour Answer: ";
    }
}

//it chooses the new option if the show_options are uhh
void Option::choose_new_option(double answer) {
    //here same case
    if (option_order == true) {
        //cout << "first condition located at choose_new_option() is executed" << endl;
        cout << "Options: " << new_random_number << " or " << answer << "\nYour Answer: ";
    } else {
        //cout << "second conditon located at choose_new_option() is executed" << endl;
        cout << "Options: " << answer << " or " << new_random_number << "\nYour Answer: ";
    }
}
