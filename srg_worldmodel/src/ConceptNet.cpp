#include "srg/wm/ConceptNet.h"
#include "srg/SRGWorldModel.h"

#include <curl/curl.h>

namespace srg
{
namespace wm
{

const std::string ConceptNet::BASE_URL = "http://api.localhost:8084";
const std::string ConceptNet::QUERYSTART = "/query?start=/c/en/";
const std::string ConceptNet::QUERYEND = "/query?end=/c/en/";
const std::string ConceptNet::QUERYNODE = "/query?node=/c/en/";
const std::string ConceptNet::QUERYOTHER = "/query?other=/c/en/";
const std::string ConceptNet::PREFIX = "cn5_";
const std::string ConceptNet::WILDCARD = "wildcard";
const std::string ConceptNet::LIMIT = "&limit=1000";
const std::string ConceptNet::RELATION = "&rel=/r/";
const std::string ConceptNet::END = "&end=/c/en/";
const std::string ConceptNet::RELATEDNESS = "/relatedness?";
const std::string ConceptNet::NODE1 = "node1=/c/en/";
const std::string ConceptNet::NODE2 = "&node2=/c/en/";

ConceptNet::ConceptNet(SRGWorldModel* wm)
{
    this->wm = wm;
    this->init();
}

ConceptNet::~ConceptNet() {}

std::string ConceptNet::getConcept(std::string concept)
{
    return httpGet(ConceptNet::BASE_URL + ConceptNet::QUERYNODE + concept + ConceptNet::LIMIT);
}
std::string ConceptNet::getCompleteEdge(ConceptNet::Relations relation, std::string fromConcept, std::string toConcept)
{
    return httpGet(ConceptNet::BASE_URL + ConceptNet::QUERYSTART + fromConcept + ConceptNet::RELATION + relationMapping[relation] + END + toConcept +
                   ConceptNet::LIMIT);
}
std::string ConceptNet::getOutgoingEdges(ConceptNet::Relations relation, std::string fromConcept)
{
    return httpGet(ConceptNet::BASE_URL + ConceptNet::QUERYSTART + fromConcept + ConceptNet::RELATION + relationMapping[relation] + ConceptNet::LIMIT);
}
std::string ConceptNet::getIncomingEdges(ConceptNet::Relations relation, std::string toConcept)
{
    return httpGet(ConceptNet::BASE_URL + ConceptNet::QUERYEND + toConcept + ConceptNet::RELATION + relationMapping[relation] + ConceptNet::LIMIT);
}
std::string ConceptNet::getRelations(std::string concept, std::string otherConcept)
{
    return httpGet(ConceptNet::BASE_URL + ConceptNet::QUERYSTART + concept + ConceptNet::END + otherConcept + ConceptNet::LIMIT);
}

double ConceptNet::getRelatedness(std::string firstConcept, std::string secondConcept)
{
    std::string json = httpGet(ConceptNet::BASE_URL + ConceptNet::RELATEDNESS + ConceptNet::NODE1 + firstConcept + ConceptNet::NODE2 + secondConcept);
    return 0.0;
}

std::size_t callback(const char* in, std::size_t size, std::size_t num, std::string* out)
{
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}

std::string ConceptNet::httpGet(std::string url)
{
    CURL* curl = curl_easy_init();

    // Set remote URL.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Don't bother trying IPv6, which would increase DNS resolution time.
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

    // Don't wait forever, time out after 10 seconds.
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Follow HTTP redirects if necessary.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Response information.
    int httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    // Hook up data handling function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

    // Hook up data container (will be passed as the last parameter to the
    // callback handling function).  Can be any pointer type, since it will
    // internally be passed as a void pointer.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    return *httpData;
}

void ConceptNet::init()
{
    relationMapping[RelatedTo] = "RelatedTo";
    relationMapping[FormOf] = "FormOf";
    relationMapping[IsA] = "IsA";
    relationMapping[PartOf] = "PartOf";
    relationMapping[HasA] = "HasA";
    relationMapping[UsedFor] = "UsedFor";
    relationMapping[CapableOf] = "CapableOf";
    relationMapping[AtLocation] = "AtLocation";
    relationMapping[Causes] = "Causes";
    relationMapping[HasSubevent] = "HasSubevent";
    relationMapping[HasFirstSubevent] = "HasFirstSubevent";
    relationMapping[HasLastSubevent] = "HasLastSubevent";
    relationMapping[HasPrerequisite] = "HasPrerequisite";
    relationMapping[HasProperty] = "HasProperty";
    relationMapping[MotivatedByGoal] = "MotivatedByGoal";
    relationMapping[ObstructedBy] = "ObstructedBy";
    relationMapping[Desires] = "Desires";
    relationMapping[CreatedBy] = "CreatedBy";
    relationMapping[Synonym] = "Synonym";
    relationMapping[Antonym] = "Antonym";
    relationMapping[DistinctFrom] = "DistinctFrom";
    relationMapping[DerivedFrom] = "DerivedFrom";
    relationMapping[SymbolOf] = "SymbolOf";
    relationMapping[DefinedAs] = "DefinedAs";
    relationMapping[Entails] = "Entails";
    relationMapping[MannerOf] = "MannerOf";
    relationMapping[LocatedNear] = "LocatedNear";
    relationMapping[HasContext] = "HasContext";
    relationMapping[SimilarTo] = "SimilarTo";
    relationMapping[EtymologicallyRelatedTo] = "EtymologicallyRelatedTo";
    relationMapping[EtymologicallyDerivedFrom] = "EtymologicallyDerivedFrom";
    relationMapping[CausesDesire] = "CausesDesire";
    relationMapping[MadeOf] = "MadeOf";
    relationMapping[ReceivesAction] = "ReceivesAction";
    relationMapping[InstanceOf] = "InstanceOf";
    relationMapping[NotDesires] = "NotDesires";
    relationMapping[NotUsedFor] = "NotUsedFor";
    relationMapping[NotCapableOf] = "NotCapableOf";
    relationMapping[NotIsA] = "NotIsA";
    relationMapping[NotHasProperty] = "NotHasProperty";
}

} // namespace wm

} // namespace srg
