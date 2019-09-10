#include "PayOffConstructible.h"
#include "PayOffStraddle.h"

namespace

{
	PayOffHelper<PayOffStraddle> PayOffStraddleRegistration("straddle");
}