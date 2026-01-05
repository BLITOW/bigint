#pragma once

#include <cstdlib>
#include <iostream>

class vect2{

	private:
		int x;
		int y;
	public:
		vect2(){
		x = 0;
		y = 0;
		}
		vect2(int i, int j){
			x = i;
			y = j;
		}
		vect2(const vect2& obj)
		{
			x = obj.x;
			y = obj.y;
		}
		vect2(int i){
			x = i;
			y = i;
		}
		vect2& operator=(const vect2& obj)
		{
			if (this == &obj)
				return *this;
			x = obj.x;
			y = obj.y;
			return *this;
		}

		int operator[](int i) const
		{
			if(i == 0)
				return x;
			return y;
		}
                int& operator[](int i)
                {
                        if(i == 0)
                                return x;
                        return y;
                }
		
		vect2 operator++(int)
		{
			vect2 tmp(*this);

			x++;
			y++;

			return (tmp);
		}
		vect2& operator++()
		{
			x++;
			y++;
			return *this;
		}	
                vect2 operator--(int)
                {
                        vect2 tmp(*this);

                        x--;
                        y--;

                        return (tmp);
                }
                vect2& operator--()
                {
                        x--;
                        y--;
                        return *this;
                }

		vect2 operator+(const vect2& obj) const
		{
			vect2 tmp(*this);

			tmp.x = tmp.x + obj.x;
			tmp.y = tmp.y + obj.y;

			return tmp;
		}
                vect2 operator-(const vect2& obj) const
                {
                        vect2 tmp(*this);

                        tmp.x = tmp.x - obj.x;
                        tmp.y = tmp.y - obj.y;

                        return tmp;
                }
		vect2 operator*(const vect2& obj) const
                {
                        vect2 tmp(*this);

                        tmp.x = tmp.x * obj.x;
                        tmp.y = tmp.y * obj.y;

                        return tmp;
                }

		vect2& operator+=(const vect2& obj)
		{
			*this = *this + obj;
			return *this;
		}
                vect2& operator-=(const vect2& obj)
                {
                        *this = *this - obj;
                        return *this;
                }
                vect2& operator*=(const vect2& obj)
                {
                        *this = *this * obj;
                        return *this;
                }
		
		vect2 operator-() const
		{
			vect2 tmp(*this);
			tmp.x = -tmp.x;
			tmp.y = -tmp.y;
			return tmp;
		}

		bool operator==(const vect2& obj) const
		{
			return (x == obj.x && y == obj.y);
		}
		bool operator!=(const vect2& obj) const
		{
			return (!(*this == obj));
		}
		

};

inline vect2 operator*(int i, const vect2& obj) 
{
	vect2 tmp(obj);
	tmp = tmp * i;
	return tmp;
}

inline std::ostream& operator<<(std::ostream& os, const vect2& obj)
{
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return os;
}
