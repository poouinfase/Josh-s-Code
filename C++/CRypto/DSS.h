#define CHATGPT

#ifndef CHATGPT
#ifndef DS
#define DS

DS
#include "Encrypt.h"
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <stdint.h>

    class DSS {
protected:
  uint64_t pubkey[4], priKey;
  uint64_t secretNum;
  uint64_t hash;

  uint64_t hasconv(std::string msg) {
    __uint128_t out = 0;
    uint64_t pw = 0;
    for (int i = msg.length(); i; i--) {
      unsigned char dig = msg.c_str()[i];
      dig += -'0';
      if (dig > 9)
        dig += -'a' + 10 + '0';
      out += dig * powAh(16, pw++);
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

  __uint128_t powAh(uint64_t base, uint32_t exp) {
    if (base == 0)
      return 0;
    __uint128_t t = 1;
    while (exp > 0) { // Simplifying multiplication by squaring itself
      if ((exp & 1) == 1)
        t = t * base;
      base = base * base;
      exp >>= 1;
    }
    return t;
  }

public:
  DSS(uint64_t p, uint64_t q, uint64_t h, uint64_t x) {
    /* std::cout << int(powAh(16, 5)) << std::endl; */
    keyGen(p, q, h, x);
  }
  std::string Message;
  void keyGen(uint64_t p, uint64_t q, uint64_t h, uint64_t x) {
    x = x % q;
    uint64_t g = fmod(powAh(h, (p - 1) / q), p);
    pubkey[0] = p;
    pubkey[1] = q;
    pubkey[2] = g;
    pubkey[3] = fmod((uint64_t)powAh(g, x), p);
    DSS::priKey = x;
  }

  uint64_t *getPubKey() { return pubkey; }
  uint64_t HashGen(std::string msg) {
    hash = hasconv(Sha1(msg).hash());
    return hash;
  }

  std::pair<uint64_t, uint64_t> signGet() {
    uint64_t r, s;
    r = fmod(fmod(powAh(pubkey[2], secretNum), pubkey[0]), pubkey[1]);
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
    uint64_t v =
        fmod(fmod(powAh(pub[2], u1) * powAh(pub[3], u2), pub[0]), pub[1]);

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

#endif // !DS

#else
#include <cmath>
#include <iostream>
#include <random>
#include <string>

// Define large prime numbers (p and q) and generator (g)
const int p = 11;
const int q = 5;
const int g = 2;

// Function to calculate modular exponentiation (base^exp % mod)
int modExp(int base, int exp, int mod) {
  int result = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return result;
}

// Function to calculate modular inverse
int modInv(int base, int mod) { return modExp(base, mod - 2, mod); }

// Function to generate key pair
std::pair<int, int> generateKeyPair() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, q - 1);
  int privateKey = dist(gen);
  int publicKey = modExp(g, privateKey, p);
  return std::make_pair(privateKey, publicKey);
}

int Hash(const std::string &message) {
  int hashValue = 0;
  for (char c : message) {
    hashValue += static_cast<int>(c);
  }
  return hashValue;
}

// Function to sign a message
std::pair<int, int> signMessage(const std::string &message, int privateKey) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, q - 1);
  int k = dist(gen);
  int r = modExp(g, k, p) % q;
  int s = (modInv(k, q) * (Hash(message) + privateKey * r)) % q;
  return std::make_pair(r, s);
}

// Function to verify signature
bool verifySignature(const std::string &message, int r, int s, int publicKey) {
  int w = modInv(s, q);
  int u1 = (Hash(message) * w) % q;
  int u2 = (r * w) % q;
  int v = ((modExp(g, u1, p) * modExp(publicKey, u2, p)) % p) % q;
  return v == r;
}

// Dummy hash function (replace with a secure hash function)

int DssEg(std::string message) {
  // Generate key pair
  std::pair<int, int> keys = generateKeyPair();
  int privateKey = keys.first;
  int publicKey = keys.second;

  // Sign message
  /* std::string message = "Hello, world!"; */
  std::pair<int, int> signature = signMessage(message, privateKey);
  int r = signature.first;
  int s = signature.second;

  // Verify signature
  bool isValid = verifySignature(message, r, s, publicKey);

  if (isValid) {
    std::cout << "Signature is valid." << std::endl;
  } else {
    std::cout << "Signature is not valid." << std::endl;
  }

  return 0;
}
#endif // !CHATGPT
