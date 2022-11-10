#ifndef __VALUE_H_
#define __VALUE_H_
#include<iostream>
class value 
{
public:
	value():_value(0){}
	value(int value):_value(value){}
	int val() const {return _value;}
	void set_value(int temp)
	{
		_value=temp;
	}
private:
	int _value;
};
std::istream &operator>>(std::istream &is,value &rhs)
{
	int temp;
	is>>temp;
	rhs.set_value(temp);
	
	return is;
}
std::ostream &operator<<(std::ostream &os,const value &rhs)
{
	os<<rhs.val();
	return os;
}
#define DEF_OP(OP) value operator OP(const value &rhs) const{\
	return value(_value OP rhs._value);\}

value operator+(const value &rhs) const{
	return value(_value+rhs._value);
}
value operator-(const value &rhs) const{
	return value(_value-rhs._value);
}
value operator*(const value &rhs) const{
	return value(_value*rhs._value);
}
value operator/(const value &rhs) const{
	return value(_value/rhs._value);
}

bool operator==(const value &rhs) const{
	retrun rhs._value==_value;
}

bool operator!=(const value &rhs) const{
	return !operator==(rhs);
}

bool operator>(const value &rhs) const{
	return _value>rhs._value;
}

bool operator<(const value &rhs) const{
	return _value<rhs._value;
}
//前加
value &operator++()
{
	++_value;
	return *this;
}
//后加
value operator++(int)
{
	value result =_value;
	++_value;
	return result;
}




#endif 