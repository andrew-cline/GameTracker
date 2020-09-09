#include "Game.h"



Game::Game()
{
    
}
void Game::setName(){getline(cin, name);} //setters
void Game::setTimeToBeat(){ cin >> beat;}
void Game::setTimePlayed(){ cin >> played;}
void Game::setStartedFlag(){ cin >> started;}
void Game::setRestartFlag(){ cin >> restart;}
void Game::setFinishFlag(){ cin >> finish;}
void Game::setInProgressFlag(){ cin >> inProgress;}
void Game::setName(string name){this->name = name;}
void Game::setTimeToBeat(int beat){this->beat = beat;}
void Game::setTimePlayed(int played){this->played = played;}
void Game::setStartedFlag(bool started){this->started = started;}
void Game::setRestartFlag(bool restart){this->name = restart;}
void Game::setFinishFlag(bool finish){this->finish = finish;}
void Game::setInProgressFlag(bool inProgress){this->inProgress = inProgress;}
void Game::setTimeToBeat(string beat){stringstream ss(beat); ss >> this->beat;}
void Game::setTimePlayed(string played){stringstream ss(played); ss >> this->played;}
void Game::setStartedFlag(string started){stringstream ss(started); ss >> this->started;}
void Game::setRestartFlag(string restart){stringstream ss(restart); ss >> this->restart;}
void Game::setFinishFlag(string finish){stringstream ss(finish); ss >> this->finish;}
void Game::setInProgressFlag(string inProgress){stringstream ss(inProgress); ss >> this->inProgress;}
string Game::getName(){return name;}
int Game::getTimeToBeat(){return beat;}
int Game::getTimePlayed(){return played;}
bool Game::getStartedFlag(){return started;}
bool Game::getRestartFlag(){return restart;}
bool Game::getFinishFlag(){return finish;}
bool Game::getInProgressFlag(){return inProgress;}
void Game::formattedWrite(){fstream file; file.open("data", ios::out | ios::app); file << name << "|"<< beat << "|" << played << "|" <<started << "|"<< restart << "|"<< finish << "|"<< inProgress <<"\n"; file.close(); }