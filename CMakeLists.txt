# 本環境
## CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.12)

## コンパイラーを指定
SET( CMAKE_C_COMPILER /usr/bin/clang )

## C言語のフラグを立ててくる
## ここで必要なライブラリのリンカを貼る
## SET(CMAKE_C_FLAGS "-lGL -lglfw -lm")
SET(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)

## プロジェクト名と使用する言語を設定
project(cmake_template C)

## サブディレクトリを追加する
add_subdirectory(lib/unity)

## 共有ライブラリを作成
add_library(succ SHARED src/succ.c)

## 最後の実行ファイルを追加
add_executable(test_cmake src/main.c)


## shardで生成したライブラリをついか
target_link_libraries(test_cmake succ)



## 以下test_cmakeのincludeファイル設定

target_include_directories(test_cmake PUBLIC ${INC_DIR})


# 以上testのincludeファイル設定

# test関係

# unityソースを参照
SET( UNITY_ROOT lib/unity )

## unityファイルを設定
SET(UNITY_FILES ${UNITY_ROOT}/src/unity.c ${UNITY_ROOT}/extras/fixture/src/unity_fixture.c)

## テストケースのファイルを設定
SET(TEST_FILES test/testcase/test_succ.c)

## テストするファイルを設定
SET(SOURCE_FILESS src/succ.c)

## test runnerを設定
SET(TEST_RUNNER_FILES test/testrunner/succ_test_runner.c test/testrunner/all_tests.c)

## includeするファイルを設定
SET(INCLUDE_DIRECTORIES_TEST ${UNITY_ROOT}/src/unity.h)

## 設定したファイルをコンパイルする
add_executable(test_service ${TEST_RUNNER_FILES} ${SOURCE_FILESS} ${TEST_FILES} ${UNITY_FILES} ${INCLUDE_DIRECTORIES_TEST})

## ヘッダーファイルをincludeする（取り込む）
target_include_directories(test_service PRIVATE ${UNITY_ROOT}/src ${UNITY_ROOT}/extras/fixture/src ${UNITY_ROOT}/extras/memory/src ${INC_DIR})