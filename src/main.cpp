#include <iostream>
#include "vec3.h"
#include "ray.h"
#include "color.h"

double hit_sphere( const point3 center, double radius, const ray& r ) {
  vec3 oc = center - r.origin();
  auto a = r.direction().length_squared();
  auto h = dot(r.direction(), oc);
  auto c = oc.length_squared() - radius*radius;
  auto discriminant = h*h - a*c;
  
  if( discriminant < 0 ) {
    return -1.0;
  }

  return (h - std::sqrt(discriminant)) / a;
}

color rayColor( const ray& r ) {
  auto t = hit_sphere( point3( 0, 0, -1 ), 0.5, r ) ;
  if(t > 0.0 ) {
    vec3 N = unit_vector( r.at( t ) - vec3( 0, 0, -1 ) );
    return 0.5 * color( N.x()+1, N.y()+1, N.z()+1 );
  }

  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5*(unit_direction.y() + 1.0);
  return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main() {
	
	// Picture settings
  double aspect_ratio = ( 16.0 ) / 9.0;
  int imWidth = 400;
	int imHeight = int( imWidth / aspect_ratio );
  imHeight = ( imHeight < 1 ) ? 1 : imHeight;

  // Camera
  double focalLength = 1.0;
  double viewHeight = 2.0;
  double viewWidth = viewHeight * ( double( imWidth ) / imHeight );
  point3 cameraCenter = point3( 0.0, 0.0, 0.0 );

  // Viewport
  vec3 viewU = vec3( viewWidth, 0.0, 0.0 );
  vec3 viewV = vec3( 0.0, -viewHeight, 0.0 );

  vec3 pidexlDU = viewU / imWidth;
  vec3 pidexlDV = viewV / imHeight;

  point3 viewUpperLeft = cameraCenter - 
                          vec3( 0, 0, focalLength ) -
                          ( viewU / 2 ) -
                          ( viewV / 2 );

  point3 pixel00_loc = viewUpperLeft + 0.5 * ( pidexlDU + pidexlDV );

	// Rendering
	std::cout << "P3\n" << imWidth << ' ' << imHeight << "\n255\n";

  for ( int j = 0; j < imHeight; j++ ) {
    std::clog << "\rScanlines remaining: " << ( imHeight - j ) << ' ' << std::flush;
    for ( int i = 0; i < imWidth; i++ ) {
      point3 pixelCenter = pixel00_loc + ( i * pidexlDU ) + ( j * pidexlDV );
      vec3 rDir = pixelCenter - cameraCenter;
      ray r( cameraCenter, rDir );
      color pixel_color = rayColor( r );
      write_color( std::cout, pixel_color );
    }
  }
  std::clog << "\rDone.                 \n" << std::flush;
}