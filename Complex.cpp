#include "Complex.h"
#include <iostream>
#include <string>

/*Karmaşık sayının varsayılan değeri sıfırdır.Ayrıca double değeri sınıfın objesine dönüştürür.(conversion constructor)*/
Complex::Complex(double newVal)
	/*Member initializer ile ilklendirme.Böylece değerler doğrudan atanır.*/
	:real{newVal}, img{0.0} ,myType{"double"} 
{
}
/*Aldığı int değeri sınıfın nesnesine dönüştüren conversion constructor.*/
Complex::Complex(int newVal)
	: img {0.0} , myType{ "int" }//Member initializer.
{
	real = (double)newVal; /*Otomatik casting 1 kez olduğu için type casting yaptık.*/
}
/*Aldığı parametreleri sınıfın objesine dönüştüren conversion constructor.*/
Complex::Complex(double a, double b)
	:real{a} , img{b} , myType{ "double" }//Member initializer.
{
	
}
/*Const tanımlı getter fonksiyonu veri üyelerini değiştirmeyecektir.*/
double Complex::getMyReal() const
{
	return real;
}
/*Const tanımlı getter fonksiyonu veri üyelerini değiştirmeyecektir.*/
double Complex::getMyİmg() const
{
	return img;
}
/*Veri üyelerini düzenleyen setter fonksiyonlar.*/
void Complex::setMyReal(double newReal)
{
	if (myType == "double")
	{
		real = newReal;
	}
	else
	{
		real = (double)newReal;
	}
}

void Complex::setMyİmg(double newİmg)
{
	if (myType == "double")
	{
		img = newİmg;
	}
	else
	{
		img = (double)newİmg;
	}
}
/*Aldığı karmaşık sayıyı kendisine ekler.*/
void Complex::add(const Complex & a)
{
	/*Kendisine ekler.*/
	 this->real += a.real;
	 this->img += a.img;

     //Ekleme sonucu oluşan karmaşık sayı ekrana bastırırlır.
	 cout << this->real << "+" << this->img << "i" << endl;
}
/*Aldığı karmaşık sayıyı kendisinden çıkarır.*/
 void Complex::subtract(const Complex & a)
 {
	 /*Kendisinden çıkarır.*/
	 this->real -= a.real;
	 this->img -= a.img;
	 
	 //Çıkarma sonucu oluşan karmaşık sayı ekrana bastırırlır.
	 cout << this->real << "+" << this->img << "i" << endl;
 }
 /*Aldığı karmaşık sayıyı kendisine böler.*/
 void Complex::divide(const Complex & a)
 {
	 /*Eğer böldüğümüz sayı 0 ise logic error fırlatılır.*/
	 if (a.real == 0 || a.img == 0)
	 {
		 throw logic_error("Division by zero!!!!");
	}
	 /*Değilse aldığı karmaşık sayıyı kendisine böler.*/
	 else 
	 {
		 this->real = this->real / a.real;
		 this->img = this->img / a.img;

		 //Bölme sonucu oluşan karmaşık sayı ekrana bastırırlır.
		 cout << this->real << "+" << this->img << "i" << endl;
	 }
 }
 /*Complex sınıfının objesi ekrana bastırılır.(üye fonksiyon)*/
 void Complex::printComplex()
 {
	 cout << real << "+" << img << "i" << endl;
 }
 /*Aldığı stringi Complex sınıfının objesine dönüştüren conversion constructor.*/
 Complex::Complex(const string & Com)
 {
	 
 }
