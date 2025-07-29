#include "GameObjectFactory.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"


std::shared_ptr<GameObject> GameObjectFactory::create(const std::string& type) {
    if (type == "Paddle") {
        return std::make_shared<Paddle>(360, 580, 80, 10);
    } else if (type == "Ball") {
        return std::make_shared<Ball>(390, 300, 15);
    }else if (type == "Brick") {
        return std::make_shared<Brick>(100, 100, 80, 20); // Default
    }

    return nullptr;
}
