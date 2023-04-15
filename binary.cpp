#include <iostream>
#include <fstream>
int main(int argc, char *argv[]) {
  std::ofstream fout("test.txt", std::ios::binary);
  uint32_t a = 0x778899AA;
  uint32_t b = 0xBBCCDDEE;
  //fout << a;
  fout.write(reinterpret_cast<char*>(&a), sizeof(a));
  fout.write(reinterpret_cast<char*>(&b), sizeof(b));
  fout.close();

  std::ifstream fin("test.txt", std::ios::binary);
  if (!fin) {
    std::cerr << "ファイルオープンに失敗" << "\n";
    return EXIT_FAILURE;
  }
  uint32_t d;
  fin.read((char*)&d, sizeof(d));
  std::cout << std::hex << d << "\n";
  std::cout << std::hex << (d >> 24 & 0x00FF) << "\n";
  std::cout << std::hex << (d >> 16 & 0x00FF) << "\n";
  std::cout << std::hex << (d >>  8 & 0x00FF) << "\n";
  std::cout << std::hex << (d       & 0x00FF) << "\n";
  fin.read((char*)&d, sizeof(d));
  std::cout << std::hex << d << "\n";
  std::cout << std::hex << (d >> 24 & 0x00FF) << "\n";
  std::cout << std::hex << (d >> 16 & 0x00FF) << "\n";
  std::cout << std::hex << (d >>  8 & 0x00FF) << "\n";
  std::cout << std::hex << (d       & 0x00FF) << "\n";
  return 0;
}
