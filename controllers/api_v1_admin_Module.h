#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api::v1::admin
{
    class Module : public drogon::HttpController<Module>
    {
    public:
        METHOD_LIST_BEGIN
        // use METHOD_ADD to add your custom processing function here;
        // METHOD_ADD(Module::get, "/{2}/{1}", Get); // path is /api/v1/admin/Module/{arg2}/{arg1}
        // METHOD_ADD(Module::your_method_name, "/{1}/{2}/list", Get); // path is
        // /api/v1/admin/Module/{arg1}/{arg2}/list ADD_METHOD_TO(Module::your_method_name,
        // "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
        METHOD_ADD(Module::getAll, "/get-all", Get);
        METHOD_ADD(Module::getById, "/get-by-id?id={id}", Get);
        METHOD_ADD(Module::getByName, "/get-by-name?name={name}", Get);
        METHOD_ADD(Module::getByProfession, "/get-by-profession?profession={profession}", Get);
        METHOD_ADD(Module::getByProfessionAndCategory,
                   "/get-by-profession-and-category?profession={profession}&category={category}", Get);
        METHOD_ADD(Module::getByProfessionAndGrade,
                   "/get-by-profession-and-grade?profession={profession}&grade={grade}", Get);
        METHOD_ADD(Module::getByCategory, "/get-by-category?category={category}", Get);
        METHOD_ADD(Module::getByCategoryAndGrade, "/get-by-category-and-grade?category={category}&grade={grade}", Get);
        METHOD_ADD(Module::getByGrade, "/get-by-grade?grade={grade}", Get);
        METHOD_ADD(Module::create, "/create", Post);
        METHOD_ADD(Module::updateById, "/update-by-id", Put);
        METHOD_ADD(Module::deleteById, "/delete-by-id?id={id}", Delete);
        METHOD_ADD(Module::deleteAllByProfession, "/delete-all-by-profession?profession={profession}", Delete);
        METHOD_ADD(Module::deleteAllByGrade, "/delete-all-by-grade?grade={grade}", Delete);
        METHOD_ADD(Module::deleteAllByCategory, "/delete-all-by-category?category={category}", Delete);

        METHOD_LIST_END
        // your declaration of processing function maybe like this:
        // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1,
        // std::string p2); void your_method_name(const HttpRequestPtr& req, std::function<void (const
        // HttpResponsePtr &)> &&callback, double p1, int p2) const;
        void getAll(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void getById(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                     const std::string &id);
        void getByName(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                       const std::string &name);
        void getByProfession(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                             const std::string &profession);
        void getByProfessionAndCategory(const HttpRequestPtr &req,
                                        std::function<void(const HttpResponsePtr &)> &&callback,
                                        const std::string &profession, const std::string &category);
        void getByProfessionAndGrade(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                                     const std::string &profession, const std::string &grade);
        void getByCategory(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                           const std::string &category);
        void getByCategoryAndGrade(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                                   const std::string &category, const std::string &grade);
        void getByGrade(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                        const std::string &grade);
        void create(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void updateById(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void deleteById(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                        const std::string &id);
        void deleteAllByProfession(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                                   const std::string &profession);
        void deleteAllByGrade(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                              const std::string &grade);
        void deleteAllByCategory(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                                 const std::string &category);
    };
} // namespace api::v1::admin
