# 机试复习笔记整理


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


- Huffman树模板

  ```c++
  /*模拟Huffman树计算总权值sum_weight代码*/
  priority_queue<int, vector<int>, greater<int> > Q;
  while(Q.empty()) Q.pop();
  for(int i = 0 ; i < n ; i ++) {
    scanf("%d", &x);
    Q.push(x);
  }
  int sum_weight = 0;
  int a, b;
  while(Q.size() > 1){
    a = Q.top();
    Q.pop();
    b = Q.top();
    Q.pop();
    Q.push(a + b);
    sum_weight += (a + b);
  }
  ```

  - Huffman树权值和：为所有非叶节点权值和。

- 二叉树的建立

  - 二叉树存储、建立模板

  ```c++
  struct Node {
    Node *left;
    Node *right;
    int val;
  } Tree[SIZE];  // 数组静态分配空间
  
  int loc;       // 分配到的下标，每个循环用例开始时置0
  // 节点分配创建方法
  Node *creat() {
    Tree[loc].left = Tree[loc].right = NULL;
    return &Tree[loc ++];  // 注意返回指针类型
  }
  ```

  - 二叉树遍历模板

  ```c++
  // 前序遍历
  void preOrder(Node *t) {
    /*visit Node t*/
    if(t -> left) {
      preOrder(t -> left);
    }
    if(t -> right) {
      preOrder(t -> right);
    }
  }
  // 中序遍历
  void inOrder(Node *t) {
    if(t -> left) {
     	inOrder(t -> left);
    }
    /*visit Node t*/
    if(t -> right) {
      inOrder(t -> right);
    }
  }
  // 后序遍历
  void postOrder(Node *t) {
  	if(t -> left) {
      postOrder(t -> left);
    } 
    if(t -> right) {
      postOrder(t -> right);
    }
    /*visit Node t*/
  }
  ```


- BST的建立（插入节点法）

  ```c++
  Node *insert(Node* t, int x) {
    if(t == NULL) {
      t = creat();
      t -> val = x;
      return t;
    }
    else if(x < t -> val) {
      x -> left = insert(x -> left, x);
    }
    else if(x > t -> val) {
      x -> right = insert(x -> right, x);
    }
    return t;
  }
  ```

  - 注意此处不给出插入值x于当前节点值相等的判断，这是因为，输入相等值的时候不应重复插入节点。
  
- GCD

  ```c++
  int gcd(int a ,int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
  }
  ```

  - 注意
    - 出口为得到余数为0（即a==b的情况）
    - a % b一定小于b，入口处应有 a > b

- 素数判定算法

  ```c++
  bool isPrime(int n) {
    if(n < 2) return false;
    int bound = (int)sqrt(n) + 1;
    for(int i = 2 ; i < bound ; i ++) {
      if(n % i == 0) return false;
    }
    return true;
  }
  ```

- 素数的欧拉筛法

  ```c++
  bool mark[SIZE];
  int prime[SIZE];
  
  void Eura() {
    for(int i = 0 ; i < SIZE ; i ++) {
      mark[i] = false;
    }
    int n = 0; // 素数个数
    for(int i = 2 ; i < SIZE ; i ++) {
      if(mark[i]) continue; // 被标记的都不是素数
      prime[n ++] = i; // 找到一个新素数
      for(int j = i * i ; j < SIZE ; j += i) { //将找到i的倍数都标记，技巧：从i*i开始标记即可
        mark[j] = true;
      }
    }
  }
  ```

  - 扩展：质因数分解方案
    - 先用欧拉筛初始化得到一定范围内的素数
    - 从小向大尝试用待分解数除质数列表
    - 注意超大质因数的处理：判断循环结束条件为待分解数被除到 n = 1 ，如果在素数表范围内n得不到1，则剩下的n必为一质因数，且次数为1。
  - 注意：求所有的约数

- 高精度整数运算

  ```c++
  // 高精度整数结构体定义
  struct bigInt{
    int digit[SIZE];
    int size;
    // 初始化该高精度整数
    void init() {
      size = 0;
      for(int i = 0 ; i < SIZE ; i ++) {
        digit[i] = 0;
      }
    }
    // 从输入字符串读取数字，4位一组，倒序存储
    void set(char s[]) {
      init();
      int l = strlen(s);
      // i字符串下标，t当前4位的数值，j位数计数器，c当前数字权值
      for(int i = l - 1, t = 0, j = 0, c = 1; i >= 0 ; i --) {
        t += (s[i] - '0') * c;
        j ++;
        c *= 10;
        if(j == 4 || i == 0) {
          digit[size ++] = t;
          t = 0;
          j = 0;
          c = 1;
        }
      }
    }
    // 输出控制，中间的数字补零
    void output() {
      for(int i = size - 1; i >= 0; i --) {
        if(i != size - 1) {
          printf("%04d", digit[i]);
        }
        else {
          printf("%d", digit[i]);
        }
      }
      printf("\n");
    }
    // 重载+运算符
    bigInt operator + (const bigInt &A) const {
      bigInt ret;
      ret.init();
      // 注意相邻位之间的进位
      int carry = 0, tmp;
      // 注意循环结束条件
      for(int i = 0 ; i < A.size || i < size ; i ++) {
      	tmp = A.digit[i] + digit[i] + carry;
        carry = tmp / 10000;
        tmp %= 10000;
        ret.digit[ret.size ++] = tmp;
      }
      // 注意最后一位的进位
      if(carry != 0) {
        ret.digit[ret.size ++] = carry;
      }
      return ret;
    }
  }a, b, c;
  
  // 使用方式
  a.set(str1);
  b.set(str2);
  c = a + b;
  c.output();
  ```


- 邻接链表的增删查清

  ```c++
  #include <vector>
  #define N 1000   // 图中节点数量 
  using namespace std;
  // 声明边结构体（存储边的集合）
  struct Edge {
    int nextNode; //邻接的下一节点
    int cost; //该边权重
  };
  // 创建一个N个节点的邻接链表
  vector<Edge> edge[N];
  // 清空邻接链表
  for(int i = 0 ; i < N ; i ++) edge[i].clear();
  // 添加信息至邻接链表
  Edge e;
  e.nextNode = 3;
  e.cost = 10;
  edge[1].push_back(e); // 将节点3添加至1的邻接链表中，权重位10
  // 查询节点2的全部邻接信息
  for(int i = 0 ; i < edge[2].size() ; i ++) {
    int nextNode = edge[2][i].nextNode;
    int cost = dege[2][i].cost;
  }
  // 删除edge[1][i]个邻接节点的信息
  edge[1].erase(edge[1].begin() + i, edge[1].begin + i + 1);
  ```

- 并查集模板

  ```c++
  // 并查集：查找两个节点是否属于同一棵树，即找两个节点的根节点是否相同，跟节点双亲标记为-1
  int findRoot(int x) {
    if(Tree[x] == -1) return x; // 找到根节点，返回
    int tmp = findRoot(Tree[x]); // 递归寻找根节点
    Tree[x] = tmp; // 路径压缩，将当前节点双亲直接指向找到的跟节点，减少遍历深度
    return tmp;
  }
  // 在创建并查集树的时候，初始化每个节点双亲为-1
  for(int i = 0 ; i < n ; i +=) Tree[x] = -1;
  scanf("%d%d",&a,&b); //读入a,b分别为联通边的两个节点
  a = findRoot(a);
  b = findRoot(b);
  if(a != b) Tree[a] = b; //查两个节点若不属于同一集合，就合并两个集合，合并方式为修改a的根节点为b即可
  ```


- Kruskal算法模板(与并查集几乎一模一样)

  ```c++
  // n个节点, N条边
  struct Edge{
    int a;
    int b;
    int weight;
    bool operator < (const Edge &a) const {
      return weight < a.weight;
    }
  } e[N + 1];
  
  int tree[n + 1];
  
  int findRoot(int x) {
    if(tree[x] == -1) return x;
    int tmp = findRoot(tree[x]);
    tree[x] = tmp;
    return tmp;
  }
  
  int main() {
    int bound = n * (n - 1) / 2;
    for(int i = 1 ; i <= n ; i ++) {
      tree[i] = -1;
    }
    for(int i = 0 ; i < bound ; i ++) {
      scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].weight); // 按边输入，端点、权重
    }
   	sort(e, e + bound); // 按边的权重从小到大排列
    int ans = 0; // 计算MST总权重
    // 十分类似并查集写法，注意区别！按边遍历
    for(int i = 0 ; i < bound ; i ++) {
      int a = findRoot(e[i].a);
      int b = findRoot(e[i].b);
      if(a != b) {
        tree[a] = b;
        ans += weight;
      }
    }
  }
  ```

  - 特点：按边遍历
  - 算法流程：
    - 初始化所有节点为孤立点集
    - 将所有边按权重递增排序
    - 按按权重排序后边遍历各边两端点
    - 使用并查集查找两端点是否属于同一集合，若不属于，合并之，更新MST总权重
    - 最后判断所有点是否已被纳入该MST，若图不联通，MST不存在

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



### STL的使用

- stack用法

  ```c++
  #include <stack>
  stack<int> S; //定义一个int型栈结构S
  S.push(i); //i元素压栈
  S.pop(); //弹出栈顶元素
  int x = S.top(); //取栈顶元素
  while(!S.empty()) S.pop(); //清空栈S
  ```

- priority_queue用法

  - 优先队列：默认为大顶堆（实现为堆的数据结构）
  - 常用：Huffman树（这类经常需要调整数据存储为按序排列的问题）

  ```c++
  #include <queue>
  using namespace std;
  priority_queue<int> Q;  //定义一个int型优先队列（默认大顶堆）
  priority_queue<int, vector<int>, greater<int> > Q;   // 小顶堆的声明（即较小数据排在前面）注意两个>之间要有空格！
  Q.push(i);	// 将i加入Q
  Q.pop();	// 弹出堆顶
  Q.top(); // 取得堆顶元素
  Q.size(); // 获取队列大小
  while(!Q.empty()) Q.pop(); // 清空队列
  ```

- vector用法

  - 常用：图问题存储邻接链表使用

  ```c++
  #include <vector>
  #define N 1000   // 图中节点数量 
  using namespace std;
  // 声明边结构体（存储边的集合）
  struct Edge {
    int nextNode; //邻接的下一节点
    int cost; //该边权重
  };
  // 创建一个N个节点的邻接链表
  vector<Edge> edge[N];
  // 清空邻接链表
  for(int i = 0 ; i < N ; i ++) edge[i].clear();
  // 添加信息至邻接链表
  Edge e;
  e.nextNode = 3;
  e.cost = 10;
  edge[1].push_back(e); // 将节点3添加至1的邻接链表中，权重位10
  // 查询节点2的全部邻接信息
  for(int i = 0 ; i < edge[2].size() ; i ++) {
    int nextNode = edge[2][i].nextNode;
    int cost = dege[2][i].cost;
  }
  // 删除edge[1][i]个邻接节点的信息
  edge[1].erase(edge[1].begin() + i, edge[1].begin + i + 1);
  ```



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

- 输出字符串，结尾需要补'\0'!

- scanf读字符串会在结尾自动补充'\0'

- puts输出字符串，会补充一个'\n'输出

- gets()函数

  - 用于读入缓冲区中的字符串，直到读到换行符结束，*并从缓冲区中删除该换行符*
  - 读到文件尾返回0，故循环读入方式可用如下所示方法

  ```c++
  while(gets(str)){}
  ```


### 重要规律

- 判定两棵二叉树为同一二叉树
  - 只需两者前序 / 中序遍历结果一致（必须包含中序即可，再配合前/后序中任意一种）

- %求模运算符
  - a % b 符号与a相同，与b无关
  - 结果修正（保证求模结果非负-用于下标）(a % b + b) % b
  - 大数求模（防止溢出）
    - (a * b) % c = (a % c * b % c) % c
    - (a + b) % c = (a % c + b % c) % c

- 数位拆解进制转换中的循环
  - 开始时**必须**记得判断是否为0

- 求一串数组中的最值问题
  - 务必记得再每个样例循环中初始化（必须包含在输入循环里初始化）
    - int max = INT_MIN, min = INT_MAX;

### C字符串处理

- strcmp(char* a, char* b)
- strlen(char *a)
- strcpy(char* a, char* b)
- 传递字符串参数入函数 (char* s)

### 注意事项

- struct 结构体中不能定义string！
- char[]字符串数组输出前需要为结尾添加'\0'!
- 浮点数除法：要使用double类型定义各项数据
- 注意减法、除法的计算顺序
- scanf("%d") / scanf("%s") 操作会留下一个\n在缓冲区中，若下一次输入使用scanf("%c")读字符会读入此换行符！因此每次使用scanf("%c")时务必注意！先配合一个getchar()使用