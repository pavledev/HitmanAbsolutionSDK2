#pragma once

enum ERenderPrimitiveType
{
	PRIM_TYPE_MESH_STANDARD = 0,
	PRIM_TYPE_MESH_STANDARD_TC1 = 1,
	PRIM_TYPE_MESH_STANDARD_TC2 = 2,
	PRIM_TYPE_MESH_STANDARD_TC3 = 3,
	PRIM_TYPE_MESH_STANDARD_HIRES = 4,
	PRIM_TYPE_MESH_STANDARD_TC1_HIRES = 5,
	PRIM_TYPE_MESH_STANDARD_TC2_HIRES = 6,
	PRIM_TYPE_MESH_STANDARD_TC3_HIRES = 7,
	PRIM_TYPE_MESH_LINKED = 8,
	PRIM_TYPE_MESH_LINKED_HIRES = 9,
	PRIM_TYPE_MESH_WEIGHTED = 10,
	PRIM_TYPE_MESH_WEIGHTED_HIRES = 11,
	PRIM_TYPE_GENERIC = 12,
	PRIM_TYPE_DECAL_STANDARD = 13,
	PRIM_TYPE_DECAL_LINKED = 14,
	PRIM_TYPE_DECAL_WEIGHTED = 15,
	PRIM_TYPE_SIMPLE = 16,
	PRIM_TYPE_SIMPLE_COLORTEX = 17,
	PRIM_TYPE_RAIN = 18,
	PRIM_TYPE_SPRITES_SA = 19,
	PRIM_TYPE_SPRITES_AO = 20,
	NUM_PRIM_TYPES = 21,
	PRIM_TYPE_INVALID = 127
};
