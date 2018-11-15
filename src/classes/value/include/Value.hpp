/* Abstract value
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 18/10/2018
   Edited: 18/10/2018 */

#ifndef VALUE_HPP_CEQUAL
#define VALUE_HPP_CEQUAL

// Possible evaluation values
enum ValueType {
    LITERALVAL
};

class Value {
public:
    explicit Value(ValueType t): type(t){}

    ValueType type;
};

#endif /* VALUE_HPP_CEQUAL */
