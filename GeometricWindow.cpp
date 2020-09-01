///////////////////////////////////////////////////
//
//	Hamish Carr
//	February, 2019
//
//	------------------------
//	GeometricWindow.cpp
//	------------------------
//	
//	The main window for our little geometric application
//	
///////////////////////////////////////////////////

#include "GeometricWindow.h"
	
// constructor
GeometricWindow::GeometricWindow(GeometricSurfaceDirectedEdge *newSurface, QWidget *parent)
	: QWidget(parent), surface(newSurface)
	{ // GeometricWindow constructor
	setWindowTitle(QString("COMP5821M Assignment 2"));

	// create a layout
	windowLayout = new QGridLayout(this);

	// a label for the slider
	smoothnessLabel = new QLabel("Laplace operator ", this);
	smoothnessLabelIterations = new QLabel("Number of iterations ", this);
	// and a slider for controlling the computation
	smoothnessSlider = new QSlider(Qt::Horizontal, this);

	smoothnessSliderIterations = new QSlider(Qt::Horizontal, this);

	//	create the geometric widget
	geometricWidget = new GeometricWidget(surface, this);

	smoothnessSwapToNegative = new QPushButton("Swap to negative/positive Laplace operator", this);

	// add the widgets to the layout
	windowLayout->addWidget(geometricWidget, 0, 0, 1, 1);
	windowLayout->setRowStretch(0, 1);
	windowLayout->addWidget(smoothnessLabel, 1, 0, 1, 1);
	windowLayout->addWidget(smoothnessSlider, 2, 0, 1, 1);
	windowLayout->addWidget(smoothnessLabelIterations, 3, 0, 1, 1);
	windowLayout->addWidget(smoothnessSliderIterations, 4, 0, 1, 1);
	windowLayout->addWidget(smoothnessSwapToNegative, 5, 0, 1, 1);
	} // GeometricWindow constructor

// destructor
GeometricWindow::~GeometricWindow()
	{ // GeometricWindow destructor
	delete smoothnessSliderIterations;
	delete smoothnessSlider;
	delete smoothnessLabel;
	delete smoothnessLabelIterations;
	delete geometricWidget;
	delete smoothnessSwapToNegative;
	} // GeometricWindow destructor

// routine to force interface refresh
void GeometricWindow::ResetInterfaceElements()
	{ // ResetInterfaceElements()
	geometricWidget->update();
	smoothnessLabel->update();
	smoothnessLabelIterations->update();
	smoothnessSlider->update();
	smoothnessSliderIterations->update();
	smoothnessSwapToNegative->update();
	} // ResetInterfaceElements()
