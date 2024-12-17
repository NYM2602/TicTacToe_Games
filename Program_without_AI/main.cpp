/*
Foldername: A2_Task23_AllB_20230716_S26_20230567_S26_20230449.zip 
Purpose: This program contains 8 board games to play
Authors:  Aseel Mohamed Hatem       Section: All B      ID: 20230716
          Mariam Mohamed            Section: S26        ID: 20230567
          Noura Yasser Mohamed      Section: S26        ID: 20230449

Date Created: 28/11/2024
Program Description:
This program allows the user to play 8 different Tic-Tac-Toe games
1) Pyramid Tic-Tac-Toe
2) Four in a row
3) 5x5 Tic-Tac-Toe
4) Word Tic-Tac-Toe
5) Numerical Tic-Tac-Toe
6) Misere (Inverse) Tic-Tac-Toe
7) Ultimate Tic-Tac-Toe
8) SUS

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
            cout << "*** Pyramid Tic-Tac-Toe ***" << endl;
            
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
                p2_name = ask_for_name("the second player");
            }
            
            p2_smbl = p1_smbl == 'X' ? 'O' : 'X'; //set the symbol of player 2 to the opposite of player 1
            

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new Pyr_XO_Player<char>(p1_name, p1_smbl);
            }
            else {
                players[0] = new Pyr_XO_RandomPlayer<char>(p1_smbl);
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new Pyr_XO_Player<char>(p2_name, p2_smbl);
            }
            else {
                players[1] = new Pyr_XO_RandomPlayer<char>(p2_smbl);
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
            cout << "*** Four in a row ***" << endl;
                        
            Player<char>* players[2];
            FourInARowBoard<char>* board = new FourInARowBoard<char>();
            string p1_name, p2_name;
            char p1_type, p2_type, p1_smbl, p2_smbl;


            //setup player 1
            p1_type = ask_for_plyr_type("the first player"); // ask if human or random
            
            if (p1_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the first player");
            }
            
            p1_smbl = ask_for_symbol("Please enter the symbol of the first player (X or O): ", 2);
            
            
            //set up player 2
            
            p2_type = ask_for_plyr_type("the second player"); // ask if human or random
            
            if (p2_type == '1') {   //if it is a human player then ask for name
                p2_name = ask_for_name("the second player");
            }
            
            p2_smbl = p1_smbl == 'X' ? 'O' : 'X'; //set the symbol of player 2 to the opposite of player 1

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new FourInARowPlayer<char>(p1_name, p1_smbl);
            }
            else {
                players[0] = new FourInARowRandomPlayer<char>(p1_smbl);
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new FourInARowPlayer<char>(p2_name, p2_smbl);
            }
            else {
                players[1] = new FourInARowRandomPlayer<char>(p2_smbl);
            }

            // set board for players
            players[0]->setBoard(board);
            players[1]->setBoard(board);

            //initialize game manager
            GameManager<char> FourInARowGame(board, players);
            FourInARowGame.run();

            delete board;
            delete players[0];
            delete players[1];
        }

        else if (game == '3') { // 5x5 Tic-Tac-Toe
            cout << "*** 5x5 Tic-Tac-Toe ***" << endl;

            Player<char>* players[2];
            FiveXFive_Board<char>* board = new FiveXFive_Board<char>();
            string p1_name, p2_name;
            char p1_type, p2_type, p1_smbl, p2_smbl;


            //setup player 1
            p1_type = ask_for_plyr_type("the first player"); // ask if human or random
            
            if (p1_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the first player");
            }
            
            p1_smbl = ask_for_symbol("Please enter the symbol of the first player (X or O): ", 3);
            
            
            //set up player 2
            
            p2_type = ask_for_plyr_type("the second player"); // ask if human or random
            
            if (p2_type == '1') {   //if it is a human player then ask for name
                p2_name = ask_for_name("the second player");
            }
            
            p2_smbl = p1_smbl == 'X' ? 'O' : 'X'; //set the symbol of player 2 to the opposite of player 1

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new FiveXFive_Player<char>(p1_name, p1_smbl);
            }
            else {
                players[0] = new FiveXFive_Random_Player<char>(p1_smbl);
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new FiveXFive_Player<char>(p2_name, p2_smbl);
            }
            else {
                players[1] = new FiveXFive_Random_Player<char>(p2_smbl);
            }

            // set board for players
            players[0]->setBoard(board);
            players[1]->setBoard(board);

            //initialize game manager
            GameManager<char> FiveXFive_Game(board, players);
            FiveXFive_Game.run();

            delete board;
            delete players[0];
            delete players[1];
        }

        else if (game == '4') { // Word Tic-Tac-Toe
            cout << "*** Word Tic-Tac-Toe ***" << endl;

            Player<char>* players[2];
            Word_XO_Board<char>* board = new Word_XO_Board<char>();
            string p1_name, p2_name;
            char p1_type, p2_type;

            //setup player 1
            p1_type = ask_for_plyr_type("the first player"); // ask if human or random
            
            if (p1_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the first player");
            }
            
            
            //set up player 2
            
            p2_type = ask_for_plyr_type("the second player"); // ask if human or random
            
            if (p2_type == '1') {   //if it is a human player then ask for name
                p2_name = ask_for_name("the second player");
            }
            

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new Word_XO_Player<char>(p1_name, 'A');
            }
            else {
                players[0] = new Word_XO_RandomPlayer<char>('A');
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new Word_XO_Player<char>(p2_name, 'B');
            }
            else {
                players[1] = new Word_XO_RandomPlayer<char>('B');
            }

            // set board for players
            players[0]->setBoard(board);
            players[1]->setBoard(board);

            //initialize game manager
            GameManager<char> Word_XO_Game(board, players);
            Word_XO_Game.run();

            delete board;
            delete players[0];
            delete players[1];
        }

        else if (game == '5') { // Numerical Tic-Tac-Toe
            cout << "*** Numerical Tic-Tac-Toe ***" << endl;
                        
            Player<int>* players[2];
            NumericalTicTacToeBoard<int>* board = new NumericalTicTacToeBoard<int>();
            string p1_name, p2_name;
            char p1_type, p2_type, p1_smbl, p2_smbl;


            //setup player 1
            p1_type = ask_for_plyr_type("the first player"); // ask if human or random
            
            if (p1_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the first player");
            }
            
            p1_smbl = ask_for_symbol("Please enter the parity of the first player:\n1) Odd\n2) Even", 5);
            
            
            //set up player 2
            
            p2_type = ask_for_plyr_type("the second player"); // ask if human or random
            
            if (p2_type == '1') {   //if it is a human player then ask for name
                p2_name = ask_for_name("the second player");
            }
            
            p2_smbl = p1_smbl == '1' ? '0' : '1';  //set the parity of the second player to the opposite of first player

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new NumericalTicTacToePlayer<int>(p1_name, 0, p1_smbl - '0');
            }
            else {
                players[0] = new NumericalTicTacToeRandomPlayer<int>(0, p1_smbl - '0');
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new NumericalTicTacToePlayer<int>(p2_name, 0, p2_smbl - '0');
            }
            else {
                players[1] = new NumericalTicTacToeRandomPlayer<int>(0, p2_smbl - '0');
            }

            // set board for players
            players[0]->setBoard(board);
            players[1]->setBoard(board);

            //initialize game manager
            GameManager<int> NumericalTicTacToeGame(board, players);
            NumericalTicTacToeGame.run();

            delete board;
            delete players[0];
            delete players[1];
        }

        else if (game == '6') { //Misere (Inverse) Tic-Tac-Toe
            cout << "*** Misere (Inverse) Tic-Tac-Toe ***" << endl;

            Player<char>* players[2];
            Misere_board<char>* board = new Misere_board<char>();
            string p1_name, p2_name;
            char p1_type, p2_type, p1_smbl, p2_smbl;


            //setup player 1
            p1_type = ask_for_plyr_type("the first player"); // ask if human or random
            
            if (p1_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the first player");
            }
            
            p1_smbl = ask_for_symbol("Please enter the symbol of the first player (X or O): ", 6);
            
            
            //set up player 2
            
            p2_type = ask_for_plyr_type("the second player"); // ask if human or random
            
            if (p2_type == '1') {   //if it is a human player then ask for name
                p2_name = ask_for_name("the second player");
            }
            
            p2_smbl = p1_smbl == 'X' ? 'O' : 'X'; //set the symbol of player 2 to the opposite of player 1

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new Misere_Player<char>(p1_name, p1_smbl);
            }
            else {
                players[0] = new Misere_Random_Player<char>(p1_smbl);
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new Misere_Player<char>(p2_name, p2_smbl);
            }
            else {
                players[1] = new Misere_Random_Player<char>(p2_smbl);
            }

            // set board for players
            players[0]->setBoard(board);
            players[1]->setBoard(board);

            //initialize game manager
            GameManager<char> Misere_Game(board, players);
            Misere_Game.run();

            delete board;
            delete players[0];
            delete players[1];
        }

        else if (game == '7') { // Ultimate Tic-Tac-Toe
            cout << "*** Ultimate Tic-Tac-Toe ***" << endl;
            
            Player<char>* players[2];
            UltimateBoard<char>* board = new UltimateBoard<char>();
            string p1_name, p2_name;
            char p1_type, p2_type, p1_smbl, p2_smbl;


            //setup player 1
            p1_type = ask_for_plyr_type("the first player"); // ask if human or random
            
            if (p1_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the first player");
            }
            
            p1_smbl = ask_for_symbol("Please enter the symbol of the first player (X or O): ", 7);
            
            
            //set up player 2
            
            p2_type = ask_for_plyr_type("the second player"); // ask if human or random
            
            if (p2_type == '1') {   //if it is a human player then ask for name
                p2_name = ask_for_name("the second player");
            }
            
            p2_smbl = p1_smbl == 'X' ? 'O' : 'X'; //set the symbol of player 2 to the opposite of player 1
            

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new UltimatePlayer<char>(p1_name, p1_smbl);
            }
            else {
                players[0] = new UltimateRandomPlayer<char>(p1_smbl);
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new UltimatePlayer<char>(p2_name, p2_smbl);
            }
            else {
                players[1] = new UltimateRandomPlayer<char>(p2_smbl);
            }

            // set board for players
            players[0]->setBoard(board);
            players[1]->setBoard(board);

            //initialize game manager
            GameManager<char> UltimateGame(board, players);
            UltimateGame.run();

            delete board;
            delete players[0];
            delete players[1];
        }

        else if (game == '8') { // SUS
            cout << "*** SUS ***" << endl;
            
            Player<char>* players[2];
            SUS_XO_Board<char>* board = new SUS_XO_Board<char>();
            string p1_name, p2_name;
            char p1_type, p2_type, p1_smbl, p2_smbl;


            //setup player 1
            p1_type = ask_for_plyr_type("the first player"); // ask if human or random
            
            if (p1_type == '1') {   //if it is a human player then ask for name
                p1_name = ask_for_name("the first player");
            }
            
            p1_smbl = ask_for_symbol("Please enter the symbol of the first player (S or U): ", 8);
            
            
            //set up player 2
            
            p2_type = ask_for_plyr_type("the second player"); // ask if human or random
            
            if (p2_type == '1') {   //if it is a human player then ask for name
                p2_name = ask_for_name("the second player");
            }
            
            p2_smbl = p1_smbl == 'S' ? 'U' : 'S'; //set the symbol of player 2 to the opposite of player 1

            //initialize players
            //player 1
            if (p1_type == '1') {
                players[0] = new SUS_XO_Player<char>(p1_name, p1_smbl);
            }
            else {
                players[0] = new SUS_XO_RandomPlayer<char>(p1_smbl);
            }
            //player 2
            if (p2_type == '1') {
                players[1] = new SUS_XO_Player<char>(p2_name, p2_smbl);
            }
            else {
                players[1] = new SUS_XO_RandomPlayer<char>(p2_smbl);
            }

            // set board for players
            players[0]->setBoard(board);
            players[1]->setBoard(board);

            //initialize game manager
            GameManager<char> SUS_XO_Game(board, players);
            SUS_XO_Game.run();

            delete board;
            delete players[0];
            delete players[1];
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

        if (gamenum == 5) { // get parity for numericat tic-tac-toe
            if (smbl == '1') { // odd parity
                return '1';
            }
            else if (smbl == '2') { //even parity
                return '0';
            }
            else {
                cout << "This is not a valid choice" << endl;
            }
        }
        else if (gamenum == 8) { // SUS game
            if (smbl == 'S' || smbl == 'U') {
                return smbl;
            }
            cout << "This is not a valid symbol" << endl;
        }
        else { //games that use X and O
            if (smbl == 'X' || smbl == 'O') {
                return smbl;
            }
            cout << "This is not a valid symbol" << endl;
        }
    }
}
