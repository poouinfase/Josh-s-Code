#include <assert.h>
#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <stdio.h>

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
    if (ind >= len)
      return -1;
    uint8_t byte = data[ind / 8];
    return byte & (ind % 8);
  }
  uint8_t get1Byte(__uint128_t ind) {
    if (ind >= len)
      return -1;
    return data[ind];
  }
  uint64_t get64Bits(__uint128_t ind) {
    if (ind >= len / 8)
      return -1;
    uint64_t *data64 = (uint64_t *)data;
    return __builtin_bswap64(data64[ind]);
  }
  void set1Bits(__uint128_t ind, uint8_t ele) {
    if (ind >= bitlen || ele > 1)
      return;

    if (ele)
      data[ind / 8] |= ele << (ind % 8);
    else
      data[ind / 8] &= ele << (ind % 8);
  }
  void setByte(__uint128_t ind, uint8_t ele) {
    if (ind >= len)
      return;
    data[ind] = ele;
  }

  void set64Bits(__uint128_t ind, uint64_t ele) {
    if (ind >= len / 8)
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

  inline uint64_t ROTR(int64_t v, int n) { return (v >> n) | (v << (64 - n)); }
  inline uint64_t CH(int64_t e, int64_t f, int64_t g) {
    return (e & f) ^ (~e & g);
  }
  inline uint64_t MAJ(int64_t a, int64_t b, int64_t c) {
    return (a & b) ^ (a & c) ^ (b & c);
  }

public:
  Sha512ByteArray(int le)
      : WordArray(le){assert(0 == (le % 128));}

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
    std::cout << "SHA-512 HASH: " << hash << std::endl;
  }

  std::string hash() { return ByteArray->transform(); }

  ~Sha512() { delete ByteArray; }
};

#define BLOCKSIZE 16

class MD5ByteArray : public WordArray {
protected:
  uint32_t A = 0x67452301;
  uint32_t B = 0xefcdab89;
  uint32_t C = 0x98badcfe;
  uint32_t D = 0x10325476;

  const uint32_t K[64] = {
      0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a,
      0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
      0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340,
      0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
      0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
      0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
      0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6, 0xeaa127fa,
      0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
      0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
      0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
      0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

  /*
   * Constants for the MD5 Transform routine as defined in RFC 1321
   */
  const uint32_t S1[4] = {7, 12, 17, 22};
  const uint32_t S2[4] = {5, 9, 14, 20};
  const uint32_t S3[4] = {4, 11, 16, 23};
  const uint32_t S4[4] = {6, 10, 15, 21};

  /*
   * Function to perform the cyclic left rotation of blocks of data
   */
  inline uint32_t CLROT(uint32_t data, uint32_t shift_bits) {
    return (data << shift_bits) | (data >> (32 - shift_bits));
  }

  inline uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (~x & z);
  };
  inline uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & ~z);
  };
  inline uint32_t H(uint32_t x, uint32_t y, uint32_t z) { return x ^ y ^ z; };
  inline uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | ~z);
  };

  inline void FF(unsigned int &a, unsigned int b, unsigned int c,
                 unsigned int d, unsigned int Xk, unsigned int s,
                 unsigned int i) {

    a += F(b, c, d) + Xk + K[i];
    a = CLROT(a, S1[s]);
    a += b;
  };

  inline void GG(unsigned int &a, unsigned int b, unsigned int c,
                 unsigned int d, unsigned int Xk, unsigned int s,
                 unsigned int i) {

    a += G(b, c, d) + Xk + K[i];
    a = CLROT(a, S2[s]);
    a += b;
  };

  inline void HH(unsigned int &a, unsigned int b, unsigned int c,
                 unsigned int d, unsigned int Xk, unsigned int s,
                 unsigned int i) {

    a += H(b, c, d) + Xk + K[i];
    a = CLROT(a, S3[s]);
    a += b;
  };
  inline void II(unsigned int &a, unsigned int b, unsigned int c,
                 unsigned int d, unsigned int Xk, unsigned int s,
                 unsigned int i) {

    a += I(b, c, d) + Xk + K[i];
    a = CLROT(a, S4[s]);
    a += b;
  };

public:
  MD5ByteArray(int le) : WordArray(le) { assert(0 == (le % 64));}

  void procBlock(int ind) {
    unsigned int AA = A, BB = B, CC = C, DD = D;

    uint32_t X[16];
    for (int i = ind; i < ind + BLOCKSIZE; i++) {
      X[i - ind] = get1Byte(i + 4 * (i + ind)) << 0 |
                   get1Byte(1 + i + 4 * (i + ind)) << 8 |
                   get1Byte(2 + i + 4 * (i + ind)) << 16 |
                   get1Byte(3 + i + 4 * (i + ind)) << 24;
    }

    /* Round 1 */
    FF(A, B, C, D, X[0], 0, 0);
    FF(D, A, B, C, X[1], 1, 1);
    FF(C, D, A, B, X[2], 2, 2);
    FF(B, C, D, A, X[3], 3, 3);
    FF(A, B, C, D, X[4], 0, 4);
    FF(D, A, B, C, X[5], 1, 5);
    FF(C, D, A, B, X[6], 2, 6);
    FF(B, C, D, A, X[7], 3, 7);
    FF(A, B, C, D, X[8], 0, 8);
    FF(D, A, B, C, X[9], 1, 9);
    FF(C, D, A, B, X[10], 2, 10);
    FF(B, C, D, A, X[11], 3, 11);
    FF(A, B, C, D, X[12], 0, 12);
    FF(D, A, B, C, X[13], 1, 13);
    FF(C, D, A, B, X[14], 2, 14);
    FF(B, C, D, A, X[15], 3, 15);

    /* Round 2 */
    GG(A, B, C, D, X[1], 0, 16);
    GG(D, A, B, C, X[6], 1, 17);
    GG(C, D, A, B, X[11], 2, 18);
    GG(B, C, D, A, X[0], 3, 19);
    GG(A, B, C, D, X[5], 0, 20);
    GG(D, A, B, C, X[10], 1, 21);
    GG(C, D, A, B, X[15], 2, 22);
    GG(B, C, D, A, X[4], 3, 23);
    GG(A, B, C, D, X[9], 0, 24);
    GG(D, A, B, C, X[14], 1, 25);
    GG(C, D, A, B, X[3], 2, 26);
    GG(B, C, D, A, X[8], 3, 27);
    GG(A, B, C, D, X[13], 0, 28);
    GG(D, A, B, C, X[2], 1, 29);
    GG(C, D, A, B, X[7], 2, 30);
    GG(B, C, D, A, X[12], 3, 31);

    /* Round 3 */
    HH(A, B, C, D, X[5], 0, 32);
    HH(D, A, B, C, X[8], 1, 33);
    HH(C, D, A, B, X[11], 2, 34);
    HH(B, C, D, A, X[14], 3, 35);
    HH(A, B, C, D, X[1], 0, 36);
    HH(D, A, B, C, X[4], 1, 37);
    HH(C, D, A, B, X[7], 2, 38);
    HH(B, C, D, A, X[10], 3, 39);
    HH(A, B, C, D, X[13], 0, 40);
    HH(D, A, B, C, X[0], 1, 41);
    HH(C, D, A, B, X[3], 2, 42);
    HH(B, C, D, A, X[6], 3, 43);
    HH(A, B, C, D, X[9], 0, 44);
    HH(D, A, B, C, X[12], 1, 45);
    HH(C, D, A, B, X[15], 2, 46);
    HH(B, C, D, A, X[2], 3, 47);

    /* Round 4 */
    II(A, B, C, D, X[0], 0, 48);
    II(D, A, B, C, X[7], 1, 49);
    II(C, D, A, B, X[14], 2, 50);
    II(B, C, D, A, X[5], 3, 51);
    II(A, B, C, D, X[12], 0, 52);
    II(D, A, B, C, X[3], 1, 53);
    II(C, D, A, B, X[10], 2, 54);
    II(B, C, D, A, X[1], 3, 55);
    II(A, B, C, D, X[8], 0, 56);
    II(D, A, B, C, X[15], 1, 57);
    II(C, D, A, B, X[6], 2, 58);
    II(B, C, D, A, X[13], 3, 59);
    II(A, B, C, D, X[4], 0, 60);
    II(D, A, B, C, X[11], 1, 61);
    II(C, D, A, B, X[2], 2, 62);
    II(B, C, D, A, X[9], 3, 63);

    A += AA;
    B += BB;
    C += CC;
    D += DD;
  }

  std::string transform() {
    for (int i = 0; i < len; i += BLOCKSIZE) {
      procBlock(i);
    }
    std::stringstream strout;
    strout << std::setfill('0') << std::setw(8) << std::hex << A;
    strout << std::setfill('0') << std::setw(8) << std::hex << B;
    strout << std::setfill('0') << std::setw(8) << std::hex << C;
    strout << std::setfill('0') << std::setw(8) << std::hex << D;
    return strout.str();
  }
};

class MD5 {
protected:
  MD5ByteArray *ByteArray;
  __uint128_t le;
  __uint128_t padding;
  __uint128_t blockBytesLen;

public:
  MD5(std::string msg) {
    le = msg.length();
    padding = ((512 - (8 * le) - 64) % 512) / 8;
    blockBytesLen = padding + le + 8;
    // message + padding 1 + padding 2;

    ByteArray = new MD5ByteArray(blockBytesLen);
    for (__uint128_t i = 0; i < le; i++) {
      ByteArray->setByte(i, msg.c_str()[i]);
    }
    ByteArray->setByte(le, 1 << 7);

    ByteArray->set64Bits(((padding + le + 1) >> 3), le);
  }

  void out() {
    ByteArray->print();
    std::string hash = ByteArray->transform();
    std::cout << "MD5 HASH: " << hash << std::endl;
  }

  std::string hash() { return ByteArray->transform(); }

  ~MD5() { delete ByteArray; }
};

class Sha1ByteArray : public WordArray {
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

  inline uint64_t ROTR(int64_t v, int n) { return (v >> n) | (v << (64 - n)); }
  inline uint64_t CH(int64_t e, int64_t f, int64_t g) {
    return (e & f) ^ (~e & g);
  }
  inline uint64_t MAJ(int64_t a, int64_t b, int64_t c) {
    return (a & b) ^ (a & c) ^ (b & c);
  }

public:
  Sha1ByteArray(int le)
      : WordArray(le){assert(0 == (le % 64));}

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

class Sha1 {
protected:
  Sha1ByteArray *ByteArray;
  __uint128_t le;
  __uint128_t padding;
  __uint128_t blockBytesLen;

public:
  Sha1(std::string msg) {
    le = msg.length();
    padding = ((512 - (8 * le) - 64) % 512) / 8;
    blockBytesLen = le + padding + 8;
    // message + padding 1 + padding 2;

    ByteArray = new Sha1ByteArray(blockBytesLen);
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
    std::cout << "SHA-1 HASH: " << hash << std::endl;
  }

  std::string hash() { return ByteArray->transform(); }

  ~Sha1() { delete ByteArray; }
};
