# CPP技能

### string操作

1. 随机访问

   1. 按位访问

      ```c++
      string str;
      str[0]; //按位取出字符，得到type:char
      ```

   2. 取子串

      ```c++
      //string::substr(int startpos, int length) 
      //从startpos开始，取出length位组成的str
      //默认情况下，substr(n)表示从n开始直到字符串末尾
      string str = "I love u";
      str.substr(2, 4); //"love"
      ```

2. 长度

   ```c++
   string str;
   int length = str.size();
   ```

3. 修改

   1. 向后追加一位

      ```c++
      string str;
      str.push_back('a');
      ```

   2. 向后追加子串

      ```c++
      string str1, str2;
      str1.append(str2);
      ```

   3. 修改某一位/几位

      ```c++
      //string::replace(pos, len, substr, subpos, sublen);
      //意为将str的pos开始len位替换为substr中subpos开始的sublen位
      string str = "I love u";
      string str2 = "hate"
      str.replace(2, 4, str2); // "I hate u"
      // 或者
      str.replace(2, 2, str2, 0, 2); //"I have u"
      ```

4. 迭代

   ```c++
   string::iterator iter
   for (string::iterator iter = str.begin(); iter != str.end(); iter ++) {
     //do something
     //*iter表示当前迭代器所指的位置的字符值，类型为char
   }
   ```

-----

### vector操作

1. 初始化

   1. 初始化为空表

      ```c++
      vector<int> v;
      ```

   2. 拷贝初始化

      ```c++
      vector<int> v(v1);
      ```

   3. 指定元素初始化

      ```c++
      vector<int> v = {1,2,3,4,5};
      ```

   4. 缺省初始化

      ```c++
      vector<int> v(7); //初始化为7个int的vector，其中每个值根据类型做缺省设定，如此处0
      ```

   5. 相同元素初始化

      ```c++
      vector<int> v(7, 3); //初始化为7个3
      ```

2. 增删

   1. 尾部增删

      ```c++
      vector<int> v = {1,2,3,4,5};
      v.push_back(6); //v=[1,2,3,4,5,6]
      v.push_back(10); //v=[1,2,3,4,5,6,10]
      t = v.pop_back(); //v=[1,2,3,4,5,6], t=10
      ```

   2. 指定位置删除

      ```c++
      vector<int> v = {1,2,3,4,5,6,7,8,9,10};
      v.erase(v.begin()+5); //v=[1,2,3,4,5,7,8,9,10]
      v.erase(v.begin(), v.begin()+3); //v=[4,5,7,8,9,10]
      ```

   3. 指定位置增加

      ```c++
      // 1. v.insert(it, count, val) 在指定位置vector<T>::iterator it处插入count个val
      // 并返回一个新迭代器（指针），指向新插入的元素中的第一个的位置
      // 2. v.insert(it, begin, end) 在指定位置it插入从begin到end的元素
      // begin，end可以为vector的定位，也可以为数组（作为指针）的定位
      vector<int> v = {1,2,3,4,5};
      it = v.begin();
      it = v.insert(it, 2, 9); //v=[9,9,1,2,3,4,5] it = (新的)v.begin()
      
      vector<int> v1 = {7,8,9};
      v.insert(it+2, v1.begin(), v1.end());//v=[9,9,7,8,9,1,2,3,4,5]
      
      int array [] = {6,6,6};
      v.insert(v.begin()+3,array, array+3);//v=[9,9,7,6,6,6,8,9,1,2,3,4,5]
      ```

3. 迭代

   ```c++
   vector<T>::iterator iter
   for(vector<T>::iterator iter = vec.begin(); iter != vec.end(); iter ++) {
   	//do something
   }
   ```

-----

### 常见问题解决方案：

1. 数组/向量反序

   ```c++
   //迭代器实现
   void reverse(vector<T>& A) {
       for(vector<T>::iterator left = A.begin(), right = A.end()-1; left <= right; left ++, right --) {
           T t = *left;
           *left = *right;
           *right = t;
       }
   }
   
   //序号实现
   void reverse(vector<T>& A) {
       for (int left = 0, right = A.size()-1; left <= right; left++, right--) {
           T t = A[left];
           A[left] = A[right];
           A[right] = t;
       }
   }
   ```

2. 一个十进制数，取出其每位上的数字

   ```c++
   vector<int> getNumber(int x) {
       vector<int> res;
       while (x) {
           res.push_back(x%10);
           x /= 10;
       }
       return (res);
   }
   ```

   