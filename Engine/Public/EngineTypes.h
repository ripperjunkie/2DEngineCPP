//
// * ENGINE-X
//
// + Types.h
// representations of: 2D vector with floats, 2D vector with integers and RBGA color as four bytes
//

#pragma once

//-----------------------------------------------------------------
//-----------------------------------------------------------------



struct exVector2
{
	float x, y;

	exVector2 operator+(const exVector2& other)
	{
		return exVector2{ this->x + other.x, this->y + other.y };
	}
	exVector2 operator+=(const exVector2& other)
	{
		return exVector2{ this->x + other.x, this->y + other.y };
	}
	bool operator==(const exVector2& other)
	{
		return this->x == other.x && this->y == other.y;
	}
	exVector2 operator=(const exVector2& other)
	{
		return exVector2{ this->x = other.x , this->y = other.y};
	}

};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exIntegerVector2
{
	int x, y;
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exColor
{
	unsigned char mColor[4];
};

#define LIGHTGRAY  exColor{ 200, 200, 200, 255 }   // Light Gray
#define GRAY       exColor{ 130, 130, 130, 255 }   // Gray
#define DARKGRAY   exColor{ 80, 80, 80, 255 }      // Dark Gray
#define YELLOW     exColor{ 253, 249, 0, 255 }     // Yellow
#define GOLD       exColor{ 255, 203, 0, 255 }     // Gold
#define ORANGE     exColor{ 255, 161, 0, 255 }     // Orange
#define PINK       exColor{ 255, 109, 194, 255 }   // Pink
#define RED        exColor{ 230, 41, 55, 255 }     // Red
#define MAROON     exColor{ 190, 33, 55, 255 }     // Maroon
#define GREEN      exColor{ 0, 228, 48, 255 }      // Green
#define LIME       exColor{ 0, 158, 47, 255 }      // Lime
#define DARKGREEN  exColor{ 0, 117, 44, 255 }      // Dark Green
#define SKYBLUE    exColor{ 102, 191, 255, 255 }   // Sky Blue
#define BLUE       exColor{ 0, 121, 241, 255 }     // Blue
#define DARKBLUE   exColor{ 0, 82, 172, 255 }      // Dark Blue
#define PURPLE     exColor{ 200, 122, 255, 255 }   // Purple
#define VIOLET     exColor{ 135, 60, 190, 255 }    // Violet
#define DARKPURPLE exColor{ 112, 31, 126, 255 }    // Dark Purple
#define BEIGE      exColor{ 211, 176, 131, 255 }   // Beige
#define BROWN      exColor{ 127, 106, 79, 255 }    // Brown
#define DARKBROWN  exColor{ 76, 63, 47, 255 }      // Dark Brown

#define WHITE      exColor{ 255, 255, 255, 255 }   // White
#define BLACK      exColor{ 0, 0, 0, 255 }         // Black
#define BLANK      exColor{ 0, 0, 0, 0 }           // Blank (Transparent)
#define MAGENTA    exColor{ 255, 0, 255, 255 }     // Magenta
#define RAYWHITE   exColor{ 245, 245, 245, 255 }   // My own White 