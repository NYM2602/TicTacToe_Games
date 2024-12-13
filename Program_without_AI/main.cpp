/*
Foldername: A2_Task2345_AllB_20230716_S26_20230567_S26_20230449.zip 
Purpose: This program contains 8 board games to play
Authors:  Aseel Mohamed             Section: All B      ID: 20230716
          Mariam Mohamed            Section: S26        ID: 20230567
          Noura Yasser Mohamed      Section: S26        ID: 20230449

Date Created: 28/11/2024
Program Description:
--TBM--
*/



#include <iostream>
#include "BoardGame_Classes.h"
#include "NewGames.h"

using namespace std;

string ask_for_name(string player);
char ask_for_plyr_type(string player);
char ask_for_symbol(string prompt, int gamenum);

int main() {
    while (true) {
        //Display menu
        cout << "*** Welcome to this game hub ***" << endl;
        cout << "What do you want to play?" << endl;
        cout << "1) Pyramid Tic-Tac-Toe" << endl;
        cout << "2) Four in a row" << endl;
        cout << "3) 5x5 Tic-Tac-Toe" << endl;
        cout << "4) Word Tic-Tac-Toe" << endl;
        cout << "5) Numerical Tic-Tac-Toe" << endl;
        cout << "6) Misere (Inverse) Tic-Tac-Toe" << endl;
        cout << "7) Ultimate Tic-Tac-Toe" << endl; // Game 8
        cout << "8) SUS" << endl; // Game 9
        cout << "0) Exit" << endl;
        cout << "Please enter your choice:" << endl;

        char game;
        cin>>game;
        cin.ignore();
        
        if (game == '1') { // Pyramid Tic-Tac-Toe
            Player<char>* players[2];
            Pyr_XO_Board<char>* board = new Pyr_XO_Board<char>();
            string p1_name, p2_name;
            char p1_type, p2_type, p1_smbl, p2_smbl;


            //setup player 1
            p1_type = ask_for_plyr_type("the first player"); // ask if human or random
            
            if (p1_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the first player");
            }
            
            p1_smbl = ask_for_symbol("Please enter the symbol of the first player (X or O): ", 1);
            
            
            //set up player 2
            
            p2_type = ask_for_plyr_type("the second player"); // ask if human or random
            
            if (p2_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the second player");
            }
            
            if (p1_smbl == 'X') { //set the symbol of player 2 to the opposite of player 1
                p2_smbl = 'O';
            }
            else {
                p2_smbl = 'X';
            } 

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new Pyr_XO_Player<char>(p1_name, p1_smbl);
                cout << "initialized player 1 as human" << endl;
            }
            else {
                players[0] = new Pyr_XO_RandomPlayer<char>(p1_smbl);
                cout << "initialized player 1 as random" << endl;
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new Pyr_XO_Player<char>(p2_name, p2_smbl);
                cout << "initialized player 2 as human" << endl;
            }
            else {
                players[1] = new Pyr_XO_RandomPlayer<char>(p2_smbl);
                cout << "initialized player 2 as random" << endl;
            }

            // set board for players
            players[0]->setBoard(board);
            players[1]->setBoard(board);

            //initialize game manager
            GameManager<char> Pyr_XO_Game(board, players);
            Pyr_XO_Game.run();

            delete board;
            delete players[0];
            delete players[1];

        }

        else if (game == '2'){ //Four in a row
            continue;
        }

        else if (game == '3') {
            continue;
        }

        else if (game == '4') {
            continue;
        }

        else if (game == '5') {
            continue;
        }

        else if (game == '6') {
            continue;
        }

        else if (game == '7') {
            continue;
        }

        else if (game == '8') {
            continue;
        }
        // Exit the program
        else if (game == '0') {
            cout << "Thank you for using this program :)" << endl;
            break;
        }
        //invalid choice
        else {
            cout << "This is not a valid choice" << endl;
        }
    }
    return 0;
}

string ask_for_name(string player) {
    while (true) {
        cout << "Please enter the name of " << player << ": ";
        string name;
        getline(cin, name);
        if (name.size() > 0) {
            return name;
        }
        cout << "The name string is empty" << endl;
    }
}
char ask_for_plyr_type(string player) {
    while (true) {
        cout << "Please choose the type of " << player << ":"<< endl;
        cout << "1) Human Player" << endl;
        cout << "2) Random Player" << endl;
        cout << "Please enter your choice: ";
        char ptype;
        cin >> ptype;
        cin.ignore();

        if (ptype == '1' || ptype == '2'){
            return ptype;
        }
        cout << "This is not a valid choice" << endl;
    }
}

char ask_for_symbol(string prompt, int gamenum) {
    while (true) {
        cout << prompt << endl;
        char smbl;
        cin>>smbl;
        cin.ignore();
        smbl = toupper(smbl);

        if (gamenum == 1) { //games that use X and O
            if (smbl == 'X' || smbl == 'O') {
                return smbl;
            }
            cout << "This is not a valid symbol" << endl;
        }
    }
}
