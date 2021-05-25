#include "Interface.h"
#include "HaineManager.cpp"
#include <stdio.h>
#include <iostream>
#include <limits>

using std::numeric_limits;

void CLI::mainMenu(const int &menuPage) {
    int newPage = -1;
    HaineManager hm(10);
    switch (menuPage) {
        case 0: {
            if (this->lang == en) {
                std::cout << "Welcome to SmartDrobe!\n";
                std::cout << "What can I help you with? \\342\\230\\272 \n" <<
                          "Enter one of the numbers below to let me know!\n";
                // \342\230\272 este smiley face
                std::cout << "1. Consult outfit recommendations for today.\n" <<
                          "2. Check what the weather is going to be.\n" <<
                          "3. View my upcoming events.\n" <<
                          "4. Modify wardrobe.\n" <<
                          "5. See hangers.\n" <<
                          "6. Access controls and settings.\n";
                for (;;) {
                    std::cout << "So which one will it be? ";
                    if (std::cin >> newPage && newPage > 0 && newPage < 7) {
                        std::cout << "Success!";
                        break;
                    } else {
                        std::cout << "I asked you to choose one of the given numbers! \\342\\230\\272" << std::endl;
                        std::cout << "Let's try again!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            } else {
                std::cout << "SmartDrobe îți stă la dispoziție!\n";
                std::cout << "Cum te pot ajuta? \\342\\230\\272 \n"
                          << "Introdu unul dintre numerele comenzilor de mai jos!\n";
                std::cout << "1. Consultă recomandările de ținute pentru azi.\n" <<
                          "2. Verifică starea meteo.\n" <<
                          "3. Vezi evenimentele imediat viitoare.\n" <<
                          "4. Modifcă articolele din dulap.\n" <<
                          "5. Vezi umerașele.\n" <<
                          "6. Accesează setările.\n";
                for (;;) {
                    std::cout << "Așadar, ce alegi? ";
                    if (std::cin >> newPage && newPage > 0 && newPage < 7) {
                        std::cout << "Succes!";
                        break;
                    } else {
                        std::cout << "Trebuie să alegi una dintre opțiunile valabile! \\342\\230\\272" << std::endl;
                        std::cout << "Să încercăm din nou!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            }
            break;
        }
        case 1: {
            int weatherFilter = 0;
            int eventFilter = 0;
            if (this->lang == en) {
                std::cout
                        << "If you'd like an outfit recommendation based on the weather today, apply one of the filters below:\n";
                std::cout << "1. ice cold, harsh winter, heavy snowing\n" <<
                          "2. cold winter, mild snowing or no snowing at all\n" <<
                          "3. very cold autumn, strong wind, heavy rain\n" <<
                          "4. regular to soft fall, maybe windy and a little rainy\n" <<
                          "5. cool spring, cloudy sky, breezy or even muggy\n" <<
                          "6. warm spring, sunny and pleasant, low humidity\n" <<
                          "7. average summer, hot and bright, clear skies\n" <<
                          "8. burning hot, boiling summer, sweaty heatwaves\n";
                std::cout << "Select the line that best describes today's weather by entering its number!\n" <<
                          "Be careful! Entering any number outside the list will not apply any filter! ";
                std::cin >> weatherFilter;
                std::cout
                        << "If you'd like an outfit recommendation based on the event you're attending today, apply one of the filters below:\n";
                std::cout << "1. sports and physical activities\n" <<
                          "2. casual, leisure activities\n" <<
                          "3. professional, business setting\n" <<
                          "4. cocktail party, clubbing\n" <<
                          "5. simple but formal events\n" <<
                          "6. fancy, glamorous, highly sophisticated occasions\n";
                std::cout << "Select the line that best describes today's plans by entering its number!\n" <<
                          "Be careful! Entering any number outside the list will not apply any filter! ";
                std::cin >> eventFilter;
            } else {
                std::cout
                        << "Aplică unul dintre filtrele de mai jos pentru a primi recomandări pe baza condițiilor meteo:\n";
                std::cout << "1. iarnă agresivă, ninsori puternice, gheață\n" <<
                          "2. iarnă friguroasă, ninsoare blândă\n" <<
                          "3. toamnă rece, vânt puternic, ploaie abundentă\n" <<
                          "4. toamnă obișnuită, vânt și ploaie ușoare\n" <<
                          "5. primăvară răcoroasă, cer înnorat, vreme umedă\n" <<
                          "6. primăvară călduroasă, senin și plăcut, vreme uscată\n" <<
                          "7. vară obișnuită, călduroasă și luminoasă, cer limpede\n" <<
                          "8. vară deosebit de fierbinte, valuri copleșitoare de căldură\n";
                std::cout << "Selectează cea mai fidelă descriere a vremii de afară introducând numărul ei!\n" <<
                          "Atenție! Dacă tastezi un număr ce nu corespunde niciunei descrieri, nu voi putea aplica niciun filtru! ";
                std::cin >> weatherFilter;
                std::cout
                        << "Aplică unul dintre filtrele de mai jos pentru a primi recomandări pe baza activității tale de astăzi:\n";
                std::cout << "1. sport, activități fizice \n" <<
                          "2. activități comune și comode\n" <<
                          "3. mediu profesional, zi de muncă la birou\n" <<
                          "4. petrecere de club, discotecă\n" <<
                          "5. eveniment simplu, dar formal\n" <<
                          "6. ocazie ceremonioasă, sofisticată, tip gală\n";
                std::cout << "Selectează cea mai fidelă descriere a programului tău introducând numărul ei!\n" <<
                          "Atenție! Dacă tastezi un număr ce nu corespunde niciunei descrieri, nu voi putea aplica niciun filtru! ";
                std::cin >> eventFilter;
            }
            break;
        }
        case 2: //nu tine de menu interface, te trimite la aplicatia/ site ul cu prognoze
            break;
        case 3: //nu tine de menu interface, te trimite la evenimentele din Google Calendar
            break;
        case 4: {
            int contentAction = 0;
            if (this->lang == en) {
                std::cout << "So you want to modify my content! What exactly will you do?\n";
                std::cout << "1. Add a new clothing item.\n";
                std::cout << "2. Edit one of the clothing items.\n";
                std::cout << "3. Delete a clothing item.\n";
                for (;;) {
                    std::cout << "Let me know your intention by typing the number of the upcoming action! ";
                    if (std::cin >> contentAction && contentAction > 0 && contentAction < 4) {
                        std::cout << "Success!";
                        break;
                    } else {
                        std::cout << "Please don't make up your own actions! \\342\\230\\272" << std::endl;
                        std::cout << "Remember! Only the numbers from my list are available!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            } else {
                std::cout << "Îmi modifici conținutul? În ce mod mai exact?\n";
                std::cout << "1. Adaug un nou articol vestimentar.\n";
                std::cout << "2. Editez un articol vestimentar cunoscut.\n";
                std::cout << "3. Elimin un articol vestimentar.\n";
                for (;;) {
                    std::cout << "Introdu numărul acțiunii ca să știu și eu ce faci! ";
                    if (std::cin >> contentAction && contentAction > 0 && contentAction < 4) {
                        switch (contentAction) {
                            case 1:
                            {
                                std::string nume;
                                int culoare;
                                int material;
                                int stil;
                                int piesa;
                                std::cout << "Introdu denumirea articolului vestimentar: ";
                                std::cin >> nume;
                                for (;;) {
                                    std::cout << "Alege culoarea articolului vestimentar: ";
                                    std::cout << "1. Alb\n 2. Negru\n 3. Albastru\n 4. Verde\n 5. Galben\n "
                                              << "6. Rosu\n 7. Portocaliu\n 8. Bleumarin\n 9. Gri\n 10. Bej\n 11. Maro\n 12. Mov\n";
                                    if (std::cin >> culoare && culoare > 0 && culoare < 13) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege materialul articolului vestimentar: ";
                                    std::cout << "1. poliester\n 2. bumbac\n 3. stofa\n 4. denim\n 5. matase\n "
                                              << "6. in\n 7. fas\n 8. lana\n";
                                    if (std::cin >> material && material > 0 && material < 9) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege stilul articolului vestimentar: ";
                                    std::cout << "1. casual\n 2. sport\n 3. business\n 4. formal\n";
                                    if (std::cin >> stil && stil > 0 && stil < 5) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                for (;;) {
                                    std::cout << "Alege piesa articolului vestimentar: ";
                                    std::cout << "1. jacheta\n 2. top\n 3. pantaloni\n 4. piesa unica\n";
                                    if (std::cin >> piesa && piesa > 0 && piesa < 5) {
                                        break;
                                    } else {
                                        std::cin.clear();
                                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                    }
                                }
                                hm.introducereHaina(nume, (PiesaVestimentara) piesa, (Culoare) culoare, (Stil) stil,(Material) material);
                        break;
                        }
                        case 2:{
//                                cout<<"Alege numarul umeului pe care se afla articolul vestimentar pe care vrei sa-l editezi!";
//                                for(auto &item: hm.getHaine()){
//                                    cout<<item.first.getIndex()<<" "<<item.second.afisare()<<'\n';
//                                }
//                                if (std::cin >> nrUmeras && nrUmeras > 0 && piesa < 5)
//TODO

                        }
                        case 3:{

                        }
                    }
                    break;
                    } else {
                        std::cout << "Te rog nu inventa acțiuni! \\342\\230\\272" << std::endl;
                        std::cout << "Ține minte! Numai acțiunile din lista mea sunt acceptate!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
            }
            break;
        }

        case 5: //metoda de a afisa umerasele cu status liber/ ocupat
            break;
        case 6: //vezi starea consumabilelor?
            break;
    }
    mainMenu(newPage);
}