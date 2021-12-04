#include <iostream>
#include <vector>
#include <random>
#include "mainRandFunction.h"
#include <fstream>
class Branch{
    std::string nameElf = "null";
    Branch* parent = nullptr;
public:
    std::vector<Branch*> averBranch;
    void setName(std::string &name){
        if (name.empty()) return;
        nameElf = name;
    }
    std::string getName(){
        return nameElf;
    }
    void setAverBranch(){
        for (int i = randNum(2,3); i >=0; i--){
            averBranch.push_back(new Branch);
        }
    }
};
class Wood{
    Branch** arrBranch = nullptr;
public:
    Wood(){
        arrBranch = new Branch*[5];
        for (int i = 0; i < 5; i++){
            arrBranch[i] = new Branch();
            arrBranch[i]->setAverBranch();
        }
    }
    void setNameBranch(std::ifstream &fileName){
        for (int i = 0; i < 5; i++){
            //std::cout << "Enter name elf on " << i+1 << " branch\n";
            std::string name;
            //std::cin >> name;
            fileName >> name;
            arrBranch[i]->setName(name);
        }
    }
    void setNameAverBranch(std::ifstream &fileName){
        for (int i = 0; i < 5; i++){
            //std::cout << "wood " << i+1 << std::endl;
            for (int a = 0; a < arrBranch[i]->averBranch.size(); a++){
                std::string name;
                //std::cin >> name;
                fileName >> name;
                arrBranch[i]->averBranch[a]->setName(name);
            }
        }
    }
    void list(){
        for (int i = 0; i < 5; i++){
            std::cout << "wood " << i+1 << std::endl;
            std::cout << " name " << arrBranch[i]->getName() << std::endl;
            for (int b = 0; b < arrBranch[i]->averBranch.size(); b++) {
                std::cout << "aver branch " << b+1 << std::endl;
                for (auto ab : arrBranch[i]->averBranch){
                    std::cout << " name " << ab->getName() << std::endl;
                }
            }
        }
    }
    void searchElf(){

        std::cout << "enter name\n";
        std::string name;
        std::cin >> name;
        for (int B = 0; B < 5; B++){
            if (arrBranch[B]->getName() == name){
                std::cout << "there is such\n";
                return;
            }
            for (int b = 0; b < arrBranch[B]->averBranch.size(); b++){
                Branch* ptrAverBranch = arrBranch[B]->averBranch[b];
                if (name == ptrAverBranch->getName()){
                    std::cout << "there is such\n";
                    std::cout << "neighbor " << arrBranch[B]->getName() << std::endl;
                    return;
                }
            }
        }
        std::cout << "found nobody\n";
    }
};
int main(){
    std::ifstream fileName("name");
    Wood wood = Wood();
    wood.setNameBranch(fileName);
    wood.setNameAverBranch(fileName);
    wood.list();
    wood.searchElf();
    return 0;
}
