#pragma once

class CIntN_Vert : public CIntN
{
public:

	using CIntN::CIntN;

	CIntN_Vert(const CIntN& other) : CIntN(other)
	{

	}

	using CIntN::operator=;

	friend CIntN_Vert operator+(CIntN&, CIntN&);
	friend CIntN_Vert operator-(CIntN&, CIntN&);

	void print(const string filename) override;

	~CIntN_Vert();
};
