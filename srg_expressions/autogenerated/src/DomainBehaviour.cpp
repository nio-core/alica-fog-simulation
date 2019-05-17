#include "DomainBehaviour.h"
/*PROTECTED REGION ID(domainBehaviourSrcHeaders) ENABLED START*/
#include <SystemConfig.h>
#include <capnzero/Publisher.h>

#include <capnp/message.h>
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
void DomainBehaviour::sendSimCmd(srgsim::Command::Action action, uint32_t x, uint32_t y) {
    // init builder
    ::capnp::MallocMessageBuilder msgBuilder;
    srgsim::Command::Builder commandBuilder = msgBuilder.initRoot<srgsim::Command>();
    commandBuilder.setAction(action);
    commandBuilder.setX(x);
    commandBuilder.setY(y);

//        UUID::Builder sender = commandBuilder.initSenderId();
//        sender.setValue(kj::arrayPtr(aai.senderID->getRaw(), (unsigned int) aai.senderID->getSize()));
//    commandBuilder.setSenderId()


    this->simPub->send(msgBuilder);
}
/*PROTECTED REGION END*/
} /* namespace alica */
