#pragma once

struct SVector3
{
	union 
	{
		struct 
		{
			float x;
			float y;
			float z;
		};

		float v[3];
	};

	SVector3() = default;
	~SVector3() = default;
};
