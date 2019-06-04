#include "srg/wm/BasicHumanNeeds.h"
#include "srg/SRGWorldModel.h"
#include "srg/wm/ConceptNet.h"
#include "srg/container/Relations.h"

namespace srg
{
namespace wm
{
BasicHumanNeeds::BasicHumanNeeds(SRGWorldModel* wm)
        : wm(wm)
{
    this->cn = this->wm->conceptNet;
}

std::vector<std::string> BasicHumanNeeds::answerNeed(std::string need)
{
    //TODO
    /**
     *  1. ask ConceptNet for MotivatedByGoal(WILDCARD, need)
     *  2. ask ConceptNet for Synonyms for top 5 results from 1.
     *  => Synonym, IsA(subtype), SimilarTo, InstanceOf
     *  3. select top 5 from resulting concepts
     *  4. ask ConceptNet for UsedFor(concept, WILDCARD)
     *  5. ask ConceptNet for Synonyms for top 5 results from 4
     *  => Synonym, IsA(subtype), SimilarTo, InstanceOf
     *  6. return top 5
     */
    //1. ask ConceptNet for MotivatedByGoal(WILDCARD, need)
    std::vector<container::Edge> motivatedEdges = this->cn->getIncomingEdges(container::Relation::MotivatedByGoal, need);
    std::sort(motivatedEdges.begin(), motivatedEdges.end());
    //2. ask ConceptNet for Synonyms for top 5 results from 1.
    //=> Synonym, IsA(subtype), SimilarTo, InstanceOf
    int size = (motivatedEdges.size() < 5 ? motivatedEdges.size() : 5);
    std::vector<container::Edge> synonyms;
    synonyms.insert(synonyms.begin(), motivatedEdges.begin(), motivatedEdges.begin() + size);
    std::vector<container::Edge> tmp;
    for(int i = 0; i < size; i++) {
        tmp = this->cn->getOutgoingEdges(container::Relation::Synonym, motivatedEdges.at(i).fromConcept.term);
        synonyms.insert(synonyms.end(), tmp.begin(), tmp.end());
        tmp = this->cn->getOutgoingEdges(container::Relation::IsA, motivatedEdges.at(i).fromConcept.term);
        synonyms.insert(synonyms.end(), tmp.begin(), tmp.end());
        tmp = this->cn->getOutgoingEdges(container::Relation::SimilarTo, motivatedEdges.at(i).fromConcept.term);
        synonyms.insert(synonyms.end(), tmp.begin(), tmp.end());
        tmp = this->cn->getOutgoingEdges(container::Relation::InstanceOf, motivatedEdges.at(i).fromConcept.term);
        synonyms.insert(synonyms.end(), tmp.begin(), tmp.end());
    }
    //3. select top 5 from resulting concepts
    std::sort(synonyms.begin(), synonyms.end());
    size = (synonyms.size() < 5 ? synonyms.size() : 5);
    // 4. ask ConceptNet for UsedFor(concept, WILDCARD)
    std::vector<container::Edge> usedForEdges;
    for(int i = 0; i < size; i++) {
        tmp = this->cn->getOutgoingEdges(container::Relation::UsedFor, synonyms.at(i).fromConcept.term);
        usedForEdges.insert(usedForEdges.end(), tmp.begin(), tmp.end());
    }
    //5. ask ConceptNet for Synonyms for top 5 results from 4
    //=> Synonym, IsA(subtype), SimilarTo, InstanceOf
    synonyms.clear();
    for(int i = 0; i < size; i++) {
        tmp = this->cn->getOutgoingEdges(container::Relation::Synonym, usedForEdges.at(i).toConcept.term);
        synonyms.insert(synonyms.end(), tmp.begin(), tmp.end());
        tmp = this->cn->getOutgoingEdges(container::Relation::IsA, usedForEdges.at(i).toConcept.term);
        synonyms.insert(synonyms.end(), tmp.begin(), tmp.end());
        tmp = this->cn->getOutgoingEdges(container::Relation::SimilarTo, usedForEdges.at(i).toConcept.term);
        synonyms.insert(synonyms.end(), tmp.begin(), tmp.end());
        tmp = this->cn->getOutgoingEdges(container::Relation::InstanceOf, usedForEdges.at(i).toConcept.term);
        synonyms.insert(synonyms.end(), tmp.begin(), tmp.end());
    }
    //6. return top 5
    std::sort(synonyms.begin(), synonyms.end());
    size = (synonyms.size() < 5 ? synonyms.size() : 5);
    std::vector<std::string> answer;
    for(int i = 0; i < size; i++) {
        answer.push_back(synonyms.at(i).toConcept.term);
    }
    return answer;
}
} // namespace wm
} // namespace srg