#include"Orbito.hh"



int main(){


    eval_all_Pos("AllPositions13eval.txt", "AllPositions12.txt", "AllPositions12eval.txt", 'X', 1681680);
    eval_all_Pos("AllPositions12eval.txt", "AllPositions11.txt", "AllPositions11eval.txt", 'O', 2018016);
    eval_all_Pos("AllPositions11eval.txt", "AllPositions10.txt", "AllPositions10eval.txt", 'X', 2018016);
    eval_all_Pos("AllPositions10eval.txt", "AllPositions9.txt", "AllPositions9eval.txt", 'O', 1441440);
    eval_all_Pos("AllPositions9eval.txt", "AllPositions8.txt", "AllPositions8eval.txt", 'X', 900900);
    eval_all_Pos("AllPositions8eval.txt", "AllPositions7.txt", "AllPositions7eval.txt", 'O', 400400);
    eval_all_Pos("AllPositions7eval.txt", "AllPositions6.txt", "AllPositions6eval.txt", 'X', 160160);
    eval_all_Pos("AllPositions6eval.txt", "AllPositions5.txt", "AllPositions5eval.txt", 'O', 43680);
    eval_all_Pos("AllPositions5eval.txt", "AllPositions4.txt", "AllPositions4eval.txt", 'X', 10920);
    eval_all_Pos("AllPositions4eval.txt", "AllPositions3.txt", "AllPositions3eval.txt", 'O', 1680);
    eval_all_Pos("AllPositions3eval.txt", "AllPositions2.txt", "AllPositions2eval.txt", 'X', 240);
    eval_all_Pos("AllPositions2eval.txt", "AllPositions1.txt", "AllPositions1eval.txt", 'O', 16);
    eval_all_Pos("AllPositions1eval.txt", "AllPositions0.txt", "AllPositions0eval.txt", 'X', 1);

    // ifstream game_file("AllPositions16.txt");
    // ofstream eval_file("AllPositions16eval.txt");
    // string game;
    // if(game_file.is_open() && eval_file.is_open()){
    //     while(getline(game_file, game)){
    //         eval_file << game;
    //         if(win(game, 'X') && win(game, 'O')) eval_file << 1 << endl;
    //         else if(win(game, 'X')) eval_file << 2 << endl;
    //         else if(win(game, 'O')) eval_file << 0 << endl;
    //         else{
    //             for(int i = 0; i < 5; i++){
    //                 orbit(game);
    //                 if(win(game, 'X') && win(game, 'O')){
    //                     eval_file << 1 << endl;
    //                     break;
    //                 }else if(win(game, 'X')){
    //                     eval_file << 2 << endl;
    //                     break;
    //                 }else if(win(game, 'O')){
    //                     eval_file << 0 << endl;
    //                     break;
    //                 }else if(i == 4){
    //                     eval_file << 1 << endl;
    //                 }
    //             }
    //         }
    //     }
    // }
    // game_file.close();
    // eval_file.close();


    // vector<string> allPos;
    // string line;
    // unsigned int number_of_Pos = 102960;
    // ifstream game_file("AllPositions15.txt");
    // if(game_file.is_open()){
    //     while(getline(game_file, line)){
    //         for(int pos = 0; pos < 16; pos++){
    //             string copy = line;
    //             if(copy.at(pos) == ' '){
    //                 copy.at(pos) = 'O';
    //                 allPos.push_back(copy);
    //                 cout << (100.0 * allPos.size() / number_of_Pos) << "% " << "der neuen Positionen für AllPositions16.txt berechnet.\n";
    //             }
    //         }
    //     }
    // }
    // game_file.close();

    // cout << "Entferne alle Duplikate.\n";
    // sort( allPos.begin(), allPos.end() );
    // allPos.erase( unique( allPos.begin(), allPos.end() ), allPos.end() );

    // cout << "Schreibe alle Elemente in AllPositions16.txt.\n";
    // ofstream next_game_file("AllPositions16.txt");
    // for(int i = 0; i < allPos.size(); i++){
    //     next_game_file << allPos.at(i) << endl;
    // }
    // next_game_file.close();


    // array<char, 16> Feld = {' ', ' ', ' ', ' ',
    //                         ' ', ' ', ' ', ' ',
    //                         ' ', ' ', ' ', ' ',
    //                         ' ', ' ', ' ', ' '};

    // test mit direkter Bearbeitung des Strings, Entfernung der Duplikate nachträglich
    // 2 s

    // vector<string> allPos;
    // string line;
    // int number_of_Pos = 10920 * 12;
    // ifstream game_file("AllPositions4.txt");
    // if(game_file.is_open()){
    //     while(getline(game_file, line)){
    //         for(int pos = 0; pos < 16; pos++){
    //             string copy = line;
    //             if(copy.at(pos) == ' '){
    //                 copy.at(pos) = 'X';
    //                 allPos.push_back(copy);
    //                 cout << (100.0 * allPos.size() / number_of_Pos) << "% " << "der neuen Positionen für test.txt berechnet.\n";
    //             }
    //         }
    //     }
    // }
    // game_file.close();

    // cout << "Entferne alle Duplikate.\n";
    // sort( allPos.begin(), allPos.end() );
    // allPos.erase( unique( allPos.begin(), allPos.end() ), allPos.end() );

    // cout << "Schreibe alle Elemente in test.txt.\n";
    // ofstream next_game_file("test.txt");
    // for(int i = 0; i < allPos.size(); i++){
    //     next_game_file << allPos.at(i) << endl;
    // }
    // next_game_file.close();


    
    // test mit Direkter Bearbeitung des Strings
    // 3 min, 37 s

    // vector<string> allPos;
    // string line;
    // int number_of_Pos = 43680;
    // ifstream game_file("AllPositions4.txt");
    // if(game_file.is_open()){
    //     while(getline(game_file, line)){
    //         for(int pos = 0; pos < 16; pos++){
    //             string copy = line;
    //             if(copy.at(pos) == ' '){
    //                 copy.at(pos) = 'X';
    //                 if(!contains(copy, allPos)){
    //                     allPos.push_back(copy);
    //                     cout << (100.0 * allPos.size() / number_of_Pos) << "% " << "von test.txt berechnet.\n";
    //                 }
    //             }
    //         }
    //     }
    // }
    // game_file.close();

    // ofstream next_game_file("test.txt");
    // for(int i = 0; i < allPos.size(); i++){
    //     next_game_file << allPos.at(i) << endl;
    // }
    // next_game_file.close();


    // test mit Game Objekten
    // 4 min 36 s

    // vector<Game> allPos;
    // string line;
    // int number_of_Pos = 43680;
    // ifstream game_file("AllPositions4.txt");
    // if(game_file.is_open()){
    //     while(getline(game_file, line)){
    //         for(int pos = 0; pos < 16; pos++){
    //             Game G(line);
    //             if(G.valid_place_dec(pos)){
    //                 G.place_dec(pos, 'X');
    //                 if(!contains(G, allPos)){
    //                     allPos.push_back(G);
    //                     cout << (100.0 * allPos.size() / number_of_Pos) << "% " << "von test.txt berechnet.\n";
    //                 } 
    //             }
    //         }
    //     }
    // }
    // game_file.close();

    // ofstream next_game_file("test.txt");
    // for(int i = 0; i<allPos.size(); i++){
    //     next_game_file << allPos.at(i);
    // }
    // next_game_file.close();

    
    return 0;
}
