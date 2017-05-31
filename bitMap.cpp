#define INT_BITS sizeof(int)
#define SHIFT 5 // 2^5=32
#define MASK 0x1f (16进制，2进制的00011111）// 2^5=32
#define MAX 1024*1024*1024 //max number
 
int bitmap[MAX/INT_BITS];
 
/*
* 设置第i位
* i >> SHIFT 相当于 i / (2 ^ SHIFT),
* i&MASK相当于mod操作 m mod n 运算只保留最第五位，故相当于mod 32
*/
 
void set(int i) {//设置弟i位为1
bitmap[i >> SHIFT] |= 1 << (i & MASK); //比如100位设置为1,实际上数组指针先移动三位,int 32位相当于移动了96位的bitMap, |是一位内置1的工具
                //这时候bitmap[]下标已经不行，因为那个是int为单位 
}
 
//获取第i位
int test(int i) {
return bitmap[i >> SHIFT] & (1 << (i & MASK));//与第i位做与，结果是1说明存在
}
 
//清除第i位
 
int clear(int i) {
return bitmap[i >> SHIFT] & ~(1 << (i & MASK));
}
