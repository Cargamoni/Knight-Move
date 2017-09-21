#include <stdio.h>
#include <stdbool.h>
//Neden ingilizce ? Sedat Hocam ingilizce anlatıyor dersi, ekran çıktıları da ingilizce bu yüzden
//Ayrıca öğrencilerin üzerinde yapılan "İnternetten mi buldun bu kodları ?" önyargısına bir
//göndermek olarak hazırlanmıştır. Saygılarımla...
//Not: Bu header file kullanılmadan yapılan versiyondur. Yapımında Kullanılan Linux Komutları Aşağıdadır

/*
  800  gcc knight.c -o knight
  801  ./knight
*/
//Değişiklik

//Satranç Tahtası 12x12'lik bir matris olarak oluşturulmuştur. Bunun nedeni 8x8 dışarısındaki bölümler
//-1 ile doldurulup herhangi bir şekilde dışa çıkıldığında bu alınan -1 değeri ile yanlış seçim yapıldığı
//anlaşılması hedeflenmiştir, programın geliştirilmesi ve istenilen noktaya gitmesi için bu şekilde
//düşünülmüş ve potansiyel noktaları bulurken ekrana yazdırılırken de bu -1 değerlerinden yararlanılmıştır.
//pos_i ve pos_j kullanıcıdan alınan pozisyona yerleştirilen Knight için herin hafızada tutulduğu bölümdür
//program geliştirilmek istendiğinde bu pozisyonlar bir sonraki pozisyon olarak değiştirilebilir
int chessBoard[12][12];
int pos_i = 0;
int pos_j = 0;

//Satranç Tahtasının kullanılabilir ve kullanılamayan bölümlerinin oluşturulması bu fonksiyon ile mümkündür.
//Kullanılabilir 0    Kullanılamayan -1 ile doldurulmuştur.
void define_chessBoard()
{
  for(int i = 0; i <= 11; i++)
  {
    for(int j = 0; j<= 11; j++)
    {
      if((i<= 1 || j <= 1) || (i >= 10 || j >= 10))
        chessBoard[i][j] = -1;
      else
        chessBoard[i][j] = 0;
    }
  }
}

//Satranç Tahtasını Ekrana yazdırmak için bu fonksyion kullanılır. Etrafındaki 123 ve ABC de bu bölümde
//hazırlanmıştır. Köşelere @ konulması için ekstra if blokları kullanılıştır.
void show_chessBoard()
{
    printf("\nThis is your chess board. 0's shows available positions.\n$ is your knight.\n\n");
    for(int i = 1; i <= 10; i++)
    {
      for(int j = 1; j<= 10; j++)
      {
        if((j==1 && (i >= 2 && i <= 9 )) || (j==10 && (i <= 2 || i <= 10)))
        {
          //Örnek olarak burda sütunun ilk ve son bölümüne @ karakteri bu if ile mümkün kılınmıştır.
          if(j==10 && (i == 10 || i == 1))
            printf("%4c", 64);
          else
            printf("%4d", i-1);
            //Diğer bölümlerde ise 1-8 arası rakamlar sütunu oluşturacaktır.
        }
        //Burada da A-H arasındaki karakterler ilk ve son satırlara yazılmaktadır. Bir üst bölüm @ oluşturulmuştu
        else if((i==1 && (j >= 2 || j <= 10)) || (i==10 && (j >= 2 || j <= 9)))
            printf("%4c", j+63);
        //Bu bölümde eğer Knight yerleştirilmişse tahta üzerine $ işareti ile ifade edilecektir gösterilirken.
        else if(chessBoard[i][j] == 1)
          printf("%4c", 36);
        else if(chessBoard[i][j] == 2)
            printf("%4c", 35);
        else
        //Kalan kısımlarda ise kullanılabilir hamleler yani 0 lar ekranda gösterilir.
            printf("%4d", chessBoard[i][j]);
      }
      printf("\n\n");
    }
}
//Bu fonksiyon herhangi bir sorun olup olmadığı kontrol edilmesi için yazılmıştır. Matris üzerindeki
//değişimleri gözlemlemek için ekrana yazdırır.
void show_chessArray()
{
    for(int i = 0; i <= 11; i++)
    {
      for(int j = 0; j<= 11; j++)
      {
          printf("%4d", chessBoard[i][j]);
      }
      printf("\n\n");
    }
}
//Bu fonksyion Knight'ın yerleştirilmesi için kullanılmaktadır. Gönderilen pozisyonlar kullanıcıdan alınır
//ve ona göre yerleşim yapılır, eğer istenmeyen bir pozisyon alınırsa yerleştirme yapılmaz ve oluşturulan
//do while döngüsü bu fonksiyona göre değerleri yeniden ister. Column ve Line hangi sütun ve satıra
//yerleştirileceğini belirlemek için kullanılır. chessBoard matrisine buna göre yerleştirilir.
//c_pos ile gelen parametre column, i_pos ile gelen parametre line olarak ayarlanır.
bool first_knight_set(char c_pos, int i_pos)
{
  bool durum = false;
  int column = 0, line = 0;
  switch(c_pos)
  {
    case 'a':
      column = 2;
      break;
    case 'b':
      column = 3;
      break;
    case 'c':
      column = 4;
      break;
    case 'd':
      column = 5;
      break;
    case 'e':
      column = 6;
      break;
    case 'f':
      column = 7;
      break;
    case 'g':
      column = 8;
      break;
    case 'h':
      column = 9;
      break;
    default:
      printf("Choose a available position in Chess Table please.\n");
      return durum;
  }

  switch(i_pos)
  {
    case 1:
      line = 2;
      break;
    case 2:
      line = 3;
      break;
    case 3:
      line = 4;
      break;
    case 4:
      line = 5;
      break;
    case 5:
      line = 6;
      break;
    case 6:
      line = 7;
      break;
    case 7:
      line = 8;
      break;
    case 8:
      line = 9;
      break;
    default:
      printf("Choose a available position in Chess Table please.\n");
      return durum;
  }
  durum = true;
  pos_i = line;
  pos_j = column;
  chessBoard[line][column] = 1;
  return durum;
}
bool first_bishop_set(char c_pos, int i_pos)
{
  bool durum = false;
  int column = 0, line = 0;
  switch(c_pos)
  {
    case 'a':
      column = 2;
      break;
    case 'b':
      column = 3;
      break;
    case 'c':
      column = 4;
      break;
    case 'd':
      column = 5;
      break;
    case 'e':
      column = 6;
      break;
    case 'f':
      column = 7;
      break;
    case 'g':
      column = 8;
      break;
    case 'h':
      column = 9;
      break;
    default:
      printf("Choose a available position in Chess Table please.\n");
      return durum;
  }

  switch(i_pos)
  {
    case 1:
      line = 2;
      break;
    case 2:
      line = 3;
      break;
    case 3:
      line = 4;
      break;
    case 4:
      line = 5;
      break;
    case 5:
      line = 6;
      break;
    case 6:
      line = 7;
      break;
    case 7:
      line = 8;
      break;
    case 8:
      line = 9;
      break;
    default:
      printf("Choose a available position in Chess Table please.\n");
      return durum;
  }
  durum = true;
  pos_i = line;
  pos_j = column;
  chessBoard[line][column] = 2;
  return durum;
}
int knight_move(int takeMove)
{
  //ilk başta burada yazdırma gibi bir fikrim vardı sonra case içerisine koymaya karar verdim
  //Bu sayede yapılabilecek hareket ekranda yazdırılabiliyor ve kullanıcı seçip ona göre
  //Knight'ı istediği gibi hareket ettirebiliyordu. Daha sonra her bir hareketin kontrol edilmesi
  //ve ekranda gösterilmesi gerektiğini okudum ödevden ve bu kodları case içerisine taşıdım.
  //burda durmalarının sebebi ise kodu nasıl değiştirdiğimi ifade etmek ve gelişim sürecini göstermektir.

  //int takeMove = 0;
  //printf("1 - Available moves: One left, two up.\n");
  //printf("2 - Available moves: One left, two down.\n");
  //printf("3 - Available moves: One right, two up.\n");
  //printf("4 - Available moves: One right, two down.\n");
  //printf("5 - Available moves: One up, two right.\n");
  //printf("6 - Available moves: One down, two right.\n");
  //printf("7 - Available moves: One up, two left.\n");
  //printf("8 - Available moves: One down, two left.\n");
  //scanf("%d", &takeMove);

  //Burada tüm hamleler istenirse hesaplanabilir her hamleden sonraki lokasyonu bulunabilir.
  //Yorum satırındaki bölümler, hamleden sonra ilk pozisyonu kaldırmak için yapılmıştır.
  //Knight'ın yapabileceği hamle sayısı 8'dir yukarıda da belirtildiği gibi, bu da i/j olarak
  //bir koordinat sistemi hayal edilecek olursa aşağıdaki gibi hareketleri düzenlenmiştir.
  /*
            |
     -i -j  | -i +j
            |
    -----------------
            |
     +i -j  | +i +j
            |
  */
  //void olarak da yapılabilecek bir fonksiyon int değer döndürmesi için yapılmıştır.
  //bu pozisyon hareket yerinin uygunluğunu kontrol etmek için de kullanılabilir bu yüzden.
  switch(takeMove)
  {
    case 1:
      if(chessBoard[pos_i-2][pos_j-1] == 0)
      {
        printf("1 - Available move: One left, two up.\n");
        chessBoard[pos_i-2][pos_j-1] = 1;
      }
      else
        printf("1 - Non-Available move: One left, two up.\n");
      //chessBoard[pos_i][pos_j] = 0;
      return chessBoard[pos_i-2][pos_j-1];
    break;
    case 2:
      if(chessBoard[pos_i+2][pos_j-1] == 0)
        {
          printf("2 - Available move: One left, two down.\n");
          chessBoard[pos_i+2][pos_j-1] = 1;
        }
      else
        printf("2 - Non-Available move: One left, two down.\n");
      //chessBoard[pos_i][pos_j] = 0;
      return chessBoard[pos_i+2][pos_j+1];
    break;
    case 3:
      if(chessBoard[pos_i-2][pos_j+1] == 0)
      {
        printf("3 - Available move: One right, two up.\n");
        chessBoard[pos_i-2][pos_j+1] = 1;
      }
      else
        printf("3 - Non-Available move: One right, two up.\n");
      //chessBoard[pos_i][pos_j] = 0;
      return chessBoard[pos_i-2][pos_j+1];
    break;
    case 4:
      if(chessBoard[pos_i+2][pos_j+1] == 0)
      {
        printf("4 - Available move: One right, two down.\n");
        chessBoard[pos_i+2][pos_j+1] = 1;
      }
      else
        printf("4 - Non-Available move: One right, two down.\n");
      //chessBoard[pos_i][pos_j] = 0;
      return chessBoard[pos_i+2][pos_j+1];
    break;
    case 5:
      if(chessBoard[pos_i-1][pos_j+2] == 0)
      {
        printf("5 - Available move: One up, two right.\n");
        chessBoard[pos_i-1][pos_j+2] = 1;
      }
      else
        printf("5 - Non-Available moves: One up, two right.\n");
      //chessBoard[pos_i][pos_j] = 0;
      return chessBoard[pos_i-1][pos_j+2];
    break;
    case 6:
      if(chessBoard[pos_i+1][pos_j+2] == 0)
      {
        printf("6 - Available moves: One down, two right.\n");
        chessBoard[pos_i+1][pos_j+2] = 1;
      }
      else
        printf("6 - Non-Available moves: One down, two right.\n");
      //chessBoard[pos_i][pos_j] = 0;
      return chessBoard[pos_i+1][pos_j+2];
    break;
    case 7:
      if(chessBoard[pos_i-1][pos_j-2] == 0)
      {
        printf("7 - Available move: One up, two left.\n");
        chessBoard[pos_i-1][pos_j-2] = 1;
      }
      else
        printf("7 - Non-Available move: One up, two left.\n");
      //chessBoard[pos_i][pos_j] = 0;
      return chessBoard[pos_i-1][pos_j-2];
    break;
    case 8:
      if(chessBoard[pos_i+1][pos_j-2] == 0)
      {
        printf("8 - Available move: One down, two left.\n");
        chessBoard[pos_i+1][pos_j-2] = 1;
      }
      else
        printf("8 - Non-Available move: One down, two left.\n");
      //chessBoard[pos_i][pos_j] = 0;
      return chessBoard[pos_i+1][pos_j-2];
    break;
  }
}

int bishop_move(int posi, int posj, int yon)
{
    if(posi == 9)
        return bishop_move(pos_i, pos_j, yon +1);
    else if(posj == 9)
        return bishop_move(pos_i, pos_j, yon +1);
    else if(posi == 1)
        return bishop_move(pos_i, pos_j, yon +1);
    else if (posj == 1)
        return bishop_move(pos_i, pos_j, yon +1);
    if(yon == 0)
    {
       chessBoard[posi][posj] = 0;
        return bishop_move(posi-1, posj+1, yon);
    }
    else if(yon == 1)
    {
        chessBoard[posi][posj] = 0;
        return bishop_move(posi+1, posj+1, yon);
    }
    else if(yon == 2)
    {
        chessBoard[posi][posj] = 0;
        return bishop_move(posi+1, posj-1, yon);
    }
    else if(yon == 3)
    {
        chessBoard[posi][posj] = 0;
        return bishop_move(posi-1, posj-1, yon);
    }

}

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

  do
  {
    printf("Please set a bishop in available positions. Please join your column characters in lowercase.\n");
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
  }while(!first_bishop_set(c_pick, l_pick));
  bishop_move(pos_i,pos_j, 0);
  first_bishop_set(c_pick, l_pick);
  show_chessBoard();
}
