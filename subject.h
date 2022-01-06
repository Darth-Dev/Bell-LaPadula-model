#include <string>


class subject{
    private:
        int value;
        std::string subjectName;
        std::string level;
        
    
    public:
        subject();
        subject(std::string, std::string);
        void setValue(int);
        void setName(std::string);
        int getValue();
        std::string getName();
        std::string getLevel();
};