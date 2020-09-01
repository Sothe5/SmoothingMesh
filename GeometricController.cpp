///////////////////////////////////////////////////
//
//	Hamish Carr
//	February, 2019
//
//	------------------------
//	GeometricController.cpp
//	------------------------
//	
///////////////////////////////////////////////////

#include "GeometricController.h"

// constructor
GeometricController::GeometricController(GeometricSurfaceDirectedEdge *Surface, GeometricWindow *Window)
	: surface(Surface), window(Window)
	{ // constructor
	QObject::connect(	window->smoothnessSlider,	SIGNAL(valueChanged(int)), 
						this,						SLOT(smoothnessSliderChanged(int)));

	QObject::connect(	window->smoothnessSliderIterations,	SIGNAL(valueChanged(int)), 
						this,						SLOT(smoothnessSliderIterationsChanged(int)));

	QObject::connect(	window->smoothnessSwapToNegative,	SIGNAL(clicked()), 
						this,						SLOT(smoothnessSwapToNegative()));
	} // constructor

// slot for responding to slider changes
void GeometricController::smoothnessSliderChanged(int value)
	{ // smoothnessSliderChanged()
		surface->SmoothRough((laplaceOperatorPositive * value)/(float)100,surface->currentSmoothScale);	// smooth the surface by the value of the slider*sign of the Laplacian

		surface->currentSmoothnessDegree = (laplaceOperatorPositive * value)/(float)100;	// update the value of the laplacian for the iteration's slider

		printf("Laplace operator parameter  %f\n", surface->currentSmoothnessDegree);
		window->ResetInterfaceElements();

	} // smoothnessSliderChanged()

void GeometricController::smoothnessSliderIterationsChanged(int value)
	{
		surface->SmoothRough(surface->currentSmoothnessDegree, value);

		surface->currentSmoothScale = value;	// update the value of the iterations for the Laplacian's slider
		printf("iteration  %d\n", surface->currentSmoothScale);
		window->ResetInterfaceElements();
	}

void GeometricController::smoothnessSwapToNegative()	// When the button is pressed it will change the sign of the laplacian operator to make the surface rougher or smoother
{
	if(laplaceOperatorPositive == 1)
		laplaceOperatorPositive = -1;
	else
		laplaceOperatorPositive = 1;
	
	printf("Laplace operator is now %d\n", laplaceOperatorPositive);

	surface->SmoothRough(laplaceOperatorPositive * surface->currentSmoothnessDegree,surface->currentSmoothScale);
	
	window->ResetInterfaceElements();
}