//
// Created by cosmin on 24.05.2021.
//

#ifndef SMARTDROBE_SERVER_H
#define SMARTDROBE_SERVER_H

#include <algorithm>

#include <pistache/net.h>
#include <pistache/http.h>
#include <pistache/peer.h>
#include <pistache/http_headers.h>
#include <pistache/cookie.h>
#include <pistache/router.h>
#include <pistache/endpoint.h>
#include <pistache/common.h>

#include <csignal>

using namespace Pistache;

class Server {
public:
    explicit Server (Address addr): httpEndpoint(std::make_shared<Http::Endpoint>(addr))
    { }

    void init(size_t thr);
    void start();
    void stop();

private:
    void setupRoutes();
    void sayOk(const Rest::Request& request, Http::ResponseWriter response);

    std::shared_ptr<Http::Endpoint> httpEndpoint;
    Rest::Router router;

};


#endif //SMARTDROBE_SERVER_H
