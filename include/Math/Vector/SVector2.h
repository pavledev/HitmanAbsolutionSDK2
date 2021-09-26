#pragma once

struct SVector2
{
	union 
	{
		struct 
		{
			float x;
			float y;
		};

		float v[2];
	};

	SVector2() = default;
	~SVector2() = default;
};
