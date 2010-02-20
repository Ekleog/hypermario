/**
 * @author Lenoa
 */

#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "TileAttributes.h"

/**
 * The main function of the program which just edits the correspondance table
 *
 * @return 0 if success ; 1 otherwise
 * @author Lenoa
 */
int main(int, char**)
{
	bool stop = false;
	std::map<char, TileAttributes> m;
	std::ifstream file("maps/correspondance.table", std::ios::in | std::ios::binary);
	std::string s;

	// Read the file
	while(std::getline(file, s, '\n'))
	{
		if(s.length() > 2)
			m.insert(std::pair<char, TileAttributes>(s[0], TileAttributes(s.substr(2), s[1])));
	}
	file.close();

	// Edit
	while(!stop)
	{
		std::cout << "Actually, the correspondance table is :" << std::endl << std::endl;
		for(std::map<char, TileAttributes>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			std::cout << (*it).first << '=' << (*it).second.Filename << " (" << short((*it).second.Attributes) << ')' << std::endl;
		}
		std::cout << std::endl <<
		"What would you like to do ? \n"
		"[I]nsert a tile             \n"
		"[R]emove a tile             \n"
		"[Q]uit                      \n"
		"[I/E/R/Q] ? ";
		char action;
		std::cin >> action;
		std::cin.ignore();
		char id;
		TileAttributes attrs;
		char tmp;
		switch(action)
		{
			case 'q':
			case 'Q':
				stop = true;
				break;
			case 'i':
			case 'I':
				std::cout << "ID ? ";
				std::cin >> id;
				std::cin.ignore();
				std::cout << "File name ? ";
				std::getline(std::cin, attrs.Filename, '\n');
				std::cout << "Empty (0/1) ? ";
				std::cin >> tmp;
				std::cin.ignore();
				if(tmp == '1') attrs.Attributes |= TileAttributes::Empty;
				std::cout << "Breakable (0/1) ? ";
				std::cin >> tmp;
				std::cin.ignore();
				if(tmp == '1') attrs.Attributes |= TileAttributes::Breakable;
				std::cout << "Pushable (as a box) (0/1) ? ";
				std::cin >> tmp;
				std::cin.ignore();
				if(tmp == '1') attrs.Attributes |= TileAttributes::Pushable;
				m.insert(std::pair<char, TileAttributes>(id, attrs));
				break;
			case 'r':
			case 'R':
				std::cout << "ID ? ";
				std::cin >> id;
				std::cin.ignore();
				m.erase(id);
				break;
		}
	}

	// Write the changes
	std::ofstream out("maps/correspondance.table", std::ios::out | std::ios::binary | std::ios::trunc);
	for(std::map<char, TileAttributes>::const_iterator it = m.begin(); it != m.end(); ++it)
	{
		out << (*it).first << (*it).second.Attributes << (*it).second.Filename << std::endl;
	}
	return 0;
}

