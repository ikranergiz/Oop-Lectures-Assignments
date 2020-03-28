#include "Quadrilateral.h"
#include <iostream>
//constructorlarda olusturulan nesnenin uye fonksiyonu(isValid) cagirilarak kontrol yapildi.

//default constructor .
Quadrilateral::Quadrilateral(const Point & a, const Point & c, const Color & color)
	: color{ color } //member initializer

{
		this->isValid();
}
//constructor.
Quadrilateral::Quadrilateral(const Point & a, double width, double height, const Color & color) 
	: color { color }//member initializer
{
	 pts[0].x = a.x;
	 pts[0].y = a.y;

	 height = a.distanceTo(b);
	 width = d.distanceTo(a);

	 this->isValid();
}
//constructor.
Quadrilateral::Quadrilateral(const Point & a, const Point & b, const Point & c, const Point & d, const Color & color) 
	: pts { a , b , c , d } , color{ color } //member initializer
{
		this->isValid();
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color & color) 
	: pts{ pts[0] , pts[1] , pts[2] , pts[3] } , color{ color }  //member initializer
{
	this->isValid();
}
//getter function
Point Quadrilateral::getA() const noexcept
{
	return a;
}
//getter function
Point Quadrilateral::getB() const noexcept
{
	return b;
}
//getter function
Point Quadrilateral::getC() const noexcept
{
	return c;
}
//getter function
Point Quadrilateral::getD() const noexcept
{
	return d;
}
//getter function
Quadrilateral::Color Quadrilateral::getColor() const noexcept
{
	return color;
}

string Quadrilateral::getColorAsString() const noexcept
{
	//color a gore string dondurur.
	switch (color)
	{
	case Quadrilateral::Color::RED:
		return "Red"; break;
	case Quadrilateral::Color::BLUE:
		return "Blue"; break;
	case Quadrilateral::Color::WHITE:
		return "White"; break;
	case Quadrilateral::Color::BLACK:
		return "Black"; break;
	case Quadrilateral::Color::GREEN:
		return "Green"; break;
	default:
		return "Green"; break;
	}
	
}
//dortgenin cevresini hesaplar.
double Quadrilateral::getPerimeter() const noexcept
{
	//kenar uzunluklari hesaplanir.
	double side1 = a.distanceTo(b);
	double side2 = b.distanceTo(c);
	double side3 = c.distanceTo(d);
	double side4 = a.distanceTo(d);

	//cevreyi hesapladik.
	double perimeter = side1 + side2 + side3 + side4;

	return perimeter;
}
//noktalarin dortgen olusturup olusturmadigini kontrol eder.
bool Quadrilateral::isValid() const
{
	//a-c ve b-d egimleri hesaplanir.
	double m1 = (c.y - a.y) / (c.x - a.x); 
	double m2 = (b.x - d.x) / (b.y - d.y);

	//egimlerin isaretleri birbirinden zitsa dortgen olusmaz.
	if (m1 < 0 && m2 > 0)
	{
		throw invalid_argument("Invalid Quadrilateral");
		return false;
	}
	else if (m1 > 0 && m2 < 0)
	{
		throw invalid_argument("Invalid Quadrilateral");
		return false;
	}
	else 
	{
		//isaret ayniysa true doner.
		return true;
	}
	
}
//a noktasini duzenler
bool Quadrilateral::setA(const Point & pt)
{
	//olusturulan bos nesne ile dortgen olusabildiyse a noktasinin koordinatlarina paramatrenin koordinatlari atanir.
	Quadrilateral temp{ pt , getB() , getC() , getD() };
	if (temp.isValid() != false)
	{
		return false;
	}
	else
	{
		//gelen parametre ile dortgen olusamadiysa constructor cagirilarak varsayilan dortgen olusturulur.
		a.x = pt.x;
		a.y = pt.y;
		return true;
	}
}
//b noktasini duzenler
bool Quadrilateral::setB(const Point & pt)
{
	//olusturulan bos nesne ile dortgen olusabildiyse b noktasinin koordinatlarina paramatrenin koordinatlari atanir.
	Quadrilateral temp{ getA() , pt , getC() , getD() };

	if (temp.isValid() != false)
	{
		return false;
	}
	else
	{
		//gelen parametre ile dortgen olusamadiysa constructor cagirilarak varsayilan dortgen olusturulur.
		b.x = pt.x;
		b.y = pt.y;
		return true;
	}
}
//c noktasini duzenler
bool Quadrilateral::setC(const Point & pt)
{
	// olusturulan bos nesne ile dortgen olusabildiyse c noktasinin koordinatlarina paramatrenin koordinatlari atanir.
	Quadrilateral temp{ getA() , getB() , pt , getD() };

	if (temp.isValid() != false)
	{
		return false;
	}
	else
	{
		//gelen parametre ile dortgen olusamadiysa constructor cagirilarak varsayilan dortgen olusturulur.
		c.x = pt.x;
		c.y = pt.y;
		return true;
	}
}
//d noktasini duzenler
bool Quadrilateral::setD(const Point & pt)
{
	// olusturulan bos nesne ile dortgen olusabildiyse d noktasinin koordinatlarina paramatrenin koordinatlari atanir.
	Quadrilateral temp{ getA() , getB() , getC() , pt };

	if (temp.isValid() != false)
	{
		return false;
	}
	else
	{
		//gelen parametre ile dortgen olusamadiysa constructor cagirilarak varsayilan dortgen olusturulur.
		d.x = pt.x;
		d.y = pt.y;
		return true;
	}
}
//nesnenin bilgilerini ekrana basar .
double Quadrilateral::printInfo() const noexcept
{
	cout << "Quadrilateral" << endl << "Number of corners: " << NUMBER_OF_CORNERS << endl;
	cout << "Points: (" << a.x << "," << a.y << ") " << "(" << b.x << "," << b.y << ") " << "(" << c.x << "," << c.y << ")" << "(" << d.x << "," << d.y << ")" << endl;
	cout << "Perimeter" << getPerimeter() << endl;
	cout << "Color " << &getColorAsString() << endl;
	return 0.0;
}
