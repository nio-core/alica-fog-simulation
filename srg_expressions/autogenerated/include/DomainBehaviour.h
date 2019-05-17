#pragma once

#include <engine/BasicBehaviour.h>
#include <string>
/*PROTECTED REGION ID(domainBehaviourHeaderHead) ENABLED START*/
namespace capnzero {
    class Publisher;
}

namespace essentials {
    class SystemConfig;
}
/*PROTECTED REGION END*/

namespace alica
{
class DomainBehaviour : public BasicBehaviour
{
public:
    DomainBehaviour(std::string name);
    virtual ~DomainBehaviour();

    /*PROTECTED REGION ID(domainBehaviourClassDecl) ENABLED START*/
    essentials::SystemConfig* sc;

    std::string simCmdTopic;
    std::string simAddress;

    capnzero::Publisher* simPub;
    void* capnzeroContext;

    /*PROTECTED REGION END*/
};
} /* namespace alica */
