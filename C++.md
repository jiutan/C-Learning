# C++基础知识
## 一、对象 与 类（什么是对象，对象能干什么）
### 1. 对象

### 2. 类
一个类 既要 **规定初始化其对象的方法**，又要 **定义对象上所能执行的操作**。
既能定义 **通过函数名调用的操作**，又能定义 <<、>>、+等各种运算符在该类对象上的**新含义**

## 二、模板：C++语言 既有类模板 又有函数模板
1. 定义：编译器生成类或函数 编写的一份说明。
2. 实例化：编译器根据模板创建类或函数的过程
3. 注意：当使用模板时，需要指出编译器应把 类或函数 **实例化成何种类型**
### 1.类模板（第16章）
1. vector是类模板
2. 使用时，需提供 **额外信息**来指定模板 到底实例化成什么样的类
3. 提供额外信息的方法：在**模板名字后面跟一对尖括号，在括号内放上信息**
### 2.函数模板

## 三、流程结构
### 1. 选择结构：
#### 三目运算符
1）语法：
		表达式1 ? 表达式2 : 表达式3
2）作用：
若表达式1为真，则 执行表达式2；
若表达式1为假，则 执行表达式3.
#### switch语句
1）作用：执行 多条件分支结构
2）语句：
```c
int main(){
	switch(表达式){
		case 结果1:
        	执行语句1; break;	// break 退出当前分支
        case 结果2: 
        	执行语句2; break;
        ...
        default: 
        	执行语句n; break;	// 都不满足，则执行这个
	}
}
```
#### if 和 switch 区别
switch：
缺点：判断时，只能是 整型 或者 字符型，**不可以是一个区间**
优点：结构清晰，执行效率高
### 2.循环结构
#### while语句
1）作用：重复执行
2）语法
```c
	while(循环条件){		// 条件为真，则一直循环
	
	}
```
#### do while语句
1）作用：先执行一次 循环语句，再进行判断条件
2）语法：
```c
	do{
		循环语句
	}while(循环条件);
```
### 3.跳转语句
#### break语句：
1) 作用：用于 跳出**选择结构 或者 循环结构**
2) 使用时机：【跳过最近的 整个循环】
	（1）在switch语句中，作用是 终止case并跳出switch
	（2）在循环语句中，作用是 跳出当前的循环语句
	（3）在嵌套语句中，作用是 跳出**最近的**内层循环语句
	break;				// 可以利用 break 退出当前循环
#### continue语句：
1) 作用：在**循环语句**中，**跳过本次循环中余下尚未执行的语句**，继续执行下一次的循环
2) 使用时机：【跳过本次循环，不再执行后面的代码】
#### goto语句：
1) 作用：可以**无条件跳转语句**
2) 语法：
	goto 标记;	   // 如果 标记的名称存在，则执行到goto时
	标记;			// 则会跳转到 标记的位置
3) 使用：
```c
	cout << "1" << endl;
	goto Flag;				// 程序运行到这时，进行跳转
	cout << "2" << endl;
	Flag;					// 直接跳转到此处执行，忽略了2
	cout << "3" << endl;	
```

# C++Primer
## 一、初始化
### 初始值

### 列表初始化
1. 定义：无论是初始化对象还是某些时候为对象赋新值，都可以使用一组**由花括号括起来的初始值**
2. 特点：当用于内置类型时，使用列表初始化且初始值存在丢失信息的风险，则编译器将会报错。


## 二、变量和基本类型
### 2.2 变量 == 对象 【对象 也是 变量 】
1. 对象 有自己的 地址。
### 2.3 复合类型
**声明语句 = 基本数据类型  声明符(变量名)**
#### 2.3.1 引用（本身不是一个对象，不能定义引用的引用，一旦定义了，九无法再绑定另外的对象）
1) 语法： **基本数据类型 &d = 变量**，其中d为声明的变量名
	【将 d 与 变量 **绑定**在一起，数据类型必须相同】
2) 例如：
```c
	int ival = 1024;
	int &refVal = inval;// refVal -> inval（为ival另一个名字）
```
3) 核心：引用是 已经存在的对象 起的另外一个名字
4) 使用：
```c
int i = refval;	// 利用与refval绑定的对象的值（inval）的值初始化
```
5) 注意：
（1）_引用必须被初始化_
（2）引用类型的 初始值 必须是一个对象（变量），不能是一个数
（3）引用类型 必须 与 被引用的对象 **相同类型**。（有两种例外）
两种例外：
a.初始化常量引用（const）时，允许用任意类型的表达式作为初始值。【系统自动增加临时量】
如：
```c
	double dval = 3.14;			// 双精度浮点数定义 dval
	const int &ri = dval;		// 正确。
/** 相当于
	const int temp = dval;		// 其中 temp 为临时量
	const int &ri = temp;
*/
```

#### 2.3.2 指针（pointer）
1) 语法： 声明符：** \*d **，其中d为声明的变量名
如：
```c++
	int *ip1;	// ip1是指向 int型 对象的指针
```
2) 作用：指针**存放某个对象的地址**【获取地址：用 取地址符 &】
（指针的值 即是 地址：\*p=&ival）
```c++
	int ival = 42;
	int *p = &ival;// p是指向变量ival的指针（p存放变量ival的地址）
```
3) 利用指针访问对象：使用 **解引用符 \***来访问该对象。
【对指针**解引用** 得到**所指的对象**】
注意：解引用 仅适用于 确实指向了某个对象的 有效指针。
4) 建议：**初始化所有指针**，避免出错。实在不行，用nullptr。
5) 赋值：令他 存放一个新的地址，从而 指向一个新的对象。
区分 改变指针的值 还是 改变指针所指对象的值：
【技巧：**赋值永远改变的是 等号左侧的对象**】
```c++
	pi = &ival;	// 改变的是指针的值，pi指向了ival
	*pi =0;		// 改变的是指针所指对象的值，ival=0，指针pi不变 
```
6. 指针所占内存空间：

   （1）在32位操作系统下：占 4个字节 空间

   （2）在64位操作系统下：占 8个字节 空间 
##### 空指针：
1) 用途：初始化指针变量
2) 生成方式：
```c++
	int *p1 = nullptr;	// 等价于 int *p1 = 0;【常用】
	int *p2 = 0;
```
```c++
#include<cstdlic>		// 需要 前置的头文件
	int *p3 = NULL;		// 等价于 int *p3 = 0;【避免使用】
```
3) 注意：空指针指向的内存是不可以访问的
##### void* 指针
1) 定义：
	void \* 可用于存放 **任意类型对象的地址**。
2) 使用：
```c
	void *pv = &obj;	// obj可以是任意类型的对象
```
3) 注意：不能直接操作 void\* 指针所指的对象，没办法访问内存空间中所存的对象。
3) 后续：在19.1.1节 和 4.11.3节讲述
##### 野指针（常见的 错误 ）
1) 定义：指针变量指向 非法的内存空间
2) 如：
```cpp
	int *p = (int *)0x1100;	// 该空间不是我们申请的，所以无法访问
	cout << *p << endl;		// 野指针，无法访问。报错
```

#### 2.3.3 符号的多重含义【关键概念】
根据上下文推断：
	int &r = i; // & 紧随 类型名 出现，是一个 引用声明。
	int *p;		// * 紧随 类型名 出现，是一个 指针声明。
	p = &i;		// & 出现在 表达式 中，是一个 取地址符。
	*p = i;		// * 出现在 表达式 中，是一个 解引用符。
	int &r2 = *p;// & 为 引用声明，* 为 解引用符。
#### 2.3.4 理解复合类型的声明
1. 指向 指针的指针：
```c
	int **ppi = &pi;	// 指向一个int型的指针
```
需用两次解引用。
2. 指向 指针的引用：int \*&r = p
```c
	int *p;			// p是一个 int型 指针
	int *&r = p;	// r是一个 引用，*&r是一个指向指针p的引用。（其中，符号*说明：r引用的是一个指针）
```
### 2.4 const 限定符【定义 常量】
1. 定义：当希望定义一种**常量（值不被改变的变量）**时，可以用const对变量的类型加以限定
2. 语法：
```c
	const int ci = 56;	// ci=56，在程序中无法对ci进行更改
```
## 三、字符串、向量和数组
### 3.1 String类	[#include<string>]（为一个 对象）
#### 3.1.1 定义/初始化 string 对象
```c
	string s1;		// 创建 空字符串s1

	string s2 = s1;	// s2 是 s1 的副本 （拷贝初始化）
	string s2(s1);	// 同上（直接初始化）

	string s3 = "hello world";	// s3 是该字段的 副本（拷贝初始化）
	string s3("hello world");	// 同上（直接初始化）

	string s4(10,'c');		// s4 的内容为 10个c（直接初始化）
```
### 3.1.2 string对象上的操作
#### 读写 string 对象
注意：string对象 会自动忽略开头的空白，直到遇到下一处空白为止
```c
	os << s					// 将s写到输出流os中

	is >> s					// 将 is中读取字符串 赋给s，字符串以空白分隔，返回 is
```
#### 读取一整行[getline()]
注意：只要一遇到 换行符 就结束读取操作
```c
	getline(cin,s)			// 从 cin中 读取一行赋给 s，返回cin
```
#### empty 和 size 操作
(1)定义：empty、size 是 string的一个**成员函数**，只要使用**点操作符**指明哪个对象执行就可。
```c
	s.empty()				// s 为空返回时，则为true；否则，返回false

	s.size()				// 返回 s中 字符的个数
```
(2)注意：size函数返回的是 一个**string::size_type类型**的值；且 返回的是一个 **无符号整型数**。
```c
	// 可以用 auto 与 decltype 来查看 变量的类型
```
#### 比较 string对象【注意：对 大小写敏感 】
（1）相等/不等 运算符:(==和!=)
（2）关系运算符：<、>、>=、<=
（3）比较规则：【**按字典顺序比大小**】
a. 如果两个对象，长度不同但是前面的内容相同：则 长的 > 短的
b. 如果两个对象，内容不同：则**对第一对相异字符**进行比较。
#### 两个 string对象 相加
定义：新的对象 = 将 两个对象串接起来
```c
	string s3 = s1 + s2;		// 将 s1的内容 与 s2的内容 串接后 输出为s3

	s2 += s1;					// s2 = s1 + s2
```
#### 字符串字面值("字面值") 与 string对象 相加
（1）原则：**每个+号 左右两侧 至少有一个string对象**
（2）切记：*字符串字面值 与 string对象 是不同的类型*，**字符串字面值 + string对象 = string对象**
（3）举例：
```c
	// 正确 例子
	string s3 = s1 + "," + s2;		// 字符串字面值“，” + 两边有一个string对象
	
	string s3 = s1 + "," + "hello";	// 相当于 (s1 + ",") + "hello". 其中(s1 + ",")也为 string对象

	// 错误 例子
	string s3 = "hello" + "world";	// +号两边都为字符串字面值
	
	string s3 = "hello" + "world" + s1;	// 相当于("hello" + "world")+s1. 其中("hello" + "world")里边是两个字面值相加，错误。 
```
### 3.2.1 处理 string对象 中的字符 [#include<cctype>头文件]
目的：需要 单独处理 string对象 中的字符
#### 处理每个字符[使用 基于范围的 for语句]
```c
	// expression 是一个String对象，用于处理该对象内的字符
	// declaration 负责定义一个变量，用于访问序列中的基础元素【可以使用 引用&str 来更改自己】
	for( declaration : expression)		// 每次迭代，declaration部分的变量会被初始化为expression部分的下一个元素值
		statement;						// 待实现的功能
```
举例：改变自身字符串字符
```c
	string str("hello");
	// 使用for语句 与 引用：每次迭代，c 引用 str的下一个字符
	for(auto &c : str)					// 使用 auto自动定义变量类型；引用&c，使c与str绑定，更改c就是更改str。最后输出str
		c = toupper(c);					// toupper函数是将 小写字母变为大写字母
	cout << str << endl;
```
#### 访问/处理 单个字符 的方式：（1）使用 下标 （2）使用 迭代器
##### 方法一：下标/索引 （下标符号：[ ]）
注意：s[index] 下标的类型为 **string::size_type类型**，可以使用 **decltype(str.size())来定义 index**
前提：要保证 下标必须在合理范围内： 0 <= index <= str.size()
```c
	string str("Hello");

	cout << str[0] << endl;
```
##### 方法二：迭代器（3.4节与第9章）

### 3.3 标准库类型 vector（vector容纳着其他类型的对象，也称容器）【对象】
1. vector 表示对象的集合（所有对象的类型都相同）：集合中，每一个对象 都有一个 对应的索引
2. 使用：必须包含**头文件**
```c
	#include<vector>
	using std::vector;
```
3. vector 是 类模板：使用时，需提供 **额外信息**来指定模板 到底实例化成什么样的类
提供额外信息的方法：在**模板名字后面跟一对尖括号，在括号内放上信息**
比如：
```c
	vector<int> ivec;				// ivec为保存int类型的对象
	vector<Sales_item> Sales_vec;	// 为 保存Sacles_item类的对象
	vector<vector<string>> file;	// file为保存 vector类型的对象（老式编译器可能右三角须有空格：vector<vector<string> >）
```
4. 注意：vector*不能包含引用类型*
#### 3.3.1 定义和初始化 vector对象（两个参数：容量 和 元素初值）
##### 定义vector对象的常用方法
```c
//	T 为内部元素的类型，v 为vector对象
	vector<T> v1;				// 创建 v1为空vector类对象，其内部元素为T类型，默认初始化（常用，后面再往里加值）
	
	vector<T> v2(v1);			// v2中包含v1所有元素的副本（直接初始化）【需类型相同】
	vector<T> v2 = v1;			// 同上（拷贝初始化）【需类型相同】

	vector<T> v3(n,val);		// v3包含了 n个重复的元素，每个元素的值都是val
	vector<T> v4(n);			// v4包含了 n个重复地执行了 值初始化的对象

	vector<T> v5{a,b,c,..};		// v5包含了 初始值个数的元素，每个元素被赋予相应的初始值（直接初始化）
	vector<T> v5={a,b,c,...};	// 同上（拷贝初始化）
```
##### 列表初始化 vector对象
方法：用 **花括号**括起来的0个或多个初始元素值 被赋值给vector对象。
如：
```c

	vector<string> v1{"a","an","the"};			// 列表初始化（注意：不能使用 圆括号() ）

```
##### 创建指定数量的元素
方法：
```c
	vector<int> ivec(n,a);			// 创建 n个int类元素，每个元素的值都为a

	vector<string> svec(10,"a");	// 创建 10个string类型的元素，每个元素都为"a"
```
##### 值初始化
1. 定义：只提供 vector对象容纳的 元素数量 而省略初始值。
如：
```c
	vector<int> ivec(10);			// 10个元素，都默认为0

	vector<string> svec(10);		// 10个元素，都默认为空string对象
```
2. 库会 创建一个值初始化的初值，赋给容器中的所有元素。
  - 内置类型（如:int）：元素初始值自动设置为 0
  - 类 类型（如:string）:元素由 类默认初始化

3. 限制、注意：
  - 若 元素类型不支持默认初始化，则必须提供初始化值，否则无法初始化。
  - **只提供了元素的数量**，而没有设定初始值，**只能使用直接初始化**

##### 容量还是元素初值？（使用 花括号 或者 圆括号 区分）
1. 圆括号：提供的值是用来 **构造vector对象的**
2. 花括号：列表初始化。花括号内的值，当成是**元素初始值的列表**来处理
```c
	// 区分
	vector<int> v1(10);				// v1有10个元素，每个值都是0
	vector<int> v2{10};				// v2只有1个元素，其值为10
	
	vector<int> v3(10,1);			// v3有10个元素，每个值都是1
	vector<int> v4{10,1};			// v4有2个元素，一个10,一个1
```
3. 若使用花括号形式，但是**提供的值不能用来初始化**，则用默认值初始化对象。（如：类型不符等）
```c
	vector<string> v1{"hi"};		// 列表初始化
	vector<string> v2("hi");		// 错误。不能用圆括号

	vector<string> v3(10);			// v3有10个默认初始化的元素（因为10不为string类型）
	vector<string> v4{10,"hi"}		// v4有10个值为"hi"的元素（因为10不为string类型，使用默认初始化对象）
```
#### 3.3.2 vector 中添加元素
1. 方法：
   第一步：先创建一个 空vector：`vector<类型> v1`
   第二步：再使用 `v1.push_back(元素)`向其中添加元素。
2. 语法： 
```c
	vector<int> v1;			// 创建空vector

	v1.push_back(i);		// 将 元素i 添加至 vector后面

```
3. 注意事项：
  - 必须要确保所写的 **循环正确无误**
  - 循环体内部 **包含有vector对象添加元素的语句**，则 **不能使用范围for循环**

#### 3.3.3 其他 vector操作
1. 语法：
```c
	v.empty()					// 如果v中不含有任何元素，则返回真；否则为假

	v.size()					// 返回 v中元素的个数

	v.push_back(t)				// 向v的尾端 添加一个值为t的元素

	v(n)						// 返回 v中第n个位置上元素的引用

	v1 = v2						// 将 v2中的元素 拷贝至v1
	
	v1 = {a,b,c,..}				// 用 列表中元素的拷贝 替换 v1中的元素

	v1 == v2 					// 若 v1与v2中的对应位置元素 完全相同 ，则 返回真

	v1 != v2					// v1与v2 元素不同，则为真

	<,>,>=,<=					// 以 字典顺序进行比较

```
2. 举例：
- 使用**范围for语句**处理vector对象中的**所有元素**：【**&i:v**：引用i，并将其与v中元素绑定】
```c
	vector<int> v{1,2,3,4,5,6,7,8,9};		// 创建向量v，并设置初值

	//范围for语句
	for( &i : v )			// 引用i，并将i与v绑定：改变i，即改变v中元素。i从1开始，往上迭代
		i *= i;				// i = i*i
	
	for( i : v )			// 调用i，遍历v中元素（i从1开始，往上迭代）
		cout << i << endl;	// 打印
	
	答案：
	1 4 9 16 25 36 49 64 81
```
- `v.size()`返回vector对象中元素的个数，其类型为由 vector<类型> 定义的 size_type类型
```c
	// vector对象的类型，总是包含着元素的类型
	vector<int>::size_type
```
- 只有当**元素的值可以比较时**，**vector对象才能被比较**
如：
	string类，定义了自己的关系运算符，所以 可比较；
	size_type类，未定义关系运算符，所以 不可比较。
#### 3.3.4 计算 vector内对象的 索引
1. 方法：使用**下标运算符[]**获取指定的元素。`v[i]`（从0开始）
2. 下标的类型：`size_type`类型
3. 注意：只要vector对象**不是一个常量**，就可通过下标运算符返回的元素**赋值**
##### 注意：
1. 不能用 下标形式（索引） 添加元素：下标形式 只能用于访问元素，不能添加元素
2. 只能对 **确知已存在**的元素执行 下标操作。

##### 技巧：确保下标合法的一种有效手段：尽可能使用 范围for语句

# C++常用函数
### 生成随机数：
```c
/*	time时间系统 头文件	*/
#include<ctime>				// 头文件

int main{
/* 添加 随机数种子：利用当前时间生成随机数，防止每次随机数都一样 */
	srand( (unsigned int)time(NULL) );
	
	rand()%100;		// 生成 0~99的随机数
}
```
### 查看内存空间：
```c
	sizeof(变量)	：查看 变量 所占的内存空间
```
### 推断 变量的类型：【auot 或 decltype】
```c
	auto len = s.size();		// 系统自己定义 len的类型 （是 string::size_type类型） 
```

# C++头文件的使用
## 对 String对象 的操作
### cctype头文件
```c
#include<cctype>

	// 头文件中的函数
	isalnum(s);					// 若 s为 字母或数字 时，为真，否则为假
	isalpha(s);					// 若 s为 字母 时，为真，否则为假
	iscntrl(s);					// 若 s为 控制字符 时，为真，否则为假
	isdigit(s);					// 若 s为 数字 时，为真，否则为假
	isgraph(s);					// 若 s为 不是空格但可打印 时，为真，否则为假
	islower(s);					// 若 s为 小写字母 时，为真，否则为假
	isprint(s);					// 若 s为 可打印字符（如：空格） 时，为真，否则为假
	ispunct(s);					// 若 s为 标点符号 时，为真，否则为假
	isspace(s);					// 若 s为 空白（空格、制表符、回车、换行等） 时，为真，否则为假
	isupper(s);					// 若 s为 大写字母 时，为真，否则为假
	isxdigit(S);				// 若 s为 十六进制数字 时，为真，否则为假

	tolower(s); 				// 若 s为大写字母，则输出 对应的小写字母
	toupper(s); 				// 若 s为小写字母，则输出 对应的大写字母
```