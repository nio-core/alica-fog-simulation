#pragma once

#include <srgsim/Command.capnp.h>
#include <essentials/AgentIDConstPtr.h>

#include <string>

namespace capnzero
{
class Publisher;
}

namespace essentials
{
class SystemConfig;
}

namespace srg
{

class SRGWorldModel;

class Robot
{

public:
    Robot(srg::SRGWorldModel* wm);
    virtual ~Robot();

    void spawn() const;

private:
    essentials::SystemConfig* sc;

    std::string simCmdTopic;
    std::string simAddress;

    capnzero::Publisher* simPub;
    void* capnzeroContext;
    essentials::AgentIDConstPtr id;

    srg::SRGWorldModel* wm;
};
} // namespace srg