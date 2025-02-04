#include <cstdint>
#include <iostream>

typedef uint64_t U64;

U64 set_bit(U64 bitboard, int square_no) {
  return (bitboard | (1ULL << square_no));
}

U64 clear_bit(U64 bitboard, int square_no) {
  return (bitboard & (~(1ULL << square_no)));
}

int get_bit(U64 bitboard, int square_no) { return (bitboard >> square_no) & 1; }

U64 flip_bit(U64 bitboard, int square_no) {
  if (get_bit(bitboard, square_no) == 1) {
    return (clear_bit(bitboard, square_no));
  }
  return (set_bit(bitboard, square_no));
}

void print_bitboard(U64 bitboard) {
  int square = 0;
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      square = rank * 8 + file;
      std::cout << " " << get_bit(bitboard, square);
    }

    std::cout << "\n";
  }
  std::cout << "\n\n";
}

int main() {
  U64 board = 2;
  print_bitboard(board);
  board = set_bit(board, 3);
  print_bitboard(board);
  board = clear_bit(board, 2);
  print_bitboard(board);
  board = flip_bit(board, 2);
  print_bitboard(board);

  return 0;
}
