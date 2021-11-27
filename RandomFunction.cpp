#include <random>
#include <ctime>
#include "mainRandFunction.h"
void timeSrand(){
    std::srand(time(nullptr));
}
void userSrand(int initNumber){
    std::srand(initNumber);
}
int randNum(int min, int max){
    double frac = 1.0 / (double(RAND_MAX) + 1.0);
    return int(rand() * frac * (max - min + 1) + min);
}

char randABC(){
    randNum(4,8);
    int number = randNum(1,3);
    switch(number){
        case 1:
            return 'A';
        case 2:
            return 'B';
        case 3:
            return 'C';
        default:
            return 'N';
    }
}