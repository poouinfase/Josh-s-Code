#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <stdio.h>

inline uint64_t ROTR(int64_t v, int n) { return (v >> n) | (v << (64 - n)); }
inline uint64_t CH(int64_t e, int64_t f, int64_t g) {
  return (e & f) ^ (~e & g);
}
inline uint64_t MAJ(int64_t a, int64_t b, int64_t c) {
  return (a & b) ^ (a & c) ^ (b & c);
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
    uint64_t *data64 = (uint64_t *)data;
    return __builtin_bswap64(data64[ind]);
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
    putchar('\n');
  }
};

class Sha512ByteArray : public WordArray {
protected:
  uint64_t H[8] = {0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b,
                   0xa54ff53a5f1d36f1, 0x510e527fade682d1, 0x9b05688c2b3e6c1f,
                   0x1f83d9abfb41bd6b, 0x5be0cd19137e2179};
  const uint64_t K[80] = {
      0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
      0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
      0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
      0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
      0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
      0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
      0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
      0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
      0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
      0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
      0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
      0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
      0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
      0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
      0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
      0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
      0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
      0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
      0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
      0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
      0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
      0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
      0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
      0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
      0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
      0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
      0x5fcb6fab3ad6faec, 0x6c44198c4a475817};

public:
  Sha512ByteArray(int le) : WordArray(le) {}

  std::string transform() {
    uint64_t TMP[80];
    for (int c = 0; c < 80; c++) {
      TMP[c] = 0x00;
    }
    for (int c = 0; c < len / 128; c++) {
      for (int i = 0; i < 16; i++)
        TMP[i] = get64Bits(i + 16 * c);
    }

    uint64_t V[8];
    memcpy(V, H, sizeof(uint64_t) * 8);

    for (int c = 16; c < 80; c++) {
      uint64_t s0 =
          ROTR(TMP[c - 15], 1) ^ ROTR(TMP[c - 15], 8) ^ (TMP[c - 15] >> 7);

      uint64_t s1 =
          ROTR(TMP[c - 2], 19) ^ ROTR(TMP[c - 2], 61) ^ (TMP[c - 2] >> 6);

      TMP[c] = TMP[c - 16] + s0 + TMP[c - 7] + s1;
    }
    for (int c = 0; c < 80; c++) {
      uint64_t S0 = ROTR(V[0], 28) ^ ROTR(V[0], 34) ^ ROTR(V[0], 39);

      uint64_t temp2 = S0 + MAJ(V[0], V[1], V[2]);

      uint64_t S1 = ROTR(V[4], 14) ^ ROTR(V[4], 18) ^ ROTR(V[4], 41);

      uint64_t temp1 = V[7] + S1 + CH(V[4], V[5], V[6]) + K[c] + TMP[c];

      V[7] = V[6];
      V[6] = V[5];
      V[5] = V[4];
      V[4] = V[3] + temp1;
      V[3] = V[2];
      V[2] = V[1];
      V[1] = V[0];
      V[0] = temp1 + temp2;
    }
    for (int c = 0; c < 8; c++) {
      H[c] += V[c];
    }
    std::stringstream strout;
    for (int c = 0; c < 8; c++) {
      strout << std::setfill('0') << std::setw(16) << std::hex << (H[c] | 0);
    }
    return strout.str();
  }
};

class Sha512 {
protected:
  Sha512ByteArray *ByteArray;
  __uint128_t le;
  __uint128_t padding;
  __uint128_t blockBytesLen;

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
  }

  void out() {
    ByteArray->print();
    std::string hash = ByteArray->transform();
    std::cout << "HASH: " << hash << std::endl;
  }

  ~Sha512() { delete ByteArray; }
};
int main() { Sha512(std::string("HELLO")).out(); }
