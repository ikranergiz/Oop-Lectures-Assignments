/*Bu program kamaşık sayıları ifade eden sınıf içerir.
Bu sınıfın üye fonksiyoları ile karmaşık sayıyı kendine ekleyen ,çıkaran ya da bölen fonksiyonları kullanabiliriz.
Karmaşık sayıyı ekrana basmak için hem üye hem de global fonksiyon içerir.*/

#include "Complex.h"
#include <iostream>
#include <exception>

using namespace std;

//Fonksiyon prototipi.
void printComplex(const Complex & com);

int main()
{
	/*Main içerisinde fonksiyonları çağırarak işlemler yaptık.*/
	constexpr int i = 10;
	Complex num{i};

	num.printComplex();
	cout << endl;

	Complex a{ 5.6 }, b{ 3.9 };
	cout << "a:" << a.getMyReal() << endl;
	cout << "b:" << b.getMyReal() << endl;
	
	cout << "a = a+b isleminin sonucu: ";
	a.add(b);
	cout << endl;

	cout << "a: ";
	a.printComplex();
	cout << endl;

	Complex x{ 4.42,2.22 };
	Complex y{ 2.22,1.12 };

	cout << "y:" << y.getMyReal() << endl;
	y.add(x);

	cout << "islem sonucu y:" << y.getMyReal() << endl;
	cout << endl;
	
	Complex c{ 15 }, d{ 5 };

	cout << "setter fonksiyonu cagirilmadan once elimizde olan c:" << endl;
	c.printComplex();
	cout << endl;

	cout << "setter fonksiyonu cagirilmadan once elimizde olan c:" << endl;
	d.printComplex();
	cout << endl;

	c.setMyİmg(10);
	cout << "setter fonksiyonu cagirarak elde edilen c:" << endl;
	c.printComplex();
	d.setMyİmg(1);
	cout << "setter fonksiyonu cagirarak elde edilen d:" << endl;
	d.printComplex();
	cout << endl;
	
	cout << "karmasik sayi x:" << endl;
	x.printComplex();
	cout << "karmasik sayi c:" << endl;
	c.printComplex();
	cout << "x = x - c:" << endl;
	c.subtract(x);
	cout << "islem sonucu x:" << endl;
	x.printComplex();
	cout << endl;
	
	cout << "karmasik sayi a reel kisim:" << a.getMyReal() << endl;
	cout << "karmasik sayi a sanal kisim:" << a.getMyİmg()<< endl;
	cout << "karmasik sayi b reel kisim:" << b.getMyReal() << endl;
	cout << "karmasik sayi b sanal kisim:" << b.getMyİmg()<< endl;

	a.setMyReal(10);
	b.setMyReal(2);
	a.setMyİmg(1);
	b.setMyİmg(1);

	cout << "setter fonksiyonlarin cagirilmasi ile elde edilen sayilar :" << endl;
	cout << "a:"; 
	a.printComplex();
	cout << endl;

	cout << "b:";
	b.printComplex();
	cout << endl;

	cout << "a = a/b isleminin sonucu: " << endl;
	a.divide(b);
	cout << endl;

	cout << "islem sonucu a :" << a.getMyReal()<< "+" << a.getMyİmg()<< "i" << endl;
	
	/*Bölme işleminde 0'a bölmeye hatası alma ihtimalimiz olduğundan deneyeceğiz.*/
	try
	{
		cout << "y:";
		y.printComplex();
		cout << endl;

		Complex q{};
		cout << "q:";
		q.printComplex();
		cout << endl;

		cout << "y = y/q isleminin sonucu: " << endl;
		y.divide(q);
		cout << endl;
	}
	 /*0'a bölme hatası olursa hata yakalayacağız.*/
	catch (logic_error &e)
	{
		cout << "logic_error : " << e.what() << endl;
	}
	/*Tanımlanamayan hatalar olursa.*/
	catch (...)
	{
		cout << "Undefined Exception: " << endl;
	}

	return 0;
}

/*Karmaşık sayıyı ekrana bastıran global fonksiyon.*/
void printComplex(const Complex & com)
{
	cout << com.getMyReal() << "+" << com.getMyİmg() << "i" << endl;
}
