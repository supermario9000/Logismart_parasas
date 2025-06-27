#include "parasai.cpp"

void aprasymas(wstring versija)
{
    wcout<<L"Jūs naudojatės Logismart elektroninio parašo generatoriumi."<<endl;
    wcout<<L"Visų virusų, kuriuos instaliavote su šia programa, autorių teisės ir patentai priklauso Išmanioji Logistika, UAB (2025)"<<endl;
    wcout<<L"Jūs naudojatės ";
    wcout<<versija<<L" versija.\n"<<endl;
    wcout<<L"Gero naudojimo!"<<endl;
}

void praleiskenter() {
    while (wcin.get() != L'\n'); //praleidzia \n ir taip programa nestringa
}

void ivedimas(wstring &vardas_pavarde, wstring &pareigos, wstring &elpastas, wstring &numeris)
{
    wstring input;
    //vardo ivedimas
    //naudojamas linijos nuskaitymui, vedant varda ir pavarde
    wcout<<L"Įveskite savo vardą ir pavardę (Vardenis Pavardenis): ";
    while(true)
    {
        getline(wcin,vardas_pavarde);
        wcout<<L"Jūs įvedėte: '"<<vardas_pavarde<<L"' ar viskas teisingai?[taip/ne]:"<<endl;
        try {
            wcin>>input;
            praleiskenter();
            if(wcin.fail() || (input!=L"taip"&&input!=L"ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
        }
        catch (const std::out_of_range& e) {
            input=L"";
            wcout << e.what() << endl;
            wcout<<L"Bandykite įvesti vardą ir pavardę is naujo: ";
        }
        if(input==L"taip") break;
        else if (input==L"ne") wcout<<L"Bandykite įvesti iš naujo: ";
        vardas_pavarde=L"";
        praleiskenter();
    }
    //=======================================
    //pareigu ivedimas
    wcin.clear();
    praleiskenter();
    wcout<<L"Įveskite savo einamas pareigas: ";
    while(true)
    {
        getline(wcin, pareigos);
        wcout<<L"Jūs įvedėte: '"<<pareigos<<L"' ar viskas teisingai?[taip/ne]:"<<endl;
        try {
            wcin>>input;
            praleiskenter();
            if(wcin.fail() || (input!=L"taip"&&input!=L"ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
        }
        catch (const std::out_of_range& e) {
            input=L"";
            wcout << e.what() << endl;
            wcout<<L"Bandykite įvesti pareigas iš naujo: ";
        }
        if(input==L"taip") break;
        else if (input==L"ne") wcout<<L"Bandykite įvesti iš naujo: ";
        pareigos=L"";
        praleiskenter();
    }
    //=======================================
    //el pasto ivedimas
    wcin.clear();
    praleiskenter();
    wcout<<L"Įveskite savo el. pašto adresą: ";
    while(true)
    {
        wcin>>elpastas;
        wcout<<L"Jūs įvedėte: '"<<elpastas<<L"' ar viskas teisingai?[taip/ne]:"<<endl;
        try {
            wcin>>input;
            praleiskenter();
            if(wcin.fail() || (input!=L"taip"&&input!=L"ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
        }
        catch (const std::out_of_range& e) {
            input=L"";
            wcout << e.what() << endl;
            wcout<<L"Bandykite įvesti el. paštą iš naujo: ";
        }
        if(input==L"taip") break;
        else if (input==L"ne") wcout<<L"Bandykite įvesti iš naujo: ";
        elpastas=L"";
        praleiskenter();
    }
    //==============================================
    //numerio ivedimas
    wcin.clear();
    praleiskenter();
    wcout<<L"Ar norėsite, kad paraše būtų jūsų tel. numeris?[taip/ne]: ";
    while(true)
    {
        try {
            wcin>>input;
            praleiskenter();
            if(wcin.fail() || (input!=L"taip"&&input!=L"ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
            break; //gerai ivedus nutraukiame nesibaigianti cikla
        }
        catch (const std::out_of_range& e) {
            wcin.clear();
            wcout << e.what() << endl;
        }
        praleiskenter();
    }
    
    if(input==L"taip")
    {
        wcout<<L"Įveskite savo telefono numerį (be tarpu): ";
        while(true)
        {
            wcin>>numeris;
            wcout<<L"Jūs įvedėte: '"<<numeris<<L"' ar viskas teisingai?[taip/ne]:"<<endl;
            try {
                wcin>>input;
                praleiskenter();
                if(wcin.fail() || (input!=L"taip"&&input!=L"ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
            }
            catch (const std::out_of_range& e) {
                input=L"";
                wcout << e.what() << endl;
                wcout<<L"Bandykite įvesti numerį iš naujo: ";
            }
            if(input==L"taip") break;
            else if (input==L"ne") wcout<<L"Bandykite įvesti iš naujo: ";
            numeris=L"";
            praleiskenter();
        }
    }
    else numeris=L"nera";//jei numerio nera, mes jo neisvesime
    //===============================================
    //pabaiga.
}

int main()
{
    #ifdef _WIN32
    #include <windows.h>
    SetConsoleCP(CP_UTF8);               // Set console input code page
    SetConsoleOutputCP(CP_UTF8);         // Set console output code page
    _setmode(_fileno(stdout), _O_U8TEXT); // Enable wide output
    _setmode(_fileno(stdin), _O_U16TEXT); // Enable wide input
    #endif

    //lietuviku ir vokisku simboliu (UTF 8) leidimas
    locale::global(locale(""));

    wcin.imbue(locale());
    wcout.imbue(locale());

    wstring vardas_pavarde, pareigos, elpastas, numeris, versija=L"0.01.1.20";//versijavimas: 0.-UI versija; 00.-github; 0.-oficiali versija; 11-subversija
    wstring kalba, adresai, vokadr; //kintamieji filtravimui
    aprasymas(versija);//parodome, kokia programa zmogus naudojasi
    ivedimas(vardas_pavarde, pareigos, elpastas, numeris);
    wcout<<L"Kokios kalbos parašo norėsite?[lt/en/de]: ";
    while(true)
    {
        try {
            wcin>>kalba;
            praleiskenter();
            if(wcin.fail() || (kalba!=L"lt"&&kalba!=L"en"&&kalba!=L"de") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'lt', 'en' arba 'de'!");
            break; //gerai ivedus nutraukiame nesibaigianti cikla
        }
        catch (const std::out_of_range& e) {
            wcin.clear();
            wcout <<e.what() << endl;
        }
        praleiskenter();
    }

    wcout<<L"Ar norėsite paraše matyti visų sandėlių adresus? Pasirinkdami \"ne\", paraše turėsite tik savo darbovietės šalį, parinktą pagal kalbą. [taip/ne]: ";
    while(true)
    {
        praleiskenter();
        try {
            wcin>>adresai;
            praleiskenter();
            if(wcin.fail() || (adresai!=L"taip"&&adresai!=L"ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
            break; //gerai ivedus nutraukiame nesibaigianti cikla
        }
        catch (const std::out_of_range& e) {
            wcin.clear();
            wcout <<e.what() << endl;
            wcout<<L"Bandykite iš naujo:";
        }
    }

    if(adresai==L"taip"&&kalba==L"de") {
        wcout<<L"Kuriame Vokietijos sandėlyje dirbate?"<<endl;
        wcout<<L"1 - Schlitzer str."<<endl;
        wcout<<L"2 - Orber str."<<endl;
        while(true)
        {
            praleiskenter();
            try {
                wcin>>vokadr;
                praleiskenter();
                if(wcin.fail() || (vokadr!=L"1"&&vokadr!=L"2") ) throw out_of_range("Netinkama ivestis, galite ivesti tik '1' arba '2'!");
                break; //gerai ivedus nutraukiame nesibaigianti cikla
            }
            catch (const std::out_of_range& e) {
                wcin.clear();
                wcout <<e.what() << endl;
                wcout<<L"Bandykite iš naujo:";
            }
        }
    }

    paras_generator(vardas_pavarde, pareigos, elpastas, numeris, kalba, adresai, vokadr);
    wcout<<L"Ar patiko programa?:)"<<endl;
    wstring patiko;
    wcin>>patiko;
    return 0;
}