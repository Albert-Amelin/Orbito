#include"Orbito.hh"



int main(){

    array<char, 16> Feld = {' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' '};
    
    //AllPositions8.txt befüllen

    vector<Game> allPos;
    string line;
    int number_of_Pos = 900900;
    ifstream game_file("AllPositions7.txt");
    if(game_file.is_open()){
        while(getline(game_file, line)){
            for(int pos = 0; pos < 16; pos++){
                Game G(line);
                if(G.valid_place_dec(pos)){
                    G.place_dec(pos, 'O');
                    if(!contains(G, allPos)){
                        allPos.push_back(G);
                        cout << (100.0 * allPos.size() / number_of_Pos) << "% " << "von AllPositions8.txt berechnet.\n";
                    } 
                }
            }
        }
    }
    game_file.close();

    ofstream next_game_file("AllPositions8.txt");
    for(int i = 0; i<allPos.size(); i++){
        next_game_file << allPos.at(i);
    }
    next_game_file.close();
    
    
    
    // allPos.clear();

    // //AllPositions9.txt befüllen

    // number_of_Pos = 1441440;
    // ifstream game_file("AllPositions8.txt");
    // if(game_file.is_open()){
    //     while(getline(game_file, line)){
    //         for(int pos = 0; pos < 16; pos++){
    //             Game G(line);
    //             if(G.valid_place_dec(pos)){
    //                 G.place_dec(pos, 'X');
    //                 if(!contains(G, allPos)){
    //                     allPos.push_back(G);
    //                     cout << (100.0 * allPos.size() / number_of_Pos) << "% " << "von AllPositions9.txt berechnet.\n";
    //                 } 
    //             }
    //         }
    //     }
    // }
    // game_file.close();

    // ofstream next_game_file("AllPositions9.txt");
    // for(int i = 0; i<allPos.size(); i++){
    //     next_game_file << allPos.at(i);
    // }
    // next_game_file.close();
    // allPos.clear();

    // //AllPositions10.txt befüllen

    // number_of_Pos = 2018016;
    // ifstream game_file("AllPositions9.txt");
    // if(game_file.is_open()){
    //     while(getline(game_file, line)){
    //         for(int pos = 0; pos < 16; pos++){
    //             Game G(line);
    //             if(G.valid_place_dec(pos)){
    //                 G.place_dec(pos, 'O');
    //                 if(!contains(G, allPos)){
    //                     allPos.push_back(G);
    //                     cout << (100.0 * allPos.size() / number_of_Pos) << "% " << "von AllPositions10.txt berechnet.\n";
    //                 } 
    //             }
    //         }
    //     }
    // }
    // game_file.close();

    // ofstream next_game_file("AllPositions10.txt");
    // for(int i = 0; i<allPos.size(); i++){
    //     next_game_file << allPos.at(i);
    // }
    // next_game_file.close();
    // allPos.clear();

    
    return 0;
}
