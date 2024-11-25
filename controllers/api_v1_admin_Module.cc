#include "api_v1_admin_Module.h"

using namespace api::v1::admin;

// Add definition of your processing function here
void Module::getAll(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::getById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                     const std::string& id)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::getByName(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                       const std::string& name)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::getByProfession(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                             const std::string& profession)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::getByProfessionAndCategory(const HttpRequestPtr& req,
                                        std::function<void(const HttpResponsePtr&)>&& callback,
                                        const std::string& profession, const std::string& category)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::getByProfessionAndGrade(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                                     const std::string& profession, const std::string& grade)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::getByCategory(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                           const std::string& category)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::getByCategoryAndGrade(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                                   const std::string& category, const std::string& grade)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::getByGrade(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                        const std::string& grade)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::create(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::updateById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::deleteById(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                        const std::string& id)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::deleteAllByProfession(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                                   const std::string& profession)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::deleteAllByGrade(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                              const std::string& grade)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
void Module::deleteAllByCategory(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback,
                                 const std::string& category)
{
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k501NotImplemented);
    callback(resp);
}
