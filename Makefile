all:
  @g++ plotter.cpp -lvga -lvgagl -o graphplotter
install:
	cp graphplotter /bin/ 