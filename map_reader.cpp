#include <iostream>
#include "Map.h"

void usage() {
  std::cout
  << "Usage:\n"
  << "\tmap_reader <map_file_name>\n";
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    usage();
    return EXIT_FAILURE;
  }

  MapClass map;
  std::cout << argv[1] << "\n";
  map.read_map(argv[1]);

  map.show_config();
  cv::Mat img = map.map2img();
  cv::circle(img, cv::Point(map.ORIGIN_X, map.ORIGIN_Y),
             0.5/map.csize, cv::Scalar(100, 0, 0), 1, cv::LINE_8);
  cv::line(img, cv::Point(map.ORIGIN_X - 0.5/map.csize, map.ORIGIN_Y),
           cv::Point(map.ORIGIN_X + 0.5/map.csize, map.ORIGIN_Y),
           cv::Scalar(100, 0, 0), 1, cv::LINE_8);
  cv::line(img, cv::Point(map.ORIGIN_X, map.ORIGIN_Y - 0.5/map.csize),
           cv::Point(map.ORIGIN_X, map.ORIGIN_Y + 0.5/map.csize),
           cv::Scalar(100, 0, 0), 1, cv::LINE_8);
  cv::imshow("MAP", img);
  cv::waitKey();
  return EXIT_SUCCESS;
}
