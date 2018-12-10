/* Abstract leaf node for block end type
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 16/11/2018
   Edited: 16/11/2018 */

#include "src/classes/value/include/StopType.hpp"

StopType::StopType(SType s, int line) : Value(STOPTYPE), stype(s), line(line) {

}
