#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Song
{
	string title;
	string author;
	int year;
	string lyrics;
};


vector<Song> catalog;

void AddSong()
{

	Song newSong;
	cout << "Enter the song title: ";
	getline(cin, newSong.title);

	cout << "Enter the song author: ";
	getline(cin, newSong.author);


	cout << "Enter the song year: ";
	cin >> newSong.year;
	cin.ignore();

	cout << "Enter the song lyrics:" << endl;
	getline(cin, newSong.lyrics);

	catalog.push_back(newSong);
	cout << "The song has been added to the catalog." << endl;
}

void DeleteSong()
{
	if (catalog.empty())
	{
		cout << "The catalog is empty." << endl;

		return;
	}

	string title;
	cout << "Enter the song title to delete: ";
	getline(cin, title);

	for (auto it = catalog.begin(); it != catalog.end(); ++it)
	{
		if (it->title == title)
		{
			catalog.erase(it);
			cout << "The song has been successfully deleted." << endl;

			return;
		}
	}
	cout << "The song with the specified title was not found." << endl;
}
