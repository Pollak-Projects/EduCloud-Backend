#include "api_v1_Assignment.h"

using namespace api::v1;

// Add definition of your processing function here
void Assignment::getAll(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
