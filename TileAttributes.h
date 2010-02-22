/**
 * @author Lenoa
 */

#ifndef TILE_ATTRIBUTES_INCLUDED
#define TILE_ATTRIBUTES_INCLUDED 1

#include <string>

/**
 * It models the attributes of a tile :
 * <ul>
 * <li>File name of the image</li>
 * <li>Attributes (empty, breakable, pushable) as bit flags</li>
 * </ul>
 *
 * @author Lenoa
 */
struct TileAttributes
{
	/**
	 * The bit flags of the attributes
	 */
	enum AttributeFlags
	{
		    NotEmpty = 0 << 0,
		       Empty = 1 << 0,
		NotBreakable = 0 << 1,
		   Breakable = 1 << 1,
		 NotPushable = 0 << 2,
		    Pushable = 1 << 2
	};

	/**
	 * The file name of the image of the tile
	 */
	std::string Filename;

	/**
	 * The attributes of the tile
	 *
	 * It is a combinaison of AttributeFlags
	 */
	unsigned char Attributes;

	TileAttributes() : Filename(), Attributes(Empty) {}

	/**
	 * @param File the file name
	 * @param Attrs the attributes
	 */
	TileAttributes(const std::string &File, unsigned char Attrs) : Filename(File), Attributes(Attrs) {}
};

#endif // TILE_ATTRIBUTES_INCLUDED

