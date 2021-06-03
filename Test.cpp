#include "NumberWithUnits.hpp"
#include "doctest.h"


// std::string nospaces(std::string input) {
// 	std::erase(input, ' ');
// 	std::erase(input, '\t');
// 	std::erase(input, '\n');
// 	std::erase(input, '\r');
// 	return input;
// }





TEST_CASE("Good post code") {
	ariel::NumberWithUnits m_3{3 ,"m"};
	ariel::NumberWithUnits kg_3{3 ,"kg"};
	ariel::NumberWithUnits cm_3000{3000,"cm"};
	ariel::NumberWithUnits cm_2000{2000 ,"cm"};
	ariel::NumberWithUnits num5 = cm_3000;
	ariel::NumberWithUnits g_4700 {4700,"g"};
	ariel::NumberWithUnits mins_30 (30 ,"min") ;
 	
	//Distances
	ariel::NumberWithUnits km_3(3 , "km");
    ariel::NumberWithUnits km_1(1 , "km");
    ariel::NumberWithUnits m_1000(1000 , "m");
    ariel::NumberWithUnits cm_100000(100000 , "cm");

    //Weights
    ariel::NumberWithUnits ton_1(1 , "ton");
    ariel::NumberWithUnits kg_1000(1000 , "kg");
    ariel::NumberWithUnits g_1000000(1000000 , "g");
    ariel::NumberWithUnits mg_1000000000(1000000000 , "mg");

    //Coins
    ariel::NumberWithUnits EUR_10(10,"EUR");
    ariel::NumberWithUnits USD_100(100,"USD");
    ariel::NumberWithUnits ILS_45(45,"ILS");
    ariel::NumberWithUnits ILS_333(333,"ILS");

    //Time units
    ariel::NumberWithUnits hour_1(1 , "hour");
    ariel::NumberWithUnits min_60(60 , "min");
    ariel::NumberWithUnits sec_3600(3600 , "sec");
	
	CHECK((m_3 <= cm_2000) == false);
	CHECK((cm_3000 <= cm_2000) == false);
	CHECK((cm_3000 >= cm_2000) == true);;
	CHECK((m_3 == cm_2000) == false); 
	CHECK((cm_2000 <= cm_3000) == true);
	CHECK((kg_3 <= g_4700) == false);
	CHECK((g_4700 <= kg_3) == true);
	CHECK((ton_1 <= g_4700) == false);
	CHECK((g_4700 <= ton_1) == true);
	CHECK((mins_30 ==hour_1) == false);
	CHECK((hour_1 <= mins_30) == false);
	CHECK((m_3 >= cm_2000) == true);
	CHECK((m_3 != cm_2000) == true);
	CHECK((m_3 != m_3) == false);
	mins_30+= hour_1; // now mins_30 is bigger than hour_1;
	CHECK((hour_1 <= mins_30) == true);
	CHECK(km_1 == m_1000);
    CHECK(km_1 == cm_100000);//
	CHECK(ton_1 >= mg_1000000000);
	CHECK(hour_1 >= min_60);
    CHECK(hour_1 >= sec_3600);
	CHECK_EQ(km_1 + m_1000 + cm_100000, ariel::NumberWithUnits(3000, "m"));
    CHECK_EQ(mins_30 + hour_1, ariel::NumberWithUnits(90, "min"));
	km_1++;
    m_1000++;
    ton_1++;
    kg_1000++;
	CHECK(km_1 == ariel::NumberWithUnits(2 , "km"));
    CHECK(m_1000 == ariel::NumberWithUnits(1001 , "m"));
	CHECK(ton_1 == ariel::NumberWithUnits(2 , "ton"));
    CHECK(kg_1000 == ariel::NumberWithUnits(1001 , "kg"));
	CHECK(km_1 != m_1000);
	CHECK(EUR_10 == ariel::NumberWithUnits(11 , "EUR"));
    CHECK(USD_100 == ariel::NumberWithUnits(101 , "USD"));
    CHECK(ILS_45 == ariel::NumberWithUnits(46 , "ILS"));
	EUR_10--;
    m_1000--;
    USD_100--;
    kg_1000--;
	EUR_10--;
    m_1000--;
    USD_100--;
    kg_1000--;
	CHECK(EUR_10 == ariel::NumberWithUnits(8 , "EUR"))
}