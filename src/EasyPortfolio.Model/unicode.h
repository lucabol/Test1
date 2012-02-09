#ifndef UNICODE_HPP
#define UNICODE_HPP


#ifdef __cplusplus
#include <string>
#include <iostream>

	#if defined(UNICODE)
		typedef std::wstring tstring;
		std::wostream & tcout = std::wcout;
		std::wostream & tcerr = std::wcerr;
		std::wistream & tcin = std::wcin;
	#else
		typedef std::string tstring;
		std::ostream & tcout = std::cout;
		std::ostream & tcerr = std::cerr;
		std::istream & tcin = std::cin;
	#endif
#endif

#if defined(UNICODE)
	typedef wchar_t TCHAR;
#else
	typedef char TCHAR;
#endif

#endif