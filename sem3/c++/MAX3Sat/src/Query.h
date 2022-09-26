#pragma once
class Query
{
	int v1;
	int v2;
	int v3;

	bool sgn(int a) { return a > 0; }
public:
	Query(int a, int b, int c) { v1 = a; v2 = b; v3 = c; }

	int get1() { return v1 - 1; }
	int get2() { return v2 - 1; }
	int get3() { return v3 - 1; }

	bool checkQuery(bool b1, bool b2, bool b3){ return ((b1 && sgn(v1)) || (b2 && sgn(v2)) || (b3 && sgn(v3))); }
};

