#pragma once
#include <string>
#include <utility>
class Number
{
private:
	int number_value;
	std::string number_name;
public:

	Number();
	// normal constructor
	Number(int number_value);
	// move contstructor
	Number(Number && Other) noexcept;
	// copy constructor 
	Number(const Number& Other);
	// assignment copy operator 
	Number& operator = (const Number& number);
	// assignment move operator 

	Number& operator = (const Number&& number) noexcept;
	// addition copy operator 
	Number& operator + (const Number& number);
	// addition move operator 

	Number& operator +(const Number&& number) noexcept;

	void setNumberValue(int value);
	void setNumberName(std::string name);
	int getNumberValue()const;
	std::string getNumberName()const;
	//Destructor
	~Number();

};

