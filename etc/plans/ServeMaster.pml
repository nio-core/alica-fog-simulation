{
  "id" : 1555601736192,
  "name" : "ServeMaster",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1555601746711,
    "name" : "1555601746711",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1555601344076",
    "state" : 1555601748848,
    "plan" : 1555601736192
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1555601748848,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : 1555601746711,
    "parentPlan" : 1555601736192,
    "abstractPlans" : [ "Behaviours/Stop.beh#1555602210283" ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ ]
  } ],
  "transitions" : [ ],
  "synchronisations" : [ ]
}