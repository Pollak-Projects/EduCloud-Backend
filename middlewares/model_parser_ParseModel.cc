#include "model_parser_ParseModel.h"

using namespace model_parser;

void ParseModel::invoke(const HttpRequestPtr &req,
    MiddlewareNextCallback &&nextCb,
    MiddlewareCallback &&mcb)
{

        if (req->path() == "/ some/ path") {
            // intercept directly
            mcb(HttpResponse::newNotFoundResponse(req));
            return;
        }
        // Do something before calling the next middleware
        nextCb([mcb = std::move(mcb)](const HttpResponsePtr &resp) {
            // Do something after the next middleware returns
            mcb(resp);
        });

}