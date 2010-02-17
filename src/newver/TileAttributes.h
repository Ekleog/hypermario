/**
 * @version 1.0
 *
 * @author Lenoa
 */

#ifndef TILE_ATTRIBUTES_INCLUDED
#define TILE_ATTRIBUTES_INCLUDED 1

#include <string>

struct TileAttributes
{
	enum
	{
		    NotEmpty = 0 << 0,
		       Empty = 1 << 0,
		NotBreakable = 0 << 1,
		   Breakable = 1 << 1,
		 NotPushable = 0 << 2,
		    Pushable = 1 << 2
	};

	std::string Filename;
	unsigned char Attributes;

	TileAttributes() : Filename(), Attributes(Empty) {}
	TileAttributes(const std::string &File, unsigned char Attrs) : Filename(File), Attributes(Attrs) {}
};

#endif // TILE_ATTRIBUTES_INCLUDED

