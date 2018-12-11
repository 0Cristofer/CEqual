/* Leaf node for string definitons
   Authors: Bruno Cesar, Cristofer Oswald and Narcizo Gabriel
   Created: 19/10/2018
   Edited: 19/10/2018 */

#include <iostream>
#include <map>
#include "include/LiteralStr.hpp"

std::map<char, char> scape{
        {'a', '\a'},
        {'b', '\b'},
        {'f', '\f'},
        {'n', '\n'},
        {'r', '\r'},
        {'t', '\t'},
        {'v', '\v'},
        {'\\', '\\'},
        {'\"', '\"'},
        {'\'', '\''}
};

LiteralStr::LiteralStr(std::string *s): Literal(STR, "string"){
    auto * n_s = new std::string();
    bool add = false;
    unsigned long i;


    if((*s)[0] == '\"'){
        s->erase(0, 1);
    }

    if((*s)[s->size()-1] == '\"'){
        s->erase(s->size()-1, 1);
    }

    i = 0;
    for(auto c: *s){
        if(add){
            i++;
            add = false;
            continue;
        }

        if(c == '\\'){
            if(i < (s->size()-1)){
                if(scape.find((*s)[i+1]) != scape.end()){
                    c = scape[(*s)[i+1]];
                    add = true;
                }
            }
        }

        n_s->push_back(c);

        i++;
    }

    val = n_s;
}

LiteralStr::~LiteralStr(){
    free(val);
}
