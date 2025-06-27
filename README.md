# __Versijų aprašymai (Release notes)__

Šiame dokumente galite pažiūrėti visas funkcijas, kurios buvo pridėtos su naujausiomis išleistomis versijomis.  
Versijos programoje nesutampa su github versijomis.

Šiuo metu programa nepalaikoma linux ir macOs sistemose.

__Naudojimosi instrukcija__  

* Atsisiūskite LogismartInstaller.msi ir jį paleiskite. (Windows gali bandyti blokuoti atsisiuntimą, tai reikia surasti, kaip viską leisti)
* Jei windows blokuoja, reikia pasirinkti „matyti daugiau“, ar kažką panašaus ir paspausti „Vis tiek paleisti programą“, ar kažką panašaus.
* Programa bus atsiųsta į __C:/ProgramFiles(x86)/LogismartGeneratorius__.
* Galite programą naudoti tiesiai iš atsisiuntimo aplanko, tačiau rekomenduojama programą nusikopijuoti į patogią lokaciją.

__Parašo naudojimo instrukcija__  

Kadangi Logismart naudoja Thunderbird ir pastas.serveriai.lt (Roundcube), tad yra 2 skirtingi būdai pridėti sugeneruotą parašą.  
__Rekomenduoju naudoti thunderbird__, nes jis failą naudoja tiesiogiai. Serverių pašte gali kilti problemų su nuotraukomis, formatavimu.  

_Thunderbird instrukcija:_  
* Apatiniame kairiajame kampe pasirinkti Settings -> Account Settings.
* Pažymėti "Attach the signature from a file instead (text, HTML, or image):"
* Pasirinkti sugeneruotą parašo failą.

_Serveriai.lt instrukcija_
* Prisijungti prie paskyros ir nueiti į Settings -> Identities.
* Pasirinkti el.paštą (identitetą), kurio parašą norite pakeisti.
* Pažymėti "HTML signature".
* Atsidaryti sugeneruotą parašą per Google (per kitas naršykles gali neteisingai rodyti raides).
* Nukopijuoti visą parašą (Ctrl + A ; Ctrl + C).
* Įklijuoti parašą ir išsaugoti pakeitimus.

## __V.1.1__

Šios versijos atnaujinimai:
* Pridėtas pasirinkimas parodyti bendrai visus adresus po kompanijos logotipu.  
    Adresai paryškinami pagal pasirinktą kalbą (vokietijos sandėliams pateikiamas papildomas pasirinkimas pagal adresą.)
* Pridėtas lietuviškas sutikimas programos diegimo metu.

## __V.1.0 (lt_1)__

Pirminė versija.

Šios versijos funkcijos:
* Konsolinė c++ aplikacija su įdiegimo .msi failu.
* Vardo, pareigų, el. pašto suvedimas su patikrinimu.
* Pasirinktinas telefono numerio suvedimas paraše. (Parašas generuojamas su arba be tel. nr.)
* Base64 užkoduotos nuotraukos, kad užimtų mažiau vietos ir visuose paštuose būtų atvaizduojamos vienodai (Thunderbird, Roundcube, Gmail, ir t.t.)
* Sugeneruojamas .html failas su parinktais parametrais ir iš karto paruoštas naudojimui.
