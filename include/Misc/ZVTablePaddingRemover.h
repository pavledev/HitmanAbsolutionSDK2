#pragma once

class ZVTablePaddingRemover
{
public:
	virtual ~ZVTablePaddingRemover() = default;

	ZVTablePaddingRemover(const ZVTablePaddingRemover& __that);
	ZVTablePaddingRemover() = default;
	ZVTablePaddingRemover& operator=(const ZVTablePaddingRemover& __that);
};
