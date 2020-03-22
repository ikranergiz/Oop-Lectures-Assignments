#pragma once
#include <string>

using namespace std;

/*Karmaşık sayıları ifade eden sınıf.*/
class Complex
{
public:

	/*Bir double değeri Complex sınıfının nesnesine dönüştüren conversion constructor.
	Varsayılan değer atandığı için default constructor.*/
	Complex(double newVal = 0.0);
	/*Bir int değeri Complex sınıfının bir objesine dönüştüren conversion constructor.*/
	explicit Complex(int newVal);
	/*2 parametreli constructor.Aldığı double değerleri ile Complex sınıfının bir objesini oluştur.*/
	explicit Complex(double a, double b);
	/*Bir stringi Complex sınıfının objesine dönüştüren conversion constructor.*/
	Complex(const string & Com);

	/*Veri üyelerine erişim için getter fonksiyonlar.*/
	double getMyReal() const;
	double getMyİmg() const;

	/*Veri üyelerini düzenlemek için setter fonksiyonlar.*/
	void setMyReal(double newReal);
	void setMyİmg(double newİmg);

	/*Aldığı Complex sınıfı objesini kendisine ekleyen add fonksiyonu.*/
	void add(const Complex &a);
	/*Aldığı Complex sınıfı objesini kendisinden çıkaran subtract fonksiyonu.*/
	void subtract(const Complex &a);
	/*Aldığı Complex sınıfı objesini kendisine bölen divide fonksiyonu.*/
	void divide(const Complex &a);

	/*Sınıfın objesini ekrana basan üye fonksiyon.*/
	void printComplex();

private:

	/*Private veri üyeleri.*/
	double real;
	double img;
	string myType;

};
