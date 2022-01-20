#include "include.h"

void Display::horizontal_rule(string symbol){
    for(int i = 0; i <= 50; i++){
        cout << symbol;
    }
    cout << "\n";
}

void Display::Welcome_Text(){
    horizontal_rule("=");
    cout << "Hello playa :)\n";
    cout << "Welc\'u\'me to the Math Quiz program!\n";
    cout << "where you are given a question with two choices\n";
    cout << "if the answer you entered is correct, you given a point and will be added to the overall score";
    cout << "\n which will be shown at the end of the quiz\n";
    cout << "if the answer is wrong, no points for you sunny Jim :)\n";
    horizontal_rule("=");
    cout << "you can choose to get any number of questions you want\nI recommend having lower than/equal to 10 or 15" << endl;
}

Display_2::Display_2(){
    Display screen;
    screen.Welcome_Text();

    //asks the user to input how many times question needs to be displayed
    cout << "Number of Questions: ";
    cin >> number_Of_Questions;

    for (int i = 1; i <= number_Of_Questions; i++) {
        //here's the question displayed
        cout << "Question: " << i << endl;
        genrat.choose_question();
        cout << endl << endl;
    }

    solve.final_score();
}
