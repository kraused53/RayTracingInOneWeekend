#include <iostream>
#include "vec3.h"
#include "color.h"
int main() {
	
	// Image settings
	int imWidth = 256;
	int imHeight = 256;

	// Rendering
	std::cout << "P3\n" << imWidth << ' ' << imHeight << "\n255\n";

  for ( int j = 0; j < imHeight; j++ ) {
    std::clog << "\rScanlines remaining: " << ( imHeight - j ) << ' ' << std::flush;
    for ( int i = 0; i < imWidth; i++ ) {
      auto pixel_color = color(
        double( i ) / ( imWidth - 1 ),
        double( j ) / ( imHeight - 1 ),
        0
      );
      write_color( std::cout, pixel_color );
    }
  }
  std::clog << "\rDone.                 \n" << std::flush;
}