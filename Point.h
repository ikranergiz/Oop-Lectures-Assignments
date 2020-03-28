#pragma once
#include <array>

// !!!!!!!!!!!!!!!! BU SAYFADA DUZENLEME YAPMAYINIZ !!!!!!!!!!!!!!!!

using namespace std;

// 2-boyutlu bir uzayda bir noktanın gösterilmesini sağlayan yapı (struct)
typedef struct Point_st {
	/* Sınıflarda varsayılan erişim düzenleyicisi (access modifier) PRIVATE, 
	 * yapılarda ise PUBLIC olarak tanımlıdır.
	 */	
	array<double, 2> coords;

	// Noktanın x, ve y konumlarına farklı bir şekilde erişim imkanı sağlanmıştır
	double & x = coords[0]; // Referanslar ya burada yapıldığı gibi tanımlandığında ilklendirilmeli ya da üye ilklendirme söz dizimi içinde bu işlem yapılmalıdır 
	double & y = coords[1]; // Sonrasında referansın gösterdiği yer değiştirilemez ama gösterdiği yerdeki değer değiştirilebilir.

	// Diğer bir nokta ile Euclidean uzaklığını veren bir üye fonksiyon
	inline double distanceTo(const Point_st & other) const
	{
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	/* Yapılarda da constructor ve diğer üye fonksiyonları/operatörleri tanımlayabilirsiniz.
	 * Aşağıdaki yapici fonksiyonlarda uye ilklendirme soz dizimi kullanmaktadir ve 
	 * bu fonksiyonlar boş bir ana bloğa sahiptirler.
	 */
	Point_st(double x = 0, double y = 0) : coords{ x , y } //, x{ coords[0] }, y{ coords[1] } //Yukarıda verilen ilklendirmeyi kapatıp referansları burada da ilklendirebilirsiniz.
	{ 
		/* Bilerek boş bırakılmıştır. */ 
	}	

	// Dönüştüren yapıcı
	Point_st(const array<double, 2> & coords) : coords{ coords }//, x{ this->coords[0] }, y{ this->coords[1] }  //Yukarıda verilen ilklendirmeyi kapatıp referansları burada da ilklendirebilirsiniz.
	{ 
		/* Bilerek boş bırakılmıştır. */
	}
} Point;
