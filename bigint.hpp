#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class bigint{

	private: 
		std::string digits;
	public:

		bigint(){
		digits = "0";
		}
		bigint(std::string num){
			digits = num;
		}
		bigint(unsigned int num){
			std::stringstream ss;
			ss << num;
			digits = ss.str();
		}
		bigint(const bigint&  num)
		{
			digits = num.digits;
		}
		bigint& operator=(const bigint& num)
		{
			if (this != &num)
				digits = num.digits;
			return *this;
		}

		
		bigint operator+(const bigint num) const
		{
			bigint tmp(num);

			int i = digits.size() - 1;
			int j = tmp.digits.size() - 1;

			bigint ret;
			ret.digits = "";

			int sum;
			int rest = 0;
			int x;
			int y;

			while(i >= 0 || j >= 0 || rest > 0)
			{
				if (i >= 0)
					x = digits[i] - '0';
				else
					x = 0;
				if (j >= 0)
					y = tmp.digits[j] - '0';
				else
					y = 0;
				
				sum = x + y + rest;

				rest = sum / 10;
				sum = sum % 10;

				ret.digits.push_back(sum + '0');
				i--;
				j--;		
			}

			std::reverse(ret.digits.begin(), ret.digits.end());
			
			return ret;

		}


		bigint& operator +=(const bigint& num)
		{
			*this = *this + num;
			return *this;
		}

		bigint operator++(int){
		
			bigint tmp = *this;
			*this = *this + 1;
			return tmp;
		}

		bigint& operator++(){
		*this = *this + 1;
		return *this;
		}
		
		bigint operator<<(const bigint& num){
			bigint tmp(*this);
			unsigned int i = num.getint();

			while (i > 0){
				tmp.digits.push_back('0');
				i--;
			}
			return tmp;
		}

		bigint operator>>(const bigint& num){
			bigint tmp(*this);
			unsigned int i = num.getint();
			
			if (i >= digits.size())
				return (tmp.digits = "0", tmp);
			tmp.digits.erase(tmp.digits.size() - i, i);
			return tmp;
		}

		bigint& operator<<=(const bigint& num)
		{
			*this = *this << num;
			return *this;
		}
		bigint& operator>>=(const bigint& num)
                {
                        *this = *this >> num;
                        return *this;
                }

		bool operator<(const bigint& num){
			bigint tmp(*this);
			return (tmp.getint() < num.getint());
		}

                bool operator>(const bigint& num){
			bigint tmp(*this);
                        return (tmp.getint() > num.getint());
                }
		
		bool operator==(const bigint& num){
			bigint tmp(*this);
			return (tmp.getint() == num.getint());
		}
		bool operator!=(const bigint& num){
			return (!(*this == num));
		}
		bool operator<=(const bigint& num) {
			return (!(*this > num));
		}
		bool operator>=(const bigint& num){
			return (!(*this < num));
		}






		unsigned int getint() const
		{
			unsigned int i;
			std::stringstream ss(digits);
			ss >> i;
		       return i;	
		}
		std::string getstring()
		{
			return (this->digits);
		}
};

inline std::ostream& operator<<(std::ostream& os, const bigint& num)
{
	bigint tmp(num);
	os << tmp.getstring();
	return os;
};
