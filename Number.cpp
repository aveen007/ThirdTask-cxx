#include "Number.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;


string translate(int num) {
    if (num == 0) {
        return "zero";
    }

    std::vector<std::string> belowTwenty = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };
    std::vector<std::string> tens = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    std::string words = "";

    if (num >= 1000) {
        words += belowTwenty[num / 1000] + " thousand ";
        num %= 1000;
    }

    if (num >= 100) {
        words += belowTwenty[num / 100] + " hundred ";
        num %= 100;
    }

    if (num >= 20) {
        words += tens[num / 10] + " ";
        num %= 10;
    }

    if (num > 0) {
        words += belowTwenty[num] + " ";
    }

    return words.substr(0, words.size() - 1); // Remove the trailing space
}
Number::Number() :number_value(0), number_name("zero") {
    //std::cout << "Normal empty constructor" << std::endl;
}
// normal constructor
Number::Number(int number_value)
    :number_value(number_value) {
    number_name = translate(number_value);
    //std::cout << "Normal constructor" << std::endl;
}
// move contstructor
Number::Number(Number&& Other) noexcept
    :number_value(Other.number_value), number_name(Other.number_name) {
    //std::cout << "Move constructor" << std::endl;

}
// copy constructor 
Number::Number(const Number& Other)
    :number_value(Other.number_value), number_name(Other.number_name) {
    //std::cout << "Copy constructor" << std::endl;

}

// assignment copy operator 
Number& Number::operator = (const Number& number) {
    if (this != &number) {
        number_value = number.number_value;
        number_name = number.number_name;
    }
    //std::cout << "assigmenet copy operator" << std::endl;

    return *this;
}
// assignment move operator 

Number& Number::operator = (const Number&& number) noexcept {
    if (this != &number) {

        number_value = number.number_value;
        number_name = number.number_name;
        //number_name = std::move(number.number_name);
    }
    //std::cout << "assigmenet move operator" << std::endl;

    return *this;
}
Number& Number::operator + (const Number& number) {
    if (this != &number) {
        number_value += number.number_value;
        number_name = translate(number_value);
    }
    //std::cout << "addition copy operator" << std::endl;

    return *this;

}
// addition move operator 

Number& Number::operator +(const Number&& number) noexcept {
    if (this != &number) {

        number_value += number.number_value;
        number_name = translate(number_value);
        //number_name = std::move(number.number_name);
    }
    //std::cout << "addition move operator" << std::endl;

    return *this;
}
void Number:: setNumberValue(int value) {
    number_value = value;
}
void Number::  setNumberName(std::string name) {
   number_name = name;
}
int  Number:: getNumberValue() const {
    return number_value;

}
std::string Number::getNumberName() const{
    return number_name;
}

//Destructor
Number::~Number() {
    //std::cout << "destructor" << std::endl;
}