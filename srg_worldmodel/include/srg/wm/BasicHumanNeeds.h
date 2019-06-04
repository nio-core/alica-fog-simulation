#pragma once

#include <string>
#include <vector>

namespace srg
{
class SRGWorldModel;
namespace wm
{
class ConceptNet;
class BasicHumanNeeds
{
public:
    BasicHumanNeeds(SRGWorldModel* wm);

    std::vector<std::string> answerNeed(std::string need);

private:
    SRGWorldModel* wm;
    ConceptNet* cn;
};
} // namespace wm
} // namespace srg
