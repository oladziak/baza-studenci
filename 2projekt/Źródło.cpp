#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<fstream>
using namespace std;

struct student {
	int id;
	string nazwisko;
	string specjalnosc;
	float srednia;
	student(int id_, string nazwisko_, string specjalnosc_, float srednia_);
};
student::student(int id_, string nazwisko_, string specjalnosc_, float srednia_)
{
	cout << "Dodano nowego studenta do bazy."<<endl;
	id = id_;
	nazwisko = nazwisko_;
	specjalnosc = specjalnosc_;
	srednia = srednia_;
}
void dodaj(vector <student> &tab, int &ktory)
{
	system("cls");
	ktory++;
	cout << "Podaj nazwisko studenta: " << endl;
	string nazw;
	cin >> nazw;
	cout << "Podaj specjalnosc studenta: " << endl;
	string specj;
	cin >> specj;
	cout << "Podaj srednia studenta: " << endl;
	float srednia;
	cin >> srednia;
	tab.push_back(student(ktory, nazw, specj, srednia));
	system("cls");
}
void usun(vector<student> &tab, int ktory)
{
	tab.erase(tab.begin() + ktory);
}
void wyswietl(vector<student> tab)
{
	if(tab.size()==0)
	{
		cout << "W bazie nie ma jeszcze zadnych studentow."<<endl;
	}
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i].id<<" " << tab[i].nazwisko<<" " << tab[i].specjalnosc<<" " << tab[i].srednia << endl;
	}
}
void szukaj(vector <student> tab)
{
	int wybor;
	int a= 0;
	int idd;
	string nazw;
	string spec;
	float sr;
	int i = 0;
	cout << "\nPo ktorej wartosci szukaæ?(id->1, nazwisko->2, specjalnosc->3, srednia->4 " << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		cout << "Podaj numer id szukanego studenta: ";
		cin >> idd;
		idd--;
		if (idd < tab.size())
		{
			cout << tab[idd].id << " " << tab[idd].nazwisko << " " << tab[idd].specjalnosc<<" " << tab[idd].srednia << endl;
		}
		else
		{
			cout << "Brak takiego numeru id w bazie studentow." << endl;
		}
		break;
	case 2:
		cout << "Podaj nazwisko szukanego studena: ";
		cin >> nazw;
		cout << endl;
		for (int i = 0; i < tab.size(); i++)
		{
			if (tab[i].nazwisko == nazw)
			{
				a++;
				cout << tab[i].id << " " << tab[i].nazwisko << " " << tab[i].specjalnosc << " " << tab[i].srednia << endl;
			}
		}
		if (a == 0)
		{
			cout << "W bazie nie ma studentow o podanym nazwisku." << endl;
		}
		break;
	case 3:
		cout << "Podaj specjalnosc szukanego student: ";
		cin >> spec;
		for (int i = 0; i < tab.size(); i++)
		{
			if (tab[i].specjalnosc == spec)
			{
				a++;
				cout << tab[i].id << " " << tab[i].nazwisko << " " << tab[i].specjalnosc << " " << tab[i].srednia << endl;
			}
		}
		if (a == 0)
		{
			cout << "W bazie nie ma studentow o podanej specjalnosci." << endl;
		}
		break;
	case 4:
		cout << "Podaj srednia szukanego studenta: ";
		cin >> sr;
		for (int i = 0; i < tab.size(); i++)
		{
			if (tab[i].srednia == sr)
			{
				a++;
				cout << tab[i].id << " " << tab[i].nazwisko << " " << tab[i].specjalnosc << " " << tab[i].srednia << endl;
			}
		}
		if (a == 0)
		{
			cout << "W bazie nie ma stodentow o podanej sredniej." << endl;
		}
		break;
	default:
		cout << "Podano niewlasciwa cyfre." << endl;
		break;
	}
	
}
void edytuj(vector<student> &tab)
{
	int idd, w;
	string edyt;
	float ed;
	cout << "\nKtorego studenta edytowac?(podaj id): " << endl;
	cin >> idd;
	cout << "\nKtora wartosc zmienic?(nazwisko->1, specjalnosc->2, srednia->3)" << endl;
	cin >> w;
	switch (w)
	{
	case 1:
		cout << "Podaj poprawione nazwisko: " << endl;
		cin >> edyt;
		tab[idd - 1].nazwisko = edyt;
		break;
	case 2:
		cout << "\nPodaj poprawiona specjalnosc: " << endl;
		cin >> edyt;
		tab[idd - 1].specjalnosc = edyt;
		break;
	case 3:
		cout << "\nPodaj poprawiona srednia: " << endl;
		cin >> ed;
		tab[idd - 1].srednia = ed;
		break;

	default:
		cout << "Podano nieprawid³owe oznaczenie!" << endl;
		break;
	}
}
string nazwa_pliku = "baza_studentow.txt";
void zapisz(vector<student> &tab)
{
	ofstream plik;
	plik.open(nazwa_pliku, ios::out);
	for (int i = 0; i < tab.size(); i++)
	{
		plik << tab[i].id << " " << tab[i].nazwisko << " " << tab[i].specjalnosc << " " << tab[i].srednia;
		if (i < tab.size() - 1) plik << endl;
	}
}
void wczytaj(vector <student> &tab, int &ktory)
{
	ifstream plikw(nazwa_pliku, ios::in);
	if (plikw.good()==false)
	{
		cout << "\nNie uda³o sie otworzyc plik." << endl;
	}
	while (!plikw.eof())
	{
		int id;
		string nazwisko;
		string specj;
		float sr;
		plikw >> id>>nazwisko>>specj>>sr;
		tab.push_back(student(id, nazwisko, specj, sr));
		ktory++;
	}
	plikw.close();
}

int main()
{
	int ktory = 0;
	int wybor;
	vector <student> tab;
	start:
		cout << "\t\tBAZA DANYCH STUDENTOW!" << endl;
		cout << "Dodanie studenta ->1" << "\nUsuwanie studenta ->2" << "\nWyswietlenie aktualnego stanu bazy->3" << endl;
		cout << "Wyszukiwanie studenta ->4" << "\nEdycja danych ->5" << endl;
		cout << "Zapisz dane do pliku ->6" << "\nWczytaj dane do programu ->7" <<"\nWyjscie ->8" <<endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "Ilu stduentow chcesz wpisac?" << endl;
			int ile;
			cin >> ile;
			for (int i = 0; i < ile; i++)
			{
				dodaj(tab, ktory);
			}
			system("cls");
			goto start;
		case 2:
			cout << "Ktorego studenta usunac?(podaj numer, ktory to student)" << endl;
			int usu;
			cin >> usu;
			usu--;
			usun(tab, usu);
			system("cls");
			goto start;
		case 3:
			wyswietl(tab);
			system("pause");
			system("cls");
			goto start;
		case 4:
			szukaj(tab);
			system("pause");
			system("cls");
			goto start;
		case 5:
			edytuj(tab);
			system("cls");
			goto start;
		case 6:
			zapisz(tab);
			system("cls");
			goto start;
		case 7:
			wczytaj(tab, ktory);
			system("cls");
			goto start;
		case 8:
			break;
		default:
			cout << "Podano nieprawidlowe oznaczenie, sprobuj ponownie!" << endl;
			system("cls");
			goto start;
		}
	return 0;
}