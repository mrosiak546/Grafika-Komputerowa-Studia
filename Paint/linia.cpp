#include "linia.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include <math.h>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QStack>
#include <QColorDialog>
#include <QPointF>
#include <QColor>
//#include "ui_mainwindow.h"
//#include "mainwindow.h"
using namespace std;

bool bKolor = false;
QColor kolor;

Linia::Linia(QWidget *parent)
    : QWidget{parent}
{
    im = QImage(961,571,QImage::Format_RGB32);
    im.fill(0);
    im2 = QImage(961,571,QImage::Format_RGB32);
    im3 = QImage(961,571,QImage::Format_RGB32);
    //im2=im;
    //drawPixel(100,60,255,255,255);
    //drawLine(0,0,10,20);
}

void Linia::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(0,0,width(),height(),Qt::green);
    p.drawImage(0,0,im);
}

void Linia::mousePressEvent(QMouseEvent *e)
{
    im2=im;
    startPos = e->pos();// ustawienie startowej pozycji na tą gdzie znajduje się nasza myszka

    //Bezier
    if(e->buttons() & Qt::LeftButton)
    {
        if(tryb == 4)
        {
            qBezier.enqueue(startPos); //dodanie do kolejki punktu startowego
            drawBezier();//rysowanie beziera
            update();
        }

        if(tryb == 5)
        {
            qBSline.enqueue(startPos); //dodanie do kolejki punktu startowego
            drawBSpline();//rysowanie beziera
            update();
        }

        if(tryb == 6)
        {
            QRgb rgb = im.pixel(startPos.x(),startPos.y());
            flood_fill(startPos.x(),startPos.y(),rgb);
            update();
        }

        if(tryb == 7)
        {
            if (bKolor == false)
            {
                QColor wybor = QColorDialog::getColor(Qt::black, this, "Wybierz kolor"); // Wyświetlenie dialogu z wyborem koloru
                if (wybor.isValid()) // Sprawdzenie, czy wybrany kolor jest poprawny
                {
                    bKolor = true;// Ustawienie flagi na true, żeby kolor został wybrany tylko raz
                    kolor = wybor;
                }
            }
            else
            {
                qScanLine.append(startPos);
                drawPoints();
                scanLine(kolor);
                update();
            }
        }
    }

    if(e->buttons() & Qt::RightButton)
    {
        if(tryb == 4)
        {
            pom = findPoints();
        }

        if(tryb == 5)
        {
            pom = findPoints();
        }
        if(tryb == 7)
        {
            pom = findPoints();
        }
    }

    if(e->buttons() & Qt::MiddleButton)
    {
        if(tryb == 4)
        {
            if(qBezier.size()>0)
            {
                pom = findPoints();
                qBezier.removeAt(pom);
                drawBezier();
                update();
            }
        }

        if(tryb == 5)
        {
            if(qBSline.size()>0)
            {
                pom = findPoints();
                qBSline.removeAt(pom);
                drawBSpline();
                update();
            }
        }

        if(tryb == 7)
        {
            if(qScanLine.size()>0)
            {
                pom = findPoints();
                qScanLine.removeAt(pom);
                scanLine(kolor);
                update();
            }
        }
    }
}



void Linia::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton) //reakcja na klikniecie lewego przycisku myszy
    {
        /*
         Do rysowania samym pikselem
        */
//        int x = e->pos().x();
//        int y = e->pos().y();

//        uchar *pix = im.scanLine(y) + 4 * x;
//        pix[0] = 255;
//        pix[1] = 255;
//        pix[2] = 255;

//        drawPixel(m_startPos.x(),m_startPos.y(),255,255,255);
//        update(); //odświeżenie widgetu
        /*
        --------------------------------------
        */

        /*
         Do rysowania linii
        */
        /*
         Jezeli nie ma im = im2 to na ekranie widzimy kazda linie podczas ruszania nasza myszką
         czyli wiele linii naraz kazdej jej ruszenie spowoduje wypisanie innej linii ktora
         jest nam niepotrzebna
        */
//       if (e->buttons() & Qt::LeftButton) //reakcja na klikniecie lewego przycisku myszy
//        {
         /*
         Jezeli nie ma im = im2 to na ekranie widzimy kazda linie podczas ruszania nasza myszką
         czyli wiele linii naraz kazdej jej ruszenie spowoduje wypisanie innej linii ktora
         jest nam niepotrzebna
         */
//            im=im2;
//            endPos = e->pos(); //ustawienie koncowej pozycji na miejsce naszego kursora
//            drawLine(startPos.x(), startPos.y(), endPos.x(), endPos.y());//rysowanie linii
//            update(); //odświeżenie widgetu
//        }
        /*
        --------------------
        */

        /*
         Do rysowania kola
        */
//        if (e->buttons() & Qt::LeftButton)
//        {
//            im=im2;
//            endPos = e->pos();
//          int r = sqrt(pow(startPos.x()-endPos.x(), 2)+pow(startPos.y()-endPos.y(), 2));
//          drawCircle(startPos.x(), startPos.y(), r);
//            drawCircle2(startPos.x(),startPos.y(),endPos.x(),endPos.y());
//            update(); //odświeżenie widgetu
//        }
        /*
        --------------------
        */

        /*
         Do rysownia elipsy
        */
  //      if (e->buttons() & Qt::LeftButton)
      //  {
            im=im2;
            endPos = e->pos();

            //drawEllipse(startPos.x(),startPos.y(),e,f,5);
            if(tryb==0){
                drawPixel(endPos.x(),endPos.y(), 255, 255, 255);
                im2=im;
            }
            else if(tryb==1){
                drawLine(startPos.x(),startPos.y(), endPos.x(), endPos.y());
            }
            else if(tryb==2){
                int r = sqrt(pow(startPos.x()-endPos.x(), 2)+pow(startPos.y()-endPos.y(), 2));
                drawCircle2(startPos.x(),startPos.y(),endPos.x(), endPos.y());
            }
            else if(tryb==3){
                int e = abs(startPos.x()-endPos.x());
                int f = abs(startPos.y()-endPos.y());
                drawEllipse(startPos.x(),startPos.y(),e,f,n);
            }

            update();
    //    }
        /*
         --------------------
        */

    }

    if (e->buttons() & Qt::RightButton)
    {
         endPos = e->pos();
            if(tryb == 4)
            {
                replacePoint(pom);
                drawBezier();
                update();
            }
            else  if(tryb == 5)
            {
                replacePoint(pom);
                drawBSpline();
                update();
            }
            else  if(tryb == 7)
            {
                replacePoint(pom);
                scanLine(kolor);
                update();
            }
    }  
}

void Linia::mouseReleaseEvent(QMouseEvent *)
{
    if(tryb == 4)
    {
            im3=im2;
            drawBezier();
            update();
    }

    if(tryb == 5)
    {
            im3=im2;
            drawBSpline();
            update();
    }

    if(tryb == 7)
    {
            im3 = im2;
            scanLine(kolor);
            update();
    }
}


void Linia::drawPixel(int x,int y,int r,int g,int b)
{
    if(x<im.width() && x>=0 && y<im.height() && y>=0)
    {
            uchar *pix = im.scanLine(y) + 4 * x;
            pix[0] = r;
            pix[1] = g;
            pix[2] = b;
    }
}

void Linia::drawPixel2(int x,int y,int r,int g,int b)
{
    if(x<im.width() && x>=0 && y<im.height() && y>=0)
    {
            uchar *pix = im.scanLine(y) + 4 * x;
            pix[2] = r;
            pix[1] = g;
            pix[0] = b;
    }
}

void Linia::drawLine(int x1,int y1,int x2,int y2)
{
    //Uwzglednic ze oba punkty są zerami !! bo moze byc problem
    int x, y;
//    if(x1>im.width()) x1 = im.width();
//    if(x2>im.width()) x2 = im.width();
//    if(x1<0) x1 = 0;
//    if(x2<0) x2 = 0;
//    if(y1>im.height()) y1 = im.height();
//    if(y2>im.height()) y2 = im.height();
//    if(y1<0) y1 = 0;
//    if(y2<0) y2 = 0;
    if((x1 == x2) && (y1==y2))
    {
        drawPixel(x1,y1,255,255,255);
        return;
    }
    if(abs(y2-y1) <= abs(x2-x1))
    {
        /*
         Pojawienie sie problemu z rysowaniem linii w z prawej do lewej czyli zmniejszanie wartości
         aby to zrobić należało zmienić kolejność aby uzyskiwac poprawne wartości co gwarantuje nam podany warunek
        */
        if (x1 > x2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        for(x=x1; x<=x2; x++)
        {
            y=y1+(x-x1)*(y2-y1)/(x2-x1);
            drawPixel(x, y, 200, 200, 200);
        }
    }
    else
    {
        /*
         Pojawienie sie problemu z rysowaniem linii w z góry na dół czyli zmniejszanie wartości
         aby to zrobić należało zmienić kolejność aby uzyskiwac poprawne wartości co gwarantuje nam podany warunek
        */
        if (y1 > y2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        for(y=y1; y<=y2; y++)
        {
            x=x1+(y-y1)*(x2-x1)/(y2-y1);
            drawPixel(x, y, 200, 200, 200);
        }
    }
}

void Linia::drawLine2(int x1, int y1, int x2, int y2, const QColor& color)
{
    int x, y;

    if (x1 == x2 && y1 == y2)
    {
            drawPixel2(x1, y1, color.red(), color.green(), color.blue());
            return;
    }

    if (abs(y2 - y1) <= abs(x2 - x1))
    {
            if (x1 > x2)
            {
                std::swap(x1, x2);
                std::swap(y1, y2);
            }

            for (x = x1; x <= x2; x++)
            {
                y =(double)( y1 + (x - x1) * (y2 - y1) / (x2 - x1));
                drawPixel2(x, y, color.red(), color.green(), color.blue());
            }
    }
    else
    {
            if (y1 > y2)
            {
                std::swap(x1, x2);
                std::swap(y1, y2);
            }

            for (y = y1; y <= y2; y++)
            {
                x = (double)(x1 + (y - y1) * (x2 - x1) / (y2 - y1));
                drawPixel2(x, y, color.red(), color.green(), color.blue());
            }
    }
}

//Rysowanie Kola
void Linia::drawCircle(int x, int y, int r)
{
    int pxTemp, pyTemp;
    for (int i = 0; i <= 360; i++)
    {
        float rad = i * M_PI / 180;
        int px = x - r * cos(rad); // x + r * cos(rad) gwarantuje nam ze mozemy rysowac kolo z dowolnego miejsca
        int py = y - r * sin(rad); //y + r * sin(rad) gwarantuje nam ze mozemy rysowac kolo z dowolnego miejsca
        if(i>0)
        {
            drawLine(px, py, pxTemp, pyTemp);
        }
        pxTemp=px;
        pyTemp=py;
    }
}

void Linia::drawCircle2(int x0,int y0,int x1,int y1)
{
    float R = sqrt(((x1-x0)*(x1-x0))+((y1-y0)*(y1-y0)));
        for(int i=-R; i<=R; i++)
        {
            double y = sqrt(R*R - i*i);
            drawPixel(i+x0,(int)floor(y+0.5)+y0,255,255,255);      // prawy dół
            drawPixel(i+x0,-(int)floor(y+0.5)+y0,255,255,255);    //prawa góra
            drawPixel(-i+x0,(int)floor(y+0.5)+y0,255,255,255);   //lewy dół
            drawPixel(-i+x0,-(int)floor(y+0.5)+y0,255,255,255);
            drawPixel((int)floor(y+0.5)+x0,i+y0,255,255,255);       //prawy środek "dół"
            drawPixel(-(int)floor(y+0.5)+x0,i+y0,255,255,255);     //lewy środek "dół"
            drawPixel((int)floor(y+0.5)+x0,-i+y0,255,255,255);    //prawy środek "góra"
            drawPixel(-(int)floor(y+0.5)+x0,-i+y0,255,255,255);  //lewy środek "góra"//lewa góra
        }
}
//Rysowanie elipsy
void Linia::setN(int value)
{
    n = value;
    update(); //odswiez widok
}

void Linia::drawEllipse(int x, int y, int e, int f, int n)
{
    int px_temp, py_temp;
    for (int i = 0; i <= n; i++)
    {
        float rad = i * M_PI / n * 2;
        int px = x - e * cos(rad);
        int py = y - f * sin(rad);
        //drawPixel(px, py, 255, 255, 255);
        if(i>0)
        {
            drawLine(px, py, px_temp, py_temp);
        }
        px_temp=px;
        py_temp=py;
    }
}

//Bezier
void Linia::drawPoints()
{
    if(tryb == 4)
    {
        for (int i = 0; i < qBezier.size(); i++)
        {
            drawCircle2(qBezier.at(i).x(),qBezier.at(i).y(),qBezier.at(i).x()+2,qBezier.at(i).y());
        }
    }
    else if(tryb == 5)
    {
        for (int i = 0; i < qBSline.size(); i++)
        {
            drawCircle2(qBSline.at(i).x(),qBSline.at(i).y(),qBSline.at(i).x()+2,qBSline.at(i).y());
        }
    }
    else if(tryb == 7)
    {
        for (int i = 0; i < qScanLine.size(); i++)
        {
            drawCircle2(qScanLine.at(i).x(),qScanLine.at(i).y(),qScanLine.at(i).x()+2,qScanLine.at(i).y());
        }
    }
}
int Linia::findPoints()
{
    int minDist = -1;
    int n = -1;
    if(tryb == 4)
    {
        for (int i = 0; i < qBezier.size(); i++)
        {
            int dist = (qBezier.at(i) - startPos).manhattanLength();
            if (minDist == -1 || dist < minDist)
            {
                minDist = dist;
                n = i;
            }
        }
    }
    else if(tryb == 5)
    {
        for (int i = 0; i < qBSline.size(); i++)
        {
            int dist = (qBSline.at(i) - startPos).manhattanLength();
            if (minDist == -1 || dist < minDist)
            {
                minDist = dist;
                n = i;
            }
        }
    }
    else if(tryb == 7)
    {
        for (int i = 0; i < qScanLine.size(); i++)
        {
            int dist = (qScanLine.at(i) - startPos).manhattanLength();
            if (minDist == -1 || dist < minDist)
            {
                minDist = dist;
                n = i;
            }
        }
    }

    return n;
}

void Linia::replacePoint(int i)
{
    if(tryb == 4)
    {
        if(i==-1) return;
        qBezier.replace(i, endPos);
        update();
    }
    else if (tryb == 5)
    {
        if(i==-1) return;
        qBSline.replace(i, endPos);
        update();
    }
    else if (tryb == 7)
    {
        if(i==-1) return;
        qScanLine.replace(i, endPos);
        update();
    }
}

//Bezier
void Linia::drawBezier()
{
    int bXt, bXt_temp, bYt, bYt_temp;
    int n=qBezier.size();
    im.fill(0);
    drawPoints();

    if(n>=4)
    {
      while((n-4)%3) n--; //warunek do rysowania linii po pierwszych 4 punktach
      for (int i = 1; i < n; i+=3)
      {
            for(float t=0; t<=1; t+=0.02)
            {
                bXt = pow((1 - t), 3) * qBezier[i-1].x() + 3 * pow((1 - t), 2) * t * qBezier[i].x() + 3 * pow((1 - t), 1) * pow(t, 2) * qBezier[i+1].x() + pow(t, 3) * qBezier[i+2].x();
                bYt = pow((1 - t), 3) * qBezier[i-1].y() + 3 * pow((1 - t), 2) * t * qBezier[i].y() + 3 * pow((1 - t), 1) * pow(t, 2) * qBezier[i+1].y() + pow(t, 3) * qBezier[i+2].y();
                if(t>0){
                    drawLine(bXt_temp, bYt_temp, bXt, bYt);
                }
                bXt_temp=bXt;
                bYt_temp=bYt;
            }
      }

    }
}

//BSpline
void Linia::drawBSpline()
{
    int bXt, bXt_temp, bYt, bYt_temp;
    float t;
    im.fill(0);
    drawPoints();

    if(qBSline.size()>=4)
    {
      for (int i = 3; i < qBSline.size(); i++)
        {
            for(t=0; t<=1; t+=0.02)
            {
                bXt = (-(t*t*t) + 3*(t*t) - 3*t +1)/6 * qBSline[i-3].x() + (3*(t*t*t) - 6*(t*t) +4)/6 * qBSline[i-2].x() + (-3*(t*t*t) + 3*(t*t) + 3*t +1)/6 * qBSline[i-1].x() + t*t*t/6 * qBSline[i].x();
                bYt = (-(t*t*t) + 3*(t*t) - 3*t +1)/6 * qBSline[i-3].y() + (3*(t*t*t) - 6*(t*t) +4)/6 * qBSline[i-2].y() + (-3*(t*t*t) + 3*(t*t) + 3*t +1)/6 * qBSline[i-1].y() + t*t*t/6 * qBSline[i].y();

                if(t>0)
                {
                 drawLine(bXt_temp, bYt_temp, bXt, bYt);
                }
                bXt_temp=bXt;
                bYt_temp=bYt;
            }
        }
    }
}

//Pomocnicze QColorDialog QFileDialog

void Linia::flood_fill (int x0, int y0, QRgb rgb)
{
    int x,y;
    QColor Kolor = QColorDialog::getColor(Qt::white, this, "Kolor");
    if(!Kolor.isValid()) return;

    QRgb RGB = Kolor.rgb();
    if(RGB == rgb) return;

    stack.push(QPoint(x0,y0));
    while (!stack.isEmpty())
    {
        x = stack.top().x();
        y = stack.top().y();
        stack.pop();
        if(im.pixel(x,y) == rgb)
        {
            drawPixel(x, y, qBlue(RGB), qGreen(RGB), qRed(RGB));
            if (y>=0 && y<im.height())
            {
                if (x+1 >= 0 && x+1 < im.width())
                 stack.push(QPoint(x+1,y));

                if (x-1 >= 0 && x-1 < im.width())
                 stack.push(QPoint(x-1,y));
            }
            if (x>=0 && x<im.width())
            {
                if (y+1 >= 0 && y+1 < im.height())
                 stack.push(QPoint(x,y+1));

                if (y-1 >= 0 && y-1 < im.height())
                 stack.push(QPoint(x,y-1));
            }
        }
    }
}

//scanLine
void Linia::scanLine(const QColor& color)
{
    im.fill(0);
    drawPoints();

    QVector<int> x; // Wektor przechowujący współrzędne x
    int p1, p2; // Indeksy punktów

    if (qScanLine.size() < 3)
        return; // Jeśli mniej niż 3 punkty na linii, zakończ funkcję

    int yMax = qScanLine[0].y(); // Największa wartość y
    int yMin = qScanLine[0].y(); // Najmniejsza wartość y

    // Znajdź największą i najmniejszą wartość y na linii
    for (int i = 0; i < qScanLine.size(); i++)
    {
        if (qScanLine[i].y() > yMax)
            yMax = qScanLine[i].y();
        if (qScanLine[i].y() < yMin)
            yMin = qScanLine[i].y();
    }

    for (int y = yMin; y <= yMax; y++)
    {
        for (int i = 0; i < qScanLine.size(); i++)
        {
            p1 = i;
            p2 = (i + 1) % qScanLine.size(); // Zapewnienie działania dla ostatniego punktu

            // Upewnij się, że p1 ma mniejszą wartość y niż p2
            if (qScanLine[p1].y() > qScanLine[p2].y())
                std::swap(p1, p2);

            // Jeśli y mieści się pomiędzy wartościami  p1 i p2 oraz wartości  p1 i p2 są różne
            if (y >= qScanLine[p1].y() && y < qScanLine[p2].y() && qScanLine[p1].y() != qScanLine[p2].y())
            {
                // Oblicz współrzędną x "twierdzenie z prezentacji"
                int xValue = qScanLine[p1].x() + (y - qScanLine[p1].y()) * (qScanLine[p2].x() - qScanLine[p1].x()) / (qScanLine[p2].y() - qScanLine[p1].y());
                x.push_back(xValue);
            }
        }

        std::sort(x.begin(), x.end()); // Posortuj współrzędne x

        // Narysuj odcinki poziome między parami współrzędnych x
        for (int i = 0; i < x.size() - 1; i += 2)
        {
            drawLine2(x[i], y, x[i + 1], y, color);
        }

        x.clear(); // Wyczyść wektor x
    }
}


//RGB i HSV
/*
 Zakłada się, że alfa jest wartością od 0 do 6, która reprezentuje sześć sektorów w okręgu barw (od 0 do 60 stopni).
 Warunki alfa >= 0 i alfa <= 1 odnoszą się do pierwszego sektora.
 Każdy warunek sprawdza, w którym sektorze znajduje się alfa i na tej podstawie przypisuje odpowiednie wartości składowych koloru.
 Na przykład, jeśli alfa jest w przedziale od 0 do 1, oznacza to, że jesteśmy w pierwszym sektorze,
 więc wartości składowych koloru są przypisywane zgodnie z tym sektorem. Podobnie, dla każdego kolejnego warunku,
 odpowiednie wartości składowych koloru są przypisywane w zależności od sektora, w którym znajduje się alfa.
*/

void Linia::barwy()
{
    //Zmienne rgb
    float R,G,B;
    //Zmienne HSV
    float S,V,C,X,alfa;

    if(Red)
    {
        for(int y = 0;y<im.height();y++)                     //mniejsze od wysokosci obrazu
        {
            //green  = y%255;
            /*
            oblicza wartość składowej green na podstawie wartości y i wysokości obrazu.
            Dzielenie przez im.height() zmienia wartość do zakresu od 0 do 255, co odpowiada składowej koloru.
            */
            //green = y/im.height();
            green = (y*255)/im.height();                    // dzielic przez height i *255 na nic nie rzutowac w reszcie to samo
            for(int x = 0;x<im.width();x++)
            {
                //blue = x%255;
            /*
            oblicza wartość składowej blue na podstawie wartości x i szerokości obrazu (im.width()).
            Dzielenie przez im.width() normalizuje wartość do zakresu od 0 do 255.
            */
            //    blue = x/im.width();
                blue = (x*255)/im.width();                 //dzielic przez width i * 255 na nic nie rzutowac w reszcie to samo
                drawPixel2(x,y,red,green,blue);
            }
        }
        Red = false;
    }
    else if(Green)
    {
        for(int y = 0;y<im.height();y++)                //mniejsze od wysokosci obrazu
        {
            //red = y%255
            red = (y*255)/im.height();
            for(int x = 0;x<im.width();x++)
            {
                //blue = y%255
                blue = (x*255)/im.width();
                drawPixel2(x,y,red,green,blue);
            }
        }
        Green = false;
    }
    else if(Blue)
    {
        for(int y = 0;y<im.height();y++)                //mniejsze od wysokosci obrazu
        {
            //red = y%255
            red = (y*255)/im.height();
            for(int x = 0;x<im.width();x++)
            {

                green = (x*255)/im.width();
                drawPixel2(x,y,red,green,blue);
            }
        }
        Blue= false;
    }

    else if(Hue||Saturation||Value)
    {
        for(int y = 0;y<im.height();y++)                //mniejsze od wysokosci obrazu
        {
            for(int x = 0;x<im.width();x++)
            {
                if(Hue) //odcień
                {
                 S = (float)x/(im.width()-1);           //Oblicza wartość nasycenia (S) na podstawie pozycji piksela w poziomie (x) i szerokości obrazu.
                 V = (float)y/(im.height()-1);          //Oblicza wartość jasności (V) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
                 C = S*V;                               //Oblicza wartość chrominancji (C) na podstawie wartości nasycenia (S) i jasności
                                                        //Chrominacja odnosi się do procesu dodawania koloru do obrazu lub sygnału wideo w celu wzbogacenia jego jakości wizualnej.
                 alfa = hue/60.0f;                      //Przelicza wartość odcienia (hue) na przedział od 0 do 6, reprezentujący sześć sektorów w okręgu barw (od 0 do 60 stopni).
                 X = C * (1-fabs(fmod(alfa,2.0f)-1));   //Wartość X jest wykorzystywana później do obliczenia składowych koloru (R, G i B) w zależności od sektora barwnego, w którym znajduje się alfa.
                                                        //Wartość pomocnicza X jest istotna, ponieważ umożliwia precyzyjne obliczenie składowych koloru na podstawie odcienia i nasycenia (lub innych właściwości barwnych).
                }
                if(Saturation)//nasycenie
                {
                 S = (float)saturation/255;                 //Przeskalowuje wartość nasycenia (saturation) z zakresu od 0 do 255 na zakres od 0 do 1.
                 V = (float)y / (im.height()-1);            //Oblicza wartość jasności (V) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
                 C = S*V;
                 alfa = ((float)x / (im.width()-1))*6;      //Przelicza wartość odcienia (alfa) na przedział od 0 do 6, reprezentujący sześć sektorów w okręgu barw.
                 X = C * (1-fabs(fmod(alfa,2.0f)-1));
                                                            //fabs - zwraca wartość bezwzględną (wartość bez znaku) liczby zmiennoprzecinkowej.
                                                            //fmod - zwraca resztę z dzielenia dwóch liczb zmiennoprzecinkowych.
                }
                if(Value) //jasność
                {
                 S = (float)y/(im.height()-1);              //Oblicza wartość nasycenia (S) na podstawie pozycji piksela w pionie (y) i wysokości obrazu.
                 V = (float)value/255;                      //Przeskalowuje wartość jasności (value) z zakresu od 0 do 255 na zakres od 0 do 1.
                 C = S*V;
                 alfa = ((float)x / (im.width()-1))*6;
                 X = C * (1-fabs(fmod(alfa,2.0f)-1));
                }

                if(alfa >=0 && alfa <=1)
                {
                 R = V;
                 G = X + V - C;
                 B = V - C;
                }
                else if(alfa >=1 && alfa <=2)
                {
                 R = X+V-C;
                 G = V;
                 B = V - C;
                }
                else if(alfa >=2 && alfa <=3)
                {
                 R = V-C;
                 G = V;
                 B = X + V - C;
                }
                else if(alfa >=3 && alfa <=4)
                {
                 R = V-C;
                 G = X + V - C;
                 B = V;
                }
                else if(alfa >=4 && alfa <=5)
                {
                 R = X+V-C;
                 G = V - C;
                 B = V;
                }
                else
                {
                 R = V;
                 G = V - C;
                 B = X + V - C;
                }
                drawPixel2(x,y,R*255,G*255,B*255);      //mnożone przez 255 w celu przeskalowania ich z zakresu od 0 do 1
                                                        //(wartości zmiennoprzecinkowe) do zakresu od 0 do 255 (wartości całkowite) chodzi o intensywność koloru.
            }
        }
        Hue = false;
        Saturation = false;
        Value = false;
    }
}
void Linia::_RedSlider(int n)
{
    red = n; //przypisanie wartosci
    Red = true; //zmiana na true że akurat ten suwak zmieniamy
    //Wywolanie funkcji
    barwy();
    update();
}

void Linia::_GreenSlider(int n)
{
    green = n; //przypisanie wartosci
    Green = true; //zmiana na true że akurat ten suwak zmieniamy
    //Wywolanie funkcji
    barwy();
    update();
}

void Linia::_BlueSlider(int n)
{
    blue = n; //przypisanie wartosci
    Blue = true; //zmiana na true że akurat ten suwak zmieniamy
    //Wywolanie funkcji
    barwy();
    update();
}

void Linia::_HueSlider(int n)
{
    hue = n; //przypisanie wartosci
    Hue = true; //zmiana na true że akurat ten suwak zmieniamy
    //Wywolanie funkcji
    barwy();
    update();
}

void Linia::_SaturationSlider(int n)
{
    saturation = n; //przypisanie wartosci
    Saturation = true; //zmiana na true że akurat ten suwak zmieniamy
    //Wywolanie funkcji
    barwy();
    update();
}

void Linia::_ValueSlider(int n)
{
    value = n; //przypisanie wartosci
    Value = true; //zmiana na true że akurat ten suwak zmieniamy
    //Wywolanie funkcji
    barwy();
    update();
}
void Linia::czysc()
{
    im.fill(0);
    update();
}

void Linia::slot_czysc()
{
    czysc();
}

void Linia::slot_b1()
{
    tryb=0;
}
void Linia::slot_b2()
{
    tryb=1;
}
void Linia::slot_b3()
{
    tryb=2;
}
void Linia::slot_b4()
{
    tryb=3;
}
void Linia::slot_b5()
{
    tryb=4;
}

void Linia::slot_b6()
{
    tryb=5;
}

void Linia::slot_b7()
{
    tryb=6;
}

void Linia::slot_b8()
{
    tryb = 7;
}

void Linia::slot_cofnij()
{
    im=im2;
    update();
}

