#ifndef knightLib_h
#define knightLib_h

//knight.c içerisinde kullanılan tüm fonksiyonlar prototip olarak burada tanımlanıp
//header dosyasından çağırılmaktadır.
void define_chessBoard();
void show_chessBoard();
void show_chessArray();
bool first_knight_set(char c_pos, int i_pos);
int knight_move(int takeMove);

#endif