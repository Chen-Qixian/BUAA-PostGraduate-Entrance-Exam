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

  







### 注意事项

- struct 结构体中不能定义string！
- char[]字符串数组输出前需要为结尾添加'\0'!
- 



### C字符串处理





### I/O





