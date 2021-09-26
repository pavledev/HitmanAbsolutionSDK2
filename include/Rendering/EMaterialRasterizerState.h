#pragma once

enum EMaterialRasterizerState
{
	RASTERIZER_STATE_CULL_BACK = 0,
	RASTERIZER_STATE_CULL_NONE = 1,
	RASTERIZER_STATE_CULL_FRONT = 2,
	RASTERIZER_STATE_CULL_BACK2 = 3,
	RASTERIZER_STATE_CULL_BACK_FRONT_CW = 4,
	RASTERIZER_STATE_WIRE_BIAS = 5,
	RASTERIZER_STATE_WIRE_AALINE_BIAS = 6,
	RASTERIZER_STATE_SOLID_BIAS = 7,
	RASTERIZER_STATE_WIRE_BIAS_2_CULL_NONE = 8,
	RASTERIZER_STATE_WIRE_BIAS_2_CULL_BACK = 9,
	RASTERIZER_STATE_SOLID_BIAS_2_CULL_NONE = 10,
	RASTERIZER_STATE_SOLID_BIAS_2_CULL_BACK = 11,
	RASTERIZER_STATE_SIZE = 12
};