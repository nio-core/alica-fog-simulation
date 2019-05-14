#pragma once

#include <string>

namespace srg
{
namespace container
{
class Concept
{
public:
    Concept(std::string term, std::string senseLabel, std::string id);
    virtual ~Concept();
    Concept(const Concept& concept);

    std::string term;
    std::string senseLabel;
    std::string id;
};
} // namespace container
} // namespace srg
