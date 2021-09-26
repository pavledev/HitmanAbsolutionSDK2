#pragma once

class GColor
{
public:
	enum StandardColors
	{
		Black = 0,
		White = 16777215,
		VeryLightGray = 14737632,
		LightGray = 12632256,
		Gray = 8421504,
		DarkGray = 4210752,
		VeryDarkGray = 2105376,
		Red = 16711680,
		LightRed = 16744576,
		DarkRed = 8388608,
		VeryDarkRed = 4194304,
		Green = 65280,
		LightGreen = 8454016,
		DarkGreen = 32768,
		VeryDarkGreen = 16384,
		Blue = 255,
		LightBlue = 8421631,
		DarkBlue = 128,
		VeryDarkBlue = 64,
		Cyan = 65535,
		LightCyan = 8454143,
		DarkCyan = 32896,
		Magenta = 16711935,
		LightMagenta = 16744703,
		DarkMagenta = 8388736,
		Yellow = 16776960,
		LightYellow = 16777088,
		DarkYellow = 8421376,
		Purple = 16711935,
		DarkPurple = 8388736,
		Pink = 16761024,
		DarkPink = 12615808,
		Beige = 16760960,
		LightBeige = 16769216,
		DarkBeige = 12615744,
		Orange = 16744448,
		Brown = 8404992,
		LightBrown = 12607488,
		DarkBrown = 4202496
	};

	enum StandardAlphas
	{
		Alpha0 = 0,
		Alpha25 = 1073741824,
		Alpha50 = 2130706432,
		Alpha75 = 3204448256,
		Alpha100 = 4278190080
	};

	struct Rgb24
	{
		unsigned char Blue;
		unsigned char Green;
		unsigned char Red;
	};

	struct Rgb32
	{
		unsigned char Blue;
		unsigned char Green;
		unsigned char Red;
		unsigned char Alpha;
	};

	union
	{
		Rgb32 Channels;
		unsigned long Raw;
	};

	~GColor() = default;
	GColor() = default;
};
