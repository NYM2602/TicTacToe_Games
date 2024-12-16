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
template <typename T>
class FiveXFive_Board : public Board<T> {
private:
    int t_moves=0;
    bool winner=false;
    int player1_scr = 0;
    int player2_scr = 0;
public:
    FiveXFive_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    int count_three(T symbol); // additional func to count each three in a row, column or diagonal
};

template <typename T>
class FiveXFive_Player : public Player<T> {
public:
    FiveXFive_Player(std::string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class FiveXFive_Random_Player:public RandomPlayer<T> {
public:
    FiveXFive_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

//=============================================================================
//                               IMPLEMENTATION
//=============================================================================

template <typename T>
FiveXFive_Board<T>::FiveXFive_Board() {    //constructor of the FiveXFive_Board class (makes the board empty)
    this->rows = this->columns = 5;  // the size of the board 5x5
    this->board = new char*[this->rows];
    // loops on whole board to make it empty make all the cells empty
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = '-';
        }
    }
    //number of moves and total moves are zero
    this->n_moves = 0;
    t_moves=0;
}

template <typename T>
void FiveXFive_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout <<setw(1) << this->board[i][j] << " |";
        }
        cout << "\n__________________________________________";
    }
    cout << endl;
}

template <typename T>
bool FiveXFive_Board<T>::update_board(int x, int y, T symbol) {
    //if the move is valid place the symbol in the position and increment the counter
    if (x <0|| x>=this->rows|| y<0||y>= this->columns) {
        cerr<< "invalid move (out of bounds): ( " << x << "," << y << " )"<<endl;
        return false;}

    if (this->board[x][y] != '-') {
        cerr<< "invalid cell (already played): (" << x << ", " << y << ")\n";
        return false;}
    this->board[x][y] = toupper(symbol);
    this->n_moves++;
    t_moves++;
    cout << "valid move:(" << x << ", " << y << ")  symbol-> " << symbol << "\n";
    return true;
}

// func that counts each three (vertical ,horizontal ,diagonal)
template <typename T>
int FiveXFive_Board<T>::count_three(T symbol) {
    int count = 0;

    for (int i = 0; i < this->rows; i++) {      //check each three in a row and increment hte counter
        for (int j = 0;j<=this->columns-3; j++) {
            if (this->board[i][j] == symbol && this->board[i][j+1] == symbol && this->board[i][j+2] == symbol) {
                count++;}
        }
    }
    for (int i=0;i<=this->rows-3;i++){     //check each three in a column and increment hte counter
        for(int j=0;j< this->columns;j++){
            if (this->board[i][j]==symbol && this->board[i+1][j]==symbol && this->board[i+2][j]==symbol){
                count++;
            }
        }
    }
    for (int i=0;i<=this->rows-3 ;i++){     //checks each three diagonally (left)
        for(int j=0;j<=this->columns-3 ;j++){
            if (this->board[i][j]==symbol && this->board[i+1][j+1]==symbol && this->board[i+2][j+2]==symbol){
                count++;
            }
        }
    }
    for (int i=0;i<=this->rows-3 ;i++){     //checks each three diagonally (right)
        for(int j=0;j<=this->columns-3 ;j++){
            if (this->board[i][j]==symbol && this->board[i+1][j-1]==symbol && this->board[i+2][j-2]==symbol){
                count++;
            }
        }
    }
    return count;}

template <typename T>   // Check if the game is a draw
bool FiveXFive_Board<T>::is_draw() {
    //condition when game is draw
    return (this->n_moves == 24 && player1_scr==player2_scr);
}

template <typename T>  //check the winner
bool FiveXFive_Board<T>::is_win() {
    if(!winner &&t_moves==24){
        player1_scr=count_three('X');
        player2_scr=count_three('O');
        winner=true;
    }
    return (player1_scr > player2_scr)||(player2_scr>player1_scr);
}

template <typename T>  // Check whether the game is over or not
bool FiveXFive_Board<T>::game_is_over() {
    return (is_win()) || (is_draw());
}

//================================================================
//                      PLAYERS IMPLEMENTATION
//================================================================

template <typename T>
FiveXFive_Player<T>::FiveXFive_Player(std::string name, T symbol) : Player<T>(name, symbol) {}

// Get the player's move
template <typename T>
void FiveXFive_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
    cout<< "Player input: (" << x << ", " << y << ")\n";
}

//================================================================
//                     RANDOM  PLAYERS IMPLEMENTATION
//================================================================

// Constructor for FiveByFive_Random_Player
template <typename T>
FiveXFive_Random_Player<T>::FiveXFive_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 5;  // Dimension for random move generation
    srand(static_cast<unsigned int>(time(0)));  // Seed random generator
}

// Generate a random move
template <typename T>
void FiveXFive_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() %5;
    y = rand() %5;
}


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

template <typename T>
class Misere_board : public Board<T> {
private:
    int player1_counter=1;
    int player2_counter=1;
    bool flag=false;
public:
    Misere_board();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over()override;
    int count(T symbol);      // counts number of wins

};
template <typename T>
class Misere_Player:public Player<T> {
public:
    Misere_Player(string name ,T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class Misere_Random_Player : public RandomPlayer<T> {
public:
    Misere_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};

//=============================================================================
//                               IMPLEMENTATION
//=============================================================================


template <typename T>
Misere_board<T>::Misere_board() {   //constructor of the FiveXFive_Board class (makes the board empty)
    this->rows = 3;    // the size of the board 3x3
    this->columns = 3;
    this->board = new char*[this->rows];
    // loops on whole board to make it empty make all the cells empty
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = '-';
        }
    }
    //number of moves=0
    this->n_moves = 0;
}
template <typename T>
bool Misere_board<T>::update_board(int x, int y, T symbol) {
    // Only update if move is valid
    if (!(x < 0|| x >= this->rows|| y <0|| y >= this->columns) && (this->board[x][y] == '-'|| symbol == '-')) {
        if (symbol == '-'){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(symbol);
        }
        return true;
    }
    return false;
}

template <typename T>
void Misere_board<T>::display_board(){
    for (int i = 0; i < this->rows; i++) {
        cout << "\n|| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " ||";
        }
        cout << "\n=======================================";
    }
    cout << endl;
}
template <typename T>
int Misere_board<T>::count(T symbol) {
    int count = 1;
    // Check each row for 3-in-a-row
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j <= this->columns - 3; j++) {
            if (this->board[i][j] == symbol && this->board[i][j+1] == symbol && this->board[i][j+2] == symbol) {
                count--;
                break;
            }
        }
    }
    // Check each column for 3-in-a-column
    for (int i = 0; i <= this->rows - 3; i++) {
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] == symbol && this->board[i+1][j] == symbol && this->board[i+2][j] == symbol) {
                count--;
                break;
            }
        }
    }

    // Check diagonals (left to right)
    for (int i = 0; i <= this->rows - 3; i++) {
        for (int j = 0; j <= this->columns - 3; j++) {
            if (this->board[i][j] == symbol && this->board[i+1][j+1] == symbol && this->board[i+2][j+2] == symbol) {
                count--;
                break;
            }
        }
    }
    // Check diagonals (right to left)
    for (int i = 0; i <= this->rows - 3; i++) {
        for (int j = this->columns - 1; j >= 2; j--) {
            if (this->board[i][j] == symbol && this->board[i+1][j-1] == symbol && this->board[i+2][j-2] == symbol) {
                count--;
                break;
            }
        }
    }
    return count;
}

template <typename T>
bool Misere_board<T>::game_is_over() {   //game is over when the game is win or draw
    if (is_win()||is_draw()) {
        return true;
    }
    return false;
}

template <typename T>
bool Misere_board<T>::is_win() {
    if (flag==true){
        return true;
    }
    player1_counter = count('X');
    player2_counter = count('O');
    if (player1_counter == 1&&player2_counter != 1) {
        flag = true;
        return false;
    }
    if (player2_counter == 1 && player1_counter != 1) {
        flag = true;
        return false;
    }
    return false;
}

template <typename T>
bool Misere_board<T>::is_draw() {
// Checking if all the cells are filled
    if (this->n_moves == this->rows * this->columns) {
        return !is_win(); // game is draw if no win
    }
    return false;
}

//================================================================
//                      PLAYERS IMPLEMENTATION
//================================================================

template <typename T>
Misere_Player<T>::Misere_Player(string name, T symbol) : Player<T>(name, symbol)  {}

template <typename T>
void Misere_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

//================================================================
//                     RANDOM  PLAYERS IMPLEMENTATION
//================================================================

template <typename T>
Misere_Random_Player<T>::Misere_Random_Player(T symbol) : Player<T>(symbol) {
    this->dimension =3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Speeds the random number generator
}

template <typename T>
void Misere_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 3;  // Random number between 0 and 2
    y = rand() % 3;
}


//Game 8

template <typename T>
class UltimateBoard : public Board<T> {
private:
    bool is_smallB_win[3][3];  // tracks if any of the small boards is_win
public:
    UltimateBoard();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
    bool is_smallB_winn(int row,int column);
};

template <typename T>
class UltimatePlayer : public Player<T> {
public:
    UltimatePlayer(string name, T symbol);
    void getmove(int& x, int& y) override;
};

template <typename T>
class UltimateRandomPlayer : public RandomPlayer<T> {
public:
    UltimateRandomPlayer(T symbol);
    void getmove(int& x, int& y) override;
};

//=============================================================================
//                               IMPLEMENTATION
//=============================================================================

template <typename T>
UltimateBoard<T>::UltimateBoard() {
    this->rows =9;  // size of ultimate board is 9x9
    this->columns =9;
    this->board=new T*[this->rows];
// loops on whole board to make it empty make all the cells empty
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = '-';
        }
    }
    //loops on the small board making its status false
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            is_smallB_win[i][j] = false;   //no wins yet
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool UltimateBoard<T>::update_board(int x, int y, T symbol) {
    int smallB_row = x/3;  // get the row num in the small board
    int smallB_col = y/3;  // get the column num in the small board

    //if the small board is win,the move isnt valid
    if(is_smallB_win[smallB_row][smallB_col]) {
        return false;
    }
    if (this->board[x][y] == '-') {  // placing the symbol if the position is empty
        this->board[x][y] = symbol;
        this->n_moves++;    // increment the moves
        if (is_smallB_winn(smallB_row, smallB_col)) {
            is_smallB_win[smallB_row][smallB_col] = true;
        }
        return true;
    }
    return false;
}

template <typename T>
void UltimateBoard<T>::display_board() {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout<< "(" <<i<< "," <<j<< ")";
            cout<< setw(1) << this->board[i][j]<<" ";
            if ((j+1)%3==0){
                cout << " * "; // Separate each small board by stars
            }
        }
        cout<<endl;
        if ((i + 1)%3==0){  //seprating each 3 rows
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
        }
    }
    cout<<endl;
}

template <typename T>
bool UltimateBoard<T>::is_smallB_winn(int smallB_row, int smallB_col) {
    T symbol = this->board[smallB_row * 3][smallB_col * 3];
    if (symbol == '-'){return false;}

    for (int i = 0; i < 3; i++) {// Check rows
        if (this->board[smallB_row*3+i][smallB_col*3]== symbol &&this->board[smallB_row*3+i][smallB_col*3+1]== symbol &&
        this->board[smallB_row*3+i][smallB_col*3+2]== symbol)
            return true;
    }
    for (int i = 0; i < 3; i++) {// Check columns
        if (this->board[smallB_row*3][smallB_col*3+i]== symbol &&
            this->board[smallB_row*3+1][smallB_col*3+i]== symbol &&
            this->board[smallB_row*3+2][smallB_col*3+i]== symbol){
            return true;}
    }
    // left to right diagonal
    if (this->board[smallB_row *3][smallB_col*3] == symbol &&
        this->board[smallB_row*3+1][smallB_col*3+1] == symbol &&
        this->board[smallB_row*3+2][smallB_col*3+2] ==symbol){
        return true;}
    //right to left diagonal
    if (this->board[smallB_row*3 +2][smallB_col * 3] == symbol &&
        this->board[smallB_row* 3+1][smallB_col*3+1] == symbol &&
        this->board[smallB_row*3][smallB_col*3+2]== symbol){
        return true;}

    return false;
}

template <typename T>
bool UltimateBoard<T>::is_win() {
    // Check each row, column, and diagonal of the 3x3 meta board
    for (int i = 0; i < 3; i++) {
        if (is_smallB_win[i][0] && is_smallB_win[i][1] && is_smallB_win[i][2]){return true;} // check each row in the small boards
        if (is_smallB_win[0][i] && is_smallB_win[1][i] && is_smallB_win[2][i]){return true;}  // check each column int the small boards
    }
    if (is_smallB_win[0][0] && is_smallB_win[1][1] && is_smallB_win[2][2]){return true;} // left to right diagonal
    if (is_smallB_win[0][2] && is_smallB_win[1][1] && is_smallB_win[2][0]){return true;} // right to left diagonal
    return false;
}

template <typename T>
bool UltimateBoard<T>::is_draw() {
    // game is draw if no win
    if (this->n_moves == this->rows * this->columns) {
        return !is_win();
    }
    return false;
}

template <typename T>
bool UltimateBoard<T>::game_is_over() {
    return is_win() || is_draw();
}
//================================================================
//                      PLAYER IMPLEMENTATION
//================================================================
template <typename T>
UltimatePlayer<T>::UltimatePlayer(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void UltimatePlayer<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move (x and y) separated by spaces (0 to 8): ";
    cin >> x >> y;
    cout<< "Player input: (" << x << ", " << y << ")\n";
}
//================================================================
//                     RANDOM PLAYER IMPLEMENTATION
//================================================================
template <typename T>
UltimateRandomPlayer<T>::UltimateRandomPlayer(T symbol) : RandomPlayer<T>(symbol) {}

template <typename T>
void UltimateRandomPlayer<T>::getmove(int& x, int& y) {
        x = rand() % 9;  // Random number between 0 and 8
        y = rand() % 9;
}

//Game 9


// Game 7

template <typename T>
class FourXFour_Board : public Board<T> {
private:
    vector<pair<int, int>> player_tokens[2]; // Track each player's token positions
    int player1_scr = 0;
     int player2_scr = 0;
public:
    FourXFour_Board();
    void display_board() override;
    bool update_board(int x, int y, T symbol) override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
    int count_three(T symbol); // additional func to count each three in a row, column or diagona
};
template <typename T>
class FourXFour_Player:public Player<T> {
public:
    FourXFour_Player(string name ,T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class FourXFour_Random_Player : public RandomPlayer<T> {
public:
    FourXFour_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};
//=====================================================================
//                         BOARD IMPLEMENTATION
//=====================================================================

template <typename T>
FourXFour_Board<T>::FourXFour_Board() {
    this->rows=this->columns = 4; // size of board 4x4
    this->board =new T*[4];
    for (int i=0; i<4; i++) {
        this->board[i] = new T[4];
        for (int j=0;j<4; j++) {
            this->board[i][j]= '-'; // make the board empty
        }
    }
    player_tokens[0] = {{0, 1},{0, 3},{3, 0},{3, 2}}; //initialize tokens of player 1 (X)
    player_tokens[1] = {{0, 0},{0, 2}, {3, 1},{3, 3}}; //initialize tokens of player 2 (O)
    // placing the tokens on the board
    for(const auto& pos:player_tokens[0]){ // tokens of player 1 (X)
        this->board[pos.first][pos.second] = 'X';
    }
    for(const auto& pos : player_tokens[1]){ // tokens of player 2 (O)
        this->board[pos.first][pos.second] = 'O';
    }
    this->n_moves  = 0;
}
template <typename T>
void FourXFour_Board<T>::display_board() {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i<4; i++) {
        cout << "| ";
        for (int j = 0;j<4; j++) {
            cout << setw(2) << this->board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << endl;
}

template <typename T>
bool FourXFour_Board<T>::update_board(int x, int y, T symbol){
    for (auto&token:player_tokens[symbol=='X'?0:1]) {
    int current_x = token.first;
    int current_y = token.second;
    if ((abs(current_x - x) + abs(current_y - y) == 1) && this->board[x][y] != symbol){
    this->board[current_x][current_y] = '-';
    this->board[x][y]=symbol;
    this->n_moves++;
    return true;}
    else {
        cout<<" Invalid move , Please try again ";
    return false ;}
    }

}

template <typename T>
int FourXFour_Board<T>::count_three(T symbol){
    int count = 0;
    for (int i = 0; i < this->rows; i++) {      //check each three in a row and increment hte counter
        for (int j = 0;j<=this->columns-2; j++) {
            if (this->board[i][j] == symbol && this->board[i][j+1] == symbol && this->board[i][j+2] == symbol) {
                count++;}
        }
    }
    for (int i=0;i<=this->rows-2;i++){     //check each three in a column and increment hte counter
        for(int j=0;j< this->columns;j++){
            if (this->board[i][j]==symbol && this->board[i+1][j]==symbol && this->board[i+2][j]==symbol){
                count++;
            }
        }
    }
    for (int i=0;i<=this->rows-2 ;i++){     //checks each three diagonally (left)
        for(int j=0;j<=this->columns-2 ;j++){
            if (this->board[i][j]==symbol && this->board[i+1][j+1]==symbol && this->board[i+2][j+2]==symbol){
                count++;
            }
        }
    }
    for (int i=0;i<=this->rows-2 ;i++){     //checks each three diagonally (right)
        for(int j=0;j<=this->columns-2 ;j++){
            if (this->board[i][j]==symbol && this->board[i+1][j-1]==symbol && this->board[i+2][j-2]==symbol){
                count++;
            }
        }
    }
    return count;}

template <typename T>  //check the winner
bool FourXFour_Board<T>::is_win() {
        player1_scr=count_three('X');
        player2_scr=count_three('O');
    return (player1_scr >player2_scr)||(player2_scr>player1_scr);
}

template <typename T>
bool FourXFour_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
bool FourXFour_Board<T>::is_draw() {
    return this->n_moves >= 32 && !is_win();
}

//================================================================
//                      PLAYERS IMPLEMENTATION
//================================================================
template <typename T>
FourXFour_Player<T>::FourXFour_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void FourXFour_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 3) separated by spaces: "
    <<endl<<"you can move only one step vertically or horizontally"<<endl;
    cin >> x >> y;

}
//================================================================
//                     RANDOM  PLAYERS IMPLEMENTATION
//================================================================

template <typename T>
FourXFour_Random_Player<T>::FourXFour_Random_Player(T symbol): RandomPlayer<T>(symbol) {
    this->dimension = 4;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void FourXFour_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 4;  // Random number between 0 and 3
    y = rand() % 4;
}


#endif //NEWGAMES_H
