/* Abstract leaf node for block end type
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 16/11/2018
   Edited: 16/11/2018 */

#ifndef STOPTYPE_HPP_CEQUAL
#define STOPTYPE_HPP_CEQUAL

#include "Value.hpp"

enum SType{
    STOP, SKIP, RETURN, END
};

class StopType: public Value {
public:
    explicit StopType(SType s);

    SType stype;
    Value *val = nullptr;
};


#endif /* STOPTYPE_HPP_CEQUAL */
