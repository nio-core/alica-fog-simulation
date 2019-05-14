#pragma once

#include <map>
#include <string>

namespace srg
{
class SRGWorldModel;
namespace wm
{

class ConceptNet
{
public:
    ConceptNet(SRGWorldModel* wm);
    virtual ~ConceptNet();

    enum Relations
    {
        RelatedTo,
        FormOf,
        IsA,
        PartOf,
        HasA,
        UsedFor,
        CapableOf,
        AtLocation,
        Causes,
        HasSubevent,
        HasFirstSubevent,
        HasLastSubevent,
        HasPrerequisite,
        HasProperty,
        MotivatedByGoal,
        ObstructedBy,
        Desires,
        CreatedBy,
        Synonym,
        Antonym,
        DistinctFrom,
        DerivedFrom,
        SymbolOf,
        DefinedAs,
        Entails,
        MannerOf,
        LocatedNear,
        HasContext,
        SimilarTo,
        EtymologicallyRelatedTo,
        EtymologicallyDerivedFrom,
        CausesDesire,
        MadeOf,
        ReceivesAction,
        InstanceOf,
        NotDesires,
        NotUsedFor,
        NotCapableOf,
        NotIsA,
        NotHasProperty
    };

    std::string getConcept(std::string concept);
    std::string getCompleteEdge(ConceptNet::Relations relation, std::string fromConcept, std::string toConcept);
    std::string getOutgoingEdges(ConceptNet::Relations relation, std::string fromConcept);
    std::string getIncomingEdges(ConceptNet::Relations relation, std::string toConcept);
    std::string getRelations(std::string concept, std::string otherConcept);
    double getRelatedness(std::string firstConcept, std::string secondConcept);

private:
    SRGWorldModel* wm;
    std::map<ConceptNet::Relations, std::string> relationMapping;
    void init();
    std::string httpGet(std::string url);
    /**
     * Containts the begin of a concept net query url.
     */
    static const std::string BASE_URL;
    /**
     * Query part: /query?start=/c/en/
     */
    static const std::string QUERYSTART;
    /**
     * Query part: /query?end=/c/en/
     */
    static const std::string QUERYEND;
    /**
     * Query part: /query?node=/c/en/
     */
    static const std::string QUERYNODE;
    /**
     * Query part: /query?other=/c/en/
     */
    static const std::string QUERYOTHER;
    /**
     * Containts the cn5_ prefix.
     */
    static const std::string PREFIX;
    /**
     * Wildcard string
     */
    static const std::string WILDCARD;
    /**
     * Limit part
     */
    static const std::string LIMIT;
    /**
     * Relation part
     */
    static const std::string RELATION;
    /**
     * End part
     */
    static const std::string END;
    /**
     * Relatedness part
     */
    static const std::string RELATEDNESS;
    /**
     * Nod1 part
     */
    static const std::string NODE1;
    /**
     * Node2 part
     */
    static const std::string NODE2;
};

} /* namespace wm */
} /* namespace srg */
