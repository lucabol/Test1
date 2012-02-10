#include "Model.h"
#include "platform.h"

#ifdef __cplusplus
extern "C" {
#endif

DLL_EXPORT Portfolio CreatePortfolio() {
	Portfolio p = Portfolio();
	return p;
}

#ifdef __cplusplus
}
#endif
