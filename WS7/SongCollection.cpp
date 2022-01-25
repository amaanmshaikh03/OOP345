// Name: Mohammedamaan Shaikh
// Seneca Student ID: 157304197
// Seneca email: mishaikh3@myseneca.ca
// Date of completion: 16th July
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include "SongCollection.h"
namespace sdds {
	Song::Song(){
		m_artist = "";
		m_title = "";
		m_album = "";
		m_release_year = "";
		m_price = 0;
		m_song_length = 0u;
	}
	Song::Song(const std::string& line) : Song(){
		std::string temp_song_length;
		auto trim = [](std::string str) {
			if ((!str.empty() && !std::all_of(str.begin(), str.end(), isspace))) {
				while (str.at(0) == ' ')
					str = str.substr(1, str.length() - 1);
				while (str.at(str.length() - 1) == ' ')
					str = str.substr(0, str.length() - 1);
			}
			return str;
		};
		if (!line.empty() && line.length() >= 90) {
			m_title = trim((line.substr(0, 24)));
			m_artist = trim(line.substr(24, 25));
			m_album = trim(line.substr(50, 25));
			m_release_year = trim(line.substr(75, 5));
			m_song_length = stoul(trim(line.substr(80, 5)));
			try {
				m_price = stod(line.substr(85, 5));
			}
			catch (...) {
				throw "Price grabbed is not a number...";
			}
		}
	}
	std::ostream& operator<<(std::ostream& os, const Song& song){
		auto SongPlaytime = [](int secs) {
			std::string Time;
			int mins;
			mins = secs / 60;
			Time = std::to_string(int(mins % 60));
			Time += ":";
			Time += int(secs % 60) < 10 ? "0" + std::to_string(int(secs % 60)) : std::to_string(int(secs % 60));
			return Time;
		};
		os << "| ";
		os << std::left << std::setw(20) << song.m_title << " | ";
		os << std::left << std::setw(15) << song.m_artist << " | ";
		os << std::left << std::setw(20) << song.m_album << " | ";
		os << std::right << std::setw(6) << song.m_release_year << " | ";
		os << SongPlaytime(song.m_song_length) << " | ";
		os << std::setprecision(2) << std::fixed << song.m_price << " |";
		return os;
	}
	SongCollection::SongCollection(){
		m_collection_length = 0;
	}
	SongCollection::SongCollection(const char* filename) : SongCollection(){
		std::ifstream file(filename);
		std::string line;
		if (std::string(filename) == std::string("songs.txt")) {
			if (file.good()) {
				while (std::getline(file, line))
					if (!line.empty()) {
						Song tmp(line);
						m_Songs.push_back(tmp);
						m_collection_length += m_Songs.back().m_song_length;
					}
			}
		}
		else {
			throw std::string("Wrong filename : ") + filename;
		}
		file.close();
	}
	void SongCollection::display(std::ostream& os) const {
		for_each(m_Songs.begin(), m_Songs.end(), [&os](const Song& song) {os
			<< song << std::endl; });
		size_t totalLength = accumulate(m_Songs.begin(), m_Songs.end(), 0u,
			[](const size_t& currentLength, const Song& song) {return currentLength +
			song.m_song_length; });
		os << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
			os << "| ";
		os.width(76);
		os << "Total Listening Time:" << std::setfill(' ') <<std::right << std::setw(2)
			<< totalLength / 3600 << ":" << (totalLength - (totalLength / 3600) * 3600) / 60
			<< ":" << totalLength - (totalLength / 3600) * 3600 - ((totalLength -
				(totalLength / 3600) * 3600) / 60) * 60;
		os << " |" << std::endl;
	};

	void SongCollection::sort(std::string column) {
		if (column == "title")
			std::sort(m_Songs.begin(), m_Songs.end(), [](const Song& a,
				const Song& b) {return a.m_title < b.m_title; });
		if (column == "artist")
			std::sort(m_Songs.begin(), m_Songs.end(), [](const Song& a,
				const Song& b) {return a.m_artist < b.m_artist; });
		if (column == "album")
			std::sort(m_Songs.begin(), m_Songs.end(), [](const Song& a,
				const Song& b) {return a.m_album < b.m_album; });
		if (column == "length")
			std::sort(m_Songs.begin(), m_Songs.end(), [](const Song& a,
				const Song& b) {return a.m_song_length < b.m_song_length; });
		if (column == "year")
			std::sort(m_Songs.begin(), m_Songs.end(), [](const Song& a,
				const Song& b) {return a.m_release_year < b.m_release_year; });
		if (column == "price")
			std::sort(m_Songs.begin(), m_Songs.end(), [](const Song& a,
				const Song& b) {return a.m_price < b.m_price; });
	}
	void SongCollection::cleanAlbum() {
		for_each(m_Songs.begin(), m_Songs.end(), [](Song& song)
			{ song.m_album = song.m_album == "[None]" ? "" : song.m_album; });
	}
	bool SongCollection::inCollection(std::string artist) const {
		auto inCollection = find_if(m_Songs.begin(), m_Songs.end(),
			[&artist](const Song& song) {return song.m_artist == artist; });
		return inCollection != m_Songs.end();
	}
	std::list<sdds::Song> SongCollection::getSongsForArtist(std::string artist)
		const {
		auto filter_cnt = count_if(m_Songs.begin(), m_Songs.end(), [&artist]
		(const Song& song) {return song.m_artist == artist; });
		std::list<Song>l_songs(filter_cnt);
			copy_if(m_Songs.begin(), m_Songs.end(), l_songs.begin(), [&artist]
			(const Song& song) {return song.m_artist == artist; });
		return l_songs;
	};
}