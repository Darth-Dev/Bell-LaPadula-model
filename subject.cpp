#include "subject.h"

subject::subject(){
    value = 0;
}

subject::subject(std::string subName, std::string subLevel){
    subjectName = subName;
    level = subLevel;
    value = 0;
}

std::string subject::getName(){
    return subjectName;
}

std::string subject::getLevel(){
    return level;
}

int subject::getValue(){
    return value;
}