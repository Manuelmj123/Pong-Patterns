#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include <string>
#include <memory>
#include "GameObject.h"

class GameObjectFactory {
public:
    static std::shared_ptr<GameObject> create(const std::string& type);
};

#endif
