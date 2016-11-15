#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cmath> 

template<typename T>
std::string to_string(const T& value)
{
    std::ostringstream stream;
    stream << value;
    return stream.str();
} //to string fix

//Teilaufgabe a)

int weekday2001(int d, int m, int y){
	int z, j1, w;
	int p = 0;
	int schalt = 0;
	std::string Tag;
	
	z = y - 2001;
	j1 = ( 365*z + (z/4) - (z/100) + (z/400) ) % 7;
	
	(y%400 == 0) ? schalt = 1
		:(y%100 == 0)? schalt = 0
			:(y%4 == 0)? schalt = 1
				: schalt = 0;	
	
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(/*m > 2 &&*/ schalt == 0)? p = d + 59 + ((153*m - 457) / 5) : 
				/*(m > 2 && schalt == 1)?*/ p = d + 60 + ((153*m - 457) / 5);
	
	w = (j1 + p -1) % 7;
	
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	std::cout << "Durch weekday2001: " << to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
	
	return w ;
}


//Teilaufgabe b)

int floorDiv(int a, int b){
	int test, r;
	int c = std::abs(b) - 1;
	test = a / b;
	(test > 0)? r = a / b
		: r = ( -( (std::abs(a) + c) / std::abs(b) ) ); 
	return r;
}
/* Welchen Wert hat c in Abhängigkeit von a und b?
	Eigentlich sollte c in diesem Fall c = a%b entsprechen, wobei floorMod verwendet wird
	Dies kann in dieser Funktion nicht implementiert werden (Fehler: "floorMod was not declared in this scope"), 
	weil C++ alles "von oben nach unten" ausführt.
	Deswegen haben wir c als c = |b| - 1 gesetzt. Dies ist möglich, da ((|a| + c) / b) für jede Zahl genau in den Bereich der
	Zahl "drüber" kommt (z.B. 2,4 --> 3). Im negativen wird -((|a| + c) / b) dadurch immer abgerundet
*/

//Teilaufgabe c)

int floorMod(int a, int b) {
	int r;
	r = a - b * floorDiv (a,b);
}  
/*Wie unterscheidet sich floorMod () von der %-operation in c++? (aufgabe 2c)
	floorMod kann auch das richtige Modulo von negativen Zahlen rechnen z.B. -12%5 = 3
	die %-Operation kann dies nicht: -12%5 wird als -2 ausgegeben, es wird also -(12%5) gerechnet
*/


//Teilaufgabe d)

int weekday(int d, int m, int y){
	int z, j1, w;
	int p = 0;
	int schalt = 0;
	std::string Tag;
	
	z = y - 2001;
	j1 = floorMod(( 365*z + floorDiv(z,4) - floorDiv(z,100) + floorDiv(z,400) ) , 7) ;
	
	(floorMod(y, 400) == 0) ? schalt = 1
		:(floorMod(y, 100) == 0)? schalt = 0
			:(floorMod(y, 4) == 0)? schalt = 1
				: schalt = 0;	
	
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(/*m > 2 &&*/ schalt == 0)? p = d + 59 + floorDiv((153*m - 457), 5) : 
				/*(m > 2 && schalt == 1)?*/ p = d + 60 + floorDiv((153*m - 457), 5);
	
	w = floorMod ( (j1 + p - 1) , 7);
	
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	std::cout << "Durch weekday: " << to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
	
	return w ;
}


//Teilaufgabe e)

/* Warum funktioniert das auch mit z = y - 1?
	Alle 400 Jahre (z.B. 401, 801, 1201, 1601 und 2001 (aufgabe 2a))  beginnt das Jahr mit einem Montag. Was bedeutet,
	dass nach 2000 Jahren auch wieder ein Montag an diesem Datum ist. 
	Daher kann man auch y - 1 schreiben, da 2000 Jahre früher der gleiche Tag am gleichen Datum war.
	
*/

int weekday1(int d, int m, int y){
	int z, j1, w;
	int p = 0;
	int schalt = 0;
	std::string Tag;
	
	z = y - 1;
	j1 = ( 365*z + (z/4) - (z/100) + (z/400) ) % 7;
	
	(y%400 == 0) ? schalt = 1
		:(y%100 == 0)? schalt = 0
			:(y%4 == 0)? schalt = 1
				: schalt = 0;	
	
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(/*m > 2 &&*/ schalt == 0)? p = d + 59 + ((153*m - 457) / 5) : 
				/*(m > 2 && schalt == 1)?*/ p = d + 60 + ((153*m - 457) / 5);
	
	w = (j1 + p -1) % 7;
	
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	std::cout << "Durch weekday1: "<< to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
	
	return w ;
}

int main () {
	int d, m, y;
	/*
	std::cout << "Geben sie den Tag ein" << std::endl;
	std::cin >> d;
	std::cout << "Geben sie den Monat ein" << std::endl;
	std::cin >> m;
	std::cout << "Geben sie die Jahreszahl ein" << std::endl;
	std::cin >> y;
	
	weekday2001(d, m, y);
	weekday(d, m, y);
	weekday1(d, m, y);
	*/ 
	
	std::cout << " " << std::endl; //zur besseren Übersicht im Terminal
	
	//Teilaufgabe a)
	std::cout << "Teilaufgabe a)" << std::endl;
    assert(weekday2001(10, 11, 2016)==3);
    assert(weekday2001(1, 1, 2001)==0);
    assert(weekday2001(31, 8, 2098)==6);
    assert(weekday2001(31, 8, 1998)!=0); //für Tage vor 2001 kommt ein falsches Ergebnis raus
    std::cout << " " << std::endl;
	
    //Teilaufgabe b)
    assert(floorDiv(-12,5) == -3);
    assert(floorDiv(12,-5) == -3);
    assert(floorDiv(-17,9) == -2);
    assert(floorDiv(17,-9) == -2);
  
    //Teilaufgabe c)
	assert(floorMod(-12,5) == 3);
    assert(floorMod(12,-5) == -3);
    assert(floorMod(-17,9) == 1);
    assert(floorMod(17,-9) == -1);
    
   //Teilaufgabe d)
	std::cout << "Teilaufgabe d)" << std::endl;
    assert(weekday(10, 11, 2016)==3);
    assert(weekday(1, 1, 2001)==0);
    assert(weekday(31, 8, 2098)==6);
    assert(weekday(6, 9, 1998)==6);
    assert(weekday(29, 2, 2016)==0);
    assert(weekday(31, 8, 1998)==0);
    assert(weekday(24, 12, 2000)==6);
    assert(weekday(20, 1, 1583)==3);
    assert(weekday(5, 11, 1605)==5);
    assert(weekday(13, 1, 2017)==4);
    assert(weekday(31, 10, 1666)==6);
    assert(weekday(12, 9, 1964)==5);
    assert(weekday(22, 2, 2022)==1);
    assert(weekday(14, 11, 2016)==0);
    assert(weekday(6, 6, 6666)==2);
    assert(weekday(26, 4, 1701)==1);
	std::cout << " " << std::endl;

    //Teilaufgabe e)
	std::cout << "Teilaufgabe e)" << std::endl;
    assert(weekday1(10, 11, 2016)==3);
    assert(weekday1(1, 1, 2001)==0);
    assert(weekday1(31, 8, 2098)==6);
    assert(weekday1(6, 9, 1998)==6);
    assert(weekday1(29, 2, 2016)==0);
    assert(weekday1(31, 8, 1998)==0);
    assert(weekday1(24, 12, 2000)==6);
    assert(weekday1(20, 1, 1583)==3);
    assert(weekday1(5, 11, 1605)==5);
    assert(weekday1(13, 1, 2017)==4);
    assert(weekday1(31, 10, 1666)==6);
    assert(weekday1(12, 9, 1964)==5);
    assert(weekday1(22, 2, 2022)==1);
    assert(weekday1(14, 11, 2016)==0);
    assert(weekday1(6, 6, 6666)==2);
    assert(weekday1(26, 4, 1701)==1);
	std::cout << " " << std::endl;
	
}