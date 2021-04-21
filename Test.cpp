#include "NumberWithUnits.hpp"
#include "doctest.h"

std::string nospaces(std::string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
/*
ariel::NumberWithUnits num1{3 ,"m"};
ariel::NumberWithUnits num2{3.6 ,"kg"};
ariel::NumberWithUnits num3{3000,"cm"};
ariel::NumberWithUnits num4{2000 ,"cm"};
ariel::NumberWithUnits num5 = num3;
ariel::NumberWithUnits num6 {4.7,"kg"};
ariel::NumberWithUnits num7 {1 ,"ton" };
*/

TEST_CASE("Good post code") {
	CHECK((num1 <= num4) == false);
	CHECK((num3 <= num4) == false);
	CHECK((num3 >= num4) == true);;
	CHECK((num1 == num4) == false); 
	CHECK((num4 <= num3) == true);
	CHECK((num2 <= num6) == false);
	CHECK((num6 <= num2) == true);
	CHECK((num7 <= num6) == false);
	CHECK((num6 <= num7) == true);//
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
	CHECK((num1 <= num4) == false);
}