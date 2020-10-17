#include "FenTaille.h"


int FenTaille::longueur = 1000;
int FenTaille::hauteur = 1000;

FenTaille::FenTaille(Canevas *canevas) : QWidget()
{

    QVBoxLayout *layout = new QVBoxLayout(this);
    longueurLine = new QLineEdit;
    hauteurLine = new QLineEdit;
    QFormLayout *donne = new QFormLayout;

    donne->addRow("Ingrese longitud (x)",longueurLine);
    donne->addRow("Ingrese altura (y)",hauteurLine);


    creer = new QPushButton("Crear");
    layout->addLayout(donne);
    layout->addWidget(creer);
    connect(creer,SIGNAL(clicked(bool)),canevas,SLOT(nouveauCanevas()));
    connect(longueurLine,SIGNAL(textChanged(QString)),this,SLOT(getLongueurLine(QString)));
    connect(hauteurLine,SIGNAL(textChanged(QString)),this,SLOT(getHauteurLine(QString)));

    connect(creer,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void FenTaille::creerClick()
{

    this->show();

}
//ranuras del programa
void FenTaille::getLongueurLine(QString lLine)
{
    longueur = lLine.toInt();
}
void FenTaille::getHauteurLine(QString hLine)
{
    hauteur = hLine.toInt();
}

//funciones
int FenTaille::getLongueur()
{
    return longueur;
}

int FenTaille::getHauteur()
{
    return hauteur;
}
