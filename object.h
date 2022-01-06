#include <string>
using namespace std;

class object{
    private:
        int value;
        std::string objectName;
        std::string level;
        
    public:
        object();
        object(std::string, std::string);
        std::string getName();
        std::string getLevel();
        int getValue();
        void setValue(int);
        

};