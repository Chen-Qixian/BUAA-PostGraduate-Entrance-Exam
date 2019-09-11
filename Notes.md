# 机试复习笔记整理

### 语法糖

- sort(buf, buf + size, [cmp]) 

  - cmp可选，是一个函数
  - cmp返回true时，传入第一个参数排在第二个参数前面
    - eg：降序排列：当第一个参数>第二个参数，返回true

- 重载运算符

  - 定义于struct结构体中的方法
  - 多用于重载比较运算符用于sort排序
  - 形式上类似于cmp函数
  - 注意审题，如果排序标准不同建议使用cmp函数，注意多属性排序的指标选取

  ```c++
  bool operator< (const E &a) const{
    return attr < a.attr    
    // 将struct中的属性与传入a中的属性比较，
    // 返回true的话struct中的属性排在前面（默认传入的a为后来的元素）
  }
  ```

  





### 模板类

- 判断闰年宏定义模板【别记错了】！

  ```c++
  #define ISLEAP(x) (x % 100 != 0 && x % 4 == 0) || (x % 400 == 0) ? 1 : 0
  ```

  - 需要搭配日期数组定义进行使用

  ```c++
  int dayOfMonth[13][2] = {
  	0,0, // 补位便于月份数位对齐至1
  	31,31,
  	28,29,
  	31,31,
  	30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
  }
  ```

- 日期结构体数组

  ```c++
  struct Date {
    int day;
    int month;
    int year;
    void nextDay() {  // 查找当前日期的下一天日期
      day ++;
      if(day > dayOfMonth[month][ISLEAP(year)]){
        day = 1;
        month ++;
        if(month > 12) {
          month = 1;
          year ++;
        }
      }
    }
  }
  ```

- 日期预处理（存储每一天的信息)

  ```c++
  int buf[5001][13][2];
  int cnt = 0;  // 例如存储当前日期为总共的第几天 
  Date tmp;
  tmp.day = 1;
  tmp.month = 1;
  tmp.year = 0;
  while(tmp.year < 5001) {
    buf[tmp.year][tmp.month][tmp.day] = (cnt++);  // save some info
    tmp.nextDay();
  }
  ```

  

### 注意事项

- struct 结构体中不能定义string！
- char[]字符串数组输出前需要为结尾添加'\0'!
- 



### C字符串处理

- strcmp(char* a, char* b)
- 传递字符串参数入函数 (char* s)



### I/O

- 绝对不能printf() 和 cin 混用！！！

- 多组输入用while(scanf() != EOF) 的循环形式

- 输入特定位数的整数

  ```c++
  scanf("%4d%2d%2d", &year, &month, &day);
  ```

  - 若要输出前导0

  ```c++
  printf("%04d-%02d-%02d", &year, &month, &day);
  ```

  此例输出为2000-01-03形式

- 注意在输入的时候用%c读入，可能会读如空格/回车换行。需要将相应字符过滤掉。

- scanf的返回值为成功读入的变量个数

  - 读入数值一定要&
  - 读字符串不要&

- 读入double类型的数据%lf

- 控制输出小数点后若干位

  ```c++
  printf("%.3lf", ans);
  ```

  输出控制小数点后3位

