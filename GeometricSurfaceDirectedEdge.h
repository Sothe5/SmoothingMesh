///////////////////////////////////////////////////
//
//	Hamish Carr
//	January, 2018
//
//	------------------------
//	GeometricSurfaceDirectedEdge.h
//	------------------------
//	
//	Base code for geometric assignments.
//
//	This is the minimalistic Face-based D/S for storing
//	surfaces, to be used as the basis for fuller versions
//	
//	It will include object load / save code & render code
//	
///////////////////////////////////////////////////

#ifndef _GEOMETRIC_SURFACE_DIRECTED_EDGE_H
#define _GEOMETRIC_SURFACE_DIRECTED_EDGE_H

#include <vector>

// an index type - signed so we can use negative numbers as flags
typedef signed long indexType;

// define a macro for "not used" flag
#define NO_SUCH_ELEMENT -1

#include "Cartesian3.h"

class GeometricSurfaceDirectedEdge
	{ // class GeometricSurfaceDirectedEdge
	public:
	// the vertex positions
	std::vector<Cartesian3> position;
	// the "first" directed edge for each vertex
	std::vector<indexType> firstDirectedEdge;
	// the face vertices - doubles as the "to" array for edges
	std::vector<indexType> faceVertices;
	// the other half of the directed edges
	std::vector<indexType> otherHalf;

	// array to hold the normals
	std::vector<Cartesian3> normal;

	// bounding sphere size
	float boundingSphereSize;

	// midpoint of object
	Cartesian3 midPoint;

	// constructor will initialise to safe values
	GeometricSurfaceDirectedEdge();
		
	// read routine returns true on success, failure otherwise
	// does *NOT* check consistency
	bool ReadFileDirEdge(char *fileName);

	// write routine
	bool WriteFileDirEdge(char *fileName);
	
	// routine to render
	void Render();
	
	// debug routine to dump arrays
	void DumpArrays();

	
	void setUpSmooth();

	void SmoothRough(float smoothnessDegree, int smoothScale);

	std::vector<indexType> getNeighbours(indexType i);
	indexType get1RingSize(indexType vertexId);

	int currentSmoothScale = 0;
	float currentSmoothnessDegree = 0;
private:
	std::vector<Cartesian3> originalPos;

	}; // class GeometricSurfaceDirectedEdge

#endif