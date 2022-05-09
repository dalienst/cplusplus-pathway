#include "splashkit.h"
#include<string>

//procedure to display the menu
void display_menu() 
{
    write_line("Menu");
    write_line("1. Write your Name: ");
    write_line("2. Enter a Name and a message: ");
    write_line("3. Play a Game");
    write_line("4. Exit");
}

//returns a string of the input from the terminal
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

//to read an integer from the user
int read_integer(string prompt) 
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}
//function for option 1 asking user to enter their name
string your_name() 
{
    string name;
    string result;
    name = read_string("Enter your name: ");
    write_line(name);
    return name;
}
//Option 2 function to ask user to enter name and a message and manipulate strings
string name_and_message() 
{
    string name;
    string message;
    string capitalize;
    string lower;

    //input name and message
    name = read_string("Enter friend's or tutor's name: ");
    message = read_string("Send them a message: ");
    write_line("Hello "+ name + "." + "\nHere's a message for you: " + message);
    write_line(" ");

    //change to uppercase
    capitalize = to_uppercase(name + " " + message);
    write_line("In Uppercase: " + capitalize);
    write_line(" ");

    //change to lowercase
    lower = to_lowercase(name + " " + message);
    write_line("In lowercase: " + lower);
    return name;
    return message;
    return capitalize;
    return lower;
}
//function to play game
int play_game() 
{
    //generate random number between 1 and 100
    int num = rand() % 100 + 1;
    int userInput = 0;
    int guess;
    write_line("Welcome to the number guessing number.");
    while (userInput < num)
    {
        userInput += 1;
        guess = read_integer("Guess number between 1 and 100: ");
        if (guess < 1 or guess > 100)
        {
            write_line("You are beyond limits!!!");
            break;
        };
        if (num == guess)
        {
            write_line("Congratulations!!! You got it");
            break;
        }else if (num > guess)
        {
            write_line("You guessed lower.");
            write("The answer is: ");
            write_line(num);
            break;
        }else if (num < guess)
        {
            write_line("You guessed higher.");
            write("The answer is: ");
            write_line(num);
            break;
        }else{
            write("The answer is: ");
            write_line(num);
            break;
        };
        
    }
    return 0; 
}

//main() body
int main()
{
    int option;

    display_menu();
    option = read_integer("Select your choice (1, 2, 3, 4): ");

    do{
        switch (option)
        {
            //choice 1
        case 1:
            your_name();
            break;

        //choice 2
        case 2:
            name_and_message();
            break;

        //choice 3
        case 3:
            play_game();
            break;

        //choice 4
        case 4:
            write_line("Bye");
            break;

        default:
            write_line("Start again");
            break;
        }
        
    }while ((option = read_integer("Select your choice (1, 2, 3, 4): ")) == true);
    

    return 0;
}