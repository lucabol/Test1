#ifndef UNICODE_HPP
#define UNICODE_HPP

#ifdef __cplusplus
	#if defined(UNICODE)
		typedef std::wstring tstring;
		wostream & tcout = wcout;
		wostream & tcerr = wcerr;
		wistream & tcin = wcin;
	#else
		typedef std::string tstring;
		ostream & tcout = cout;
		ostream & tcerr = cerr;
		istream & tcin = cin;
	#endif
#endif

#if defined(UNICODE)
	typedef wchar_t TCHAR;
#else
	typedef char TCHAR;
#endif

#endif