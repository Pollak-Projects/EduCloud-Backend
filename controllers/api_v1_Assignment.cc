#include "api_v1_Assignment.h"

#include <Assignment.h>

using namespace orm;
using namespace api::v1;

extern DbClientPtr eduCloudDbClientPtr;

// Add definition of your processing function here
void Assignment::getAll(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    Mapper<drogon_model::educloud::Assignment> mp(eduCloudDbClientPtr);
    auto const assignments = mp.findAll();

    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    resp->setBody(assignments.data()->toJson().asString());
    callback(resp);
}
