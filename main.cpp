#include <cstdint>
#include <iostream>

typedef uint64_t U64;

enum{
	a8, b8, c8, d8, e8, f8, g8, h8,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a1, b1, c1, d1, e1, f1, g1, h1

};

/*"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",*/


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

      if (!file) {
        std::cout << " " << 8 - rank << "  ";
      }
      square = rank * 8 + file;
      std::cout << " " << get_bit(bitboard, square);
    }

    std::cout << "\n";
  }
  std::cout << "\n     a b c d e f g h";
  std::cout << "\n   bitboard value = " << bitboard << "\n\n";
}

int main() {
	U64 board = 0ULL;
	board = set_bit(board,d5);
	print_bitboard(board);
	return 0;
}
