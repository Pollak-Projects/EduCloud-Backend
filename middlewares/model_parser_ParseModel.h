#pragma once

#include <drogon/HttpMiddleware.h>

using namespace drogon;

namespace model_parser {
    class ParseModel : public drogon::HttpMiddleware<ParseModel>
    {
    public:
        ParseModel(){};  // do not omit constructor

        virtual ~ParseModel()
        {
        }

        void invoke(const HttpRequestPtr &req,
            MiddlewareNextCallback &&nextCb,
            MiddlewareCallback &&mcb) override;
    };
}