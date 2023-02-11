//
// Created by riwaa on 9-2-2023.
//

#include "Game.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
using namespace std;
void Game::displaywords(){
    WPM_counter = 0;
    srand(time(0));
    ifstream read{"words"};
    string word = "";
    while(getline(read,word)){
        words.push_back(word);
        total_lines++;
    }
    cout<<"Hi!, your main goal here is to type as fast as you can ..." << endl;
    cout<<endl;
    cerr<<"NOTE: After typing the first word the one minute timer will go off ! GOODLUCK :)" << endl;
    cout<< endl;
    if (!first){
        getindex = rand() % total_lines;
        displayed_words.push_back(words[getindex]);
        cout<<"Type the following:"<<endl;
        cout<< words[getindex]<<endl;
        cin>> userinput;
        if (userinput == words[getindex]){
            WPM_counter++;
        }
        printf("Your one-minute timer starts now ! GOODLUCK :) \n");
        goto game;
    }
    else{
        game:
        auto start = chrono::high_resolution_clock::now();
        auto end = start + chrono::minutes(1);
        while(chrono::high_resolution_clock::now()<end){
            getindex = rand() % total_lines;
            cout<<"Type the following: " <<endl;
            cout<<"********************"<<endl;
            cout<<   words[getindex] << endl;
            cout<<"********************"<<endl;
            cout<<endl;
            displayed_words.push_back(words[getindex]);
            cin>>userinput;
            if (userinput == words[getindex]){
                WPM_counter++;
                cout << WPM_counter << endl;
            }
        }
        Game::end(WPM_counter,displayed_words);
    }
}

void Game::end(int input_counter, vector<string> input_vector) const {
    printf("*************************************************************\n");
    cout<< "YOUR WPM: " << WPM_counter << endl;
    cout << "ACCURACY: "<< 100.0 * WPM_counter / displayed_words.size() << "%\n";
    printf("*************************************************************\n");
    cout<<endl;
    cout<<endl;
}

void Game::starting()const{
    cout<<"*************************************************************************************************************"<<endl;
    printf(" __ __ __   ______   ___ __ __             _________  ______   ______   _________  ______   ______       \n"
           "/_//_//_/\\ /_____/\\ /__//_//_/\\           /________/\\/_____/\\ /_____/\\ /________/\\/_____/\\ /_____/\\      \n"
           "\\:\\\\:\\\\:\\ \\\\:::_ \\ \\\\::\\| \\| \\ \\   _______\\__.::.__\\/\\::::_\\/_\\::::_\\/_\\__.::.__\\/\\::::_\\/_\\:::_ \\ \\     \n"
           " \\:\\\\:\\\\:\\ \\\\:(_) \\ \\\\:.      \\ \\ /______/\\  \\::\\ \\   \\:\\/___/\\\\:\\/___/\\  \\::\\ \\   \\:\\/___/\\\\:(_) ) )_   \n"
           "  \\:\\\\:\\\\:\\ \\\\: ___\\/ \\:.\\-/\\  \\ \\\\__::::\\/   \\::\\ \\   \\::___\\/_\\_::._\\:\\  \\::\\ \\   \\::___\\/_\\: __ `\\ \\  \n"
           "   \\:\\\\:\\\\:\\ \\\\ \\ \\    \\. \\  \\  \\ \\            \\::\\ \\   \\:\\____/\\ /____\\:\\  \\::\\ \\   \\:\\____/\\\\ \\ `\\ \\ \\ \n"
           "    \\_______\\/ \\_\\/     \\__\\/ \\__\\/             \\__\\/    \\_____\\/ \\_____\\/   \\__\\/    \\_____\\/ \\_\\/ \\_\\/ \n");
    cout<<"*************************************************************************************************************"<<endl;
    cout<< endl;
}






