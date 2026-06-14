#include <spdlog/sinks/ostream_sink.h>
#include <spdlog/spdlog.h>

#include <iostream>

int main(void) {
  // Route spdlog to stderr so it doesn't pollute PPM stdout
  auto stderr_sink =
      std::make_shared<spdlog::sinks::ostream_sink_mt>(std::cerr);
  auto logger = std::make_shared<spdlog::logger>("console", stderr_sink);
  spdlog::set_default_logger(logger);

  // Image settings
  int image_height = 256;
  int image_width = 256;

  spdlog::info("Saving image to ./image.ppm");
  spdlog::info("Image size: {}px x {}px", image_width, image_height);

  // Rendering
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      int ir = int(255.999 * r);
      int ig = int(255.999 * g);
      int ib = int(255.999 * b);

      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
  std::clog << "\r                      \r";

  spdlog::info("Done.");
  return 0;
}