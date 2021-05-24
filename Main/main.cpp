#include <../Services/JSONHandler.cpp>
#include "Haina.h"
#include "HaineManager.h"
#include "SearchEngine.h"
#include "SearchEngine.cpp"
#include "DulapManager.h"
#include "DulapManager.cpp"
#include "Interface.cpp"
#include <string>
#include <thread>
#include <map>

int main(int argc, char **argv) { //adaugare parametrii linie de comanda
    //Testare functionalitate JSONHandler
    /*ifstream file("../Repositories/TestInput.json");
    string s =  JSONHandler::parseJSONFromFile(file);
    cout << s;
    file.close();
     */

    Haina h1("geaca verde", jacheta, Verde, casual, stofa);
    Haina h2("rochie rosie", piesaUnica, Rosu, formal, matase);
    Haina h3("blugi", pantaloni, Albastru, casual, denim);
    Haina h4("tricou flori", top, Mov,casual, bumbac);
    Haina h5("geaca fas", jacheta,Albastru, casual, fas);
    Haina h6("rochie neagra", piesaUnica, Negru, sport, bumbac);
    Haina h7("pantaloni de stofa", pantaloni, Maro, formal, stofa);
    Haina h8("tricou sport", top, Rosu,sport, bumbac);
    Haina h9("salopeta matasoasa", piesaUnica, Portocaliu, formal, matase);
    Haina h10("sacou", jacheta, Bleumarin, business, lana);
    Haina h11("blugi rupti", pantaloni, Gri, sport, denim);
    Haina h12("ie traditionala", top, Alb,formal, in);
    Haina h13("haina de blana", jacheta,Bej, casual, poliester);
    Haina h14("camasa cu volane", top, Negru, casual, poliester);
    Haina h15("camasa simpla", top, Alb, formal, bumbac);
    Haina h16("tricou polo", top, Galben,sport, bumbac);
    Haina h17("vesta de fas", jacheta,Negru, sport, fas);
    Haina h18("fusta plisata", pantaloni, Gri, formal, stofa);
    Haina h19("hanorac cu gluga", jacheta, Verde, sport, bumbac);
    Haina h20("helanca", top, Bej,casual, poliester);

    h4.setNrPurtari(3);
    h5.setNrPurtari(1);
    h3.setNrPurtari(2);
    h10.setNrPurtari(4);
    h7.setNrPurtari(1);

    map<int, Haina> haine;
    haine.insert(haine.begin(), pair<int, Haina>(1,h1));
    haine.insert(pair<int, Haina>(2,h2));
    haine.insert(pair<int, Haina>(3,h3));
    haine.insert(pair<int, Haina>(4,h4));
    haine.insert(pair<int, Haina>(5,h5));
    haine.insert(pair<int, Haina>(6,h6));
    haine.insert(pair<int, Haina>(7,h7));
    haine.insert(pair<int, Haina>(8,h14));
    haine.insert(pair<int, Haina>(9,h9));
    haine.insert(pair<int, Haina>(10,h10));
    haine.insert(pair<int, Haina>(11,h11));
    haine.insert(pair<int, Haina>(12,h12));
    for (auto& t: haine)
        std::cout << t.first << " " << t.second.afisare();
    std::cout <<"\n";

    SearchEngine se;
    map<int,Haina> testnume = se.cautare(haine, "rochie");
    for (auto& t: testnume)
        std::cout << t.first << " " << t.second.afisare();
    std::cout <<"\n";

    map<int,Haina> testtip = se.cautare(haine, jacheta);
    for (auto& t: testtip)
        std::cout << t.first << " " << t.second.afisare();
    std::cout <<"\n";

    map<int,Haina> testculoare = se.cautare(haine, Albastru);
    for (auto& t: testculoare)
        std::cout << t.first << " " << t.second.afisare();
    std::cout <<"\n";

    map<int,Haina> teststil = se.cautare(haine, formal);
    for (auto& t: teststil)
        std::cout << t.first << " " << t.second.afisare();
    std::cout <<"\n";

    map<int,Haina> testmaterial = se.cautare(haine, bumbac);
    for (auto& t: testmaterial)
        std::cout << t.first << " " << t.second.afisare();
    std::cout <<"\n";

    DulapManager DM("Dezinfectant", "Parfum");
    DM.getApa().setFull();
    std::thread t1 = std::thread(&DulapManager::sprayThread, &DM, 0.2, std::ref(DM.getApa()));

    DM.getDezinfectant().setFull();
    std::thread t2 = std::thread(&DulapManager::sprayThread, &DM, 0.1, std::ref(DM.getDezinfectant()));
    t1.join();
    t2.join();
//    cout<<(haine.find(3)==haine.end());
//    haine.erase(2);
//    haine.find(1)->second.setCuloare(Mov);
//    for ( auto &item : haine)
//        cout<<item.second.afisare()<<'\n';
//    HaineManager hm(haine, 4);
//    for ( auto &item :hm.getHaine())
//       cout<<item.second.afisare()<<'\n';
    //hm.editareHaina(h2, "Vesta", jacheta, Maro, formal,fas);
//    hm.introducereHaina("Costum", piesaUnica, Negru,formal, stofa);
//    hm.introducereHaina("Salopeta", piesaUnica, Galben,casual, bumbac);
    //  hm.stergereHaina(h1);
//    hm.introducereHaina("Salopeta", piesaUnica, Galben,casual, bumbac);
//    hm.vizualizareHaina(h3);

//    for ( auto &item :hm.getHaine())
//        cout<<item.second.afisare()<<'\n';
//    hm.generareTinuta(22, false,casual);

mainMenu(0);
    return 0;
}

