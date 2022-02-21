**串**（String）是由零个或多个任意字符组成的有限序列。如下图所示

**目录**

[一、BF算法](#一、BF算法)

[二、KMP算法](#二、KMP算法)

[一、前缀、后缀，最大公共前后缀](#一、前缀、后缀，最大公共前后缀)

[二、研究KMP与BF的区别 （主要是回溯）](#二、研究KMP与BF的区别 （主要是回溯）)



[三、next数组的讲解](#三、next数组的讲解)

[j 位置的确定 （即next数组的详解）](#j 位置的确定 （即next数组的详解）)

------

当n=0时，为空串，与空格串不同。

![img](https://img-blog.csdnimg.cn/b16a68ded9c24e5db86312abe0126252.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

 一个串中任意个连续字符组成的子序列（包含空串）成为该串的子串。子串的概念类似于数学中的集合，有真子串，如下图所示

![img](https://img-blog.csdnimg.cn/30bb656546e34382a669c1510bb7e591.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

 **图来自于bilibili 王卓老师**

具体初始化，创建等就不讲了，实际开发中不可默守陈规，关键在于学习两种算法

## **一、BF算法**

**此算法也称为简单匹配算法。实际上即是暴力穷举法，算法时间复杂度为O（n\*m）,为方便理解算法先看下面图解**

![img](https://img-blog.csdnimg.cn/bdccee31082040f2af45e5ba980a93f5.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

 若刚开始S[0]!=T[0],条件同样满足，因此只要S[s]!=T[t],回溯就成立。循环此步骤的条件为s,t均小于该串长度

![img](https://img-blog.csdnimg.cn/118cac67123e48f3bcca4d1bf9e8b097.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

 **当前面元素都满足条件S[s]==T[t]，且进行到T[t]=="/0"时，代表匹配到了字符。此算法每次都要回溯因此时间复杂度为0（n\*m）**

![img](https://img-blog.csdnimg.cn/ac5a5e9b53f3416eab86842057661c07.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

代码实现如下(我以字符数组为例主要演示算法) 

```cpp
char S[7] = {"abcacbb"};
	char T[4] = {"cacb"};
	int s = 0;
	int t=0;
	while (s<sizeof(S)&&t< sizeof(T)) {    //j范围在主串内，t范围在子串内
		if (S[s]==T[t]) {
			s++;
			t++;    //值相等则比较下一元素
		}
		else {
			s = s - t + 1;    //回溯子串主串
			t= 0;
		}
		if (T[t]=="/0") {
			return 1;        //找到了
		}
		else {
			return 0;       //还未到循环结束
		}	
	}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

## **二、KMP算法**

KMP算法主要是在回溯方面进行了优化，使得不至于傻瓜式的回溯到头，关键点在于找到最大前后缀以减少无谓的过程。

由于网上的讲法有很多，我这面主要拆分为**完整过程**和**next数组**两部分讲解，我这面归纳总结为以下几个步骤：

**KMP算法流程**

①前缀，后缀，最大公共前后缀 概念 

②研究KMP与BF的区别 （主要是回溯）

③next数组的讲解 

### **一、前缀、后缀，最大公共前后缀**

前后缀的概念直接看如下范例，解释起来不如看例子理解的快，这个地方无需考虑原理什么的，就是需要用到这三个概念。当做平常知识即可，
 有一条字符串 为 **“abcde”** 
 **前缀**的集合：{a,ab,abc,abcd}
 **后缀**的集合：{e,de,cde,bcde}
 **公共缀**：就是该字符串 前缀后缀都包含的元素如下图所示
 **最大公共前后缀**：如图中所示字符串“a b c a b d a”有 公共的前后缀为 a,b,ab三种情况，但最大的公共前后缀 就为ab.
 **失配位**：即不相等时的位置。

![img](https://img-blog.csdnimg.cn/c2e2be41b2e14a3aae05ded28bc7e67a.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

 **那么最大公共前后缀有什么意义呢？接下来就进入正题。（本段思路来自天勤考研）**

**我们设定主串为 S[11]={"abcabbbabc"},子串为 T[5]={"abcabc"}，i，j分别为数组下标**

 如下图所示，**S[i]** 与 **T[j]** 分别对应，直到 **i=j=5**时，即第六个元素时，二者不相等
 当遇到不相等的情况是，BF的算法是将i回溯到 **i-j+1 的位置，**即之前比较的后一个位置
 然而对于Kmp算法则不同，Kmp首先找到**主串**与**子串**相同的部分的**最大公共前后缀，**
 其次将子串的**前缀**挪到与主串**后缀**的地方对齐。再进行**S[i]** 与 **T[j]** 的比较。

总结：步骤为 ①找到 **失配位** ② 找到**最大公共前后缀**   

### **二、**研究KMP与BF的区别 （主要是回溯）

那么为什么可以直接跳过这些元素而直接比较呢，即为什么 i 可以不回溯，j回溯位置也不用从头开始呢。那么接下来就进行此步骤的剖析：

![img](https://img-blog.csdnimg.cn/578818b1ad5440a78100b8165e290a1f.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

 当遇到不相等元素时证明**主串**与**子串**在此元素之前一定都相等。那么先看相等这一部分，如图所示，若子串向**右**移动，不管移动多少次，子串头元素a只有遇到后缀a时才会相等。那么同理b也是，因此我们直接找到**最大公共前后缀，**进行对齐即可。这里的移动只是方便看图，实际上移动的 只有 **j** 。这里的**最大公共前后缀**是在**失配位**之前寻找，（即绿线之前）
 由此步骤我们得出代码如下所示

 ![img](https://img-blog.csdnimg.cn/28eb9b0290324b6999c2ed7cb283a4cb.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

### ![img](https://img-blog.csdnimg.cn/c6365a2574834599b2da07841f3978a2.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

**图片来自bilibili 懒猫老师** 

BF算法在本文上面有提到，那么Kmp算法与其不同的地方主要在于**判定条件**，与**回溯**两处。此处判定条件 **j=-1** 会越界因此要加上条件，具体在后面会有讲到。j=next[j] 是 j 的回溯条件，即如何确定 **S[i]** 与 **T[j]** 不相等时，j 的回溯位置 ！！！再此强调 **i** 是不用回溯的，敌动我不动即可。只有在匹配成功后才会和 j 一同跳到下一个位置。

### **三、**next数组的讲解

**那么以上所有步骤，就是Kmp算法的整体架构，接下来我们只需要考虑 next 数组了，同时这里也是最关键的地方 ！！！**

**next数组的意义**在于找到每次 **S[i]** 与 **T[j]** 不相等时，即失配位时，j 的回溯位置 ， 这里我们先以**手算**法，讲解以便于理解后面的代码部分

事实上，在我们“移动”的过程中，根本不需要看主串，只需要看 **子串（模式串）**即可，直接将字串的**最大前缀**移动到**最大后缀**出即可如下图所示。此时我们再此强调，所谓的移动指示假想的，实际上是 j 的移动，如图 j 从原来失配位移动到了后缀之后。

![img](https://img-blog.csdnimg.cn/408a784ad5434198bf19014adc76095e.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

### **j 位置的确定** （即next数组的详解）

**一、手算图解法**

此法仅仅为了方便观察对应代码来思考方便理解。（这里我们用**新**的一组**子串**来演示）

由上图可知，想要判断**最大公共前后缀只需要子串即可**，那么我们制作以下表格

![img](https://img-blog.csdnimg.cn/b6a3201d21664f8ab17d3e3bb84d362a.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

这里的 **T** 代表了**子串（模式串）**后面数值为 子串内容，**下标**为串数组对应下标，**next**即为 j 要回溯的位置。
 **注意：这里next不同视频教程，有不同的版本，大概讲解一下**，其实就是各个位右移的区别。
 本文采用第二种方式 （这里不懂下面讲）

**next数组的求法**

![img](https://img-blog.csdnimg.cn/9cf8a728520d4dfb878d7f9ab07ac5c0.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==) 

第一步：数组初始化：

我们设定 j 为**前缀** i 为**后缀** 。数组**初始化** j 就等于0，对应的数组元素就等于 a，i为**后缀**所以 i=3,此时的 j 对应的 next值即为 -1.这里可以是0，也可以是-1，对应的上面的表，那么数组外部的 **j=next [] =-1**; 此时就对应之前的判断条件，为什么要加上j=-1。

![img](https://img-blog.csdnimg.cn/980ac550de134c488fea8a9b0dee9508.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)



第二步：求next [ j ]的值 

**求法是前n项 是否有公共前后缀，没有填0，有一个则填1，有两个填2，以此类推** 
 当 j =-0时，数组初始化， next [1] = -1；
 当 j =1 时，前面就只有a一个元素，所以  next [1] 应该为 0；
 当 j =2 时，前面有a b 两个元素， 所以  next [2] 应该为 0；
 当 j =3 时，前面有a b a 三个元素，所以  next [3] 应该为 1；（有公共前后缀 a）
 后面以此类推，结果如下表

![img](https://img-blog.csdnimg.cn/ca26530fbf194507aa5dca8463fd750d.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

 二、**代码解法**

**将图表和代码结合看**

![img](https://img-blog.csdnimg.cn/0dec1bc98ad24d98ab068b3ace43ee63.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA56iL5bqPbGVl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

 总结：j 始终指向 a的位置，移动的为 i ，当遇到 **j==-1 或 T [ i]=T [ j ]**时才会+1，进行下一元素比较，如果相等其实是代表了**最大公共前后缀**有2位，若不相等，则证明只有一位**最大公共前后缀，**与此同时，j=next[ j ],也就是回退到值等于a的地方。 