#include "include.h"

void Display::horizontal_rule(char symbol){
    for(int i = 0; i <= 53; i++){
        cout << symbol;
    }
    cout << "\n";
}

void Display::Welcome_Text(){
    horizontal_rule('=');
    cout << "Hello playa :)\n";
    cout << "Welc\'u\'me to the Math Quiz Game!\n";
    cout << "where you are given a question with two choices\n";
    cout << "if the answer you entered is correct, you get a point\nit will be added to the overall score";
    cout << "\nwhich will be shown at the end of the quiz\n";
    cout << "if the answer is wrong, no points for you sunny Jim :)\n";
    cout << "you can choose to get any number of questions you want\nI recommend having lower than/equal to 10 or 15\nThe limit is 25\n";
    cout << "so you don't keep answering forever like a moron :P" << endl;
    horizontal_rule('=');
    cout << "+++++++++++++++Owner Contact Details++++++++++++++++++\n";
    cout << "Discord: https://discord.com/users/481829350749110293\n";
    cout << "Itch.io: https://rellotscrewdriver.itch.io/\n";
    horizontal_rule('+');
}

Display_2::Display_2(){
    Display screen;
    screen.Welcome_Text();

    //asks the user to input how many times question needs to be displayed
    cout << "Number of Questions: ";
    cin >> number_Of_Questions;
    if(number_Of_Questions <= 25){

        for (int i = 1; i <= number_Of_Questions; i++) {
            //here's the question displayed
            cout << "Question: " << i << endl;
            genrat.choose_question();
            cout << endl << endl;
        }
        solve.final_score();

    } else {
        cout << "Maximum Questions reached! The Limit is 25 or You put an invalid number" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

}
