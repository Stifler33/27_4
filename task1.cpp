#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <vector>
#include <fstream>
int randNum(int min, int max){
    double frac = 1.0 / (double(RAND_MAX) + 1.0);
    return int(rand() * frac * (max - min + 1) + min);
}
class Home{
    std::string nameTenant;
public:
    Home(std::string name = "none"): nameTenant(name)
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
        assert(numberHome >= 0 && numberHome < countHome);
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
        assert(numberHome >= 0 && numberHome < counterHome);
        return arPtrHome[numberHome];
    }
    int getCountAverBranch(){
        return countAverBranch;
    }
    AverBranch* getPtrAverBranch(int numberAverBranch){
        assert(numberAverBranch >= 0 && numberAverBranch < countAverBranch);
        return arPtrAverBranch[numberAverBranch];
    }
};

class Wood{
    int countBranch = 0;
    //int numBB;
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
        assert(numberBigBranch >= 0 && numberBigBranch < countBranch);
        return arrBB[numberBigBranch];
    }
    void setNameHomeBB(std::ifstream& fileName){
        std::string name;
        //open file with names
        std::cout << "Enter name homes on big branch\n";
        //list big branch
        for (int i = 0; i < countBranch; i++){
            int countHome = arrBB[i]->getCounterHome();
            std::cout << "Big branch " << i+1 << std::endl;
            BigBranch* ptrBigBranch = arrBB[i];
            //list home on a branch
            for (int h = 0; h < countHome; h++){
                Home* ptrBBHome = ptrBigBranch->getPtrHome(h);
                std::cout << "Enter name home :";
                //std::cin >> name;
                if (!fileName.eof()) {
                    fileName >> name;
                }else if (fileName.eof()){
                    name = "none";
                }
                std::cout << name << std::endl;
                ptrBBHome->setName(name);
            }
            //list aver branch
            int countAverBranch = arrBB[i]->getCountAverBranch();
            std::cout << "Enter aver branch\n";
            for (int a = 0; a < countAverBranch; a++){
                AverBranch* ptrAB = arrBB[i]->getPtrAverBranch(a);
                int countABHome = ptrAB->getCountHome();
                std::cout << "Aver branch " << a+1 << std::endl;
                for (int h = 0; h < countABHome; h++){
                    Home* ptrABHome = ptrAB->getPtrHome(h);
                    std::cout << "Enter name home :";
                    //std::cin >> name;
                    if (!fileName.eof()) {
                        fileName >> name;
                    }else if (fileName.eof()){
                        name = "none";
                    }
                    std::cout << name << std::endl;
                    ptrABHome->setName(name);
                }
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
        assert (numberWood >= 0 && numberWood < countWood);
        return arrPtrWood[numberWood];
    }
};
int main() {
    srand(std::time(nullptr));
    randNum(3,5);
    Forest forest = Forest();
    std::string nameTenant;
    std::ifstream fileName("name");
    for (int i = 0; i < 5; i++){
        std::cout << "Wood " << i+1 << ":\n";
        forest.getPtrWood(i)->setNameHomeBB(fileName);
    }
    std::string searchName;
    std::cout << "Enter search name\n";
    std::cin >> searchName;
    for (int w = 0; w < 5; w++){
        int counterBB = forest.getPtrWood(w)->getNumArrBB();
        for (int b = 0; b < counterBB; b++){
            BigBranch* currentPtrBB = forest.getPtrWood(w)->getPtrBigBranch(b);
            int counterHomeBB = currentPtrBB->getCounterHome();
            for (int hB = 0; hB < counterHomeBB; hB++){
                Home* currentPtrHomeBB = forest.getPtrWood(w)->getPtrBigBranch(b)->getPtrHome(hB);
                if (searchName == currentPtrHomeBB->getName()){
                    std::cout << "Wood " << w+1 << ", BigBranch " << b+1 << ", Home " << hB+1 << std::endl;
                    std::cout << "number of neighbors " << counterHomeBB;
                    fileName.close();
                    return 0;
                }
            }
            int countAverBranch = forest.getPtrWood(w)->getPtrBigBranch(b)->getCountAverBranch();
            for (int ab = 0; ab < countAverBranch; ab++){
                AverBranch* currentAverBranch = forest.getPtrWood(w)->getPtrBigBranch(b)->getPtrAverBranch(ab);
                int countHomeAB = currentAverBranch->getCountHome();
                for (int hAB = 0; hAB < countHomeAB; hAB++){
                    Home* ptrHomeAB = currentAverBranch->getPtrHome(hAB);
                    if (searchName == ptrHomeAB->getName()){
                        std::cout << "Wood " << w+1 << ", BigBranch " << b+1 << ", Aver Branch " << ab+1 << ", Home " << hAB+1 << std::endl;
                        std::cout << "number of neighbors " << counterHomeBB << std::endl;
                        fileName.close();
                        return 0;
                    }
                }
            }
        }
    }
    fileName.close();
    return 0;
}
