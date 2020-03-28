#pragma once
#include <array>
#include <vector>

#include "Point.h"
using namespace std;

class Triangle
{
public:
	constexpr static int NUMBER_OF_CORNERS{ 3 };
	enum class Color { PINK, RED, BLUE, WHITE, BLACK, GREEN };

	// Constructor
	Triangle(const Point & a = { 1, 0 }, const Point & b = { 0, 1 }, const Point & c = { 2, 1 }, const Color & color = Color::RED);
	Triangle(const vector<Point> & pts, const Color & color = Color::RED);
	Triangle(const array<Point, NUMBER_OF_CORNERS> & pts, const Color & color = Color::RED);
	
	const Point & a = pts[0];
	Point & b = pts[1];
	Point & c = pts[2];

	// Getter Functions
	Point getA() const noexcept; 
	Point getB() const noexcept; 
	Point getC() const noexcept; 

	Color getColor() const noexcept;
	string getColorAsString() const noexcept;

	double getPerimeter() const noexcept;

	// Setter Functions
	bool setA(const Point & pt); 
	bool setB(const Point & pt); 
	bool setC(const Point & pt);

	/* Ucgen olup olmadığını kontrol eder.
	 * Bu fonksiyonun tüm yapıcılar ve setter fonksiyonlar içinde doğrudan/dolaylı olarak çağrılması zorunludur.
	 * Eğer verilen değerler bir üçgen oluşturmuyorsa invalid_argument exception fırlatılmalı ve bu bu exception kontrol edilmelidir
	 * Program sonlandırılmamalıdır.
	 */
	bool isValid() const;

	double printInfo() const noexcept;
	// Ekrana şunu basar:
	/* Triangle
	   Number of points: 3
	   Points: (3.00, 4.40), (2.00, 5.00), (4.80, 5.00)
	   Primeter: 5.86
	   Color: Red
	*/
private:
	array<Point, NUMBER_OF_CORNERS> pts; 
	Color color;
};
