all:
  @g++ Plotter.cpp -lvga -lvgagl -o graphplotter
install:
	cp graphplotter /bin/ 
