# Parametry projektu

Nazwa: pm-lab-3  
Autor: Paweł Dąbal (pawel.dabal@wat.edu.pl)  
Opis: Projekt bazowy repozytorium na trzecie spotkanie laboratoryjne z przedmiotu _Programowanie mikrokontrolerów_.  
Wersja: v1.0  
Data: 23.05.2020 r.

# Informacje o studencie

Imię i nazwisko studenta: Łukasz Drozd<br/>
Numer albumu: 53371<br/>
Grupa studencka: WEL18EX1N1<br/>

# Odpowiedzi do pytań z instrukcji
# W jaki sposób można rozbudować funkcjonalność programu w przypadku gdy liczba naciśnięć przycisku przekroczy określoną ilość?
<br/>
Dodać do w warunku if (linia w kodzie 25) dodatkowy warunek && liczba_nacisniec =< [podać liczbe lub zapisać do zmiennej globalnej określająca ile razy można wcisnąć przycisk] 

To przypadek gdy chcemy zablokować dalsze wciskanie przycisku, a gdy chcemy poinformować użytkownika do środku ifa (linia w kodzie 25) dodać nowy if ze sprawdzeniem czy przekroczono ilość wciśnięć i pointormowąc użytkownika do terminala a następnie wyczyścić zmienną która sprawdzala ilość określonych wciśnięć

# W jaki sposób można zwiększyć liczbę obsługiwanych poleceń oraz liczbę obsługiwanych parametrów?

<br/>
Dodać do naszej logiki biznesowej kolejny wymyśloną komende którą chcemy obsłużyć 
<br/>
else if (!strcmp(paramStr, "[nazwa naszej nowej komendy]")) 
<br/>
{
    <br/>
    do your business logic :)
    <br/>
}
<br/>

Najlepiej zastosować tutaj wzorzec projektowy command do lepszego zarządzania kodem w przyszłości i pozybycia się dodawania kolejnych warunków else if aby nie łamać 2 zasady solid open/closed