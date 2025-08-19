#include"Orbito.hh"



int main(){

    vector<string> allPos;
    string line;
    int number_of_Pos = 1441440;
    ifstream game_file("AllPositions8.txt");
    if(game_file.is_open()){
        while(getline(game_file, line)){
            for(int pos = 0; pos < 16; pos++){
                string copy = line;
                if(copy.at(pos) == ' '){
                    copy.at(pos) = 'X';
                    if(!contains(copy, allPos)){
                        allPos.push_back(copy);
                        cout << (100.0 * allPos.size() / number_of_Pos) << "% " << "von AllPositions9.txt berechnet.\n";
                    }
                }
            }
        }
    }
    game_file.close();

    ofstream next_game_file("AllPositions9.txt");
    for(int i = 0; i < allPos.size(); i++){
        next_game_file << allPos.at(i) << endl;
    }
    next_game_file.close();



    // array<char, 16> Feld = {' ', ' ', ' ', ' ',
    //                         ' ', ' ', ' ', ' ',
    //                         ' ', ' ', ' ', ' ',
    //                         ' ', ' ', ' ', ' '};
    
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


    // // test mit Game Objekten
    // // 4 min 36 s

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
