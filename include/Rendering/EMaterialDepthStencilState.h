#pragma once

enum EMaterialDepthStencilState
{
	DEPTHSTENCIL_STATE_DEPTH_DISABLED = 0,
	DEPTHSTENCIL_STATE_STENCIL_WRITE_EQUAL = 1,
	DEPTHSTENCIL_STATE_STENCIL_WRITE_EQUAL_NO_DEPTH = 2,
	DEPTHSTENCIL_STATE_STENCIL_TEST = 3,
	DEPTHSTENCIL_STATE_STENCIL_TEST_REF_WRITE_NO_DEPTH = 4,
	DEPTHSTENCIL_STATE_STENCIL_TEST_WRITE_NO_DEPTH = 5,
	DEPTHSTENCIL_STATE_STENCIL_TEST_WRITE_REF_NO_DEPTH = 6,
	DEPTHSTENCIL_STATE_REFRACTIVE_MASK = 7,
	DEPTHSTENCIL_STATE_WRITE_DEPTH = 8,
	DEPTHSTENCIL_STATE_WRITE_NO_DEPTH = 9,
	DEPTHSTENCIL_STATE_STENCIL_TEST_EQUAL_DEPTH_DISABLED = 10,
	DEPTHSTENCIL_STATE_STENCIL_TEST_EQUAL_DEPTH_DISABLED_DECR = 11,
	DEPTHSTENCIL_STATE_STENCIL_TEST_EQUAL_DEPTH_DISABLED_INCR = 12,
	DEPTHSTENCIL_STATE_STENCIL_REPLACE_NO_DEPTH = 13,
	DEPTHSTENCIL_STATE_WRITE_NO_DEPTH_TEST_NO_DEPTH = 14,
	DEPTHSTENCIL_STATE_TEST_NO_DEPTH = 15,
	DEPTHSTENCIL_STATE_STENCIL_PASSINCR_WRITE_NO_DEPTH = 16,
	DEPTHSTENCIL_STATE_STENCIL_PASSDECR_WRITE_NO_DEPTH = 17,
	DEPTHSTENCIL_STATE_STENCIL_VOLUME_INCR_INSIDE_WRITE_NO_DEPTH = 18,
	DEPTHSTENCIL_STATE_STENCIL_VOLUME_DECR_INSIDE_WRITE_NO_DEPTH = 19,
	DEPTHSTENCIL_STATE_STENCIL_VOLUME_INCR_OUTSIDE_WRITE_NO_DEPTH = 20,
	DEPTHSTENCIL_STATE_STENCIL_VOLUME_DECR_OUTSIDE_WRITE_NO_DEPTH = 21,
	DEPTHSTENCIL_STATE_STENCIL_VOLUME_INCR_INSIDE_CMP_NOTEQUAL_WRITE_NO_DEPTH = 22,
	DEPTHSTENCIL_STATE_STENCIL_VOLUME_INCR_OUTSIDE_CMP_NOTEQUAL_WRITE_NO_DEPTH = 23,
	DEPTHSTENCIL_STATE_STENCIL_VOLUME_INCR_SAT_INSIDE_WRITE_NO_DEPTH = 24,
	DEPTHSTENCIL_STATE_STENCIL_VOLUME_INCR_SAT_OUTSIDE_WRITE_NO_DEPTH = 25,
	DEPTHSTENCIL_STATE_STENCIL_DECR_WRITE_NO_DEPTH_HISTENCIL_EQUAL = 26,
	DEPTHSTENCIL_STATE_STENCIL_DECR_WRITE_NO_DEPTH_HISTENCIL_NOTEQUAL = 27,
	DEPTHSTENCIL_STATE_STENCIL_CMP_NOTEQUAL_DEPTH_ALWAYS = 28,
	DEPTHSTENCIL_STATE_STENCIL_INCR_DEPTH_FAIL = 29,
	DEPTHSTENCIL_STATE_STENCIL_CLEAR_DEPTH_PASS = 30,
	DEPTHSTENCIL_STATE_STENCIL_PASSDECR_TEST_EQUAL_WRITE_NO_DEPTH = 31,
	DEPTHSTENCIL_STATE_STENCIL_WRITE_MSAA_EDGE_MASK = 32,
	DEPTHSTENCIL_STATE_STENCIL_TEST_MSAA_EDGE_MASK = 33,
	DEPTHSTENCIL_STATE_STENCIL_TEST_MSAA_EDGE_MASK_PASS_1 = 34,
	DEPTHSTENCIL_STATE_STENCIL_TEST_MSAA_EDGE_MASK_PASS_2 = 35,
	DEPTHSTENCIL_STATE_SIZE = 36
};
