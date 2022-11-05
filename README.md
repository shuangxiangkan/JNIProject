#### jni.h所在目录：

```
/Library/Java/JavaVirtualMachines/jdk1.8.0_321.jdk/Contents/Home/include
```

#### 1. 下面是初始目录

```
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        └── HelloWorld.java
```

#### 2. javac HelloWorld.java

```
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        ├── HelloWorld.class
        └── HelloWorld.java
```

#### 3. 命令: javac HelloWorld.java -h . （注意：最后有个点 "."）

```
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        ├── HelloWorld.class
        ├── HelloWorld.java
        └── test_HelloWorld.h
```
#### 4. 编写.c文件

```
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        ├── HelloWorld.c
        ├── HelloWorld.class
        ├── HelloWorld.java
        └── test_HelloWorld.h
```

#### 5. 生成.o文件(注意：生成的.jnilib要以lib开头，即libHelloWorld.jnilib)

```
gcc -dynamiclib -I /Library/Java/JavaVirtualMachines/jdk1.8.0_321.jdk/Contents/Home/include HelloWorld.c -o libhello.jnilib
```

```
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        ├── HelloWorld.c
        ├── HelloWorld.class
        ├── HelloWorld.java
        ├── libHelloWorld.jnilib
        └── test_HelloWorld.h
```

#### 6. 把libhello.jnilib放到/Library/Java/Extensions文件夹下，因为这是java默认的加载库的路径

#### 7. 退回到上一级目录，即/src下，然后执行命令java test.HelloWorld



-----------------------------------------------------------------------------
#### 命令行演示如下：

```
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % tree
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        └── HelloWorld.java

2 directories, 3 files
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % cd src/test
shuangxiangkan@SHUANGXIANGdeMacBook-Pro test % javac HelloWorld.java
shuangxiangkan@SHUANGXIANGdeMacBook-Pro test %
shuangxiangkan@SHUANGXIANGdeMacBook-Pro test % cd ../../
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % tree
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        ├── HelloWorld.class
        └── HelloWorld.java

2 directories, 4 files
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % cd -
~/Code/IDEAProject/JNIProject/src/test
shuangxiangkan@SHUANGXIANGdeMacBook-Pro test % javac HelloWorld.java -h .
shuangxiangkan@SHUANGXIANGdeMacBook-Pro test % cd -
~/Code/IDEAProject/JNIProject
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % tree
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        ├── HelloWorld.class
        ├── HelloWorld.java
        └── test_HelloWorld.h

2 directories, 5 files
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % cd -
~/Code/IDEAProject/JNIProject/src/test
shuangxiangkan@SHUANGXIANGdeMacBook-Pro test % cd -
~/Code/IDEAProject/JNIProject
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % tree
.
├── JNIProject.iml
├── Readme
└── src
    └── test
        ├── HelloWorld.c
        ├── HelloWorld.class
        ├── HelloWorld.java
        └── test_HelloWorld.h

2 directories, 6 files
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % cd -
~/Code/IDEAProject/JNIProject/src/test
shuangxiangkan@SHUANGXIANGdeMacBook-Pro test % gcc -dynamiclib -I /Library/Java/JavaVirtualMachines/jdk1.8.0_321.jdk/Contents/Home/include HelloWorld.c -o libhello.jnilib
shuangxiangkan@SHUANGXIANGdeMacBook-Pro test %
shuangxiangkan@SHUANGXIANGdeMacBook-Pro JNIProject % tree
.
├── JNIProject.iml
├── Readme
├── out
│   └── production
│       └── JNIProject
│           └── test
│               ├── HelloWorld.c
│               ├── HelloWorld.class
│               ├── libhello.jnilib
│               └── test_HelloWorld.h
└── src
    └── test
        ├── HelloWorld.c
        ├── HelloWorld.class
        ├── HelloWorld.java
        ├── libhello.jnilib
        └── test_HelloWorld.h

6 directories, 11 files

shuangxiangkan@SHUANGXIANGdeMacBook-Pro test % cd ..
shuangxiangkan@SHUANGXIANGdeMacBook-Pro src % java test.HelloWorld
Hello JNI World!!!!
```

