#pragma once

struct sOTSAimFlags
{
	union 
	{
		unsigned int m_nOTSFlags;

		struct 
		{
			bool m_bOTSPressed : 1;
			bool m_bOTSReleased : 1;
			bool m_bOTSTap : 1;
			bool m_mOTSLastState : 1;
			bool m_bOTSBlocked : 1;
		};
	};

	sOTSAimFlags() = default;
	~sOTSAimFlags() = default;
};
