#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


namespace ariel{
    class NumberWithUnits{
        double number;
        std::string units;
        public:
        static std::vector<std::string> conversion;
        NumberWithUnits(double number , std::string units);
        double get_number()const {
            return this->number;
        }
        std::string get_units() const {
            return this-> units;
        }
        void set_number(double number){
            this->number = number;
        }
        void set_units(std::string units){
            this->units = units;
        }
        NumberWithUnits& operator++(); // pre-increment  done.
        NumberWithUnits& operator--(); // pre-decrement   done.
        NumberWithUnits operator++(int); // post-increment  done. 
        NumberWithUnits operator--(int); // post-decrement   done.
        NumberWithUnits operator+();
        NumberWithUnits operator-();
        NumberWithUnits operator+(const NumberWithUnits &num1);
        NumberWithUnits operator-(const NumberWithUnits &num1);
        NumberWithUnits& operator +=(const NumberWithUnits& b);
        NumberWithUnits& operator =(const NumberWithUnits& b);
        
        static void read_units(std::ifstream& units_file){
        std::string str;
        static std::vector<std::string> conversion;
            while (std::getline(units_file, str))
            {
                // Line contains string of length > 0 then save it in vector.
                conversion.push_back(str);
                std::cout<< str<<std::endl;
            }

        }
        
    };
    NumberWithUnits operator*(const double &b ,NumberWithUnits& num) ; // multiply number with units with duoble.
    std::ostream& operator<<(std::ostream& os, const NumberWithUnits& num);
    std::istream& operator>>(std::istream& is, NumberWithUnits& num);
    bool operator == (const NumberWithUnits &num1 , const NumberWithUnits &num2); // equal operator
    bool operator != (const NumberWithUnits &num1 , const NumberWithUnits &num2); // not equal operator
    bool operator < (const NumberWithUnits &num1 , const NumberWithUnits &num2); // less than operator
    bool operator > (const NumberWithUnits &num1 , const NumberWithUnits &num2); // greater than operator
    bool operator <=(const NumberWithUnits &num1 , const NumberWithUnits &num2); //less or equal than operator
    bool operator >=(const NumberWithUnits &num1 , const NumberWithUnits &num2); // greater or equal than operator    
 
};