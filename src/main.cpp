#include <iostream>

int main() {
	
	// Image settings
	int imWidth = 1000;
	int imHeight = 1000;

	// Rendering
	std::cout << "P3\n" << imWidth << ' ' << imHeight << "\n255\n";

  for ( int j = 0; j < imHeight; j++ ) {
    std::clog << "\rScanlines remaining: " << ( imHeight - j ) << ' ' << std::flush;
    for ( int i = 0; i < imWidth; i++ ) {
      auto r = double( i ) / ( imWidth - 1 );
      auto g = double( j ) / ( imHeight - 1 );
      auto b = 0.0;

      int ir = int( 255.999 * r );
      int ig = int( 255.999 * g );
      int ib = int( 255.999 * b );

      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
  std::clog << "\rDone.                 \n" << std::flush;
}