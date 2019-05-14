#pragma once
namespace srg
{
namespace container
{

enum Relation
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
    NotHasProperty,
    UNDEFINED
};
} // namespace container
} // namespace srg