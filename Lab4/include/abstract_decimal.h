#ifndef ABSTRACT_DECIMAL_H
#define ABSTRACT_DECIMAL_H

class Decimal
{
	public:
		virtual ~Decimal() {}
		virtual double convertToDecimal() const = 0;
};

#endif
