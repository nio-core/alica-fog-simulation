#pragma once

namespace srg
{
class SRGWorldModel;
namespace wm
{

class Communication
{
public:
    Communication(SRGWorldModel* wm);

private:
    SRGWorldModel* wm;
};
} // namespace wm
} // namespace srg
