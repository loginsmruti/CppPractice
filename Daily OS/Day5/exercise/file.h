#pragma pack(1)

typedef struct file 
{
 char fileName[15];
 short int toggleFlag;
 int startByte , totalBytes ; 
}FILE;
