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

void EditSong()
{
	if (catalog.empty())
	{
		cout << "The catalog is empty." << endl;
		return;
	}

	string title;
	cout << "Enter the song title to edit: ";
	getline(cin, title);

	for (auto& song : catalog)
	{
		if (song.title == title)
		{
			cout << "Enter the new lyrics:" << endl;
			getline(cin, song.lyrics);
			cout << "The song has been successfully edited." << endl;
			return;
		}
	}

	cout << "The song with the specified title was not found." << endl;
}

void DisplaySong()
{
	if (catalog.empty())
	{
		cout << "The catalog is empty." << endl;
		return;
	}

	string title;
	cout << "Enter the song title to display: ";
	getline(cin, title);

	for (const auto& song : catalog)
	{
		if (song.title == title)
		{
			cout << "Song title: " << song.title << endl;
			cout << "Song author: " << song.author << endl;
			cout << "Song year: " << song.year << endl;
			cout << "Song lyrics:" << endl;
			cout << song.lyrics << endl;

			return;
		}
	}

	cout << "The song with the specified title was not found." << endl;
}

void SaveCatalogToFile()
{
	if (catalog.empty())
	{
		cout << "The catalog is empty. Nothing to save." << endl;

		return;
	}

	string filename;

	cout << "Enter the filename to save the catalog: ";
	getline(cin, filename);

	ofstream outputFile(filename);
	if (outputFile.is_open())
	{
		for (const auto& song : catalog)
		{
			outputFile << song.title << endl;
			outputFile << song.author << endl;
			outputFile << song.year << endl;
			outputFile << song.lyrics << endl;
		}

		outputFile.close();
		cout << "The catalog has been successfully saved to the file." << endl;
	}
	else
	{
		cout << "Failed to open the file for saving." << endl;
	}
}

void SearchByAuthor()
{
	if (catalog.empty())
	{
		cout << "The catalog is empty." << endl;

		return;
	}

	string author;
	cout << "Enter the author name to search for songs: ";
	getline(cin, author);

	bool found = false;

	for (const auto& song : catalog)
	{
		if (song.author == author)
		{
			cout << "Song title: " << song.title << endl;
			cout << "Song author: " << song.author << endl;
			cout << "Song year: " << song.year << endl;
			cout << "Song lyrics:" << endl;
			cout << song.lyrics << endl;
			cout << endl;

			found = true;
		}
	}

	if (!found)
	{
		cout << "No songs by the specified author were found." << endl;
	}
}

void SearchByKeyword()
{
	if (catalog.empty())
	{
		cout << "The catalog is empty." << endl;

		return;
	}

	string keyword;
	cout << "Enter the keyword to search for songs: ";
	getline(cin, keyword);

	bool found = false;

	for (const auto& song : catalog)
	{
		if (song.lyrics.find(keyword) != string::npos)
		{
			cout << "Song title: " << song.title << endl;
			cout << "Song author: " << song.author << endl;
			cout << "Song year: " << song.year << endl;
			cout << "Song lyrics:" << endl;
			cout << song.lyrics << endl;
			cout << endl;
			found = true;
		}
	}

	if (!found)
	{
		cout << "No songs with the specified keyword were found." << endl;
	}
} 

void PrintMenu()
{
	cout << "----- Menu -----" << endl;
	cout << "1. Add a song" << endl;
	cout << "2. Delete a song" << endl;
	cout << "3. Edit a song" << endl;
	cout << "4. Display a song" << endl;
	cout << "5. Save the catalog to a file" << endl;
	cout << "6. Search songs by author" << endl;
	cout << "7. Search songs by keyword" << endl;
	cout << "0. Exit" << endl;
	cout << "----------------" << endl;
	cout << "Enter your choice: ";

}

int main()
{
	bool exitMenu = false;
	while (!exitMenu)
	{
		PrintMenu();

		int choice;
		cin >> choice;

		cin.ignore();

		switch (choice)
		{
		case 1:
			AddSong();
			break;
		case 2:
			DeleteSong();
			break;
		case 3:
			EditSong();
		case 4:
			DisplaySong();
			break;
		case 5:
			SaveCatalogToFile();
			break;
		case 6:
			SearchByAuthor();
			break;
		case 7:
			SearchByKeyword();
			break;
		case 0:
			exitMenu = true;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}

		cout << endl;
	}

	return 0;
}
		

