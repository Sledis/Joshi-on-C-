#include "PayOffConstructible.h"
#include "PayOffDigital.h"

namespace
{
	PayOffHelper<PayOffDigitalCall> RegisterDigitalCall("digitalCall");
	PayOffHelper<PayOffDigitalPut> RegisterDigitalPut("digitalPut");
}