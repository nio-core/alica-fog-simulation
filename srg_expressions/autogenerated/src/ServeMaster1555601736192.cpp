#include "ServeMaster1555601736192.h"
/*PROTECTED REGION ID(eph1555601736192) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

using namespace alica;

namespace alicaAutogenerated
{
// Plan:ServeMaster
/* generated comment
    Task: Serve  -> EntryPoint-ID: 1555601746711
*/
shared_ptr<UtilityFunction> UtilityFunction1555601736192::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1555601736192) ENABLED START*/
    std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}
} // namespace alicaAutogenerated