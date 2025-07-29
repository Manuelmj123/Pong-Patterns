#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <vector>
#include "Observer.h"

class ScoreManager {
public:
    void addObserver(Observer* observer);
    void notify(int score);

private:
    std::vector<Observer*> observers;
};

#endif
