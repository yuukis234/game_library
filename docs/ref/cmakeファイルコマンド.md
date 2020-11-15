# コマンド集

## cmake_minimum_required(VERSION 3.12)

### 特徴

cmakeのバージョンを指定する。
指定以下のバージョンだとcmakeが動かなくなったり動作が不安定になる。

## SET( CMAKE_C_COMPILER <font color="red">/usr/bin/clang</font> )

### 特徴

cmakeで使うコンパイラを設定する。

gccを使いたい場合は「<font color="red">/user/bin/clang</font>」の部分をgccのパスに変更する

## project(<font color="red">cmake_template</font> C)

### 特徴

project名を設定する
「<font color="red">cmake_template</font>」ここの名前はルートフォルダと同じ名前にする

## add_library(succ <font color="blue">SHARED</font> <font color="red">src/succ.c</font>)

共有ライブラリ、静的ライブラリを作成する。「<font color="blue">SHARED</font>」では、**SHAREDでは共有ライブラリ**を**STATICでは静的ライブラリ**を生成してくれる。

共有ライブラリの場合
```
add_library(succ SHARED src/succ.c)
```

静的ライブラリの場合
```
add_library(succ STATIC src/succ.c)
```

## target_link_libraries(succ <font color="blue">PUBLIC</font> <font color="red">m</font>)

target_link_librariesは共有ライブラリ、静的ライブラリ、リンカを貼ることができます。math.hを利用したい場合は```clang test.c -o -lm```でリンクを貼ります。cmakeの場合はtarget_link_librariesでリンクを貼ることができます。

PUBLICとPRIVATEが選択できます。
赤色の部分にリンカを貼ることができます。

math.hのリンク貼る場合
```
target_link_libraries(succ PUBLIC m)
```

ライブラリファイルがsuccの場合
```
add_library(succ SHARED src/succ.c)
target_link_libraries(succ PUBLIC succ)
```

## target_include_directories(test_cmake <font color="blue">PUBLIC</font> <font color="red">${INC_DIR}</font>)

ヘッダーファイルをincludeします。

PUBLICとPRIVATEが選択できます。
赤色の部分にヘッダーファイルを貼ることができます。


```
## ヘッダーファイルを設定する
SET(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)

## INC_DIRのヘッダーファイルをincludeしてくれる
target_include_directories(test_cmake PUBLIC ${INC_DIR})
```

# 参考資料

CMakeスクリプトを作成する際のガイドライン: https://qiita.com/shohirose/items/5b406f060cd5557814e9

CMakeの使い方（その２）:https://qiita.com/shohirose/items/637f4b712893764a7ec1

http://www.dbms.cs.kumamoto-u.ac.jp/~y-manabe/class/jikken2_5B/2018/files/unity.pdf