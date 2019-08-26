# C's Macro Introduction  
### 1.The Connect Macros: `##`  
这是一个预处理连接符，这个操作符主要用来将两个符号连接成为一个完整的宏符号。通过下面的代码，可以看到其具体的使用方法:  
1. **如下例子:**  
  ```
  #include <stdio.h>
  struct macro
  {
      int N;
      char M;
  };
  struct macro macro_drv = {100,20};
  #define XNAME(n) x##n
  #define Macro(x) x##_drv.N

  int main(void)
  {
      char *XNAME(3) = "Hello,Macro(##)\n";
      printf("%s",XNAME(3));
      printf("The struct:%d\n",Macro(macro));
      return 0;
  }
  ```  
2. **运行结果如下所示:**  
![Res](https://img2018.cnblogs.com/blog/772331/201908/772331-20190826201100589-1552523535.png)  

### 2.The Variadic Macros: `...` and `__VA_ARGS__`  
在某些函数当中，需要接收变化数量的参数，例如基本的printf函数。  
我们可以通过将函数的**最后一个参数**定义为宏`...`，这样函数就可以使用预定义的宏`__VA_ARGS__`来表示变化数量的变量了。  
1. **如下例子:**  
  ```
  #include <stdio.h>
  #define PR(x,...) printf("Message" #x ":" __VA_ARGS__)
  #define VA(x,y,...) printf(#x" "#y" "#__VA_ARGS__)

  int main(void)
  {
      PR(1,"%s,%s\n","Hello","Macro");
      VA(I,am,Superman!);
      return 0;
  }
  ```  
上述程序中输入给PR函数的参数一共有4个：`1,"%s,%s\n","Hello","Macro"`，第一个参数是保存在x形参中的，剩下的三个参数保存在`__VA_ARGS__`宏当中。   
2. **运行结果如下所示:**   
![](https://img2018.cnblogs.com/blog/772331/201908/772331-20190826203407290-1733127586.png)   

### 3.The Other Macros:`__FILE__` `__LINE__` `__FUNCTION__`   
1. **基本概念：**   
  * __FILE__：宏在预编译时会替换成当前的源文件名.    
  * __LINE__：宏在预编译时会替换成当前的行号.    
  * __FUNCTION__：宏在预编译时会替换成当前的函数名称.    
  * __TIME__：在源文件中插入当前编译时间.  
  * __DATE__：在源文件中插入当前的编译日期.  
  
2. **Coding：**    
  ```
  #include <stdio.h>

  int main(void)
  {
      printf("The Source File Name:%s\n",__FILE__);
      printf("Current Code Line:%d\n",__LINE__);
      printf("Current Func Name:%s\n",__FUNCTION__);
      return 0;
  }
  ```    
  当程序在预编译过程当中，上述的三种宏就被替换成了对应的数值或者字符串了。    
3. **运行结果：**   
![](https://img2018.cnblogs.com/blog/772331/201908/772331-20190826212451755-1660111280.png)  

### 4.The FUNC Macro.  
通常我们将某些简短的函数直接改写为宏定义，这就减少了我们在调用过程中的代码编写。  
如`#define pi 3.14`称作变量式宏定义，再如`#define MAX(a,b) (a>b?a:b)`称为函数时宏定义。具体例子如下：  
1. **Codeing:**  
  ```
  #include <stdio.h>
  #define E 4
  #define PI 3.14
  #undef E // 将定义完成的宏撤销,可以重新定义一个名字叫E的宏.
  #define E 3
  #define MAX(a,b) ((a)>(b)?(a):(b))

  int main(void)
  {
      printf("The PI:%f\n",PI);
      printf("The Bigger:%f\n",MAX(PI,2.34));
      return 0;
  }
  ```  
2. **Result:**  
![Res](https://img2018.cnblogs.com/blog/772331/201908/772331-20190826213932662-1088305722.png)  

### 5.Reference  
[宏定义中的操作符](https://www.cnblogs.com/lidabo/p/4570949.html)  
[C语言的宏macro的使用](https://www.cnblogs.com/uestc-mm/p/11414798.html)
