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
  
- Floyd算法


  - 特点：

    - 时间O(n ^ 3) 空间 O(n ^ 2) -> 要求图中节点总数不能超出200
    - 可以找到所有点之间的最短路径（全源最短路径问题）
    - 存储使用邻接矩阵进行存储，若两点之间有多余1条边，则选择较短边存储
    
  - 算法：

    - 邻接矩阵保存图，若两节点间没有直接联通路径，则距离先保存为-1（代表∞）
    - 三重循环，最外层表示经过前k个点时，节点i到节点j之间最短路径
    - 若i到k或j到k之间无联通路径，则跳过该点
    - 若i经过k到j的长度更短或i和j之间无联通路径，则更新i和j之间的最短路径
    
    ```c++
    // 邻接矩阵初始化
      for(int i = 1 ; i <= n ; i ++) {
        for(int j = 1 ; j <= n ; j ++) {
          ans[i][j] = -1;
        }
        ans[i][i] = 0; // 注意自身到自身的距离为0
      }
      // Floyd算法实现
      for(int k = 1 ; k <= n ; k ++) {
        for(int i = 1 ; i <= n ; i ++) {
          for(int j = 1 ; j <= n ; j ++) {
            if(ans[i][k] == -1 || ans[k][j] == -1) continue;
            if(ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j]) {
              ans[i][j] = ans[i][k] + ans[k][j];
            }
          }
        }
      }
    ```

- Dijkstra算法模板

  - 存储使用邻接链表存储 vector<E> e[N];
  - 标记数组 bool mark[N]; 表示当前点是否有加入到集合K中（集合K为已经确定的最短路点集）
  - 距离向量 int dis[N]; 当mark[i]为true时，表示从源到i点的最短距离；否则表示从源出发经过K中某点到达i点的最短距离
  - 外层循环n-1次，除源点直接初始化确定外，其他n-1个点需要依次确定
  - 内层2个循环，第一个循环遍历新加入点相邻且不在K中的点，更新距离向量至最短；第二个循环遍历所有点，跳过所有已经在K中的点和不可达点，找到一个新的到源点到最小距离，确定为到该点的最短距离，将这个新点加入K，更新，进行下一圈外层循环
  - 最后得到的结果是单源最短路径，即从特定点出发能到达其他所有点的最短距离
  - 代码模板如下

  ```c++
  #define N 1001 // 点总数上限 
  // 声明邻接链表结构体
  struct E {
    int next; // 下一相邻点
    int c; // 权重
  };
  vector<E> e[N];
  int dis[N];
  bool mark[N];
  int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m); //输入点总数n和边总数m
    // 初始化
    for(int i = 1 ; i <= n ; i ++) {
      e[i].clear();
      dis[i] = -1;
      mark[i] = false;
    }
    // 输入图信息
    while(m --) {
      scanf("%d%d%d", &a, &b, &c);
      E tmp;
      tmp.c = c;
      tmp.next = a;
      e[b].push_back(tmp);
      tmp.next = b;
      e[a].push_back(tmp); // 无向图邻接链表两个方向都要存储 
    }
    // 初始化第一个点
    int newP = 1; // 这个数值不一定是1，看题意要求从第几个点开始的最短路径，即设置为源
    mark[newP] = true;
    dis[newP] = 0;
    // 外层循环n-1次依次确定n-1个新加入点
    for(int i = 1 ; i < n ; i ++) {
      // 第一个内层循环遍历新加入点相邻且不在K中的点，更新距离向量dis
      for(int j = 0 ; j < e[newP].size() ; j ++) {
        int next = e[newP][j].next;
        int c = e[newP][j].c;
        if(mark[next]) continue;
        // !!易错点注意这里要与经过新加入的点进行比较！
        if(dis[next] == -1 || dis[next] > dis[newP] + c) {
          dis[next] = dis[newP] + c;
        }
      }
      // 第二个内层循环遍历所有可达且不在K中的点，找距离最短的点确定之，并加入K
      int min = INT_MAX;
      for(int j = 1 ; j <= n ; j ++) {
        if(mark[j]) continue;
        if(dis[j] == -1) continue;
        if(dis[j] < min) {
          min = dis[j];
          newP = j;
        }
      }
      mark[newP] = true;
    }
    printf("%d\n", dis[n]); // 打印输出到目标点距离值（按题意未必是n）
    return 0;
  }
  ```

- 拓扑排序模板

  - 使用邻接链表存储，存下一节点数字即可
  - 每次寻找入度为0的节点，删除之，删除以之为尾的所有边
  - 循环上述过程至无入度为0的点，若还有点在图中，说明有环，拓扑排序失败

  ```c++
  #include <bits/stdc++.h>
  #define N 110
  using namespace std;
  
  vector<int> e[N]; // 邻接链表存储该有向图
  queue<int> q; // 队列存储入度为0点（不一定用queue，只是存储一下，便于处理）
  int indeg[N]; // 存储每个节点入度
  
  int main(void) {
  	int n, m, x, y;
  	while(scanf("%d%d", &n, &m) != EOF) {
  		if(n == 0) break;
  		while(q.empty() == false) q.pop(); // 每次初始化清空队列
      // 初始化
  		for(int i = 0 ; i < n ; i ++) {
  			e[i].clear();
  			indeg[i] = 0;
  		}
      // 有向图初始化，设置入度
  		while(m --){
  			scanf("%d%d", &x, &y);
  			indeg[y] ++;
  			e[x].push_back(y);
  		}
  		// 统计处理过的点数
  		int cnt = 0;
  		// 找所有入度为0的点加入q
  		for(int i = 0 ; i < n ; i ++) {
  			if(indeg[i] == 0) {
  				q.push(i);
  			}
  		}
  		// 循环删除入度0点以及相邻边
  		while(q.empty() == false) {
  			int t = q.front();
  			q.pop();
  			cnt ++; // 当弹出一个点后证明该点被处理
  			for(int i = 0 ; i < e[t].size() ; i ++) {
  				indeg[e[t][i]] --;
          // 删除尾点入度后，尾点入度若变为0，则将该点加入处理队列
  				if(indeg[e[t][i]] == 0) {
  					q.push(e[t][i]);
  				}
  			}
  		}
  		if(cnt == n) {
  			printf("YES\n"); // 拓扑排序成功
  		}
  		else {
  			printf("NO\n"); // 有环图
  		}
  	}
  	return 0;
  }
  ```

- BFS模板
  - BFS实现的数据结构为一个队列，队列中存储一个状态结构体
  - BFS非常适合解决找寻最优解的问题
  - 关键是确定状态的转换方式，确定有效状态，并添加状态标记
  - 模板代码如下
  
  ```c++
  void bfs() {
    while(Q.empty() == false) {
      E now = Q.front();
      Q.pop();
      for(int i = 0 ; i < 6 ; i ++) {
        int nx = now.x + go[i][0];
        int ny = now.y + go[i][1];
        /*边界处理*/
        /*更新状态和标记*/
        E tmp;
        tmp.x = nx;
        tmp.y = ny;
        Q.push(tmp); // 队列Q中存放的表示状态的结构体
        /*达到出口处返回*/
      }
    }
  }
  ```
  
- 全排列模板


  - 类似于DFS

  ```c++
  int num[N]; // 存储全排列
  bool mark[N]; // 标记当前数字是否被使用
  int n; // 输入需要全排列的总数
  
  void perm(int k) {
    if(k == n) {
      for(int i = 0 ; i < n ; i ++) {
        printf("%d",num[i]);
      }
      printf("\n");
      return;
    }
    for(int i = 1 ; i <= n ; i ++) {
      if(mark[i]) continue;
      num[k] = i;
      mark[i] = true;
      perm(k + 1);
      mark[i] = false;
    }
  }
  
  int main(void) {
    perm(0);
  }
  ```

- DFS模板


  - DFS的实现为递归
  - 重点是确定状态元组，状态转移方式，以及出口
  - 易错点：dfs后需要将遍历过的状态复原

  ```c++
  // 遍历图：状态转移数组
  int go[][2] = {
  	1 , 0,
  	-1, 0,
  	0 , 1,
  	0 ,-1
  };
  // dfs：针对此题有3个量在进行状态转移：位置坐标x，y以及时间信息time
  void dfs(int x, int y, int time) {
  	for(int i = 0 ; i < 4 ; i ++) {
  		int nx = x + go[i][0];
  		int ny = y + go[i][1];
  		int nt = time + 1;
      // 先排除不可达状态
  		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
  		if(maze[nx][ny] == 'X') continue;
      // 确定出口为时间恰好为t，到达dx和dy点
  		if(nx == dx && ny == dy && nt == t) {
  			flag = true;
  			return;
  		}
      // 递归前设置该点为已访问
  		maze[nx][ny] = 'X';
  		dfs(nx, ny, nt);
  		// 注意DFS每层递归后将该点恢复到原来状态
  		maze[nx][ny] = '.';
  	}
  	return;
  }
  ```

- 错位排列模板（欧拉装错信封问题）

  ```c++
  #include <stdio.h>
  long long f[20];
  int n;
  long long F(int x) {
    if(x <= 1) return 0;
    if(x == 2) return 1;
    return (x - 1) * F(x - 1) + (x - 1) * F(x - 2); // 错排公式 
  }
  int main(void) {
    scanf("%d", &n);
    printf("%lld", F(n));
  }
  ```

- LIS 模板

  - 最长递增子序列：确定如下的递推关系
    - F[1] = 1
    - F[i] = max(1, F[j] + 1) , j < i , ai > aj
  - 若是递减子序列：将上述ai > aj调整为ai < aj即可

  ```c++
  #include <bits/stdc++.h>
  #define N 50
  using namespace std;
  int a[N], dp[N];
  int main(void) {
    int k, ans, tmax;
    while(scanf("%d", &k) != EOF) {
      for(int i = 0 ; i < k ; i ++) {
        scanf("%d", &a[i]);
      }
      dp[0] = 1;
      // 要点1:每个DP需要根据之前所有遍历j<i的DP中取得最值
      for(int i = 0 ; i < k ; i ++) {
        tmax = 1;
        for(int j = 0 ; j < i ; j ++) {
          if(a[j] >= a[i]) {
            tmax = max(tmax, dp[j] + 1);
          }
        }
        dp[i] = tmax;
      }
      // 要点2:最终结果要从所有DP中选最优解
      ans = 0;
      for(int i = 0 ; i < k ; i ++) {
        ans = max(ans, dp[i]);
      }
      printf("%d\n", ans);
    }
    return 0;
  }
  ```

  - 时间O(n^2) 空间O(n)

- LCS 模板

  - 思路：用dp[x] [y]存储s1中前x个字符与s2中前y个字符组成的最长公共子序列长度
  - 递推关系：
    - dp[i] [0] = 0 , 0 <= i <= n
    - dp[0] [j] = 0 , 0 <= j <= m
    - dp[x] [y] = dp[x-1] [y-1] + 1 , s1[x] == s2[y]
    - dp[x] [y] = max(dp[x-1] [y], dp[x] [y-1]) , s1[x] != s2[y]
  - 时间复杂度O(l1 * l2)

  - 样例代码：

  ```c++ 
  #include <bits/stdc++.h>
  #define N 110
  using namespace std;
  int dp[N][N];
  char s1[N], s2[N];
  int main(void) {
    while(scanf("%s", s1) != EOF) {
      scanf("%s", s2);
      int l1 = strlen(s1), l2 = strlen(s2);
      for(int i = 0 ; i <= l1 ; i ++) {
        dp[i][0] = 0;
      }
      for(int j = 0 ; j <= l2 ; j ++) {
        dp[0][j] = 0;
      }
      for(int i = 1 ; i <= l1 ; i ++) {
        for(int j = 1 ; j <= l2 ; j ++) {
          if(s1[i-1] == s2[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1;
          }
          else {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
          }
        }
      }
      printf("%d\n",dp[l1][l2]);
    }
  }
  ```

- 0-1背包问题模板

  - 0-1背包问题：给定背包总空间，每种物品的价值，所占空间，每种物品要么不放，要么只放1个，求能装物品的最大价值。
  - 重量的遍历顺序为倒序！

  ```c++
  #include <bits/stdc++.h>
  #define N 1100
  using namespace std;
  
  int c[N], v[N]; // 花费 / 价值
  int dp[N]; // 装重量为j的物品的最大价值
  
  int main(void) {
  	int t, m;
  	while(scanf("%d%d", &t, &m) != EOF) {
  		for(int i = 1 ; i <= m ; i ++) {
  			scanf("%d%d", &c[i], &v[i]);
  		}
  		for(int i = 0 ; i <= t ; i ++) {
  			dp[i] = 0;
  		}
  		for(int i = 1 ; i <= m ; i ++) {
        // 注意：必须为倒序遍历（因为只有1个物品）
  			for(int j = t ; j >= c[i] ; j --) {
  				dp[j] = max(dp[j], dp[j-c[i]] + v[i]); 
  			}
  		}
  		printf("%d\n", dp[t]);
  	}
  	return 0; 
  }
  ```
  - 0-1背包的基本变形：要求所选物品必须恰好装满背包
    - 解决：将状态修改为dp[i] [j]表示装满j重量物品
    - 只需将初始值修改dp[0] [0] = 0，dp[0] [j] = -INF即可。其他步骤完全不变

- 完全背包问题

  - 完全背包：0-1基础上，每种物品没有数量限制
  - 解决方案：调整遍历顺序即可
  - 代码模板：

  ```c++
  // 只需调换一下0-1背包问题中的重量遍历顺序
  for(int i = 1 ; i <= m ; i ++) {
    for(int j = c[i] ; j <= t ; j ++) {
      dp[j] = max(dp[j], dp[j-c[i]] + v[i]);
    }
  }
  ```

- 多重背包问题

  - 多重背包：在0-1的基础上，每种物品有多个
  - 解决方案：转化成0-1背包进行处理，对每种物品，按照其数量进行拆分，拆分类似于二分

  ```c++
  int cnt = 0; // 物品总数
  int c = 1; // 权值，每层循环初始化为1
  while(k - c > 0) {
    k -= c;
    w[++ cnt] = k * w[i];
    v[cnt] = k * v[i];
    c *= 2;
  }
  w[++ cnt] = k * w[i];
  v[cnt] = k * v[i];
  ```

  

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

- queue用法

  - 维持队列FIFO性质

  ```c++
  #include <queue>
  queue<int> Q;
  Q.push(i);
  int head = Q.front();
  Q.pop();
  Q.empty();
  while(Q.empty() == false) Q.pop(); // 清空队列
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