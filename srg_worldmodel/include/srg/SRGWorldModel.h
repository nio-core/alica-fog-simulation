#pragma once

#include "srg/wm/ConceptNet.h"
#include "wm/SRGSimData.h"

#include <SystemConfig.h>
#include <essentials/EventTrigger.h>
#include <knowledge_manager/ASPKnowledgeManager.h>
#include <supplementary/InformationElement.h>
#include <supplementary/WorldModel.h>

namespace essentials
{
class SystemConfig;
}

namespace reasoner
{
namespace asp
{
class Solver;
}
} // namespace reasoner

namespace srg
{
class SRGWorldModel : public supplementary::WorldModel
{
public:
    static SRGWorldModel* getInstance(); /**< Singleton Getter */

    virtual ~SRGWorldModel();
    void init();
    void setSolver(::reasoner::asp::Solver* solver);
    std::string getAgentName();

    // Public Data Access Classes
    wm::SRGSimData sRGSimData;
    knowledge_manager::ASPKnowledgeManager knowledgeManager;
    wm::ConceptNet conceptNet;

private:
    SRGWorldModel(); /**< Private Singleton Constructor */
    std::string agentName;
};

} /* namespace srg */
