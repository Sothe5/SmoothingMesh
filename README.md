# SmoothingMesh

### Most of this code does not belong to me. It belongs to Dr.Hamish Carr lecturer at the University of Leed which gave us this files as templates.

Our task was to modify them to be able to have a final application to do the following: when moving an slider made with QT which indicates
how smooth the final mesh should be. We implemented the code behind the slider to modify the mesh by moving the vertices in the direction of their laplacian opertator.

My personal code are the functions setUpSmooth(), SmoothRough(), get1RingSize(), getNeighbours(). All of them are in the file GeometricSurfaceDirectedEdge.cpp

Also, I modified the file GeometricController.cpp to be able to implement the smoothness of the vertices depending on the values of the slider and a second slider to indicate
how many iterations should be done using that laplacian value.

# To Compile:

For linux machines download and install QT and execute ./compile.sh it is a file I created to execute all the commands to compile

To execute the compiled files use: ./nameFolder ./diredgenormals/fileName.diredgenormal

# Results

Initial Model:

<img src="/InitialSmooth.jpg" width="300" height="300">

Slightly Smoothed:

<img src="/SlightlySmooth.jpg" width="300" height="300">

Very Smoothed:

<img src="/VerySmooth.jpg" width="300" height="300">
