/*
 * 地図ファイルの保存フォーマット
 * 拡張子 .map
 * ファイル内部構造
 *
 * MAP // 識別子．必ずつける
 * WIDTH  // 横のサイズ uint16_t
 * HEIGHT // 縦のサイズ uint16_t
 * csize  // 解像度．double型
 * channel  // 格子に格納するチャネル数
 * ORIGIN_X   // 格子上の原点X
 * ORIGIN_Y   // 格子状の原点Y
 * 以下，格子ごとにchannel分の2バイト値が連続したセットを格納する
 * 00AABBCC 11DDEEFF 20ABCDEF ... // 格納データはスペースで区切らない
 *
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

#include "Map.h"
int main(int argc, char *argv[]) {
  std::ofstream fout("log.map", std::ios::binary);

  MapClass map;

  map.set_WIDTH(640);
  map.set_HEIGHT(480);
  map.set_csize(0.05);
  map.set_channel(4);  // 0:占有値 1:作業1 2:作業2 3:作業3 
  map.set_ORIGIN_X(50);
  map.set_ORIGIN_Y(40);

  // ここから地図の1ピクセル毎の処理
  uint8_t c1 = 0x7F; // =
  uint8_t c2 = 0x00; // >
  uint8_t c3 = 0x00; // ?
  uint8_t c4 = 0x00; // @

  for (int y = 0; y < map.HEIGHT; y++) {
    for (int x = 0; x < map.WIDTH; x++) {
      uint32_t a = c1 << 24 | c2 << 16 | c3 << 8 | c4;
      map.set_pixel(CH::ch1, x, y, c1);
      //map.set_map(a);
      //fout.write(reinterpret_cast<const char*>(&a), sizeof(a));
    }
    //fout << "\n";
  }
  //map.show();
  //map.output(fout);
  //fout.close();

  MapClass map2;
  //map2.read_map("log.map");
  //map2.show();
  //cv::Mat img = map2.map2img();
  //cv::imshow("TEST", img);
  //cv::waitKey();

  MapClass map3;
  cv::Mat img3 = cv::imread("occMap.png");
  map3.img2map(img3, 0.025, 4, 132, 372);
  map3.output(fout);
  fout.close();

  MapClass map4;
  map4.read_map("log.map");
  map4.show();

  return 0;
}
