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
    ofstream lt(utf8_filename);

    if (!lt.is_open()) {
        wcerr << L"Failo sukurti nepavyko: " << utf8_filename.c_str() << endl;
        return;
    }
    lt<<"<body>\n<em>Pagarbiai, Best Regards, Freundliche Grüße, </em><br /><br />\n<p style=\"padding-left:8px; margin:0\"><strong>"<<wstring_to_utf8(vardas_pavarde)<<"</strong><br />\n"<<wstring_to_utf8(pareigos)<<" <br />\n</p>\n"<<endl;

    lt<<"<table style=\"font-family: Arial, sans-serif; font-size: 14px; color: #333;\">\n"
      <<"<tr>\n  <td style=\"padding-left: 8px;\">\n  <a href=\"mailto:"<<wstring_to_utf8(elpastas)<<"\">\n"
      <<"  <img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAACWCAYAAAAouC1GAAAAAXNSR0IArs4c6QAAATxJREFUeJzt\n"
      <<"3bERwjAQAEFg6IKMNqifNsioAxogeGYMPsNurMDWjYK3Au92AAAAAAAAAAAAAABQt58uvJ7Oj88+\n"
      <<"ym+73G+jvT58/lF4hyAxgsQIEiNIjCAxgsQIEiNIzH46gU8nTV6b7rMTEiNIjCAxgsQIEiNIjCAx\n"
      <<"gsQIEjOe1Kf+baJfev+ckBhBYgSJESRGkBhBYgSJESRGkJjjdOF0Av+VO/ql38Od+kYJEiNIjCAx\n"
      <<"gsQIEiNIjCAxgsSMJ/WppSfXtaz1JcEJiREkRpAYQWIEiREkRpAYQWIEiVl8Up+q36mvxQmJESRG\n"
      <<"kBhBYgSJESRGkBhBYgSJESRGkBhBYgSJESRGkBhBYgSJESRGkBh/afsSf2nbKEFiBIkRJEaQGEFi\n"
      <<"BIkRJEYQAAAAAAAAAAAAAAAAAAAA2LAnyvIoo3+8YfsAAAAASUVORK5CYII=\" height=\"15\" style=\"height:15px;\"/><br />\n</a>"<<endl;
    
    if(numeris!=L"nera")
    {
        lt<<"<a href=\"tel:"<<wstring_to_utf8(numeris)<<"\">\n"
      <<"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAACWCAYAAAAouC1GAAAAAXNSR0IArs4c6QAAAdZJREFUeJzt\n"
      <<"3LFNxEAQQNHziS7IaOPqpw0y6oACuGCQFvbJ/i92cLqvCUZr73Eben99+5o+m58enx/H5Ln73/+U\n"
      <<"/EZBMAXBFARTEExBMAXBFARTEMwx3cCnm2aem/7PTQimIJiCYAqCKQimIJiCYAqCKQimIJiCYAqC\n"
      <<"KQimIJiCYAqCKQimIJiCYF52/4D/tvot/tXvGjQhmIJgCoIpCKYgmIJgCoIpCKYgmIJgCoIpCKYg\n"
      <<"mIJgCoIpCKYgmIJgCoK53Jn69Ax81w16TQimIJiCYAqCKQimIJiCYAqCKQjmcpu6foNeE4IpCKYg\n"
      <<"mIJgCoIpCKYgmIJgCoJZvqnv+g5c38CnmhBMQTAFwRQEUxBMQTAFwRQEUxAMf6Z+lg18qgnBFART\n"
      <<"EExBMAXBFARTEExBMAXBLN/Uz7Ix79KEYAqCKQimIJiCYAqCKQimIJiCYAqCKQimIJiCYAqCKQim\n"
      <<"IJiCYAqCKQimIJiCYAqCKQimIJiCYAqCKQimIJiCYE7znfqU/nZ+E4IpCKYgmIJgCoIpCKYgmIJg\n"
      <<"CoLZtqnvuilOv6GuCcEUBFMQTEEwBcEUBFMQTEEwBcGMt9HVZ9tXM938mxBMQTAFwRQEUxBMQTAF\n"
      <<"wRQEUxDMN2VGNTrd9ywzAAAAAElFTkSuQmCC\" height=\"15\" style=\"height:15px; margin-top:0px;\"/><br />\n</a>"<<endl;
    }
    
    lt<<"<a href=\"https://www.logismart.lt\">\n"
      <<"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAACWCAYAAAAouC1GAAAAAXNSR0IArs4c6QAAAXZJREFUeJzt\n"
      <<"3ctpQzEQQFHbpAvv0obrdxvepQ6ngoDAgrkR56wNwu+ixaD3uVwAAAAAAAAAAAAAAKDuOrXw8/79\n"
      <<"nlp7xePnNXJtbhOL8jdBYgSJESRGkBhBYgSJESRGkJjt0+jqBL46Ce+e6Hevu3uit0NiBIkRJEaQ\n"
      <<"GEFiBIkRJEaQGEFilqfMqQl89yRc/x92SIwgMYLECBIjSIwgMYLECBIjSMy1PrlOmboudkiMIDGC\n"
      <<"xAgSI0iMIDGCxAgSI0jM1+oP68+VT9l9XeyQGEFiBIkRJEaQGEFiBIkRJEaQmLEz9VM4Uz+cIDGC\n"
      <<"xAgSI0iMIDGCxAgSI0jM8pn6bqfc/b6bHRIjSIwgMYLECBIjSIwgMYLECBLjjXIfruuNcocTJEaQ\n"
      <<"GEFiBIkRJEaQGEFiBInxlbYP1/WVtsMJEiNIjCAxgsQIEiNIjCAxgsSM3YFef5596u58OyRGkBhB\n"
      <<"YgSJESRGkBhBYgSJEQQAAAAAAAAA+Bd+AVl5YMlLcAw3AAAAAElFTkSuQmCC\" height=\"15\" style=\"height:15px; margin-top:2px\"/><br /><br />\n</a>"<<endl;
    
    lt<<"</td>\n  <td>\n"
      <<"<a href=\""<<wstring_to_utf8(elpastas)<<"\">"<<wstring_to_utf8(elpastas)<<"</a><br />"<<endl;
    if(numeris!=L"nera")lt<<"<a href=\"tel:"<<wstring_to_utf8(numeris)<<"\">"<<wstring_to_utf8(numeris)<<"</a><br />"<<endl;
    lt<<"<a href=\"https://www.logismart.lt\" target=\"_blank\">www.logismart.lt</a> | <a href=\"https://www.logismart.lt/en\">en</a> | <a href=\"https://www.logismart.lt/de\">de</a>\n"
      <<"<br /><br />\n  </td>\n </tr>\n </table>"<<endl;

    lt<<"<table>\n\n  <tr>\n  <td style=\"margin:0; padding-right:5px;\">\n   <a href=\"https://logismart.lt/\">\n"
      <<"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAyUAAACHCAMAAAA/dgbVAAAAZlBMVEUAAAApM3jFGyJOLmfGGyIp\n"
      <<"MnjGGyLGGyLGGyIpM3gpM3gqM3gpM3jGGyIpM3gpMnjGGyLGGyLGGyLFGyIpM3jGGyIpM3gpM3gp\n"
      <<"M3jGGyIpMngpM3jGGyLFGyLGGyLGGyLGGyIpM3hiJDolAAAAIHRSTlMA4fAPUaIxgeI+crIvrh+S\n"
      <<"05QhQMBi6s5gF0yFocZvuEfHITkAABHKSURBVHja7NzddqIwFIbhbRIBwfDnKAIiyf3f5MzqrBln\n"
      <<"CrjDLqS17Oe4dq0evMUPI7AEpUV/lsAYGxcUwry5KWCMDQRhZB5EEQBj7B/1PTfvRWEJjLE38tyb\n"
      <<"cd29BsaY0uYZ3vJs606FMCjNW55t1mOvj+Itz7auDnMzRxRyKGxT5Lkz8+W85dlmTOx1YXAdb3m2\n"
      <<"AfheF7zl2ZZN7XUxqxVRnICxb6kMc0MieMuzTajP3VQCRDkfYGHfitLUi4d4vuX5phf7Hk43YYj4\n"
      <<"c3m2BUEREbeIK3HjLc9e2NheR+8D62FWAnlxxAdY2Guq7938a4dWv9+i8ZZnG6B6Mw4f4/jcF/xl\n"
      <<"FPby1G3+BMnDErt1jOt5y7OXEBTCzBWFwVIfQ/KWZ19dGebO1w/xOHCCHmkZD+9Lbfm6/KWGN6/1\n"
      <<"y4dk+gufKyUg7XWcVvjxyEdYX3HLlyrU+eM2XK5DVcJCgnOou8j8FeV9cVclrEU2bVJd7B+XKmmv\n"
      <<"B2ALQmY2/SC80ma2AEbc3ivgg1QRjX+Ig/1luFPYmQminzjHdhsAd022s6OqrJEwqt0PteCO/vp4\n"
      <<"/y+nktP9pCxr42tzSOGZ634BYKYJ4peq6F/bCpw6FvARwdNb1voEdEoLyhtLMwCO0uxin/kRpzA0\n"
      <<"mtURXKV2xA4cSPufBBwcLW6XxJPFZXYBgE6R4V6nfwVYfHolCg03PwNJWQjHW+dLVZImFlfF0qmS\n"
      <<"DFy15Epi+7+UUAnyH2H9SsQqD3sIwujLXEtOuXEQEToJtHF2XqQSmVlH+4NDJVaCo4tzJVie7axK\n"
      <<"cEnjoRL6Xnfb8tNBCi+V1No46oKZjfTGeK6k2Vl3VYpXcgU3V0utpLHvXGZWgts1vioRazyETulP\n"
      <<"v5achXEXgjtZGOO7ktbOcsArqcBNRa4kse81hEoQ1dFDJeudIZHn/jMrkdrM0tXgSEXGeyWJXaKS\n"
      <<"4c/gDpZaSTqyJQiVoGIPlaz5cOz6nn9WJWVuZhIBOCmM8V5JYleoJAEXe3IlrR1KCZWgEumtEnyv\n"
      <<"07e8/0oCyjNgFKE+L5Xs7RqV2BRwcmoQ0FZ/RqgEV0lvleB7nX5mzHclJ2EolMsvxsMTC1cS23Uq\n"
      <<"iQEXkytp7IgLpRLcTi5fif+HxivttZJAzDrqLJwzUYbgo5Uc7UqV7ABHf+0P2p21o6WoVqmEvtfp\n"
      <<"W95bJaXA0ph0WjISsUwl1VqV2AYwjaVWktpRFV4JSbZyJX0JftSFn0pk/iQLLKByViTCw7Xkaler\n"
      <<"5AdgEnIlrR13RCuhadatJARflJ9KfrJ3rztuwkAUgA0OBQMxpMkaB5pEvP9L9qLe7eGYMdBq5fOz\n"
      <<"2bBEmq/D2IQ9xzzKohdkPoC37qNEmv2UzBo2BLYS6rS7nZQYmZSsyBPQALmQrbD687j54i/Jt1JS\n"
      <<"z7spwSU7ASWcDiiREmampCQ8HxcN5FXfVwQdMJrgx17mVe8cPVpJNpPJhmHITIwSA0rWsJXcZip2\n"
      <<"JyVGvi8l+Z5K6HuAX+X1/r0tXMvH2muuchHf6/cvdd0/nMpzFaEEF81Qq58Frse6yIASXsnaBaHs\n"
      <<"Wh/QO7mp35eSqF7CXKut/l7Hu5PbneXKoaQqve1Hni49Swm+5mla97fZwpBKuCU7cJTAWlUrlWT1\n"
      <<"j0xd0Qxm+bOomkjn+a+GyntX4i/9/OmdYHL/D9+Fm54y8jgtPp78FanktqIBqM4AJW4UKFimEjPT\n"
      <<"KYAStBKnbcNZi1ArbtF550qe/mutO1HEr9Bm8qSMXAWIPJ1PEUpWbpmPDaGEU7IFUMJdvZZrlThp\n"
      <<"vU5sUhKWClR92LQhnVLPQYsCYSvRq6/r9WQcJbySlTNbyQAGCI4SvPTXJCVBeXOWn9AHLElWGFP/\n"
      <<"UeytZOR8e8oOK5TUvDXoLGICz1hK8MCWJSVB6UHJBzKpglrJS4rdlVjenbxKQyW4tPDbuE9oUCwl\n"
      <<"ePRJSojAhagzZ6v+BCSBA2+npF5RCrxyn0eyjXGVyBmkYSnBFHVSwvuCVCUFyN3TKD7haecl9lCC\n"
      <<"rysMQwmrZBu2EjujaI4SrFglJQHJia6Ahhk3cA+ml4cr4fcSTslq/mwxOD8MhiGWkjYpCVWCqvkR\n"
      <<"NM0AXGdwz/+xV1xyayUd8AmU4HI0I3g3S4lOShwlzAuuK1PXRfyKBEsCByuxWysxwhfDVlI4DN2D\n"
      <<"jamXHKcEjQ89d2msck6bePn4NS6j45Vgd3ZGSsJn99ZtTM0uc0mblHDuBn6yd+x/2wr5hKadHZUo\n"
      <<"X4HqjZUMYLYASlD7G3ylr6OVTGmNi6PkRGyi49xJB/wWxVeCF1VryVFCR4FajdtmqX3opmglWdov\n"
      <<"4Si58FdrH8RgQrSot32V4PHAdGpLJQXYjABKQDFqX4MxsUps2ntnKXlQF1w4JQGMWCiWxykpyDIt\n"
      <<"rGQqwetmcmYraby1qIlhiK1Epfu4eEpy9/D8TftqoUWdxSFK8A74MI08JWj/omYrkQSHG6h9rAQv\n"
      <<"LtRJCYwExccoXKJFvR2oRBj4ZzxUvJKM/w7oiyrrlq9ENen7JUwlH2KG7N5d5KJb1P1IJd0MYwor\n"
      <<"gRKUkWhgSAn+XQXVYzqeEjlOGbVUl5TAXIm7sZhPJ7qSLaoSRyrRc1BuVsYoaajZAisBvhQ1YJlQ\n"
      <<"Jdn0LV3XNbfBzGTqpATnLeaTXcil4A945ezZw1ygkvhHDRUtX8msAUyghPSV0X4soYQbmZTglGCJ\n"
      <<"i/lm96QvLjGY8yFPQG1atpIJ3MIFlJC+JnrAGrZ+HldSglMS7YDbiMArxynRZg5OJ4OUNIs3cxn3\n"
      <<"54ES2pdeeK3d9tmOSQn3ool/aiV598rbwUqEWlMsKkSJ54h2aZV1hEpwv2hd0lsqsSIpYSm5xpza\n"
      <<"hVRy2lEJnIlx6gAl8rawQuR5TYYpGRdPZsCTBF9JIZKSkHyKUXIllZT/gRIxmjk8XYAST79QdJna\n"
      <<"QCXNooMaguYryWRSckAv+b+VCD1w5lhaiTDk/8adZ2YJU6KJOiRfHrZSYrRISvhK4ueSy3+hZN2z\n"
      <<"5y1WMlErqdKjjlCCZ/cRtBq1jRLTiqSEvcYVpeS/6iVfoos5OC1Uoj0DDaVRByoxYOPQgmmCq2TQ\n"
      <<"IilhK3mLeXLqEx/WVZJHKMFpg50MUImgFnczTzGFKbFwQiL6V6SSQoqkJFTJE3wyJrFnzH5JzlJC\n"
      <<"R9aB84mFSpRvfvf+8xio5Ea3NHLkqaOVmFGIpAQowQN45ALZ85/vvbtPXMcxUIkYvFVTeDyEKWnx\n"
      <<"cK4YhwGZpEhKou4JfsT8baCP5Em/dlaCo6YbbCZQiZ2dSN/sXgcq6Vg7N2OMEvPVSFKyRsmd8z5c\n"
      <<"uC6+KkxJHqEkXsoAlUjjKevaQydQiQkYOmpcqe26a62k5HN757qlJgxF4UOCgKBcBOWiDuH9X7L2\n"
      <<"vtok7BBEYSbf6p9OhYZZ51vJDkkE1Y4r/WS/V5Hp5RPtq/oSbIo+pqTIEsoUpe8pErjaEpzdq1Ri\n"
      <<"r2infV/iLLGwJFcmcMvkfx+paX8tljxIY29Q0kBL0kHiOkgcDC2pBzuu9pZc0k1b4hflCyzBCfxo\n"
      <<"vwmrGJGvWJElDzqlJxm0hJIBUxGwZGJxW9zokj2oBgXJdi0pCyaE/wZLPmwuxP1FAYPJqfyPj8Ut\n"
      <<"wbt+K2xJN2A6Q0uywZbOaEcv9wYFzTYt+aGIeI8lgfUZjP5YpDlPP324XNwSXKMXbAl5hjPK2BI+\n"
      <<"WJNgS/TbB9LtWfJTkbdZQsz22Lpe7i5G5evXZomq3g0siQdEbGhJM9iTQkv0ja02ZklZREKIt1rS\n"
      <<"C4nAshMqRuUTwdosUS1exJbwAcENLakHe67YEn2MijdkyU9FnmsJm2zJGaRmkN117b8JiX5tljSD\n"
      <<"RIotoR3c22RmyX6YwcXAEn00OWzEkuC3Iu/uS1ohUxKkFDIgtQh/ZZZ0Npbgmak9tATbhmmwJXoX\n"
      <<"601YEnxXZB2W0F1I5ATJQRfEhQxrV28JHHHhkVJNZpbwYRYVtmQkmmRbsMQX67HkLGQKAoSw+Tch\n"
      <<"06/LktjCEpy6G0NL4mEeB2jJWDTZO0uQJfh72c/T2x/hIZm4vcSSuCMjdlZzXA8uODBgS7xhHpmp\n"
      <<"JVzVXG8D+0vWZAkVoC2GzQ/lMZnM8RWW7IYaeKIrds/MkiucfMKW7Ie5AEvAf7Vzlkyy5AQaY9Z6\n"
      <<"xqWRnIr89ApLBqUneMCVmFmSwhcZ2JLdMJcGWTJudecsmWIJHYWKAmQS+BuJhJLwFZY8qBtUADJX\n"
      <<"bAlYzJWQmSV8mE1tbAlVynMdnSVTLDmpt3fkJSkIcqGCcU3LZaLz4pb85HI9kMRoBO+AJXi41EFL\n"
      <<"9Nk9G6FS5XdgCTgPNtmiJex2eqolJxPG1+feJW/LXqj50M8xy7AiWNaSP3hZx0lBVw0qOLIETQZ7\n"
      <<"ZGiJN3HhSKqyCliCDrpstmYJu/mz95dgdB1Oy/T17Lf0C+4XkW5vYQ4WsUiwPvRP4EHtLfmHOov3\n"
      <<"Kf3l0GQeGC5BS5pBTWxoSTe5aBOV1MASFE3STVlylBR5rSV0Hv3QvT8ej/dIjBBoEgwgetz6dnvc\n"
      <<"PJc8nWeJjFclyS6pqsuMfe84VnBkib7mL9NjVAwsQdGk3o4lkiLzLWFTLaFezCJE7/UxS1vyhDNU\n"
      <<"8NaQjJAl+vHTdfoK5hpYAqNJvA1LgCKv6kuojcQM7qThxKY26J2WxNgSMBl8MLTkCroh0+mGPbAE\n"
      <<"RpPDopb0pydYcvQ5IdpioiXMyhIqtVdjopZ0lBvqSzwClsCcUJGhJZ7FWz4+yOyQJaj7q59qicz9\n"
      <<"o51hiZki/NwLsXRfgqIJJjDqCtnaLekmWdJp74At6QwXVuEq59ASMDGXPdkSmf7MyY7A5Er/KCSs\n"
      <<"LGHaSmU4amNArtpKX5IRsgR94EKGliQWQVo9yIuBJTia7Je2BOcKe4KCCTHTEpzoGWk0YRaSAE3Q\n"
      <<"jdl7LanJyBL8/TvYktR0GhhPU3nAEhxNPL6EJfgN2XyCMJo6wMGVBy2h0CZj+4QomZgKe7klXoot\n"
      <<"QRJwQ0uu5tPAeJAHLMGDtt0ilshE4YmeR/uRC4klZ4L/cp549eNPQJhTrrh2XSMuSRJsCe3U5YYt\n"
      <<"ucBpYPPJ4ARZgqNJt6wl87M8zusLp3ewhxKV9t3wqcOV55I6pamWyKW5N7Sksz78J1ZdCSzB2eaS\n"
      <<"LmSJfZbHeX0ZS5iRJdQewXWWb42C3LRx7A2WJJwsLKFaFWywJZX1eYt8kLkiS/Bbl2QhS3CWtz+Y\n"
      <<"67V9iYQfaWpX+lse0ATOr5sJTqthCpeGyMqSRpG/sSUpHvRM8d+DluBo0ixsiZzlywXyumDTLWGW\n"
      <<"lhAPzZ70g6bBw2iawSGHluBTgDEZJ0tL6CLnb2xJpqp0Qw4qw6AlOJqky1jCxrJ8QNNow1wAzCxh\n"
      <<"wDHpRwy/78clbM75bqxwFLb0D/LD0BhNZehISmRtyVXO39iSy6TlVLjEE2gJNq1ewBJIPiHL85+l\n"
      <<"M98SGSwMs5tnu5/nzHFj8iIweED49Qs1DO0xJ7KyRM7CqaElzcQlXDhWpNASfI94WUuYtpC4dV6X\n"
      <<"QwC2JLIiH6tnjSj3mfPewUfPxgws/NbsAQmSNpk36KjilEaovP/hJJF5v9mRBJfuUBFR4klcyZza\n"
      <<"k4iJDtIPE9KTeTKpxhLpg9nYO4w7NgRmeZzXMXl4olfR+uHxH1XyY+hzegKn73dm/z1ZX4T+8x+O\n"
      <<"7+Ms+dcVL8maAzkW4ATCA8ryeOyBiYqAXk4bBKXvl0HQLnHroPRLfO/58HS/77r9fp9ycgAWWlsF\n"
      <<"szxWDvdTt5Icjg3g38TsQVIr53VM75PDsRn8Xkzmfm5VeR3D/qx/cTg2hZTljd/Ll7d153WHY5Es\n"
      <<"z4yDBTtuJK87HBjz7+lZFubyumP7WAygzN+PH11ed3wSDMI4Q//I5A/ezy6vOz4R6oldJiDM5XXH\n"
      <<"F+J3lmdQBEwUurzu+KSABSeGsMLldcenxmzxIlP1MS6vO74O2iyPuZ/dMjzHF0G3qYqN/jR3S1Ac\n"
      <<"X4s2zE0EcXnd8bUxz/LMLUFxfF3+z/Iurzsc07N87/K6w6E50NRtGXE48KE9kVuC4nBIWd7ldYfD\n"
      <<"+GCJm8vrDsdIlmcurzs+L98Ax2puYCz4oKsAAAAASUVORK5CYII=\" alt=\"Logismart\" height=\"35\" style=\"height: 35px; margin-left:7px; margin-top:-5px\" />\n </a>\n"<<endl;

    lt<<"<td>\n <a href=\"https://www.facebook.com/profile.php?id=100057528846124\"> \n"
      <<"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAlgAAAJYAgMAAADDCHBPAAAACVBMVEUAAAAYd/L///8Lxa3XAAAA\n"
      <<"AXRSTlMAQObYZgAAAvZJREFUeNrs20FygkAURdFMsj8mf+L+nLDKJEVbTatEsaX46rkLaM7sVRfw\n"
      <<"1dd3LDT0nYu1HNaaU7DWnIK15pT3Zl3F7A/EwiphYWE9Q5TJhoVVwsLCerB4SlhYWFhYCVlXJ2f/\n"
      <<"GcLCwsLCSiSqDVhYWFhYGVhxpQSXjTiFhYWFhZVrd2oDFtYUFhZWJyvZ7tSwsEpYWFh9Jdud2oCF\n"
      <<"NYWFhdXJSrY7NSysEhYWVl/Jdqc2YGFNYWFhdbKS7U4NC6uEhYXVV7LdqQ1YWFNYWFhYi2FhYWEt\n"
      <<"9ums2D0srBLWmrDW9Lmszt0Zb3SM+xqwsLDasLD2ZLWie21YWFhYWC/COowjFhYWFlZ2VjzWWOtl\n"
      <<"1bCwsLCwsLCwsLCmsBbb6nbR/84ACwsLCwsLCwsLKwJrI1bP07GwTmFhXYSVnRW3w8KahYXVhvVs\n"
      <<"VjzWJrtTwzoLC6uGhXWjftZhHLH+DQvrLCys2uuy4v6wsJqwsOZhYTVhYc3DwmrCwpqHhdWEhTUP\n"
      <<"C6sJC2seFlZTOlZxdHbEwsLCwsLCwsLCwnpBVtIrBhYWFhYWFhYWFtarsu76Jfew/e2i/SUXCwsL\n"
      <<"CwsLCwsLCysDKyKwsLCwsN6TdYzAwsLCwtqHVYoVbf0Z/y8H6y8srMuwsEpYWJdh/bRfBycMw1AQ\n"
      <<"BU++pD/330rk4LAXCSPMxwqZV8HclsU6w/pD1uXPKGflXWDtWFjdsLCOsLC6YWEdYWF1w8I6wsLq\n"
      <<"hvUjrNZ+UT2rIbCwsPphYaUZ1vUClbOyO1hYWFhYWC0sLCwsrAnW+GfUs/IusLCwsLAqWOMFKmdl\n"
      <<"d7CwsLCwillpT5Ws7A4WFhYWVgFr3FbOyu5gYWFhYZWxxpWysjtYWFhYWKWscVsRK7uDhYWFhfUA\n"
      <<"KxWwsjtYWFhYWA+x0lbBaruDhYWFhbUCK7b7rIiwsLCwsBZitW6yciywsLCwsBZknW0TrPHkYGFh\n"
      <<"YWGtyfr06rMmRVhYWFhYa7K+9VjzGCwsLKxhWHdZb1jRxCTNao8eAAAAAElFTkSuQmCC\" alt=\"Facebook\" height=\"35\" style=\"border-radius:15px; height: 30px; display:inline-block; margin-left:5px; margin-top:-5px\" />\n </a>\n </td>\n"<<endl;

    lt<<"<td>\n <a href=\"https://www.linkedin.com/company/logismart-lithuania/posts/?feedView=all\">\n"
      <<"<img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAlgAAAJYAgMAAADDCHBPAAAACVBMVEUAAAAAd7X////ig02lAAAA\n"
      <<"AXRSTlMAQObYZgAAAuBJREFUeNrs1zGOwjAURVE37M+Nm+yPJqucjJKRhSCQj8NgwrmtZel0Tz+1\n"
      <<"dSor5dQU1npYKRBWCoSVAh2bdRPzfiAW1hIWFtYeop5sWFhLWFhYT1Z2CQsLCwurQ9bNyXn/DGFh\n"
      <<"YWFhdSSqZSwsLCysHljlRh0cG+UvLCwsLKy+dqeWsbDmsLCwGlmd7U4NC2sJCwurrc52p5axsOaw\n"
      <<"sLAaWZ3tTg0LawkLC6utznanlrGw5rCwsBpZne1ODQtrCQsLq63OdqeWsbDmsLCwsFbDwsLCWu3b\n"
      <<"WeVx42/lZWFhbQwLC+t+T+3OMP51Lq8qY2FtCgsLa2/WeFl5HBYWFtZqWFhYWKthYWEFWeVxgROj\n"
      <<"LSyszWFFwor0naypZ3cHKxJWJKxIWJEOxDqVzspYWHNYkbAiYUXCioQVCSsSViSsSFiRsCJhRcKK\n"
      <<"hHXdeNmjh2G87oyFhYWF9d+sUtuPNa5VNoaFhYWF1StrGO91xsLCwsL6YNYUFhYWFtbXsqawsLCw\n"
      <<"sD6bVeYGLCwsLKzDsS6OCCwsLCwsLCwsLCysD2FdfRywsLCwsLCwsLCwsLCwsLCwsGKslE69sXJK\n"
      <<"WFhYWFhYWFhYWFhYWFhYWFhYWFhYWEdlTfXEmjhYWFhYWFhYWD/t3TGKA0EMRNFK5n6d7P2vsjSe\n"
      <<"wNgYI5AZGb9/gpcVioSFhfWedXbMYK0ECwsLC6uPNezFNxbWGVYlrEpYlbAqYVXCqoRV6VdZSf4u\n"
      <<"LwkW1g6rElaln2ZdvEArwcLaYWFhYb0MCwsL62VYF94ZSbCwdlhYWD2sSQu0EiysHRYWVg9r1AIl\n"
      <<"wcLaYWFh9bAmLdBKsLB2WFhYPaxRC5QEC2uHhYXVw5q0QCvBwtphYWH1sEYtUBIsrB0WFlYPa9IC\n"
      <<"rQQLCwsLawLrZhsnwsLCwsJ6bMCxkQQLCwsLayDr7BgxOVhYWFhYH+wYJ8LCug8LC6sNOAmDhfUU\n"
      <<"VgphpdDXsP4BZuA4AqOGvgQAAAAASUVORK5CYII=\" height=\"30\" style=\"border-radius:50%; height: 30px; margin-top:-5px\"/>\n    </a>\n  </td>\n</table>\n"<<endl;

    if(kalba==L"lt")
    {
        lt<<"<table>\n <td style=\"padding-top:7px; padding-left:8px;\">\n"
        <<"<strong><a href=\"https://logismart.lt/kontaktai/\" style=\" text-decoration: none;\">Lietuva</a></strong>  "
        <<"|  <a href=\"https://logismart.lt/en/contacts/\" style=\" text-decoration: none;\">United Kingdom</a>  "
        <<"|  <a href=\"https://logismart.lt/de/kontakte/\" style=\" text-decoration: none;\">Deutschland</a>\n </td>\n </tr>\n  </table>\n"<<endl;

        lt<<"<hr style=\"width: 100%; border: none; border-top: 2px solid black; margin-top: 20px;\">\n"
        <<"<p style=\"font-size: 10px;\">\n Išmanioji logistika, UAB<br />\n"
        <<"Galinės g. 1, Galinė, LT-14247, Vilniaus r. sav., Lietuva <br />\n"
        <<"Įmonės kodas: 304751937, PVM mokėtojo kodas (VAT): LT100011569214 <br />\n"
        <<"IBAN LT247290000015467502 <br />\n AB Citadelė Bankas <br />\n"
        <<"Šis el. laiškas ir visi su juo perduodami failai yra konfidencialūs ir skirti tik tam asmeniui ar subjektui, kuriam jie yra adresuoti. "
        <<"Jei šią žinutę gavote per klaidą, prašome ją grąžinti siuntėjui atsakydami į ją ir tuomet ištrinti iš savo kompiuterio. "
        <<"LOGISMART (Išmanioji logistika, UAB) neatsako už šios žinutės turinio pakeitimus, atliktus po jos išsiuntimo. \n </p>\n </body>"<<endl;
    }

    else if(kalba==L"en")
    {
        lt<<"<table>\n <td style=\"padding-top:7px; padding-left:8px;\">\n"
        <<"<a href=\"https://logismart.lt/kontaktai/\" style=\" text-decoration: none;\">Lietuva</a>  "
        <<"|  <strong><a href=\"https://logismart.lt/en/contacts/\" style=\" text-decoration: none;\">United Kingdom</a></strong>  "
        <<"|  <a href=\"https://logismart.lt/de/kontakte/\" style=\" text-decoration: none;\">Deutschland</a>\n </td>\n </tr>\n  </table>\n"<<endl;

        lt<<"<hr style=\"width: 100%; border: none; border-top: 2px solid black; margin-top: 20px;\">\n"
        <<"<p style=\"font-size: 10px;\">\n LOGISMART FULFILLMENT Ltd<br />\n"
        <<"1 Springwood Dr, Braintree CM7 2YN, United Kingdom <br />\n"
        <<"Company code: 15320786, VAT number: GB456358760 <br />\n"
        <<"IBAN GB34REVO00996927985500 <br />\n Revolut Ltd <br />\n"
        <<"This e-mail message and any files transmitted with it are confidential and intended solely for the use of the individual or entity to whom they are addressed. "
        <<"If the message is received by anyone other than the addressee, please return the message to the sender by replying to it and then delete the message from your computer. "
        <<"LOGISMART (LOGISMART FULFILLMENT LTD) does not accept responsibility for changes made to this message after it was sent. \n </p>\n </body>"<<endl;
    }

    else {
        lt<<"<table>\n <td style=\"padding-top:7px; padding-left:8px;\">\n"
        <<"<a href=\"https://logismart.lt/kontaktai/\" style=\" text-decoration: none;\">Lietuva</a>  "
        <<"|  <a href=\"https://logismart.lt/en/contacts/\" style=\" text-decoration: none;\">United Kingdom</a>  "
        <<"|  <strong><a href=\"https://logismart.lt/de/kontakte/\" style=\" text-decoration: none;\">Deutschland</a></strong>\n </td>\n </tr>\n  </table>\n"<<endl;

        lt<<"<hr style=\"width: 100%; border: none; border-top: 2px solid black; margin-top: 20px;\">\n"
        <<"<p style=\"font-size: 10px;\">\n Logismart GmbH<br />\n"
        <<"Orber Str. 10, 60386 Frankfurt am Main, Deutschland <br />\n"
        <<"HRB 123968, USt-IdNr. DE346387238 <br />\n"
        <<"IBAN DE29100101231865944111 <br />\n Olinda Zweigniederlassung Deutschland <br />\n"
        <<"Diese E-Mail-Nachricht sowie alle damit übermittelten Dateien sind vertraulich und ausschließlich für den Gebrauch durch die Person oder Organisation bestimmt, an die sie adressiert sind. "
        <<"Wenn Sie diese Nachricht irrtümlich erhalten haben, bitten wir Sie, sie durch eine Antwort an den Absender zurückzusenden und anschließend von Ihrem Computer zu löschen. "
        <<"LOGISMART (Logismart GmbH) übernimmt keine Verantwortung für nachträgliche Änderungen an dieser Nachricht nach dem Versand. \n </p>\n </body>"<<endl;
    }

    lt.close();
    wcout<<L"Parašo .html failas sukurtas!"<<endl;
}
