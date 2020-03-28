#include <iostream>
#include <vector>
#include <random>


#include "Triangle.h"
#include "Quadrilateral.h"

using namespace std;

// Rastgele olarak Triangle nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Triangle nesnelerinde yer alacak noktaların x ve y değerleri [0, 100] arasında olabilir.
Şeklin renk değeri de rastgele olarak belirlenmelidir.
*/
void fillTriangles(vector<Triangle> &v, int numberOfItems = 100)
{
	//random sayilar olusturduk.
	default_random_engine engine;
	uniform_int_distribution <double> distribution(0, numberOfItems); //0-100 arasi sayilar olusturur.
	uniform_int_distribution <int> colorRand(0, 5); //0-5 arasi sayilar olusturur.
	
	//10 adet nesne olusturacagiz rastgele olarak.
	for (auto i = 0; i < 10; ++i)
	{
			//Nokta olusturduk ve koordinatlarina rastgele 0-100 arasi sayilar atadik.
			Point aPoint;
			aPoint.x = distribution(engine);
			aPoint.y = distribution(engine);

			Point bPoint;
			bPoint.x = distribution(engine);
			bPoint.y = distribution(engine);

			Point cPoint;
			cPoint.x = distribution(engine);
			cPoint.y = distribution(engine);

			//Triangle::Color tipinde degisken.
			Triangle::Color colorRandom;
			//rastgele renk icin 0-5 arasi sayi aldik.
			int randomNumber = colorRand(engine);

			switch (randomNumber)
			{
			case 0:
				colorRandom = Triangle::Color::PINK;
				break;
			case 1:
				colorRandom = Triangle::Color::RED;
				break;
			case 2:
				colorRandom = Triangle::Color::BLUE;
				break;
			case 3:
				colorRandom = Triangle::Color::WHITE;
				break;
			case 4:
				colorRandom = Triangle::Color::BLACK;
				break;
			case 5:
				colorRandom = Triangle::Color::GREEN;
				break;
			}
			//rastgele nesne olusturduk.
			Triangle a{ aPoint , bPoint , cPoint , colorRandom};
			v.push_back(a); //olusan nesneyi vektore ekledik.
	}
}

// Rastgele olarak Quadrilateral nesneleri olusturur ve parametre olarak verilen vektore ekler.
/* Quadrilateral nesnelerinde yer alacak noktaların x ve y değerleri [0, 100] arasında olabilir.
Şeklin renk değeri de rastgele olarak belirlenmelidir.
*/
void fillQuads(vector<Quadrilateral> &v, int numberOfItems = 100)
{
	//random sayilar olusturduk.
	default_random_engine engine;
	uniform_int_distribution <double> distribution(0, numberOfItems); //0-100 arasi sayilar olusturur.
	uniform_int_distribution <int> colorRand(0, 4); //0-4 arasi sayilar olusturur.

	//10 adet nesne olusturacagiz rastgele olarak.
	for (auto i = 0; i < 10; ++i)
	{
		//Nokta olusturduk ve koordinatlarina rastgele 0-100 arasi sayilar atadik.
		Point aPoint;
		aPoint.x = distribution(engine);
		aPoint.y = distribution(engine);

		Point bPoint;
		bPoint.x = distribution(engine);
		bPoint.y = distribution(engine);

		Point cPoint;
		cPoint.x = distribution(engine);
		cPoint.y = distribution(engine);

		Point dPoint;
		dPoint.x = distribution(engine);
		dPoint.y = distribution(engine);

		//Triangle::Color tipinde degisken.
		Quadrilateral::Color colorRandom;
		//rastgele renk icin 0-4 arasi sayi aldik.
		int randomNumber = colorRand(engine);

		switch (randomNumber)
		{
		case 0:
			colorRandom = Quadrilateral::Color::RED;
			break;
		case 1:
			colorRandom = Quadrilateral::Color::BLUE;
			break;
		case 2:
			colorRandom = Quadrilateral::Color::WHITE;
			break;
		case 3:
			colorRandom = Quadrilateral::Color::BLACK;
			break;
		case 4:
			colorRandom = Quadrilateral::Color::GREEN;
			break;
		}
		//rastgele nesne olusturduk.
		Quadrilateral a{ aPoint , bPoint , cPoint , dPoint ,  colorRandom };
		v.push_back(a);//olusan nesneyi vektore ekledik.
}


/* Verilen Triangle veya Rectangle vektörününde çevre uzunluğu ve renk değeri eşleşen ilk elemanın indeksini döndürür.
Eleman bulunamazsa -1 döndürülür.*/
template<class T>
int search(const vector<T> &v, const T & key)
{
	for (auto i = 0; i < v.size(); ++i)
	{
		//cevre uzunlugu ve rengi ayni ise o indexin degerini dondurduk.
		if ( v[i].getPerimeter() == key.getPerimeter() && v[i].color == key.color)
		{
			return i;
			break;
		}
		
	}
	//yoksa -1 dondurduk
	return -1;
}


template<class T>
int sortByPerimeter(vector<T> &v)
{
	T temp; //bos degisken
	//kucukten buyuge siralama
	for (auto i = 0; i < v.size() - 1; ++i)
	{
		for (auto j = i + 1; i < v.size(); ++i)
		{
			if (v[j].getPerimeter() < v[i].getPerimeter)
			{
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}


}

int main()
{

	// Point class test
	auto p = Point{ 4.5, 6.2 };

	cout << p.x << " " << p.y << endl;
	cout << p.coords[0] << " " << p.coords[1] << endl;

	// Sample Quad and Triangle Objects
	auto sampleQuad = Quadrilateral{ Point(4, 5), 20, 20 };
	cout << "Color of Sample Quad:" << sampleQuad.getColorAsString() << endl;

	auto sampleTriangle = Triangle{ Point(4, 5),  Point(9, 5),  Point(14, 15) };
	cout << "Color of Sample Triangle:" << sampleTriangle.getColorAsString() << endl;


	// Filling vectors randomly
	auto vectorOfQuads = vector<Quadrilateral>{};
	auto vectorOfTriangles = vector<Triangle>{};

	fillTriangles(vectorOfTriangles);
	fillQuads(vectorOfQuads);

	// Search sample objects in the corresponding vectors
	cout << "Searching a triangle...\n";
	cout << sampleTriangle.printInfo() << endl;
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;

	cout << "Searching a quadrilateral...\n";
	cout << sampleQuad.printInfo() << endl;
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Add sample Triangle object to the vector and sort the vector
	vectorOfTriangles.push_back(sampleTriangle);
	sortByPerimeter(vectorOfTriangles);


	// Search sample item again. Now, you must have a hit.
	cout << "Searching a triangle...\n";
	cout << sampleTriangle.printInfo() << endl;
	if (auto idx = search(vectorOfTriangles, sampleTriangle) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;



	// Add sample Quad object to the vector and sort the vector
	vectorOfQuads.push_back(sampleQuad);
	sortByPerimeter(vectorOfQuads);

	// Search sample item again. Now, you must have a hit.
	cout << "Searching a quadrilateral...\n";
	cout << sampleQuad.printInfo() << endl;
	if (auto idx = search(vectorOfQuads, sampleQuad) >= 0)
		cout << "A similar object is found at index-" << idx << endl;
	else cout << "No similar object can be found" << endl;


	// Invalid cases
	try
	{
		auto invalidTriangle1 = Triangle{ Point{ 4, 0 },  Point{ 9, 0 },  Point{ 14, 0 } };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle2 = Triangle{ Point{ 4, 4 },  Point{ 4, 4 },  Point{ 4, 4 } };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidTriangle3 = Triangle{ Point{ 4, 0 },  Point{ 4, 4 },  Point{ 4, 14 } };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid triangle: " << ex.what() << endl;
	}

	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{ 4, 0 },  Point{ 9, 0 },  Point{ 14, 0 }, Point{ 0, 0 } };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad1 = Quadrilateral{ Point{ 4, 0 },  Point{ 9, 0 },  Point{ 14, 0 }, Point{ 0, 0 } };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}


	try
	{
		auto invalidQuad2 = Quadrilateral{ Point{ 4, 0 },  Point{ 9, 0 },  Point{ 3, 20 }, Point{ 10, 20 } };
	}
	catch (invalid_argument & ex)
	{
		cout << "Invalid Quad: " << ex.what() << endl;
	}

	return 0;
}
