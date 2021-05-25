// prints the numbers from ten down to zero.(use while)

#include <iostream>
int main() {
  int i = 10, sum = 0;
  while (i > 0) {
    sum += i;
    std::cout << i << " ";
    i--;
  }
  std::cout <<"sum:"<< sum << std::endl;
}
