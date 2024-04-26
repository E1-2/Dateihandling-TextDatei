#include <iostream> // alt: input / output-stream
#include <string>
#include <fstream> // NEU: file-stream
using namespace std;

int main()
{
// Dateizeiger
	ofstream dateiZeigerZumSpeichern;  
	// output >> immer aus der Sicht des C++ Programmes >> Vom Programm in die Datei 
	ifstream dateiZeigerZumEinlesen;   
	// input >> immer aus der Sicht des C++ Programmes >> eine Datei einlesen in das Programm
	fstream dateiZeigerFlexibel; 
	// in- und output >> am Anfang nicht zu empfehlen, 
	// da du ja die verschiedenen Richtungen lernen sollst. 

// Daten
	char zeichen = 'A';
	int anzahl = 42;
	char cstring[6] = "Hallo";
	string zeichenkette = "Welt";
	double preis = 999.99;
	
// Speichern in die Datei
	dateiZeigerZumSpeichern.open("Text.txt", ios::out);
	if (!dateiZeigerZumSpeichern.good()) {
		cout << "Datei defekt!" << endl; 
	}
	cout <<  zeichen << '\t' << anzahl << '\t' << cstring << '\n' << zeichenkette << '\t' << preis << endl;
	dateiZeigerZumSpeichern << zeichen << '\t' << anzahl << '\t' << cstring << '\n' << zeichenkette << '\t' << preis;
	dateiZeigerZumSpeichern.close();

// Lesen aus einer Datei
	string zwischenspeicher;
	dateiZeigerZumEinlesen.open("Text.txt", ios::in);
	
	while (!dateiZeigerZumEinlesen.eof()) {
		getline(dateiZeigerZumEinlesen, zwischenspeicher, '\t');
		// alles Ausgeben >> eher selten
		//cout << zwischenspeicher << endl;

		// WERT einlesen in eine andere Variable
		// char 
		char z = zwischenspeicher[0];
		cout << z << endl;

		// int
		getline(dateiZeigerZumEinlesen, zwischenspeicher, '\t');
		int a = stoi(zwischenspeicher);
		cout << a << endl;

		// cstring
		getline(dateiZeigerZumEinlesen, zwischenspeicher, '\n');
		char cstr[6] = { 0 }; // Die Groesse des cstrings muss bekannt sein.
		strcpy_s(cstr, zwischenspeicher.c_str());
		cout << cstr << endl;

		//string
		getline(dateiZeigerZumEinlesen, zwischenspeicher, '\t');
		string zk = zwischenspeicher;
		cout << zk << endl;

		// double
		getline(dateiZeigerZumEinlesen, zwischenspeicher);
		double p = stod(zwischenspeicher);
		cout << p << endl;
	}
	dateiZeigerZumEinlesen.close();
	
	return 0;
}

