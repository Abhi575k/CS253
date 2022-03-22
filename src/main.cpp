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
         return crow::mustache::load("index.html").render(); });
    CROW_ROUTE(app, "/login")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("login.html").render(); });
    CROW_ROUTE(app, "/register")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("register.html").render(); });
    CROW_ROUTE(app, "/forgot-password")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("password.html").render(); });
    CROW_ROUTE(app, "/password")
    ([]
     {
         crow::mustache::context ctx;
         return crow::mustache::load("resetPassword.html").render(); 
    });
    CROW_ROUTE(app, "/posts")
        .methods("POST"_method)([](const crow::request &req)
                                {

        crow::multipart::message msg(req);
        crow::json::wvalue x = {{"email", msg.parts[0].body}, {"password", msg.parts[1].body}};
  
        return x["email"]; });
    // set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
}
