//NERMIN UZAY 02200201019
//clion idesi kullanılarak c99 versiyonu ile yazıldı
//bölme işleminde DX registeri sadece kalan için kullanılmıştır.
//gonderilecek olan txt uzantılı dosyada yazılı olan kodun sonu enter ile bitmelidir.
#include <stdio.h>
#include <stdint.h>

char filearray[255][255];
uint8_t A;
uint8_t B;
uint8_t C;
uint8_t D;
uint8_t ram[255];
uint8_t digit1 = 0;
uint8_t digit2 = 0;
uint8_t digit3 = 0;
uint8_t adress;

void hrk(int count, int count1) {
    if (filearray[count1][count + 4] == 'A' || filearray[count1][count + 4] == 'B' ||
        filearray[count1][count + 4] == 'C' || filearray[count1][count + 4] == 'D') {
        //ax=bx
        if (filearray[count1][count + 7] == 'A' || filearray[count1][count + 7] == 'B' ||
            filearray[count1][count + 7] == 'C' || filearray[count1][count + 7] == 'D') {
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'B') {
                A = B;
                printf("A registeri %d B registeri %d\n", A, B);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'C') {
                A = C;
                printf("A registeri %d C registeri %d\n", A, C);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'D') {
                A = D;
                printf("A registeri %d D registeri %d\n", A, D);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'A') {
                B = A;
                printf("B registeri %d A registeri %d\n", B, A);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'C') {
                B = C;
                printf("B registeri %d C registeri %d\n", B, C);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'D') {
                B = D;
                printf("B registeri %d D registeri %d\n", B, D);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'A') {
                C = A;
                printf("C registeri %d A registeri %d\n", C, A);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'B') {
                C = B;
                printf("C registeri %d B registeri %d\n", C, B);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'D') {
                C = D;
                printf("C registeri %d D registeri %d\n", C, D);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'A') {
                D = A;
                printf("D registeri %d A registeri %d\n", D, A);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'B') {
                D = B;
                printf("D registeri %d B registeri %d\n", D, B);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'C') {
                D = C;
                printf("D registeri %d C registeri %d\n", D, C);
            }
        }
        //hrk ax,2 burda sayinin kac basamakli oldugu konusunda uc nokta sorunu olabilir handle edilsin (ETTIK HERHAL)
        if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                A = digit1;
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                A = digit1 + digit2;
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                A = digit1 + digit2 + digit3;
                printf("A registeri %d \n", A);
            }
        }
        if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                B = digit1;
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                B = digit1 + digit2;
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                B = digit1 + digit2 + digit3;
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                C = digit1;
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                C = digit1 + digit2;
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                C = digit1 + digit2 + digit3;
                printf("C registeri %d \n", C);
            }


        }
        if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = digit1;
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = digit1 + digit2;
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                D = digit1 + digit2 + digit3;
                printf("D registeri %d \n", D);
            }


        }

//hrk ax,[adr]
        if (filearray[count1][count + 4] == 'A') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                A = ram[adress];
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                A = ram[adress];
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 4] == 'B') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                B = ram[adress];
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                B = ram[adress];
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 4] == 'C') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                C = ram[adress];
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                C = ram[adress];
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 4] == 'D') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                C = ram[adress];
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                C = ram[adress];
                printf("D registeri %d \n", D);
            }

        }

    }
    //hrk [adr],ax +++
    if (filearray[count1][count + 4] == '[') {
        if (filearray[count1][count + 8] == ']') {
            digit3 = 100 * ((int) filearray[count1][count + 5] - 48);
            digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
            digit1 = (int) filearray[count1][count + 7] - 48;
            adress = digit1 + digit2 + digit3;
        } else if (filearray[count1][count + 7] == ']') {
            digit2 = 10 * ((int) filearray[count1][count + 5] - 48);
            digit1 = (int) filearray[count1][count + 6] - 48;
            adress = digit1 + digit2;
        }
        if (adress < 10) {//8de a olmali
            if (filearray[count1][count + 8] == 'A') {
                ram[adress] = A;
            }
            if (filearray[count1][count + 8] == 'B') {
                ram[adress] = B;
            }
            if (filearray[count1][count + 8] == 'C') {
                ram[adress] = C;
            }
            if (filearray[count1][count + 8] == 'D') {
                ram[adress] = D;
            }


        } else if (adress < 100) {//9da a olmali
            if (filearray[count1][count + 9] == 'A') {
                ram[adress] = A;
            }
            if (filearray[count1][count + 9] == 'B') {
                ram[adress] = B;
            }
            if (filearray[count1][count + 9] == 'C') {
                ram[adress] = C;
            }
            if (filearray[count1][count + 9] == 'D') {
                ram[adress] = D;
            }

        } else if (adress < 1000) {//10da a olmali
            if (filearray[count1][count + 10] == 'A') {
                ram[adress] = A;
            }
            if (filearray[count1][count + 10] == 'B') {
                ram[adress] = B;
            }
            if (filearray[count1][count + 10] == 'C') {
                ram[adress] = C;
            }
            if (filearray[count1][count + 10] == 'D') {
                ram[adress] = D;
            }
        }
        printf("%d adresindeki deger %d \n", adress, ram[adress]);
    }
}

void top(int count, int count1) {
    if (filearray[count1][count + 4] == 'A' || filearray[count1][count + 4] == 'B' ||
        filearray[count1][count + 4] == 'C' || filearray[count1][count + 4] == 'D') {
        //top ax,bx    ax=ax+bx
        if (filearray[count1][count + 7] == 'A' || filearray[count1][count + 7] == 'B' ||
            filearray[count1][count + 7] == 'C' || filearray[count1][count + 7] == 'D') {
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'B') {
                A = A + B;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'C') {
                A = A + C;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'D') {
                A = A + D;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'A') {
                B = A + B;
                printf("B registeri %d %d\n", B);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'C') {
                B = B + C;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'D') {
                B = B + D;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'A') {
                C = C + A;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'B') {
                C = C + B;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'D') {
                C = C + D;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'A') {
                D = D + A;
                printf("D registeri %d \n", D);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'B') {
                D = D + B;
                printf("D registeri %d \n", D);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'C') {
                D = D + C;
                printf("D registeri %d \n", D);
            }
        }
        //top ax,2     ax= ax+2 burda sayinin kac basamakli oldugu konusunda uc nokta sorunu olabilir handle edilsin (ETTIK HERHAL)
        if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                A = A + digit1;
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                A = A + digit1 + digit2;
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                A = A + digit1 + digit2 + digit3;
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                B = B + digit1;
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                B = B + digit1 + digit2;
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                B = B + digit1 + digit2 + digit3;
                printf("B registeri %d \n", B);
            }
        }
        if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                C = C + digit1;
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                C = C + digit1 + digit2;
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                C = C + digit1 + digit2 + digit3;
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = D + digit1;
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = D + digit1 + digit2;
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                D = D + digit1 + digit2 + digit3;
                printf("D registeri %d \n", D);
            }

        }


//top ax,[adr]  ax=ax+[adr]
        if (filearray[count1][count + 4] == 'A') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                A = A + ram[adress];
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                A = A + ram[adress];
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 4] == 'B') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                B = B + ram[adress];
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                B = B + ram[adress];
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 4] == 'C') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                C = C + ram[adress];
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                C = C + ram[adress];
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 4] == 'D') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                D = D + ram[adress];
                printf("D registeri %d \n ", D);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                D = D + ram[adress];
                printf("D registeri %d \n ", D);
            }

        }

    }
    //top [adr],ax    [adr]=[adr]+ax
    if (filearray[count1][count + 4] == '[') {
        if (filearray[count1][count + 6] == ']') {//1 basmaakli adres 8de register ismi
            digit1 = (int) filearray[count1][count + 5] - 48;
            adress = digit1;
            if (filearray[count1][count + 8] == 'A') {
                ram[adress] = ram[adress] + A;
            }
            if (filearray[count1][count + 8] == 'B') {
                ram[adress] = ram[adress] + B;
            }
            if (filearray[count1][count + 8] == 'C') {
                ram[adress] = ram[adress] + C;
            }
            if (filearray[count1][count + 8] == 'D') {
                ram[adress] = ram[adress] + D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        } else if (filearray[count1][count + 7] == ']') {//2basamakli adres gelmis. register ismi 9da baslar
            digit2 = 10 * ((int) filearray[count1][count + 5] - 48);
            digit1 = (int) filearray[count1][count + 6] - 48;
            adress = digit1 + digit2;
            if (filearray[count1][count + 9] == 'A') {
                ram[adress] = ram[adress] + A;
            } else if (filearray[count1][count + 9] == 'B') {
                ram[adress] = ram[adress] + B;
            } else if (filearray[count1][count + 9] == 'C') {
                ram[adress] = ram[adress] + C;
            } else if (filearray[count1][count + 9] == 'D') {
                ram[adress] = ram[adress] + D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }
        if (filearray[count1][count + 8] == ']') {//3 basamakli adres gelmis. register ismi 10da baslar
            digit3 = 100 * ((int) filearray[count1][count + 5] - 48);
            digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
            digit1 = (int) filearray[count1][count + 7] - 48;
            adress = digit1 + digit2 + digit3;
            if (filearray[count1][count + 10] == 'A') {
                ram[adress] = ram[adress] + A;
            }
            if (filearray[count1][count + 10] == 'B') {
                ram[adress] = ram[adress] + B;
            }
            if (filearray[count1][count + 10] == 'C') {
                ram[adress] = ram[adress] + C;
            }
            if (filearray[count1][count + 10] == 'D') {
                ram[adress] = ram[adress] + D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }

    }
}

void cik(int count, int count1) {
    if (filearray[count1][count + 4] == 'A' || filearray[count1][count + 4] == 'B' ||
        filearray[count1][count + 4] == 'C' || filearray[count1][count + 4] == 'D') {
        // cik ax,bx    ax=ax-bx
        if (filearray[count1][count + 7] == 'A' || filearray[count1][count + 7] == 'B' ||
            filearray[count1][count + 7] == 'C' || filearray[count1][count + 7] == 'D') {
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'B') {
                A = A - B;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'C') {
                A = A - C;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'D') {
                A = A - D;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'A') {
                B = A - B;
                printf("B registeri %d %d\n", B);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'C') {
                B = B - C;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'D') {
                B = B - D;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'A') {
                C = C - A;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'B') {
                C = C - B;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'D') {
                C = C - D;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'A') {
                D = D - A;
                printf("D registeri %d \n", D);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'B') {
                D = D - B;
                printf("D registeri %d \n", D);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'C') {
                D = D - C;
                printf("D registeri %d \n", D);
            }
        }
        // cik ax,2     ax= ax -2 burda sayinin kac basamakli oldugu konusunda uc nokta sorunu olabilir handle edilsin (ETTIK HERHAL)
        if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                A = A - digit1;
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                A = A - (digit1 + digit2);
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                A = A - (digit1 + digit2 + digit3);
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                B = B - digit1;
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                B = B - (digit1 + digit2);
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                B = B - (digit1 + digit2 + digit3);
                printf("B registeri %d \n", B);
            }
        }
        if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                C = C - digit1;
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                C = C - (digit1 + digit2);
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                C = C - (digit1 + digit2 + digit3);
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = D - digit1;
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = D - (digit1 + digit2);
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                D = D - (digit1 + digit2 + digit3);
                printf("D registeri %d \n", D);
            }

        }


// cik ax,[adr]  ax=ax -[adr]
        if (filearray[count1][count + 4] == 'A') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                A = A - ram[adress];
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                A = A - ram[adress];
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 4] == 'B') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                B = B - ram[adress];
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                B = B - ram[adress];
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 4] == 'C') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                C = C - ram[adress];
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                C = C - ram[adress];
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 4] == 'D') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                D = D - ram[adress];
                printf("D registeri %d \n ", D);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                D = D - ram[adress];
                printf("D registeri %d \n ", D);
            }

        }

    }
    // cik [adr],ax    [adr]=[adr] -ax
    if (filearray[count1][count + 4] == '[') {
        if (filearray[count1][count + 6] == ']') {//1 basmaakli adres 8de register ismi
            digit1 = (int) filearray[count1][count + 5] - 48;
            adress = digit1;
            if (filearray[count1][count + 8] == 'A') {
                ram[adress] = ram[adress] - A;
            }
            if (filearray[count1][count + 8] == 'B') {
                ram[adress] = ram[adress] - B;
            }
            if (filearray[count1][count + 8] == 'C') {
                ram[adress] = ram[adress] - C;
            }
            if (filearray[count1][count + 8] == 'D') {
                ram[adress] = ram[adress] - D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        } else if (filearray[count1][count + 7] == ']') {//2basamakli adres gelmis. register ismi 9da baslar
            digit2 = 10 * ((int) filearray[count1][count + 5] - 48);
            digit1 = (int) filearray[count1][count + 6] - 48;
            adress = digit1 + digit2;
            if (filearray[count1][count + 9] == 'A') {
                ram[adress] = ram[adress] - A;
            } else if (filearray[count1][count + 9] == 'B') {
                ram[adress] = ram[adress] - B;
            } else if (filearray[count1][count + 9] == 'C') {
                ram[adress] = ram[adress] - C;
            } else if (filearray[count1][count + 9] == 'D') {
                ram[adress] = ram[adress] - D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }
        if (filearray[count1][count + 8] == ']') {//3 basamakli adres gelmis. register ismi 10da baslar
            digit3 = 100 * ((int) filearray[count1][count + 5] - 48);
            digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
            digit1 = (int) filearray[count1][count + 7] - 48;
            adress = digit1 + digit2 + digit3;
            if (filearray[count1][count + 10] == 'A') {
                ram[adress] = ram[adress] - A;
            }
            if (filearray[count1][count + 10] == 'B') {
                ram[adress] = ram[adress] - B;
            }
            if (filearray[count1][count + 10] == 'C') {
                ram[adress] = ram[adress] - C;
            }
            if (filearray[count1][count + 10] == 'D') {
                ram[adress] = ram[adress] - D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }

    }

}

void crp(int count, int count1) {
    if (filearray[count1][count + 4] == 'A' || filearray[count1][count + 4] == 'B' ||
        filearray[count1][count + 4] == 'C' || filearray[count1][count + 4] == 'D') {
        // /crp ax,bx    ax=ax*bx
        if (filearray[count1][count + 7] == 'A' || filearray[count1][count + 7] == 'B' ||
            filearray[count1][count + 7] == 'C' || filearray[count1][count + 7] == 'D') {
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'B') {
                A = A * B;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'C') {
                A = A * C;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'D') {
                A = A * D;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'A') {
                B = B * A;
                printf("B registeri %d %d\n", B);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'C') {
                B = B * C;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'D') {
                B = B * D;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'A') {
                C = C * A;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'B') {
                C = C * B;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'D') {
                C = C * D;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'A') {
                D = D * A;
                printf("D registeri %d \n", D);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'B') {
                D = D * B;
                printf("D registeri %d \n", D);
            }
            if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 7] == 'C') {
                D = D * C;
                printf("D registeri %d \n", D);
            }
        }
        // /crp ax,2     ax= ax *2
        if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                A = A * digit1;
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                A = A * (digit1 + digit2);
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                A = A * (digit1 + digit2 + digit3);
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                B = B * digit1;
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                B = B * (digit1 + digit2);
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                B = B * (digit1 + digit2 + digit3);
                printf("B registeri %d \n", B);
            }
        }
        if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                C = C * digit1;
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                C = C * (digit1 + digit2);
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                C = C * (digit1 + digit2 + digit3);
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 4] == 'D' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = D * digit1;
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = D * (digit1 + digit2);
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                D = D * (digit1 + digit2 + digit3);
                printf("D registeri %d \n", D);
            }

        }


// /crp ax,[adr]  ax=ax *[adr]
        if (filearray[count1][count + 4] == 'A') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                A = A * ram[adress];
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                A = A * ram[adress];
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 4] == 'B') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                B = B * ram[adress];
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                B = B * ram[adress];
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 4] == 'C') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                C = C * ram[adress];
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                C = C * ram[adress];
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 4] == 'D') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                D = D * ram[adress];
                printf("D registeri %d \n ", D);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                D = D * ram[adress];
                printf("D registeri %d \n ", D);
            }

        }

    }
    // /crp [adr],ax    [adr]=[adr] *ax
    if (filearray[count1][count + 4] == '[') {
        if (filearray[count1][count + 6] == ']') {//1 basmaakli adres 8de register ismi
            digit1 = (int) filearray[count1][count + 5] - 48;
            adress = digit1;
            if (filearray[count1][count + 8] == 'A') {
                ram[adress] = ram[adress] * A;
            }
            if (filearray[count1][count + 8] == 'B') {
                ram[adress] = ram[adress] * B;
            }
            if (filearray[count1][count + 8] == 'C') {
                ram[adress] = ram[adress] * C;
            }
            if (filearray[count1][count + 8] == 'D') {
                ram[adress] = ram[adress] * D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        } else if (filearray[count1][count + 7] == ']') {//2basamakli adres gelmis. register ismi 9da baslar
            digit2 = 10 * ((int) filearray[count1][count + 5] - 48);
            digit1 = (int) filearray[count1][count + 6] - 48;
            adress = digit1 + digit2;
            if (filearray[count1][count + 9] == 'A') {
                ram[adress] = ram[adress] * A;
            } else if (filearray[count1][count + 9] == 'B') {
                ram[adress] = ram[adress] * B;
            } else if (filearray[count1][count + 9] == 'C') {
                ram[adress] = ram[adress] * C;
            } else if (filearray[count1][count + 9] == 'D') {
                ram[adress] = ram[adress] * D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }
        if (filearray[count1][count + 8] == ']') {//3 basamakli adres gelmis. register ismi 10da baslar
            digit3 = 100 * ((int) filearray[count1][count + 5] - 48);
            digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
            digit1 = (int) filearray[count1][count + 7] - 48;
            adress = digit1 + digit2 + digit3;
            if (filearray[count1][count + 10] == 'A') {
                ram[adress] = ram[adress] * A;
            }
            if (filearray[count1][count + 10] == 'B') {
                ram[adress] = ram[adress] * B;
            }
            if (filearray[count1][count + 10] == 'C') {
                ram[adress] = ram[adress] * C;
            }
            if (filearray[count1][count + 10] == 'D') {
                ram[adress] = ram[adress] * D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }

    }

}

void bol(int count, int count1) {
    if (filearray[count1][count + 4] == 'A' || filearray[count1][count + 4] == 'B' ||
        filearray[count1][count + 4] == 'C' || filearray[count1][count + 4] == 'D') {
        // bol ax,bx    ax=ax/bx
        if (filearray[count1][count + 7] == 'A' || filearray[count1][count + 7] == 'B' ||
            filearray[count1][count + 7] == 'C' || filearray[count1][count + 7] == 'D') {
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'B') {
                D = A % B;
                A = A / B;
                printf("A registeri %d \n", A);
                printf("bolumden kalan %d\n", D);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'C') {
                D = A % C;
                A = A / C;
                printf("A registeri %d \n", A);
                printf("bolumden kalan %d\n", D);
            }
            if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 7] == 'D') {
                D = A & D;
                A = A / D;
                printf("A registeri %d \n", A);
                printf("bolumden kalan %d\n", D);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'A') {
                D = B % A;
                B = B / A;
                printf("B registeri %d %d\n", B);
                printf("bolumden kalan %d\n", D);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'C') {
                D = B % C;
                B = B / C;
                printf("B registeri %d \n", B);
                printf("bolumden kalan %d\n", D);
            }
            if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 7] == 'D') {
                D = B % D;
                B = B / D;
                printf("B registeri %d \n", B);
                printf("bolumden kalan %d\n", D);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'A') {
                D = C % A;
                C = C / A;
                printf("C registeri %d \n", C);
                printf("bolumden kalan %d\n", D);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'B') {
                D = C % A;
                C = C / B;
                printf("C registeri %d \n", C);
                printf("bolumden kalan %d\n", D);
            }
            if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 7] == 'D') {
                D = C % D;
                C = C / D;
                printf("C registeri %d \n", C);
                printf("bolumden kalan %d\n", D);
            }

        }
        // bol ax,2     ax= ax /2
        if (filearray[count1][count + 4] == 'A' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = A % digit1;
                A = A / digit1;
                printf("A registeri %d \n", A);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = A % (digit1 + digit2);
                A = A / (digit1 + digit2);
                printf("A registeri %d \n", A);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                D = A % (digit1 + digit2 + digit3);
                A = A / (digit1 + digit2 + digit3);
                printf("A registeri %d \n", A);
                printf("bolumden kalan %d\n", D);
            }

        }
        if (filearray[count1][count + 4] == 'B' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = B % digit1;
                B = B / digit1;
                printf("B registeri %d \n", B);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = B % (digit1 + digit2);
                B = B / (digit1 + digit2);
                printf("B registeri %d \n", B);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                D = B % (digit1 + digit2 + digit3);
                B = B / (digit1 + digit2 + digit3);
                printf("B registeri %d \n", B);
                printf("bolumden kalan %d\n", D);
            }
        }
        if (filearray[count1][count + 4] == 'C' && filearray[count1][count + 8] != 'X') {
            if (filearray[count1][count + 8] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = C % digit1;
                C = C / digit1;
                printf("C registeri %d \n", C);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = C % (digit1 + digit2);
                C = C / (digit1 + digit2);
                printf("C registeri %d \n", C);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                D = C % (digit1 + digit2 + digit3);
                C = C / (digit1 + digit2 + digit3);
                printf("C registeri %d \n", C);
                printf("bolumden kalan %d\n", D);
            }

        }

// bol ax,[adr]  ax=ax /[adr]
        if (filearray[count1][count + 4] == 'A') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                D = A % ram[adress];
                A = A / ram[adress];
                printf("A registeri %d \n", A);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                D = A % ram[adress];
                A = A / ram[adress];
                printf("A registeri %d \n", A);
                printf("bolumden kalan %d\n", D);
            }

        }
        if (filearray[count1][count + 4] == 'B') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                D = B % ram[adress];
                B = B / ram[adress];
                printf("B registeri %d \n", B);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                D = B % ram[adress];
                B = B / ram[adress];
                printf("B registeri %d \n", B);
                printf("bolumden kalan %d\n", D);
            }

        }
        if (filearray[count1][count + 4] == 'C') {
            if (filearray[count1][count + 11] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                adress = digit1 + digit2 + digit3;
                D = C % ram[adress];
                C = C / ram[adress];
                printf("C registeri %d \n", C);
                printf("bolumden kalan %d\n", D);
            } else if (filearray[count1][count + 10] == ']') {
                digit1 = (int) filearray[count1][count + 9] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                adress = digit1 + digit2;
                D = C % ram[adress];
                C = C / ram[adress];
                printf("C registeri %d \n", C);
                printf("bolumden kalan %d\n", D);
            }

        }

    }
    // bol [adr],ax    [adr]=[adr] /ax
    if (filearray[count1][count + 4] == '[') {
        if (filearray[count1][count + 6] == ']') {//1 basmaakli adres 8de register ismi
            digit1 = (int) filearray[count1][count + 5] - 48;
            adress = digit1;
            if (filearray[count1][count + 8] == 'A') {
                D = ram[adress] % A;
                ram[adress] = ram[adress] / A;
            }
            if (filearray[count1][count + 8] == 'B') {
                D = ram[adress] % B;
                ram[adress] = ram[adress] / B;
            }
            if (filearray[count1][count + 8] == 'C') {
                D = ram[adress] % C;
                ram[adress] = ram[adress] / C;
            }

            printf("%d adresindeki deger %d\n", adress, ram[adress]);
            printf("bolumden kalan %d\n", D);
        } else if (filearray[count1][count + 7] == ']') {//2basamakli adres gelmis. register ismi 9da baslar
            digit2 = 10 * ((int) filearray[count1][count + 5] - 48);
            digit1 = (int) filearray[count1][count + 6] - 48;
            adress = digit1 + digit2;
            if (filearray[count1][count + 9] == 'A') {
                D = ram[adress] % A;
                ram[adress] = ram[adress] / A;
            } else if (filearray[count1][count + 9] == 'B') {
                D = ram[adress] % B;
                ram[adress] = ram[adress] / B;
            } else if (filearray[count1][count + 9] == 'C') {
                D = ram[adress] % C;
                ram[adress] = ram[adress] / C;
            }

            printf("%d adresindeki deger %d\n", adress, ram[adress]);
            printf("bolumden kalan %d\n", D);
        }
        if (filearray[count1][count + 8] == ']') {//3 basamakli adres gelmis. register ismi 10da baslar
            digit3 = 100 * ((int) filearray[count1][count + 5] - 48);
            digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
            digit1 = (int) filearray[count1][count + 7] - 48;
            adress = digit1 + digit2 + digit3;
            if (filearray[count1][count + 10] == 'A') {
                D = ram[adress] % A;
                ram[adress] = ram[adress] / A;
            }
            if (filearray[count1][count + 10] == 'B') {
                D = ram[adress] % B;
                ram[adress] = ram[adress] / B;
            }
            if (filearray[count1][count + 10] == 'C') {
                D = ram[adress] % C;
                ram[adress] = ram[adress] / C;
            }

            printf("%d adresindeki deger %d\n", adress, ram[adress]);
            printf("bolumden kalan %d\n", D);
        }

    }

}

void veya(int count, int count1) {
    if (filearray[count1][count + 5] == 'A' || filearray[count1][count + 5] == 'B' ||
        filearray[count1][count + 5] == 'C' || filearray[count1][count + 5] == 'D') {
        //veya ax,bx    ax=ax+bx
        if (filearray[count1][count + 8] == 'A' || filearray[count1][count + 8] == 'B' ||
            filearray[count1][count + 8] == 'C' || filearray[count1][count + 8] == 'D') {
            if (filearray[count1][count + 5] == 'A' && filearray[count1][count + 8] == 'B') {
                A = A | B;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 5] == 'A' && filearray[count1][count + 8] == 'C') {
                A = A | C;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 5] == 'A' && filearray[count1][count + 8] == 'D') {
                A = A | D;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 5] == 'B' && filearray[count1][count + 8] == 'A') {
                B = A | B;
                printf("B registeri %d %d\n", B);
            }
            if (filearray[count1][count + 5] == 'B' && filearray[count1][count + 8] == 'C') {
                B = B | C;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 5] == 'B' && filearray[count1][count + 8] == 'D') {
                B = B | D;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 5] == 'C' && filearray[count1][count + 8] == 'A') {
                C = C | A;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 5] == 'C' && filearray[count1][count + 8] == 'B') {
                C = C | B;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 5] == 'C' && filearray[count1][count + 8] == 'D') {
                C = C | D;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 5] == 'D' && filearray[count1][count + 8] == 'A') {
                D = D | A;
                printf("1442D registeri %d \n", D);
            }
            if (filearray[count1][count + 5] == 'D' && filearray[count1][count + 8] == 'B') {
                D = D | B;
                printf("1446D registeri %d \n", D);
            }
            if (filearray[count1][count + 5] == 'D' && filearray[count1][count + 8] == 'C') {
                D = D | C;
                printf("1450D registeri %d \n", D);
            }
        }
        //veya ax,2     ax= ax|2
        if (filearray[count1][count + 5] == 'A' && filearray[count1][count + 9] != 'X') {
            if (filearray[count1][count + 9] == '\0') {
                digit1 = (int) filearray[count1][count + 8] - 48;
                A = A | digit1;
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                A = A | (digit1 + digit2);
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 11] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                A = A | (digit1 + digit2 + digit3);
                printf("A registeri %d \n", A);
            }


        }
        if (filearray[count1][count + 5] == 'B' && filearray[count1][count + 9] != 'X') {
            if (filearray[count1][count + 9] == '\0') {
                digit1 = (int) filearray[count1][count + 8] - 48;
                B = B | digit1;
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                B = B | (digit1 + digit2);
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 11] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                B = B | (digit1 + digit2 + digit3);
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 5] == 'C' && filearray[count1][count + 9] != 'X') {
            if (filearray[count1][count + 9] == '\0') {
                digit1 = (int) filearray[count1][count + 8] - 48;
                C = C | digit1;
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                C = C | (digit1 + digit2);
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 11] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                C = C | (digit1 + digit2 + digit3);
                printf("C registeri %d \n", C);
            }


        }
        if (filearray[count1][count + 5] == 'D' && filearray[count1][count + 9] != 'X') {
            if (filearray[count1][count + 9] == '\0') {
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = D + digit1;
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 10] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                D = D | (digit1 + digit2);
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 11] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 8] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                digit1 = (int) filearray[count1][count + 10] - 48;
                D = D | (digit1 + digit2 + digit3);
                printf("D registeri %d \n", D);
            }


        }


//veya ax,[adr]  ax=ax+[adr]
        if (filearray[count1][count + 5] == 'A') {
            if (filearray[count1][count + 12] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 10] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 9] - 48);
                digit1 = (int) filearray[count1][count + 11] - 48;
                adress = digit1 + digit2 + digit3;
                A = A | ram[adress];
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 11] == ']') {
                digit1 = (int) filearray[count1][count + 10] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                adress = digit1 + digit2;
                A = A | ram[adress];
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 5] == 'B') {
            if (filearray[count1][count + 12] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 10] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 9] - 48);
                digit1 = (int) filearray[count1][count + 11] - 48;
                adress = digit1 + digit2 + digit3;
                B = B | ram[adress];
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 11] == ']') {
                digit1 = (int) filearray[count1][count + 10] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 89] - 48);
                adress = digit1 + digit2;
                B = B | ram[adress];
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 5] == 'C') {
            if (filearray[count1][count + 12] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 10] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 9] - 48);
                digit1 = (int) filearray[count1][count + 11] - 48;
                adress = digit1 + digit2 + digit3;
                C = C | ram[adress];
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 11] == ']') {
                digit1 = (int) filearray[count1][count + 10] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                adress = digit1 + digit2;
                C = C | ram[adress];
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 5] == 'D') {
            if (filearray[count1][count + 12] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 10] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 9] - 48);
                digit1 = (int) filearray[count1][count + 11] - 48;
                adress = digit1 + digit2 + digit3;
                D = D | ram[adress];
                printf("D registeri %d \n ", D);
            } else if (filearray[count1][count + 11] == ']') {
                digit1 = (int) filearray[count1][count + 10] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 9] - 48);
                adress = digit1 + digit2;
                D = D | ram[adress];
                printf("D registeri %d \n ", D);
            }

        }

    }
    //veya [adr],ax    [adr]=[adr]|ax
    if (filearray[count1][count + 5] == '[') {
        if (filearray[count1][count + 7] == ']') {//1 basmaakli adres 8de register ismi
            digit1 = (int) filearray[count1][count + 6] - 48;
            adress = digit1;
            if (filearray[count1][count + 9] == 'A') {
                ram[adress] = ram[adress] | A;
            }
            if (filearray[count1][count + 9] == 'B') {
                ram[adress] = ram[adress] | B;
            }
            if (filearray[count1][count + 9] == 'C') {
                ram[adress] = ram[adress] | C;
            }
            if (filearray[count1][count + 9] == 'D') {
                ram[adress] = ram[adress] | D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        } else if (filearray[count1][count + 7] == ']') {//2basamakli adres gelmis. register ismi 9da baslar
            digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
            digit1 = (int) filearray[count1][count + 7] - 48;
            adress = digit1 + digit2;
            if (filearray[count1][count + 10] == 'A') {
                ram[adress] = ram[adress] | A;
            } else if (filearray[count1][count + 10] == 'B') {
                ram[adress] = ram[adress] | B;
            } else if (filearray[count1][count + 10] == 'C') {
                ram[adress] = ram[adress] | C;
            } else if (filearray[count1][count + 10] == 'D') {
                ram[adress] = ram[adress] | D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }
        if (filearray[count1][count + 9] == ']') {//3 basamakli adres gelmis. register ismi 10da baslar
            digit3 = 100 * ((int) filearray[count1][count + 6] - 48);
            digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
            digit1 = (int) filearray[count1][count + 8] - 48;
            adress = digit1 + digit2 + digit3;
            if (filearray[count1][count + 11] == 'A') {
                ram[adress] = ram[adress] | A;
            }
            if (filearray[count1][count + 11] == 'B') {
                ram[adress] = ram[adress] | B;
            }
            if (filearray[count1][count + 11] == 'C') {
                ram[adress] = ram[adress] | C;
            }
            if (filearray[count1][count + 11] == 'D') {
                ram[adress] = ram[adress] | D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }

    }

}

void ve(int count, int count1) {
    if (filearray[count1][count + 3] == 'A' || filearray[count1][count + 3] == 'B' ||
        filearray[count1][count + 3] == 'C' || filearray[count1][count + 3] == 'D') {
        //veya ax,bx    ax=ax+bx
        if (filearray[count1][count + 6] == 'A' || filearray[count1][count + 6] == 'B' ||
            filearray[count1][count + 6] == 'C' || filearray[count1][count + 6] == 'D') {
            if (filearray[count1][count + 3] == 'A' && filearray[count1][count + 6] == 'B') {
                A = A & B;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 3] == 'A' && filearray[count1][count + 6] == 'C') {
                A = A & C;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 3] == 'A' && filearray[count1][count + 6] == 'D') {
                A = A & D;
                printf("A registeri %d \n", A);
            }
            if (filearray[count1][count + 3] == 'B' && filearray[count1][count + 6] == 'A') {
                B = A & B;
                printf("B registeri %d %d\n", B);
            }
            if (filearray[count1][count + 3] == 'B' && filearray[count1][count + 6] == 'C') {
                B = B & C;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 3] == 'B' && filearray[count1][count + 6] == 'D') {
                B = B & D;
                printf("B registeri %d \n", B);
            }
            if (filearray[count1][count + 3] == 'C' && filearray[count1][count + 6] == 'A') {
                C = C & A;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 3] == 'C' && filearray[count1][count + 6] == 'B') {
                C = C & B;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 3] == 'C' && filearray[count1][count + 6] == 'D') {
                C = C & D;
                printf("C registeri %d \n", C);
            }
            if (filearray[count1][count + 3] == 'D' && filearray[count1][count + 6] == 'A') {
                D = D & A;
                printf("D registeri %d \n", D);
            }
            if (filearray[count1][count + 3] == 'D' && filearray[count1][count + 6] == 'B') {
                D = D & B;
                printf("D registeri %d \n", D);
            }
            if (filearray[count1][count + 3] == 'D' && filearray[count1][count + 6] == 'C') {
                D = D & C;
                printf("D registeri %d \n", D);
            }
        }
        //ve ax,2     ax= ax&2
        if (filearray[count1][count + 3] == 'A' && filearray[count1][count + 7] != 'X') {
            if (filearray[count1][count + 7] == '\0') {
                digit1 = (int) filearray[count1][count + 6] - 48;
                A = A & digit1;
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 8] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
                digit1 = (int) filearray[count1][count + 7] - 48;
                A = A & (digit1 + digit2);
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 6] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                A = A & (digit1 + digit2 + digit3);
                printf("A registeri %d \n", A);
            }


        }
        if (filearray[count1][count + 3] == 'B' && filearray[count1][count + 7] != 'X') {
            if (filearray[count1][count + 7] == '\0') {
                digit1 = (int) filearray[count1][count + 6] - 48;
                B = B & digit1;
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 8] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
                digit1 = (int) filearray[count1][count + 7] - 48;
                B = B & (digit1 + digit2);
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 6] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                B = B & (digit1 + digit2 + digit3);
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 3] == 'C' && filearray[count1][count + 7] != 'X') {
            if (filearray[count1][count + 7] == '\0') {
                digit1 = (int) filearray[count1][count + 6] - 48;
                C = C & digit1;
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 8] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
                digit1 = (int) filearray[count1][count + 7] - 48;
                C = C & (digit1 + digit2);
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 6] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                C = C & (digit1 + digit2 + digit3);
                printf("C registeri %d \n", C);
            }


        }
        if (filearray[count1][count + 3] == 'D' && filearray[count1][count + 7] != 'X') {
            if (filearray[count1][count + 7] == '\0') {
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = D + digit1;
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 8] == '\0') {//sayi 2 basamakli
                digit2 = 10 * ((int) filearray[count1][count + 6] - 48);
                digit1 = (int) filearray[count1][count + 7] - 48;
                D = D & (digit1 + digit2);
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 9] == '\0') {//sayi 3 basamakli
                digit3 = 100 * ((int) filearray[count1][count + 6] - 48);
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 8] - 48;
                D = D & (digit1 + digit2 + digit3);
                printf("D registeri %d \n", D);
            }


        }


//veya ax,[adr]  ax=ax+[adr]
        if (filearray[count1][count + 4] == 'A') {
            if (filearray[count1][count + 10] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                adress = digit1 + digit2 + digit3;
                A = A & ram[adress];
                printf("A registeri %d \n", A);
            } else if (filearray[count1][count + 9] == ']') {
                digit1 = (int) filearray[count1][count + 8] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                adress = digit1 + digit2;
                A = A & ram[adress];
                printf("A registeri %d \n", A);
            }

        }
        if (filearray[count1][count + 3] == 'B') {
            if (filearray[count1][count + 10] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                adress = digit1 + digit2 + digit3;
                B = B & ram[adress];
                printf("B registeri %d \n", B);
            } else if (filearray[count1][count + 9] == ']') {
                digit1 = (int) filearray[count1][count + 8] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                adress = digit1 + digit2;
                B = B & ram[adress];
                printf("B registeri %d \n", B);
            }

        }
        if (filearray[count1][count + 3] == 'C') {
            if (filearray[count1][count + 10] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                adress = digit1 + digit2 + digit3;
                C = C & ram[adress];
                printf("C registeri %d \n", C);
            } else if (filearray[count1][count + 9] == ']') {
                digit1 = (int) filearray[count1][count + 8] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                adress = digit1 + digit2;
                C = C & ram[adress];
                printf("C registeri %d \n", C);
            }

        }
        if (filearray[count1][count + 3] == 'D') {
            if (filearray[count1][count + 10] == ']') {
                //adresin kac basamakli oldugunu bulma
                digit2 = 10 * ((int) filearray[count1][count + 8] - 48);
                digit3 = 100 * ((int) filearray[count1][count + 7] - 48);
                digit1 = (int) filearray[count1][count + 9] - 48;
                adress = digit1 + digit2 + digit3;
                D = D & ram[adress];
                printf("D registeri %d \n", D);
            } else if (filearray[count1][count + 9] == ']') {
                digit1 = (int) filearray[count1][count + 8] - 48;
                digit2 = 10 * ((int) filearray[count1][count + 7] - 48);
                adress = digit1 + digit2;
                D = D & ram[adress];
                printf("D registeri %d \n", D);
            }

        }

    }
    //veya [adr],ax    [adr]=[adr]&ax
    if (filearray[count1][count + 3] == '[') {
        if (filearray[count1][count + 5] == ']') {//1 basmaakli adres 8de register ismi
            digit1 = (int) filearray[count1][count + 4] - 48;
            adress = digit1;
            if (filearray[count1][count + 7] == 'A') {
                ram[adress] = ram[adress] & A;
            }
            if (filearray[count1][count + 7] == 'B') {
                ram[adress] = ram[adress] & B;
            }
            if (filearray[count1][count + 7] == 'C') {
                ram[adress] = ram[adress] & C;
            }
            if (filearray[count1][count + 7] == 'D') {
                ram[adress] = ram[adress] & D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        } else if (filearray[count1][count + 6] == ']') {//2basamakli adres gelmis. register ismi 9da baslar
            digit2 = 10 * ((int) filearray[count1][count + 4] - 48);
            digit1 = (int) filearray[count1][count + 5] - 48;
            adress = digit1 + digit2;
            if (filearray[count1][count + 8] == 'A') {
                ram[adress] = ram[adress] & A;
            } else if (filearray[count1][count + 8] == 'B') {
                ram[adress] = ram[adress] & B;
            } else if (filearray[count1][count + 8] == 'C') {
                ram[adress] = ram[adress] & C;
            } else if (filearray[count1][count + 8] == 'D') {
                ram[adress] = ram[adress] & D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }
        if (filearray[count1][count + 7] == ']') {//3 basamakli adres gelmis. register ismi 10da baslar
            digit3 = 100 * ((int) filearray[count1][count + 4] - 48);
            digit2 = 10 * ((int) filearray[count1][count + 5] - 48);
            digit1 = (int) filearray[count1][count + 6] - 48;
            adress = digit1 + digit2 + digit3;
            if (filearray[count1][count + 9] == 'A') {
                ram[adress] = ram[adress] & A;
            }
            if (filearray[count1][count + 9] == 'B') {
                ram[adress] = ram[adress] & B;
            }
            if (filearray[count1][count + 9] == 'C') {
                ram[adress] = ram[adress] & C;
            }
            if (filearray[count1][count + 9] == 'D') {
                ram[adress] = ram[adress] & D;
            }
            printf("%d adresindeki deger %d\n", adress, ram[adress]);
        }

    }

}

void deg(int count, int count1) {
    if (filearray[count1][count + 4] == 'A') {
        A = ~A;
        printf("A registerinin tersi %d\n", A);
    }
    if (filearray[count1][count + 4] == 'B') {
        B = ~B;
        printf("B registerinin tersi %d\n", B);
    }
    if (filearray[count1][count + 4] == 'C') {
        C = ~C;
        printf("C registerinin tersi %d\n", C);
    }
    if (filearray[count1][count + 4] == 'D') {
        D = ~D;
        printf("D registerinin tersi %d\n", D);
    }
}

void assamble(char filearray[255][255], int count, int count1) {
    if (filearray[count1][count] == 'H') {
        hrk(count, count1);
    }
    if (filearray[count1][count] == 'T') {
        top(count, count1);
    }
    if (filearray[count1][count] == 'C' && filearray[count1][count + 1] == 'R') {
        crp(count, count1);
    }
    if (filearray[count1][count] == 'C' && filearray[count1][count + 1] == 'I') {
        cik(count, count1);
    }
    if (filearray[count1][count] == 'B') {
        bol(count, count1);
    }
    if (filearray[count1][count] == 'V' && filearray[count1][count + 2] == 'Y') {
        veya(count, count1);
    }
    if (filearray[count1][count] == 'V' && filearray[count1][count + 2] == ' ') {
        ve(count, count1);
    }
    if (filearray[count1][count] == 'D') {
        deg(count, count1);
    }

}

int main() {
    char buffer;
    int counter = 0;
    int counter1 = 0;
    int i = 0;
    int j = 0;
    char ch;
    char ch1;
    char file[255];

    printf("dosyanin adresini girin \n Ornegin : C:\\Users\\Dell\\Desktop\\file.txt \n");
    scanf("%s", &file);
    FILE *fn = fopen(file, "r");

//dosya içeriğini diziye aktarma
    if (fn == NULL) {
        fprintf(stderr, "Unable to open file %s\n", file);
    } else {
        while ((buffer = getc(fn)) != EOF) {
            printf("%c", buffer);
            if (buffer == '\n') {
                counter++;
                counter1 = 0;
            } else {
                filearray[counter][counter1] = buffer;
                counter1++;
            }
        }
    }
    for (int k = 0; k < 255; ++k) {
        ram[k] = k;
    }

    int count = 0;
    int count1 = 0;

    for (int k = 0; k < counter; ++k) {
        assamble(filearray, count1, k);
        printf("\nAX = %d \nBX = %d\nCX = %d\nDX = %d\n", A, B, C, D);
        count1 = 0;
    }

    return 0;
}
