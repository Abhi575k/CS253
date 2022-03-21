#include "crow.h"
#include <string>
#include <vector>
#include <chrono>
using namespace std;

int main()
{
    crow::SimpleApp app; // define your crow application

    // define your endpoint at the root directory
    CROW_ROUTE(app, "/")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("index.html").render();
     });
    CROW_ROUTE(app, "/login")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("login.html").render();
     });
    CROW_ROUTE(app, "/register")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("register.html").render();
     });
    CROW_ROUTE(app, "/forgot-password")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("password.html").render();
     });
    CROW_ROUTE(app, "/password")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("resetPassword.html").render();
     });
   CROW_ROUTE(app,"/posts")
    .methods("POST"_method)
    ([](const crow::request& req) {
   CROW_LOG_INFO<<"new output"<< crow::(req.body);
  
        return "hello";
        // auto x = crow::json::load(req.body);
        // if (x == nullptr)
        //     return crow::response(400);
        // auto userId = x["email"];
        // return userId;
       // Now here i want to call an external api, which response will used for some calculation over here.
      // External api method can be post,get and delete.

    // Do something something based on above external api response.
     //return crow response.
    });
    // set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
}
