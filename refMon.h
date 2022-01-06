#include "subject.h"
#include "object.h"
#include <iostream>
#include <vector>


class refMon{

    private:
        vector<subject*> subjects;
        vector<object*> objects;
    public:

        refMon();
        void addObj(string, string);
        void addSub(string, string);
        void status();
        void read(string, string);
        void write(string, string, int);
};