// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include <tchar.h>
#include <time.h>
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <windows.h>
#include <stdlib.h>
using namespace std;
#include "Animal.h"
#include "Dog.h"
#include "Cats.h"
#include "Control.h"
//界面
int Menu1();
int Menu2();
int Menu3(CControl *a);
// TODO: 在此处引用程序需要的其他头文件
