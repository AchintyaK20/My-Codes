#include<iostream>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string convert(string s)
{
	int nTmp = 0, i;
	bool bTmp = false;
	for (i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]) && !bTmp)
		{
			bTmp = true;
			nTmp++;
		}
		if (!isdigit(s[i]))
		{
			bTmp = false;
		}
	}
	string strRet = "";
	if (nTmp == 1)
	{
		string R, C;
		int nC = 0, nHex = 1;
		for (i = 0; i < s.size(); i++)
		{
			if (isalpha(s[i]))
			{
				C += s[i];
			}
			else
			{
				R += s[i];
			}
		}
		for (i = 0; i < C.size(); i++)
		{
			nC = nC + (C[C.size() - i - 1] - 'A' + 1) * nHex;
			nHex = nHex * 26;
		}
		strRet = strRet + "R" + R + "C";
		string strTmp = to_string(nC);
		strRet = strRet + strTmp;
	}
	else
	{
		int C = 0;
		int nPos = s.find('C');
		string tmp = s.substr(nPos + 1, s.length() - nPos - 1);
		C = stoi(tmp);
		string strTmp = "";
		while (C)
		{
			if (C % 26 == 0)
			{
				strTmp = 'Z' + strTmp;
				C /= 26;
				C--;
				continue;
			}
			strTmp = (char)((C % 26) + 'A' - 1) + strTmp;
			C = C / 26;
		}
		strRet = strTmp + s.substr(1, nPos - 1);
	}
	return strRet;
}
int main()
{
	FAST_IO;
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << convert(s);
		cout << endl;
	}
	return 0;
}