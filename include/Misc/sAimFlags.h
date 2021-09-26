#pragma once

struct sAimFlags
{
	union 
	{
		unsigned int m_nAimFlags;

		struct 
		{
			bool m_bRightHandAimInPlace : 1;
			bool m_bLeftHandAimInPlace : 1;
			bool m_bAimRight : 1;
			bool m_bAimLeft : 1;
		};
	};

	sAimFlags() = default;
	~sAimFlags() = default;
};
