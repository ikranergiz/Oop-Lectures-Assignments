#pragma once
#include <array>
#include <string>
#include <map>
#include "Point.h"

using namespace std;

class Quadrilateral
{
public:
	constexpr static int NUMBER_OF_CORNERS { 4 };
	enum class Color {RED, BLUE, WHITE, BLACK, GREEN};
	static const map<Quadrilateral::Color, string> colorToStringMap;

	// Constructors

	// Bir dikdörtgen/kare oluşturur a her zaman sol üst noktayı, c her zaman sağ alt noktayı gösterir
	Quadrilateral(const Point & a = { 0, 0 }, const Point & c = { 1, 1 }, const Color & color = Color::GREEN);

	// Verilen en ve boy değerlerine uygun olarak bir dikdörtgen/kare oluşturur a her zaman sol üst noktayı gösterir
	Quadrilateral(const Point & a, double width, double height, const Color & color = Color::GREEN);

	// Verilen noktalara göre dörtgen oluşturur. Bu noktaların bir dörtgen oluşturduğu kontrol edilmeldir.
	Quadrilateral(const Point & a, const Point & b, const Point & c, const Point & d, const Color & color = Color::GREEN);
	Quadrilateral(const array<Point, NUMBER_OF_CORNERS> & pts, const Color & color = Color::GREEN);

	// Referanslar
	Point & a = pts[0];
	Point & b = pts[1];
	Point & c = pts[2];
	Point & d = pts[3];

	// Getter Functions
	Point getA() const noexcept; 
	Point getB() const noexcept; 
	Point getC() const noexcept; 
	Point getD() const noexcept; 

	// Dörtgenin rengini string olarak dönderir
	Color getColor() const noexcept;
	string getColorAsString() const noexcept; 

	// Dörtgenin çevresini hesaplar ve gönderir
	double getPerimeter() const noexcept;


	/* Dörtgen olup olmadığını kontrol eder.
	 * Bu fonksiyonun tüm yapıcılar ve setter fonksiyonlar içinde doğrudan/dolaylı olarak çağrılması zorunludur.
	 * Eğer verilen değerler bir dörtgen oluşturmuyorsa invalid_argument exception fırlatılmalı ve bu bu exception kontrol edilmelidir
	 * Program sonlandırılmamalıdır.
	 */
	bool isValid() const;

	// Setter Functions
	bool setA(const Point & pt); 
	bool setB(const Point & pt); 
	bool setC(const Point & pt); 
	bool setD(const Point & pt); 

	double printInfo() const noexcept;
	// Ekrana şunu basar:
	/* Rectangle
	   Number of points: 4
	   Points: (3.00, 4.40), (3.00, 5.00), (3.80, 5.00), (3.80, 4.40)
	   Priperhal: 2.80
	   Color: Red
	*/
private:
	array<Point, NUMBER_OF_CORNERS> pts; 
	Color color;
};
