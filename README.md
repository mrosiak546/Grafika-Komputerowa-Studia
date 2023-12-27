# Grafika-Komputerowa-Studia
Projekty na przedmiot Grafika Komputerowa 

#Paint
Projekt ten napisany jest w języku C++ z użyciem frameworka QT i zawiera poszczególne 
typy projektów które były do realizacji na przedmiocie Grafika Komputerowa.

#Rysowanie pikseli
Metody '#drawPixel' oraz '#drawPixel2' rysują piksel na określonych współrzędnych'#(x,y)'.
Piksele te są rysowane wybranym kolorem RGB który jest ustawiany w kodzie.

#Rysowanie Linii
Metoda '#drawLine' pozwala na rysowanie linii między dwom punktami '#(x1,y1)' i #(x2,y2).
Obsługuje ona rysowanie linii o róznych nachyleniach i orientacjach.

#Rysowanie Koła
Metoda '#drawCircle2' pozwala na rysowanie koła o środku w punkcie '#(x,y)' i zadanym promieniu
wykorzystuje ona piksele do narysowania tego koła.

#Rysowanie Elips
Metoda 'drawEllipse' pozwala na narysowanie Elipsy o środku w punkcie '#(x,y)' z długościami półosi zadane przez '#e' i '#f'. W programie zawarty jest również suwak pozwalający na manipulowanie naszą elipsą

#Krzywa Beziera
Metoda '#drawBezier' pozwala na narysowanie krzywej Beziera na podstawie punktów kontrolnych przechowywanych w wektorze '#qBezier'. Obsługuje krzywe Beziera stopnia trzeciego.

#B-spliny
Metoda '#drawBSpline' pozwala na narysowanie krzywej B-spline na podstawie punktów kontrolnych przechowywanych w wektorze.

#Interakcja z punktami
Metody '#drawPoints', '#findPoints' i '#replacePoint' służą do manipulacji punktami kontrolnymi krzywych Beziera, B-splinów oraz ScanLine.

#Wypełnianie
Metoda '#flood_fill' pozwala nam na zamalowanie całego obrazu lub narysowanego rysunku na dowolnie wybrany kolor. Zaczyna od określonego piksela '#(x0,y0)'. Używa podejścia opartego na stosie.

#ScanLine
Metoda '#scanLine' wykonuje wypełnianie algorytmem Scan Line kolorem wybranym przez użytkownika wewnątrz wielokąta określonego przez punkty kontrolne w wektorze.

#RGB I HSV
Metoda '#barwy' generuje nam obraz w zależności od wybranego rodzaju kanału. Kanały zawarte w kodzie to RGB oraz HSV.

#Przyciski Myszy

