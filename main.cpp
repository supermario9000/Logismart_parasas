#include "parasai.cpp"

void aprasymas(string versija)
{
    cout<<"Jus naudojates Logismart elektroninio paraso generatoriumi."<<endl;
    cout<<"Visu virusu, kuriuos instaliavote su sia programa, autoriu teises ir patentai priklauso Ismanioji Logistika, UAB (2025)"<<endl;
    cout<<"Jus naudojates ";
    cout<<versija<<" versija.\n"<<endl;
    cout<<"Gero naudojimo!"<<endl;
}

void ivedimas(string &vardas_pavarde, string &pareigos, string &elpastas, string &numeris)
{
    string input;
    //vardo ivedimas
    //naudojamas linijos nuskaitymui, vedant varda ir pavarde
    cout<<"Iveskite savo varda ir pavarde (Vardenis Pavardenis): ";
    while(true)
    {
        getline(cin,vardas_pavarde);
        cout<<"Jus ivedete: '"<<vardas_pavarde<<"' ar viskas teisingai?[taip/ne]:"<<endl;
        try {
            cin>>input;
            cin.ignore(numeric_limits<streamsize>::max(), L'\n');
            if(cin.fail() || (input!="taip"&&input!="ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
        }
        catch (const std::out_of_range& e) {
            input="";
            cout << e.what() << endl;
            cout<<"Bandykite ivesti varda ir pavarde is naujo: ";
        }
        if(input=="taip") break;
        vardas_pavarde[0] = {'\0'};//pazymime masyva kaip tuscia
    }
    //=======================================
    //pareigu ivedimas
    cin.clear();
    cout<<"Iveskite savo einamas pareigas: ";
    while(true)
    {
        getline(cin, pareigos);
        cout<<"Jus ivedete: '"<<pareigos<<"' ar viskas teisingai?[taip/ne]:"<<endl;
        try {
            cin>>input;
            cin.ignore(numeric_limits<streamsize>::max(), L'\n');
            if(cin.fail() || (input!="taip"&&input!="ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
        }
        catch (const std::out_of_range& e) {
            input="";
            cout << e.what() << endl;
            cout<<"Bandykite ivesti pareigas is naujo: ";
        }
        if(input=="taip") break;
        pareigos[0] = {'\0'};
    }
    //=======================================
    //el pasto ivedimas
    cin.clear();
    cout<<"Iveskite savo el. pasto adresa: ";
    while(true)
    {
        cin>>elpastas;
        cout<<"Jus ivedete: '"<<elpastas<<"' ar viskas teisingai?[taip/ne]:"<<endl;
        try {
            cin>>input;
            cin.ignore(numeric_limits<streamsize>::max(), L'\n');
            if(cin.fail() || (input!="taip"&&input!="ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
        }
        catch (const std::out_of_range& e) {
            input="";
            cout << e.what() << endl;
            cout<<"Bandykite ivesti el. pasta is naujo: ";
        }
        if(input=="taip") break;
        elpastas="";
    }
    //==============================================
    //numerio ivedimas
    cin.clear();
    cout<<"Ar noresite, kad parase butu jusu tel. numeris?[taip/ne]: ";
    while(true)
    {
        try {
            cin>>input;
            cin.ignore(numeric_limits<streamsize>::max(), L'\n');
            if(cin.fail() || (input!="taip"&&input!="ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
            break; //gerai ivedus nutraukiame nesibaigianti cikla
        }
        catch (const std::out_of_range& e) {
            cin.clear();
            cout << e.what() << endl;
        }
    }
    
    if(input=="taip")
    {
        cout<<"Iveskite savo telefono numeri (be tarpu): ";
        while(true)
        {
            cin>>numeris;
            cout<<"Jus ivedete: '"<<numeris<<"' ar viskas teisingai?[taip/ne]:"<<endl;
            try {
                cin>>input;
                cin.ignore(numeric_limits<streamsize>::max(), L'\n');
                if(cin.fail() || (input!="taip"&&input!="ne") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'taip' arba 'ne'!");
            }
            catch (const std::out_of_range& e) {
                input="";
                cout << e.what() << endl;
                cout<<"Bandykite ivesti numeri is naujo: ";
            }
            if(input=="taip") break;
            numeris="";
        }
    }
    else numeris="nera";//jei numerio nera, mes jo neisvesime
    //===============================================
    //pabaiga.
}

int main()
{
    string vardas_pavarde, pareigos, elpastas, numeris, versija="0.00.0.11";
    string kalba; //versijavimas: 0.-UI versija; 00.-github; 0.-oficiali versija; 11-subversija
    aprasymas(versija);//parodome, kokia programa zmogus naudojasi
    ivedimas(vardas_pavarde, pareigos, elpastas, numeris);
    cout<<"Kokios kalbos paraso noresite?[lt/en/de]: ";
    while(true)
    {
        try {
            cin>>kalba;
            cin.ignore(numeric_limits<streamsize>::max(), L'\n');
            if(cin.fail() || (kalba!="lt"&&kalba!="en"&&kalba!="de") ) throw out_of_range("Netinkama ivestis, galite ivesti tik 'lt', 'en' arba 'de'!");
            break; //gerai ivedus nutraukiame nesibaigianti cikla
        }
        catch (const std::out_of_range& e) {
            cin.clear();
            cout <<e.what() << endl;
        }
    }
    paras_generator(vardas_pavarde, pareigos, elpastas, numeris, kalba);
    cout<<"Ar patiko programa?:)"<<endl;
    string patiko;
    cin>>patiko;
    return 0;
}