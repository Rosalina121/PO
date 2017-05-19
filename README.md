# PO

Kacper Bialecki - Projekt na programowanie obiektowe - Symulacja wydarzenia esportowego

Projekt polega na symulacji zarządzania wydarzeniem esportowym. Zadaniem uzytkownika będzie odpowiednia dystrybucja zasobami by impreza się udała i stan konta po zakończeniu symulacji był większy bądź równy początkowemu. Sesja trwa 6 dni (3 weekendy) bądź dowolny okres czasu (wyrażany w dniach) sprecyzowany przez użytkownika.
Z technicznej strony projekt zawierać bedzie klasy odpowiadające różnym elementom symulacji takie jak: Venue, Teams czy Sponsors oraz szereg zmiennych, które będą w jakiś sposób zmieniane po każdej aktualizacji symulacji (koniec dnia, losowa awaria sprzętu itp.). To jak te zmienne bedą się zmieniały zależy od poprzednich decyzji użytkownika. Przykładowo, im więcej zainwestujemy w sprzęt komputerowy tym mnijesza jest szansa na jego awarię, co za to bedzie skutkować zwiększonym zadowoleniem widzów.

Symluacja kończy się w 3 przypadkach:
1. Użytkownik dotarł do końca ostatniego dnia symulacji. W zalezności czy saldo końcowe jest wyższe od początkowego zostanie wyświetlona wiadomośc o wygranej bądź przegranej.
2. Użytkownik zbankrutuje zanim skończy symulację.
3. Uzytkownik nie zainwestuje wystarczających środków by wydarzenie się rozpoczęło.

# Harmonogram

Plan pracy na nastepne tygodnie:
1. Dokończyć klasy obiektów programu oraz dopisać wszytstkie metody (interakcja, działanie). Dokończenie funkcji inicjalizujcych symulację.
2. Zaprogramować system działania aktualizacji, czyli tego, jak program będzie podsumowywał kazdy dzień i obliczał zmienne (saldo, zadowolenie itd.). Zaprogramować system rozgrywek i jego wpływ na inne elementy symulacji.
3. Stworzenie zdarzeń losowych wynikających z poprzednich działań uzytkownika. Awarie/opóźnienia, obecność znanych osób i wypadki. Każde z nich bedzie w jakis sposób wpływało na rozgrywkę (zarówno pozytywnie i negatywnie).
4. Dopracowanie kodu w taki sposób, by był jak najbardziej niezawodny (w skrócie idiotoodporny). Stworzenie systemu, który będzie przekazywał informacje o wydarzeniach w symulacji uzytkownikowi w postaci nagłówków w stylu serwisów informacyjnych. 

Plan ten może ulec niewielkim zmianom (zależy od szybkosci pracy nad projektem i ewentualnymi problemami z realizacją ideii.
