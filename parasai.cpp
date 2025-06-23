#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <locale>
#include <string>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <codecvt>
#endif

using namespace std;

string wstring_to_utf8(const wstring& wstr) {
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

void paras_generator(wstring vardas_pavarde, wstring pareigos, wstring elpastas, wstring numeris, wstring kalba)
{
    #ifdef _WIN32
    SetConsoleCP(CP_UTF8);               // Set console input code page
    SetConsoleOutputCP(CP_UTF8);         // Set console output code page
    _setmode(_fileno(stdout), _O_U8TEXT); // Enable wide output
    _setmode(_fileno(stdin), _O_U16TEXT); // Enable wide input
    #endif

    wstring pavadinimas;
    wcout<<L"Kaip noresite pavadinti paraso faila?: ";
    wcin>>pavadinimas;
    string utf8_filename = wstring_to_utf8(pavadinimas + L".html");
    wofstream lt(utf8_filename);
    lt.imbue(std::locale("en_US.UTF-8"));  // Or an appropriate UTF-8 locale for your system

    if (!lt.is_open()) {
        wcerr << L"Failo sukurti nepavyko: " << utf8_filename.c_str() << endl;
        return;
    }
    lt<<L"<body>\n<em>Pagarbiai, Best Regards, Freundliche Grüße, </em><br /><br />\n<p style=\"padding-left:8px; margin:0\"><strong>"<<vardas_pavarde<<L"</strong><br />\n"<<pareigos<<L" <br />\n</p>\n"<<endl;

    lt<<L"<table style=\"font-family: Arial, sans-serif; font-size: 14px; color: #333;\">\n"
      <<L"<tr>\n  <td style=\"padding-left: 8px;\">\n  <a href=\"mailto:"<<elpastas<<L"\">\n"
      <<L"  <img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAACWCAYAAAAouC1GAAAAAXNSR0IArs4c6QAAATxJREFUeJzt\n"
      <<L"3bERwjAQAEFg6IKMNqifNsioAxogeGYMPsNurMDWjYK3Au92AAAAAAAAAAAAAABQt58uvJ7Oj88+\n"
      <<L"ym+73G+jvT58/lF4hyAxgsQIEiNIjCAxgsQIEiNIzH46gU8nTV6b7rMTEiNIjCAxgsQIEiNIjCAx\n"
      <<L"gsQIEjOe1Kf+baJfev+ckBhBYgSJESRGkBhBYgSJESRGkJjjdOF0Av+VO/ql38Od+kYJEiNIjCAx\n"
      <<L"gsQIEiNIjCAxgsSMJ/WppSfXtaz1JcEJiREkRpAYQWIEiREkRpAYQWIEiVl8Up+q36mvxQmJESRG\n"
      <<L"kBhBYgSJESRGkBhBYgSJESRGkBhBYgSJESRGkBhBYgSJESRGkBh/afsSf2nbKEFiBIkRJEaQGEFi\n"
      <<L"BIkRJEYQAAAAAAAAAAAAAAAAAAAA2LAnyvIoo3+8YfsAAAAASUVORK5CYII=\" height=\"15\" style=\"height:15px;\"/><br />\n</a>"<<endl;
    
    lt.flush();
    
    wcout<<L"1"<<endl;
    if(numeris!=L"nera")
    {
        lt<<L"<a href=\"tel:"<<numeris<<L"\">\n"
      <<L"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAACWCAYAAAAouC1GAAAAAXNSR0IArs4c6QAAAdZJREFUeJzt\n"
      <<L"3LFNxEAQQNHziS7IaOPqpw0y6oACuGCQFvbJ/i92cLqvCUZr73Eben99+5o+m58enx/H5Ln73/+U\n"
      <<L"/EZBMAXBFARTEExBMAXBFARTEMwx3cCnm2aem/7PTQimIJiCYAqCKQimIJiCYAqCKQimIJiCYAqC\n"
      <<L"KQimIJiCYAqCKQimIJiCYF52/4D/tvot/tXvGjQhmIJgCoIpCKYgmIJgCoIpCKYgmIJgCoIpCKYg\n"
      <<L"mIJgCoIpCKYgmIJgCoK53Jn69Ax81w16TQimIJiCYAqCKQimIJiCYAqCKQjmcpu6foNeE4IpCKYg\n"
      <<L"mIJgCoIpCKYgmIJgCoJZvqnv+g5c38CnmhBMQTAFwRQEUxBMQTAFwRQEUxAMf6Z+lg18qgnBFART\n"
      <<L"EExBMAXBFARTEExBMAXBLN/Uz7Ix79KEYAqCKQimIJiCYAqCKQimIJiCYAqCKQimIJiCYAqCKQim\n"
      <<L"IJiCYAqCKQimIJiCYAqCKQimIJiCYAqCKQimIJiCYE7znfqU/nZ+E4IpCKYgmIJgCoIpCKYgmIJg\n"
      <<L"CoLZtqnvuilOv6GuCcEUBFMQTEEwBcEUBFMQTEEwBcGMt9HVZ9tXM938mxBMQTAFwRQEUxBMQTAF\n"
      <<L"wRQEUxDMN2VGNTrd9ywzAAAAAElFTkSuQmCC\" height=\"15\" style=\"height:15px; margin-top:0px;\"/><br />\n</a>"<<endl;
    }
    
    lt<<L"<a href=\"https://www.logismart.lt\">\n"
      <<L"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAACWCAYAAAAouC1GAAAAAXNSR0IArs4c6QAAAXZJREFUeJzt\n"
      <<L"3ctpQzEQQFHbpAvv0obrdxvepQ6ngoDAgrkR56wNwu+ixaD3uVwAAAAAAAAAAAAAAKDuOrXw8/79\n"
      <<L"nlp7xePnNXJtbhOL8jdBYgSJESRGkBhBYgSJESRGkJjt0+jqBL46Ce+e6Hevu3uit0NiBIkRJEaQ\n"
      <<L"GEFiBIkRJEaQGEFilqfMqQl89yRc/x92SIwgMYLECBIjSIwgMYLECBIjSMy1PrlOmboudkiMIDGC\n"
      <<L"xAgSI0iMIDGCxAgSI0jM1+oP68+VT9l9XeyQGEFiBIkRJEaQGEFiBIkRJEaQmLEz9VM4Uz+cIDGC\n"
      <<L"xAgSI0iMIDGCxAgSI0jM8pn6bqfc/b6bHRIjSIwgMYLECBIjSIwgMYLECBLjjXIfruuNcocTJEaQ\n"
      <<L"GEFiBIkRJEaQGEFiBInxlbYP1/WVtsMJEiNIjCAxgsQIEiNIjCAxgsSM3YFef5596u58OyRGkBhB\n"
      <<L"YgSJESRGkBhBYgSJEQQAAAAAAAAA+Bd+AVl5YMlLcAw3AAAAAElFTkSuQmCC\" height=\"15\" style=\"height:15px; margin-top:2px\"/><br /><br />\n</a>"<<endl;
    
    lt.flush();

      wcout<<L"2"<<endl;
    lt<<L"</td>\n  <td>\n"
      <<L"<a href=\""<<elpastas<<L"\">"<<elpastas<<L"</a><br />"<<endl;
    if(numeris!=L"nera")lt<<L"<a href=\"tel:"<<numeris<<L"\">"<<numeris<<L"</a><br />"<<endl;
    lt<<L"<a href=\"https://www.logismart.lt\" target=\"_blank\">www.logismart.lt</a> | <a href=\"https://www.logismart.lt/en\">en</a> | <a href=\"https://www.logismart.lt/de\">de</a>\n"
      <<L"<br /><br />\n  </td>\n </tr>\n </table>"<<endl;

    lt<<L"<table>\n\n  <tr>\n  <td style=\"margin:0; padding-right:5px;\">\n   <a href=\"https://logismart.lt/\">\n"
      <<L"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAyUAAACHCAMAAAA/dgbVAAAAZlBMVEUAAAApM3jFGyJOLmfGGyIp\n"
      <<L"MnjGGyLGGyLGGyIpM3gpM3gqM3gpM3jGGyIpM3gpMnjGGyLGGyLGGyLFGyIpM3jGGyIpM3gpM3gp\n"
      <<L"M3jGGyIpMngpM3jGGyLFGyLGGyLGGyLGGyIpM3hiJDolAAAAIHRSTlMA4fAPUaIxgeI+crIvrh+S\n"
      <<L"05QhQMBi6s5gF0yFocZvuEfHITkAABHKSURBVHja7NzddqIwFIbhbRIBwfDnKAIiyf3f5MzqrBln\n"
      <<L"CrjDLqS17Oe4dq0evMUPI7AEpUV/lsAYGxcUwry5KWCMDQRhZB5EEQBj7B/1PTfvRWEJjLE38tyb\n"
      <<L"cd29BsaY0uYZ3vJs606FMCjNW55t1mOvj+Itz7auDnMzRxRyKGxT5Lkz8+W85dlmTOx1YXAdb3m2\n"
      <<L"AfheF7zl2ZZN7XUxqxVRnICxb6kMc0MieMuzTajP3VQCRDkfYGHfitLUi4d4vuX5phf7Hk43YYj4\n"
      <<L"c3m2BUEREbeIK3HjLc9e2NheR+8D62FWAnlxxAdY2Guq7938a4dWv9+i8ZZnG6B6Mw4f4/jcF/xl\n"
      <<L"FPby1G3+BMnDErt1jOt5y7OXEBTCzBWFwVIfQ/KWZ19dGebO1w/xOHCCHmkZD+9Lbfm6/KWGN6/1\n"
      <<L"y4dk+gufKyUg7XWcVvjxyEdYX3HLlyrU+eM2XK5DVcJCgnOou8j8FeV9cVclrEU2bVJd7B+XKmmv\n"
      <<L"B2ALQmY2/SC80ma2AEbc3ivgg1QRjX+Ig/1luFPYmQminzjHdhsAd022s6OqrJEwqt0PteCO/vp4\n"
      <<L"/y+nktP9pCxr42tzSOGZ634BYKYJ4peq6F/bCpw6FvARwdNb1voEdEoLyhtLMwCO0uxin/kRpzA0\n"
      <<L"mtURXKV2xA4cSPufBBwcLW6XxJPFZXYBgE6R4V6nfwVYfHolCg03PwNJWQjHW+dLVZImFlfF0qmS\n"
      <<L"DFy15Epi+7+UUAnyH2H9SsQqD3sIwujLXEtOuXEQEToJtHF2XqQSmVlH+4NDJVaCo4tzJVie7axK\n"
      <<L"cEnjoRL6Xnfb8tNBCi+V1No46oKZjfTGeK6k2Vl3VYpXcgU3V0utpLHvXGZWgts1vioRazyETulP\n"
      <<L"v5achXEXgjtZGOO7ktbOcsArqcBNRa4kse81hEoQ1dFDJeudIZHn/jMrkdrM0tXgSEXGeyWJXaKS\n"
      <<L"4c/gDpZaSTqyJQiVoGIPlaz5cOz6nn9WJWVuZhIBOCmM8V5JYleoJAEXe3IlrR1KCZWgEumtEnyv\n"
      <<L"07e8/0oCyjNgFKE+L5Xs7RqV2BRwcmoQ0FZ/RqgEV0lvleB7nX5mzHclJ2EolMsvxsMTC1cS23Uq\n"
      <<L"iQEXkytp7IgLpRLcTi5fif+HxivttZJAzDrqLJwzUYbgo5Uc7UqV7ABHf+0P2p21o6WoVqmEvtfp\n"
      <<L"W95bJaXA0ph0WjISsUwl1VqV2AYwjaVWktpRFV4JSbZyJX0JftSFn0pk/iQLLKByViTCw7Xkaler\n"
      <<L"5AdgEnIlrR13RCuhadatJARflJ9KfrJ3rztuwkAUgA0OBQMxpMkaB5pEvP9L9qLe7eGYMdBq5fOz\n"
      <<L"2bBEmq/D2IQ9xzzKohdkPoC37qNEmv2UzBo2BLYS6rS7nZQYmZSsyBPQALmQrbD687j54i/Jt1JS\n"
      <<L"z7spwSU7ASWcDiiREmampCQ8HxcN5FXfVwQdMJrgx17mVe8cPVpJNpPJhmHITIwSA0rWsJXcZip2\n"
      <<L"JyVGvi8l+Z5K6HuAX+X1/r0tXMvH2muuchHf6/cvdd0/nMpzFaEEF81Qq58Frse6yIASXsnaBaHs\n"
      <<L"Wh/QO7mp35eSqF7CXKut/l7Hu5PbneXKoaQqve1Hni49Swm+5mla97fZwpBKuCU7cJTAWlUrlWT1\n"
      <<L"j0xd0Qxm+bOomkjn+a+GyntX4i/9/OmdYHL/D9+Fm54y8jgtPp78FanktqIBqM4AJW4UKFimEjPT\n"
      <<L"KYAStBKnbcNZi1ArbtF550qe/mutO1HEr9Bm8qSMXAWIPJ1PEUpWbpmPDaGEU7IFUMJdvZZrlThp\n"
      <<L"vU5sUhKWClR92LQhnVLPQYsCYSvRq6/r9WQcJbySlTNbyQAGCI4SvPTXJCVBeXOWn9AHLElWGFP/\n"
      <<L"UeytZOR8e8oOK5TUvDXoLGICz1hK8MCWJSVB6UHJBzKpglrJS4rdlVjenbxKQyW4tPDbuE9oUCwl\n"
      <<L"ePRJSojAhagzZ6v+BCSBA2+npF5RCrxyn0eyjXGVyBmkYSnBFHVSwvuCVCUFyN3TKD7haecl9lCC\n"
      <<L"rysMQwmrZBu2EjujaI4SrFglJQHJia6Ahhk3cA+ml4cr4fcSTslq/mwxOD8MhiGWkjYpCVWCqvkR\n"
      <<L"NM0AXGdwz/+xV1xyayUd8AmU4HI0I3g3S4lOShwlzAuuK1PXRfyKBEsCByuxWysxwhfDVlI4DN2D\n"
      <<L"jamXHKcEjQ89d2msck6bePn4NS6j45Vgd3ZGSsJn99ZtTM0uc0mblHDuBn6yd+x/2wr5hKadHZUo\n"
      <<L"X4HqjZUMYLYASlD7G3ylr6OVTGmNi6PkRGyi49xJB/wWxVeCF1VryVFCR4FajdtmqX3opmglWdov\n"
      <<L"4Si58FdrH8RgQrSot32V4PHAdGpLJQXYjABKQDFqX4MxsUps2ntnKXlQF1w4JQGMWCiWxykpyDIt\n"
      <<L"rGQqwetmcmYraby1qIlhiK1Epfu4eEpy9/D8TftqoUWdxSFK8A74MI08JWj/omYrkQSHG6h9rAQv\n"
      <<L"LtRJCYwExccoXKJFvR2oRBj4ZzxUvJKM/w7oiyrrlq9ENen7JUwlH2KG7N5d5KJb1P1IJd0MYwor\n"
      <<L"gRKUkWhgSAn+XQXVYzqeEjlOGbVUl5TAXIm7sZhPJ7qSLaoSRyrRc1BuVsYoaajZAisBvhQ1YJlQ\n"
      <<L"Jdn0LV3XNbfBzGTqpATnLeaTXcil4A945ezZw1ygkvhHDRUtX8msAUyghPSV0X4soYQbmZTglGCJ\n"
      <<L"i/lm96QvLjGY8yFPQG1atpIJ3MIFlJC+JnrAGrZ+HldSglMS7YDbiMArxynRZg5OJ4OUNIs3cxn3\n"
      <<L"54ES2pdeeK3d9tmOSQn3ool/aiV598rbwUqEWlMsKkSJ54h2aZV1hEpwv2hd0lsqsSIpYSm5xpza\n"
      <<L"hVRy2lEJnIlx6gAl8rawQuR5TYYpGRdPZsCTBF9JIZKSkHyKUXIllZT/gRIxmjk8XYAST79QdJna\n"
      <<L"QCXNooMaguYryWRSckAv+b+VCD1w5lhaiTDk/8adZ2YJU6KJOiRfHrZSYrRISvhK4ueSy3+hZN2z\n"
      <<L"5y1WMlErqdKjjlCCZ/cRtBq1jRLTiqSEvcYVpeS/6iVfoos5OC1Uoj0DDaVRByoxYOPQgmmCq2TQ\n"
      <<L"IilhK3mLeXLqEx/WVZJHKMFpg50MUImgFnczTzGFKbFwQiL6V6SSQoqkJFTJE3wyJrFnzH5JzlJC\n"
      <<L"R9aB84mFSpRvfvf+8xio5Ea3NHLkqaOVmFGIpAQowQN45ALZ85/vvbtPXMcxUIkYvFVTeDyEKWnx\n"
      <<L"cK4YhwGZpEhKou4JfsT8baCP5Em/dlaCo6YbbCZQiZ2dSN/sXgcq6Vg7N2OMEvPVSFKyRsmd8z5c\n"
      <<L"uC6+KkxJHqEkXsoAlUjjKevaQydQiQkYOmpcqe26a62k5HN757qlJgxF4UOCgKBcBOWiDuH9X7L2\n"
      <<L"vtok7BBEYSbf6p9OhYZZ51vJDkkE1Y4r/WS/V5Hp5RPtq/oSbIo+pqTIEsoUpe8pErjaEpzdq1Ri\n"
      <<L"r2infV/iLLGwJFcmcMvkfx+paX8tljxIY29Q0kBL0kHiOkgcDC2pBzuu9pZc0k1b4hflCyzBCfxo\n"
      <<L"vwmrGJGvWJElDzqlJxm0hJIBUxGwZGJxW9zokj2oBgXJdi0pCyaE/wZLPmwuxP1FAYPJqfyPj8Ut\n"
      <<L"wbt+K2xJN2A6Q0uywZbOaEcv9wYFzTYt+aGIeI8lgfUZjP5YpDlPP324XNwSXKMXbAl5hjPK2BI+\n"
      <<L"WJNgS/TbB9LtWfJTkbdZQsz22Lpe7i5G5evXZomq3g0siQdEbGhJM9iTQkv0ja02ZklZREKIt1rS\n"
      <<L"C4nAshMqRuUTwdosUS1exJbwAcENLakHe67YEn2MijdkyU9FnmsJm2zJGaRmkN117b8JiX5tljSD\n"
      <<L"RIotoR3c22RmyX6YwcXAEn00OWzEkuC3Iu/uS1ohUxKkFDIgtQh/ZZZ0Npbgmak9tATbhmmwJXoX\n"
      <<L"601YEnxXZB2W0F1I5ATJQRfEhQxrV28JHHHhkVJNZpbwYRYVtmQkmmRbsMQX67HkLGQKAoSw+Tch\n"
      <<L"06/LktjCEpy6G0NL4mEeB2jJWDTZO0uQJfh72c/T2x/hIZm4vcSSuCMjdlZzXA8uODBgS7xhHpmp\n"
      <<L"JVzVXG8D+0vWZAkVoC2GzQ/lMZnM8RWW7IYaeKIrds/MkiucfMKW7Ie5AEvAf7Vzlkyy5AQaY9Z6\n"
      <<L"xqWRnIr89ApLBqUneMCVmFmSwhcZ2JLdMJcGWTJudecsmWIJHYWKAmQS+BuJhJLwFZY8qBtUADJX\n"
      <<L"bAlYzJWQmSV8mE1tbAlVynMdnSVTLDmpt3fkJSkIcqGCcU3LZaLz4pb85HI9kMRoBO+AJXi41EFL\n"
      <<L"9Nk9G6FS5XdgCTgPNtmiJex2eqolJxPG1+feJW/LXqj50M8xy7AiWNaSP3hZx0lBVw0qOLIETQZ7\n"
      <<L"ZGiJN3HhSKqyCliCDrpstmYJu/mz95dgdB1Oy/T17Lf0C+4XkW5vYQ4WsUiwPvRP4EHtLfmHOov3\n"
      <<L"Kf3l0GQeGC5BS5pBTWxoSTe5aBOV1MASFE3STVlylBR5rSV0Hv3QvT8ej/dIjBBoEgwgetz6dnvc\n"
      <<L"PJc8nWeJjFclyS6pqsuMfe84VnBkib7mL9NjVAwsQdGk3o4lkiLzLWFTLaFezCJE7/UxS1vyhDNU\n"
      <<L"8NaQjJAl+vHTdfoK5hpYAqNJvA1LgCKv6kuojcQM7qThxKY26J2WxNgSMBl8MLTkCroh0+mGPbAE\n"
      <<L"RpPDopb0pydYcvQ5IdpioiXMyhIqtVdjopZ0lBvqSzwClsCcUJGhJZ7FWz4+yOyQJaj7q59qicz9\n"
      <<L"o51hiZki/NwLsXRfgqIJJjDqCtnaLekmWdJp74At6QwXVuEq59ASMDGXPdkSmf7MyY7A5Er/KCSs\n"
      <<L"LGHaSmU4amNArtpKX5IRsgR94EKGliQWQVo9yIuBJTia7Je2BOcKe4KCCTHTEpzoGWk0YRaSAE3Q\n"
      <<L"jdl7LanJyBL8/TvYktR0GhhPU3nAEhxNPL6EJfgN2XyCMJo6wMGVBy2h0CZj+4QomZgKe7klXoot\n"
      <<L"QRJwQ0uu5tPAeJAHLMGDtt0ilshE4YmeR/uRC4klZ4L/cp549eNPQJhTrrh2XSMuSRJsCe3U5YYt\n"
      <<L"ucBpYPPJ4ARZgqNJt6wl87M8zusLp3ewhxKV9t3wqcOV55I6pamWyKW5N7Sksz78J1ZdCSzB2eaS\n"
      <<L"LmSJfZbHeX0ZS5iRJdQewXWWb42C3LRx7A2WJJwsLKFaFWywJZX1eYt8kLkiS/Bbl2QhS3CWtz+Y\n"
      <<L"67V9iYQfaWpX+lse0ATOr5sJTqthCpeGyMqSRpG/sSUpHvRM8d+DluBo0ixsiZzlywXyumDTLWGW\n"
      <<L"lhAPzZ70g6bBw2iawSGHluBTgDEZJ0tL6CLnb2xJpqp0Qw4qw6AlOJqky1jCxrJ8QNNow1wAzCxh\n"
      <<L"wDHpRwy/78clbM75bqxwFLb0D/LD0BhNZehISmRtyVXO39iSy6TlVLjEE2gJNq1ewBJIPiHL85+l\n"
      <<L"M98SGSwMs5tnu5/nzHFj8iIweED49Qs1DO0xJ7KyRM7CqaElzcQlXDhWpNASfI94WUuYtpC4dV6X\n"
      <<L"QwC2JLIiH6tnjSj3mfPewUfPxgws/NbsAQmSNpk36KjilEaovP/hJJF5v9mRBJfuUBFR4klcyZza\n"
      <<L"k4iJDtIPE9KTeTKpxhLpg9nYO4w7NgRmeZzXMXl4olfR+uHxH1XyY+hzegKn73dm/z1ZX4T+8x+O\n"
      <<L"7+Ms+dcVL8maAzkW4ATCA8ryeOyBiYqAXk4bBKXvl0HQLnHroPRLfO/58HS/77r9fp9ycgAWWlsF\n"
      <<L"szxWDvdTt5Icjg3g38TsQVIr53VM75PDsRn8Xkzmfm5VeR3D/qx/cTg2hZTljd/Ll7d153WHY5Es\n"
      <<L"z4yDBTtuJK87HBjz7+lZFubyumP7WAygzN+PH11ed3wSDMI4Q//I5A/ezy6vOz4R6oldJiDM5XXH\n"
      <<L"F+J3lmdQBEwUurzu+KSABSeGsMLldcenxmzxIlP1MS6vO74O2iyPuZ/dMjzHF0G3qYqN/jR3S1Ac\n"
      <<L"X4s2zE0EcXnd8bUxz/LMLUFxfF3+z/Iurzsc07N87/K6w6E50NRtGXE48KE9kVuC4nBIWd7ldYfD\n"
      <<L"+GCJm8vrDsdIlmcurzs+L98Ax2puYCz4oKsAAAAASUVORK5CYII=\" alt=\"Logismart\" height=\"35\" style=\"height: 35px; margin-left:7px; margin-top:-5px\" />\n </a>\n"<<endl;

    lt.flush();

    lt<<L"<td>\n <a href=\"https://www.facebook.com/profile.php?id=100057528846124\"> \n"
      <<L"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAlgAAAJYAgMAAADDCHBPAAAACVBMVEUAAAAYd/L///8Lxa3XAAAA\n"
      <<L"AXRSTlMAQObYZgAAAvZJREFUeNrs20FygkAURdFMsj8mf+L+nLDKJEVbTatEsaX46rkLaM7sVRfw\n"
      <<L"1dd3LDT0nYu1HNaaU7DWnIK15pT3Zl3F7A/EwiphYWE9Q5TJhoVVwsLCerB4SlhYWFhYCVlXJ2f/\n"
      <<L"GcLCwsLCSiSqDVhYWFhYGVhxpQSXjTiFhYWFhZVrd2oDFtYUFhZWJyvZ7tSwsEpYWFh9Jdud2oCF\n"
      <<L"NYWFhdXJSrY7NSysEhYWVl/Jdqc2YGFNYWFhdbKS7U4NC6uEhYXVV7LdqQ1YWFNYWFhYi2FhYWEt\n"
      <<L"9ums2D0srBLWmrDW9Lmszt0Zb3SM+xqwsLDasLD2ZLWie21YWFhYWC/COowjFhYWFlZ2VjzWWOtl\n"
      <<L"1bCwsLCwsLCwsLCmsBbb6nbR/84ACwsLCwsLCwsLKwJrI1bP07GwTmFhXYSVnRW3w8KahYXVhvVs\n"
      <<L"VjzWJrtTwzoLC6uGhXWjftZhHLH+DQvrLCys2uuy4v6wsJqwsOZhYTVhYc3DwmrCwpqHhdWEhTUP\n"
      <<L"C6sJC2seFlZTOlZxdHbEwsLCwsLCwsLCwnpBVtIrBhYWFhYWFhYWFtarsu76Jfew/e2i/SUXCwsL\n"
      <<L"CwsLCwsLCysDKyKwsLCwsN6TdYzAwsLCwtqHVYoVbf0Z/y8H6y8srMuwsEpYWJdh/bRfBycMw1AQ\n"
      <<L"BU++pD/330rk4LAXCSPMxwqZV8HclsU6w/pD1uXPKGflXWDtWFjdsLCOsLC6YWEdYWF1w8I6wsLq\n"
      <<L"hvUjrNZ+UT2rIbCwsPphYaUZ1vUClbOyO1hYWFhYWC0sLCwsrAnW+GfUs/IusLCwsLAqWOMFKmdl\n"
      <<L"d7CwsLCwillpT5Ws7A4WFhYWVgFr3FbOyu5gYWFhYZWxxpWysjtYWFhYWKWscVsRK7uDhYWFhfUA\n"
      <<L"KxWwsjtYWFhYWA+x0lbBaruDhYWFhbUCK7b7rIiwsLCwsBZitW6yciywsLCwsBZknW0TrPHkYGFh\n"
      <<L"YWGtyfr06rMmRVhYWFhYa7K+9VjzGCwsLKxhWHdZb1jRxCTNao8eAAAAAElFTkSuQmCC\" alt=\"Facebook\" height=\"35\" style=\"border-radius:15px; height: 30px; display:inline-block; margin-left:5px; margin-top:-5px\" />\n </a>\n </td>\n"<<endl;

    lt.flush();

    lt<<L"<td>\n <a href=\"https://www.linkedin.com/company/logismart-lithuania/posts/?feedView=all\">\n"
      <<L"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAlgAAAJYAgMAAADDCHBPAAAACVBMVEUAAAAAd7X////ig02lAAAA\n"
      <<L"AXRSTlMAQObYZgAAAuBJREFUeNrs1zGOwjAURVE37M+Nm+yPJqucjJKRhSCQj8NgwrmtZel0Tz+1\n"
      <<L"dSor5dQU1npYKRBWCoSVAh2bdRPzfiAW1hIWFtYeop5sWFhLWFhYT1Z2CQsLCwurQ9bNyXn/DGFh\n"
      <<L"YWFhdSSqZSwsLCysHljlRh0cG+UvLCwsLKy+dqeWsbDmsLCwGlmd7U4NC2sJCwurrc52p5axsOaw\n"
      <<L"sLAaWZ3tTg0LawkLC6utznanlrGw5rCwsBpZne1ODQtrCQsLq63OdqeWsbDmsLCwsFbDwsLCWu3b\n"
      <<L"WeVx42/lZWFhbQwLC+t+T+3OMP51Lq8qY2FtCgsLa2/WeFl5HBYWFtZqWFhYWKthYWEFWeVxgROj\n"
      <<L"LSyszWFFwor0naypZ3cHKxJWJKxIWJEOxDqVzspYWHNYkbAiYUXCioQVCSsSViSsSFiRsCJhRcKK\n"
      <<L"hHXdeNmjh2G87oyFhYWF9d+sUtuPNa5VNoaFhYWF1StrGO91xsLCwsL6YNYUFhYWFtbXsqawsLCw\n"
      <<L"sD6bVeYGLCwsLKzDsS6OCCwsLCwsLCwsLCysD2FdfRywsLCwsLCwsLCwsLCwsLCwsGKslE69sXJK\n"
      <<L"WFhYWFhYWFhYWFhYWFhYWFhYWFhYWEdlTfXEmjhYWFhYWFhYWD/t3TGKA0EMRNFK5n6d7P2vsjSe\n"
      <<L"wNgYI5AZGb9/gpcVioSFhfWedXbMYK0ECwsLC6uPNezFNxbWGVYlrEpYlbAqYVXCqoRV6VdZSf4u\n"
      <<L"LwkW1g6rElaln2ZdvEArwcLaYWFhYb0MCwsL62VYF94ZSbCwdlhYWD2sSQu0EiysHRYWVg9r1AIl\n"
      <<L"wcLaYWFh9bAmLdBKsLB2WFhYPaxRC5QEC2uHhYXVw5q0QCvBwtphYWH1sEYtUBIsrB0WFlYPa9IC\n"
      <<L"rQQLCwsLawLrZhsnwsLCwsJ6bMCxkQQLCwsLayDr7BgxOVhYWFhYH+wYJ8LCug8LC6sNOAmDhfUU\n"
      <<L"VgphpdDXsP4BZuA4AqOGvgQAAAAASUVORK5CYII=\" height=\"30\" style=\"border-radius:50%; height: 30px; margin-top:-5px\"/>\n    </a>\n  </td>\n</table>\n"<<endl;

    lt.flush();

      wcout<<L"3"<<endl;
    if(kalba==L"lt")
    {
        lt<<L"<table>\n <td style=\"padding-top:7px; padding-left:8px;\">\n"
        <<L"<strong><a href=\"https://logismart.lt/kontaktai/\" style=\" text-decoration: none;\">Lietuva</a></strong>  "
        <<L"|  <a href=\"https://logismart.lt/en/contacts/\" style=\" text-decoration: none;\">United Kingdom</a>  "
        <<L"|  <a href=\"https://logismart.lt/de/kontakte/\" style=\" text-decoration: none;\">Deutschland</a>\n </td>\n </tr>\n  </table>\n"<<endl;
        
        lt.flush();

        wcout<<L"4"<<endl;
        lt<<L"<hr style=\"width: 100%; border: none; border-top: 2px solid black; margin-top: 20px;\">\n"
        <<L"<p style=\"font-size: 10px;\">\n Išmanioji logistika, UAB<br />\n"
        <<L"Galinės g. 1, Galinė, LT-14247, Vilniaus r. sav., Lietuva <br />\n"
        <<L"Įmonės kodas: 304751937, PVM mokėtojo kodas (VAT): LT100011569214 <br />\n"
        <<L"IBAN LT247290000015467502 <br />\n AB Citadelė Bankas <br />\n"
        <<L"Šis el. laiškas ir visi su juo perduodami failai yra konfidencialūs ir skirti tik tam asmeniui ar subjektui, kuriam jie yra adresuoti. "
        <<L"Jei šią žinutę gavote per klaidą, prašome ją grąžinti siuntėjui atsakydami į ją ir tuomet ištrinti iš savo kompiuterio. "
        <<L"LOGISMART (Išmanioji logistika, UAB) neatsako už šios žinutės turinio pakeitimus, atliktus po jos išsiuntimo. \n </p>\n </body>"<<endl;
        if (!lt) wcout << L"lt stream failed after first write\n";
        wcout<<L"5"<<endl;
    }

    else if(kalba==L"en")
    {
        lt<<L"<table>\n <td style=\"padding-top:7px; padding-left:8px;\">\n"
        <<L"<a href=\"https://logismart.lt/kontaktai/\" style=\" text-decoration: none;\">Lietuva</a>  "
        <<L"|  <strong><a href=\"https://logismart.lt/en/contacts/\" style=\" text-decoration: none;\">United Kingdom</a></strong>  "
        <<L"|  <a href=\"https://logismart.lt/de/kontakte/\" style=\" text-decoration: none;\">Deutschland</a>\n </td>\n </tr>\n  </table>\n"<<endl;
        
        lt.flush();

        lt<<L"<hr style=\"width: 100%; border: none; border-top: 2px solid black; margin-top: 20px;\">\n"
        <<L"<p style=\"font-size: 10px;\">\n LOGISMART FULFILLMENT Ltd<br />\n"
        <<L"1 Springwood Dr, Braintree CM7 2YN, United Kingdom <br />\n"
        <<L"Company code: 15320786, VAT number: GB456358760 <br />\n"
        <<L"IBAN GB34REVO00996927985500 <br />\n Revolut Ltd <br />\n"
        <<L"This e-mail message and any files transmitted with it are confidential and intended solely for the use of the individual or entity to whom they are addressed. "
        <<L"If the message is received by anyone other than the addressee, please return the message to the sender by replying to it and then delete the message from your computer. "
        <<L"LOGISMART (LOGISMART FULFILLMENT LTD) does not accept responsibility for changes made to this message after it was sent. \n </p>\n </body>"<<endl;
    }

    else {
        lt<<L"<table>\n <td style=\"padding-top:7px; padding-left:8px;\">\n"
        <<L"<a href=\"https://logismart.lt/kontaktai/\" style=\" text-decoration: none;\">Lietuva</a>  "
        <<L"|  <a href=\"https://logismart.lt/en/contacts/\" style=\" text-decoration: none;\">United Kingdom</a>  "
        <<L"|  <strong><a href=\"https://logismart.lt/de/kontakte/\" style=\" text-decoration: none;\">Deutschland</a></strong>\n </td>\n </tr>\n  </table>\n"<<endl;
        
        lt.flush();

        lt<<L"<hr style=\"width: 100%; border: none; border-top: 2px solid black; margin-top: 20px;\">\n"
        <<L"<p style=\"font-size: 10px;\">\n Logismart GmbH<br />\n"
        <<L"Orber Str. 10, 60386 Frankfurt am Main, Deutschland <br />\n"
        <<L"HRB 123968, USt-IdNr. DE346387238 <br />\n"
        <<L"IBAN DE29100101231865944111 <br />\n Olinda Zweigniederlassung Deutschland <br />\n"
        <<L"Diese E-Mail-Nachricht sowie alle damit übermittelten Dateien sind vertraulich und ausschließlich für den Gebrauch durch die Person oder Organisation bestimmt, an die sie adressiert sind. "
        <<L"Wenn Sie diese Nachricht irrtümlich erhalten haben, bitten wir Sie, sie durch eine Antwort an den Absender zurückzusenden und anschließend von Ihrem Computer zu löschen. "
        <<L"LOGISMART (Logismart GmbH) übernimmt keine Verantwortung für nachträgliche Änderungen an dieser Nachricht nach dem Versand. \n </p>\n </body>"<<endl;
    }

    lt.close();
    wcout<<L"Paraso .html failas sukurtas!"<<endl;
}
