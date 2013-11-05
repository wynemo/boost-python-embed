#ifndef GAME_PLAYERBASE_H_
#define GAME_PLAYERBASE_H_

#include "PyProxy.h"



class CPlayerBase : public PyProxy
{
public:
    CPlayerBase(void);
    ~CPlayerBase(void){}

    /*名称*/
    int getID(void);
    void setID(int id);

private:
    int id_;
};

#endif//GAME_PLAYERBASE_H_
