
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ustawienie przyciskow

    // Połączenie sygnału valueChanged() z suwaka Suwak2 z slotem setN() w obiekcie widget
    connect(ui->Suwak2, SIGNAL(valueChanged(int)), ui->widget, SLOT(setN(int)));

    // Połączenie sygnału valueChanged() z spinBoxa z slotem setN() w obiekcie widget
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->widget, SLOT(setN(int)));

    // Połączenie sygnału valueChanged() z suwaka Suwak2 z metodą setValue() w obiekcie spinBox
    connect(ui->Suwak2,  &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

    // Połączenie sygnału valueChanged() z spinBoxa z metodą setValue() w obiekcie Suwak2
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), ui->Suwak2, &QSlider::setValue);

    //Suwaki do RGB i HSV

    //RED
    connect(ui->RedSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(_RedSlider(int)));
    connect(ui->RedSpin, SIGNAL(valueChanged(int)), ui->widget, SLOT(_RedSlider(int)));
    connect(ui->RedSlider,  &QSlider::valueChanged, ui->RedSpin, &QSpinBox::setValue);
    connect(ui->RedSpin, QOverload<int>::of(&QSpinBox::valueChanged), ui->RedSlider, &QSlider::setValue);

    //GREEN
    connect(ui->GreenSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(_GreenSlider(int)));
    connect(ui->GreenSpin, SIGNAL(valueChanged(int)), ui->widget, SLOT(_GreenSlider(int)));
    connect(ui->GreenSlider,  &QSlider::valueChanged, ui->GreenSpin, &QSpinBox::setValue);
    connect(ui->GreenSpin, QOverload<int>::of(&QSpinBox::valueChanged), ui->GreenSlider, &QSlider::setValue);

    //BLUE
    connect(ui->BlueSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(_BlueSlider(int)));
    connect(ui->BlueSpin, SIGNAL(valueChanged(int)), ui->widget, SLOT(_BlueSlider(int)));
    connect(ui->BlueSlider,  &QSlider::valueChanged, ui->BlueSpin, &QSpinBox::setValue);
    connect(ui->BlueSpin, QOverload<int>::of(&QSpinBox::valueChanged), ui->BlueSlider, &QSlider::setValue);

    //HUE
    connect(ui->HueSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(_HueSlider(int)));
    connect(ui->HueSpin, SIGNAL(valueChanged(int)), ui->widget, SLOT(_HueSlider(int)));
    connect(ui->HueSlider,  &QSlider::valueChanged, ui->HueSpin, &QSpinBox::setValue);
    connect(ui->HueSpin, QOverload<int>::of(&QSpinBox::valueChanged), ui->HueSlider, &QSlider::setValue);

    //SATURATION
    connect(ui->SaturationSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(_SaturationSlider(int)));
    connect(ui->SaturationSpin, SIGNAL(valueChanged(int)), ui->widget, SLOT(_SaturationSlider(int)));
    connect(ui->SaturationSlider,  &QSlider::valueChanged, ui->SaturationSpin, &QSpinBox::setValue);
    connect(ui->SaturationSpin, QOverload<int>::of(&QSpinBox::valueChanged), ui->SaturationSlider, &QSlider::setValue);

    //VALUE
    connect(ui->ValueSlider,SIGNAL(valueChanged(int)),ui->widget,SLOT(_ValueSlider(int)));
    connect(ui->ValueSpin, SIGNAL(valueChanged(int)), ui->widget, SLOT(_ValueSlider(int)));
    connect(ui->ValueSlider,  &QSlider::valueChanged, ui->ValueSpin, &QSpinBox::setValue);
    connect(ui->ValueSpin, QOverload<int>::of(&QSpinBox::valueChanged), ui->ValueSlider, &QSlider::setValue);

    //spinbox wyglad
    ui->spinBox->setStyleSheet("background-color: white; color:black; font-weight: bold; border: 2px solid black;");

    //pixel + wyglad
    connect(ui->b1,SIGNAL(clicked()),ui->widget,SLOT(slot_b1()));
    ui->b1->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");
    connect(ui->b2,SIGNAL(clicked()),ui->widget,SLOT(slot_b2()));

    //linia + wyglad
    ui->b2->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");
    connect(ui->b3,SIGNAL(clicked()),ui->widget,SLOT(slot_b3()));

    //kolo + wyglad
    ui->b3->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    //elipsa + wyglad
    connect(ui->b4,SIGNAL(clicked()),ui->widget,SLOT(slot_b4()));
    ui->b4->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    //Bezier
    connect(ui->b5,SIGNAL(clicked()),ui->widget,SLOT(slot_b5()));
    ui->b5->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");
    //BSpline
    connect(ui->b6,SIGNAL(clicked()),ui->widget,SLOT(slot_b6()));
    ui->b6->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    //FloodFill
    connect(ui->b7,SIGNAL(clicked()),ui->widget,SLOT(slot_b7()));
    ui->b7->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    //ScanLine
    connect(ui->b8,SIGNAL(clicked()),ui->widget,SLOT(slot_b8()));
    ui->b8->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                           QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    //cofniecie + wyglad
    connect(ui->cofnij,SIGNAL(clicked()),ui->widget,SLOT(slot_cofnij()));
    ui->cofnij->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black;} \
                               QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    //czyszczenie + wyglad
    connect(ui->czysc,SIGNAL(clicked()),ui->widget,SLOT(slot_czysc()));
    ui->czysc->setStyleSheet("QPushButton { background-color: white; font-weight: bold; border: 2px solid black; } \
                              QPushButton:hover { background-color: rgba(255, 255, 255, 0.4);}");

    //ustawienie zakresu
    ui->Suwak2->setRange(0, 360);
    ui->spinBox->setRange(0, 360);

    //Zakresy dla RGB I HSV

    //Red
    ui->RedSpin->setRange(0,255);
    ui->RedSlider->setRange(0,255);

    //Green
    ui->GreenSpin->setRange(0,255);
    ui->GreenSlider->setRange(0,255);

    //Blue
    ui->BlueSpin->setRange(0,255);
    ui->BlueSlider->setRange(0,255);

    //Hue
    ui->HueSpin->setRange(0,255);
    ui->HueSlider->setRange(0,255);

    //Saturation
    ui->SaturationSpin->setRange(0,255);
    ui->SaturationSlider->setRange(0,255);

    //Value
    ui->ValueSpin->setRange(0,255);
    ui->ValueSlider->setRange(0,255);

    //wartosc poczatkowa spinBox
    ui->spinBox->setValue(10);

    //Wartosc poczatkowa RGB I HSV

    //RED
    ui->RedSpin->setValue(0);

    //GREEN
    ui->GreenSpin->setValue(0);

    //BLUE
    ui->BlueSpin->setValue(0);

    //HUE
    ui->HueSpin->setValue(0);

    //SATURATION
    ui->SaturationSpin->setValue(0);

    //VALUE
    ui->ValueSpin->setValue(0);


    //wysrodkowanie tekstu w label label_2 label_3
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);

    //wyglad label label_2 label_3
    ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0.7); color: black; font-weight: bold; border: 1px solid black;");
    ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0.7); color: black; font-weight: bold; border: 1px solid black;");
    ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0.7); color: black; font-weight: bold; border: 1px solid black;");
}

MainWindow::~MainWindow()
{
    delete ui;
}



