//
// Created by riwaa on 9-2-2023.
//
#ifndef TYPINGSPEEDTESTER_GAME_H
#define TYPINGSPEEDTESTER_GAME_H
#include <string>
#include <vector>
using namespace std;

class Game {
private:
    int getindex,total_lines,WPM_counter;
    vector<string>words;
    vector<string>displayed_words;
    string userinput;
    bool first = false;
public:
    void displaywords();
    void end(int input_counter,vector<string>input_vector)const;
    void starting()const;
};


#endif //TYPINGSPEEDTESTER_GAME_H
