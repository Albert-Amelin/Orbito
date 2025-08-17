#include"Orbito.hh"



int main(int argc, char* argv[]){

   array<char, 16> Feld = {' ', ' ', ' ', ' ',
                           ' ', ' ', ' ', ' ',
                           ' ', ' ', ' ', ' ',
                           ' ', ' ', ' ', ' '};

    Game G(Feld);

    int Zehner_O = argv[1][0] - '0';
    int Einer_O = argv[1][1] - '0';
    int Zehner_X = argv[2][0] - '0';
    int Einer_X = argv[2][1] - '0';

    int x = Zehner_X*10 + Einer_X;
    int o = Zehner_O*10 + Einer_O;

    G.place_quad(o, 'O');
    G.place_quad(x, 'X');

    array<int,3> this_Match = G.Bot_Match(3,3,true);


    return 0;
}
