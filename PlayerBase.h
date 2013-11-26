#ifndef GAME_PLAYERBASE_H_
#define GAME_PLAYERBASE_H_

#include "PyProxy.h"
#include <stdint.h>


class CPlayerBase : public PyBase
{
public:
    CPlayerBase(void);
    ~CPlayerBase(void){}

    /*名称*/
    uint32_t getID(void);
    void setID(uint32_t id);

private:
    uint32_t id_;
};

#endif//GAME_PLAYERBASE_H_
