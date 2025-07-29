#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void onNotify(int score) = 0;
};

#endif
