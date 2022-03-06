#pragma once

class CIntN_Vert : public CIntN
{
public:

	using CIntN::CIntN;

	using CIntN::operator=;

	void print(const string filename) override;

	~CIntN_Vert();
};
