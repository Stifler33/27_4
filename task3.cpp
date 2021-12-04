#include <iostream>
#include "mainRandFunction.h"
#include <vector>
#include <cassert>
class Worker{
    std::vector<char> task;
    int numberTask;
    int nameWorker;
public:
    Worker(int inTask, int inNameWorker): numberTask(inTask), nameWorker(inNameWorker)
    {
        assert(inTask >= 0 && inNameWorker >= 0);
        for (int n = 0; n < numberTask; n++){
            task.push_back(randABC());
        }
    }
    void setTask(int countTask){
        for (int n = 0; n < countTask; n++){
            task.push_back(randABC());
            numberTask++;
        }
    }
    void listTask(){
        int count = 0;
        std::cout << "\t";
        for (auto t : task){
            std::cout << t << " ";
            count++;
            if (count > 20) {
                count = 0;
                std::cout << std::endl << "\t";
            }
        }
        std::cout << std::endl;
    }
    int gerNumberWorker(){
        return nameWorker;
    }
    int getNumberTask(){
        return numberTask;
    }
};
class Manager{
    int numberTask;
    int nameManager;
    int numberWorker;
public:
    Worker** arrWorker = nullptr;
    Manager(int inNameManager, int inCountWorker): nameManager(inNameManager), numberWorker(inCountWorker)
    {
        assert(inNameManager >= 0 && inCountWorker > 0);
        arrWorker = new Worker*[numberWorker];
    }
    void setTask(int inCountTask){
        assert (inCountTask > 0);
        userSrand(inCountTask + nameManager);
        numberTask = std::rand();
        int taskOnWorker = numberTask / numberWorker;
        int taskOnWorker2 = numberTask - (taskOnWorker * numberWorker);
        for (int w = 0; w < numberWorker; w++){
            arrWorker[w] = new Worker(taskOnWorker, w);
        }
        assert (taskOnWorker2 < numberWorker);
        for (int w = 0; w < taskOnWorker2; w++){
            arrWorker[w]->setTask(1);
        }
    }
    int getCountWorker(){
        return numberWorker;
    }
    int getCountTask(){
        return numberTask;
    }
};
class Director{
    Manager** arrManager = nullptr;
    int numberManager;
public:
    /*
    Director(int inNumberManager, int numberTask): numberManager(inNumberManager)
    {
        assert (inNumberManager > 0 && numberTask > 0);
        arrManager = new Manager*[inNumberManager];
    }
     */
    void setTeam(){
        std::cout << "Enter number Manager\n";
        std::cin >> numberManager;
        assert (numberManager > 0);
        arrManager = new Manager*[numberManager];
        for (int nw = 0; nw < numberManager; nw++){
            int numberWorker;
            std::cout << "Enter number worker for manager" << nw+1;
            std::cin >> numberWorker;
            arrManager[nw] = new Manager(nw, numberWorker);
        }
        for (int nm = 0; nm < numberManager; nm++){
            std::cout << "Enter number task for manager" << nm+1;
            int numberTask;
            std::cin >> numberTask;
            arrManager[nm]->setTask(numberTask);
        }
    }
    void listInformationTeam(){
        for (int i = 0; i < numberManager; i++){
            std::cout << "Manager " << i+1 << std::endl << "\t";
            std::cout << "task " << arrManager[i]->getCountTask() << std::endl << "\t";
            std::cout << "worker " << arrManager[i]->getCountWorker() << std::endl;
        }
    }
    void listInformationTask(){
        for (int i = 0; i < numberManager; i++){
            int numberWorker = arrManager[i]->getCountWorker();
            Worker* worker = nullptr;
            std::cout << "Manager " << i << std::endl;
            for (int w = 0; w < numberWorker; w++){
                std::cout << "Worker " << w << std::endl;
                worker = arrManager[i]->arrWorker[w];
                worker->listTask();
            }
        }
    }
};
int main(){
    //Worker worker = Worker(126);
    //Manager manager = Manager(14, 1, 7);
    /*for (int cw = 0; cw < manager.getCountWorker(); cw++){
        std::cout << "worker " << cw << " number task " << manager.arrWorker[cw]->getNumberTask() <<std::endl;
        manager.arrWorker[cw]->listTask();
        std::cout << std::endl;
    }
     */
    Director director = Director();
    director.setTeam();
    director.listInformationTeam();
    director.listInformationTask();
    return 0;
}
