//Name: Leon Becker
//File: main.cpp

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <Pool.h>

int main(int argc, char** argv){
    std::vector<Pool> standardPool;
    int drawnNumber;
    int currentAccumulation;
    int winnerIndex = -1;

    Pool gun_pool("Guns",PL_CNST::GUNS);
    Pool shield_pool("Shields", PL_CNST::SHIELDS);
    Pool grenade_pool("Grenades", PL_CNST::GRENADES);
    Pool class_mod_pool("Class Mods", PL_CNST::CLASS_MODS);
    Pool relic_pool("Relics", PL_CNST::RELICS);
    
    standardPool.push_back(gun_pool);
    standardPool.push_back(shield_pool);
    standardPool.push_back(grenade_pool);
    standardPool.push_back(class_mod_pool);
    standardPool.push_back(relic_pool);


    srand(time(NULL));
    int tries; 
    while(winnerIndex != 4){
        currentAccumulation = 0;
        drawnNumber = rand()%PL_CNST::TOTAL + 1;
        std::cout << drawnNumber << std::endl;
        for(unsigned int i = 0; i < standardPool.size(); i++){
            currentAccumulation += standardPool.at(i).tickets;
            if(currentAccumulation > drawnNumber){
                std::cout << standardPool.at(i).id << " is the winner!" << std::endl;
                winnerIndex = i;
                break;
            }
        }
        tries++;
    }
    
    std::cout << "It took " << tries << " tries to generate a relic" << std::endl;
}
