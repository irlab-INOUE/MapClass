# MapClass
## これは何?
移動ロボットで使用する情報と地図情報をセットにして扱う
ファイルフォーマットを提案し，その取り扱いをするためのクラスです．
格子地図を想定しています．

## ファイルフォーマット
拡張子`.map`

```
MAP  # 識別子．最初に必ず入れる
WIDTH  # 地図の幅（格子数） int型
HEIGHT  # 地図の縦（格子数） int型
csize   # 1格子あたりのサイズ（m） double型
channel # 1格子あたりの情報数（チャネル数） int型
ORIGIN_X  # 地図内の原点X方向（格子番号） int型
ORIGIN_Y  # 地図内の原点Y方向（格子番号） int型
<ここからバイナリの地図情報>
```

## 使い方
### 新しく地図を作成する
```cpp
#include "Map.h"

MapClass map;
map.set_WIDTH(640);
map.set_HEIGHT(480);
map.set_csize(0.05);
map.set_channel(4);  
map.set_ORIGIN_X(50);
map.set_ORIGIN_Y(40);

// ここから地図の1ピクセル毎の処理
for (int y = 0; y < map.HEIGHT; y++) {
  for (int x = 0; x < map.WIDTH; x++) {
      uint32_t a = c1 << 24 | c2 << 16 | c3 << 8 | c4;
      map.set_pixel(CH::ch1, x, y, 0x7F);   // 例としてch1に0x7Fを格納している
  }
}
map.show();
std::ofstream fout("log.map", std::ios::binary);
map.output(fout);
fout.close();
```

### 既存の画像（地図）から読み込む
```cpp
MapClass map;
cv::Mat img = cv::imread("sample_map/occMap.png");
map.img2map(img, 0.025, 4, 132, 372);
```

### 既存の地図ファイル（.mapファイル）を読み込む
```cpp
MapClass map;
map.read_map("log.map");
map.show();
```

### コンパイル
```bash
mkdir build
cd build
cmake ..
make
```
