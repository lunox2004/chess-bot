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

enum  {
	white, black	
};

/*"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",*/


void set_bit(U64 &bitboard, int square_no) {
  	bitboard = bitboard | (1ULL << square_no);
}

void clear_bit(U64 &bitboard, int square_no) {
  	bitboard = (bitboard & (~(1ULL << square_no)));
}

int get_bit(const U64 &bitboard, int square_no) { return (bitboard >> square_no) & 1; }

void flip_bit(U64 &bitboard, int square_no) {
  	if (get_bit(bitboard, square_no) == 1) {
    	clear_bit(bitboard, square_no);
  	} else {
  		set_bit(bitboard, square_no);
	}
}

void print_bitboard(U64 bitboard) {
  	int square = 0;
  	for (square = 0; square < 64; square++) {
		if(square % 8 == 0){
			std::cout<<"\n";
		}
		
		if (!(square % 8)) {
        	std::cout << " " << 8 - square/8 << "  ";
      }
      
		std::cout << " " << get_bit(bitboard, square);
   }

   std::cout << "\n";
  	
	std::cout << "\n     a b c d e f g h";
  	std::cout << "\n   bitboard value = " << bitboard << "\n\n";
}


//attacks
U64 pawn_attacks[2][64];

U64 pawn_white_attack_gen(int position){
	U64 attack = 0ULL;
	if(position % 8 == 0){
		set_bit(attack, position - 7);
		return attack;
	}

	if(position % 8 == 7){
		set_bit(attack, position - 9);
		return attack;
	}

	set_bit(attack, position - 7);
	set_bit(attack, position - 9);
	return attack;
}

U64 pawn_black_attack_gen(int position){
	U64 attack = 0ULL;
	if(position % 8 == 0){
		set_bit(attack, position + 9);
		return attack;
	}

	if(position % 8 == 7){
		set_bit(attack, position + 7);
		return attack;
	}

	set_bit(attack, position + 7);
	set_bit(attack, position + 9);
	return attack;
}
U64 pawn_attacks_gen(int side, int position){
	if(side == black){
		return pawn_black_attack_gen(position);
	}

	return pawn_white_attack_gen(position);

}
int main() {
	U64 test = 0ULL;
	set_bit(test, a3 + 1);
	//generate pawn moves
	for(int i = 8; i < 56; i++){
		pawn_attacks[white][i] = pawn_attacks_gen(white,i);
		pawn_attacks[black][i] = pawn_attacks_gen(black,i);
	}
	print_bitboard(pawn_attacks[black][h2]);
	return 0;
}
