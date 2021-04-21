#include "NumberWithUnits.hpp"

namespace ariel{
    NumberWithUnits::NumberWithUnits(double number , std::string units){
        this->number = number;
        this->units = units;
    }

    NumberWithUnits& NumberWithUnits::operator =(const NumberWithUnits& b){
        this->set_number(b.get_number());
        this->set_units(b.get_units());
        return *this;
    }

    NumberWithUnits& NumberWithUnits::operator++()
    {
        this->number++; // actual increment takes place here
        return *this; // return new value by reference
    }
 
    // postfix increment
    NumberWithUnits NumberWithUnits::operator++(int)
    {
        NumberWithUnits old = *this; // copy old value
        operator++();  // prefix increment
        return old;    // return old value
    }
 
    // prefix decrement
    NumberWithUnits& NumberWithUnits::operator--()
    {
        this->number--; // actual decrement takes place here
        return *this; // return new value by reference
    }
 
    // postfix decrement
    NumberWithUnits NumberWithUnits::operator--(int)
    {
        NumberWithUnits old = *this; // copy old value
        operator--();  // prefix decrement
        return old;    // return old value
    }

    NumberWithUnits NumberWithUnits::operator+(){
        NumberWithUnits temp {this->number, this->units };
        return temp;
    }

    NumberWithUnits NumberWithUnits::operator-(){
        NumberWithUnits temp {this->number*(-1), this->units };
        return temp;
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &num1){
        NumberWithUnits temp {this->number, this->units };
        if (this->get_units().compare("km")){
            if(num1.get_units().compare("km")){
                temp.set_number(this->number+num1.get_number());
            }
            else if (num1.get_units().compare("m")){
                temp.set_number(this->number+num1.get_number());
            }
            return temp;
        }
        return temp;
    }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &num1){
        NumberWithUnits temp {this->number, this->units };
        return temp;
    }

    NumberWithUnits operator*(const double &b ,NumberWithUnits& num ){ // multiple by double
        NumberWithUnits temp {num.get_number(), num.get_units() };
        temp.set_number(temp.get_number()*b);
        return temp;
    }

    NumberWithUnits operator*(const int &b ,NumberWithUnits& num ){   // multiple by integer
        NumberWithUnits temp {num.get_number(), num.get_units() };
        temp.set_number(temp.get_number()*b);
        return temp;
    }

    NumberWithUnits& NumberWithUnits::operator +=(const NumberWithUnits& b){
        if(this->units.compare(b.units)){
            this->number += b.number;
            return *this;
        }
        else{
            throw("Units do not match - ["+this->get_units()+"] cannot be converted to []");
        }
    }

    // Comparison operators
    bool operator == (const NumberWithUnits &num1 , const NumberWithUnits &num2){    // equal operator
        return true;
    } 
    bool operator != (const NumberWithUnits &num1 , const NumberWithUnits &num2){   // not equal operator
        return true;
    } 
    bool operator < (const NumberWithUnits &num1 , const NumberWithUnits &num2){    // less than operator
        return true;
    } 
    bool operator > (const NumberWithUnits &num1 , const NumberWithUnits &num2){    // greater than operator
        return true;
    } 
    bool operator <=(const NumberWithUnits &num1 , const NumberWithUnits &num2){    //less or equal than operator
        return true;
    } 
    bool operator >=(const NumberWithUnits &num1 , const NumberWithUnits &num2){    // greater or equal than operator
        return true;
    } 

    std::ostream& operator<<(std::ostream& os, const NumberWithUnits& num) // took example for cppreference.com/w/cpp/language/operators
    {
    // write number to stream
    os<< num.get_number() << "[" << num.get_units() << "]";
    return os;
    }

    std::istream& operator>>(std::istream& is, NumberWithUnits& num) // took example for cppreference.com/w/cpp/language/operators
    {
    // read number from stream

    return is;
    }
};