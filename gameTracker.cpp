#include "Game.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>



using namespace std;

void updateFile()
{
    string search;
    getline(cin, search);
    fstream file;
    file.open("data");
    string line;
    int tracker = 0;
    vector<string> names, lines, gameInfo;
    while(getline(file, line)) // Separates by newline character
    {
        lines.push_back(line);
        stringstream ss(line); //create a string stream object to separate the string by comma so as to store and access the information easily
        while(getline(ss, line, '|')) //Separates by comma and stores first entry, since there are only 7 points of data available , in the names vector
        {
            switch (tracker)
            {
                case 0:
                    tracker++;
                    names.push_back(line);
                    break;
                case 6:
                    tracker = 0;
                    break;
                default:
                    tracker++;
                    break;
            }     
        }
    }
    for(unsigned int i = 0; i< names.size(); i++) //iterates over generated list of names in 'data', checks if search is positive
    {
        if(names[i] == search)//if positive then fills the game object passed in with information about the game
        {
            stringstream ss(lines[i]);
            cout << "Match Found" << endl;
            while(getline(ss, lines[i], '|'))//since the lines were already created, we can use that information and reseparate them by comma and store the info in the game object
            {
                gameInfo.push_back(lines[i]);
            }
            cout << "Please enter the game name: "; getline(cin, gameInfo[0]);
            cout << "Please enter the time to beat: "; cin >> gameInfo[1];
            cout << "Please enter the time played: "; cin >> gameInfo[2];
            cout << "Have you started the game?(1 for yes, 0 for no): "; cin >> gameInfo[3];
            cout << "Should you restart?(1 for yes, 0 for no): "; cin >> gameInfo[4];
            cout << "Have you finished the game yet?(1 for yes, 0 for no): "; cin >> gameInfo[5];
            cout << "Is the game currently in progress? (1 for yes, 0 for no): "; cin >> gameInfo[6];
            lines[i] = gameInfo[0] + "|" + gameInfo[1] + "|" + gameInfo[2] + "|" + gameInfo[3] + "|" + gameInfo[4] + "|" + gameInfo[5] + "|" + gameInfo[6];
            break;
        }
        else if (i == names.size() - 1) //if nothing is found :(
        {
            cout << "No Entry Found" << endl;
        }
    }
    file.close();
    file.open("data", ios::out | ofstream::trunc);
    for(unsigned int i = 0; i < lines.size(); i++)
    {
        file << lines[i] + "\n";
    }
}

bool checkFile(string search, Game& game)
{
    ifstream file;
    file.open("data");
    string line;
    int tracker = 0;
    vector<string> names, lines, gameInfo;
    while(getline(file, line)) // Separates by newline character
    {
        lines.push_back(line);
        stringstream ss(line); //create a string stream object to separate the string by comma so as to store and access the information easily
        while(getline(ss, line, '|')) //Separates by comma and stores first entry, since there are only 7 points of data available , in the names vector
        {
            switch (tracker)
            {
                case 0:
                    tracker++;
                    names.push_back(line);
                    break;
                case 6:
                    tracker = 0;
                    break;
                default:
                    tracker++;
                    break;
            }     
        }
    }
    for(unsigned int i = 0; i< names.size(); i++) //iterates over generated list of names in 'data', checks if search is positive
    {
        if(names[i] == search)//if positive then fills the game object passed in with information about the game
        {
            stringstream ss(lines[i]);
            cout << "Match Found" << endl;
            while(getline(ss, lines[i], '|'))//since the lines were already created, we can use that information and reseparate them by comma and store the info in the game object
            {
                gameInfo.push_back(lines[i]);
            }
            game.setName(gameInfo[0]);
            game.setTimeToBeat(gameInfo[1]);
            game.setTimePlayed(gameInfo[2]);
            game.setStartedFlag(gameInfo[3]);
            game.setRestartFlag(gameInfo[4]);
            game.setFinishFlag(gameInfo[5]);
            game.setInProgressFlag(gameInfo[6]);
            return true;
        }
        else if (i == names.size() - 1) //if nothing is found :(
        {
            cout << "No Entry Found" << endl;
            return false;
        }
    }
    file.close();
    return false;
}
void addGame()
{
    char done;
    do
    {
        Game game; //creates game object, fills in with user input
        cout << "Please enter the game name: "; game.setName();
        cout << "Please enter the time to beat: "; game.setTimeToBeat();
        cout << "Please enter the time played: "; game.setTimePlayed();
        cout << "Have you started the game?(1 for yes, 0 for no): "; game.setStartedFlag();
        cout << "Should you restart?(1 for yes, 0 for no): "; game.setRestartFlag();
        cout << "Have you finished the game yet?(1 for yes, 0 for no): "; game.setFinishFlag();
        cout << "Is the game currently in progress? (1 for yes, 0 for no): "; game.setInProgressFlag();
        game.formattedWrite();
        cout << "Done? (Enter y for yes, n for no): "; cin >> done; cout << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (done != 'y');

}
void searchGame()
{
    string name;
    Game game;
    getline(cin, name);
    if(checkFile(name, game)) //game object filled by checkfile (checkfile fills the game object by search through each line of 'data' and separating out the informat)
    {
        cout << "****************************************" << endl;
        cout << "Name: " << game.getName() << endl;
        cout << "Time to beat: " << game.getTimeToBeat() << endl;
        cout << "Time played: " << game.getTimePlayed() << endl;
        if(game.getStartedFlag()){cout << "Game has been started" << endl;} else {cout << "Game has not been started" << endl;}
        if(game.getRestartFlag()){cout << "Game should be restarted" << endl;} else {cout << "Game should be continued where left off" << endl;}
        if(game.getFinishFlag()){cout << "Game has been finished" << endl;} else {cout << "Game has not been finished" << endl;}
        if(game.getInProgressFlag()){cout << "Game is in progress" << endl;} else {cout << "Game is not in progress" << endl;}
        cout << "****************************************" << endl;
    }
}
int main()
{
    int option;
    do
    {
        cout << "Type 1 to get information about a game, 2 to add, 3 to update information about a game, or 4 to exit: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (option)
            {
            case 1:
                searchGame();
                break;
            case 2:
                addGame();
                break;
            case 3:
                cout << "Please enter name of game to edit: ";
                updateFile();
                break;
            case 4:
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                cin.clear();
                cin.ignore();
                option = 0;
                break;
            } 
    } while (option != 4);
    return 0;
}
