#include <stdio.h>
#include <stdbool.h>
#include "knightLib.h"

//Neden ingilizce ? Sedat Hocam ingilizce anlatıyor dersi, ekran çıktıları da ingilizce bu yüzden
//Ayrıca öğrencilerin üzerinde yapılan "İnternetten mi buldun bu kodları ?" önyargısına bir
//göndermek olarak ingilizce hazırlanmıştır. Saygılarımla...
//Not: Bu header file kullanılarak yapılan versiyondur. Yapımında Kullanılan Linux Terminal Komutları Aşağıdadır

/*
  815  gcc -c knight.c -o knight.o
  816  gcc -c knightLib.c -o knightLib.o
  818  gcc knight.o knightLib.o -lm -o knightHeaderVersion
  819  ./knightHeaderVersion 
*/

//Satranç Tahtası 12x12'lik bir matris olarak oluşturulmuştur. Bunun nedeni 8x8 dışarısındaki bölümler
//-1 ile doldurulup herhangi bir şekilde dışa çıkıldığında bu alınan -1 değeri ile yanlış seçim yapıldığı
//anlaşılması hedeflenmiştir, programın geliştirilmesi ve istenilen noktaya gitmesi için bu şekilde
//düşünülmüş ve potansiyel noktaları bulurken ekrana yazdırılırken de bu -1 değerlerinden yararlanılmıştır.
//pos_i ve pos_j kullanıcıdan alınan pozisyona yerleştirilen Knight için herin hafızada tutulduğu bölümdür
//program geliştirilmek istendiğinde bu pozisyonlar bir sonraki pozisyon olarak değiştirilebilir
int chessBoard[12][12];
int pos_i = 0;
int pos_j = 0;

int main()
{
  //karakter ve sayı istenilerek Knight'ın yerleştirileceği lokasyonu tutan değişkenler
  char c_pick;
  int l_pick;
  //Satranç tahtasının kullanılabilinir hale getiren fonksiyon tetiklenir
  define_chessBoard();
  //Satranç tahtası gösterilir.
  show_chessBoard();
  //Bu döngü alınan değerleri first_knight_set fonksiyonuna göndererek doğru değer girilene kadar
  //tekrar etmesi için ayarlanmıştır.
  do
  {
    printf("Please set a knight in available positions. Please join your column characters in lowercase.\n");
    printf("Choose column A-H = ");
    scanf(" %c", &c_pick);
    printf("Choose line   1-8 = ");
    scanf("%d", &l_pick);
    //Tüm boş karelere koymak istedim burdaki for döngüsünde ancak bu işlem uygulanamadı, daha
    //sonra yeniden denenemek üzere yorum satırına eklendi.
    /*for(int i = 1; i <= 8; i++)
    {
        char c = i + 96;
        printf("%c",c);
        first_knight_set(c,i);
    }*/
  }while(!first_knight_set(c_pick, l_pick));
  //ilk yerleştirme yapılıktan sonra Knight'ın yeri gösterilmek için yeniden satranç tahtası gösterilir.
  show_chessBoard();
  //Burada da knight_move normalde kullanıcı odaklı bir hareket algoritmasına sahipken olabilecek
  //tüm hamlelerin ekrana gösterilmesi istenildiği üzere bu döngü oluşturulmuştur. normalde
  //seçimi kullanıcı yapmacakken şimdi bu döngü her bir hareketi uygulamaktadır.
  for(int i = 0; i<= 7; i++)
  { 
      //printf("%d",
      knight_move(i+1);
  }
  //Son olarak da tüm hareketler ekranda gösterilmektedir.
  show_chessBoard();
}
