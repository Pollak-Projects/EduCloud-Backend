#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api::v1::admin
{
    class User : public drogon::HttpController<User>
    {
    public:
        METHOD_LIST_BEGIN
        // use METHOD_ADD to add your custom processing function here;
        // METHOD_ADD(User::get, "/{2}/{1}", Get); // path is /api/v1/admin/User/{arg2}/{arg1}
        // METHOD_ADD(User::your_method_name, "/{1}/{2}/list", Get); // path is
        // /api/v1/admin/User/{arg1}/{arg2}/list ADD_METHOD_TO(User::your_method_name,
        // "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
        METHOD_ADD(User::getAll, "/get-all", Get);
        METHOD_ADD(User::getById, "/get-by-id?id={id}", Get);
        METHOD_ADD(User::create, "/create", Post);
        METHOD_ADD(User::updateById, "/update-by-id", Put);
        METHOD_ADD(User::deleteById, "/delete-by-id?id={id}", Delete);
        ADD_METHOD_TO(User::login, "/api/v1/login", Post);

        METHOD_LIST_END
        // your declaration of processing function maybe like this:
        // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1,
        // std::string p2); void your_method_name(const HttpRequestPtr& req, std::function<void (const
        // HttpResponsePtr &)> &&callback, double p1, int p2) const;
        void getAll(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void getById(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                     const std::string &id);
        void create(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void updateById(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void deleteById(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void login(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
    };
} // namespace api::v1::admin
