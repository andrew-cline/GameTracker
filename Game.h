#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

class Game
{
        string name;
        int played, beat;
        bool started, restart, finish, inProgress;
        char done;
    public:
        Game();
        void setName();//setters
        void setTimeToBeat();
        void setTimePlayed();
        void setStartedFlag();
        void setRestartFlag();
        void setFinishFlag();
        void setInProgressFlag();
        void setName(string name);
        void setTimeToBeat(int beat);
        void setTimePlayed(int played);
        void setStartedFlag(bool started);
        void setRestartFlag(bool restart);
        void setFinishFlag(bool finish);
        void setInProgressFlag(bool inProgress);
        void setTimeToBeat(string beat);
        void setTimePlayed(string played);
        void setStartedFlag(string started);
        void setRestartFlag(string restart);
        void setFinishFlag(string finish);
        void setInProgressFlag(string inProgress);
        string getName(); //getters
        int getTimeToBeat();
        int getTimePlayed();
        bool getStartedFlag();
        bool getRestartFlag();
        bool getFinishFlag();
        bool getInProgressFlag();
        void formattedWrite();
};
#endif