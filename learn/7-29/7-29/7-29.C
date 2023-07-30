#include <stdio.h>

////两个版本都可以运算
////1.老师全用说的void类型
////2.自己创的比较简单，一开始想的这个
// 
// 
// 
//typedef struct {
//	float realpart;
//	float imagpart;
//}Complex;
////创建结构体类型命名为Complex
//
////函数声明  同一文件下可有可无 操作量大的话建议弄
//void assign(Complex* p, float real, float imag);//初始化赋值
//void ADD(Complex* pa, Complex* pb, Complex* pc);//加法运算 得到的值赋给给pc指向的结构体
//void Mul(Complex* pa, Complex* pb, Complex* pc);//乘法运算 得到的值赋给给pc指向的结构体
//void Div(Complex* pa, Complex* pb, Complex* pc);//除法运算 得到的值赋给给pc指向的结构体
//
//
//void assign(Complex* p,float real,float imag)//初始化赋值
//{
//	p->imagpart = imag;
//	p->realpart = real;
//}
//void ADD(Complex* pa, Complex* pb, Complex* pc)//加法运算 得到的值赋给给pc指向的结构体
//{
//	pc->imagpart = pa->imagpart + pb->imagpart;
//	pc->realpart = pa->realpart + pb->realpart;
//}
//void Mul(Complex* pa, Complex* pb, Complex* pc)//乘法运算 得到的值赋给给pc指向的结构体
//{
//	pc->imagpart = pa->imagpart * pb->imagpart;
//	pc->realpart = pa->realpart * pb->realpart;
//}
//void Div(Complex* pa, Complex* pb, Complex* pc)//除法运算 得到的值赋给给pc指向的结构体
//{
//	pc->imagpart = pa->imagpart/pb->imagpart;
//	pc->realpart = pa->realpart/pb->realpart;
//}
//
//int main()
//{
//	float real1 = 8.0;
//	float real2 = 4.0;
//	float imag1 = 6.0;
//	float imag2 = 3.0;
//	Complex a = { 0 };
//	Complex b = { 0 };
//	Complex c = { 0 };
//	Complex d = { 0 };
//	Complex e = { 0 };
//	assign(&a,real1,imag1);
//	assign(&b, real2, imag2);
//	ADD(&a, &b, &c);
//	Mul(&a, &b, &d);
//	Div(&d, &c, &e);
//	printf("%f %f \n", e.imagpart, e.realpart);
//	return 0;
//}
////32 18
////12 9

typedef struct {
	float realpart;
	float imagpart;
}Complex;
//创建结构体类型命名为Complex

//函数声明  同一文件下可有可无 操作量大的话建议弄
void assign(Complex* p, float real, float imag);//初始化赋值
Complex ADD(Complex pa, Complex pb);//加法运算 得到的值赋给给pc指向的结构体
Complex Mul(Complex pa, Complex pb);//乘法运算 得到的值赋给给pc指向的结构体
Complex Div(Complex pa, Complex pb);//除法运算 得到的值赋给给pc指向的结构体


void assign(Complex* p, float real, float imag)//初始化赋值
{
	p->imagpart = imag;
	p->realpart = real;
}
Complex ADD(Complex pa, Complex pb)//加法运算 得到的值赋给给pc指向的结构体
{
	Complex pc = { 0 };
	pc.imagpart = pa.imagpart + pb.imagpart;
	pc.realpart = pa.realpart + pb.realpart;
	return pc;
}
Complex Mul(Complex pa, Complex pb)//乘法运算 得到的值赋给给pc指向的结构体
{
	Complex pc = { 0 };
	pc.imagpart = pa.imagpart * pb.imagpart;
	pc.realpart = pa.realpart * pb.realpart;
	return pc;
}
Complex Div(Complex pa, Complex pb)//除法运算 得到的值赋给给pc指向的结构体
{
	Complex pc = { 0 };
	pc.imagpart = pa.imagpart / pb.imagpart;
	pc.realpart = pa.realpart / pb.realpart;
	return pc;
}

int main()
{
	float real1 = 8.0;
	float real2 = 4.0;
	float imag1 = 6.0;
	float imag2 = 3.0;
	Complex a = { 0 };
	Complex b = { 0 };
	Complex c = { 0 };
	/*Complex c = { 0 };
	Complex d = { 0 };
	Complex e = { 0 };*/
	assign(&a, real1, imag1);
	assign(&b, real2, imag2);
	c = Div(Mul(a, b), ADD(a, b));
	printf("%f %f \n", c.imagpart, c.realpart);
	return 0;
}
//32 18
//12 9