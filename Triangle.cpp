#include "Triangle.h"
#include "Point.h"
#include <iostream>
//constructorlarda olusturulan nesnenin uye fonksiyonu(isValid) cagirilarak kontrol yapildi.

//default constructor .
Triangle::Triangle(const Point & a, const Point & b, const Point & c, const Color & color) 
	:pts{ a , b, c }, color{ color } //member initializer
{
	 this->isValid();
}
//2 parametreli constructor. Aldigi parametrelerle triangle nesnesi olusturur.
Triangle::Triangle(const vector<Point>& pts, const Color & color) 
	: color{ color } , pts { pts[0] , pts[1] , pts[2] } //member initializer
{
	this->isValid();
}
//2 parametreli constructor.  Aldigi parametrelerle triangle nesnesi olusturur.
Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color & color) 
	: pts { pts[0] , pts[1] , pts[2] } , color { color } //member initializer
{
	this->isValid();
}

//getter function
Point Triangle::getA() const noexcept
{
	return a;
}
//getter function
Point Triangle::getB() const noexcept
{
	return b;
}
//getter function
Point Triangle::getC() const noexcept
{
	return c;
}
//getter function
Triangle::Color Triangle::getColor() const noexcept
{
	return color;
}
//getter function
string Triangle::getColorAsString() const noexcept
{
	//color a gore string dondurur.
	switch (color)
	{
	case Triangle::Color::PINK:
		return "Pink"; break;
	case Triangle::Color::RED:
		return "Red"; break;
	case Triangle::Color::BLUE:
		return "Blue"; break;
	case Triangle::Color::WHITE:
		return "White"; break;
	case Triangle::Color::BLACK:
		return "Black"; break;
	case Triangle::Color::GREEN:
		return "Green"; break;
	default:
		return "Green"; break;
	}
}
//ucgenin cevresini hesaplar.
double Triangle::getPerimeter() const noexcept
{
	//kenar uzunluklari hesaplanir.
	double side1 = a.distanceTo(b);
	double side2 = b.distanceTo(c);
	double side3 = c.distanceTo(a);

	//cevreyi hesapladik.
	double perimeter = side1 + side2 + side3;

	return perimeter;
}
//a noktasini duzenler
bool Triangle::setA(const Point & pt) 
{
	Triangle temp{ pt , getB() , getC() };

	//olusturulan bos nesne ile ucgen olusabildiyse a noktasinin koordinatlarina paramatrenin koordinatlari atanir.
	if (temp.isValid() != false)
	{
		a.x = pt.x; 
		a.y = pt.y;
		return true;
	}
	else
	{
		//gelen parametre ile ucgen olusamadiysa constructor cagirilarak varsayilan ucgen olusturulur.
		Triangle();
		return false;
	}
}
//b noktasini duzenler
bool Triangle::setB(const Point & pt)
{
	//olusturulan bos nesne ile ucgen olusabildiyse a noktasinin koordinatlarina paramatrenin koordinatlari atanir.
	Triangle temp{ getA() , pt , getC() };

	if (temp.isValid() != false)
	{
		b.x = pt.x;
		b.y = pt.y;
		return true;
	}
	else
	{
		//gelen parametre ile ucgen olusamadiysa constructor cagirilarak varsayilan ucgen olusturulur.
		Triangle();
		return false;
	}
}
//c noktasini duzenler
bool Triangle::setC(const Point & pt)
{
	//olusturulan bos nesne ile ucgen olusabildiyse a noktasinin koordinatlarina paramatrenin koordinatlari atanir.
	Triangle temp{ getA(), getB() , pt };

	if (temp.isValid() != false)
	{
		c.x = pt.x;
		c.y = pt.y;
		return true;
	}
	else
	{
		//gelen parametre ile ucgen olusamadiysa constructor cagirilarak varsayilan ucgen olusturulur.
		Triangle();
		return false;
	}
}
//noktalarin ucgen olusturup olusturmadigini kontrol eder.
bool Triangle::isValid() const
{
	//kenar uzunluklarihesaplanir.
	double side1 = a.distanceTo(b);
	double side2 = b.distanceTo(c);
	double side3 = c.distanceTo(a);

	//eld edilen kenar uzunlugu diger iki kenar uzunlugunun toplamindan buyukse ucgen sartini saglamaz.
	if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
	{
		//expection firlatir.
		throw invalid_argument("Invalid Triangle");
		return false;
	}
	else
	{
		//sart saglanirsa true dondurur.
		return true;
	}
}
//nesnenin bilgilerini ekrana basar .
double Triangle::printInfo() const noexcept
{
	cout << "Triangle" << endl << "Number of corners: " << NUMBER_OF_CORNERS << endl;
	cout << "Points: (" << a.x << "," << a.y << ") " << "(" << b.x << "," << b.y << ") " << "(" << c.x << "," << c.y << ")" << endl;
	cout << "Perimeter" << getPerimeter() << endl;
	cout << "Color " << &getColorAsString() <<endl;

	return 0.0;
}

