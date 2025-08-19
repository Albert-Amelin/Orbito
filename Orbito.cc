#include"Orbito.hh"
using namespace std;

int quad_to_dec(int n){
    return ((n - (n % 10)) / 10)*4 + (n % 10);
}

int dec_to_quad(int n){
    return (n % 4) + 10*(n/4);
}

int dist_quad(int a, int b){
    return abs(((a - (a % 10)) / 10) - ((b - (b % 10)) / 10)) + abs((a % 10) - (b % 10));
}

int dist_dec(int a, int b){
    return dist_quad(dec_to_quad(a), dec_to_quad(b));
}

int transform(int n){
    if(n == 0) return 5;
    if(n == 1) return 10;
    if(n == 2) return 6;
    if(n == 3) return 9;
    if(n == 4) return 1;
    if(n == 5) return 14;
    if(n == 6) return 2;
    if(n == 7) return 13;
    if(n == 8) return 8;
    if(n == 9) return 7;
    if(n == 10) return 4;
    if(n == 11) return 11;
    if(n == 12) return 3;
    if(n == 13) return 12;
    if(n == 14) return 0;
    if(n == 15) return 15;
    return -1;
}

bool contains(string s, vector<string> v){
    for(int i = 0; i < v.size(); i++){
        if(s == v.at(i)) return true;
    }
    return false;
}

Move::Move(double win_chance = 0, int from = 0, int to = 0, int pos = 0){
    M_win_chance = win_chance;
    M_from = from;
    M_to = to;
    M_pos = pos;
}

Move::Move(Move const& m){
    M_win_chance = m.M_win_chance;
    M_from = m.M_from;
    M_to = m.M_to;
    M_pos = m.M_pos;
}

Move::~Move(){}

void Move::set(double win_chance, int from, int to, int pos){
    M_win_chance = win_chance;
    M_from = from;
    M_to = to;
    M_pos = pos;
}

double Move::get_win_chance() const{
    return M_win_chance;
}

int Move::get_from() const{
    return M_from;
}

int Move::get_to() const{
    return M_to;
}

int Move::get_pos() const{
    return M_pos;
}

Game::Game(array<char,16> Feld){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(Feld.at(4*i+j) == ' ' || Feld.at(4*i+j) == 'X' || Feld.at(4*i+j) == 'O'){
                M_Feld.at(4*i+j) = Feld.at(4*i+j);
            }else{
                cout << "Feld konnte nicht initialisiert werden. Benutze bitte nur ' ', 'X' oder 'O'.\nEs wurde im Feld (" << i << "," << j << ") ' ' gesetzt.\n";
                M_Feld.at(4*i+j) = ' ';
            }

        }
    }
}


Game::Game(string s){
    for(int i = 0; i < 16; i++){
        M_Feld.at(i) = s.at(i);
    }
}

Game::Game(Game const& G){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            M_Feld.at(4*i+j) = G.M_Feld.at(4*i+j);
        }
    }
}

Game::~Game(){}

void Game::print() const{
    cout << "  0  1  2  3 \n";
    for(int i = 0; i<4; i++){
        cout << i;
        for(int j = 0; j<4; j++){
            cout << "[" << M_Feld.at(4*i+j) << "]";
        }
        cout << "\n";
    }
    cout << endl;
}


bool Game::win(char Player) const{
    for(int i = 0; i<4; i++){
        if(M_Feld.at(4*i+0) == Player &&
           M_Feld.at(4*i+1) == Player &&
           M_Feld.at(4*i+2) == Player &&
           M_Feld.at(4*i+3) == Player) return true;
    }
    for(int i = 0; i<4; i++){
        if(M_Feld.at(0+i) == Player &&
           M_Feld.at(4+i) == Player &&
           M_Feld.at(8+i) == Player &&
           M_Feld.at(12+i) == Player) return true;
    }
    if(M_Feld.at(0) == Player &&
       M_Feld.at(5) == Player &&
       M_Feld.at(10) == Player &&
       M_Feld.at(15) == Player) return true;
    if(M_Feld.at(3) == Player &&
       M_Feld.at(6) == Player &&
       M_Feld.at(9) == Player &&
       M_Feld.at(12) == Player) return true;
    return false;
}


void Game::orbit(){
    char temp = M_Feld.at(0);
    for(int i = 0; i<3; i++){
        M_Feld.at(i) = M_Feld.at(i+1);
    }
    for(int i = 3; i<15; i += 4){
        M_Feld.at(i) = M_Feld.at(i+4);
    }
    for(int i = 15; i>12; i--){
        M_Feld.at(i) = M_Feld.at(i-1);
    }
    for(int i = 12; i>4; i -= 4){
        M_Feld.at(i) = M_Feld.at(i-4);
    }
    M_Feld.at(4) = temp;
    temp = M_Feld.at(5);
    M_Feld.at(5) = M_Feld.at(6);
    M_Feld.at(6) = M_Feld.at(10);
    M_Feld.at(10) = M_Feld.at(9);
    M_Feld.at(9) = temp;
}

void Game::turn_90_deg(){
    char temp = M_Feld.at(0);
    //Ecken
    M_Feld.at(0) = M_Feld.at(3);
    M_Feld.at(3) = M_Feld.at(15);
    M_Feld.at(15) = M_Feld.at(12);
    M_Feld.at(12) = temp;
    //Seiten
    temp = M_Feld.at(1);
    M_Feld.at(1) = M_Feld.at(7);
    M_Feld.at(7) = M_Feld.at(14);
    M_Feld.at(14) = M_Feld.at(8);
    M_Feld.at(8) = temp;
    temp = M_Feld.at(2);
    M_Feld.at(2) = M_Feld.at(11);
    M_Feld.at(11) = M_Feld.at(13);
    M_Feld.at(13) = M_Feld.at(4);
    M_Feld.at(4) = temp;
    //Mitte
    temp = M_Feld.at(5);
    M_Feld.at(5) = M_Feld.at(6);
    M_Feld.at(6) = M_Feld.at(10);
    M_Feld.at(10) = M_Feld.at(9);
    M_Feld.at(9) = temp;
}

bool Game::valid_move_dec(int from, int to, char Player) const{
    if(from == to && M_Feld.at(from) == Player) return true;
    if(dist_dec(from, to) > 1 ||
       M_Feld.at(from) != Player ||
       M_Feld.at(to) != ' ' ||
       from < 0 || from > 15 ||
       to < 0 || to > 15) return false;
    return true;
}

bool Game::valid_move_quad(int from, int to, char Player) const{
    return this->valid_move_dec(quad_to_dec(from), quad_to_dec(to), Player);
}

void Game::move_dec(int from, int to, char Player){
    if(valid_move_dec(from, to, Player)){
       M_Feld.at(from) = ' ';
       M_Feld.at(to) = Player;
    }else{
        cout << "Dieser Zug ist nicht legal!" << endl;
    }
}

void Game::move_quad(int from, int to, char Player){
    this->move_dec(quad_to_dec(from), quad_to_dec(to), Player);
}

bool Game::valid_place_dec(int pos) const{
    if(M_Feld.at(pos) != ' ' || pos < 0 || pos > 15) return false;
    return true;
}

bool Game::valid_place_quad(int pos) const{
    return this->valid_place_dec(quad_to_dec(pos));
}

void Game::place_dec(int pos, char Player){
    if(valid_place_dec(pos)){
        M_Feld.at(pos) = Player;
    }else{
        cout << "Dieser Zug ist nicht legal!" << endl;
    }
}

void Game::place_quad(int pos, char Player){
    this->place_dec(quad_to_dec(pos), Player);
}

void Game::player_turn_first(char Player){
    cout << "Spieler " << Player << ":\nWohin möchtest du deinen Stein setzen?\n";
    int pos;
    cin >> pos;
    while(!this->valid_place_quad(pos)){
        cout << "Dieser Zug ist nicht legal! Versuche es nochmal.\n";
        cin >> pos;
    }
    this->place_quad(pos, Player);
    this->print();
    cout << "Gebe 0 ein, um fortzufahren.\n";
    int o;
    cin >> o;
    while(o != 0){
        cout << "Falsche Eingabe! Versuche es nochmal.\n";
        cin >> o;
    }
    this->orbit();
    this->print();
}

void Game::player_turn(char Player){
    cout << "Spieler " << Player << ":\nWelchen Stein des Gegners möchtest du bewegen?\n";
    int from;
    int to;
    char enemy;
    if(Player == 'O') enemy = 'X';
    if(Player == 'X') enemy = 'O';
    cin >> from;
    cout << "Wohin soll der Stein bewegt werden?\n";
    cin >> to;
    while(!this->valid_move_quad(from, to, enemy)){
        cout << "Dieser Zug ist nicht legal! Versuche es nochmal.\nWelchen Stein des Gegners möchtest du bewegen?\n";
        cin >> from;
        cout << "Wohin soll der Stein bewegt werden?\n";
        cin >> to;
    }
    this->move_quad(from, to, enemy);
    this->print();
    cout << "Wohin möchtest du deinen Stein setzen?\n";
    int pos;
    cin >> pos;
    while(!this->valid_place_quad(pos)){
        cout << "Dieser Zug ist nicht legal! Versuche es nochmal.\n";
        cin >> pos;
    }
    this->place_quad(pos, Player);
    this->print();
    cout << "Gebe 0 ein, um fortzufahren.\n";
    int o;
    cin >> o;
    while(o != 0){
        cout << "Falsche Eingabe! Versuche es nochmal.\n";
        cin >> o;
    }
    this->orbit();
    this->print();
}

void Game::Bot1_turn_first(char Player){
    cout << "Zug von Bot " << Player <<":\n";
    for(int i = 0; i<16; i++){
        if(this->valid_place_dec(transform(i))){
            cout << dec_to_quad(transform(i)) << endl;
            this->place_dec(transform(i), Player);
            this->print();
            cout << 0 << endl;
            this->orbit();
            this->print();
            break;
        }
    }
}


array<int,4> Game::can_win(char Player) const{
    char enemy;
    if(Player == 'O') enemy = 'X';
    if(Player == 'X') enemy = 'O';
    for(int from = 0; from<16; from++){
        for(int to = 0; to<16; to++){
            if(this->valid_move_dec(from, to, enemy)){
                Game copy(*this);
                copy.move_dec(from, to, enemy);
                for(int pos = 0; pos<16; pos++){
                    if(copy.valid_place_dec(pos)){
                        Game copy2(copy);
                        copy2.place_dec(pos, Player);
                        copy2.orbit();
                        if(copy2.win(Player) && !copy2.win(enemy)){
                            return {1, from, to, pos};
                        }
                    }
                }
            }
        }
    }
    for(int from = 0; from<16; from++){
        for(int to = 0; to<16; to++){
            if(this->valid_move_dec(from, to, enemy)){
                Game copy(*this);
                copy.move_dec(from, to, enemy);
                for(int pos = 0; pos<16; pos++){
                    if(copy.valid_place_dec(pos)){
                        return {0, from, to, pos};
                    }
                }
            }
        }
    }
    return {0, 0, 0, 0};
}

void Game::Bot1_turn(char Player){
    array<int,4> win_strat = this->can_win(Player);
    char enemy;
    if(Player == 'O') enemy = 'X';
    if(Player == 'X') enemy = 'O';
    cout << "Zug von Bot " << Player << ":\n";
    if(win_strat.at(0) == 1){
        cout << dec_to_quad(win_strat.at(1)) << " -- " << dec_to_quad(win_strat.at(2)) << endl;
        this->move_dec(win_strat.at(1), win_strat.at(2), enemy);
        this->print();
        cout << dec_to_quad(win_strat.at(3)) << endl;
        this->place_dec(win_strat.at(3), Player);
        this->print();
        cout << 0 << endl;
        this->orbit();
        this->print();
        return;
    }else{
        for(int from = 0; from<16; from++){
            for(int to = 0; to<16; to++){
                if(this->valid_move_dec(transform(from), to, enemy)){
                    Game copy(*this);
                    copy.move_dec(transform(from), to, enemy);
                    for(int pos = 0; pos<16; pos++){
                        if(copy.valid_place_dec(transform(pos))){
                            Game copy2(copy);
                            copy2.place_dec(transform(pos), Player);
                            copy2.orbit();
                            array<int,4> enemy_win_strat = copy2.can_win(enemy);
                            if(enemy_win_strat.at(0) == 0){
                                cout << dec_to_quad(transform(from)) << " -- " << dec_to_quad(to) << endl;
                                this->move_dec(transform(from), to, enemy);
                                this->print();
                                cout << dec_to_quad(transform(pos)) << endl;
                                this->place_dec(transform(pos), Player);
                                this->print();
                                cout << 0 << endl;
                                this->orbit();
                                this->print();
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int from = 0; from<16; from++){
        for(int to = 0; to<16; to++){
            if(this->valid_move_dec(transform(from), to, enemy)){
                cout << dec_to_quad(transform(from)) << " -- " << dec_to_quad(to) << endl;
                this->move_dec(transform(from), to, enemy);
                this->print();
                for(int pos = 0; pos<16; pos++){
                    if(this->valid_place_dec(transform(pos))){
                        cout << dec_to_quad(transform(pos)) << endl;
                        this->place_dec(transform(pos), Player);
                        this->print();
                        cout << 0 << endl;
                        this->orbit();
                        this->print();
                        return;
                    }
                }
            }
        }
    }
}

bool Game::full_Board(){
    for(int i = 0; i<16; i++){
        if(M_Feld.at(i) == ' ') return false;
    }
    return true;
}

void Game::Player_vs_Bot1(){
    char Player = 'O';
    char Bot = 'X';
    this->print();
    this->player_turn_first(Player);
    this->Bot1_turn_first(Bot);
    while(!this->full_Board()){
        this->player_turn(Player);
        if(this->win(Player) && !this->win(Bot)){
            cout << "Der Spieler hat gewonnen!\n";
            return;
        }else if(this->win(Bot) && !this->win(Player)){
            cout << "Der Bot hat gewonnen!\n";
            return;
        }else if(this->win(Player) && this->win(Bot)){
            cout << "Unentschieden!\n";
            return;
        }
        this->Bot1_turn(Bot);
        if(this->win(Player) && !this->win(Bot)){
            cout << "Der Spieler hat gewonnen!\n";
            return;
        }else if(this->win(Bot) && !this->win(Player)){
            cout << "Der Bot hat gewonnen!\n";
            return;
        }else if(this->win(Player) && this->win(Bot)){
            cout << "Unentschieden!\n";
            return;
        }
    }
    cout << "Das Spielfeld ist voll. Es wird noch 5 Mal gedreht und geschaut, ob sich noch was ergibt.\n";
    for(int i = 0; i<5; i++){
        cout << i + 1 << endl;
        this->orbit();
        this->print();
        if(this->win(Player) && !this->win(Bot)){
            cout << "Der Spieler hat gewonnen!\n";
            return;
        }else if(this->win(Bot) && !this->win(Player)){
            cout << "Der Bot hat gewonnen!\n";
            return;
        }else if(this->win(Player) && this->win(Bot)){
            cout << "Unentschieden!\n";
            return;
        }
    }
}

Move Game::calc_move(char Player, int depth){

    Move best_move;
    char enemy;
    if(Player == 'O') enemy = 'X';
    if(Player == 'X') enemy = 'O';
    array<int,4> win_strat = this->can_win(Player);
    if(win_strat.at(0) == 1){
        //gewinne
        best_move.set(1.0, win_strat.at(1), win_strat.at(2), win_strat.at(3));
        return best_move;
    }else{
        //Alle möglichen Züge
        bool has_init = false;
        for(int from = 0; from<16; from++){
            for(int to = 0; to<16; to++){
                if(this->valid_move_dec(from, to, enemy)){
                    Game copy(*this);
                    copy.move_dec(from, to, enemy);
                    for(int pos = 0; pos<16; pos++){
                        if(copy.valid_place_dec(pos)){
                            Game copy2(copy);
                            copy2.place_dec(pos, Player);
                            copy2.orbit();

                            if(!has_init){
                                has_init = true;
                                best_move.set(0, from, to, pos);
                            }
                            //Kann Gegner gewinnen?
                            array<int,4> enemy_strat = copy2.can_win(enemy);
                            if(enemy_strat.at(0) == 0 && !copy2.win(enemy) && depth == 1){
                                return best_move;
                            }else if(enemy_strat.at(0) == 0 && !copy2.win(enemy) && depth > 1){
                                int possible_moves = 0;
                                double sum_win_chances = 0;
                                //Alle möglichen Züge des Gegners:
                                for(int from_e = 0; from_e<16; from_e++){
                                    for(int to_e = 0; to_e<16; to_e++){
                                        if(copy2.valid_move_dec(from_e, to_e, Player)){
                                            Game copy3(copy2);
                                            copy3.move_dec(from_e, to_e, Player);
                                            for(int pos_e = 0; pos_e<16; pos_e++){
                                                if(copy3.valid_place_dec(pos_e)){
                                                    Game copy4(copy3);
                                                    copy4.place_dec(pos_e, enemy);
                                                    copy4.orbit();
                                                    possible_moves++;
                                                    Move current_best_move = copy4.calc_move(Player, depth-1);
                                                    sum_win_chances += current_best_move.get_win_chance();
                                                }
                                            }
                                        }
                                    }
                                }
                                double new_win_chance = sum_win_chances / possible_moves;
                                if(new_win_chance > best_move.get_win_chance()){
                                    best_move.set(new_win_chance, from, to, pos);
                                    // Besser?
                                    if(new_win_chance == 1)  return best_move;
                                    // if(depth == 3){
                                    //     cout << "In Tiefe 1 Zug mit win_chance " << new_win_chance << " gefunden.\n";
                                    // }
                                }
                            }
                        }
                    }
                }
            }
        }
        return best_move;
    }
}


void Game::Bot2_turn_first(char Player){
    cout << "Zug von Bot " << Player << ":\n";
    if(this->valid_place_quad(11)){
        cout << 11 << endl;
        this->place_quad(11, Player);
    }else{
        cout << 12 << endl;
        this->place_quad(12, Player);
    }
    this->print();
    cout << 0 << endl;
    this->orbit();
    this->print();
}

void Game::Bot2_turn(char Player, int depth, bool display_turn){
    char enemy;
    if(Player == 'O') enemy = 'X';
    if(Player == 'X') enemy = 'O';
    Move bot_move = this->calc_move(Player, depth);
    if(display_turn) cout << "Zug von Bot " << Player << " (Tiefe " << depth << "):\n" << dec_to_quad(bot_move.get_from()) << " -- " << dec_to_quad(bot_move.get_to()) << endl;
    this->move_dec(bot_move.get_from(), bot_move.get_to(), enemy);
    if(display_turn) this->print();
    if(display_turn) cout << dec_to_quad(bot_move.get_pos()) << endl;
    this->place_dec(bot_move.get_pos(), Player);
    if(display_turn) this->print();
    if(display_turn) cout << 0 << endl;
    this->orbit();
    if(display_turn) this->print();

}

void Game::Player_vs_Bot2(){
    int depth;
    cout << "Hinweise: Die Eingabe der Züge muss die Form \"XY\" haben, wobei X die Zeilenkoordinate ist, und Y die Spaltenkoordinate.\nX kann weg gelassen werden, falls es 0 ist. Alle Eingaben müssen Integer sein.\nFalls ein Stein des Gegners nicht bewegt werden soll, kann man ihn wieder auf seine ursprüngliche Position verschieben.\n\nWas soll die Schwierigkeitsstufe des Bots sein?\n1 - leicht\n2 - mittel\n3 - schwer (Achtung: Die Wartezeit für einen Zug kann etwa eine Stunde dauern.)\n>= 4 - extrem (Die Wartezeiten wären exorbitant groß.)\n";
    cin >> depth;
    while(depth < 1){
        cout << "Falsche Eingabe! Versuche es nochmal.\n";
        cin >> depth;
    }

    char Player = 'O';
    char Bot = 'X';
    this->print();
    this->player_turn_first(Player);
    this->Bot2_turn_first(Bot);
    while(!this->full_Board()){
        this->player_turn(Player);
        if(this->win(Player) && !this->win(Bot)){
            cout << "Der Spieler hat gewonnen!\n";
            return;
        }else if(this->win(Bot) && !this->win(Player)){
            cout << "Der Bot hat gewonnen!\n";
            return;
        }else if(this->win(Player) && this->win(Bot)){
            cout << "Unentschieden!\n";
            return;
        }
        this->Bot2_turn(Bot, depth, true);
        if(this->win(Player) && !this->win(Bot)){
            cout << "Der Spieler hat gewonnen!\n";
            return;
        }else if(this->win(Bot) && !this->win(Player)){
            cout << "Der Bot hat gewonnen!\n";
            return;
        }else if(this->win(Player) && this->win(Bot)){
            cout << "Unentschieden!\n";
            return;
        }
    }
    cout << "Das Spielfeld ist voll. Es wird noch 5 Mal gedreht und geschaut, ob sich noch was ergibt.\n";
    for(int i = 0; i<5; i++){
        cout << i + 1 << endl;
        this->orbit();
        this->print();
        if(this->win(Player) && !this->win(Bot)){
            cout << "Der Spieler hat gewonnen!\n";
            return;
        }else if(this->win(Bot) && !this->win(Player)){
            cout << "Der Bot hat gewonnen!\n";
            return;
        }else if(this->win(Player) && this->win(Bot)){
            cout << "Unentschieden!\n";
            return;
        }
    }
    cout << "Unentschieden!\n";
}

array<int,3> Game::Bot_Match(int depth_Bot1, int depth_Bot2, bool display_game){
    array<int,3> res = {0,0,0};
    char Bot1 = 'O';
    char Bot2 = 'X';
    if(display_game) this->print();
    while(!this->full_Board()){
        this->Bot2_turn(Bot1, depth_Bot1, display_game);
        if(this->win(Bot1) && !this->win(Bot2)){
            if(display_game) cout << "Bot " << Bot1 << " (Tiefe " << depth_Bot1 << ") hat gewonnen!\n";
            res.at(0) = 1;
            return res;
        }else if(this->win(Bot2) && !this->win(Bot1)){
            if(display_game) cout << "Bot " << Bot2 << " (Tiefe " << depth_Bot2 << ") hat gewonnen!\n";
            res.at(2) = 1;
            return res;
        }else if(this->win(Bot1) && this->win(Bot2)){
            if(display_game) cout << "Unentschieden! (Bot " << Bot1 << ": Tiefe " << depth_Bot1 << ", Bot " << Bot1 << ": Tiefe " << depth_Bot2 << ")\n";
            res.at(1) = 1;
            return res;
        }
        this->Bot2_turn(Bot2, depth_Bot2, display_game);
        if(this->win(Bot1) && !this->win(Bot2)){
            if(display_game) cout << "Bot " << Bot1 << " (Tiefe " << depth_Bot1 << ") hat gewonnen!\n";
            res.at(0) = 1;
            return res;
        }else if(this->win(Bot2) && !this->win(Bot1)){
            if(display_game) cout << "Bot " << Bot2 << " (Tiefe " << depth_Bot2 << ") hat gewonnen!\n";
            res.at(2) = 1;
            return res;
        }else if(this->win(Bot1) && this->win(Bot2)){
            if(display_game) cout << "Unentschieden! (Bot " << Bot1 << ": Tiefe " << depth_Bot1 << ", Bot " << Bot1 << ": Tiefe " << depth_Bot2 << ")\n";
            res.at(1) = 1;
            return res;
        }
    }
    if(display_game) cout << "Das Spielfeld ist voll. Es wird noch 5 Mal gedreht und geschaut, ob sich noch was ergibt.\n";
    for(int i = 0; i<5; i++){
        if(display_game) cout << i + 1 << endl;
        this->orbit();
        if(display_game) this->print();
        if(this->win(Bot1) && !this->win(Bot2)){
            if(display_game) cout << "Bot " << Bot1 << " (Tiefe " << depth_Bot1 << ") hat gewonnen!\n";
            res.at(0) = 1;
            return res;
        }else if(this->win(Bot2) && !this->win(Bot1)){
            if(display_game) cout << "Bot " << Bot2 << " (Tiefe " << depth_Bot2 << ") hat gewonnen!\n";
            res.at(2) = 1;
            return res;
        }else if(this->win(Bot1) && this->win(Bot2)){
            if(display_game) cout << "Unentschieden! (Bot " << Bot1 << ": Tiefe " << depth_Bot1 << ", Bot " << Bot1 << ": Tiefe " << depth_Bot2 << ")\n";
            res.at(1) = 1;
            return res;
        }
    }
    if(display_game) cout << "Unentschieden! (Bot " << Bot1 << ": Tiefe " << depth_Bot1 << ", Bot " << Bot1 << ": Tiefe " << depth_Bot2 << ")\n";
    res.at(1) = 1;
    return res;
}

bool const operator==(Game const& G1, Game const& G2){
    for(int i = 0; i<16; i++){
        if(G1.M_Feld.at(i) != G2.M_Feld.at(i)) return false;
    }
    return true;
}

bool const same(Game const& G1, Game const& G2){
    if(G1 == G2) return true;
    Game G2_copy(G2);
    for(int i = 0; i<3; i++){
        G2_copy.turn_90_deg();
        if(G1 == G2_copy) return true;
    }
    return false;
}

ostream& operator<<(ostream& ostr, Game const& G){
    for(int i = 0; i<16; i++){
        ostr << G.M_Feld.at(i);
    }
    ostr << "\n";
    return ostr;
}

bool const contains(Game const& G, vector<Game> v){
    for(int i = 0; i < v.size(); i++){
        if(G == v.at(i)) return true;
    }
    return false;
}
