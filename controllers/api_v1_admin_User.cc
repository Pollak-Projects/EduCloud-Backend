#include "api_v1_admin_User.h"

using namespace api::v1::admin;

// Add definition of your processing function here
void User::getAll(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void User::getById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                   const std::string& id)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void User::create(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void User::updateById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void User::deleteById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void User::login(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
