#include <iostream>
#include "mainRandFunction.h"
#include <vector>
#include <cassert>
class Worker{
    std::vector<char> task;
    int numberTask;
public:
    Worker(int inTask): numberTask(inTask)
    {
        assert(inTask > 0);
        timeSrand();
        for (int n = 0; n < numberTask; n++){
            task.push_back(randABC());
        }
    }
    void listTask(){
        int count = 0;
        for (auto t : task){
            std::cout << t << " ";
            count++;
            if (count > 20) {
                count = 0;
                std::cout << std::endl;
            }
        }
    }
};
class Manager{
    int countTask;
    int NumberManager;
    Worker** arrWorker = nullptr;
    int countWorker;
public:
    Manager(int inCountTask, int inNumberManager, int inCountWorker): countTask(inCountTask), NumberManager(inNumberManager), countWorker(inCountWorker)
    {
        arrWorker = new Worker*[countWorker];
        for (int w = 0; w < countWorker; w++){
            
        }
    }
};
int main(){
    //Worker worker = Worker(126);
    return 0;
}
