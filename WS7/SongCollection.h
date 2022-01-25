// Name: Mohammedamaan Shaikh
// Seneca Student ID: 157304197
// Seneca email: mishaikh3@myseneca.ca
// Date of completion: 16th July
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#include <string>
#include <vector>
#include <list>
namespace sdds {
	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		std::string m_release_year;
		double m_price;
		unsigned int m_song_length;
		Song();
		Song(const std::string& line);
	};
	class SongCollection {
		std::vector<Song> m_Songs;
		unsigned int m_collection_length;
	public:
		SongCollection();
		SongCollection(const char* filename);
		void display(std::ostream& os) const;
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string artist) const;
		std::list<Song> getSongsForArtist(std::string artist) const;
	};
	std::ostream& operator<<(std::ostream& os, const Song& theSong);
}