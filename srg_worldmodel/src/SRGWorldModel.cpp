#include "srg/SRGWorldModel.h"

#include "srg/wm/ConceptNet.h"

namespace srg
{

SRGWorldModel* SRGWorldModel::getInstance()
{
    static SRGWorldModel instance;
    return &instance;
}

SRGWorldModel::SRGWorldModel()
        : WorldModel()
        , sRGSimData(this)
        , basicHumanNeeds(this)
{
    this->agentName = sc->getHostname();
    this->conceptNet = new wm::ConceptNet(this);
}

SRGWorldModel::~SRGWorldModel()
{
    delete this->conceptNet;
}

std::string SRGWorldModel::getAgentName()
{
    return this->agentName;
}

void SRGWorldModel::init()
{

}

void SRGWorldModel::setSolver(reasoner::asp::Solver* solver) {
    this->knowledgeManager.setSolver(solver);
}
} /* namespace wumpus */
