#pragma once



inline int count_moves(char** board, int x, int y, int dirx, int diry, char symb, int count = 0) {
	if (x > 2 || y > 2 || x < 0 || y < 0)
		return count - 1;
	if (board[x][y] != symb) {
		return count - 1;
	}
	if (count == 2) {
		return count;
	}
	return count_moves(board, x + dirx, y + diry, dirx, diry, symb, count + 1);
}


inline bool countmo(char** board, int x, int y, int dirx, int diry, char symb) {
	return count_moves(board, x, y, dirx, diry, symb) + count_moves(board, x, y, -dirx, -diry, symb) + 1 >= 3;
}