#include "ScoreManager.h"

void ScoreManager::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void ScoreManager::notify(int score) {
    for (auto* obs : observers) {
        obs->onNotify(score);
    }
}
