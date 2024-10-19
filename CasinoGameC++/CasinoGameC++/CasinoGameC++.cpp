#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include "Player.h"
int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

int main() {
    
    int numPlayers;
    std::cout << "Select game mode : education(0) or normal(1): ";
    int gameMode;
    std::cin >> gameMode;
    
    switch(gameMode)
    {
    case 0:
        std::cout << "u choose education mode" << std::endl;
        break;
    case 1:
        std::cout << "u choose normal mode" << std::endl;
        break;
    default:
        std::cout << "u choose uncurrent number, will be used normal mode" << std::endl;
        break;
    }
    std::cout << "Enter players number: ";
    std::cin >> numPlayers;

    std::vector<Player> players;
    std::string playerName;

    std::cout << "Enter player nickname:" << std::endl;
    for (int i = 0; i < numPlayers; ++i) {
        std::cin >> playerName;
        players.push_back(Player(playerName));
    }
    std::cout << "-----------------------------" << std::endl;
    int roundCount = 0;
    
    
    
    
    
    
    
    while (true) {
        int XNumber = generateRandomNumber(1, 100);
        std::cout << "Raund " << roundCount + 1 << std::endl;
        if (gameMode == 0) {
            std::cout << "X number : " << XNumber << std::endl;
        }
        int stavka;
        std::cout << "Enter stavka: ";
        std::cin >> stavka;

        std::vector<int> guesses(numPlayers);
        std::vector<int> distances(numPlayers);

        for (int i = 0; i < numPlayers; ++i) {
            std::cout << players[i].getName() << ", enter number from 1 to 100: ";
            std::cin >> guesses[i];
            distances[i] = abs(guesses[i] - XNumber);


        }
        if (gameMode == 1) {
            std::cout << "X number : " << XNumber << std::endl;
        }
        // Определение победителя
        int minDistance = *std::min_element(distances.begin(), distances.end());
        std::vector<int> winners;
        for (int i = 0; i < numPlayers; ++i) {
            if (distances[i] == minDistance) {
                winners.push_back(i);
            }
        }

        // Начисление очков
        if (winners.size() > 1) {
            // При равном расстоянии - 50 очков каждому
            for (int winnerIndex : winners) {
                players[winnerIndex].addScore(stavka/2);
                std::cout << players[winnerIndex].getName() << " +50 points" << std::endl;
            }
        }
        else {
            // Победитель получает 100 очков
            players[winners[0]].addScore(stavka);
            std::cout << players[winners[0]].getName() << " win" << std::endl;
            std::cout << players[winners[0]].getName() << " + " << stavka << " points" << std::endl;
           
        }

        // Штрафные очки для проигравших
        for (int i = 0; i < numPlayers; ++i) {
            if (std::find(winners.begin(), winners.end(), i) == winners.end()) {
                players[i].addScore(0-stavka/2);
                std::cout << players[i].getName() << " - " << stavka/2 <<  " points" << std::endl;
            }
        }
        int win = 0;
        // Проверка на победу
        for (const auto& player : players) {
            if (player.getScore() >= 1000) {
                std::cout << "-------------Winner: " << player.getName() <<  " --------------------" << std::endl;
                std::cout << "Number played raunds: " << roundCount + 1 << std::endl;
                return 0;
                
                win++;
                
            }
        }
        if (win == 0) 
        {
            for (const auto& player : players) {
                
                    std::cout << "Current balance : " << player.getName() << "  " << player.getScore() << std::endl;
                   
                   

                }
            
            
            std::cout << "Nobody wins. Next raund" << std::endl;
            std::cout << "-----------------------" << std::endl;
            
        }
        ++roundCount;
    }

    
}
