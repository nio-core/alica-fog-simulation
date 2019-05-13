#pragma once

#include "wm/KnowledgeManager.h"
#include "wm/SRGSimData.h"
#include <SystemConfig.h>
#include <essentials/EventTrigger.h>
#include <supplementary/InformationElement.h>
#include <supplementary/WorldModel.h>
namespace essentials
{
class SystemConfig;
}

namespace alica
{
class AlicaEngine;
class AlicaClock;
} // namespace alica

namespace srg
{

class SRGWorldModel : public supplementary::WorldModel
{
public:
    static SRGWorldModel* getInstance(); /**< Singleton Getter */

    virtual ~SRGWorldModel();
    void init();
    std::string getAgentName();

    // Public Data Access Classes
    wm::SRGSimData sRGSimData;
    wm::KnowledgeManager knowledgeManager;

private:
    SRGWorldModel(); /**< Private Singleton Constructor */
    std::string agentName;
};

} /* namespace srg */
