#include <../Services/JSONHandler.cpp>
#include <../Controller/Server.h>
//#include "../Entities/Haina.h"
//#include "../Entities/Umeras.h"
#include "../Services/HaineManager.h"
#include "../Services/SearchEngine.h"
#include "../Services/DulapManager.h"
#include "../Interface/Interface.h"
#include <string>
#include <thread>
#include <map>
#include <curl/curl.h>

static size_t WriteCallBack(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


int main(int argc, char **argv) { //adaugare parametrii linie de comanda
    //Testare functionalitate JSONHandler
    /*ifstream file("../Repositories/TestInput.json");
    string s =  JSONHandler::parseJSONFromFile(file);
    cout << s;
    file.close();
     */

    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    std::string locationInput;

    bool ok = false;
    std::cout << "Please input your location in this exact format: Bucharest,ro\n";

    while (!ok) {
        std::cin >> locationInput;
        if (std::regex_match(locationInput, std::regex("^[A-Z][a-z]+[,]([a-z]{2})$"))) {
            ok = true;
        }
        else {
            std::cout << "Please try again. Example: Focsani,ro\n";
        }
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);

    std::string requestChunk1 = "pro.openweathermap.org/data/2.5/weather?q=";
    std::string requestChunk2 = "&APPID=e564a233be5f06b32ca4763b2bcda304&units=metric";
    std::string requestFull = requestChunk1 + locationInput + requestChunk2;

    int n = requestFull.length();
    char weatherParam[n+1];
    strcpy(weatherParam,requestFull.c_str());

    curl = curl_easy_init();
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, weatherParam);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

//        std::cout << readBuffer;

        json jsonBuffer = JSONHandler::getJSONFromString(readBuffer);
        std::string::size_type sz;
        double temperatura = std::stod(to_string(jsonBuffer["main"]["temp"]), &sz);
        std::cout << "\nTemperatura este: " << temperatura << " C\n";

        if (res != CURLE_OK) {
            std::cout << stderr << " curl failed\n" << curl_easy_strerror(res);
        }
        curl_easy_cleanup(curl);

    }

    curl_global_cleanup();

//
//    sigset_t signals;
//    if (sigemptyset(&signals) != 0
//        || sigaddset(&signals, SIGTERM) != 0
//        || sigaddset(&signals, SIGINT) != 0
//        || sigaddset(&signals, SIGHUP) != 0
//        || pthread_sigmask(SIG_BLOCK, &signals, nullptr) != 0) {
//        perror("install signal handler failed");
//        return 1;
//    }

//    Port port(8080);
//    int thr = 2;
//    Address addr(Ipv4::any(), port);
//
//    Server stats(addr);
//    stats.init(thr);
//    stats.start();
//
//    int signal = 0;
//    int status = sigwait(&signals, &signal);
//    if (status == 0)
//    {
//        std::cout << " received signal " << signal << std::endl;
//    }
//    else
//    {
//        std::cerr << " sigwait returns " << status << std::endl;
//    }
//
//    stats.stop();
    Haina* h1 = new Haina("geaca verde", jacheta, Verde, casual, stofa);
    Haina* h2 = new Haina("rochie rosie", piesaUnica, Rosu, formal, matase);
    Haina* h3 = new Haina("blugi", pantaloni, Albastru, casual, denim);
    Haina* h4 = new Haina("tricou flori", top, Mov,casual, bumbac);
    Haina* h5 = new Haina("geaca fas", jacheta,Albastru, casual, fas);
    Haina* h6 = new Haina("rochie neagra", piesaUnica, Negru, sport, bumbac);
    Haina* h7 = new Haina("pantaloni de stofa", pantaloni, Maro, formal, stofa);
    Haina* h8 = new Haina("tricou sport", top, Rosu,sport, bumbac);
    Haina* h9 = new Haina("salopeta matasoasa", piesaUnica, Portocaliu, formal, matase);
    Haina* h10 = new Haina("sacou", jacheta, Bleumarin, business, lana);
    Haina* h11 = new Haina("blugi rupti", pantaloni, Gri, sport, denim);
    Haina* h12 = new Haina("ie traditionala", top, Alb,formal, in);
    Haina* h13 = new Haina("haina de blana", jacheta,Bej, casual, poliester);
    Haina* h14 = new Haina("camasa cu volane", top, Negru, casual, poliester);
    Haina* h15 = new Haina("camasa simpla", top, Alb, formal, bumbac);
    Haina* h16 = new Haina("tricou polo", top, Galben,sport, bumbac);
    Haina* h17 = new Haina("vesta de fas", jacheta,Negru, sport, fas);
    Haina* h18 = new Haina("fusta plisata", pantaloni, Gri, formal, stofa);
    Haina* h19 = new Haina("hanorac cu gluga", jacheta, Verde, sport, bumbac);
    Haina* h20 = new Haina("helanca", top, Bej,casual, poliester);



    h4->setNrPurtari(3);
    h5->setNrPurtari(1);
    h3->setNrPurtari(2);
    h10->setNrPurtari(4);
    h7->setNrPurtari(1);


    DulapManager DM("Dezinfectant", "Parfum");
    DM.getApa().setFull();
    std::thread t1 = std::thread(&DulapManager::sprayThread, &DM, 0.2, std::ref(DM.getApa()));

    DM.getDezinfectant().setFull();
    std::thread t2 = std::thread(&DulapManager::sprayThread, &DM, 0.1, std::ref(DM.getDezinfectant()));
    t1.join();
    t2.join();

    HaineManager haineManager(20);
    haineManager.introducereHaina(h1);
    haineManager.introducereHaina(h2);
    haineManager.introducereHaina(h3);
    haineManager.editareHaina(h1, "helanca", top, Bej,casual, poliester);
    //CLI *cli=new CLI();
    //cli->mainMenu(0);


    return 0;
}

