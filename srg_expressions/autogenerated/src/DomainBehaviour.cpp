#include "DomainBehaviour.h"
/*PROTECTED REGION ID(domainBehaviourSrcHeaders) ENABLED START*/
#include <capnzero/Publisher.h>
#include <SystemConfig.h>
/*PROTECTED REGION END*/

namespace alica
{
DomainBehaviour::DomainBehaviour(std::string name)
        : BasicBehaviour(name)
{
    /*PROTECTED REGION ID(domainBehaviourConstructor) ENABLED START*/
    this->sc = essentials::SystemConfig::getInstance();
    this->simCmdTopic = (*sc)["SRGSim"]->get<std::string>("SRGSim.Communication.cmdTopic", NULL);
    this->simAddress = (*sc)["SRGSim"]->get<std::string>("SRGSim.Communication.address", NULL);

    this->capnzeroContext = zmq_ctx_new();
    this->simPub = new capnzero::Publisher(this->capnzeroContext);
    this->simPub->setDefaultGroup(this->simCmdTopic);
    this->simPub->bind(capnzero::CommType::UDP, simAddress);
    /*PROTECTED REGION END*/
}

DomainBehaviour::~DomainBehaviour()
{
    /*PROTECTED REGION ID(domainBehaviourDestructor) ENABLED START*/
    delete simPub;
    /*PROTECTED REGION END*/
}

/*PROTECTED REGION ID(domainBehaviourMethods) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/
} /* namespace alica */
