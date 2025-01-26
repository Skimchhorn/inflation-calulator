// Name: Kimchhorn Sambath


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "inflation.h"

TEST_SUITE_BEGIN("calculate");
// precondition:
//    passed two arguments which are the price from last year and the current price
//    that are non-negative and non-zero
TEST_CASE("typical") {
   CHECK(calculate(25, 30) == 20);  // i.e. 20% inflation
   CHECK(calculate(30, 29) == doctest::Approx(-3.33).epsilon(0.01));
}
TEST_CASE("Special Case") {
   CHECK(calculate(80, 1) == doctest::Approx(-98.88).epsilon(0.01));  
   CHECK(calculate(1, 80) == 7900); 
}
TEST_CASE("Negative inflation"){
   CHECK(calculate(30, 25) == doctest::Approx(-16.66).epsilon(0.01));
   CHECK(calculate(60, 30) == -50);
}
TEST_CASE("Positive inflation"){
   CHECK(calculate(50, 80) == 60);
   CHECK(calculate(60,80 ) == doctest::Approx(33.33).epsilon(0.01));
}
TEST_CASE("Stable Price"){
   CHECK(calculate(25, 25) == 0);
   CHECK(calculate(1, 1) == 0);
}
TEST_CASE("inflation that is double the price a year later, decimal number"){
   CHECK(calculate(55.55, 111.1) == 100);
   CHECK(calculate(22.22, 44.44) == 100);
}
TEST_CASE("inflation that is double the price a year later, whole number") {
   CHECK(calculate(77, 154) == 100);
   CHECK(calculate(10, 20) == 100);
}
TEST_CASE("Hyper Inflation"){
   CHECK(calculate(25, 500) == 1900);
   CHECK(calculate(5, 35) == 600);
}
TEST_CASE("Lowest Inflation"){
   CHECK(calculate(25,25.1) == doctest::Approx(0.4));
   CHECK(calculate(5,5.01) == doctest::Approx(0.2));
}
TEST_SUITE_END();
