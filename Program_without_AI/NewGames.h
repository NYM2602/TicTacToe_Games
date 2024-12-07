#ifndef NEWGAMES_H
#define NEWGAMES_H

#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
using namespace std;


//Game 1
template <typename T>
class Pyr_XO_Board : public Board<T> {
public:
    Pyr_XO_Board();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};


template <typename T>
class Pyr_XO_Player : public Player<T> {
public:
    Pyr_XO_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Pyr_XO_RandomPlayer : public RandomPlayer<T>{
public:
    Pyr_XO_RandomPlayer (T symbol);
    void getmove(int &x, int &y) ;
};


//---------------------------------------Implementation

//Pyr_XO_Board Functions

//Constructor for the board
template <typename T>
Pyr_XO_Board<T>::Pyr_XO_Board() {
    this->rows = 3;
    this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            if ((i==0 && (j<2 || j>2)) || (i==1 && (j<1 || j>3))){
                this->board[i][j] = '0';
            }
            else{
                this->board[i][j] = 0;
            }
        }
    }
    this->n_moves = 0;
}

//Update move with the new move
template <typename T>
bool Pyr_XO_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the moves already made
template <typename T>
void Pyr_XO_Board<T>::display_board() {
    cout << "\n |";
    for (int j = 0; j < this->columns; j++) {
        cout << " " << j << " |";
    }
    cout << "\n----------------------\n";

    for (int i = 0; i < this->rows; i++) {
        cout << i << "|";
        if (i == 0){
            cout << setw(8) << "|";
            if (this->board[i][2] == 0) {
                    cout <<" . |";
            }
            else {
                cout << setw(2) << this->board[i][2] << " |";
            }
        }
        else if (i == 1) {
            cout << setw(4) << "|";
            for (int j = 1;j <= 3;j++){
                if (this->board[i][j] == 0) {
                    cout <<" . |";
                }
                else {
                    cout << setw(2) << this->board[i][j] << " |";
                }
            }
        }

        else {
            for (int j = 0;j < this->columns;j++){
                if (this->board[i][j] == 0) {
                    cout <<" . |";
                }
                else {
                    cout << setw(2) << this->board[i][j] << " |";
                }
            }
        }
        cout << "\n----------------------\n";
    }
    cout << endl;
}

// Check if there is a winner
template <typename T>
bool Pyr_XO_Board<T>::is_win() {
    // Check rows
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns-2; j++)
            if (this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2] && this->board[i][j] != 0 && this->board[i][j] != '0') {
                return true;
            }
    }

    // Check column
    if (this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2] && this->board[0][2] != 0) {
        return true;
    }

    // Check diagonals
    if ((this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0) ||
        (this->board[0][2] == this->board[1][3] && this->board[1][3] == this->board[2][4] && this->board[0][2] != 0)) {
        return true;
    }

    return false;
}

// Check if there is a draw
template <typename T>
bool Pyr_XO_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

//Check if game is over
template <typename T>
bool Pyr_XO_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//------------------------------------------

//Pyr_XO_Player Functions

//Constructor for the Pyr_XO_Player
template <typename T>
Pyr_XO_Player<T>::Pyr_XO_Player(string name, T symbol) : Player<T>(name, symbol) {}


//Function to get next move
template <typename T>
void Pyr_XO_Player<T>::getmove(int& x, int& y) {
    char row, col;
    while (true){
        cout << "\nPlease enter your move: row no. x (0 to 2) and column no. y (0 to 4) separated by spaces: ";
        cin>>row>>col;
        if ((row - '0' >= 0 && row - '0' <= 2) &&
            (col - '0' >= 0 && col - '0' <= 4)) {
                break;
        }
        else {
            cout << "This move is out of range" << endl;
        }
    }
    x = row - '0';
    y = col - '0';
}

//Pyr_XO_RandomPlayer Functions

//Constructor for Pyr_XO_RandomPlayer
template <typename T>
Pyr_XO_RandomPlayer<T>::Pyr_XO_RandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Pyr_XO_RandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % (this->dimension+2);
}

//Game 2




//Game 3




//Game 4

template <typename T>
class Word_XO_Board : public Board<T> {
public:
    set<string> words;
    Word_XO_Board();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};


template <typename T>
class Word_XO_Player : public Player<T> {
public:
    Word_XO_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Word_XO_RandomPlayer : public RandomPlayer<T>{
public:
    Word_XO_RandomPlayer (T symbol);
    void getmove(int &x, int &y) ;
};



//---------------------------------------Implementation

//Word_XO_Board Functions

//Constructor for the board
template <typename T>
Word_XO_Board<T>::Word_XO_Board() {
    //initialize board
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    //Store valid words
    ifstream file("dic.txt");
    string word;
    while (file >> word){
        words.insert(word);
    }
}

//Update move with the new move
template <typename T>
bool Word_XO_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the moves already made
template <typename T>
void Word_XO_Board<T>::display_board() {
    cout << "\n |";
    for (int j = 0; j < this->columns; j++) {
        cout << " " << j << " |";
    }
    cout << "\n--------------\n";

    for (int i = 0; i < this->rows; i++) {
        cout << i << "|";
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] == 0) {
                    cout <<" . |";
            }
            else {
                cout << setw(2) << this->board[i][j] << " |";
            }
        }
        cout << "\n--------------\n";
    }
    cout << endl;
}

// Check if there is a winner
template <typename T>
bool Word_XO_Board<T>::is_win() {
    // Check rows and columns
    string row = {this->board[i][0], this->board[i][1], this->board[i][2]}, row_rev = {this->board[i][2], this->board[i][1], this->board[i][0]};
    string col = {this->board[0][i], this->board[1][i], this->board[2][i]}, col_rev = {this->board[2][i], this->board[1][i], this->board[0][i]};
    for (int i = 0; i < this->rows; i++) {
        if ((words.count(row) || words.count(row_rev)) ||
            (words.count(col) || words.count(col_rev))) {
            return true;
        }
    }

    // Check diagonals
    string diag1 = {this->board[0][0], this->board[1][1], this->board[2][2]}, diag1_rev = {this->board[2][2], this->board[1][1], this->board[0][0]};
    string diag2 = {this->board[0][2], this->board[1][1], this->board[2][0]}, diag2_rev = {this->board[2][0], this->board[1][1], this->board[0][2]};
    if ((words.count(diag1) || words.count(diag1_rev)) ||
        (words.count(diag2) || words.count(diag2_rev))) {
        return true;
    }

    return false;
}

// Check if there is a draw
template <typename T>
bool Word_XO_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

//Check if game is over
template <typename T>
bool Word_XO_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//------------------------------------------

//Word_XO_Player Functions

//Constructor for the Word_XO_Player
template <typename T>
Word_XO_Player<T>::Word_XO_Player(string name, T symbol) : Player<T>(name, symbol) {}


//Function to get next move
template <typename T>
void Word_XO_Player<T>::getmove(int& x, int& y) {
    char row, col, smbl;
    while (true) {
        cout << "\nPlease enter the letter you want to add to the board: ";
        cin>>smbl;
        if (isalpha(smbl)) {
            symbol = smbl;
            break;
        }
        else {
            cout << "This is not a valid letter" << endl;
        }
    }
    while (true){
        cout << "\nPlease enter your move: row no. x (0 to 2) and column no. y (0 to 2) separated by spaces: ";
        cin>>row>>col;
        if ((row - '0' >= 0 && row - '0' <= 2) &&
            (col - '0' >= 0 && col - '0' <= 2)) {
                break;
        }
        else {
            cout << "This move is out of range" << endl;
        }
    }
    x = row - '0';
    y = col - '0';
}

//Word_XO_RandomPlayer Functions

//Constructor for Word_XO_RandomPlayer
template <typename T>
Word_XO_RandomPlayer<T>::Word_XO_RandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Word_XO_RandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % (this->dimension);
    symbol = 'A' + (rand() % 26);  // Generate random letter
}


//Game 5




//Game 6





//Game 8




//Game 9






#endif //NEWGAMES_H