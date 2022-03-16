#pragma once

class CIntN_Hori : public CIntN
{
public:

	using CIntN::CIntN;

	CIntN_Hori(const CIntN& other) : CIntN(other)
	{

	}

	using CIntN::operator=;

	friend CIntN_Hori operator+(CIntN&, CIntN&);
	friend CIntN_Hori operator-(CIntN&, CIntN&);

	void print(const string filename) override;

	~CIntN_Hori();
};

