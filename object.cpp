#include "object.h"

object::object(){
    value = 0;
}

object::object(std::string objName, std::string objLevel){
    objectName = objName;
    level = objLevel;
    value = 0;
}

std::string object::getName(){
    return objectName;
}

std::string object::getLevel(){
    return level;
}

int object::getValue(){
    return value;
}

void object::setValue(int val){
    value = val;
}