#include <iostream>

enum Flags {
    FLAG_A = 1 << 0, // 0001
    FLAG_B = 1 << 1, // 0010
    FLAG_C = 1 << 2, // 0100
    FLAG_D = 1 << 3  // 1000
};

bool isSet(int num, int bitPos) {
    return num & (1 << bitPos);
}
int setBit(int num, int bitPos) {
    return num | (1 << bitPos);
}
int clearBit(int num, int bitPos) {
    return num & ~(1 << bitPos);
}
int toggleBit(int num, int bitPos) {
    return num ^ (1 << bitPos);
}
int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
int main()
{
  int a = 5;    // 0101
  int b = 3;    // 0011
  int c = a & b; // 0001 (1)
                 //
  int a = 5;    // 0101
  int b = 3;    // 0011
  int c = a | b; // 0111 (7)

  int a = 5;    // 0101
  int b = 3;    // 0011
  int c = a ^ b; // 0110 (6)
                 //
  int a = 5;    // 0101
  int b = ~a;   // 1010 (-6 in two's complement)
                //
  int a = 5;     // 0101
  int b = a << 1; // 1010 (10)
   

   //
  // Shifts bits to the right. For unsigned numbers, fills with zeros. For signed numbers, 
  // behavior is implementation-defined (usually arithmetic shift).
  unsigned a = 10; // 1010
  unsigned b = a >> 1; // 0101 (5)
                       //
  int options = FLAG_A | FLAG_C; // 0101
    
  if (options & FLAG_A) {
        std::cout << "Flag A is set\n";
  }
    
  // Add FLAG_B
  options |= FLAG_B;
    
  // Remove FLAG_A
  options &= ~FLAG_A;
    
  // Toggle FLAG_C
  options ^= FLAG_C;
  
  return 0;
}
