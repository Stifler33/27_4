#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <vector>
int randNum(int min, int max){
    double frac = 1.0 / (double(RAND_MAX) + 1.0);
    return int(rand() * frac * (max - min + 1) + min);
}
class Home{
    std::string nameTenant;
public:
    Home(std::string name = "null"): nameTenant(name)
    {
    }
    std::string getName(){
        return nameTenant;
    }
    void setName(std::string& inName){
        nameTenant = inName;
    }
};
class AverBranch{
    Home** arPtrHome = nullptr;
    int countHome;
public:
    AverBranch(): countHome(randNum(1, 3))
    {
        arPtrHome = new Home*[countHome];
        for (int i = 0; i < countHome; i++){
            arPtrHome[i] = new Home();
        }
    }
    int getCountHome(){
        return countHome;
    }
    Home* getPtrHome(int numberHome){
        assert(numberHome >= 0 && numberHome <= countHome);
        return arPtrHome[numberHome];
    }
};
class BigBranch{
    int counterHome;
    Home** arPtrHome = nullptr;
    int countAverBranch;
    AverBranch** arPtrAverBranch = nullptr;
public:
    BigBranch(int inNumHome = randNum(3,5), int inNumAverBranch = randNum(2, 3)):
            counterHome(inNumHome), countAverBranch(inNumAverBranch)
    {
        arPtrHome = new Home*[counterHome];
        for (int i = 0; i < counterHome; i++){
            arPtrHome[i] = new Home();
        }
        arPtrAverBranch = new AverBranch*[countAverBranch];
        for (int i = 0; i < countAverBranch; i++){
            arPtrAverBranch[i] = new AverBranch();
        }
    }
    int getCounterHome(){
        return counterHome;
    }
    Home* getPtrHome(int numberHome){
        assert(numberHome >= 0 && numberHome <= counterHome);
        return arPtrHome[numberHome];
    }
    AverBranch* getPtrAverBranch(int numberAverBranch){
        assert(numberAverBranch >= 0 && numberAverBranch >= countAverBranch);
        return arPtrAverBranch[numberAverBranch];
    }
};

class Wood{
    int countBranch = 0;
    int numBB;
    BigBranch** arrBB = nullptr;
public:
    Wood(int inNumBB = randNum(3, 5)): countBranch(inNumBB)
    {
        arrBB = new BigBranch*[countBranch];
        for (int i = 0; i < countBranch; i++){
            arrBB[i] = new BigBranch();
        }
    }
    int getNumArrBB(){
        return countBranch;
    }
    BigBranch* getPtrBigBranch(int numberBigBranch){
        assert(numberBigBranch >= 0 && numberBigBranch <= countBranch);
        return arrBB[numberBigBranch];
    }
    void setNameHome(){
        std::string name;
        for (int i = 0; i < countBranch; i++){
            int countHome = arrBB[i]->getCounterHome();
            BigBranch* ptrBigBranch = arrBB[i];
            for (int h = 0; h < countHome; h++){
                Home* ptrHome = ptrBigBranch->getPtrHome(h);
                std::cout << "Enter name home :";
                std::cin >> name;
                ptrHome->setName(name);
            }
        }
    }
};

class Forest{
    int countWood;
    Wood** arrPtrWood = nullptr;
public:
    Forest(): countWood(5)
    {
        arrPtrWood = new Wood*[countWood];
        for (int i = 0; i < countWood; i++){
            arrPtrWood[i] = new Wood();
        }
    }
    Wood* getPtrWood(int numberWood){
        assert (numberWood >= 0 && numberWood <= countWood);
        return arrPtrWood[numberWood];
    }
};
int main() {
    srand(std::time(nullptr));
    randNum(3,5);
    Forest forest = Forest();
    std::string nameTenant;
    for (int i = 0; i < 5; i++){
        forest.getPtrWood(i)->setNameHome();
    }
    return 0;
}
