#ifndef DSS
#define DSS

DSS
#include "Encrypt.h"
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>

    class DSS {
protected:
  uint64_t pubkey[4], priKey;
  uint64_t secretNum;
  uint64_t hash;

  uint64_t hasconv(std::string msg) {
    uint64_t out = 0;
    uint64_t pw = 0;
    for (int i = msg.length(); i; i--) {
      unsigned char dig = msg.c_str()[i];
      dig += -'0';
      if (dig > 9)
        dig += -'a' + 10 + '0';
      out += dig * pow(16, pw++);
      out %= 1 << 20;
    }
    return out;
  }

  int prime(int64_t n) {
    for (int i = 2; i < n / 2; i++)
      if (n % i == 0)
        return 0;
    return n <= 1;
  }
  inline uint64_t modInverse(int A, int M) {
    for (int X = 1; X < M; X++)
      if (((A % M) * (X % M)) % M == 1)
        return X;

    std::cout << "ERROR" << std::endl;
    return -1;
  }

public:
  DSS(uint64_t p, uint64_t q, uint64_t h, uint64_t x) { keyGen(p, q, h, x); }
  std::string Message;
  void keyGen(uint64_t p, uint64_t q, uint64_t h, uint64_t x) {
    x = x % q;
    uint64_t g = fmod(pow(h, (p - 1) / q), p);
    pubkey[0] = p;
    pubkey[1] = q;
    pubkey[2] = g;
    pubkey[3] = fmod((uint64_t)pow(g, x), p);
    DSS::priKey = x;
  }

  uint64_t *getPubKey() { return pubkey; }
  uint64_t HashGen(std::string msg) {
    hash = hasconv(MD5(msg).hash());
    return hash;
  }

  std::pair<uint64_t, uint64_t> signGet() {
    uint64_t r, s;
    r = fmod(fmod(pow(pubkey[2], secretNum), pubkey[0]), pubkey[1]);
    s = fmod(((hash + priKey * r) / secretNum), pubkey[1]);
    return {s, r};
  }

  std::pair<uint64_t, uint64_t> SignProd(std::string msg) {
    Message = msg;
    HashGen(msg);
    secretNum = 3;
    return signGet();
  }

  int verifyMath(uint64_t *pub, uint64_t r, uint64_t s, DSS S) {
    uint64_t HM = HashGen(S.Message);

    uint64_t w = modInverse(s, pub[1]);
    uint64_t u1 = fmod(HM * w, pub[1]);
    uint64_t u2 = fmod(r * w, pub[1]);
    uint64_t v = fmod(fmod(pow(pub[2], u1) * pow(pub[3], u2), pub[0]), pub[1]);

    return v == r;
  }

  int verify(DSS Sender, uint64_t rRec, uint64_t sRec) {

    uint64_t *pub = Sender.getPubKey();
    return verifyMath(pub, rRec, sRec, Sender);
  }
};

int DssEg(std::string message) {
  srand(time(NULL));
  DSS temp = DSS(11, 5, 2, 3);
  auto [sRec, rRec] = temp.SignProd(message);
  if (temp.verify(temp, sRec, rRec)) {
    std::cout << "VERIFIED" << std::endl;
  } else {
    std::cout << "NOT VERIFIED" << std::endl;
  }
  return 0;
}

#endif // !DSS
