#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>

#include "record.hpp"
#include "unicode.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#define LONG_STRING_LENGTH	50
#define SHORT_STRING_LENGTH 50
#define DATE_STRING_LENGTH	10

// Making sure all compilers use the same packing
#pragma pack(8)

typedef uint32_t id_type;
typedef TCHAR long_string[LONG_STRING_LENGTH];
typedef TCHAR short_string[SHORT_STRING_LENGTH];
typedef TCHAR date_string[DATE_STRING_LENGTH];
typedef double money;
typedef double shares;

typedef struct Portfolio {
	id_type		PortfolioId;
	id_type		Parent;
	long_string	Name;
} PACKED Portfolio;

typedef struct Lot {
	id_type		LotId;
	id_type		PortfolioId;
} PACKED Lot;

typedef struct Investment {
	id_type			InvestmentId;
	long_string		Name;
	short_string	Symbol;
	long_string		Description;
	short_string	CUSIP;
	id_type			InvestmentTypeId;
	id_type			CurrencyId;
} PACKED Investment;

typedef struct Price {
	id_type		PriceId;
	date_string	Date;
	money		Close;
	money		Open;
	money		High;
	money		Low;
	shares		Volume;
	id_type		InvestmentId;
} PACKED Price;

typedef Transaction {
	id_type		TransactionId;
	date_string	Date;
	money		Price;
	shares		Shares;
	money		Commission;
} PACKED Transaction;

typedef Currency {
	id_type		CurrencyId;
	long_string	Name;
} PACKED Currency;

typedef InvestmentType {
	type_id		InvestmentTypeId;
	long_string	Name;
} PACKED InvestmentType;

#ifdef __cplusplus
}
#endif // extern C

#endif // guard