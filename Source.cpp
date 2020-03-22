#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <array>

using namespace std;

//aþaðýdaki satýrlarý yoruma alarak kodunuzu farklý þekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
* Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
* fonksiyonu cagri yapilmalidir.
*/
 long long recursiveFunction(int numberOfStones)
{
	 /*Dizinin artýþ miktarýný tuttuðum dizi*/
	 array <long, 71 > artis;
	 
	 /*Dizinin ilk 4 adýmýný ilklendirdim.*/
	 artis[0] = 0;
	 artis[1] = 1;
	 artis[2] = 2;
	 artis[3] = 3;

	 /*Artis miktari 2 ise bu ayni zamanda 2.adim degerine esittir.
	 1. base case*/
	 if (numberOfStones <= 2)
	 {
		 artis[numberOfStones] = numberOfStones;
		 return artis[numberOfStones];
	 }
	 /*Dizinin 3.adim degeri 4tur
	 2.base case*/
	 if (numberOfStones == 3)
	 {
		 artis[numberOfStones] = 4;
		 return artis[numberOfStones];
	 }

	 /*4'den daha buyukse artis miktarini hesapladim ve fonksiyonu tekrar cagirdim.*/
	 else
	 {
		 /*artis miktarlari arasindaki iliski ,kendinden3 sonraki artislarin toplamina esittir.*/
		 artis[numberOfStones-1] = artis[numberOfStones - 4] + artis[numberOfStones - 2] + artis[numberOfStones - 3];
		 return recursiveFunction(numberOfStones - 1) + artis[numberOfStones - 1];
	 }
	 
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
* Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
* Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
*/
long long iterativeFunction(int numberOfStones)
{
	array <long , 72> sonuc ;//Adimlarin degerini tutan dizi.
	array <long, 71 > artis;//Adimlar arasi artis miktarini tutan dizi.
		
	/*Dizilerimin ilk elemanlarini ilklendirdim*/
		sonuc[1] = 1;
		artis[1] = 1;
		artis[2] = 2;
		artis[3] = 3;
		/*4den kucukve 2 den farkli adimlar icin olusturdugum dongu*/
		for (auto i = 2; i <=4; ++i)		
		{
			sonuc[i] = sonuc[i - 1] + artis[i - 1];
		}

		/*4den buyuk adimlar icin artis miktarini hesaplayip buldugum
		degeri sonuca ekledim.*/
		for (auto i = 4; i <= numberOfStones; ++i)
		{
			artis[i] = artis[i - 1] + artis[i - 2]+artis[i-3];
			sonuc[i] = sonuc[i - 1] + artis[i - 1];
		}
		
	return sonuc[numberOfStones];//sonuc dizisinin elemanini dondurdum.
}



int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

	auto start = std::chrono::steady_clock::now();
		tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}