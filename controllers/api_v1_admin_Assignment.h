#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api::v1::admin
{
    class Assignment : public drogon::HttpController<Assignment>
    {
    public:
        METHOD_LIST_BEGIN
        // use METHOD_ADD to add your custom processing function here;
        // METHOD_ADD(Assignment::get, "/{2}/{1}", Get); // path is /api/v1/admin/Assignment/{arg2}/{arg1}
        // METHOD_ADD(Assignment::your_method_name, "/{1}/{2}/list", Get); // path is
        // /api/v1/admin/Assignment/{arg1}/{arg2}/list ADD_METHOD_TO(Assignment::your_method_name,
        // "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
        METHOD_ADD(Assignment::getById, "/get-by-id?id={id}", Get);
        METHOD_ADD(Assignment::getByName, "/get-by-name?name={name}", Get);
        METHOD_ADD(Assignment::getByProfession, "/get-by-profession?profession={profession}", Get);
        METHOD_ADD(Assignment::getByProfessionAndCategory,
                   "/get-by-profession-and-category?profession={profession}&category={category}", Get);
        METHOD_ADD(Assignment::getByProfessionAndGrade,
                   "/get-by-profession-and-grade?profession={profession}&grade={grade}", Get);
        METHOD_ADD(Assignment::getByCategory, "/get-by-category?category={category}", Get);
        METHOD_ADD(Assignment::getByCategoryAndGrade, "/get-by-category-and-grade?category={category}&grade={grade}",
                   Get);
        METHOD_ADD(Assignment::getByGrade, "/get-by-grade?grade={grade}", Get);
        METHOD_ADD(Assignment::create, "/create", Post);
        METHOD_ADD(Assignment::updateById, "/update-by-id", Put);
        METHOD_ADD(Assignment::deleteById, "/delete-by-id?id={id}", Delete);
        METHOD_ADD(Assignment::deleteAllByProfession, "/delete-all-by-profession?profession={profession}", Delete);
        METHOD_ADD(Assignment::deleteAllByGrade, "/delete-all-by-grade?grade={grade}", Delete);
        METHOD_ADD(Assignment::deleteAllByCategory, "/delete-all-by-category?category={category}", Delete);

        METHOD_LIST_END
        // your declaration of processing function maybe like this:
        // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1,
        // std::string p2); void your_method_name(const HttpRequestPtr& req, std::function<void (const
        // HttpResponsePtr &)> &&callback, double p1, int p2) const;
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
        void updateById(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                        const std::string &id);
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
