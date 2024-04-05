#include <iostream>
#include <stdint.h>
#include <stdio.h>

inline uint64_t ROTR(int64_t v, int n) { return (v >> n) | (v << (64 - n)); }
inline uint64_t CH(int64_t e, int64_t f, int64_t g) {
  return (e & f) ^ (~e & g);
}

class WordArray {
protected:
  __uint128_t len;
  __uint128_t bitlen;
  uint8_t *data;

public:
  WordArray(int le) {
    this->len = le;
    this->bitlen = this->len * 8;
    this->data = (uint8_t *)malloc(len * sizeof(uint8_t));
    for (int i = 0; i < len; i++)
      data[i] = 0;
  }
  ~WordArray() { free(data); }
  uint8_t get1Bit(__uint128_t ind) {
    if (ind > len)
      return -1;
    uint8_t byte = data[ind / 8];
    return byte & (ind % 8);
  }
  uint8_t get1Byte(__uint128_t ind) {
    if (ind > len)
      return -1;
    return data[ind];
  }
  uint64_t get64Bits(__uint128_t ind) {
    if (ind > len / 8)
      return -1;
    int64_t *data64 = (int64_t *)data;
    return data64[ind];
  }
  void set1Bits(__uint128_t ind, uint8_t ele) {
    if (ind > bitlen || ele > 1)
      return;

    if (ele)
      data[ind / 8] |= ele << (ind % 8);
    else
      data[ind / 8] &= ele << (ind % 8);
  }
  void setByte(__uint128_t ind, uint8_t ele) {
    if (ind > len)
      return;
    data[ind] = ele;
  }

  void set64Bits(__uint128_t ind, uint64_t ele) {
    if (ind > len / 8)
      return;
    setByte(ind * 8 + 7, ele & 0xff);
    ele >>= 8;
    setByte(ind * 8 + 6, ele & 0xff);
    ele >>= 8;
    setByte(ind * 8 + 5, ele & 0xff);
    ele >>= 8;
    setByte(ind * 8 + 4, ele & 0xff);
    ele >>= 8;
    setByte(ind * 8 + 3, ele & 0xff);
    ele >>= 8;
    setByte(ind * 8 + 2, ele & 0xff);
    ele >>= 8;
    setByte(ind * 8 + 1, ele & 0xff);
    ele >>= 8;
    setByte(ind * 8 + 0, ele & 0xff);
  }
  void print() {
    for (int i = 0; i < len; i++) {
      if ((i % 8) == 0) {
        printf("\n%d:\t", i);
      }
      printf("%x\t", get1Byte(i));
    }
  }
};

class Sha512ByteArray : public WordArray {
public:
  Sha512ByteArray(int le) : WordArray(le) {}
};

class Sha512 {
protected:
  Sha512ByteArray *ByteArray;
  __uint128_t le;
  __uint128_t padding;
  __uint128_t blockBytesLen;

  uint64_t H[8] = {0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b,
                   0xa54ff53a5f1d36f1, 0x510e527fade682d1, 0x9b05688c2b3e6c1f,
                   0x1f83d9abfb41bd6b, 0x5be0cd19137e2179};

public:
  Sha512(std::string msg) {
    le = msg.length();
    padding = ((1024 - (8 * le) - 128) % 1024) / 8;
    blockBytesLen = padding + le + 16;
    // message + padding 1 + padding 2;

    ByteArray = new Sha512ByteArray(blockBytesLen);
    for (__uint128_t i = 0; i < le; i++) {
      ByteArray->setByte(i, msg.c_str()[i]);
    }
    ByteArray->setByte(le, 1 << 7);

    uint64_t firs = ((le & (((__uint128_t{1} << 64) - 1))));
    uint64_t secn = (le & ~((__uint128_t{1} << 64) - 1)) >> 64;

    ByteArray->set64Bits(((padding + le + 1) >> 3) + 1, firs);
    ByteArray->set64Bits(((padding + le + 1) >> 3) + 2, secn);
    ByteArray->print();
  }

  ~Sha512() { delete ByteArray; }
};
int main() { Sha512(std::string("aasdfjkldsajfsdajlf")); }
