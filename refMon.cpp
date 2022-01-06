#include "refMon.h"
#include <iomanip>

refMon::refMon(){
    
}

void refMon::status(){

    std::cout << "+--------current state--------+\n" << "|-subject-|--level--|--value--|\n";
    for (int i = 0; i < subjects.size(); i++){
        std::cout << "| " << subjects[i]->getName() << " | "  << setw(7) << subjects[i]->getLevel() << " | " << setw(7) << subjects[i]->getValue() << " |\n";
    }


    std::cout << "|--object-|--level--|--value--|\n";
        for (int i = 0; i < objects.size(); i++){
        std::cout << "| " << objects[i]->getName() << " | " << setw(7) << objects[i]->getLevel() << " | " << setw(7) << objects[i]->getValue() << " |\n";
    }
    std::cout << "+-----------------------------+\n";
}

void refMon::addObj(std::string objName, std::string objLevel){
    object*obj = new object(objName, objLevel);
    objects.push_back(obj);
    std::cout << "Object Added   : addobj" << objName << " " << objLevel << std::endl;
}

void refMon::addSub(std::string subName, std::string subLevel){
    subject* sub = new subject(subName, subLevel);
    subjects.push_back(sub);
    std::cout << "Subject Added   : addsub " << subName << " " << subLevel << std::endl;
}

void refMon::read(string subjectName, string objectName){

    string subLevel, objLevel;
    int subIndex=-1, objIndex=-1;

    for (int i = 0; i < subjects.size(); i++){
        if(subjects[i]->getName() == subjectName){
            subLevel = subjects[i]->getLevel();
            subIndex = i;
            exit;
        }
    }

    for (int i = 0; i < objects.size(); i++){
        if(objects[i]->getName() == objectName){
            objLevel = objects[i]->getLevel();
            objIndex = i;
            exit;
        }
    }
    if(subIndex == -1 || objIndex == -1){cout << "Bad Instruction : read " << subjectName << " " << objectName << endl;  }

    if(subLevel == "LOW" && objLevel == "LOW"){
        
    }
    else if(subLevel == "MEDIUM" && (objLevel == "LOW" || objLevel == "MEDIUM")){
        cout << "Access Granted : " << subjectName << " reads " << objectName << endl;
    }
    else if (subLevel == "HIGH" && (objLevel == "LOW" || objLevel == "MEDIUM" || objLevel == "HIGH")){
        cout << "Access Granted : " << subjectName << " reads " << objectName << endl;
    }
    else{
        cout << "Access Denied : read " << subjectName << " " << objectName << endl;
    }
}

void refMon::write(string subjectName, string objectName, int value){

    string subLevel, objLevel;
    int subIndex, objIndex;

    for (int i = 0; i < subjects.size(); i++){
        if(subjects[i]->getName() == subjectName){
            subLevel = subjects[i]->getLevel();
            subIndex = i;
            exit;
        }
    }

    for (int i = 0; i < objects.size(); i++){
        if(objects[i]->getName() == objectName){
            objLevel = objects[i]->getLevel();
            objIndex = i;
            exit;
        }
    }

    if(subLevel.find("LOW") != string::npos && objLevel == "LOW"){
        cout << "Access Granted : " << subjectName << " writes " << value << " to " << objectName << endl;
        objects[objIndex]->setValue(value);

    }
    else if(subLevel == "MEDIUM" && (objLevel == "LOW" || objLevel == "MEDIUM")){
        cout << "Access Granted : " << subjectName << " writes " << value << " to " << objectName << endl;
        objects[objIndex]->setValue(value);
    }
    else if (subLevel == "HIGH" && (objLevel == "LOW" || objLevel == "MEDIUM" || objLevel == "HIGH")){
        cout << "Access Granted : " << subjectName << " writes " << value << " to " << objectName << endl;
        objects[objIndex]->setValue(value);
    }
    else{
        cout << "Access Denied : write " << subjectName << " " << objectName << " " << value << endl;
    }
    
    
    
}