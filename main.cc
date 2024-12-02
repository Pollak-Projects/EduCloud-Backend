#include <drogon/drogon.h>

drogon::orm::DbClientPtr eduCloudDbClientPtr;

int main()
{
    try
    {
        // Set HTTP listener address and port
        // drogon::app().addListener("127.0.0.1", 3300);
        // Load config file
        // drogon::app().loadConfigFile("../config.json");
        // This refused to work
        drogon::app().loadConfigFile("../config.yaml");
        // Run HTTP framework, the method will block in the internal event loop
        drogon::app().run();
        eduCloudDbClientPtr = drogon::app().getDbClient("educloud_default");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown exception occurred" << std::endl;
        return 1;
    }
    return 0;
}
