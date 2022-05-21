# assembler
8 bitlik bir islemci varsayarak uzerinde 8 bitlik AX,BX,CX,DX isimli register bulunan bir ram icin yazilmis assembler.
komutlar:
HRK X1,X2 // bu komutun anlamı X1=X2
TOP X1,X2 // bu komutun anlamı X1=X1+X2
CRP X1,X2 // bu komutun anlamı X1=X1*X2
CIK X1,X2 // bu komutun anlamı X1=X1-X2
BOL X1,X2 // bu komutun anlamı: tam kısmı X1=X1/X2 ve DX=X1 mod X2
VE X1,X2 // bu komutun anlamı X1=X1X2
VEYA X1,X2 // bu komutun anlamı X1=X1X2
DEG X1 // bu komutun anlamı 𝑋1 = ~𝑋1, X1 değerin ikili tabanda 0~1 ve 1~0 yapan komut
