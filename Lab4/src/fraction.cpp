#include "fraction.h"
#include <iostream>
#include <stdexcept>

void Fraction::checkNull() const 
{
	if(numer_ == nullptr || denom_ == nullptr)
	{
		throw std::runtime_error("can't dereference null pointers");
	}
}


Fraction::Fraction()
{
	std::cout << "I am in the default constructor" << std::endl;
	numer_ = new int(0);
	denom_ = new int(1);
}

Fraction::Fraction(int n, int d)
{
	std::cout << "I am in the custom constructor" << std::endl;
	if(d == 0)
	{
		throw std::runtime_error("Error: Division by zero");
	} 
	numer_ = new int(n);
	denom_ = new int(d);
}

Fraction::Fraction(const Fraction& other)
{
	std::cout << "I am in the copy constructor" << std::endl;
	other.checkNull();
	numer_ = new int(*other.numer_);
	denom_ = new int(*other.denom_);
}

Fraction::Fraction(Fraction&& other) noexcept
{
	std::cout << "I am in the move constructor" << std::endl;
	numer_ = other.numer_;
	denom_ = other.denom_;
	
	other.numer_ = nullptr;
	other.denom_ = nullptr;
}


Fraction::~Fraction()
{
	std::cout << "I am in the destructor" << std::endl;
	delete numer_;
	delete denom_;
}

Fraction& Fraction::operator=(const Fraction& other)
{
	std::cout << "I am in the assignment operator (lvalue)" << std::endl;
	if(this != &other)
	{
		other.checkNull();
		delete numer_;
		delete denom_;
	
		numer_ = new int(*other.numer_);
		denom_ = new int(*other.denom_);
	}
	return *this;
}

 
Fraction& Fraction::operator=(Fraction&& other) noexcept
{
	std::cout << "I am in the assignment operator (rvalue)" << std::endl;
	if(this != &other)
	{
		delete numer_;
		delete denom_;
		
		numer_ = other.numer_;
		denom_ = other.denom_;
		
		other.numer_ = nullptr;
		other.denom_ = nullptr;
	}
	
	return *this;
}

double Fraction::convertToDecimal() const 
{
	std::cout << "I am in the convertToDecimal " << std::endl;
	checkNull();
	return static_cast<double>(*numer_)/ *denom_;
}

Fraction operator+(const Fraction& Ihs, const Fraction& rhs)
{
	std::cout << "I am in the plus operator " << std::endl;
	Ihs.checkNull();
	rhs.checkNull();
	
	int newNumer = (*Ihs.numer_ * *rhs.denom_) + (*rhs.numer_ * *Ihs.denom_);
	int newDenom = *Ihs.denom_ * *rhs.denom_;
	return Fraction(newNumer, newDenom);
}


Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
	std::cout << "I am in the multiplication operator " << std::endl;
	lhs.checkNull();
	rhs.checkNull();
	return Fraction((*lhs.numer_ * *rhs.numer_), (*lhs.denom_ * *rhs.denom_));
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
	std::cout << "I am in the << operator "  << std::endl;
	f.checkNull();
	os << *f.numer_ << "/" << *f.denom_;
	return os;
}







