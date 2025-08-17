#include"Orbito.hh"



int main(){

    array<char, 16> Feld = {'O', 'X', 'O', ' ',
                            ' ', 'X', ' ', ' ',
                            ' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' '};

    Game G(Feld);

    return 0;
}
