# PO

Kacper Bialecki - Projekt na programowanie obiektowe - Symulacja wydarzenia esportowego

Projekt polega na symulacji zarządzania wydarzeniem esportowym. Zadaniem uzytkownika będzie odpowiednia dystrybucja zasobami by impreza się udała i stan konta po zakończeniu symulacji był większy bądź równy początkowemu. Sesja trwa 6 dni (3 weekendy) bądź dowolny okres czasu (wyrażany w dniach) sprecyzowany przez użytkownika.
Z technicznej strony projekt zawierać bedzie klasy odpowiadające różnym elementom symulacji takie jak: Venue, Teams czy Sponsors oraz szereg zmiennych, które będą w jakiś sposób zmieniane po każdej aktualizacji symulacji (koniec dnia, losowa awaria sprzętu itp.). To jak te zmienne bedą się zmieniały zależy od poprzednich decyzji użytkownika. Przykładowo, im więcej zainwestujemy w sprzęt komputerowy tym mnijesza jest szansa na jego awarię, co za to bedzie skutkować zwiększonym zadowoleniem widzów.

Symluacja kończy się w 3 przypadkach:
1. Użytkownik dotarł do końca ostatniego dnia symulacji. W zalezności czy saldo końcowe jest wyższe od początkowego zostanie wyświetlona wiadomośc o wygranej bądź przegranej.
2. Użytkownik zbankrutuje zanim skończy symulację.
3. Uzytkownik nie zainwestuje wystarczających środków by wydarzenie się rozpoczęło.
