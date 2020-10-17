#include "FenPrincipale.h"
#include "Canevas.h"
#include "FenTaille.h"

FenPrincipale::FenPrincipale()
{
    resize(500,500);
    //variables iniciales
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    traitEnable = 0;
    valeurSlider = 1;


    Canevas *canevas = new Canevas(this);
    FenTaille *fenetretaille = new FenTaille(canevas);
    setCentralWidget(canevas);

    //Archivos
    QMenu *menuFichier = menuBar()->addMenu("Archivos");

    QAction *actionNouveau = new QAction("nuevo",this);
    menuFichier->addAction(actionNouveau);
    QAction *actionSauvegarder = new QAction("Guardar",this);
    menuFichier->addAction(actionSauvegarder);
    QAction *actionOuvrir = new QAction("Abrir",this);
    menuFichier->addAction(actionOuvrir);

    connect(actionNouveau,SIGNAL(triggered(bool)),fenetretaille,SLOT(creerClick()));
    connect(actionSauvegarder,SIGNAL(triggered(bool)),canevas,SLOT(sauvegarderCanevas()));
    connect(actionOuvrir,SIGNAL(triggered(bool)),canevas,SLOT(ouvrirCanevas()));

    //Menu
    QMenu *menuForme = menuBar()->addMenu("&Herramientas de dibujo");

    QAction *actionDraw = new QAction("Lapiz",this);
    menuForme->addAction(actionDraw);
    QAction *actionRectangle = new QAction("Rectangulo",this);
    menuForme->addAction(actionRectangle);
    QAction *actionCercle = new QAction("Circulo",this);
    menuForme->addAction(actionCercle);
    QAction *actionTrait = new QAction("Linea",this);
    menuForme->addAction(actionTrait);


    connect(actionDraw,SIGNAL(triggered(bool)),this,SLOT(slotDraw()));
    connect(actionRectangle,SIGNAL(triggered(bool)),this,SLOT(slotRectangle()));
    connect(actionCercle,SIGNAL(triggered(bool)),this,SLOT(slotCercle()));
    connect(actionTrait,SIGNAL(triggered(bool)),this,SLOT(slotTrait()));

    //Menu
    QMenu *menuOutils = menuBar()->addMenu("Herramientas");

    QAction *actionRemplir = new QAction("Pintura",this);
    menuOutils->addAction(actionRemplir);
    QAction *actionRetour = new QAction("Retroceder",this);
    actionRetour->setShortcut(QKeySequence("Ctrl+Z"));
    menuOutils->addAction(actionRetour);

    connect(actionRemplir,SIGNAL(triggered(bool)),this,SLOT(slotRemplir()));
    connect(actionRetour,SIGNAL(triggered(bool)),canevas,SLOT(retourCanevas()));
    //Colores
    QToolBar *toolBar = addToolBar("Color");

    QPushButton *boutonCouleur = new QPushButton;
    boutonCouleur->setText("Color");
    couleurDialogue = new QColorDialog;
    toolBar->addWidget(boutonCouleur);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(1,15);
    toolBar->addWidget(slider);

    connect(boutonCouleur,SIGNAL(clicked(bool)),this,SLOT(slotCouleur()));
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(slotSlider(int)));
}
//Acciones

bool FenPrincipale::getDrawEnable()
{
    return drawEnable;
}
bool FenPrincipale::getRectangleEnable()
{
    return rectangleEnable;
}
bool FenPrincipale::getCercleEnable()
{
    return cercleEnable;
}
bool FenPrincipale::getTraitEnable()
{
    return traitEnable;
}

bool FenPrincipale::getRemplirEnable()
{
    return remplirEnable;
}

QColor FenPrincipale::getCouleur()
{
    return couleur;
}
int FenPrincipale::getVeleurSlider()
{
    return valeurSlider;
}


void FenPrincipale::slotDraw()
{
    drawEnable = 1;
    rectangleEnable = 0;
    cercleEnable = 0;
    remplirEnable = 0;
    traitEnable = 0;
}
void FenPrincipale::slotRectangle()
{
    drawEnable = 0;
    rectangleEnable = 1;
    cercleEnable = 0;
    remplirEnable = 0;
    traitEnable = 0;
}
void FenPrincipale::slotCercle()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 1;
    remplirEnable = 0;
    traitEnable = 0;
}
void FenPrincipale::slotRemplir()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    remplirEnable = 1;
    traitEnable = 0;
}

void FenPrincipale::slotTrait()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    remplirEnable = 0;
    traitEnable = 1;
}

void FenPrincipale::slotCouleur()
{
    couleur = couleurDialogue->getColor();
}

void FenPrincipale::slotSlider(int x)
{
    valeurSlider = x;
}


