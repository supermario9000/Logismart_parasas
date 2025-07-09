# __Versijų aprašymai (Release notes)__

Šiame dokumente galite pažiūrėti visas funkcijas, kurios buvo pridėtos su naujausiomis išleistomis versijomis.  
Versijos programoje nesutampa su github versijomis.

Šiuo metu programa nepalaikoma linux ir macOs sistemose. Kadangi neperku programų saugumo licensijos, programą windowsai mato kaip "virusą" ar "galimą virusą". Jei atidarius installer.msi jums išlenda mėlynas langas, reikia pasirinkti "read more" / "skaityti daugiau" ir leisti programą suinstaliuoti.  
Blogiausiu atveju atsisiųstos programos paleisti nepavyks nes windows defenderis blokuos kaip virusą. Tokiu atveju reikia paspausti iššokusį windows defenderio langą (iššoka apačioje dešinėje) ir per parametrus parinkti, kad neblokuotų programos... Kol kas labai liūdnai su tokiu veikimu, bandau sutvarkyti.

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

## __V.1.1(2)__

Ši versija buvo sukurta pataisyti nedidelę klaidą.  
*Pataisytas pašto adreso linkas. Dabar paspaudus el. paštą paraše sistema iš karto atidarys langą, kuriame bus galima rašyti laiška tam, kuris psirašė.

## __V.1.1__

Šios versijos atnaujinimai:
* Pridėtas pasirinkimas parodyti bendrai visus adresus po kompanijos logotipu.  
    Adresai paryškinami pagal pasirinktą kalbą (vokietijos sandėliams pateikiamas papildomas pasirinkimas pagal adresą.)
* Pridėtas lietuviškas sutikimas programos diegimo metu.

Sugeneruotų parašų, su visais funkcionalumais pavyzdys:  
![Example 2](https://github.com/user-attachments/assets/17e828b4-1315-4798-bc3b-7f9706c09860)


## __V.1.0 (lt_1)__

Pirminė versija.

Šios versijos funkcijos:
* Konsolinė c++ aplikacija su įdiegimo .msi failu.
* Nupieštos nuotraukos (išskyrus Logismart logotipą), kad nekiltų bėdų su autorių teisėmis (nors nelabai tikėtina, atsarga gėdos nedaro)
* Vardo, pareigų, el. pašto suvedimas su patikrinimu.
* Pasirinktinas telefono numerio suvedimas paraše. (Parašas generuojamas su arba be tel. nr.)
* Base64 užkoduotos nuotraukos, kad užimtų mažiau vietos ir visuose paštuose būtų atvaizduojamos vienodai (Thunderbird, Roundcube, Gmail, ir t.t.)
* Kiekviena nuotrauka nurodo į kažkokį adresą, taip neiškraipomos nuotraukos po išsiuntimo.
* Pateikiamas kalbos pasirinkimas, pagal kurį sugeneruojami atitinkamai lietuviški, angliški ir vokiški rekvizitai, paryškinama darbovietė po logotipu.
* Sugeneruojamas .html failas su parinktais parametrais ir iš karto paruoštas naudojimui.

Sugeneruotų parašų, su visais funkcionalumais pavyzdys:  
![Example 1](https://github.com/user-attachments/assets/24df9c2d-9fe7-431b-a898-99f5734915ba)  
(Pavyzdyje nėra vokiškų rekvizitų, juos galite matyti antros versijos pavyzdyje.)
