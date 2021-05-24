//
// Created by cosmin on 24.05.2021.
//

#include "Server.h"

void Server::init(size_t thr = 2) {
    httpEndpoint->init();
    setupRoutes();
}

void Server::start() {
    httpEndpoint->setHandler(router.handler());
    httpEndpoint->serveThreaded();
}

void Server::stop() {
    httpEndpoint->shutdown();
}

void Server::setupRoutes() {
    using namespace Rest;
    Routes::Get(router, "/", Routes::bind(&Server::sayOk, this));
}

void Server::sayOk(const Rest::Request &request, Http::ResponseWriter response) {
    response.send(Http::Code::Ok);
}

