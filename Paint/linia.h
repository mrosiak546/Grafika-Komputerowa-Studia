
#ifndef LINIA_H
#define LINIA_H


#include <QPushButton>
#include <QWidget>
#include <QQueue>
#include <QStack>


class Linia : public QWidget
{
    Q_OBJECT
public:
    explicit Linia(QWidget *parent = nullptr);
    int n;
    int tryb=0;
protected:
    void paintEvent(QPaintEvent *);
    //Rysowanie Pixela
    void drawPixel(int x,int y,int r,int g,int b);
    void drawPixel2(int x,int y,int r,int g,int b);
    //Rysowanie myszka
    void mousePressEvent(QMouseEvent *); //Nie potrzebne do rysowania pikselem
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    //Rysowanie Linii
    void drawLine(int x1,int y1,int x2,int y2);
    void drawLine2(int x1, int y1, int x2, int y2, const QColor& color);
    //void drawLine2(double x1, double y1, double x2, double y2, const QColor& color);
    //void drawLine(int x1, int y1, int x2, int y2, QColor Kolor);
    //Rysowanie kola
    void drawCircle(int x, int y, int r);
    void drawCircle2(int x0, int y0,int x1,int y1);
    //Rysowanie Elipsy
    void drawEllipse(int x, int y, int e,int f,int n);
    //Bezier
    void drawBezier();
    void drawPoints();
    int findPoints();
    void replacePoint(int i);
    //BSpline
    void drawBSpline();
    //floodFill
    void flood_fill (int x0, int y0, QRgb rgb);
    //scanLine
    void scanLine(const QColor& color);
    //RGB I HSV
    void barwy();
    //czyszczenie
    void czysc();
    void chooseColor();
private:
    QImage im, im2, im3;
    QPushButton *b1;
    QPoint startPos,endPos;
    QQueue<QPoint> qBezier , qBSline,qScanLine;
    QStack<QPoint> stack;
    QColor chosenColor;
    int pom;
    //Zmienne rgb i hsv
    bool Red = false;
    bool Green = false;
    bool Blue = false;
    bool Hue = false;
    bool Saturation = false;
    bool Value = false;
    int red = 0;
    int green = 0;
    int blue = 0;
    int hue = 0;
    int saturation = 0;
    int value = 0;
public slots:
    void slot_czysc();
    void slot_b1();
    void slot_b2();
    void slot_b3();
    void slot_b4();
    void slot_b5();
    void slot_b6();
    void slot_b7();
    void slot_b8();
    void slot_cofnij();
    void setN(int value);

    //Funkcje do kolorów
    void _RedSlider(int n);
    void _GreenSlider(int n);
    void _BlueSlider(int n);
    void _HueSlider(int n);
    void _SaturationSlider(int n);
    void _ValueSlider(int n);
signals:

};

#endif // LINIA_H
