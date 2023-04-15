#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <vector>

enum class CH : uint8_t {
  ch1,
  ch2,
  ch3,
  ch4,
};

class MapClass {
private:
  double csize;
  int channel;   // 0:占有値 1:作業1 2:作業2 3:作業3 
  int ORIGIN_X;
  int ORIGIN_Y;
  std::vector<uint32_t> map;

public:
  int WIDTH;
  int HEIGHT;

  MapClass() {};
  void set_WIDTH(int val) {WIDTH = val;};
  void set_HEIGHT(int val) {HEIGHT = val;};
  void set_csize(double val) {csize = val;};
  void set_channel(int val) {channel = val;};
  void set_ORIGIN_X(int val) {ORIGIN_X = val;};
  void set_ORIGIN_Y(int val) {ORIGIN_Y = val;};
  //void set_map(uint32_t val) {map.emplace_back(val);};
  void set_pixel(CH channel, int x, int y, uint8_t val);

  void output(std::ofstream &fout);
  void read_map(std::string fname);
  void show();
  cv::Mat map2img(); // ch1 をcv::Mat に変換する（グレースケール画像）
  void img2map(cv::Mat &img, double csize, int channel, int ORIGIN_X, int ORIGIN_Y);
};

