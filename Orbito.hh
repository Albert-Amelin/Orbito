#include<iostream>
#include<cmath>
#include<array>
#include<vector>
#include<fstream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class Move{
private:
    double M_win_chance;
    int M_from;
    int M_to;
    int M_pos;

public:
    Move(double win_chance, int from, int to, int pos);
    Move(Move const& m);
    ~Move();

    void set(double win_chance, int from, int to, int pos);
    double get_win_chance() const;
    int get_from() const;
    int get_to() const;
    int get_pos() const;
};

class Game{
private:
    array<char,16> M_Feld;

public:
    Game(array<char,16> Feld);
    Game(string const& s);
    Game(Game const& G);
    ~Game();

    void print() const;
    bool win(char Player) const;
    void orbit();
    void turn_90_deg();
    string to_string() const;

    bool valid_move_dec(int from, int to, char Player) const;
    bool valid_move_quad(int from, int to, char Player) const;
    void move_dec(int from, int to, char Player);
    void move_quad(int from, int to, char Player);

    bool valid_place_dec(int pos) const;
    bool valid_place_quad(int pos) const;
    void place_dec(int pos, char Player);
    void place_quad(int pos, char Player);


    void player_turn_first(char Player);
    void player_turn(char Player);

    void Bot1_turn_first(char Player);
    // Output: Kann gewinnen (0 = nein, 1 = ja), from, to, pos
    array<int,4> can_win(char Player) const;
    void Bot1_turn(char Player);
    bool full_Board();
    void Player_vs_Bot1();

    Move calc_move(char Player, int depth);
    void Bot2_turn_first(char Player);
    void Bot2_turn(char Player, int depth, bool display_turn);
    void Player_vs_Bot2();

    // Die ersten beiden Züge müssen im Vorfeld gemacht worden sein.
    // Output: {1,0,0}, falls Bot1 gewonnen hat,
    //         {0,1,0}, falls unentschieden,
    //         {0,0,1}, falls Bot2 gewonnen hat.
    array<int,3> Bot_Match(int depth_Bot1, int depth_Bot2, bool display_game);

    friend bool const operator==(Game const& G1, Game const& G2);
    friend bool const same(Game const& G1, Game const& G2);
    friend ostream& operator<<(ostream& ostr, Game const& G);
    friend bool const contains(Game const& G, vector<Game> v);

    int pieces() const;
    void perfect_Bot_turn(char Player);
    void Player_vs_perfect_Bot();
    int display_eval() const;
    void move_back(string last_pos);
};

int quad_to_dec(int n);
int dec_to_quad(int n);
int dist_quad(int a, int b);
int dist_dec(int a, int b);
int transform(int n);
bool contains(string s, vector<string> v);

// Funktionen aus Game Klasse aber nur mit string

bool win(string const& game, char Player);
void orbit(string& game);

bool valid_move_dec(string const& game, int from, int to, char Player);
bool valid_move_quad(string const& game, int from, int to, char Player);
void move_dec(string& game, int from, int to, char Player);
void move_quad(string& game, int from, int to, char Player);

bool valid_place_dec(string const& game, int pos);
bool valid_place_quad(string const& game, int pos);
void place_dec(string& game, int pos, char Player);
void place_quad(string& game, int pos, char Player);

bool same_game(string const& game, string const& eval_game);
void sort_Pos(string const& file);
string find_game_eval(string const& eval_file, string game);
string find_game_eval(vector<string> const& allPos, string const& game);

void eval_all_Pos(string last_eval, string now, string now_eval, char Player, int positions, int pieces);


