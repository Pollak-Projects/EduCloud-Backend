#include "api_v1_admin_Assignment.h"

using namespace api::v1::admin;

// Add definition of your processing function here
void Assignment::getById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                         const std::string& id)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::getByName(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                           const std::string& name)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::getByProfession(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                                 const std::string& profession)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::getByProfessionAndCategory(const HttpRequestPtr& req,
                                            std::function<void(const HttpResponsePtr&)>&& callback,
                                            const std::string& profession, const std::string& category)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::getByProfessionAndGrade(const HttpRequestPtr& req,
                                         std::function<void(const HttpResponsePtr&)>&& callback,
                                         const std::string& profession, const std::string& grade)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::getByCategory(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                               const std::string& category)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::getByCategoryAndGrade(const HttpRequestPtr& req,
                                       std::function<void(const HttpResponsePtr&)>&& callback,
                                       const std::string& category, const std::string& grade)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::getByGrade(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                            const std::string& grade)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::create(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::updateById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                            const std::string& id)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::deleteById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                            const std::string& id)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::deleteAllByProfession(const HttpRequestPtr& req,
                                       std::function<void(const HttpResponsePtr&)>&& callback,
                                       const std::string& profession)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::deleteAllByGrade(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                                  const std::string& grade)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Assignment::deleteAllByCategory(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                                     const std::string& category)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
