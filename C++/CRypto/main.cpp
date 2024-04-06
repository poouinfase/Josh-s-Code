#include "ENR.cpp"

int main() {
  std::cout << "CHOICES:\n1.SHA-512\n2.MD5" << std::endl;

  int n = 0;
  std::cin >> n;

  std::cout << "Message: ";

  std::string Message;
  std::cin >> Message;
  std::cout << std::endl;
  switch (n) {

  case 1:
    Sha512(Message).out();
    break;
  case 2:
    MD5(Message).out();
    break;
  }
}
